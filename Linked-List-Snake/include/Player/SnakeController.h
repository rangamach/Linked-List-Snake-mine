#pragma once

#include <SFML/System/Vector2.hpp>
#include "Direction.h"
//#include "Linked List/SingleLinked/SingleLinkedList.h"
#include "../Linked List/LinkedListBase.h"
#include "../Food/FoodType.h"
#include "../Level/LevelConfig.h"

namespace Player
{
	using namespace Food;
	//using namespace LinkedList::SingleList;
	using namespace LinkedList;
	enum class SnakeState
	{
		Alive,
		Dead,
	};
	enum class InputState
	{
		Waiting,
		Processing,
	};
	enum class TimeComplexity
	{
		None,
		One,
		N
	};
	enum class LinkedListOperation
	{
		None,
		Insert_At_Head,
		Insert_At_Mid,
		Insert_At_End,
		Remove_At_Head,
		Remove_At_Mid,
		Remove_At_End,
		Delete_Half_List,
		Reverse_List,
	};
	class SnakeController
	{
	private:
		SnakeState snake_state;
		InputState current_input_state;
		TimeComplexity time_complexity;
		LinkedListOperation linked_list_operation;
		const int initial_snake_length = 10;
		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const float movement_frame_duration = 0.1f;
		const float restart_duration = 2.f;
		float elapsed_time;
		float restart_counter;
		int player_score;

		Direction default_direction = Direction::Right;
		Direction direction;
		//SingleLinkedList* single_linked_list;
		LinkedListBase* linked_list_base;

		void ProcessPlayerInput();
		void InitializeLinkedList();
		void UpdateSnakeDirection();
		void MoveSnake();
		void ProcessSnakeCollision();
		void ProcessBodyCollision();
		void ProcessElementCollision();
		void ProcessFoodCollision();
		void OnFoodCollected(FoodType food_type);
		void HandleRestart();
		void Reset();
		void DelayedUpdate();
		void SpawnSnake();
		void Destroy();

	public:
		SnakeController();
		~SnakeController();

		void Initialize();
		void Update();
		void Render();

		void CreateLinkedList(Level::LinkedListType list_type);
		void RespawnSnake();
		SnakeState GetSnakeState();
		void SetSnakeState(SnakeState state);
		std::vector<sf::Vector2i> GetCurrentSnakePositionList();
		int GetPlayerScore();
		TimeComplexity GetTimeComplexity();
		LinkedListOperation GetLinkedListOperation();
		bool IsSnakeDead();
	};
}


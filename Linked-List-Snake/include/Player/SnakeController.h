#pragma once

#include <SFML/System/Vector2.hpp>
#include "Direction.h"
#include "Linked List/SingleLinkedList.h"

namespace Player
{
	using namespace LinkedList;

	enum class SnakeState
	{
		Alive,
		Dead,
	};
	class SnakeController
	{
	private:
		SnakeState snake_state;
		const int initial_snake_length = 10;
		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const float movement_frame_duration = 0.1f;
		const float restart_duration = 2.f;
		float elapsed_time;
		float restart_counter;

		Direction default_direction = Direction::Right;
		Direction direction;
		SingleLinkedList* single_linked_list;

		void ProcessPlayerInput();
		void UpdateSnakeDirection();
		void MoveSnake();
		void ProcessSnakeCollision();
		void HandleRestart();
		void Reset();
		void CreateLinkedList();
		void DelayedUpdate();
		void SpawnSnake();
		void Destroy();

	public:
		SnakeController();
		~SnakeController();

		void Initialize();
		void Update();
		void Render();

		void RespawnSnake();
		SnakeState GetSnakeState();
		void SetSnakeState(SnakeState state);
		std::vector<sf::Vector2i> GetCurrentSnakePositionList();
	};
}


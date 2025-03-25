#pragma once

#include <SFML/System/Vector2.hpp>
#include <vector>
#include "SnakeController.h"
#include <Level/LevelConfig.h>

namespace Player
{
	class SnakeController;
	class PlayerService
	{
	private:
		SnakeController* snake_controller;

		void CreateController();
		void Destroy();

	public:
		PlayerService();
		~PlayerService();

		void Initialize();
		void Update();
		void Render();

		void SpawnPlayer(Level::LinkedListType list_type);
		std::vector<sf::Vector2i> GetCurrentSnakePositionList();
		int GetPlayerScore();
		TimeComplexity GetTimeComplexity();
		LinkedListOperation GetLinkedListOperation();
	};
}


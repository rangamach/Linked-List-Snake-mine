#pragma once

#include <SFML/System/Vector2.hpp>
#include <vector>

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

		void SpawnPlayer();
		std::vector<sf::Vector2i> GetCurrentSnakePositionList();
	};
}


#pragma once

#include "SFML/System/Vector2.hpp"
#include <vector>
#include <random>

namespace Food
{
	enum class FoodType;
	class FoodItem;
	class FoodService
	{
	private:
		std::default_random_engine random_engine;
		std::random_device random_device;
		FoodItem* current_food_item;
		float cell_width;
		float cell_height;

		FoodItem* CreateFoodItem(sf::Vector2i position, FoodType type);
		sf::Vector2i GetRandomPosition();
		void SpawnFood();
		bool IsValidFoodPosition(std::vector<sf::Vector2i> position_data, sf::Vector2i food_position);
		sf::Vector2i GetValidFoodPosition();
		FoodType GetRandomFoodType();
		void Destroy();

	public:
		FoodService();
		~FoodService();

		void Initialize();
		void Update();
		void Render();

		void StartFoodSpawning();
	};
}


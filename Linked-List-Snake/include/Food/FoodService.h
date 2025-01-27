#pragma once

#include "SFML/System/Vector2.hpp"
#include <vector>

namespace Food
{
	enum class FoodType;
	class FoodItem;
	class FoodService
	{
	private:
		FoodItem* current_food_item;
		float cell_width;
		float cell_height;

		FoodItem* CreateFoodItem(sf::Vector2i position, FoodType type);
		void SpawnFood();
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


#pragma once

#include "SFML/System/Vector2.hpp"
#include "../Linked List/Node.h"
#include <vector>
#include <random>

namespace Food
{
	enum class FoodType;
	class FoodItem;
	enum class FoodSpawningStatus
	{
		Active,
		Inactive,
	};
	class FoodService
	{
	private:
		std::default_random_engine random_engine;
		std::random_device random_device;
		FoodItem* current_food_item;
		FoodSpawningStatus current_food_spawning_status;
		float cell_width;
		float cell_height;
		const float spawn_duration = 4.f;
		float elapsed_duration;


		FoodItem* CreateFoodItem(sf::Vector2i position, FoodType type);
		sf::Vector2i GetRandomPosition();
		void SpawnFood();
		bool IsValidFoodPosition(std::vector<sf::Vector2i> position_data, sf::Vector2i food_position);
		sf::Vector2i GetValidFoodPosition();
		FoodType GetRandomFoodType();
		void UpdateElapsedDuration();
		void HandleFoodSpawning();
		void Reset();

	public:
		FoodService();
		~FoodService();

		void Initialize();
		void Update();
		void Render();
		void Destroy();

		void StartFoodSpawning();
		void StopFoodSpawning();
		bool ProcessFoodCollision(LinkedList::Node* head_node, FoodType& out_food_type);
	};
}


#pragma once

#include "../UI/UIElement/ImageView.h"

namespace Food
{
	enum class FoodType;
	class FoodItem
	{
	private:
		UI::UIElement::ImageView* food_image;
		sf::Vector2i position;
		float cell_width;
		float cell_height;
		FoodType food_type;

		sf::String GetFoodTexturePath();
		sf::Vector2f GetFoodImagePosition();
		void InitializeFoodImage();
	
	public:
		static const int number_of_food_items = 8;

		FoodItem();
		~FoodItem();

		void Initialize(sf::Vector2i pos, float width, float height, FoodType type);
		void Update();
		void Render();

		FoodType GetFoodType();
		sf::Vector2i GetFoodPosition();
	};
}


#include "../../include/Food/FoodItem.h"
#include "../../include/Food/FoodType.h"
#include "../../include/Global/Config.h"
#include "../../include/Level/LevelView.h"


using namespace Food;
using namespace Global;
using namespace Level;

sf::String FoodItem::GetFoodTexturePath()
{
	switch (food_type)
	{
	case FoodType::Apple:
		return Config::apple_texture_path;
	case FoodType::Mango:
		return Config::mango_texture_path;
	case FoodType::Cheese:
		return Config::cheese_texture_path;
	case FoodType::Orange:
		return Config::orange_texture_path;
	case FoodType::Pizza:
		return Config::pizza_texture_path;
	case FoodType::Alcohol:
		return Config::alcohol_texture_path;
	case FoodType::Burger:
		return Config::burger_texture_path;
	case FoodType::Poison:
		return Config::poision_texture_path;
	}
}

sf::Vector2f FoodItem::GetFoodImagePosition()
{
	float x = LevelView::border_offset_left + (cell_width * position.x);
	float y = LevelView::border_offset_top + (cell_height * position.y);

	return sf::Vector2f(x,y);
}

void FoodItem::InitializeFoodImage()
{
	sf::Vector2f screen_pos = GetFoodImagePosition();
	sf::String food_texture_path = GetFoodTexturePath();

	food_image->initialize(food_texture_path, cell_width, cell_height, screen_pos);
	food_image->show();
}

void FoodItem::Destroy()
{
	delete(food_image);
}

FoodItem::FoodItem()
{
	food_image = new UI::UIElement::ImageView();
}

FoodItem::~FoodItem()
{
	Destroy();
}

void FoodItem::Initialize(sf::Vector2i pos, float width, float height, FoodType type)
{
	position = pos;
	cell_width = width;
	cell_height = height;
	food_type = type;

	InitializeFoodImage();
}

void FoodItem::Update()
{
	food_image->update();
}

void FoodItem::Render()
{
	food_image->render();
}

FoodType FoodItem::GetFoodType()
{
	return food_type;
}

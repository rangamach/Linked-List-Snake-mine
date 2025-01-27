#include "../../include/Food/FoodService.h"
#include "../../include/Food/FoodItem.h"
#include "../../include/Food/FoodType.h"
#include "../../include/Global/ServiceLocator.h"

using namespace Food;
using namespace Global;

FoodItem* FoodService::CreateFoodItem(sf::Vector2i position, FoodType type)
{
	FoodItem* food = new FoodItem();
	food->Initialize(position, cell_width, cell_height, type);
	return food;
}

void FoodService::SpawnFood()
{
	current_food_item = CreateFoodItem(sf::Vector2i(4, 6), FoodType::Burger);
}

void FoodService::Destroy()
{
	if(current_food_item)
		delete(current_food_item);
}

FoodService::FoodService()
{
	current_food_item = nullptr;
}

FoodService::~FoodService()
{
	Destroy();
}

void FoodService::Initialize()
{
	StartFoodSpawning();
}

void FoodService::Update()
{
	if (current_food_item)
		current_food_item->Update();
}

void FoodService::Render()
{
	if (current_food_item)
		current_food_item->Render();
}

void FoodService::StartFoodSpawning()
{
	cell_width = ServiceLocator::getInstance()->GetLevelService()->GetCellWidth();
	cell_height = ServiceLocator::getInstance()->GetLevelService()->GetCellHeight();

	SpawnFood();
}

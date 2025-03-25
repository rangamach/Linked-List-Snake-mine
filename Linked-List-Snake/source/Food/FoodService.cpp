#include "../../include/Food/FoodService.h"
#include "../../include/Food/FoodItem.h"
#include "../../include/Food/FoodType.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Level/LevelModel.h"
#include "../../include/Linked List/Node.h"

using namespace Food;
using namespace Global;

FoodItem* FoodService::CreateFoodItem(sf::Vector2i position, FoodType type)
{
	FoodItem* food = new FoodItem();
	food->Initialize(position, cell_width, cell_height, type);
	return food;
}

sf::Vector2i FoodService::GetRandomPosition()
{
	std::uniform_int_distribution<int> x(0, Level::LevelModel::number_of_columns - 1);
	std::uniform_int_distribution<int> y(0, Level::LevelModel::number_of_rows - 1);

	int x_pos = x(random_engine);
	int y_pos = y(random_engine);

	return sf::Vector2i(x_pos,y_pos);
}

void FoodService::SpawnFood()
{
	current_food_item = CreateFoodItem(GetValidFoodPosition(), GetRandomFoodType());
}

bool FoodService::IsValidFoodPosition(std::vector<sf::Vector2i> position_data, sf::Vector2i food_position)
{
	for (int i = 0; i < position_data.size(); i++)
	{
		if (food_position == position_data[i]) return false;
	}
	return true;
}

sf::Vector2i FoodService::GetValidFoodPosition()
{
	std::vector<sf::Vector2i> player_position_data = ServiceLocator::getInstance()->GetPlayerService()->GetCurrentSnakePositionList();
	std::vector<sf::Vector2i> element_position_data = ServiceLocator::getInstance()->GetElementService()->GetElementPositionsList();
	sf::Vector2i food_spawn_position;

	do
	{
		food_spawn_position = GetRandomPosition();
	} while (!IsValidFoodPosition(player_position_data, food_spawn_position) || !IsValidFoodPosition(element_position_data, food_spawn_position));

	return food_spawn_position;
}

FoodType FoodService::GetRandomFoodType()
{
	std::uniform_int_distribution<int> type(0, FoodItem::number_of_food_items - 1);
	return static_cast<FoodType>(type(random_engine));
}

void FoodService::UpdateElapsedDuration()
{
	elapsed_duration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();
}

void FoodService::HandleFoodSpawning()
{
	if (ServiceLocator::getInstance()->GetPlayerService()->IsPlayerDead()) return;
	if (elapsed_duration >= spawn_duration)
	{
		Destroy();
		Reset();
		SpawnFood();
	}
}

void FoodService::Reset()
{
	elapsed_duration = 0.f;
}

void FoodService::Destroy()
{
	if(current_food_item)
		delete(current_food_item);
	current_food_item = nullptr;
}

FoodService::FoodService() : random_engine(random_device())
{
	current_food_item = nullptr;
}

FoodService::~FoodService()
{
	Destroy();
}

void FoodService::Initialize()
{
	elapsed_duration = spawn_duration;

	//StartFoodSpawning();
}

void FoodService::Update()
{
	if (current_food_spawning_status == FoodSpawningStatus::Active)
	{
		UpdateElapsedDuration();
		HandleFoodSpawning();
	}
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
	current_food_spawning_status = FoodSpawningStatus::Active;

	cell_width = ServiceLocator::getInstance()->GetLevelService()->GetCellWidth();
	cell_height = ServiceLocator::getInstance()->GetLevelService()->GetCellHeight();

	SpawnFood();
}

void FoodService::StopFoodSpawning()
{
	current_food_spawning_status = FoodSpawningStatus::Inactive;
	Destroy();
	Reset();
}

bool FoodService::ProcessFoodCollision(LinkedList::Node* head_node, FoodType& out_food_type)
{
	if (current_food_item && current_food_item->GetFoodPosition() == head_node->body_part.GetPosition())
	{
		out_food_type = current_food_item->GetFoodType();
		return true;
	}
	return false;
}

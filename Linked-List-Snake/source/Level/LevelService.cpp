#include "../../include/Level/LevelService.h"
#include "../../include/Level/LevelController.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Element/ElementService.h"
#include "../../include/Element/ElementData.h"

using namespace Level;
using namespace Global;

void LevelService::Destroy()
{
	delete(level_controller);
}

void LevelService::CreateLevelController()
{
	level_controller = new LevelController();
}

void LevelService::SpawnPlayer()
{
	ServiceLocator::getInstance()->GetPlayerService()->SpawnPlayer(current_list_type);
}

void LevelService::SpawnFood()
{
	float cell_width = level_controller->GetCellWidth();
	float cell_height = level_controller->GetCellHeight();

	ServiceLocator::getInstance()->GetFoodService()->StartFoodSpawning();
}

void LevelService::SpawnLevelElements(LevelNumber level_to_load)
{
	float cell_width = level_controller->GetCellWidth();
	float cell_height = level_controller->GetCellHeight();

	std::vector<Element::ElementData> element_data_list = level_controller->GetElementDataList((int)level_to_load);
	ServiceLocator::getInstance()->GetElementService()->SpawnElements(element_data_list, cell_width, cell_height);
}

void LevelService::CreateLevel(LinkedListType list_type)
{
	current_list_type = list_type;
	SpawnLevelElements(current_level);
	SpawnPlayer();
	SpawnFood();
}

float LevelService::GetCellWidth()
{
	return level_controller->GetCellWidth();
}

float LevelService::GetCellHeight()
{
	return level_controller->GetCellHeight();
}

void LevelService::SetLevelNumber(LevelNumber level_to_load)
{
	current_level = level_to_load;
}

LevelNumber LevelService::GetCurrentLevelNumber()
{
	return current_level;
}

LevelService::LevelService()
{
	level_controller = nullptr;
	CreateLevelController();
}

LevelService::~LevelService()
{
	Destroy();
}

void LevelService::Initialize()
{
	level_controller->Initialize();
}

void LevelService::Update()
{
	level_controller->Update();
}

void LevelService::Render()
{
	level_controller->Render();
}

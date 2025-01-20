#include "../../include/Level/LevelService.h"
#include "../../include/Level/LevelController.h"
#include "../../include/Global/ServiceLocator.h"

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
	ServiceLocator::getInstance()->GetPlayerService()->SpawnPlayer();
}

void LevelService::CreateLevel(LevelNumber level)
{
	current_level = level;
	SpawnPlayer();
}

float LevelService::GetCellWidth()
{
	return level_controller->GetCellWidth();
}

float LevelService::GetCellHeight()
{
	return level_controller->GetCellHeight();
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

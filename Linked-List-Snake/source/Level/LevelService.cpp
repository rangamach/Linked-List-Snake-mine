#include "../../include/Level/LevelService.h"
#include "../../include/Level/LevelController.h"

using namespace Level;

void LevelService::Destroy()
{
	delete(level_controller);
}

void LevelService::CreateLevelController()
{
	level_controller = new LevelController();
}

void LevelService::CreateLevel(LevelNumber level)
{
	current_level = level;
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

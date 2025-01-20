#include "../../include/Level/LevelController.h"
#include "../../include/Level/LevelModel.h"
#include "../../include/Level/LevelView.h"

using namespace Level;

void LevelController::Destroy()
{
	delete(level_model);
	delete(level_view);
}

LevelController::LevelController()
{
	level_model = new LevelModel();
	level_view = new LevelView();
}

LevelController::~LevelController()
{
	Destroy();
}

void LevelController::Initialize()
{
	level_view->Initialize();
	level_model->Initialize(level_view->GetGridWidth(), level_view->GetGridHeight());
}

void LevelController::Update()
{
	level_view->Update();
}

void LevelController::Render()
{
	level_view->Render();
}

float LevelController::GetCellWidth()
{
	return level_model->GetCellWidth();;
}

float LevelController::GetCellHeight()
{
	return level_model->GetCellHeight();
}

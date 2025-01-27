#include "../../include/Player/PlayerService.h"
#include "../../include/Player/SnakeController.h"

using namespace Player;

void PlayerService::CreateController()
{
	snake_controller = new SnakeController();
}

void PlayerService::Destroy()
{
	delete(snake_controller);
}

PlayerService::PlayerService()
{
	snake_controller = nullptr;

	CreateController();
}

PlayerService::~PlayerService()
{
	Destroy();
}

void PlayerService::Initialize()
{
	snake_controller->Initialize();
}

void PlayerService::Update()
{
	snake_controller->Update();
}

void PlayerService::Render()
{
	snake_controller->Render();
}

void PlayerService::SpawnPlayer()
{
	snake_controller->RespawnSnake();
}

std::vector<sf::Vector2i> PlayerService::GetCurrentSnakePositionList()
{
	return snake_controller->GetCurrentSnakePositionList();
}

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

void PlayerService::SpawnPlayer(Level::LinkedListType list_type)
{
	snake_controller->CreateLinkedList(list_type);
	snake_controller->RespawnSnake();
}

std::vector<sf::Vector2i> PlayerService::GetCurrentSnakePositionList()
{
	return snake_controller->GetCurrentSnakePositionList();
}

int Player::PlayerService::GetPlayerScore()
{
	return snake_controller->GetPlayerScore();;
}

TimeComplexity PlayerService::GetTimeComplexity()
{
	return snake_controller->GetTimeComplexity();
}

LinkedListOperation PlayerService::GetLinkedListOperation()
{
	return snake_controller->GetLinkedListOperation();
}

bool PlayerService::IsPlayerDead()
{
	return snake_controller->IsSnakeDead();
}

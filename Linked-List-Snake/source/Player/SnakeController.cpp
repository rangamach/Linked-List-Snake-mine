#include "../../include/Player/SnakeController.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Level/LevelService.h"

using namespace Player;
using namespace LinkedList;
using namespace Global;
using namespace Level;

void SnakeController::ProcessPlayerInput()
{
}

void SnakeController::UpdateSnakeDirection()
{
}

void SnakeController::MoveSnake()
{
}

void SnakeController::ProcessSnakeCollision()
{
}

void SnakeController::HandleRestart()
{
}

void SnakeController::Reset()
{
}

void SnakeController::CreateLinkedList()
{
	single_linked_list = new SingleLinkedList();
}

void SnakeController::Destroy()
{
	delete(single_linked_list);
}

SnakeController::SnakeController()
{
	single_linked_list = nullptr;
	CreateLinkedList();
}

SnakeController::~SnakeController()
{
	Destroy();
}

void SnakeController::Initialize()
{
	float width = ServiceLocator::getInstance()->GetLevelService()->GetCellWidth();
	float height = ServiceLocator::getInstance()->GetLevelService()->GetCellHeight();

	single_linked_list->Initialize(width, height, default_position, default_direction);
}

void SnakeController::Update()
{
	switch (snake_state)
	{
	case SnakeState::Alive:
		ProcessPlayerInput();
		UpdateSnakeDirection();
		ProcessSnakeCollision();
		MoveSnake();
		break;
	case SnakeState::Dead:
		HandleRestart();
		break;
	}
}

void SnakeController::Render()
{
	single_linked_list->Render();
}

void SnakeController::SpawnSnake()
{
	single_linked_list->CreateHeadNode();
}

void SnakeController::RespawnSnake()
{
}

SnakeState SnakeController::GetSnakeState()
{
	return snake_state;
}

void SnakeController::SetSnakeState(SnakeState state)
{
	snake_state = state;
}

#include "../../include/Player/SnakeController.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Level/LevelService.h"
#include "../../include/Event/EventService.h"

using namespace Player;
using namespace LinkedList;
using namespace Global;
using namespace Level;
using namespace Event;

void SnakeController::ProcessPlayerInput()
{
	EventService* event_service = ServiceLocator::getInstance()->getEventService();

	if (event_service->pressedUpArrowKey() && direction != Direction::Down)
	{
		direction = Direction::Up;
	}
	else if (event_service->pressedDownArrowKey() && direction != Direction::Up)
	{
		direction = Direction::Down;
	}
	else if (event_service->pressedLeftArrowKey() && direction != Direction::Right)
	{
		direction = Direction::Left;
	}
	else if (event_service->pressedRightArrowKey() && direction != Direction::Left)
	{
		direction = Direction::Right;
	}
}

void SnakeController::UpdateSnakeDirection()
{
	single_linked_list->UpdateNodeDirection(direction);
}

void SnakeController::MoveSnake()
{
	single_linked_list->UpdateNodePosition();
}

void SnakeController::ProcessSnakeCollision()
{
	if (single_linked_list->ProcessNodeCollision())
	{
		snake_state = SnakeState::Dead;
	}
}

void SnakeController::HandleRestart()
{
	restart_counter += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

	if (restart_counter >= restart_duration)
	{
		RespawnSnake();
	}
}

void SnakeController::Reset()
{
	snake_state = SnakeState::Alive;
	direction = default_direction;
	elapsed_time = 0.f;
	restart_counter = 0.f;
}

void SnakeController::CreateLinkedList()
{
	single_linked_list = new SingleLinkedList();
}

void SnakeController::DelayedUpdate()
{
	elapsed_time += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

	if (elapsed_time >= movement_frame_duration)
	{
		elapsed_time = 0.f;
		UpdateSnakeDirection();
		ProcessSnakeCollision();
		MoveSnake();
	}
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
		DelayedUpdate();
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
	for (int i = 0; i < initial_snake_length; i++)
	{
		single_linked_list->InsertNodeAtTail();
	}
}

void SnakeController::RespawnSnake()
{
	single_linked_list->RemoveAllNodes();
	Reset();
	SpawnSnake();
}

SnakeState SnakeController::GetSnakeState()
{
	return snake_state;
}

void SnakeController::SetSnakeState(SnakeState state)
{
	snake_state = state;
}

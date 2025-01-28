#include "../../include/Player/SnakeController.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Level/LevelService.h"
#include "../../include/Event/EventService.h"
#include "../../include/Food/FoodService.h"
#include "../../include/Food/FoodType.h"

using namespace Player;
using namespace LinkedList;
using namespace Global;
using namespace Level;
using namespace Event;
using namespace Sound;
using namespace Element;
using namespace Food;

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
	ProcessBodyCollision();
	ProcessElementCollision();
	ProcessFoodCollision();
}

void SnakeController::ProcessBodyCollision()
{
	if (single_linked_list->ProcessNodeCollision())
	{
		snake_state = SnakeState::Dead;
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
	}
}

void SnakeController::ProcessElementCollision()
{
	ElementService* element_service = ServiceLocator::getInstance()->GetElementService();

	if (element_service->ProcessElementCollision(single_linked_list->GetHeadNode()))
	{
		snake_state = SnakeState::Dead;
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
	}
}

void SnakeController::ProcessFoodCollision()
{
	FoodService* food_service = ServiceLocator::getInstance()->GetFoodService();
	FoodType food_type;

	if (food_service->ProcessFoodCollision(single_linked_list->GetHeadNode(), food_type))
	{
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::PICKUP);
		food_service->Destroy();
		OnFoodCollected(food_type);
	}
}

void SnakeController::OnFoodCollected(FoodType food_type)
{
	switch (food_type)
	{
	case FoodType::Pizza:
		//insert at tail.
		break;
	case FoodType::Burger:
		//insert at head.
		break;
	case FoodType::Cheese:
		//insert at middle.
		break;
	case FoodType::Apple:
		//delete at head.
		break;
	case FoodType::Mango:
		//delete at middle.
		break;
	case FoodType::Orange:
		//delete at tail.
		break;
	case FoodType::Poison:
		//delete half of snake.
		break;
	case FoodType::Alcohol:
		//reverse the snake.
		break;

	default:
		break;
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

std::vector<sf::Vector2i> SnakeController::GetCurrentSnakePositionList()
{
	return single_linked_list->GetNodePositionsList();
}

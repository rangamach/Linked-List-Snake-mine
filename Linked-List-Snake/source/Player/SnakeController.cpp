#include "../../include/Player/SnakeController.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Level/LevelService.h"
#include "../../include/Event/EventService.h"
#include "../../include/Food/FoodService.h"
#include "../../include/Food/FoodType.h"
#include "../../include/Linked List/SingleLinked/SingleLinkedList.h"
#include "../../include/Linked List/DoubleLinked/DoubleLinkedList.h"

using namespace LinkedList;
using namespace SingleList;
using namespace DoubleList;
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
	if (current_input_state == InputState::Processing)
		return;
	EventService* event_service = ServiceLocator::getInstance()->getEventService();

	if (event_service->pressedUpArrowKey() && direction != Direction::Down)
	{
		direction = Direction::Up;
		current_input_state = InputState::Processing;
	}
	else if (event_service->pressedDownArrowKey() && direction != Direction::Up)
	{
		direction = Direction::Down;
		current_input_state = InputState::Processing;
	}
	else if (event_service->pressedLeftArrowKey() && direction != Direction::Right)
	{
		direction = Direction::Left;
		current_input_state = InputState::Processing;
	}
	else if (event_service->pressedRightArrowKey() && direction != Direction::Left)
	{
		direction = Direction::Right;
		current_input_state = InputState::Processing;
	}
}

void SnakeController::InitializeLinkedList()
{
	float width = ServiceLocator::getInstance()->GetLevelService()->GetCellWidth();
	float height = ServiceLocator::getInstance()->GetLevelService()->GetCellHeight();

	Reset();

	linked_list_base->Initialize(width, height, default_position, default_direction);
}

void SnakeController::UpdateSnakeDirection()
{
	linked_list_base->UpdateNodeDirection(direction);
}

void SnakeController::MoveSnake()
{
	linked_list_base->UpdateNodePosition();
}

void SnakeController::ProcessSnakeCollision()
{
	ProcessBodyCollision();
	ProcessElementCollision();
	ProcessFoodCollision();
}

void SnakeController::ProcessBodyCollision()
{
	if (linked_list_base->ProcessNodeCollision())
	{
		snake_state = SnakeState::Dead;
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
	}
}

void SnakeController::ProcessElementCollision()
{
	ElementService* element_service = ServiceLocator::getInstance()->GetElementService();

	if (element_service->ProcessElementCollision(linked_list_base->GetHeadNode()))
	{
		snake_state = SnakeState::Dead;
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
	}
}

void SnakeController::ProcessFoodCollision()
{
	FoodService* food_service = ServiceLocator::getInstance()->GetFoodService();
	FoodType food_type;

	if (food_service->ProcessFoodCollision(linked_list_base->GetHeadNode(), food_type))
	{
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::PICKUP);
		player_score++;
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
		linked_list_base->InsertNodeAtTail();
		time_complexity = TimeComplexity::N;
		linked_list_operation = LinkedListOperation::Insert_At_End;
		break;
	case FoodType::Burger:
		//insert at head.
		linked_list_base->InsertNodeAtHead();
		time_complexity = TimeComplexity::One;
		linked_list_operation = LinkedListOperation::Insert_At_Head;
		break;
	case FoodType::Cheese:
		//insert at middle.
		linked_list_base->InsertNodeAtMiddle();
		time_complexity = TimeComplexity::N;
		linked_list_operation = LinkedListOperation::Insert_At_Mid;
		break;
	case FoodType::Apple:
		//delete at head.
		linked_list_base->RemoveNodeAtHead();
		time_complexity = TimeComplexity::One;
		linked_list_operation = LinkedListOperation::Remove_At_Head;
		break;
	case FoodType::Mango:
		//delete at middle.
		linked_list_base->RemoveNodeAtMiddle();
		time_complexity = TimeComplexity::N;
		linked_list_operation = LinkedListOperation::Remove_At_Mid;
		break;
	case FoodType::Orange:
		//delete at tail.
		linked_list_base->RemoveNodeAtTail();
		time_complexity = TimeComplexity::N;
		linked_list_operation = LinkedListOperation::Remove_At_End;
		break;
	case FoodType::Poison:
		//delete half of snake.
		linked_list_base->RemoveHalfNodes();
		time_complexity = TimeComplexity::N;
		linked_list_operation = LinkedListOperation::Delete_Half_List;
		break;
	case FoodType::Alcohol:
		//reverse the snake.
		direction = linked_list_base->Reverse();
		time_complexity = TimeComplexity::N;
		linked_list_operation = LinkedListOperation::Reverse_List;
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
	current_input_state = InputState::Waiting;
	player_score = 0;
}

void SnakeController::CreateLinkedList(LinkedListType list_type)
{
	//single_linked_list = new SingleLinkedList();
	switch (list_type)
	{
	case LinkedListType::Single:
		linked_list_base = new SingleLinkedList();
		break;
	case LinkedListType::Double:
		linked_list_base = new DoubleLinkedList();
	}
	
	InitializeLinkedList();
}

void SnakeController::DelayedUpdate()
{
	elapsed_time += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

	if (elapsed_time >= movement_frame_duration)
	{
		elapsed_time = 0.f;
		UpdateSnakeDirection();
		ProcessSnakeCollision();
		if(snake_state != SnakeState::Dead)
			MoveSnake();
		current_input_state = InputState::Waiting;
	}
}

void SnakeController::Destroy()
{
	delete(linked_list_base);
}

SnakeController::SnakeController()
{
	linked_list_base = nullptr;
	//CreateLinkedList();
}

SnakeController::~SnakeController()
{
	Destroy();
}

void SnakeController::Initialize()
{
	//float width = ServiceLocator::getInstance()->GetLevelService()->GetCellWidth();
	//float height = ServiceLocator::getInstance()->GetLevelService()->GetCellHeight();

	//Reset();

	//linked_list_base->Initialize(width, height, default_position, default_direction);
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
	linked_list_base->Render();
}

void SnakeController::SpawnSnake()
{
	for (int i = 0; i < initial_snake_length; i++)
	{
		linked_list_base->InsertNodeAtTail();
	}
}

void SnakeController::RespawnSnake()
{
	linked_list_base->RemoveAllNodes();
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
	return linked_list_base->GetNodePositionsList();
}

int SnakeController::GetPlayerScore()
{
	return player_score;
}

TimeComplexity SnakeController::GetTimeComplexity()
{
	return time_complexity;
}

LinkedListOperation SnakeController::GetLinkedListOperation()
{
	return linked_list_operation;
}

bool SnakeController::IsSnakeDead()
{
	return snake_state == SnakeState::Dead;
}

#include "../../include/Player/SnakeController.h"

using namespace Player;

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

void SnakeController::Destroy()
{
}

SnakeController::SnakeController()
{
}

SnakeController::~SnakeController()
{
	Destroy();
}

void SnakeController::Initialize()
{
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
}

void SnakeController::SpawnSnake()
{

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

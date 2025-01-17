#pragma once

namespace Player
{
	enum class SnakeState
	{
		Alive,
		Dead,
	};
	class SnakeController
	{
	private:
		SnakeState snake_state;
		const int initial_snake_length = 10;

		void ProcessPlayerInput();
		void UpdateSnakeDirection();
		void MoveSnake();
		void ProcessSnakeCollision();
		void HandleRestart();
		void Reset();
		void Destroy();

	public:
		SnakeController();
		~SnakeController();

		void Initialize();
		void Update();
		void Render();

		void SpawnSnake();
		void RespawnSnake();
		SnakeState GetSnakeState();
		void SetSnakeState(SnakeState state);
	};
}


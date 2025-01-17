#pragma once

namespace Player
{
	class SnakeController
	{
	private:
		void Destroy();

	public:
		SnakeController();
		~SnakeController();

		void Initialize();
		void Update();
		void Render();
	};
}


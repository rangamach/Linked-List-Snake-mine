#pragma once

namespace Level
{
	class LevelController
	{
	private:
		void Destroy();

	public:
		LevelController();
		~LevelController();

		void Initialize();
		void Update();
		void Render();
	};
}


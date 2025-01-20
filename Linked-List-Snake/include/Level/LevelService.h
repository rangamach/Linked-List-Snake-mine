#pragma once

#include "LevelNumber.h"

namespace Level
{
	class LevelController;
	class LevelService
	{
	private:
		LevelController* level_controller;
		LevelNumber current_level;

		void Destroy();
		void CreateLevelController();
		void SpawnPlayer();

	public:
		LevelService();
		~LevelService();

		void Initialize();
		void Update();
		void Render();
		void CreateLevel(LevelNumber level);
		float GetCellWidth();
		float GetCellHeight();
	};
}


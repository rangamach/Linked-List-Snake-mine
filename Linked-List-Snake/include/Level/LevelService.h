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
		void SpawnLevelElements(LevelNumber level_to_load);

	public:
		LevelService();
		~LevelService();

		void Initialize();
		void Update();
		void Render();
		void CreateLevel(LevelNumber level);
		float GetCellWidth();
		float GetCellHeight();
		LevelNumber GetCurrentLevelNumber();
	};
}


#pragma once

#include "LevelConfig.h"

namespace Level
{
	class LevelController;
	class LevelService
	{
	private:
		LevelController* level_controller;
		LevelNumber current_level;
		LinkedListType current_list_type;

		void Destroy();
		void CreateLevelController();
		void SpawnPlayer();
		void SpawnFood();
		void SpawnLevelElements(LevelNumber level_to_load);

	public:
		LevelService();
		~LevelService();

		void Initialize();
		void Update();
		void Render();
		void CreateLevel(LinkedListType list_type);
		float GetCellWidth();
		float GetCellHeight();
		void SetLevelNumber(LevelNumber level_to_load);
		LevelNumber GetCurrentLevelNumber();

	};
}


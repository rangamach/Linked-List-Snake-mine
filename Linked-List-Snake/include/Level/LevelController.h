#pragma once

namespace Level
{
	class LevelView;
	class LevelModel;
	class LevelController
	{
	private:
		LevelModel* level_model;
		LevelView* level_view;

		void Destroy();

	public:
		LevelController();
		~LevelController();

		void Initialize();
		void Update();
		void Render();

		float GetCellWidth();
		float GetCellHeight();
	};
}


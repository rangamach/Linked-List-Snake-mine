#pragma once

#include  <vector>
#include "../Element/ElementData.h"

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
		const std::vector<Element::ElementData>& GetElementDataList(int level_to_load);
	};
}


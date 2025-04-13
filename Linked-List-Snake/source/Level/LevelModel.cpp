#include "../../include/Level/LevelModel.h"

using namespace Level;

void LevelModel::InitializeLevelData()
{
	level_configurations.push_back(LevelData(Level::LevelNumber::One, &level_one_element_list));
	level_configurations.push_back(LevelData(Level::LevelNumber::Two, &level_two_element_list));
}

LevelModel::LevelModel() = default;

LevelModel::~LevelModel() = default;

void LevelModel::Initialize(int width, int height)
{
	cell_width = width / number_of_columns;
	cell_height = height / number_of_rows;

	InitializeLevelData();
}

float LevelModel::GetCellWidth()
{
	return cell_width;
}

float LevelModel::GetCellHeight()
{
	return cell_height;
}

const std::vector<Element::ElementData>& LevelModel::GetElementDataList(int level_to_load)
{
	return *level_configurations[level_to_load].element_data_list;
}

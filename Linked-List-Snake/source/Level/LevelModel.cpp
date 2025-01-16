#include "../../include/Level/LevelModel.h"

using namespace Level;

LevelModel::LevelModel() = default;

LevelModel::~LevelModel() = default;

void LevelModel::Initialize(int width, int height)
{
	cell_width = width / number_of_columns;
	cell_height = height / number_of_rows;
}

float LevelModel::GetCellWidth()
{
	return cell_width;
}

float LevelModel::GetCellHeight()
{
	return cell_height;
}

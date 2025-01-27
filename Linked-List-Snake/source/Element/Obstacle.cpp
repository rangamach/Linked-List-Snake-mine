#include "../../include/Element/Obstacle.h"
#include "../../include/Level/LevelView.h"
//#include "../../include/Global/ServiceLocator.h"
#include "../../include/Global/Config.h"

using namespace Element;
using namespace UI::UIElement;
using namespace Level;
using namespace Global;

void Obstacle::InitialeObstacleImage()
{
	sf::Vector2f screen_pos = GetObstacleImagePosition();

	obstacle_image->initialize(Config::obstacle_texture_path, cell_width, cell_height, screen_pos);
}

sf::Vector2f Obstacle::GetObstacleImagePosition()
{
	float x = LevelView::border_offset_left + (cell_width * position.x);
	float y = LevelView::border_offset_top + (cell_height * position.y);

	return sf::Vector2f(x,y);
}

void Obstacle::Destroy()
{
	delete(obstacle_image);
}

Obstacle::Obstacle()
{
	obstacle_image = new ImageView();
}

Obstacle::~Obstacle()
{
	Destroy();
}

void Obstacle::Initialize(sf::Vector2i pos, float width, float height)
{
	position = pos;
	cell_width = width;
	cell_height = height;

	InitialeObstacleImage();
}

void Obstacle::Update()
{
	obstacle_image->update();
}

void Obstacle::Render()
{
	obstacle_image->render();
}

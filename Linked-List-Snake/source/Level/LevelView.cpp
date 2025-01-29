#include "../../include/Level/LevelView.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/UI/UIElement/RectangleShapeView.h"

using namespace Level;
using namespace Global;
using namespace UI::UIElement;

void LevelView::Destroy()
{
	delete(background_rectangle);
	delete(border_rectangle);
}

void LevelView::CreateViews()
{
	background_rectangle = new RectangleShapeView();
	border_rectangle = new RectangleShapeView();
}

void LevelView::InitializeBackground()
{
	sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	sf::Vector2f background_size = sf::Vector2f(game_window->getSize().x, game_window->getSize().y);

	background_rectangle->initialize(background_size, sf::Vector2f(0, 0), 0, background_color);
	background_rectangle->show();
}

void LevelView::InitializeBorder()
{
	sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
	sf::Vector2f border_size = sf::Vector2f(grid_width, grid_height);
	sf::Vector2f border_position = sf::Vector2f(border_offset_left, border_offset_top);

	border_rectangle->initialize(border_size, border_position, border_thickness, sf::Color::Transparent, border_color);
	border_rectangle->show();
}

void LevelView::CalculateGridExtents()
{
	sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

	grid_width = game_window->getSize().x - 2 * border_offset_left;
	grid_height = game_window->getSize().y - border_offset_top - border_offset_bottom;
}

LevelView::LevelView()
{
	CreateViews();
}

LevelView::~LevelView()
{
	Destroy();
}

void LevelView::Initialize()
{
	InitializeBackground();
	CalculateGridExtents();
	InitializeBorder();
}

void LevelView::Update()
{
	background_rectangle->update();
	border_rectangle->update();
}

void LevelView::Render()
{
	background_rectangle->render();
	border_rectangle->render();
}

float LevelView::GetGridWidth()
{
	return grid_width;
}

float LevelView::GetGridHeight()
{
	return grid_height;
}

void LevelView::SetGridWidth(float width)
{
	grid_width = width;
}

void LevelView::SetGridHeight(float height)
{
	grid_height = height;
}

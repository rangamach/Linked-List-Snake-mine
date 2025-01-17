#include "../../include/Player/BodyPart.h"
#include "../../include/UI/UIElement/ImageView.h"
#include "../../include/Global/Config.h"
#include "../../include/Level/LevelView.h"

using namespace Global;
using namespace Player;
using namespace Level;

void BodyPart::CreateBodyPartImage()
{
	bodypart_image = new UI::UIElement::ImageView();
}

void BodyPart::InitializeBodyPartImage()
{
	bodypart_image->initialize(Config::snake_body_texture_path, bodypart_width, bodypart_height, GetBodyPartScreenPosition());
	bodypart_image->setOriginAtCentre();
}

sf::Vector2f Player::BodyPart::GetBodyPartScreenPosition()
{
	float x = LevelView::border_offset_left + (bodypart_grid_position.x * bodypart_width) + (bodypart_width / 2);
	float y = LevelView::border_offset_top + (bodypart_grid_position.y * bodypart_height) + (bodypart_height / 2);
	return sf::Vector2f(x,y);
}

void BodyPart::Destroy()
{
	delete(bodypart_image);
}

BodyPart::BodyPart()
{
	bodypart_image = nullptr;
	bodypart_grid_position = sf::Vector2i(0, 0);
	CreateBodyPartImage();
}

BodyPart::~BodyPart()
{
	Destroy();
}

void BodyPart::Initialize(float width, float height, sf::Vector2i position, Direction direction)
{
	bodypart_width = width;
	bodypart_height = height;
	bodypart_grid_position = position;
	bodypart_direction = direction;

	InitializeBodyPartImage();
}

void BodyPart::Render()
{
	bodypart_image->render();
}

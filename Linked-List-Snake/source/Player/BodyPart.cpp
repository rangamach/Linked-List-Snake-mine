#include "../../include/Player/BodyPart.h"
#include "../../include/UI/UIElement/ImageView.h"
#include "../../include/Global/Config.h"
#include "../../include/Level/LevelView.h"
#include "../../include/Level/LevelModel.h"

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

sf::Vector2f BodyPart::GetBodyPartScreenPosition()
{
	float x = LevelView::border_offset_left + (bodypart_grid_position.x * bodypart_width) + (bodypart_width / 2);
	float y = LevelView::border_offset_top + (bodypart_grid_position.y * bodypart_height) + (bodypart_height / 2);
	return sf::Vector2f(x,y);
}

float BodyPart::GetRotationAngle()
{
	switch (bodypart_direction)
	{
	case Player::Direction::Up:
		return 270.f;
	case Player::Direction::Down:
		return 90.f;
	case Player::Direction::Left:
		return 180.f;
	case Player::Direction::Right:
		return 0.f;
	}
}

void BodyPart::UpdatePosition()
{
	bodypart_grid_position = GetNextPosition();

	bodypart_image->setPosition(GetBodyPartScreenPosition());
	bodypart_image->setRotation(GetRotationAngle());
	bodypart_image->update();
}

sf::Vector2i Player::BodyPart::GetNextPositionLeft()
{
	return sf::Vector2i((bodypart_grid_position.x - 1 + LevelModel::number_of_columns) % (LevelModel::number_of_columns), bodypart_grid_position.y);
}

sf::Vector2i Player::BodyPart::GetNextPositionRight()
{
	return sf::Vector2i((bodypart_grid_position.x + 1) % (LevelModel::number_of_columns), bodypart_grid_position.y);
}

sf::Vector2i Player::BodyPart::GetNextPositionUp()
{
	return sf::Vector2i(bodypart_grid_position.x, (bodypart_grid_position.y - 1 + (LevelModel::number_of_rows)) % (LevelModel::number_of_rows));
}

sf::Vector2i Player::BodyPart::GetNextPositionDown()
{
	return sf::Vector2i(bodypart_grid_position.x, (bodypart_grid_position.y + 1) % (LevelModel::number_of_rows));
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

void BodyPart::SetDirection(Direction direction)
{
	previous_direction = this->bodypart_direction;
	this->bodypart_direction = direction;
}

void BodyPart::SetPosition(sf::Vector2i position)
{
	bodypart_grid_position = position;
}

sf::Vector2i BodyPart::GetNextPosition()
{
	switch (bodypart_direction)
	{
	case Player::Direction::Up:
		return GetNextPositionUp();
	case Player::Direction::Down:
		return GetNextPositionDown();
	case Player::Direction::Left:
		return GetNextPositionLeft();
	case Player::Direction::Right:
		return GetNextPositionRight();
	default:
		return bodypart_grid_position;
	}
}

sf::Vector2i BodyPart::GetPrevPosition()
{
	switch (bodypart_direction)
	{
	case Direction::Up:
		return GetNextPositionDown();
	case Direction::Down:
		return GetNextPositionUp();
	case Direction::Right:
		return GetNextPositionLeft();
	case Direction::Left:
		return GetNextPositionRight();
	default:
		return bodypart_grid_position;
	}
}

Direction BodyPart::GetDirection()
{
	return bodypart_direction;
}

sf::Vector2i BodyPart::GetPosition()
{
	return bodypart_grid_position;
}

Direction BodyPart::GetPreviousDirection()
{

	return previous_direction;
}

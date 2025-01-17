#pragma once

#include "UI/UIElement/ImageView.h"
#include "Direction.h"
#include <SFML/System/Vector2.hpp>

namespace Player
{
	class BodyPart
	{
	protected:
		UI::UIElement::ImageView* bodypart_image;
		sf::Vector2i grid_position;
		Direction direction;
		float bodypart_width;
		float bodypart_height;
	};
}


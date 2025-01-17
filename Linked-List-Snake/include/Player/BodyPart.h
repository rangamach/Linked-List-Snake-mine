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
		sf::Vector2i bodypart_grid_position;
		Direction bodypart_direction;
		float bodypart_width;
		float bodypart_height;

	private:
		void CreateBodyPartImage();
		void InitializeBodyPartImage();
		sf::Vector2f GetBodyPartScreenPosition();
		float GetRotationAngle();
		void UpdatePosition();
		void Destroy();

	public:
		BodyPart();
		~BodyPart();

		void Initialize(float width, float height, sf::Vector2i position, Direction direction);
		void Render();

		void SetDirection(Direction direction);
	};
}


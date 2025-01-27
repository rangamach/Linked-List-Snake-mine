#pragma once

#include "../../include/UI/UIElement/ImageView.h"
#include <SFML/System/Vector2.hpp>

namespace Element
{
	class Obstacle
	{
	private:
		UI::UIElement::ImageView* obstacle_image;
		sf::Vector2i position;
		float cell_width;
		float cell_height;

		void InitialeObstacleImage();
		sf::Vector2f GetObstacleImagePosition();
		void Destroy();
	
	public:
		Obstacle();
		~Obstacle();

		void Initialize(sf::Vector2i pos, float width, float height);
		void Update();
		void Render();
	};
}


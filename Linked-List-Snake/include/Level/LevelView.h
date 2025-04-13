#pragma once

#include <SFML/Graphics.hpp>
#include "UI/UIElement/RectangleShapeView.h"


namespace Level
{
	class LevelView
	{
	private:
		const sf::Color background_color = sf::Color(180, 200, 160);
		UI::UIElement::RectangleShapeView* background_rectangle;
		UI::UIElement::RectangleShapeView* border_rectangle;
		sf::Color border_color = sf::Color::Black;
		float grid_width;
		float grid_height;

		void Destroy();
		void CreateViews();
		void InitializeBackground();
		void InitializeBorder();
		void CalculateGridExtents();

	public:
		static const int border_thickness = 10;
		static const int border_offset_top = 100;
		static const int border_offset_left = 40;
		static const int border_offset_bottom = 40;

		LevelView();
		~LevelView();

		void Initialize();
		void Update();
		void Render();

		float GetGridWidth();
		float GetGridHeight();
		void SetGridWidth(float width);
		void SetGridHeight(float height);
	};
}


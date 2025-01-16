#pragma once

#include "UI/Interface/IUIController.h"
#include "UI/UIElement/ImageView.h"
#include "UI/UIElement/ButtonView.h"

namespace UI
{
	namespace LevelSelection
	{
		class LevelSelectionUIController : public Interface::IUIController
		{
		private:
			const float button_width = 400.f;
			const float button_height = 140.f;
			const float background_alpha = 85.f;

			UIElement::ImageView* background_image;
			UIElement::ButtonView* level_one_button;
			UIElement::ButtonView* level_two_button;
			UIElement::ButtonView* menu_button;
			

			void CreateImage();
			void CreateButtons();
			void InitializeBackgroundImage();
			void InitializeButtons();
			void RegisterButtonCallback();
			float CalculateButtonXOffset();
			void LevelOneButtonCallback();
			void LevelTwoButtonCallback();
			void MenuButtonCallback();
			void Destroy();

		public:
			LevelSelectionUIController();
			~LevelSelectionUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
		};
	}
}


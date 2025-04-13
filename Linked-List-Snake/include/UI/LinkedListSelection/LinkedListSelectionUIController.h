#pragma once

#include "UI/Interface/IUIController.h"
#include "UI/UIElement/ImageView.h"
#include "UI/UIElement/ButtonView.h"

namespace UI
{
	namespace LinkedlistSelection
	{
		class LinkedListSelectionUIController : public Interface::IUIController
		{
		private:
			const float button_width = 400.f;
			const float button_height = 140.f;
			const float background_alpha = 85.f;

			UIElement::ImageView* background_image;
			UIElement::ButtonView* single_linked_list_button;
			UIElement::ButtonView* double_linked_list_button;
			UIElement::ButtonView* menu_button;

			void CreateImage();
			void CreateButtons();
			void InitializeBackgroundImage();
			void InitializeButtons();
			void RegisterButtonCallback();
			float CalculateButtonXOffset();
			void SingleLinkedListButtonCallback();
			void DoubleLinkedListButtonCallback();
			void MenuButtonCallback();
			void Destroy();

		public:
			LinkedListSelectionUIController();
			~LinkedListSelectionUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
		};
	}
}


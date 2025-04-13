#pragma once

#include "../Interface/IUIController.h"
#include "../UIElement/TextView.h"

namespace UI
{
	namespace GameplayUI
	{
		class GameplayUIController : public Interface::IUIController
		{
		private:
			const int font_size = 60.f;
			const float text_y_pos = 7.f;
			const float level_number_text_pos = 65.f;
			const float score_text_x_pos = 800.f;
			const float operation_text_font_size = 36.f;
			const float operations_text_x_position = 1330.f;
			const float operations_text_y_position = 10.f;
			const float time_complexity_text_x_position = 1330.f;
			const float time_complexity_text_y_position = 45.f;

			UIElement::TextView* level_number_text;
			UIElement::TextView* score_text;
			UIElement::TextView* time_complexity_text;
			UIElement::TextView* operation_text;

			void CreateTexts();
			void InitializeTexts();
			void InitializeLevelNumberText();
			void InitializeScoreText();
			void InitializeTimeComplexityText();
			void InitializeOperationText();
			void UpdateLevelNumberText();
			void UpdateScoreText();
			void UpdateTimeComplexityText();
			void UpdateOperationText();
			void Destroy();

		public:
			GameplayUIController();
			~GameplayUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;

		};
	}
}


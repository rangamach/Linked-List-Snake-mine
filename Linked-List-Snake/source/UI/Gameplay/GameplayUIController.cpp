#include "../../include/UI/Gameplay/GameplayUIController.h"
#include "../../include/Level/LevelNumber.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Player/SnakeController.h"

using namespace UI::GameplayUI;
using namespace UI::UIElement;
using namespace Level;
using namespace Global;
using namespace Player;

void GameplayUIController::CreateTexts()
{
	level_number_text = new TextView();
	score_text = new TextView();
	time_complexity_text = new TextView();
	operation_text = new TextView();
}

void GameplayUIController::InitializeTexts()
{
	InitializeLevelNumberText();
	InitializeScoreText();
	InitializeOperationText();
	InitializeTimeComplexityText();
}

void GameplayUIController::InitializeLevelNumberText()
{
	level_number_text->initialize("Level: 1", sf::Vector2f(level_number_text_pos, text_y_pos), FontType::BUBBLE_BOBBLE, font_size, sf::Color::Black);
}

void GameplayUIController::InitializeScoreText()
{
	score_text->initialize("Score: 0", sf::Vector2f(score_text_x_pos, text_y_pos), FontType::BUBBLE_BOBBLE, font_size, sf::Color::Black);
}

void GameplayUIController::InitializeTimeComplexityText()
{
	time_complexity_text->initialize("Time Complexity: O(1)", sf::Vector2f(time_complexity_text_x_position, time_complexity_text_y_position), FontType::BUBBLE_BOBBLE, operation_text_font_size, sf::Color::Black);
}

void GameplayUIController::InitializeOperationText()
{
	operation_text->initialize("Last Operation: Insert at Middle", sf::Vector2f(operations_text_x_position, operations_text_y_position), FontType::BUBBLE_BOBBLE, operation_text_font_size, sf::Color::Black);
}

void GameplayUIController::UpdateLevelNumberText()
{
	LevelNumber level_number = ServiceLocator::getInstance()->GetLevelService()->GetCurrentLevelNumber();
	sf::String level_number_string = std::to_string(1 + static_cast<int>(level_number));
	level_number_text->setText("Level: " + level_number_string);
	level_number_text->update();
}

void GameplayUIController::UpdateScoreText()
{
	int player_score = ServiceLocator::getInstance()->GetPlayerService()->GetPlayerScore();
	sf::String player_score_string = std::to_string(player_score);
	score_text->setText("Score: " + player_score_string);
	score_text->update();
}

void GameplayUIController::UpdateTimeComplexityText()
{
	TimeComplexity time_complexity = ServiceLocator::getInstance()->GetPlayerService()->GetTimeComplexity();
	sf::String time_complexity_string;
	switch (time_complexity)
	{
	case TimeComplexity::None:
		time_complexity_string = "";
		break;
	case TimeComplexity::One:
		time_complexity_string = "1";
		break;
	case TimeComplexity::N:
		time_complexity_string = "N";
		break;
	}
	time_complexity_text->setText("Time Complexity: (" + time_complexity_string + ")");
	time_complexity_text->update();
}

void GameplayUIController::UpdateOperationText()
{
	LinkedListOperation linked_list_operation = ServiceLocator::getInstance()->GetPlayerService()->GetLinkedListOperation();
	sf::String linked_list_operation_string;
	switch (linked_list_operation)
	{
	case LinkedListOperation::None:
		linked_list_operation_string = "";
		break;
	case LinkedListOperation::Insert_At_Head:
		linked_list_operation_string = "Insert at Head";
		break;
	case LinkedListOperation::Insert_At_Mid:
		linked_list_operation_string = "Insert at Middle";
		break;
	case LinkedListOperation::Insert_At_End:
		linked_list_operation_string = "Insert at End";
		break;
	case LinkedListOperation::Remove_At_Head:
		linked_list_operation_string = "Remove at Head";
		break;
	case LinkedListOperation::Remove_At_Mid:
		linked_list_operation_string = "Remove at Middle";
		break;
	case LinkedListOperation::Remove_At_End:
		linked_list_operation_string = "Remove at End";
		break;
	case LinkedListOperation::Delete_Half_List:
		linked_list_operation_string = "Half List Deleted";
		break;
	case LinkedListOperation::Reverse_List:
		linked_list_operation_string = "Reversed the List";
		break;
	}
	operation_text->setText("Last Operation: " + linked_list_operation_string);
	operation_text->update();
}

void GameplayUIController::Destroy()
{
	delete(level_number_text);
	delete(score_text);
	delete(time_complexity_text);
	delete(operation_text);
}

GameplayUIController::GameplayUIController()
{
	CreateTexts();
}

GameplayUIController::~GameplayUIController()
{
	Destroy();
}

void GameplayUIController::initialize()
{
	InitializeTexts();
}

void GameplayUIController::update()
{
	UpdateLevelNumberText();
	UpdateScoreText();
	UpdateOperationText();
	UpdateTimeComplexityText();
}

void GameplayUIController::render()
{
	level_number_text->render();
	score_text->render();
	time_complexity_text->render();
	operation_text->render();
}

void GameplayUIController::show()
{
	level_number_text->show();
	score_text->show();
	time_complexity_text->show();
	operation_text->show();
}

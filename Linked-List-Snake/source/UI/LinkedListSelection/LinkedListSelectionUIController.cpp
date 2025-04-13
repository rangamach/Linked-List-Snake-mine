#include "../../include/UI/LinkedListSelection/LinkedListSelectionUIController.h"
#include "../../include/UI/LevelSelection/LevelSelectionUIController.h"
#include "../../include/UI/UIElement/ImageView.h"
#include "../../include/UI/UIElement/ButtonView.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Global/Config.h"
#include "../../include/Sound/SoundService.h"
#include "../../include/Main/GameService.h"
#include "../../include/Level/LevelService.h"

using namespace UI::LinkedlistSelection;
using namespace UI::UIElement;
using namespace Global;
using namespace Sound;
using namespace Main;

void LinkedListSelectionUIController::CreateImage()
{
	background_image = new ImageView();
}

void LinkedListSelectionUIController::CreateButtons()
{
	single_linked_list_button = new ButtonView();
	double_linked_list_button = new ButtonView();
	menu_button = new ButtonView();
}

void LinkedListSelectionUIController::InitializeBackgroundImage()
{
	sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

	background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
	background_image->setImageAlpha(background_alpha);
}

void LinkedListSelectionUIController::InitializeButtons()
{
	float x_offset = CalculateButtonXOffset();

	single_linked_list_button->initialize("Single Linked List", Config::single_linked_list_button_texture_path, button_width, button_height, sf::Vector2f(x_offset, 500.f));
	double_linked_list_button->initialize("Double Linked List", Config::double_linked_list_button_texture_path, button_width, button_height, sf::Vector2f(x_offset, 700.f));
	menu_button->initialize("Menu", Config::menu_button_texture_path, button_width, button_height, sf::Vector2f(x_offset, 900.f));
}

void LinkedListSelectionUIController::RegisterButtonCallback()
{
	single_linked_list_button->registerCallbackFuntion(std::bind(&LinkedListSelectionUIController::SingleLinkedListButtonCallback, this));
	double_linked_list_button->registerCallbackFuntion(std::bind(&LinkedListSelectionUIController::DoubleLinkedListButtonCallback, this));
	menu_button->registerCallbackFuntion(std::bind(&LinkedListSelectionUIController::MenuButtonCallback, this));
}

float UI::LinkedlistSelection::LinkedListSelectionUIController::CalculateButtonXOffset()
{
	sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

	return static_cast<float>(game_window->getSize().x / 2) - button_width / 2;
}

void LinkedListSelectionUIController::SingleLinkedListButtonCallback()
{
	ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
	GameService::setGameState(GameState::GAMEPLAY);
	ServiceLocator::getInstance()->GetLevelService()->CreateLevel(Level::LinkedListType::Single);
	//ServiceLocator::getInstance()->GetLevelService()->CreateLevel(Level::LevelNumber::One);
}

void LinkedListSelectionUIController::DoubleLinkedListButtonCallback()
{
	ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
	GameService::setGameState(GameState::GAMEPLAY);
	ServiceLocator::getInstance()->GetLevelService()->CreateLevel(Level::LinkedListType::Double);
	//ServiceLocator::getInstance()->GetLevelService()->CreateLevel(Level::LevelNumber::Two);
}

void LinkedListSelectionUIController::MenuButtonCallback()
{
	ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
	GameService::setGameState(GameState::MAIN_MENU);
}

void LinkedListSelectionUIController::Destroy()
{
	delete(background_image);
	delete(single_linked_list_button);
	delete(double_linked_list_button);
	delete(menu_button);
}

LinkedListSelectionUIController::LinkedListSelectionUIController()
{
	CreateButtons();
	CreateImage();
}

LinkedListSelectionUIController::~LinkedListSelectionUIController()
{
	Destroy();
}

void LinkedListSelectionUIController::initialize()
{
	InitializeBackgroundImage();
	InitializeButtons();
	RegisterButtonCallback();
}

void LinkedListSelectionUIController::update()
{
	background_image->update();
	single_linked_list_button->update();
	double_linked_list_button->update();
	menu_button->update();
}

void LinkedListSelectionUIController::render()
{
	background_image->render();
	single_linked_list_button->render();
	double_linked_list_button->render();
	menu_button->render();
}

void LinkedListSelectionUIController::show()
{
	background_image->show();
	single_linked_list_button->show();
	double_linked_list_button->show();
	menu_button->show();
}

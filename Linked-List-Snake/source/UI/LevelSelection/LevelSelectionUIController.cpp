#include "../../include/UI/LevelSelection/LevelSelectionUIController.h"
#include "../../include/UI/UIElement/ImageView.h"
#include "../../include/UI/UIElement/ButtonView.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Global/Config.h"
#include "../../include/Sound/SoundService.h"
#include "../../include/Main/GameService.h"
#include "../../include/Level/LevelService.h"

using namespace UI::LevelSelection;
using namespace UI::UIElement;
using namespace Global;
using namespace Sound;
using namespace Main;

void LevelSelectionUIController::CreateImage()
{
	background_image = new ImageView();
}

void LevelSelectionUIController::CreateButtons()
{
	level_one_button = new ButtonView();
	level_two_button = new ButtonView();
	menu_button = new ButtonView();
}

void LevelSelectionUIController::InitializeBackgroundImage()
{
	sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

	background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
	background_image->setImageAlpha(background_alpha);
}

void LevelSelectionUIController::InitializeButtons()
{
	float x_offset = CalculateButtonXOffset();

	level_one_button->initialize("Level One", Config::level_one_button_texture_path, button_width, button_height, sf::Vector2f(x_offset, 500.f));
	level_two_button->initialize("Level Two", Config::level_two_button_texture_path, button_width, button_height, sf::Vector2f(x_offset, 700.f));
	menu_button->initialize("Menu", Config::menu_button_texture_path, button_width, button_height, sf::Vector2f(x_offset, 900.f));
}

void LevelSelectionUIController::RegisterButtonCallback()
{
	level_one_button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::LevelOneButtonCallback, this));
	level_two_button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::LevelTwoButtonCallback, this));
	menu_button->registerCallbackFuntion(std::bind(&LevelSelectionUIController::MenuButtonCallback, this));
}

float LevelSelectionUIController::CalculateButtonXOffset()
{
	sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

	return static_cast<float>(game_window->getSize().x / 2) - button_width / 2;
}

void LevelSelectionUIController::LevelOneButtonCallback()
{
	ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
	GameService::setGameState(GameState::LINKED_LIST_SELECTION);
	ServiceLocator::getInstance()->GetLevelService()->CreateLevel(Level::LevelNumber::One);
}

void LevelSelectionUIController::LevelTwoButtonCallback()
{
	ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
	GameService::setGameState(GameState::LINKED_LIST_SELECTION);
	ServiceLocator::getInstance()->GetLevelService()->CreateLevel(Level::LevelNumber::Two);
}

void LevelSelectionUIController::MenuButtonCallback()
{
	ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
	GameService::setGameState(GameState::MAIN_MENU);
}

void LevelSelectionUIController::Destroy()
{
	delete(background_image);
	delete(level_one_button);
	delete(level_two_button);
	delete(menu_button);
}

LevelSelectionUIController::LevelSelectionUIController()
{
	CreateButtons();
	CreateImage();
}

LevelSelectionUIController::~LevelSelectionUIController()
{
	Destroy();
}

void LevelSelectionUIController::initialize()
{
	InitializeBackgroundImage();
	InitializeButtons();
	RegisterButtonCallback();
}

void LevelSelectionUIController::update()
{
	background_image->update();
	level_one_button->update();
	level_two_button->update();
	menu_button->update();
}

void LevelSelectionUIController::render()
{
	background_image->render();
	level_one_button->render();
	level_two_button->render();
	menu_button->render();
}

void LevelSelectionUIController::show()
{
	background_image->show();
	level_one_button->show();
	level_two_button->show();
	menu_button->show();
}

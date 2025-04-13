#include "Global/ServiceLocator.h"
#include "Main/GameService.h"

namespace Global
{
	using namespace Graphics;
	using namespace Event;
	using namespace Sound;
	using namespace UI;
	using namespace Time;
	using namespace Level;
	using namespace Player;
	using namespace Element;
	using namespace Food;
	using namespace Main;

	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		event_service = nullptr;
		sound_service = nullptr;
		ui_service = nullptr;
		time_service = nullptr;
		level_service = nullptr;
		player_service = nullptr;
		element_service = nullptr;
		food_service = nullptr;

		createServices();
	}

	ServiceLocator::~ServiceLocator() { clearAllServices(); }

	void ServiceLocator::createServices()
	{
		event_service = new EventService();
		graphic_service = new GraphicService();
		sound_service = new SoundService();
		ui_service = new UIService();
		time_service = new TimeService();
		level_service = new LevelService();
		player_service = new PlayerService();
		element_service = new ElementService();
		food_service = new FoodService();
	}

	void ServiceLocator::initialize()
	{
		graphic_service->initialize();
		sound_service->initialize();
		event_service->initialize();
		ui_service->initialize();
		time_service->initialize();
		level_service->Initialize();
		player_service->Initialize();
		element_service->Initialize();
		food_service->Initialize();	
	}

	void ServiceLocator::update()
	{
		graphic_service->update();
		event_service->update();
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			level_service->Update();
			element_service->Update();
			player_service->Update();
			food_service->Update();
		}
		ui_service->update();
		time_service->update();
	}

	void ServiceLocator::render()
	{
		
		graphic_service->render();
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			level_service->Render();
			element_service->Render();
			player_service->Render();
			food_service->Render();
		}
		ui_service->render();
	}

	void ServiceLocator::clearAllServices()
	{
		delete(ui_service);
		delete(graphic_service);
		delete(sound_service);
		delete(event_service);
		delete(time_service);
		delete(level_service);
		delete(player_service);
		delete(element_service);
		delete(food_service);
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	EventService* ServiceLocator::getEventService() { return event_service; }

	GraphicService* ServiceLocator::getGraphicService() { return graphic_service; }

	SoundService* ServiceLocator::getSoundService() { return sound_service; }

	UIService* ServiceLocator::getUIService() { return ui_service; }

	TimeService* ServiceLocator::getTimeService() { return time_service; }

	LevelService* ServiceLocator::GetLevelService() { return level_service; }

	PlayerService* ServiceLocator::GetPlayerService() { return player_service; }

	ElementService* ServiceLocator::GetElementService() { return element_service; }

	FoodService* ServiceLocator::GetFoodService() { return food_service; }

	void ServiceLocator::deleteServiceLocator() { delete(this); }
}
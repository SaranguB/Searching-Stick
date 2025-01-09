#include "Gameplay/GameplayView.h"
#include "Gameplay/GameplayController.h"
#include "Global/ServiceLocator.h"
#include "Global/Config.h"

namespace Gameplay
{
	using namespace UI::UIElement;
	using namespace Global;

	

	GameplayView::GameplayView()
	{
		backgroundImage = new ImageView;
	}

	GameplayView::~GameplayView()
	{
		delete backgroundImage;
	}
	void GameplayView::Initialize(GameplayController* gameplayController)
	{
		this->gameplayController = gameplayController;
		IntializeBackgroundimage();

	}

	void GameplayView::IntializeBackgroundimage()
	{
		sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		backgroundImage->initialize(Config::background_texture_path,
			game_window->getSize().x,
			game_window->getSize().y,
			sf::Vector2f(0, 0));
		backgroundImage->setImageAlpha(backgroundAlpha);
	}

	void GameplayView::Update()
	{
		backgroundImage->update();
	}
	void GameplayView::Render()
	{
		
		backgroundImage->render();
	}
}


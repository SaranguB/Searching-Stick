#pragma once
#include "UI/UIElement/ImageView.h"

namespace Gameplay
{
	class GameplayController;
	class GameplayView
	{
	private:
		const float backgroundAlpha = 55.f;

		GameplayController* gameplayController;
		UI::UIElement::ImageView* backgroundImage;

		sf::Font font;

		void IntializeBackgroundimage();
	public:

		GameplayView();
		~GameplayView();

		void Initialize(GameplayController* gameplayController);
		void Update();
		void Render();

	};
}
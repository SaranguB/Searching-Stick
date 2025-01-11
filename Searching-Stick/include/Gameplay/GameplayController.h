#pragma once

namespace Gameplay
{
	class GameplayView;
	class GameplayController
	{
	private:

		GameplayView* gameplayView;

		void Destroy();

	public:

		GameplayController();
		~GameplayController();

		void Initialize();
		void Update();
		void Render();

		void Reset();

	};
}

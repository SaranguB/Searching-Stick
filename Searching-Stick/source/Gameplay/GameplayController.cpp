#include "Gameplay/GameplayController.h"
#include "Gameplay/GameplayView.h"

namespace Gameplay
{
	
	GameplayController::GameplayController()
	{
		gameplayView = new GameplayView();
	}
	GameplayController::~GameplayController()
	{
		delete gameplayView;
	}
	void GameplayController::Initialize()
	{
		gameplayView->Initialize(this);
	}
	void GameplayController::Update()
	{
		gameplayView->Update();
	}

	void GameplayController::Render()
	{
		gameplayView->Render();
	}

	void GameplayController::Reset()
	{
		
	}

	void GameplayController::Destroy()
	{
	}
}
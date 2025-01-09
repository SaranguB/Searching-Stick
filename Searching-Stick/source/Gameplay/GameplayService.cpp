#include "Gameplay/GameplayService.h"
#include "Gameplay/GameplayController.h"

namespace Gameplay
{
	GameplayService::GameplayService()
	{
		gameplayController = new GameplayController();
	}

	GameplayService::~GameplayService()
	{
		delete gameplayController;
	}

	void GameplayService::Initialize()
	{
		gameplayController->Initialize();
	}

	void GameplayService::Update()
	{
		gameplayController->Update();
	}

	void GameplayService::Render()
	{
		gameplayController->Render();
	}

	void GameplayService::Reset()
	{
		gameplayController->Reset();
	}
}
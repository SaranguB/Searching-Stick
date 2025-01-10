#include "Gameplay/GameplayService.h"
#include "Gameplay/GameplayController.h"

namespace Gameplay
{
	GameplayService::GameplayService()
	{
		gameplayController = new GameplayController();
		collectionController = new StickCollectionController();
	}

	GameplayService::~GameplayService()
	{
		delete gameplayController;
		delete collectionController;
	}

	void GameplayService::Initialize()
	{
		gameplayController->Initialize();
		collectionController->Initialize();
	}

	void GameplayService::Update()
	{
		gameplayController->Update();
		collectionController->Update();
	}

	void GameplayService::Render()
	{
		gameplayController->Render();
		collectionController->Render();
	}

	void GameplayService::Reset()
	{
		gameplayController->Reset();
		collectionController->Reset();
	}
	void GameplayService::SearchElement(Collection::SearchType searchType)
	{
		//collectionController->searchElement();
	}
	int GameplayService::GetNumberOfSticks()
	{
		return collectionController->GetNumberOfSticks();
	}
}
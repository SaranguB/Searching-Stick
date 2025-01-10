#include "Gameplay/GameplayService.h"
#include "Gameplay/GameplayController.h"
#include "Gameplay/StickCollection/StickCollectionController.h"
#include <random>

namespace Gameplay
{
	using namespace Collection;
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

		InitializeRandomSpeed();


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
		collectionController->searchElement(searchType);
	}
	Collection::SearchType GameplayService::GetCurrentSearchType()
	{
		return collectionController->GetSearchType();
	}
	int GameplayService::GetNumberOfSticks()
	{
		return collectionController->GetNumberOfSticks();
	}

	int GameplayService::GetNumberOfComparisons()
	{
		return collectionController->GetNumberOfComparisons();
	}

	int GameplayService::GetNumberOfArrayAccess()
	{
		return collectionController->GetNumberOfArrayAccess();
	}

	int GameplayService::GetDelayMilliseconds()
	{
		return collectionController->GetDelayMilliseconds();
	}

	sf::String GameplayService::GetTimeComplexity()
	{
		return collectionController->GetTimeComplexity();
	}

	

	void GameplayService::InitializeRandomSpeed()
	{
		std::srand(static_cast<unsigned int>(std::time(nullptr)));
	
	}
}
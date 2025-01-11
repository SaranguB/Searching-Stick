#pragma once
#include "Gameplay/StickCollection/StickCollectionModel.h"
#include "Gameplay/StickCollection/StickCollectionController.h"
#include <SFML/Graphics.hpp>



namespace Gameplay
{
	using namespace Collection;

	class GameplayController;
	enum class SearchType;

	class GameplayService
	{
	private:
		GameplayController* gameplayController;
		StickCollectionController* collectionController;

		void InitializeRandomSpeed();

	public:
		GameplayService();
		~GameplayService();

		void Initialize();
		void Update();
		void Render();

		void Reset();

		void SearchElement(Collection::SearchType searchType);

		Collection::SearchType GetCurrentSearchType();

		int GetNumberOfSticks();

		int GetNumberOfComparisons();
		int GetNumberOfArrayAccess();

		int GetDelayMilliseconds();

		sf::String GetTimeComplexity();

		
		

		
	};
}

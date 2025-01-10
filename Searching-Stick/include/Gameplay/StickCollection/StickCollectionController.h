#pragma once

#include <vector>

namespace Gameplay
{
	namespace Collection
	{
		class StickCollectionView;
		class StickCollectionModel;
		struct Stick;
		enum class SearchType;

		class StickCollectionController
		{
		private:

			StickCollectionView* collection_view;
			StickCollectionModel* collection_model;
			std::vector<Stick*> sticks;
			Collection::SearchType search_type;
			Stick* stickToSearch;

			int numberOfComparisons;
			int numberOfArrayAccess;

			void initializeSticks();
			float calculateStickWidth();
			void updateSticksPosition();
			void resetSticksColor();
			void initializeSticksArray();
			float calculateStickHeight(int array_pos);

			void Destroy();
			void ShuffleSticks();
			void ResetSearchStick();

			void ProcessLinearSearch();

			void ResetVariables();


		public:

			StickCollectionController();
			~StickCollectionController();

			void Initialize();
			void Update();
			void Render();

			void Reset();

			SearchType GetSearchType();
			int GetNumberOfSticks();


			void searchElement(SearchType search_type);

			int GetNumberOfComparisons();
			int GetNumberOfArrayAccess();



		};
	}
}

#include "Gameplay/StickCollection/StickCollectionController.h"
#include "Gameplay/StickCollection/StickCollectionModel.h"
#include "Gameplay/StickCollection/StickCollectionView.h"
#include "Gameplay/StickCollection/Stick.h"
#include "Gameplay/GameplayService.h"
#include "Global/ServiceLocator.h"
#include <random>
#include <iostream>


namespace Gameplay
{
	namespace Collection
	{
		using namespace UI::UIElement;
		using namespace Global;
		using namespace Graphics;

		StickCollectionController::StickCollectionController()
		{
			collection_model = new StickCollectionModel();
			collection_view = new StickCollectionView();
			initializeSticksArray();
		}

		StickCollectionController::~StickCollectionController()
		{
			Destroy();
		}

		void StickCollectionController::Initialize()
		{
			initializeSticks();
			Reset();
		}

		void StickCollectionController::Update()
		{
			ProcessSearchThreadState();

			collection_view->Update();

			for (int i = 0;i < sticks.size();i++)
			{
				sticks[i]->stickView->update();
			}
		}

		void StickCollectionController::Render()
		{
			for (int i = 0;i < sticks.size();i++)
			{
				sticks[i]->stickView->render();
			}
		}
		void StickCollectionController::Reset()
		{
			currentOperationDelay = 0;

			ShuffleSticks();
			updateSticksPosition();
			resetSticksColor();
			ResetSearchStick();
			ResetVariables();

		}

		void StickCollectionController::initializeSticks()
		{
			float rectangleWidth = calculateStickWidth();

			for (int i = 0; i < collection_model->number_of_elements;i++)
			{
				float rectangleHeight = calculateStickHeight(i);

				sf::Vector2f rectangleSize = sf::Vector2f(rectangleWidth, rectangleHeight);

				sticks[i]->stickView->initialize(rectangleSize, sf::Vector2f(0, 0), 0, collection_model->element_color);
			}

		}

		float StickCollectionController::calculateStickWidth()
		{


			float total_space = static_cast<float>(ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize().x);

			float total_spacing = collection_model->space_percentage * total_space;

			float space_between = total_spacing / (collection_model->number_of_elements - 1);
			collection_model->setElementSpacing(space_between);

			float remaining_space = total_space - total_spacing;

			float rectangle_width = remaining_space / collection_model->number_of_elements;

			return rectangle_width;
		}

		float StickCollectionController::calculateStickHeight(int array_pos)
		{
			return (static_cast<float>(array_pos + 1) / collection_model->number_of_elements) *
				collection_model->max_element_height;
		}

		void StickCollectionController::updateSticksPosition()
		{
			for (int i = 0; i < sticks.size(); i++)
			{

				float x_position = (i * sticks[i]->stickView->getSize().x) + ((i + 1) * collection_model->elements_spacing);

				float y_position = collection_model->element_y_position - sticks[i]->stickView->getSize().y;

				sticks[i]->stickView->setPosition(sf::Vector2f(x_position, y_position));
			}
		}

		void StickCollectionController::resetSticksColor()
		{
			for (int i = 0;i < sticks.size();i++)
			{
				sticks[i]->stickView->setFillColor(collection_model->element_color);
			}
		}

		void StickCollectionController::initializeSticksArray()
		{
			for (int i = 0; i < collection_model->number_of_elements;i++)
			{
				sticks.push_back(new Stick(i));
			}
		}

		void StickCollectionController::Destroy()
		{

			if (searchThread.joinable()) searchThread.join();

			for (int i = 0;i < sticks.size();i++)
			{
				delete sticks[i];
			}
			sticks.clear();

			delete collection_model;
			delete collection_view;
		}

		SearchType StickCollectionController::GetSearchType()
		{
			return search_type;
		}

		int StickCollectionController::GetNumberOfSticks()
		{
			return collection_model->number_of_elements;
		}

		void StickCollectionController::searchElement(SearchType search_type)
		{

			this->search_type = search_type;

			switch (search_type)
			{
			case SearchType::LINEAR_SEARCH:
				currentOperationDelay = collection_model->linear_search_delay;
				searchThread = std::thread(&StickCollectionController::ProcessLinearSearch, this);
				break;
			}
		}

		int StickCollectionController::GetNumberOfComparisons()
		{
			return numberOfComparisons;
		}

		int StickCollectionController::GetNumberOfArrayAccess()
		{
			return numberOfArrayAccess;
		}

		int StickCollectionController::GetDelayMillieSecond()
		{
			return currentOperationDelay;
		}

		void StickCollectionController::ShuffleSticks()
		{
			std::random_device device;
			std::mt19937 random_engine(device());

			std::shuffle(sticks.begin(), sticks.end(), random_engine);

		}
		void StickCollectionController::ResetSearchStick()
		{
			stickToSearch = sticks[std::rand() % sticks.size()];
			stickToSearch->stickView->setFillColor(collection_model->search_element_color);
		}

		void StickCollectionController::ProcessLinearSearch()
		{


			for (int i = 0; i < sticks.size();i++)
			{
				numberOfArrayAccess++;
				numberOfComparisons++;

				Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::COMPARE_SFX);

				if (sticks[i] == stickToSearch)
				{

					stickToSearch->stickView->setFillColor(collection_model->found_element_color);
					stickToSearch = nullptr;
					return;
				}
				else
				{

					sticks[i]->stickView->setFillColor(collection_model->processing_element_color);

					std::this_thread::sleep_for(std::chrono::milliseconds(currentOperationDelay));

					sticks[i]->stickView->setFillColor(collection_model->element_color);
				}
			}
		}

		void StickCollectionController::ResetVariables()
		{
			numberOfComparisons = 0;
			numberOfArrayAccess = 0;
		}

		void StickCollectionController::ProcessSearchThreadState()
		{
			if (searchThread.joinable() && stickToSearch == nullptr)
			{
				JoinThreads();
			}
		}
		void StickCollectionController::JoinThreads()
		{
			searchThread.join();
		}

		
	}
}
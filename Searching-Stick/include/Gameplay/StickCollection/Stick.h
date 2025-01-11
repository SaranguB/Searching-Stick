#pragma once
#include "UI/UIElement/RectangleShapeView.h"

namespace Gameplay
{
	namespace Collection
	{
		struct Stick
		{
			int data;
			UI::UIElement::RectangleShapeView* stickView;

			Stick();

			Stick(int data)
			{
				this->data = data;
				stickView = new UI::UIElement::RectangleShapeView();
			}

			~Stick()
			{
				delete stickView;
			}

		};
	}
}

#include "View.h"

namespace ui
{

View::View()
	: screens_()
{
}

View::~View()
{
}

void View::addScreenWithTransition(pair<pair<ScreenID, Screen>, TransitionsSwitcher>& screen)
{
	screens_.push_back(screen);
}

ScreenID View::showScreenAndReturnNewId(ScreenID id) const
{
	auto screenItr = find_if(screens_.begin(), screens_.end(),
		[id](pair<pair<ScreenID, Screen>, TransitionsSwitcher> element)
	{
		return element.first.first == id;
	});

	if (screenItr != screens_.end())
	{
		Transitions choice = screenItr->first.second.showContentAndReturnUserChoice();
		TransitionsSwitcher trans = screenItr->second;
		return trans(choice);
	}
	else
	{
		cout << "ScreenID not found" << endl;
		exit(1);
		return Screen_Error;
	}
}

void View::startView() const
{
	if (!screens_.empty())
	{
		ScreenID nextScreen = Screen_Main;
		
		do
		{
			system("cls");
			nextScreen = showScreenAndReturnNewId(nextScreen);
		} while (nextScreen != Screen_End);
	}
}

} // namespace ui



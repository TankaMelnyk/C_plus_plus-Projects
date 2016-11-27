#include "Screen.h"

namespace ui
{

Screen::Screen(function<Transitions()>& userActionFunctor)
: userActionFunctor_(userActionFunctor)
{

}

Screen::Screen(const Screen& screen)
{
	userActionFunctor_ = screen.userActionFunctor_;
}

Screen::~Screen()
{
}

Transitions Screen::showContentAndReturnUserChoice() const
{
	if (userActionFunctor_)
	{
		return userActionFunctor_();
	}
	return TransitionError;
}

} // namespace ui
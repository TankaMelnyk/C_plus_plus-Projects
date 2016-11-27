#include "TransitionsSwitcher.h"

namespace ui
{

TransitionsSwitcher::TransitionsSwitcher(function<ScreenID(Transitions)> transitionFunctor)
	: transitionFunctor_(transitionFunctor)
{
}

TransitionsSwitcher::~TransitionsSwitcher()
{
}

ScreenID TransitionsSwitcher::operator()(Transitions choice) const
{
	return transitionFunctor_(choice);
}

} //namespace ui

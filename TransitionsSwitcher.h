#pragma once

#include <functional>

#include "TransitionsEnum.h"
#include "ScreenID.h"

using namespace std;

namespace ui
{

class TransitionsSwitcher
{
public:
	ScreenID operator() (Transitions choice) const;

	TransitionsSwitcher(function<ScreenID(Transitions)> transitionFunctor);
	~TransitionsSwitcher();
private:
	function<ScreenID(Transitions)> transitionFunctor_;
};

} //namespace ui



#pragma once
#include <string>
#include <iostream>
#include <functional>

#include "TransitionsEnum.h"

using namespace std;

namespace ui
{

class Screen
{
public:
	Transitions showContentAndReturnUserChoice() const;

	Screen(function<Transitions()>& userActionFunctor);
	Screen(const Screen& screen);
	~Screen();

private:	
	const Screen& operator= (const Screen& screen);

private:
	function<Transitions()> userActionFunctor_;
};

} // namespace ui



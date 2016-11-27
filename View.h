#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

#include "Screen.h"
#include "TransitionsSwitcher.h"
#include "ScreenID.h"
#include "TransitionsEnum.h"

using namespace std;
class UiTester;

namespace ui
{

class View
{
public:
	void addScreenWithTransition( pair<pair<ScreenID, Screen>, TransitionsSwitcher>& screen);
	void startView() const;

	View();
	~View();

private:
	ScreenID showScreenAndReturnNewId(ScreenID id) const;
	View(const View& v);
	const View& operator= (const View& v);

private:
	vector<pair<pair<ScreenID, Screen>, TransitionsSwitcher>> screens_;

	friend class UiTester;
};

} // namespace ui
#pragma once

#include <iostream>
#include <memory>

#include "View.h"
#include "Screen.h"
#include "TransitionsSwitcher.h"
#include "UiFactory.h"
#include "UIWrapper.h"
#include "BLWrapper.h"
#include "DLWrapper.h"

using namespace std;


class Application
{
public:
	Application();
	~Application();

	bool RunProgramm();

private:
	const Application& operator=  (const Application& a);
private:
	shared_ptr<DLWrapper> dlWrapper_;	
	shared_ptr<BLWrapper> blWrapper_;
	shared_ptr<UIWrapper> uiWrapper_;

};


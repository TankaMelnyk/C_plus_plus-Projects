#include "Application.h"

Application::Application()
: 
  dlWrapper_(new DLWrapper("dictionary.txt")),
  blWrapper_(new BLWrapper(dlWrapper_)),
  uiWrapper_(new UIWrapper(blWrapper_))
{
	
}

Application::~Application()
{
	
}

bool Application::RunProgramm()
{
	uiWrapper_->showView();
	return true;
}

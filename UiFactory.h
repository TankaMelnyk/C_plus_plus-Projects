#pragma once

#include <string>
#include <functional>
#include <memory>
#include <utility>

#include "TransitionsEnum.h"
#include "Screen.h"
#include "TransitionsSwitcher.h"
#include "ScreenID.h"
#include "TranslateManager.h"

using namespace std;

namespace ui
{

class UiFactory
{
public:
	Screen createScreen_main() const;
	TransitionsSwitcher createTransition_main() const;

	Screen createScreen_enterWord() const;
	TransitionsSwitcher createTransition_enterWord() const;

	Screen createScreen_wordIsNotFound() const;
	TransitionsSwitcher createTransition_wordIsNotFound() const;

	Screen createScreen_addWord() const;
	TransitionsSwitcher createTransition_addWord() const;

	Screen createScreen_wordIsAdded() const;
	TransitionsSwitcher createTransition_wordIsAdded() const;

	Screen createScreen_enterString() const;
	TransitionsSwitcher createTransition_enterString() const;

	Screen createScreen_enterFile() const;
	TransitionsSwitcher createTransition_enterFile() const;

	Screen createScreen_error() const;
	TransitionsSwitcher createTransition_error() const;

	Screen createScreen_final() const;
	TransitionsSwitcher createTransition_final() const;

	Screen createScreen_viewDictionary() const;
	TransitionsSwitcher createTransitional_viewDictionary() const;

	Screen createScreen_userSettings() const;
	TransitionsSwitcher createTransitional_userSettings() const;

	UiFactory();
	UiFactory(shared_ptr<bl::TranslateManager> translateManager);
	~UiFactory();

private:
	weak_ptr<bl::TranslateManager> translateManager_;

};

} //namespace ui



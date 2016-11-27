#pragma once

#include <iostream>

#include "View.h"
#include "UiFactory.h"

using namespace std;
using namespace ui;

class UiTester
{
public:
	void runTests() const;

	void createEmptyView_test() const;
	void mainTransitionSwicher_test() const;
	void enterWordToErrorTransitionSwicher_test() const;
	void wordIsAddedTransitionSwicher_test() const;

	UiTester();
	~UiTester();

	class MockUiFactory
	{
	public:
		Screen createScreen_main() const;
		Screen createScreen_enterWord() const;
		Screen createScreen_wordIsAdded() const;
	};

private:
	MockUiFactory mockFactory_;
	UiFactory uiFactory_;
};


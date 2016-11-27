#include "UiTester.h"


UiTester::UiTester()
{
}

UiTester::~UiTester()
{
}

void UiTester::runTests() const
{
	cout << "Start user interface tests: " << endl;
	cout << endl;
	createEmptyView_test();
	mainTransitionSwicher_test();
	enterWordToErrorTransitionSwicher_test();
	wordIsAddedTransitionSwicher_test();
	cout << endl;
	cout << "All tests finished" << endl;
}

void UiTester::createEmptyView_test() const
{
	View view;
	view.startView();
	cout << "OK - createEmptyView_test()" << endl;
}

void UiTester::mainTransitionSwicher_test() const
{
	View view;
	view.addScreenWithTransition(
		make_pair(make_pair(ui::Screen_Main, mockFactory_.createScreen_main())
		, uiFactory_.createTransition_main())
		);
	ScreenID screenId = view.showScreenAndReturnNewId(Screen_Main);
	if (screenId == Screen_EnterWord)
	{
		cout << "OK - mainTransitionSwicher_test()" << endl;
	}
	else
	{
		cout << "FAIL - mainTransitionSwicher_test()" << endl;
	}
}


void UiTester::enterWordToErrorTransitionSwicher_test() const
{
	View view;
	view.addScreenWithTransition(
		make_pair(make_pair(ui::Screen_EnterWord, mockFactory_.createScreen_enterWord())
		, uiFactory_.createTransition_enterWord())
		);
	ScreenID screenId = view.showScreenAndReturnNewId(Screen_EnterWord);
	if (screenId == Screen_Error)
	{
		cout << "OK - enterWordToErrorTransitionSwicher_test()" << endl;
	}
	else
	{
		cout << "FAIL - enterWordToErrorTransitionSwicher_test()" << endl;
	}
}

void UiTester::wordIsAddedTransitionSwicher_test() const
{
	View view;
	view.addScreenWithTransition(
		make_pair(make_pair(ui::Screen_WordIsAdded, mockFactory_.createScreen_wordIsAdded())
		, uiFactory_.createTransition_wordIsAdded())
		);
	ScreenID screenId = view.showScreenAndReturnNewId(Screen_WordIsAdded);
	if (screenId == Screen_AddWord)
	{
		cout << "OK - wordIsAddedTransitionSwicher_test()" << endl;
	}
	else
	{
		cout << "FAIL - wordIsAddedTransitionSwicher_test()" << endl;
	}
}

Screen UiTester::MockUiFactory::createScreen_main() const
{
	function<Transitions()> userAction = []() -> Transitions
	{
		return TransitionOne;
	};

	return Screen(userAction);
}


Screen UiTester::MockUiFactory::createScreen_enterWord() const
{
	function<Transitions()> userAction = []() -> Transitions
	{
		return TransitionError;
	};

	return Screen(userAction);
}

Screen UiTester::MockUiFactory::createScreen_wordIsAdded() const
{
	function<Transitions()> userAction = []() -> Transitions
	{
		return TransitionOne;
	};

	return Screen(userAction);
}

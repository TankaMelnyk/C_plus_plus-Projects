#include "UiFactory.h"

namespace ui
{

UiFactory::UiFactory(shared_ptr<bl::TranslateManager> translateManager)
:translateManager_(translateManager)
{
}

UiFactory::UiFactory()
: translateManager_()
{
}

UiFactory::~UiFactory()
{
}
// ----------------------------------------------------------------------------
Screen UiFactory::createScreen_main() const
{
	function<Transitions()> userAction = []() -> Transitions
	{
		cout << "����� ���������� � ����������! " << endl << endl;
		cout << "�������� ���������� ��������:" << endl;
		cout << " - ������� ����� ������� - 1" << endl;
		cout << " - ������� ������ ������� - 2" << endl;
		cout << " - ������� ����� ������� - 3" << endl;		
		cout << " - ���������� ������ ����� - 4" << endl;
		cout << " - �������� ����� ������� - 5" << endl;
		cout << " - ��������� ���������� - 6" << endl;
		cout << " - ����� �� ��������� - 7" << endl;
		cout << endl;
		cout << "�������� ���� �����: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1: return TransitionOne;		
		case 2: return TransitionTwo;
		case 3: return TransitionThree;
		case 4: return TransitionFour;
		case 5: return TransitionFive;
		case 6: return TransitionSix;
		case 7: return TransitionSeven;

		default: return TransitionError;
		}
	};

	return Screen(userAction);
}
// ----------------------------------------------------------------------------
TransitionsSwitcher UiFactory::createTransition_main() const
{
	TransitionsSwitcher trans(function<ScreenID(Transitions)>(
		[](Transitions choice)
	{
		switch (choice)
		{
		case TransitionOne: return Screen_EnterWord;
 		case TransitionTwo: return Screen_EnterString;
 		case TransitionThree: return Screen_EnterFile;
		case TransitionFour: return Screen_AddWord;
		case TransitionFive: return Screen_ViewDictionary;
		case TransitionSix: return Screen_ProgramSettings;
		case TransitionSeven: return Screen_Final;

		default: return Screen_Error;
		}
	}
	));

	return TransitionsSwitcher(trans);
}
// ----------------------------------------------------------------------------
Screen UiFactory::createScreen_enterWord() const
{
	const weak_ptr<bl::TranslateManager>& translateManager = translateManager_;

	function<Transitions()> userAction = [&translateManager]() -> Transitions
	{
		cout << "������� ����� ��� ��������: " << endl;
		string word;
		cin >> word;
		auto managerOwnership = translateManager.lock();
		string translatedWord = managerOwnership->translateWord(word);
		if (word != "" && translatedWord != "")
		{
			cout << "�������: " << endl << translatedWord << endl;
			cout << endl;
			cout << "�������� ���������� ��������:" << endl;
			cout << " - ��������� �������� - 1" << endl;
			cout << " - ��������� � ������� ���� - 2" << endl;
			cout << " - ����� �� ��������� - 3" << endl;
			cout << endl;
			cout << "�������� ���� �����: ";
			int choice;
			cin >> choice;
			switch (choice)
			{
			case 1: return TransitionOne;
			case 2: return TransitionTwo;
			case 3: return TransitionThree;

			default: return TransitionError;
			}
		}
		if (translatedWord == "")
			{
				return TransitionFour;
			}
		return TransitionError;
	};
	return Screen(userAction);

}
// ----------------------------------------------------------------------------
TransitionsSwitcher UiFactory::createTransition_enterWord() const
{
	TransitionsSwitcher trans(function<ScreenID(Transitions)>(
		[](Transitions choice)
	{
		switch (choice)
		{
		case TransitionOne: return Screen_EnterWord;
		case TransitionTwo: return Screen_Main;
		case TransitionThree: return Screen_Final;
		case TransitionFour: return Screen_WordIsNotFound;

		default: return Screen_Error;
		}
	}
	));

	return TransitionsSwitcher(trans);
}
// ----------------------------------------------------------------------------
Screen UiFactory::createScreen_wordIsNotFound() const
{
	function<Transitions()> userAction = []() -> Transitions
	{
		cout << "����� �� ������� � ����!"<< endl;
		cout << endl;
		cout << "�������� ���������� ��������:" << endl;
		cout << " - ������ ����� � ���� - 1" << endl;
		cout << " - ��������� �������� - 2" << endl;
		cout << " - ��������� � ������� ���� - 3" << endl;
		cout << " - ����� �� ��������� - 4" << endl;
		cout << endl;
		cout << "�������� ���� �����: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1: return TransitionOne;
		case 2: return TransitionTwo;
		case 3: return TransitionThree;
		case 4: return TransitionFour;

		default: return TransitionError;
		}
	};
	return Screen(userAction);
}
// ----------------------------------------------------------------------------
TransitionsSwitcher UiFactory::createTransition_wordIsNotFound() const
{
	TransitionsSwitcher trans(function<ScreenID(Transitions)>(
		[](Transitions choice)
	{
		switch (choice)
		{
		case TransitionOne: return Screen_AddWord;
		case TransitionTwo: return Screen_EnterWord;
		case TransitionThree: return Screen_Main;
		case TransitionFour: return Screen_Final;

		default: return Screen_Error;
		}
	}
	));

	return TransitionsSwitcher(trans);
}
// ----------------------------------------------------------------------------
Screen UiFactory::createScreen_addWord() const
{
	const weak_ptr<bl::TranslateManager>& translateManager = translateManager_;
	function<Transitions()> userAction = [&translateManager]() -> Transitions
	{
		cout << "������� ����� ��� ���������� � ����: " << endl;
		string word;
		cin >> word;
		cout << "��� �������: " << endl;
		string wordTrans;
		cin >> wordTrans;

		if (word == "" || wordTrans == "")
		{
			return TransitionError;
		}

		auto translateManagerOwnership = translateManager.lock();
		if (!translateManagerOwnership)
		{
			return TransitionError;
		}

		bool saveResult = translateManagerOwnership->saveWord(word, wordTrans);
		
		if (saveResult)
		{
			return TransitionOne;
		}
		return TransitionError;
	};
	return Screen(userAction);
}
// ----------------------------------------------------------------------------
TransitionsSwitcher UiFactory::createTransition_addWord() const
{
	TransitionsSwitcher trans(function<ScreenID(Transitions)>(
		[](Transitions choice)
	{
		switch (choice)
		{
		case TransitionOne: return Screen_WordIsAdded;

		default: return Screen_Error;
		}
	}
	));

	return TransitionsSwitcher(trans);
}
// ----------------------------------------------------------------------------
Screen UiFactory::createScreen_wordIsAdded() const
{
	function<Transitions()> userAction = []() -> Transitions
	{
		cout << "����� ������� ���������!" << endl;
		cout << endl;
		cout << "�������� ���������� ��������:" << endl;
		cout << " - ��������� �������� - 1" << endl;
		cout << " - ��������� � ������� ���� - 2" << endl;
		cout << " - ����� �� ��������� - 3" << endl;
		cout << endl;
		cout << "�������� ���� �����: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1: return TransitionOne;
		case 2: return TransitionTwo;
		case 3: return TransitionThree;

		default: return TransitionError;
		}
	};
	return Screen(userAction);
}
// ----------------------------------------------------------------------------
TransitionsSwitcher UiFactory::createTransition_wordIsAdded() const
{
	TransitionsSwitcher trans(function<ScreenID(Transitions)>(
		[](Transitions choice)
	{
		switch (choice)
		{
		case TransitionOne: return Screen_AddWord;
		case TransitionTwo: return Screen_Main;
		case TransitionThree: return Screen_Final;

		default: return Screen_Error;
		}
	}
	));
	return TransitionsSwitcher(trans);
}
// ----------------------------------------------------------------------------
Screen UiFactory::createScreen_enterString() const
{
	const weak_ptr<bl::TranslateManager>& translateManager = translateManager_;

	function<Transitions()> userAction = [&translateManager]() -> Transitions
	{
		cout << "������� ����� ��� ��������: " << endl;
		string str;
		cin.get();
		getline(cin, str);
		auto managerOwnership = translateManager.lock();		
		string translatedString = managerOwnership->translateString(str);
		if (str != "" && translatedString != "")
		{
			cout << "�������: " << endl << translatedString << endl;
			cout << endl;
			cout << "�������� ���������� ��������:" << endl;
			cout << " - ��������� �������� - 1" << endl;
			cout << " - ��������� � ������� ���� - 2" << endl;
			cout << " - ����� �� ��������� - 3" << endl;
			cout << endl;
			cout << "�������� ���� �����: ";
			int choice;
			cin >> choice;
			switch (choice)
			{
			case 1: return TransitionOne;
			case 2: return TransitionTwo;
			case 3: return TransitionThree;

			default: return TransitionError;
			}
		}
		return TransitionError;
	};
	return Screen(userAction);
}
// ----------------------------------------------------------------------------
TransitionsSwitcher UiFactory::createTransition_enterString() const
{
	TransitionsSwitcher trans(function<ScreenID(Transitions)>(
		[](Transitions choice)
	{
		switch (choice)
		{
		case TransitionOne: return Screen_EnterString;
		case TransitionTwo: return Screen_Main;
		case TransitionThree: return Screen_Final;

		default: return Screen_Error;
		}
	}
	));

	return TransitionsSwitcher(trans);
}
// ----------------------------------------------------------------------------
Screen UiFactory::createScreen_enterFile() const
{
	const weak_ptr<bl::TranslateManager>& translateManager = translateManager_;
	function<Transitions()> userAction = [&translateManager]() -> Transitions
	{
		cout << "������� ���� ��� ��������: " << endl << endl;
		string adressFile;
		cin >> adressFile;
		auto managerOwnership = translateManager.lock();		
		string translatedFile = managerOwnership->translateFile(adressFile);
		if (translatedFile != "")				
		{

			cout << "������� ��������� � ����� �� ������: " << translatedFile << endl;
			cout << endl;
			cout << "�������� ���������� ��������:" << endl;
			cout << " - ��������� �������� - 1" << endl;
			cout << " - ��������� � ������� ���� - 2" << endl;
			cout << " - ����� �� ��������� - 3" << endl;
			cout << endl;
			cout << "�������� ���� �����: ";
			int choice;
			cin >> choice;
			switch (choice)
			{
			case 1: return TransitionOne;
			case 2: return TransitionTwo;
			case 3: return TransitionThree;
			}
		}
		return TransitionError;
	};
	return Screen(userAction);
}
// ----------------------------------------------------------------------------
TransitionsSwitcher UiFactory::createTransition_enterFile() const
{
	TransitionsSwitcher trans(function<ScreenID(Transitions)>(
		[](Transitions choice)
	{
		switch (choice)
		{
		case TransitionOne: return Screen_EnterFile;
		case TransitionTwo: return Screen_Main;
		case TransitionThree: return Screen_Final;

		default: return Screen_Error;
		}
	}
	));

	return TransitionsSwitcher(trans);
}
// ----------------------------------------------------------------------------
Screen UiFactory::createScreen_error() const
{
	function<Transitions()> userAction = []() -> Transitions
	{
		cout << "������� �� ���������� ������!" << endl;
		cout << endl;
		cout << "�������� ���������� ��������:" << endl;
		cout << " - ��������� � ������� ���� - 1" << endl;
		cout << " - ����� �� ��������� - 2" << endl;
		cout << endl;
		cout << "�������� ���� �����: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1: return TransitionOne;
		case 2: return TransitionTwo;

		default: return TransitionError;
		}
	};
	return Screen(userAction);
}
// ----------------------------------------------------------------------------
TransitionsSwitcher UiFactory::createTransition_error() const
{
	TransitionsSwitcher trans(function<ScreenID(Transitions)>(
		[](Transitions choice)
	{
		switch (choice)
		{
		case TransitionOne: return Screen_Main;
		case TransitionTwo: return Screen_Final;

		default: return Screen_Error;
		}
	}
	));
	return TransitionsSwitcher(trans);
}
// ----------------------------------------------------------------------------
Screen UiFactory::createScreen_final() const
{
	function<Transitions()> userAction = []() -> Transitions
	{
		cout << "�������, ��� ���� � ����!" << endl;
		cout << "���� Tanka ;)" << endl;

		return TransitionOne;
	};
	return Screen(userAction);
}
// ----------------------------------------------------------------------------
TransitionsSwitcher UiFactory::createTransition_final() const
{
	TransitionsSwitcher trans(function<ScreenID(Transitions)>(
		[](Transitions choice)
	{
		return Screen_End;
	}
	));
	return TransitionsSwitcher(trans);
}
// ----------------------------------------------------------------------------
Screen UiFactory::createScreen_viewDictionary() const
{
	const weak_ptr<bl::TranslateManager>& translateManager = translateManager_;

	function<Transitions()> userAction = [&translateManager]() -> Transitions
	{
		cout << "������� ������� ����������:" << endl << endl;

		auto managerOwnership = translateManager.lock();
		managerOwnership->viewDictionary();
		cout << endl;
		cout << "�������� ���������� ��������:" << endl;
		cout << " - ��������� � ������� ���� - 1" << endl;
		cout << " - ����� �� ��������� - 2" << endl;
		cout << endl;
		cout << "�������� ���� �����: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1: return TransitionOne;
		case 2: return TransitionTwo;

		default: return TransitionError;
		}

	};
	return Screen(userAction);
}
// ----------------------------------------------------------------------------
TransitionsSwitcher UiFactory::createTransitional_viewDictionary() const
{
	TransitionsSwitcher trans(function<ScreenID(Transitions)>(
		[](Transitions choice)
	{
		switch (choice)
		{
		case TransitionOne: return Screen_Main;
		case TransitionTwo: return Screen_Final;

		default: return Screen_Error;
		}
	}
	));

	return TransitionsSwitcher(trans);
}
// ----------------------------------------------------------------------------
Screen UiFactory::createScreen_userSettings() const
{
	const weak_ptr<bl::TranslateManager>& translateManager = translateManager_;

	function<Transitions()> userAction = [&translateManager]() -> Transitions
	{
	
		cout << "������� ���� ���������� ������������� �����: ";
		string pathFile = "";
		cin >> pathFile;
		if (pathFile == "")
		{
			pathFile = "C:\\";
		}
		auto managerOwnership = translateManager.lock();
		managerOwnership->savePath(pathFile);

		cout << endl;
		cout << "�������� ���������� ��������:" << endl;
		cout << " - ��������� �������� - 1" << endl;
		cout << " - ��������� � ������� ���� - 2" << endl;
		cout << " - ����� �� ��������� - 3" << endl;
		cout << endl;
		cout << "�������� ���� �����: ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1: return TransitionOne;
		case 2: return TransitionTwo;
		case 3: return TransitionThree;
		}
		return TransitionError;
	};
	return Screen(userAction);

}
// ----------------------------------------------------------------------------
TransitionsSwitcher UiFactory::createTransitional_userSettings() const
{
	TransitionsSwitcher trans(function<ScreenID(Transitions)>(
		[](Transitions choice)
	{
		switch (choice)
		{
		case TransitionOne: return Screen_ProgramSettings;
		case TransitionTwo: return Screen_Main;
		case TransitionThree: return Screen_Final;

		default: return Screen_Error;
		}
	}
	));

	return TransitionsSwitcher(trans);
}
// ----------------------------------------------------------------------------
} //namespace ui
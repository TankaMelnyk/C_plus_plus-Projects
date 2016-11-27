#pragma once

#include <memory>
#include <string>

#include "WordTranslator.h"
#include "FileTranslator.h"
#include "WordSaver.h"
#include "DataAccessor.h"
#include "StringTranslator.h"
#include "ViewDictionary.h"
#include "UserSettings.h"

using namespace std;

namespace bl
{

class TranslateManager
{
public:
	const string translateWord(const string& word) const;
	bool saveWord(const string& word, const string& transWord);
	const string translateString(const string& word) const;
	const string translateFile(const string& fullFileName) const;
	void viewDictionary() const;
	void savePath(const string& userPath);

	void UserSettings();

	TranslateManager(shared_ptr<dl::DataAccessor> dataAccessor);
	~TranslateManager();

private: 
	shared_ptr<WordTranslator> wordTranslator_;
	shared_ptr<StringTranslator> stringTranslator_;
	unique_ptr<FileTranslator> fileTranslator_;
	unique_ptr<WordSaver> wordSaver_;
	unique_ptr<ViewDictionary> viewDictionary_;
	unique_ptr<FileTranslator> userPath_;
};

}

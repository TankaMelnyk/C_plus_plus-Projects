#include "TranslateManager.h"

namespace bl
{
	
TranslateManager::TranslateManager(shared_ptr<dl::DataAccessor> dataAccessor)
: wordTranslator_(new WordTranslator(dataAccessor)),
  stringTranslator_(new StringTranslator(wordTranslator_)),
  fileTranslator_(new FileTranslator(stringTranslator_)),
  wordSaver_(new WordSaver(dataAccessor)),
  viewDictionary_(new ViewDictionary(dataAccessor))
{
}

TranslateManager::~TranslateManager()
{
}

const string TranslateManager::translateWord(const string& word) const
{
	return wordTranslator_->translateWord(word);
}

bool TranslateManager::saveWord(const string& word, const string& transWord)
{
	return wordSaver_->saveWord(word, transWord);
}

const string TranslateManager::translateString(const string& word) const
{
	return stringTranslator_->TranslateString(word);
}

const string TranslateManager::translateFile(const string& fullFileName) const
{
	return fileTranslator_->TranslateFile(fullFileName);
}

void TranslateManager::viewDictionary() const
{
	viewDictionary_->viewDictionary();
}

void TranslateManager::savePath(const string& userPath)
{
	fileTranslator_->changeSavedFilePath(userPath);
}

}



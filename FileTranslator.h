#pragma once

#include <memory>

#include "StringTranslator.h"

using namespace std;

namespace bl
{

class FileTranslator
{
public:
	const string TranslateFile(const string& fullPachAdress);
	void changeSavedFilePath(const string& filePath);

	FileTranslator(shared_ptr<StringTranslator> wordTranslator);
	~FileTranslator();
private:
	void addStringToFile(const string& str, const string& fullPachAdress);
	string textFromFileIntoString(const string& pathFile);
	string newNamePachFileTranslate(const string& pathFile);

private:
	shared_ptr<StringTranslator> stringTranslator_;
	string pathUserAdress_;
};

} //namespace bl

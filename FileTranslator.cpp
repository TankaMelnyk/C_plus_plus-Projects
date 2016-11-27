#include "FileTranslator.h"


namespace bl
{

FileTranslator::FileTranslator(shared_ptr<StringTranslator> stringTranslator)
: stringTranslator_(stringTranslator)//,
//pathUserAdress_("C:\\")
{	
}

FileTranslator::~FileTranslator()
{
}

void FileTranslator::addStringToFile(const string& str, const string& fullPathAdress)
{
	ofstream fout(fullPathAdress);
	fout << str << endl;
	fout.close();
}

string FileTranslator::textFromFileIntoString(const string& pathFile)
{
	string str = "";
	ifstream fin(pathFile);

	if (!fin.is_open())
	{
		return str;
	}

	getline(fin, str, '\0');
	fin.close();
	return str;
}

string FileTranslator::newNamePachFileTranslate(const string& pathFile)
{
	string delim = ".txt";
	string replacement = ".ru.txt";
	string pachNewFile;
	auto itr = pathFile.find(delim);
	return pachNewFile = pathFile.substr(0, itr) + replacement;
}

const string FileTranslator::TranslateFile(const string& fullPathAdress)
{
	string text = textFromFileIntoString(fullPathAdress);
	if (text == "")
	{
		return "";
	}
	string textTranslate = stringTranslator_->TranslateString(text);
	string nameTranslateFile = newNamePachFileTranslate(fullPathAdress);
	string pathAndNameTranslateFile = pathUserAdress_ + nameTranslateFile;
	addStringToFile(textTranslate, pathAndNameTranslateFile);
	return pathAndNameTranslateFile;
}

void FileTranslator::changeSavedFilePath(const string& filePath)
{
	pathUserAdress_ = filePath;
}

} //namespace bl
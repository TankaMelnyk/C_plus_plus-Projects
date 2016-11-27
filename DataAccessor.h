#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

namespace dl
{

class DataAccessor
{
public:
	bool isDictionaryChanged() const;
	bool insertWord(const string& word, const string& transWord);
	map<string, string> getDictionary();

	DataAccessor(string& dbFilePath);
	~DataAccessor();

private:
	bool isDictionaryChanged_;
	string dbFilePath_;
	ifstream fin_;
	ofstream fout_;
};

} // namespace dl
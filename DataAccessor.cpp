#include "DataAccessor.h"

namespace dl
{

DataAccessor::DataAccessor(string& dbFilePath)
: dbFilePath_(dbFilePath)
{
}

DataAccessor::~DataAccessor()
{
}

bool DataAccessor::isDictionaryChanged() const
{
	return isDictionaryChanged_;
}

string glueWords(const string& word, const string& translateWord)
{
	string delim = " - ";
	string str = word + delim + translateWord;
	return	str;
}

bool DataAccessor::insertWord(const string& word, const string& transWord)
{
	fout_.open(dbFilePath_, ios::app);
	if (!fout_.is_open())
	{
		return false;
	}
	string str = glueWords(word, transWord);
	fout_ << endl << str;
	fout_.close();
	return true;
}

pair<string, string> parseString(const string& buffer)
{
	string first = "";
	string second = "";
	string delim = " - ";

	auto delimPosition = buffer.find(delim);
	if (delimPosition < buffer.size() && delimPosition > 0 && buffer.size() > delimPosition + delim.size() )
	{
		first = buffer.substr(0, delimPosition);
		second = buffer.substr(delimPosition + delim.size(), buffer.size() - delimPosition - delim.size());
	}
	return pair<string, string>(first, second);
}

map<string, string> DataAccessor::getDictionary()
{
	map<string, string> dictionary;
	fin_.open(dbFilePath_);
	if (fin_.is_open())
	{
		string buffer;

		while (!fin_.eof())
		{
			getline(fin_, buffer);
			if (buffer != "")
			{
				pair<string, string> pair = parseString(buffer);
				if (!pair.first.empty() && !pair.second.empty())
				{
					dictionary.insert(pair);
				}
			}
		}
		fin_.close();
	}

	return dictionary;
}

} // namespace dl
#include "StringTranslator.h"

namespace bl
{

	StringTranslator::StringTranslator(shared_ptr<WordTranslator> wordTranslator)
		: wordTranslator_(wordTranslator)
	{
	}


	StringTranslator::~StringTranslator()
	{
	}


	const vector<string> explode(const string& s, const char& c)
	{
		string buff = "";
		vector<string> v;


		for (auto& n : s) //for (auto& n = s.begin(); n != s.end(); ++n) 
		{
			if (n != c)
			{
				buff += n;
			}
			else
			{
				if (n == c && buff != "")
				{
					v.push_back(buff); buff = "";
				}
			}

		}
		if (buff != "") v.push_back(buff);

		return v;
	}

	const string StringTranslator::TranslateString(const string& s) const
	{
		string str = s;
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		vector<string> vec{ explode(str, ' ') };

		string translateString = "";
		for (auto& n : vec)
		{
			string translateWord = wordTranslator_->translateWord(n);
			if (translateWord == "")
			{
				translateString += n + " ";
			}
			translateString += translateWord + " ";

		}
		return translateString;
	}


}
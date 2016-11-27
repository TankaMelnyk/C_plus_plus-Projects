#pragma once

#include <string>
#include <memory>
#include <map>

#include "DataAccessor.h"

using namespace std;


namespace bl
{

class WordSaver
{
public:
	bool saveWord(const string& word, const string& transWord);

	WordSaver(shared_ptr<dl::DataAccessor> dataAccessor);
	~WordSaver();

private:
	map<string, string> dictionary_;
	weak_ptr<dl::DataAccessor> dataAccessor_;
};

}

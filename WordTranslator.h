#pragma once

#include <map>
#include <string>
#include <utility>
#include <memory>

#include "DataAccessor.h"

using namespace std;

namespace bl
{

class WordTranslator
{
public:
	const string translateWord(const string& word) const;

	WordTranslator(shared_ptr<dl::DataAccessor> dataAccessor);
	~WordTranslator();

private:
	map<string, string> dictionary_;
	weak_ptr<dl::DataAccessor> dataAccessor_;
};

}

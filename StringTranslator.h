#pragma once

#include <memory>
#include <vector>
#include <algorithm>

#include "WordTranslator.h"

namespace bl
{

class StringTranslator
{
public:
	const string TranslateString(const string& s) const;

	StringTranslator(shared_ptr<WordTranslator> wordTranslator);
	~StringTranslator();

private:
	shared_ptr<WordTranslator> wordTranslator_;
};

}

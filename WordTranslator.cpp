#include "WordTranslator.h"

namespace bl
{

WordTranslator::WordTranslator(shared_ptr<dl::DataAccessor> dataAccessor)
: dataAccessor_(dataAccessor)
{
	auto dataAccessorOwnership = dataAccessor_.lock();
	dictionary_ = dataAccessorOwnership->getDictionary();
}

WordTranslator::~WordTranslator()
{
}

const string WordTranslator::translateWord(const string& word) const
{
	auto itr = dictionary_.find(word);
	if (itr == dictionary_.end())
	{
		return "";
	}
	return itr->second;
}

}
#include "WordSaver.h"

namespace bl
{

WordSaver::WordSaver(shared_ptr<dl::DataAccessor> dataAccessor)
: dataAccessor_(dataAccessor)
{
	auto dataAccessorOwnership = dataAccessor_.lock();
	dictionary_ = dataAccessorOwnership->getDictionary();
}

WordSaver::~WordSaver()
{
}

bool WordSaver::saveWord(const string& word, const string& transWord)
{
	shared_ptr<dl::DataAccessor> dataAccessorOwnership = dataAccessor_.lock();
	if (dataAccessorOwnership)
	{
		return dataAccessorOwnership->insertWord(word, transWord);
		
	}
	return false;
}

}
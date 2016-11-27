#include "ViewDictionary.h"

namespace bl
{
ViewDictionary::ViewDictionary(shared_ptr<dl::DataAccessor> dataAccessor)
	: dataAccessor_(dataAccessor)
{
	auto dataAccessorOwnership = dataAccessor_.lock();
	dictionary_ = dataAccessorOwnership->getDictionary();
}

ViewDictionary::~ViewDictionary()
{
}

void ViewDictionary::viewDictionary() const
{
	//for (auto it = translator.begin(); it != translator.end(); ++it)
	for (auto it : dictionary_)
	{
		cout << it.first << " - " << it.second <<  endl;
	}
}

}
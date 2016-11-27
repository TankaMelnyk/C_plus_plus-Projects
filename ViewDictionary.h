#pragma once

#include <map>
#include <string>
#include <memory>


#include "DataAccessor.h"

using namespace std;

namespace bl
{

class ViewDictionary
{
public:
	void viewDictionary() const;

	ViewDictionary(shared_ptr<dl::DataAccessor> dataAccessor);
	~ViewDictionary();
private:
	map<string, string> dictionary_;
	weak_ptr<dl::DataAccessor> dataAccessor_;
};

}
#pragma once

#include <memory>

#include "DataAccessor.h"

using namespace std;

class DLWrapper
{
public:
	shared_ptr<dl::DataAccessor> getDataAccessor() const;
	DLWrapper(string dbFilePath);
	~DLWrapper();

private:
	shared_ptr<dl::DataAccessor> dataAccessor_;
};



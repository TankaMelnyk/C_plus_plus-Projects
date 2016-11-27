#include "DLWrapper.h"


DLWrapper::DLWrapper(string dbFilePath)
: dataAccessor_(new dl::DataAccessor(dbFilePath))
{
}


DLWrapper::~DLWrapper()
{
}

shared_ptr<dl::DataAccessor> DLWrapper::getDataAccessor() const
{
	return dataAccessor_;
}

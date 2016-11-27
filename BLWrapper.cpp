#include "BLWrapper.h"


BLWrapper::BLWrapper(shared_ptr<DLWrapper> dlWrapper)
 : dlWrapper_(dlWrapper),
 translateManager_(new bl::TranslateManager(dlWrapper_->getDataAccessor()))
{
}


BLWrapper::~BLWrapper()
{
}

shared_ptr<bl::TranslateManager> BLWrapper::getTranslateManager() const
{
	return translateManager_;
}

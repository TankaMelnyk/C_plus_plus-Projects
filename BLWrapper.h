#pragma once

#include <memory>

#include "TranslateManager.h"
#include "DLWrapper.h"

using namespace std;

class BLWrapper
{
public:
	shared_ptr<bl::TranslateManager> getTranslateManager() const;

	BLWrapper(shared_ptr<DLWrapper> dlWrapper);
	~BLWrapper();

private:
	const BLWrapper& operator=  (BLWrapper& blWrapper);
	BLWrapper(const BLWrapper&);

private:
	shared_ptr<DLWrapper> dlWrapper_;	
	shared_ptr<bl::TranslateManager> translateManager_;

};


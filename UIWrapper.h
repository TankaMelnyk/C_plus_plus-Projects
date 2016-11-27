#pragma once

#include <memory>

#include "View.h"
#include "UiFactory.h"
#include"BLWrapper.h"
#include "TranslateManager.h"

using namespace std;

class UIWrapper
{
public:
	void showView() const;

	UIWrapper(shared_ptr<BLWrapper> blWrapper);
	~UIWrapper();

private:
	const UIWrapper& operator= (UIWrapper& uiWraper);
	UIWrapper(const UIWrapper&);

private:
	weak_ptr<BLWrapper> blWrapper_;
	unique_ptr<ui::View> view_;
	unique_ptr<ui::UiFactory> factory_;

};


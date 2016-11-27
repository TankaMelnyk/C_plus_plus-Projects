#include "UIWrapper.h"


UIWrapper::UIWrapper(shared_ptr<BLWrapper> blWrapper)
: blWrapper_(blWrapper),
view_(new ui::View()),
factory_(new ui::UiFactory(blWrapper->getTranslateManager()))
{
	view_->addScreenWithTransition(
		make_pair(make_pair(ui::Screen_Main, factory_->createScreen_main())
		, factory_->createTransition_main())
		);
	view_->addScreenWithTransition(
		make_pair(make_pair(ui::Screen_EnterWord, factory_->createScreen_enterWord())
		, factory_->createTransition_enterWord())
		);
	view_->addScreenWithTransition(
		make_pair(make_pair(ui::Screen_WordIsNotFound, factory_->createScreen_wordIsNotFound())
		, factory_->createTransition_wordIsNotFound())
		);
	view_->addScreenWithTransition(
		make_pair(make_pair(ui::Screen_EnterString, factory_->createScreen_enterString())
		, factory_->createTransition_enterString())
		);
	view_->addScreenWithTransition(
		make_pair(make_pair(ui::Screen_AddWord, factory_->createScreen_addWord())
		, factory_->createTransition_addWord())
		);
	view_->addScreenWithTransition(
		make_pair(make_pair(ui::Screen_WordIsAdded, factory_->createScreen_wordIsAdded())
		, factory_->createTransition_wordIsAdded())
		);
	view_->addScreenWithTransition(
		make_pair(make_pair(ui::Screen_EnterFile, factory_->createScreen_enterFile())
		, factory_->createTransition_enterFile())
		);
	view_->addScreenWithTransition(
		make_pair(make_pair(ui::Screen_Error, factory_->createScreen_error())
		, factory_->createTransition_error())
		);
	view_->addScreenWithTransition(
		make_pair(make_pair(ui::Screen_Final, factory_->createScreen_final())
		, factory_->createTransition_final())
		);
	view_->addScreenWithTransition(
		make_pair(make_pair(ui::Screen_ViewDictionary, factory_->createScreen_viewDictionary())
		, factory_->createTransitional_viewDictionary())
		);
	view_->addScreenWithTransition(
		make_pair(make_pair(ui::Screen_ProgramSettings, factory_->createScreen_userSettings())
		, factory_->createTransitional_userSettings())
		);
}

UIWrapper::~UIWrapper()
{
}

void UIWrapper::showView() const
{
	view_->startView();
}

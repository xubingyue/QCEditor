#include "CCQApplication.h"
#include "CCQGLView.h"

#include <QTimer>
#include "CCQGLWidget.h"
#include "EditorMain.h"
#include "HelloWorldScene.h"

USING_NS_CC;

/* sharedApplication pointer */
CCQApplication * CCQApplication::sm_pSharedApplication = nullptr;

CCQApplication::CCQApplication(int argc, char *argv[])
    : QApplication(argc, argv)
{
    _qAnimationInterval = 1.0f / 60.0f * 1000.0f;
    CC_ASSERT(! sm_pSharedApplication);
    sm_pSharedApplication = this;
}

CCQApplication::~CCQApplication()
{
    CC_ASSERT(this == sm_pSharedApplication);
    sm_pSharedApplication = nullptr;
}

int CCQApplication::run()
{
	/* Qt Window, default design for 1080P monitor. */
	float width = 640;
	float height = 960;
	CCQGLWidget* window = new CCQGLWidget(width, height);

	window->setWindowFlags(window->windowFlags() & ~Qt::WindowMaximizeButtonHint);
	window->setBaseSize(width, height);
	window->setMinimumSize(500, 500);
	window->setMaximumSize(1920, 1080);

	EditorMain w;
	w.setCentralWidget(window);
	w.show();

	CCQGLView* view = CCQGLView::getInstance();
	auto director = Director::getInstance();
	window->makeCurrent();
	view->init();
	director->setOpenGLView(view);
	view->setFrameSize(width, height);
	//view->setDesignResolutionSize(width, height, ResolutionPolicy::EXACT_FIT);

	applicationDidFinishLaunching();

    return CCQApplication::getInstance()->exec();
}

void CCQApplication::setAnimationInterval(double interval)
{

}

/* static member function */
CCQApplication* CCQApplication::getInstance()
{
    CC_ASSERT(sm_pSharedApplication);
    return sm_pSharedApplication;
}

bool CCQApplication::applicationDidFinishLaunching()
{
	auto director = Director::getInstance();
	auto glview = CCQGLView::getInstance();
	glview->setBgColor(Color4B(50, 50, 50, 255));

	director->runWithScene(HelloWorld::createScene());
	
	return true;
}


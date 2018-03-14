#include "AppDelegate.h"
#include "WelcomeScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
	//FileUtils::getInstance()->addSearchPath("lolita/lolita1");
	//FileUtils::getInstance()->addSearchPath("lolita/lolita2");
	//FileUtils::getInstance()->addSearchPath("lolita/lolita3");
	FileUtils::getInstance()->addSearchPath("lolita");
	FileUtils::getInstance()->addSearchPath("items");
	FileUtils::getInstance()->addSearchPath("buttons");
	FileUtils::getInstance()->addSearchPath("background");
	FileUtils::getInstance()->addSearchPath("setting");
	FileUtils::getInstance()->addSearchPath("loading");
	FileUtils::getInstance()->addSearchPath("ui");
	FileUtils::getInstance()->addSearchPath("font");
	FileUtils::getInstance()->addSearchPath("sound");
	FileUtils::getInstance()->addSearchPath("gun");
	FileUtils::getInstance()->addSearchPath("hit");

    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLView::create("My Game");
        director->setOpenGLView(glview);
    }

	glview->setFrameSize(640,480);
	glview->setDesignResolutionSize(640,480, ResolutionPolicy::FIXED_WIDTH);

    // turn on display FPS
    director->setDisplayStats(false);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    auto scene = WelcomeScene::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

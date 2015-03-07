#include "HelloWorldScene.h"
#include "AppMacros.h"

USING_NS_CC;

bool HelloWorld::sResReady = false;
std::vector<std::string> HelloWorld::sResVector;
unsigned int HelloWorld::sIndex = -1;

void HelloWorld::doTrans(float dt){
	log("do trans from %d", sIndex);
	Director::getInstance()->replaceScene(
			TransitionCrossFade::create(0.5, HelloWorld::scene())
			);
}

Scene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // add the 'mask' layer
	{
    	float width = designResolutionSize.width;
    	float height = 100;//估计值
		auto layerBot = LayerColor::create(Color4B(0, 0, 0, 0xFF), width, height);
		layerBot->setAnchorPoint(Vec2(0, 0));
		layerBot->setPosition(0, 0);
		scene->addChild(layerBot);

		auto layerTop = LayerColor::create(Color4B(0, 0, 0, 0xFF), width, height);
		layerTop->setAnchorPoint(Vec2(0, 0));
		layerTop->setPosition(0, designResolutionSize.height - height);
		scene->addChild(layerTop);
	}
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    // 静态变量初始化
	if (!sResReady) {
		sResReady = true;
		sResVector.push_back("00.jpg");
		sResVector.push_back("01.jpg");
		sResVector.push_back("02.jpg");
		sResVector.push_back("03.jpg");
		sResVector.push_back("04.jpg");

		sResVector.push_back("05.jpg");
		sResVector.push_back("06.jpg");
		sResVector.push_back("07.jpg");
		sResVector.push_back("08.jpg");
		sResVector.push_back("09.jpg");

		sResVector.push_back("10.jpg");
		sResVector.push_back("11.jpg");
		sResVector.push_back("12.jpg");
	}

	sIndex++;// index start from 0

	// make it repeat for ever
	if(sIndex==sResVector.size()){
		sIndex = 0;
	}

	if(sIndex<sResVector.size()){
	    auto visibleSize = Director::getInstance()->getVisibleSize();
	    auto origin = Director::getInstance()->getVisibleOrigin();
	    // add "HelloWorld" splash screen"
	    auto sprite = Sprite::create(sResVector.at(sIndex));

	    // position the sprite on the center of the screen
	    sprite->setPosition(Vec2(visibleSize / 2) + origin);

	    // run the scale action
	    sprite->runAction(ScaleTo::create(4, 1.08f));

	    // add the sprite as a child to this layer
	    this->addChild(sprite);

	    // prepare to do trans
	    scheduleOnce(schedule_selector(HelloWorld::doTrans), 4);
	}


//    /////////////////////////////
//    // 2. add a menu item with "X" image, which is clicked to quit the program
//    //    you may modify it.
//
//    // add a "close" icon to exit the progress. it's an autorelease object
//    auto closeItem = MenuItemImage::create(
//                                        "CloseNormal.png",
//                                        "CloseSelected.png",
//                                        CC_CALLBACK_1(HelloWorld::menuCloseCallback,this));
//
//    closeItem->setPosition(origin + Vec2(visibleSize) - Vec2(closeItem->getContentSize() / 2));
//
//    // create menu, it's an autorelease object
//    auto menu = Menu::create(closeItem, nullptr);
//    menu->setPosition(Vec2::ZERO);
//    this->addChild(menu, 1);
//
//    /////////////////////////////
//    // 3. add your codes below...
//
//    // add a label shows "Hello World"
//    // create and initialize a label
//
//    auto label = LabelTTF::create("Hello World", "Arial", TITLE_FONT_SIZE);
//
//    // position the label on the center of the screen
//    label->setPosition(origin.x + visibleSize.width/2,
//                            origin.y + visibleSize.height - label->getContentSize().height);
//
//    // add the label as a child to this layer
//    this->addChild(label, 1);
//
//    // add "HelloWorld" splash screen"
//    auto sprite = Sprite::create("HelloWorld.png");
//
//    // position the sprite on the center of the screen
//    sprite->setPosition(Vec2(visibleSize / 2) + origin);
//
//    // add the sprite as a child to this layer
//    this->addChild(sprite);
    
    return true;
}

void HelloWorld::menuCloseCallback(Ref* sender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

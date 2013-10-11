#include "SeekSprite.h"
#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(HelloWorld::menuCloseCallback) );
    pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );
    

    // create menu, it's an autorelease object
    this -> schedule(schedule_selector(HelloWorld::UpdateWorld));
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition( CCPointZero );
    this->addChild(pMenu, 1);
    
    /////////////////////////////
    // 3. add your codes below...
    m_SeekingSprite = SeekSprite::create();
    m_SeekingSprite -> initWithFile("Icon-72.png");
    CCPoint tmpP = m_SeekingSprite -> getVehicle() -> getPos();
    m_SeekingSprite -> setAnchorPoint(ccp(0.5, 0.5));
    m_SeekingSprite -> setPosition(tmpP);
    //    SteeringBehaviors *tmpSB = m_SeekingSprite -> getVehicle().getSteering();
    this -> addChild(m_SeekingSprite);
    
    CCLabelTTF *x_axis = CCLabelTTF::create("X", "Arial", 24);
    x_axis -> setPosition(ccp(800, 20));
    this -> addChild(x_axis);
    CCLabelTTF *y_axis = CCLabelTTF::create("Y", "Arial", 24);
    y_axis -> setPosition(ccp(20, 500));
    this -> addChild(y_axis);
    
    CCSprite *targetSprite = CCSprite::create("Icon-72.png");
    targetSprite -> setTag(618);
    targetSprite -> setAnchorPoint(ccp(0.5, 0.5));
    targetSprite -> setPosition(TARGETPOS);
    this -> addChild(targetSprite);
   
    
    
    // add a label shows "Hello World"
    // create and initialize a label
    
    this -> setTouchEnabled(true);
    return true;
}

void  HelloWorld::UpdateWorld(float dt){
    m_SeekingSprite -> update(dt);
    
}
void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


bool HelloWorld::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent){
    CCLOG("%f %f", pTouch -> getLocation().x, pTouch -> getLocation().y);
    CCNode *tmpSprite = this -> getChildByTag(618);
    tmpSprite -> setPosition(pTouch -> getLocation());
    m_SeekingSprite -> getVehicle() -> setTarget(pTouch -> getLocation());
    return true;
}

void HelloWorld::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent){
    CCLOG("%f %f", pTouch -> getLocation().x, pTouch -> getLocation().y);
    CCNode *tmpSprite = this -> getChildByTag(618);
    tmpSprite -> setPosition(pTouch -> getLocation());
    m_SeekingSprite -> getVehicle() -> setTarget(pTouch -> getLocation());

}

void HelloWorld::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent){
    
}

void HelloWorld::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent){
}

void HelloWorld::registerWithTouchDispatcher(){
    CCDirector::sharedDirector() -> getTouchDispatcher() -> addTargetedDelegate(this, 0, true);
}

void HelloWorld::draw(){
    CCNode *tmpSprite = this -> getChildByTag(618);
    ccDrawLine(m_SeekingSprite -> getVehicle() -> getHeading(), tmpSprite -> getPosition());
    ccDrawLine(m_SeekingSprite -> getVehicle() -> getPos(), tmpSprite -> getPosition());
    // 画坐标轴的两条线
    ccDrawLine(ccp(10, 10), ccp(800, 10));
    ccDrawLine(ccp(10, 10), ccp(10, 500));
}
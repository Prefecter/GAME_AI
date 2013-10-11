//
//  SeekSprite.h
//  SteeringBehaviors
//
//  Created by samael on 13-9-18.
//
//

#ifndef __SteeringBehaviors__SeekSprite__
#define __SteeringBehaviors__SeekSprite__
#include "Vehicle.h"
#include "SteeringBehaviors.h"
#include "cocos2d.h"
#include <iostream>
USING_NS_CC;
class SeekSprite : public CCSprite{
public :
    CREATE_FUNC(SeekSprite);
    virtual bool init();
    // 精灵所包含的运动体
    CC_SYNTHESIZE(Vehicle *, m_vVehicle, Vehicle);
    void update(float dt);
private :
    // 设置动作体的运动行为
    SteeringBehaviors *m_sSteering;
};

#endif /* defined(__SteeringBehaviors__SeekSprite__) */

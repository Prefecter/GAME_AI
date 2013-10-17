//
//  SteeringBehaviors.h
//  SteeringBehaviors
//
//  Created by samael on 13-9-18.
//
//

#ifndef __SteeringBehaviors__SteeringBehaviors__
#define __SteeringBehaviors__SteeringBehaviors__
#include "Vehicle.h"
#include "MovingEntity.h"
#include "cocos2d.h"
#include <iostream>
const CCPoint TARGETPOS = ccp(500, 0);
USING_NS_CC;
// 移动行为
class Vehicle;
class SteeringBehaviors {
public:
    void SeekOn(){};
    void SeekOff(){};
    // 计算合力
    CCPoint Calculate();
    CC_SYNTHESIZE_PASS_BY_REF(CCPoint, m_vSteeringForce, SteeringForce)
    SteeringBehaviors(Vehicle *agent);
    virtual ~SteeringBehaviors(){};
    // 移动到目标位置
    CCPoint Seek(CCPoint &TargetPos);
private:
    Vehicle *m_pVehicle;

    
};
#endif /* defined(__SteeringBehaviors__SteeringBehaviors__) */

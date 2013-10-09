//
//  Vehicle.h
//  SteeringBehaviors
//
//  Created by samael on 13-9-18.
//
//

#ifndef __SteeringBehaviors__Vehicle__
#define __SteeringBehaviors__Vehicle__
#include "MovingEntity.h"
#include "SteeringBehaviors.h"
#include "BaseGameEntity.h"
#include <iostream>
USING_NS_CC;
class BaseGameEntity;
class MovingEntity;
class SteeringBehaviors;
class Vehicle : public MovingEntity{
public:

    virtual ~Vehicle(){};
    void Update(double time_elapsed);
    void Render();
    CC_SYNTHESIZE(SteeringBehaviors *, m_pSteering, Steering);
    CC_SYNTHESIZE(CCPoint, m_vTarget, Target);
    Vehicle(CCPoint pos, CCPoint targetPos):MovingEntity(pos),
                         m_vTarget(targetPos){
    }
};

#endif /* defined(__SteeringBehaviors__Vehicle__) */

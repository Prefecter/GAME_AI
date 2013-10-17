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
    CC_SYNTHESIZE(bool, m_bMoving, CanMoving);
    Vehicle(CCPoint pos, CCPoint targetPos):
    MovingEntity(pos, targetPos),
    m_bMoving(false)
    {
    }
};

#endif /* defined(__SteeringBehaviors__Vehicle__) */

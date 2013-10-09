//
//  BaseGameEntity.h
//  SteeringBehaviors
//
//  Created by samael on 13-9-16.
//
//

#ifndef __SteeringBehaviors__BaseGameEntity__
#define __SteeringBehaviors__BaseGameEntity__


#include "cocos2d.h"
#include "CCGeometry.h"
#include <iostream>
USING_NS_CC;
class BaseGameEntity
{
    
private:
    int m_ID;
    int NextValidID(){static int NextID = 0; return NextID++;};
    // 物体当前的位置
    CC_SYNTHESIZE_PASS_BY_REF(CCPoint, m_vPos, Pos);

    CC_SYNTHESIZE_PASS_BY_REF(double, m_dBoundingRadius, BRadius);
public:
    virtual ~BaseGameEntity(){};
    BaseGameEntity(CCPoint pos):m_ID(NextValidID())

    {m_vPos = pos;};

    virtual void Update(){};
    virtual void Render() = 0;

};
#endif /* defined(__SteeringBehaviors__BaseGameEntity__) */

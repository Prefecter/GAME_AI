//
//  MovingEntity.h
//  SteeringBehaviors
//
//  Created by samael on 13-9-17.
//
//

#ifndef __SteeringBehaviors__MovingEntity__
#define __SteeringBehaviors__MovingEntity__
#include "BaseGameEntity.h"
#include <iostream>
class MovingEntity : public BaseGameEntity{
    
    // 当前速度
    CC_SYNTHESIZE_PASS_BY_REF(CCPoint, m_vVelocity, Velocity);
    // 面对的方向
    CC_SYNTHESIZE_PASS_BY_REF(CCPoint, m_vHeading, Heading);
    // 行进最大速度
    CC_SYNTHESIZE_PASS_BY_REF(double, m_dMaxSpeed, MaxSpped);
    // 最大转弯
    CC_SYNTHESIZE_PASS_BY_REF(double, m_dMaxTurnRate, MaxTurnRate);
    // 最大推力
    CC_SYNTHESIZE_PASS_BY_REF(double, m_dMaxForce, MaxForce);
    // 物体质量
    CC_SYNTHESIZE_PASS_BY_REF(double, m_dMass, Mass);
    CC_SYNTHESIZE_PASS_BY_REF(CCPoint, m_vSide, Side);
    CC_SYNTHESIZE_PASS_BY_REF(double, m_dDegress, Degress);
    CC_SYNTHESIZE(CCPoint, m_vTarget, Target);
public:
    MovingEntity(CCPoint pos, CCPoint targetPos):
    BaseGameEntity(pos),
    m_vHeading(ccp(0, 4)),
    m_vVelocity(ccpNormalize(m_vHeading)),
    m_dMass(10),
    m_vSide(ccp(0, 10)),
    m_dMaxSpeed(50.0),
    m_dMaxTurnRate(5),
    m_dMaxForce(1.0),
    m_dDegress(0),
    m_vTarget(targetPos)
    {
        
    }
    virtual ~MovingEntity(){};
    double isFaceToTheTarget(){
        // 通过三角函数判断是否是面对
        double d1 = ccpDistance(m_vTarget, m_vPos);
        double d4 = ccpDistance(m_vPos, m_vHeading);
        double d6 = ccpDistance(m_vTarget, m_vHeading);
        double x1 = m_vPos.x, y1 = m_vPos.y;
        double x2 = m_vHeading.x, y2 = m_vHeading.y;
        double x3 = m_vTarget.x, y3 = m_vTarget.y;

        if(isThreePointInALine(x1, y1, x2, y2, x3, y3) && fabs(d4 + d6 - d1) <= 0.1){
            return  true;
        }
        return false;
    };
    bool isThreePointInALine(double x1, double y1, double x2, double y2, double x3, double y3 ){

        float d1 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        float d2 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
        float d3 = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
        // 判断d1, d2, d3是否有两个值相加等于第三个值的情况
        if ((fabs(d1 + d2 - d3) <= 0.1) ||
            (fabs(d1 + d3 - d2) <= 0.1) ||
            (fabs(d2 + d3 - d1) <= 0.1))
        {
            return true;
        }
        return false;
    }
    void FaceToTarget(){
        float range = ccpDistance(m_vPos, m_vTarget);
        float o = m_vTarget.x - m_vPos.x;
        float a = m_vTarget.y - m_vPos.y;
        float at= (float) CC_RADIANS_TO_DEGREES(atanf(o/a));
        if(a < 0){
            if(o < 0){
                at = 180 + fabs(at);
            }else{
                at = 180 - fabs(at);
            }
        }
        m_dDegress = at;
    }
};
#endif /* defined(__SteeringBehaviors__MovingEntity__) */

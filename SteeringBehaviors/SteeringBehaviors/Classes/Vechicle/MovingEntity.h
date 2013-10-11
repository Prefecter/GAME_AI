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
public:
    MovingEntity(CCPoint pos):
    BaseGameEntity(pos),
    m_vHeading(ccp(pos.x, pos.y + 50)),
    m_vVelocity(ccp(10, 0)),
    m_dMass(10),
    m_vSide(ccp(0, 10)),
    m_dMaxSpeed(50.0),
    m_dMaxTurnRate(5),
    m_dMaxForce(10.0),
    m_dDegress(0)
    {
        
    }
    virtual ~MovingEntity(){};
    double isFaceToTheTarget(const CCPoint &target){
        
        // 通过三角函数判断是否是面对
        double d1 = ccpDistance(target, m_vPos);
        double d2 = target.x - m_vPos.x;
        double d3 = m_vHeading.x - m_vPos.x;
        double d4 = ccpDistance(m_vPos, m_vHeading);
        double d6 = ccpDistance(target, m_vHeading);
        double x1 = m_vPos.x, y1 = m_vPos.y;
        double x2 = m_vHeading.x, y2 = m_vHeading.y;
        double x3 = target.x, y3 = target.y;
        double t1 = d2 / (y3 - y1);
        double t2 = (x3 - x2) / (y3 - y2);

        if(isThreePointInALine(x1, y1, x2, y2, x3, y3) && d4 + d6 - d1 <= 0.05){
            return  0;
        }else{
            if(t1 < t2){
                this -> setHeading(ccpRotateByAngle(m_vHeading, m_vPos, CC_DEGREES_TO_RADIANS(-5)));
                m_dDegress += 5;
                m_dDegress = (int)m_dDegress % 360;
            }else{
                this -> setHeading(ccpRotateByAngle(m_vHeading, m_vPos, CC_DEGREES_TO_RADIANS(5)));
                m_dDegress -= 5;
                m_dDegress = (int)m_dDegress % 360;
            }
            CCLOG("%f %f", t1, t2);
        }
        return m_dDegress;
        
    };
    bool isThreePointInALine(double x1, double y1, double x2, double y2, double x3, double y3 ){

        float d1 = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
        float d2 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
        float d3 = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
        // 判断d1, d2, d3是否有两个值相加等于第三个值的情况
        if ((fabs(d1 + d2 - d3) <=  0.05) ||
            (fabs(d1 + d3 - d2) <= 0.05) ||
            (fabs(d2 + d3 - d1) <=  0.05))
        {
            return true;
        }
        return false;
    }
};
#endif /* defined(__SteeringBehaviors__MovingEntity__) */

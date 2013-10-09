//
//  Vehicle.cpp
//  SteeringBehaviors
//
//  Created by samael on 13-9-18.
//
//

#include "Vehicle.h"
void Vehicle::Update(double time_elapsed){
    
//    CCPoint SteeringForce = m_pSteering -> Calculate();
//    CCLOG("%f,%f", this -> getPos().x, this -> getPos().y);
//    CCPoint accleration = ccp(SteeringForce.x/m_dMass, SteeringForce.y/m_dMass);
//    // 数乘
//    accleration = ccpMult(accleration, time_elapsed);
//    // 向量加
//    m_vVelocity = ccpAdd(m_vVelocity, accleration);
//
//    // 更新位置
//    m_vPos = m_vPos + ccpMult(m_vVelocity, time_elapsed);
    
    double tmpAngle = this -> isFaceToTheTarget(m_vTarget);
    
//    m_vPos = m_vPos + ccp(1, 0);


}

void Vehicle::Render(){
    
};

//
//  SteeringBehaviors.cpp
//  SteeringBehaviors
//
//  Created by samael on 13-9-18.
//
//

#include "SteeringBehaviors.h"
SteeringBehaviors::SteeringBehaviors(Vehicle *agent){
    m_pVehicle = agent;
    m_vSteeringForce = ccp(0, 0);
}

CCPoint SteeringBehaviors::Calculate(){
    CCPoint tmpPos = TARGETPOS;
//    m_vSteeringForce = ccp(0, 0);
    m_vSteeringForce = m_vSteeringForce + this -> Seek(tmpPos);
//    m_vSteeringForce = this -> Seek(tmpPos);
//    CCLOG("hello m_vSteeringForce %f %f", m_vSteeringForce.x, m_vSteeringForce.y);
    return m_vSteeringForce;
}


//
//        TargetPos
//   ^   /
//   |  /
//   | /
//   |/
//   v----->
//     Seek
CCPoint SteeringBehaviors::Seek(CCPoint &TargetPos){
    CCPoint tmpPos1 = ccpMult(ccpNormalize(TargetPos), m_pVehicle -> getMaxForce());
    CCPoint tmpPos2 = ccpSub(tmpPos1, m_pVehicle -> getVelocity());
    return tmpPos2;
    
}
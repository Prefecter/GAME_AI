//
//  Vehicle.cpp
//  SteeringBehaviors
//
//  Created by samael on 13-9-18.
//
//

#include "Vehicle.h"
void Vehicle::Update(double time_elapsed){
    
    this -> FaceToTarget();
    m_vPos = m_vPos + ccpMult(ccpNormalize(ccpSub(m_vTarget, m_vPos)), 1);
}

void Vehicle::Render(){
    ;
}

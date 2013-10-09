//
//  SeekSprite.cpp
//  SteeringBehaviors
//
//  Created by samael on 13-9-18.
//
//

#include "SeekSprite.h"

bool SeekSprite::init()
{
    bool bRet = false;
    do{
        CC_BREAK_IF(!CCSprite::init());
        m_vVehicle = new Vehicle(ccp(200,100), TARGETPOS);
        m_sSteering = new SteeringBehaviors(m_vVehicle);
        m_vVehicle -> setSteering(m_sSteering);
        bRet = true;
    }while(0);
    return bRet;
}

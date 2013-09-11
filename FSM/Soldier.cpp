#include "State.h"
#include "BaseGameEntity.h"
#include <iostream>
Soldier::Soldier(int id):BaseGameEntity(id),
                         m_iButtletInPocket(200),
                         m_iBulletInMagazine(20),
                         m_iFatigue(200),
                         m_pCurrentState(State_Patrol::Instance())
{}
void Soldier::Update()
{
  if(m_pCurrentState){
    m_pCurrentState -> Execute(this);
  }
}

void Soldier::ChangeState(State* pNewState){
  // 更改状态
  m_pCurrentState = pNewState;
}

int Soldier::getBulletNumInMagazine()
{
  return m_iBulletInMagazine;
}

int Soldier::getBulletNumInPocket()
{
  return m_iButtletInPocket;
}

void Soldier::reloadBullet()
{

  if(this -> m_iButtletInPocket - 10 >= 0){
    this -> m_iButtletInPocket -= 10;
    this -> m_iBulletInMagazine += 10;
  }else{
    this -> m_iButtletInPocket = 10;
    this -> m_iBulletInMagazine += this -> m_iButtletInPocket;
  }
}

void Soldier::setBulletNumInMagazine(int v)
{
  
}
void Soldier::setBulletNumInPocket(int v)
{
  
}


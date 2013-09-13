#include "State.h"
#include "BaseGameEntity.h"
#include <iostream>
Soldier::Soldier(int id):BaseGameEntity(id),
                         m_iButtletInPocket(20),
                         m_iBulletInMagazine(10),
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
  std::cout << "pocket in " << m_iButtletInPocket << std::endl;
  if(this -> m_iButtletInPocket - 10 > 0){
    this -> m_iButtletInPocket -= 10;
    this -> m_iBulletInMagazine += 10;
  }else{
    this -> m_iBulletInMagazine += this -> m_iButtletInPocket;
    this -> m_iButtletInPocket = 0;

  }

}

void Soldier::setBulletNumInMagazine(int v)
{
  this -> m_iBulletInMagazine = v;
}
void Soldier::setBulletNumInPocket(int v)
{
  this -> m_iButtletInPocket = v;
}


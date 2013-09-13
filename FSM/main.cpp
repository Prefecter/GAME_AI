#include <iostream>
#include "State.h"
#include "BaseGameEntity.h"
int main()
{
  Soldier soldier(1);
  soldier.Update();
  int bulletInPocket = soldier.getBulletNumInPocket();
  int bulletInMan = soldier.getBulletNumInMagazine();
  soldier.ChangeState(State_Attack::Instance());
  
  while(1){
    bulletInPocket = soldier.getBulletNumInPocket();
    bulletInMan = soldier.getBulletNumInMagazine();
    if(bulletInMan <= 0)
      if(bulletInPocket > 0){
        soldier.ChangeState(State_Cover::Instance());
        soldier.Update();
        soldier.ChangeState(State_Attack::Instance());
      }else{
        soldier.ChangeState(State_Wait::Instance());
        soldier.Update();
        break;
      }
    soldier.Update();
  }
  return 0;
}

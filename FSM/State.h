#ifndef __State__
#define __State__
#include <iostream>
#include "BaseGameEntity.h"
class State
{
 public:
  virtual void Execute(Soldier *soldier) = 0;
 };

class State_Cover : public State
{
 public :
  static State_Cover *Instance(){
    static State_Cover instance;
    return &instance;
  }
  virtual void Execute(Soldier *soldier){
    if(soldier -> getBulletNumInMagazine() <= 0){
      soldier -> reloadBullet();
      std::cout << "covering" << std::endl;
    }
  }
};

class State_Attack : public State
{
 public:
  static State_Attack *Instance(){
    static State_Attack instance;
    return &instance;
  }

  virtual void Execute(Soldier *soldier){
    if(soldier -> getBulletNumInMagazine() > 0){
      std::cout << "attacking" << std::endl;
    }else{
      State_Cover * state_cover = new State_Cover();
      soldier -> ChangeState(state_cover);
    }
  }
};

class State_Patrol : public State
{
 public:
  static State_Patrol *Instance(){
    static State_Patrol instance;
    return &instance;
  }

  virtual void Execute(Soldier *soldier){
    std::cout << "patroling" << std::endl;
  }
};
class State_Wait : public State
{
 public:
  static State_Wait *Instance(){
    static State_Wait instance;
    return &instance;
  }

  virtual void Execute(Soldier *soldier){
    if(soldier -> getBulletNumInPocket() <= 0){
      std::cout << "waiting" << std::endl;
    }
  }
};

#endif

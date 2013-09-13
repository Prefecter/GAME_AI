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
      std::cout << "covering and reloading" << std::endl;
      soldier -> reloadBullet();
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
    int cost_buttlet = 1;
    int temp = soldier -> getBulletNumInMagazine();
    soldier -> setBulletNumInMagazine(temp - 5);
    std::cout << "attacking " << soldier -> getBulletNumInMagazine() << std::endl;
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
      std::cout << "waiting" << std::endl;
  }
};

#endif

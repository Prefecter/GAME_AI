#ifndef __BaseGameEntity__
#define __BaseGameEntity__
class State;
class BaseGameEntity
{
 private:
  int m_ID;
  void SetID(int val);
 public:
  BaseGameEntity(int id){
    SetID(id);
  }
  virtual ~BaseGameEntity(){};
  virtual void Update() = 0;
  int ID() const {return m_ID;}
};

class Soldier : public BaseGameEntity
{
 private:
  // 士兵的状态
  State* m_pCurrentState;
  // 身上的子弹数
  int m_iButtletInPocket;
  // 弹夹的子弹数
  int m_iBulletInMagazine;
  // 体力
  int m_iFatigue;
 public:
  Soldier(int ID);
  void Update();
  // 如果有子弹就攻击，没有子弹就回避
  void ChangeState(State* pNewState);
  int getBulletNumInMagazine();
  int getBulletNumInPocket();
  void setBulletNumInMagazine(int v);
  void setBulletNumInPocket(int v);
  void reloadBullet();

};
#endif

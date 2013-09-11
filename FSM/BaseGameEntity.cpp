#include "BaseGameEntity.h"
#include <iostream>
void BaseGameEntity::SetID(int id){
  this -> m_ID = id;
  std::cout << "the ID is " << this -> m_ID << std::endl;
}


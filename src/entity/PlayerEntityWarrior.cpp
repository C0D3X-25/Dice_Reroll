#include "PlayerEntityWarrior.hpp"  
#include "../capacity/CapacityPlayerSingleAttack.hpp"  

using namespace capacity;  

entity::PlayerEntityWarrior::PlayerEntityWarrior(const std::string& name, const int16_t life, const int16_t armor)
    : BasePlayerEntity(name, life, armor)
{  
    setCapacity(std::make_shared<CapacityPlayerSingleAttack>(*this), 1);
    setCapacity(std::make_shared<CapacityPlayerSingleAttack>(*this), 3);
    setCapacity(std::make_shared<CapacityPlayerSingleAttack>(*this), 10);
}

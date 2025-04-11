#include "../../include/entity/BasePlayerEntity.hpp"


entity::BasePlayerEntity::BasePlayerEntity(const std::string& name, const int16_t life, const int16_t armor)
	: m_name(name), m_life(life), m_armor(armor)
{

}


void entity::BasePlayerEntity::setCapacity(const std::shared_ptr<BaseCapacity> sp_capacity, const uint8_t side) {
    m_up_dice_capacity->setCapacity(sp_capacity, side);
}


//const BaseCapacity& entity::BasePlayerEntity::rollDiceCapacity(void) const {
//    return *m_up_dice_capacity->roll();
//}


void entity::BasePlayerEntity::printEntity(void) {
	std::cout
		<< "Name: " << m_name
		<< " | Life: " << m_life
		<< " | Armor: " << m_armor
		<< '\n';

	m_up_dice_capacity->printDice();
}


void entity::BasePlayerEntity::useCapacity(const BaseCapacity& capacity, IEntity& target) {
	std::cout
		<< m_name
		<< " use capacity " << capacity.getName()
		<< " on " << target.getName()
		<< '\n';

	//target.resolveCapacity(capacity.getStats(), *this);
}


void entity::BasePlayerEntity::resolveCapacity(const SCapacityModifiers& capacity, const IEntity& source) {
    // Initialize modifiers
    int16_t dmg_life = capacity.m_life < 0 ? -capacity.m_life : 0;
    int16_t heal_life = capacity.m_life > 0 ? capacity.m_life : 0;
    int16_t remove_armor = capacity.m_armor < 0 ? -capacity.m_armor : 0;
    int16_t add_armor = capacity.m_armor > 0 ? capacity.m_armor : 0;

    if (dmg_life > 0) {
        std::cout << m_name << " took (" << dmg_life << ") damage from "
            << source.getName() << '\n';
    }

    // First apply armor modifications
    if (remove_armor > 0) {
        m_armor = std::max(0, m_armor - remove_armor);
    }
    if (add_armor > 0) {
        m_armor += add_armor;
    }

    // Then handle damage
    if (dmg_life > 0) {
        // Damage is first absorbed by armor
        if (m_armor > 0) {
            if (m_armor >= dmg_life) {
                m_armor -= dmg_life;
                dmg_life = 0;
            }
            else {
                dmg_life -= m_armor;
                m_armor = 0;
            }
        }

        // Remaining damage goes to life
        if (dmg_life > 0) {
            m_life -= dmg_life;
        }
    }

    // Apply healing
    if (heal_life > 0) {
        m_life += heal_life;
    }

    // Check for death
    if (m_life <= 0) {
        std::cout << m_name << " has been killed by " << source.getName() << '\n';
    }

    printEntity();
    std::cout << '\n';
}



std::string entity::BasePlayerEntity::getName(void) const {
	return m_name;
}
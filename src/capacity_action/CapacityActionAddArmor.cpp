#include "CapacityActionAddArmor.hpp"

using namespace capacity;

//CapacityActionAddArmor::CapacityActionAddArmor(uint8_t armor, ECapacityTarget target)
//	: m_max_armor(armor), m_target(target) {
//}


CapacityComponent capacity::CapacityActionAddArmor::doAction(void) {
	CapacityComponent modifiers;
	modifiers.m_add_armor = m_armor;
	return modifiers;
}




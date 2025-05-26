#include "CapacityActionRemoveArmor.hpp"

using namespace capacity;

//capacity::CapacityActionRemoveArmor::CapacityActionRemoveArmor(uint8_t armor)
//	: m_max_armor(armor) {
//}

capacity::CapacityComponent CapacityActionRemoveArmor::doAction(void) {
	CapacityComponent modifiers;
	modifiers.m_remove_armor = m_armor;
	return modifiers;
}

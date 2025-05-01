#include "CapacityActionAddArmor.hpp"

using namespace capacity;

//CapacityActionAddArmor::CapacityActionAddArmor(uint8_t armor, CapacityTargetEnum target)
//	: m_armor(armor), m_target(target) {
//}


CapacityModifiersStruct capacity::CapacityActionAddArmor::doAction(void) {
	CapacityModifiersStruct modifiers;
	modifiers.m_add_armor = m_armor;
	return modifiers;
}




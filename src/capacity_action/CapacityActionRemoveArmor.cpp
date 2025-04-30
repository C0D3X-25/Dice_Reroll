#include "CapacityActionRemoveArmor.hpp"

using namespace capacity;

capacity::CapacityActionRemoveArmor::CapacityActionRemoveArmor(uint8_t armor)
	: m_armor(armor) {
}

capacity::CapacityModifiersStruct CapacityActionRemoveArmor::doAction(void) {
	CapacityModifiersStruct modifiers;
	modifiers.m_remove_armor = m_armor;
	return modifiers;
}

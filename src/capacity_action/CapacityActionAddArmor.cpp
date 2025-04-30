#include "CapacityActionAddArmor.hpp"

using namespace capacity;

CapacityActionAddArmor::CapacityActionAddArmor(uint8_t armor)
	: m_armor(armor) {
}

CapacityModifiersStruct CapacityActionAddArmor::doAction(void) {
	CapacityModifiersStruct modifiers;
	modifiers.m_add_armor = m_armor;
	return modifiers;
}


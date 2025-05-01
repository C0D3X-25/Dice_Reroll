#include "CapacityActionHeal.hpp"

using namespace capacity;

//capacity::CapacityActionHeal::CapacityActionHeal(uint8_t heal)
//	: m_heal(heal) {
//}

CapacityModifiersStruct capacity::CapacityActionHeal::doAction(void) {
	CapacityModifiersStruct modifiers;
	modifiers.m_heal = m_heal;
	return modifiers;
}
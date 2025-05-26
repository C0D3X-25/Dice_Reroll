#include "CapacityActionHeal.hpp"

using namespace capacity;

//capacity::CapacityActionHeal::CapacityActionHeal(uint8_t heal)
//	: m_heal(heal) {
//}

CapacityComponent capacity::CapacityActionHeal::doAction(void) {
	CapacityComponent modifiers;
	modifiers.m_heal = m_heal;
	return modifiers;
}
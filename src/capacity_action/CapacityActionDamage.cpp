#include "CapacityActionDamage.hpp"

#include <cstdint>

using namespace capacity;

CapacityActionDamage::CapacityActionDamage(uint8_t damage)
	: m_damage(damage)
{}


CapacityModifiersStruct CapacityActionDamage::doAction(void) {
	CapacityModifiersStruct mod;
	mod.m_damage = m_damage;
	return mod;
}

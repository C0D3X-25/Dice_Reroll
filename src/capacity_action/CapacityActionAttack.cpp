#include "CapacityActionAttack.hpp"
#include <cstdint>

using namespace capacity;

CapacityActionAttack::CapacityActionAttack(uint8_t damage)
	: m_damage(damage)
{}


CapacityModifiersStruct CapacityActionAttack::doAction(void) {
	CapacityModifiersStruct mod;
	mod.m_damage = m_damage;
	return mod;
}

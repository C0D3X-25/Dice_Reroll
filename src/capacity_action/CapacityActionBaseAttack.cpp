#include "CapacityActionBaseAttack.hpp"

using namespace capacity;

CapacityActionAttack::CapacityActionAttack(uint8_t damage)
	: m_damage(damage)
{}


SCapacityModifiers CapacityActionAttack::doAction(void) {
	SCapacityModifiers mod;
	mod.m_life = -m_damage;
	return mod;
}

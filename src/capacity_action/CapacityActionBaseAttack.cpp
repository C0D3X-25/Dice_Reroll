#include "../../include/capacity_action/CapacityActionBaseAttack.hpp"

using namespace capacity;

CapacityActionBaseAttack::CapacityActionBaseAttack(uint8_t dmg)
	: m_dmg(dmg)
{}


SCapacityModifiers CapacityActionBaseAttack::doAction(void) {
	SCapacityModifiers mod;
	mod.m_life = -m_dmg;
	return mod;
}

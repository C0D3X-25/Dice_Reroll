#include "CapacityActionDamage.hpp"

using namespace capacity;

CapacityActionDamage::CapacityActionDamage(const uint8_t damage, const std::vector<ECapacityTarget>& targets)
	: m_damage(damage), BaseCapacityAction(targets) {}


CapacityComponent capacity::CapacityActionDamage::doAction(void) {
	m_modifier = BaseCapacityAction::doAction();
	m_modifier.m_damage = m_damage;
	return m_modifier;
}

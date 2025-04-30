#pragma once 

#include "BaseCapacity.hpp"
#include "../capacity_action/CapacityActionDamage.hpp"
#include "../attribute/Attribute.hpp"
#include "../entity/BaseEntity.hpp" 


namespace capacity {

	using namespace entity;
	using namespace attribute;

	class CapacityPlayerSingleAttack : public BaseCapacity {
	public:

		CapacityPlayerSingleAttack(const BaseEntity& user) {

			m_name = "Attack";

			int8_t base_damage = 5;
			int8_t best_between_dex_str = std::max(user.getStrength(), user.getDexterity());
			int8_t total_damage = base_damage + best_between_dex_str;

			CapacityActionDamage attack(total_damage >= 1 ? total_damage : 1);

			queueCapacityModifier(attack.doAction());
		}
		~CapacityPlayerSingleAttack(void) = default;
	};
} // namespace capacity

#pragma once 

#include "BaseCapacity.hpp"
#include "../capacity_action/CapacityActionDamage.hpp"
#include "../attribute/Attribute.hpp"
#include "../entity/BaseEntity.hpp" 

#include <vector>

namespace capacity {

	using namespace entity;
	using namespace attribute;

	class CapacityPlayerSingleAttack : public BaseCapacity {
	public:

		CapacityPlayerSingleAttack(const BaseEntity& user) {

				setCapacityName("Attack");
				setCapacityPurposes({ ATTACK_PHYSICAL });
				setCapacityTriggers({ USED_WHEN_TURN_END });

				// Take the best between dexterity and strength
			{
				std::vector<CapacityTargetEnum> targets{ TARGET_ALIVE, TARGET_SINGLE, TARGET_ENNEMY };

				constexpr int8_t min_damage{ 1 };
				constexpr int8_t base_damage{ 5 };
				int8_t best_between_dex_str = std::max(user.getStrength(), user.getDexterity());
				int8_t total_damage = base_damage + best_between_dex_str;

				CapacityActionDamage attack(total_damage >= min_damage ? total_damage : min_damage, targets);
				queueCapacityModifier(attack.doAction());
			}

				// Take the best between dexterity and strength
			{
				std::vector<CapacityTargetEnum> targets{ TARGET_ALIVE, TARGET_RANDOM, TARGET_ENNEMY };

				constexpr int8_t min_damage{ 1 };
				constexpr int8_t base_damage{ 5 };
				int8_t best_between_dex_str = std::max(user.getStrength(), user.getDexterity());
				int8_t total_damage = base_damage + best_between_dex_str;

				CapacityActionDamage attack(total_damage >= min_damage ? total_damage : min_damage, targets);
				queueCapacityModifier(attack.doAction());
			}
		}
		~CapacityPlayerSingleAttack(void) = default;
	};
} // namespace capacity

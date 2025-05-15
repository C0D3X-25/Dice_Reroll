#pragma once 

#include "BaseCapacity.hpp"
#include "../capacity_action/CapacityActionDamage.hpp"
#include "../attribute/Attribute.hpp"
#include "../entity/BaseEntity.hpp" 
#include "../helper/SCalculate.hpp"

#include <vector>

namespace capacity {

	using namespace entity;
	using namespace attribute;

	class CapacityFactory {
	public:

		CapacityFactory(void) {}
		~CapacityFactory(void) = default;

		BaseCapacity nothing(void) {
			BaseCapacity capacity;
			capacity.setCapacityName("Nothing");
			capacity.setCapacityDescription("Just skip your turn");
			return capacity;
		}


		BaseCapacity attackSingle(const BaseEntity& user) {
			BaseCapacity capacity;
			capacity.setCapacityName("1 Attack");
			capacity.setCapacityDescription("Attack a single ennemy with STR or DEX");
			capacity.setCapacityPurposes({ ATTACK_PHYSICAL });
			capacity.setCapacityTriggers({ USED_WHEN_TURN_END });

			// Take the best between dexterity and strength
			{
				std::vector<ECapacityTarget> targets{ TARGET_ALIVE, TARGET_SINGLE, TARGET_ENNEMY };
				constexpr int8_t min_damage{ 1 };
				constexpr int8_t base_damage{ 3 };
				int8_t total_damage = base_damage + helper::calculate::getBestValue(user.getStrength(), user.getDexterity(), min_damage);
				CapacityActionDamage attack(total_damage, targets);
				capacity.queueCapacityModifier(attack.doAction());
			}
			return capacity;
		}


		BaseCapacity attackRandom(const BaseEntity& user) {
			BaseCapacity capacity;
			capacity.setCapacityName("1 Attack and 1 Random Attack");
			capacity.setCapacityDescription("Attack a single ennemy with STR or DEX, then attack a random ennemy with STR or DEX");
			capacity.setCapacityPurposes({ ATTACK_PHYSICAL });
			capacity.setCapacityTriggers({ USED_WHEN_TURN_END });

			// Take the best between dexterity and strength
			{
				std::vector<ECapacityTarget> targets{ TARGET_ALIVE, TARGET_SINGLE, TARGET_ENNEMY };

				constexpr int8_t min_damage{ 1 };
				constexpr int8_t base_damage{ 3 };
				int8_t total_damage = base_damage + helper::calculate::getBestValue(user.getStrength(), user.getDexterity(), min_damage);

				CapacityActionDamage attack(total_damage, targets);
				capacity.queueCapacityModifier(attack.doAction());
			}

			// Take the best between dexterity and strength
			{
				std::vector<ECapacityTarget> targets{ TARGET_ALIVE, TARGET_RANDOM, TARGET_ENNEMY };

				constexpr int8_t min_damage{ 1 };
				constexpr int8_t base_damage{ 5 };
				int8_t total_damage = base_damage + helper::calculate::getBestValue(user.getStrength(), user.getDexterity(), min_damage);

				CapacityActionDamage attack(total_damage, targets);
				capacity.queueCapacityModifier(attack.doAction());
			}
			return capacity;
		}
	};
} // namespace capacity

#pragma once

#include "BaseEntity.hpp"
#include "../capacity/BaseCapacity.hpp"
#include "../dice/DiceCapacity.hpp"
#include "../capacity/IUseAndResolveCapacity.hpp"
#include "../helper/SCalculate.hpp"

#include <iostream>
#include <string>
#include <memory>
#include <cstdint>



namespace entity {

	using namespace dice;
	using namespace capacity;

	inline constexpr uint8_t BASE_MAX_LIFE{ 20 };
	inline constexpr uint8_t BASE_MIN_LIFE{ 1 };
	inline constexpr uint8_t BASE_MAX_ARMOR{ 2 };
	inline constexpr uint8_t BASE_MIN_ARMOR{ 0 };

	class BasePlayerEntity : public BaseEntity, 
		public IUseAndResolveCapacity {
	
	public:
		BasePlayerEntity(const std::string& name);
		virtual ~BasePlayerEntity(void) = default;
		//BasePlayerEntity(const BasePlayerEntity& other);
		//BasePlayerEntity& operator=(const BasePlayerEntity& other);

		/**
		* @brief Assigns a capacity to a specific side of the dice capacity
		* @param sp_capacity The capacity to assign
		* @param side The side number to assign the capacity to (1-10)
		*/
		void setCapacity(const BaseCapacity& sp_capacity, const uint8_t side);

		const BaseCapacity rollDiceCapacity(void);
		
		void useCapacity(const BaseCapacity& capacity, BaseEntity& target) override;
		void resolveCapacity(const CapacityComponent& capacity, const BaseEntity& source) override {

			//TODO: use the pattern chain of responsibility to resolve the capacity
			
			//// Initialize modifiers
			//int16_t dmg_life = capacity.m_max_life < 0 ? -capacity.m_max_life : 0;
			//int16_t heal_life = capacity.m_max_life > 0 ? capacity.m_max_life : 0;
			//int16_t remove_armor = capacity.m_max_armor < 0 ? -capacity.m_max_armor : 0;
			//int16_t add_armor = capacity.m_max_armor > 0 ? capacity.m_max_armor : 0;

			//if (dmg_life > 0) {
			//    std::cout << m_name << " took (" << dmg_life << ") damage from "
			//        << source.getEntityName() << '\n';
			//}

			//// First apply armor modifications
			//if (remove_armor > 0) {
			//    m_max_armor = std::max(0, m_max_armor - remove_armor);
			//}
			//if (add_armor > 0) {
			//    m_max_armor += add_armor;
			//}

			//// Then handle damage
			//if (dmg_life > 0) {
			//    // Damage is first absorbed by armor
			//    if (m_max_armor > 0) {
			//        if (m_max_armor >= dmg_life) {
			//            m_max_armor -= dmg_life;
			//            dmg_life = 0;
			//        }
			//        else {
			//            dmg_life -= m_max_armor;
			//            m_max_armor = 0;
			//        }
			//    }

			//    // Remaining damage goes to life
			//    if (dmg_life > 0) {
			//        m_max_life -= dmg_life;
			//    }
			//}

			//// Apply healing
			//if (heal_life > 0) {
			//    m_max_life += heal_life;
			//}

			//// Check for death
			//if (m_max_life <= 0) {
			//    std::cout << m_name << " has been killed by " << source.getEntityName() << '\n';
			//}

			//printEntity();
			//std::cout << '\n';
		}

		void printEntity(void) const override;

		void resetToDefaultValues(void) {
			updateEntity();
			m_current_life = m_max_life;
			m_current_armor = m_max_armor;
		}

	//protected:

		void updateEntity(void) override {
			calculateMaxLife();
			calculateMaxArmor();
		}

	private:

		void calculateMaxLife(void) {

			int16_t max_life{ BASE_MAX_LIFE };
			// TODO: max_life += bonus_life;
			max_life += int16_t(m_attributes.getConstitution() * 1.5);

			setMaxLife(max_life);
		}


		// Calculate the maximum armor value based on the attributes
		// best physic = max(strength, dexterity)
		// best psychic = max(wisdom, intelligence, charisma)
		// max_armor = base_max_armor + best_physic + best_psychic
		void calculateMaxArmor(void) {

			// TODO: max_armor += bonus_armor;
			int16_t best_physic{ helper::calculate::getBestValue<int16_t>( m_attributes.getStrength(), m_attributes.getDexterity(), 0) };
			int16_t best_psychic{ helper::calculate::getBestValue<int16_t>(m_attributes.getWisdom(), m_attributes.getIntelligence(), m_attributes.getCharisma(), 0) };
			int16_t max_armor{ BASE_MAX_ARMOR + best_physic + best_psychic };

			setMaxArmor(max_armor);
		}

	private:

		DiceCapacity m_dice_capacity;
		// TODO: Equipment m_inventory;
		// TODO: Feat m_feat;

	};
} // namespace entity

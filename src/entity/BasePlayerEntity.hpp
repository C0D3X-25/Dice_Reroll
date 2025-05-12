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
		void setCapacity(const std::shared_ptr<BaseCapacity> sp_capacity, const uint8_t side);

		const BaseCapacity& rollDiceCapacity(void) const;
		
		void useCapacity(const BaseCapacity& capacity, BaseEntity& target) override;
		void resolveCapacity(const CapacityModifiersStruct& capacity, const BaseEntity& source) override;

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
			max_life += int16_t(m_up_attributes->getConstitution() * 1.5);

			setMaxLife(max_life);
		}


		// Calculate the maximum armor value based on the attributes
		// best physic = max(strength, dexterity)
		// best psychic = max(wisdom, intelligence, charisma)
		// max_armor = base_max_armor + best_physic + best_psychic
		void calculateMaxArmor(void) {

			// TODO: max_armor += bonus_armor;
			int16_t best_physic{ helper::calculate::bestValue<int16_t>( m_up_attributes->getStrength(), m_up_attributes->getDexterity(), 0) };
			int16_t best_psychic{ helper::calculate::bestValue<int16_t>(m_up_attributes->getWisdom(), m_up_attributes->getIntelligence(), m_up_attributes->getCharisma(), 0) };
			int16_t max_armor{ BASE_MAX_ARMOR + best_physic + best_psychic };

			setMaxArmor(max_armor);
		}

	private:

		std::unique_ptr<DiceCapacity> m_up_dice_capacity = std::make_unique<DiceCapacity>();
		// TODO: Equipment m_inventory;
		// TODO: Feat m_feat;

	};
} // namespace entity

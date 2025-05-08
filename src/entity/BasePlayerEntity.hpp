#pragma once

#include "BaseEntity.hpp"
#include "../capacity/BaseCapacity.hpp"
#include "../dice/DiceCapacity.hpp"
#include "../capacity/IUseAndResolveCapacity.hpp"

#include <iostream>
#include <string>
#include <memory>
#include <cstdint>



namespace entity {

	using namespace dice;
	using namespace capacity;

	inline constexpr uint8_t BASE_MAX_LIFE{ 20 };

	class BasePlayerEntity : public BaseEntity, 
		public IUseAndResolveCapacity {
	
	public:
		BasePlayerEntity(const std::string& name);
		virtual ~BasePlayerEntity(void) = default;
		//BasePlayerEntity(const BasePlayerEntity& other);
		//BasePlayerEntity& operator=(const BasePlayerEntity& other);

		/**
		* @brief Assigns a capacity to a specific side of the dice capacity
		* @param capacity The capacity to assign
		* @param side The side number to assign the capacity to (1-10)
		*/
		void setCapacity(const std::shared_ptr<BaseCapacity> sp_capacity, const uint8_t side);

		const BaseCapacity& rollDiceCapacity(void) const;
		
		void useCapacity(const BaseCapacity& capacity, BaseEntity& target) override;
		void resolveCapacity(const CapacityModifiersStruct& capacity, const BaseEntity& source) override;

		void printEntity(void) const override;

	protected:

		void updateEntity(void) override {
			calculateMaxLife();
			calculateMaxArmor();
		}

	private:

		void calculateMaxLife(void) {

			uint16_t max_life{ BASE_MAX_LIFE };
			max_life += m_up_attributes->getConstitution() * 1.5;

			setMaxLife(max_life);
		}

		// Calculate the maximum armor based on the entity's max life and the best between Strength and Wisdom.
		void calculateMaxArmor(void) {

			calculateMaxLife();

			uint16_t max_armor{ m_max_life };
			int16_t best{ std::max(m_up_attributes->getStrength(), m_up_attributes->getWisdom()) };
			max_armor += (best * 1.5) > 0 ? best : 0;

			setMaxArmor(max_armor);
		}

	private:

		std::unique_ptr<DiceCapacity> m_up_dice_capacity = std::make_unique<DiceCapacity>();
		// TODO: Equipment m_inventory;
		// TODO: Feat m_feat;

	};
} // namespace entity

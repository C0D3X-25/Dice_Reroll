#pragma once

#include "IEntity.hpp"
#include "../capacity/BaseCapacity.hpp"
#include "../dice/DiceCapacity.hpp"

#include <iostream>
#include <string>
#include <memory>


namespace entity {

	using namespace dice;

	class BasePlayerEntity : public IEntity {
	public:
		BasePlayerEntity(const std::string& name, const int16_t life, const int16_t armor);
		virtual ~BasePlayerEntity(void) = default;

		/**
		* @brief Assigns a capacity to a specific side of the dice capacity
		* @param capacity The capacity to assign
		* @param side The side number to assign the capacity to (1-10)
		*/
		void setCapacity(const std::shared_ptr<BaseCapacity> sp_capacity, const uint8_t side);

		const BaseCapacity& rollDiceCapacity(void) const;
		
		void printEntity(void) override;
		void useCapacity(const BaseCapacity& capacity, IEntity& target) override;
		void resolveCapacity(const SCapacityModifiers& capacity, const IEntity& src) override;
		std::string getName(void) const override;

	private:
		std::string m_name{ "N/A" };
		int16_t m_life{ 0 };
		int16_t m_armor{ 0 };
		//TODO: Status m_status;
		std::unique_ptr<DiceCapacity> m_up_dice_capacity = std::make_unique<DiceCapacity>();
	};
} // namespace entity

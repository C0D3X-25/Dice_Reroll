#pragma once

#include "BaseEntity.hpp"
#include "../capacity/BaseCapacity.hpp"
#include "../dice/DiceCapacity.hpp"
#include "../capacity/IUseAndResolveCapacity.hpp"

#include <iostream>
#include <string>
#include <memory>


namespace entity {

	using namespace dice;
	using namespace capacity;

	class BasePlayerEntity : public BaseEntity, 
		public IUseAndResolveCapacity {
	
	public:
		BasePlayerEntity(const std::string& name, const int16_t life, const int16_t armor);
		virtual ~BasePlayerEntity(void) = default;
		BasePlayerEntity(const BasePlayerEntity& other);
		BasePlayerEntity& operator=(const BasePlayerEntity& other);

		/**
		* @brief Assigns a capacity to a specific side of the dice capacity
		* @param capacity The capacity to assign
		* @param side The side number to assign the capacity to (1-10)
		*/
		void setCapacity(const std::shared_ptr<BaseCapacity> sp_capacity, const uint8_t side);

		const BaseCapacity& rollDiceCapacity(void) const;
		
		void useCapacity(const BaseCapacity& capacity, BaseEntity& target) override;
		void resolveCapacity(const CapacityModifiersStruct& capacity, const BaseEntity& source) override;

		void printEntity(void);

	private:

		std::unique_ptr<DiceCapacity> m_up_dice_capacity = std::make_unique<DiceCapacity>();
		//TODO: Equipment m_inventory;

	};
} // namespace entity

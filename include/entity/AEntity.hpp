#pragma once

#include "../capacity/ACapacity.hpp"
#include "../capacity_action/CapacityActionBaseAttack.hpp"
#include "../entity/IEntity.hpp"
#include <iostream>



namespace entity {
	class AEntity : public IEntity {
	public:


		void printEntity(void) override {
			std::cout
				<< "Name: " << m_name
				<< " | Life: " << m_life
				<< " | Armor: " << m_armor
				<< '\n';
		}


	private:
		std::string m_name{ "N/A" };
		int16_t m_life{ 0 };
		int16_t m_armor{ 0 };
		// Status m_status;
	};
} // namespace entity

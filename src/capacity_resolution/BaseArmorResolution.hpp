#pragma once

#include "ICapacityResolution.hpp"

namespace capacity_resolution {

	// When taking damage, the armor will absorb the damage taken first
	// Min armor = 0
	// Max armor = 
	class BaseArmorResolution : public ICapacityResolution {
	public:

		void resolveCapacity(const CapacityComponent& capacity_comp, BaseEntity& target) override {
			std::cout << "BaseArmorResolution: Resolving capacity for target: " << target.getEntityName() << "\n";
		}
	};
}

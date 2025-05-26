#pragma once

#include "ICapacityResolution.hpp"

namespace capacity_resolution {


	class BaseDeathResolution : public ICapacityResolution {
	public:

		void resolveCapacity(const CapacityComponent& capacity_comp, BaseEntity& target) override {
			std::cout << "BaseDeathResolution: Resolving capacity for target: " << target.getEntityName() << "\n";
		}
	};
}

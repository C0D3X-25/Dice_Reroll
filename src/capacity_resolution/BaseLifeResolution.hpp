#pragma once

#include "ICapacityResolution.hpp"

namespace capacity_resolution {


	class BaseLifeResolution : public ICapacityResolution {
	public:

		void resolveCapacity(const CapacityComponent& capacity_comp, BaseEntity& target) override {
			std::cout << "BaseLifeResolution: Resolving capacity for target: " << target.getEntityName() << "\n";
		}
	};
}

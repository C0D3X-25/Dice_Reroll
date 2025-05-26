#pragma once

#include "ICapacityResolution.hpp"

namespace capacity {

	// When taking damage, the armor will reduce the damage taken
	// Min armor = 0
	// Max armor = 
	class BaseArmorResolution : public ICapacityResolution {
	public:
		// Inherited via ICapacityResolution
		void resolve(const BaseCapacity& capacity) override {

		}
	};
}

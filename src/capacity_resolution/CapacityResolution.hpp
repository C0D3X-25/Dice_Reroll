#pragma once

#include "ICapacityResolution.hpp"

#include <iostream>
#include <vector>
#include <memory>

namespace capacity_resolution {

	// How a capacity is resolved when received
    class CapacityResolution : public ICapacityResolution {
    public:

        // TODO: Change by a linked list and add weight to each resolution for having an order of resolution
        void addResolution(std::shared_ptr<ICapacityResolution> sp_resolution) {
            m_sp_resolutions.push_back(sp_resolution);
        }

        std::shared_ptr<ICapacityResolution> getResolution(int index) {
            return m_sp_resolutions.at(index);
        }

        void resolveCapacity(const CapacityComponent& capacity_comp, BaseEntity& target) override {
			for (auto& resolution : m_sp_resolutions) {
				resolution->resolveCapacity(capacity_comp, target);
			}
        }

    private:
		std::vector<std::shared_ptr<ICapacityResolution>> m_sp_resolutions;
    };
}

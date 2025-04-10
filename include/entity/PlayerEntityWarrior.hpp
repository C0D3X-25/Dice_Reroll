#pragma once 

#include "../../include/entity/BasePlayerEntity.hpp"


#include <iostream>
#include <string>
#include <memory>


namespace entity {

	class PlayerEntityWarrior : public BasePlayerEntity {
	public:
		PlayerEntityWarrior(const std::string& name, const int16_t life, const int16_t armor);
		~PlayerEntityWarrior(void) = default;
	};
} // namespace entity

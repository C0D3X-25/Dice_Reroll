#pragma once 

//#include "tool_lib.hpp"
#include "../../include/capacity_modifiers/SCapacityModifiers.hpp"
#include "../../include/entity/AEntity.hpp"

#include <iostream>
#include <string>

namespace entity {
	class PlayerEntityWarrior : public AEntity {
	public:
		PlayerEntityWarrior(const std::string& name, const int16_t life, const int16_t armor)
			: AEntity::AEntity(name, life, armor) {}
		~PlayerEntityWarrior(void) = default;







	};
} // namespace entity
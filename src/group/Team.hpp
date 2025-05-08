#pragma once

#include "../entity/BaseEntity.hpp"
#include "BaseGroup.hpp"


namespace group {

	using entity::BaseEntity;

	inline constexpr uint8_t TEAM_MAX_SIZE{ 5 };

	class Team : public BaseGroup {
	public:
		Team(void)
		: BaseGroup(TEAM_MAX_SIZE) {

		}


	private:

	};
}
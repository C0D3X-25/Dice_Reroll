#pragma once

#include "../entity/BaseEntity.hpp"

#include <array>
#include <memory>

namespace team {

	using entity::BaseEntity;

	inline constexpr uint8_t MAX_TEAM_SIZE{ 5 };

	class BaseTeam {
	public:
		virtual ~BaseTeam(void) = default;

		// TODO: shared ptr are probably useless for entities, maybe use unique ptr and move
		virtual bool addEntity(void) {
			for (size_t i = 0; i < MAX_TEAM_SIZE; i++) {
				if (m_wp_team.at(i).expired()) {
					m_wp_team.at(i) = std::make_shared<BaseEntity>();
					return true;
				}
			}
			return false;
		}

		virtual bool removeEntity(uint8_t index_entity) {
			if (!m_wp_team.at(index_entity).expired()) {
				m_wp_team.at(index_entity).reset();
				return true;
			}
			return false;
		}

		virtual BaseEntity& getEntity(uint8_t index_entity) const {

		}
		virtual void printTeam(void) const {}

	private:
		std::array<std::weak_ptr<BaseEntity>, MAX_TEAM_SIZE> m_wp_team;
	};
}

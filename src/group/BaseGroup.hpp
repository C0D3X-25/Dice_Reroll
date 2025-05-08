#pragma once

#include "../entity/BaseEntity.hpp"

#include <vector>
#include <memory>

namespace group {

	using entity::BaseEntity;

	class BaseGroup {
	public:
		BaseGroup(uint8_t group_size)
		: m_group_size(group_size) {
			m_up_group.reserve(group_size);
		}
		virtual ~BaseGroup(void) = default;


		virtual bool addEntity(std::unique_ptr<BaseEntity> entity, const uint8_t index_entity) {

			if (!entity) {
				return false;
			}
			if (isTeamComplete()) {
				return false;
			}

			// Place the new entity in the specified slot if it's empty
			if (index_entity < m_group_size) {
				if (!m_up_group.at(index_entity)) {
					m_up_group.at(index_entity) = std::move(entity);
					return true;
				}
			}

			// Place the new entity in the first empty slot if index_entity is out of range or the slot is occupied
			for (size_t i = 0; i < m_group_size; i++) {
				if (!m_up_group.at(i)) {
					m_up_group.at(i) = std::move(entity);
					return true;
				}
			}
			return false;
		}


		virtual bool removeEntity(uint8_t index_entity) {
			if (!m_up_group.at(index_entity)) {
				m_up_group.at(index_entity).reset();
				return true;
			}
			return false;
		}


		virtual BaseEntity& getEntity(uint8_t index_entity) const {
			if (!m_up_group.at(index_entity)) {
				return;
			}
			return *m_up_group.at(index_entity);
		}


		bool isTeamComplete(void) const {
			for (const auto& entity : m_up_group) {
				if (!entity) {
					return false;
				}
			}
			return true;
		}


		virtual void printTeam(void) const {
			for (const auto& entity : m_up_group) {
				if (entity) {
					entity->printEntity();
					std::cout << "========================================================\n\n";
				}
			}
		}



	private:
		std::vector<std::unique_ptr<BaseEntity>> m_up_group;
		uint8_t m_group_size{ 0 };
	};
}

#pragma once

#include "../entity/BaseEntity.hpp"

#include <array>
#include <memory>
#include <iostream>

namespace group {

    using entity::BaseEntity;

    inline constexpr uint8_t GROUP_MAX_SIZE{ 20 };

    class BaseGroup {
    public:
        BaseGroup(uint8_t group_size)
            : m_group_size(group_size) {}
        virtual ~BaseGroup(void) = default;

        virtual bool addEntity(std::unique_ptr<BaseEntity> up_entity, const uint8_t index_entity) {
            if (!up_entity) {
                std::cout << "Entity passed is incorrect\n";
                return false;
            }
            if (isGroupComplete()) {
                std::cout << "Group is complete\n";
                return false;
            }

            // Place the new entity in the specified slot if it's empty
            if (index_entity < m_group_size) {
                if (!m_up_group[index_entity]) {
                    m_up_group[index_entity] = std::move(up_entity);
                    std::cout << "Entity added at index " << static_cast<int>(index_entity) << '\n';
                    return true;
                }
            }

            // Place the new entity in the first empty slot if index_entity is out of range or the slot is occupied
            for (size_t i = 0; i < m_group_size; i++) {
                if (!m_up_group[i]) {
                    m_up_group[i] = std::move(up_entity);
                    std::cout << "Entity added at index " << static_cast<int>(i) << '\n';
                    return true;
                }
            }
            return false;
        }

        virtual bool removeEntity(uint8_t index_entity) {
            if (m_up_group[index_entity]) {  // Changed condition to check if entity exists
                m_up_group[index_entity].reset();
                return true;
            }
            return false;
        }

        virtual BaseEntity& getEntity(uint8_t index_entity) const {
            if (index_entity >= m_group_size || !m_up_group[index_entity]) {
                static BaseEntity entity("Non existent Entity");
                return entity;
            }
            return *m_up_group[index_entity];
        }

        bool isGroupComplete(void) const {
            for (const auto& entity : m_up_group) {
                if (!entity) {  // Changed condition to check for empty slots
                    return false;
                }
            }
            return true;
        }

        bool isGroupEmpty(void) const {
            for (const auto& entity : m_up_group) {
                if (entity) {
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

        uint8_t getGroupSize(void) const { return m_group_size; }

    private:
        std::array<std::unique_ptr<BaseEntity>, GROUP_MAX_SIZE> m_up_group{};
        uint8_t m_group_size{ 0 };
    };
}

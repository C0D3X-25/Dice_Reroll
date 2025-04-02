#pragma once

#include "../capacity/BaseCapacity.hpp"
#include "../capacity_action/CapacityActionBaseAttack.hpp"
#include "../entity/IEntity.hpp"
#include <iostream>



namespace entity {
	class AEntity : public IEntity {
	public:
		AEntity(const std::string& name, const int16_t life, const int16_t armor)
			: m_name(name), m_life(life), m_armor(armor) {
		}
		virtual ~AEntity(void) = default;


		void printEntity(void) override {
			std::cout
				<< "Name: " << m_name
				<< " | Life: " << m_life
				<< " | Armor: " << m_armor
				<< '\n';
		}


		void useCapacity(BaseCapacity& capacity, IEntity& target) override {
			std::cout
				<< m_name
				<< " use capacity " << capacity.getName()
				<< " on " << target.getName()
				<< '\n';

			//target.takeCapacity(capacity.getStats(), *this);
		}


		void takeCapacity(const SCapacityModifiers& capacity, const IEntity& source) override {

			// TODO: Apply Status

			int16_t dmg_life{ 0 };
			int16_t heal_life{ 0 };
			int16_t remove_armor{ 0 };
			int16_t add_armor{ 0 };
			int16_t remain_dmg{ 0 };

			// Reverse the modify_life and modify_armor if they are negative
			if (capacity.m_life < 0) {

				dmg_life = capacity.m_life * -1;

				std::cout << m_name << " took (" << dmg_life << ") damage from "
					<< source.getName() << '\n';
			}
			else {
				heal_life = capacity.m_life;
			}

			if (capacity.m_armor < 0) {
				remove_armor = capacity.m_armor * -1;
			}
			else {
				add_armor = capacity.m_armor;
			}

			// Damage apply to armor
			if ((dmg_life > 0 || remove_armor > 0) && (m_armor > 0)) {
				if (m_armor <= remove_armor) {
					m_armor = 0;
				}
				else {
					m_armor += remove_armor;
				}

				if (m_armor <= dmg_life) {
					remain_dmg = dmg_life - m_armor;
					m_armor = 0;
				}
				else {
					m_armor += dmg_life;
				}
			}

			// Damage apply to life
			if (m_armor == 0) {
				if (remain_dmg > 0) {
					m_life += remain_dmg;
				}

				// TODO: Death of the Entity
				if ((m_life <= 0) || (dmg_life >= m_life)) {
					std::cout << m_name << " as been killed by " << source.getName() << '\n';
				}
				else {
					m_life += dmg_life;
				}
			}

			// TODO: Buff

			printEntity();
			std::cout << '\n';
		}


		std::string getName(void) const override {
			return m_name;
		}


	private:
		std::string m_name{ "N/A" };
		int16_t m_life{ 0 };
		int16_t m_armor{ 0 };
		//TODO: Status m_status;
		//TODO: Dice m_dice_capacity;
	};
} // namespace entity

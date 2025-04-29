#pragma once 

#include "../capacity/BaseCapacity.hpp"
#include "Attributes.hpp"

#include <memory>

namespace entity {

	using capacity::BaseCapacity;
	using capacity::CapacityModifiersStruct;

	class BaseEntity {
	public:
		BaseEntity(const std::string& name, const int16_t life, const int16_t armor);
		virtual ~BaseEntity(void) = default;

		virtual void setName(const std::string& name)		{ m_name = name; }
		virtual void setLife(int16_t life)					{ m_life = life; }
		virtual void setArmor(int16_t armor)				{ m_armor = armor; }
		virtual void setStrength(uint8_t strength)			{ m_up_stats->setStrength(strength); }
		virtual void setDexterity(uint8_t dexterity)		{ m_up_stats->setDexterity(dexterity); }
		virtual void setConstitution(uint8_t constitution)	{ m_up_stats->setConstitution(constitution); }
		virtual void setIntelligence(uint8_t intelligence)	{ m_up_stats->setIntelligence(intelligence); }
		virtual void setWisdom(uint8_t wisdom)				{ m_up_stats->setWisdom(wisdom); }
		virtual void setCharisma(uint8_t charisma)			{ m_up_stats->setCharisma(charisma); }

		virtual std::string_view getName(void) const	{ return m_name; }
		virtual int16_t getLife(void) const				{ return m_life; }
		virtual int16_t getArmor(void) const			{ return m_armor; }
		virtual uint8_t getStrength(void) const			{ return m_up_stats->getStrength(); }
		virtual uint8_t getDexterity(void) const		{ return m_up_stats->getDexterity(); }
		virtual uint8_t getConstitution(void) const		{ return m_up_stats->getConstitution(); }
		virtual uint8_t getIntelligence(void) const		{ return m_up_stats->getIntelligence(); }
		virtual uint8_t getWisdom(void) const			{ return m_up_stats->getWisdom(); }
		virtual uint8_t getCharisma(void) const			{ return m_up_stats->getCharisma(); }

	protected:
		std::string m_name{ "N/A" };
		std::unique_ptr<Attributes> m_up_stats;
		int16_t m_life{ 0 };
		int16_t m_armor{ 0 };
		//TODO: Status m_status;
		//TODO: Equipment m_equipment;

	};
} // namespace entity

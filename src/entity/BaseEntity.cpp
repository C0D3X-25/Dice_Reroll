#include "BaseEntity.hpp"

using namespace entity;

entity::BaseEntity::BaseEntity(const std::string& name, const int16_t life, const int16_t armor)
	: m_name(name), m_life(life), m_armor(armor) 
{
	m_up_stats = std::make_unique<Attributes>();
}



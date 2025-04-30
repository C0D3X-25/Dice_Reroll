#pragma once

namespace capacity {

	enum CapacityTypeEnum {

		// Attribute of the capacity
		STRENGTH,
		DEXTERITY,
		CONSTITUTION,
		INTELLIGENCE,
		WISDOM,
		CHARISMA,

		// Attack
		ATTACK_PHYSICAL,
		ATTACK_MAGIC,

		// Goal of the capacity
		DEFENSE,
		SUPPORT,
		MAGIC,
		HEALING,
		BUFF,
		DEBUFF,
		SPECIAL,

		// Target
		TARGET_SELF,
		TARGET_SINGLE,
		TARGET_RANDOM,
		TARGET_GROUP_OF_3,
		TARGET_ENNEMY_TEAM,
		TARGET_FRENDLY_TEAM,
		TARGET_EVERYONE
	};
}

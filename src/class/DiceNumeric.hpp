
#include "tool_lib.hpp"
#include "../interface/IDice.hpp"

namespace dice {

	class DiceNumeric : public IDice {
	public:
		DiceNumeric();
		~DiceNumeric();

		uint16_t rollDice(uint16_t max_value ,uint16_t nbr_roll) override;

	private:

	};
}

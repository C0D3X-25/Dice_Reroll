#pragma once
#include <cstdint>

namespace dice {
	class IRollAdvantageDisadvantage {
	public:
		virtual uint16_t rollAdvantage(void) = 0;
		virtual uint16_t rollDisadvantage(void) = 0;
	};
}

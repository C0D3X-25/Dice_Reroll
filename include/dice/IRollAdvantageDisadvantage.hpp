#pragma once
#include <cstdint>

namespace dice {
	template <typename T>
	class IRollAdvantageDisadvantage {
	public:
		virtual const T rollAdvantage(void) = 0;
		virtual const T rollDisadvantage(void) = 0;
	};
}

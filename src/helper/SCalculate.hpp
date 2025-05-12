#pragma once

namespace helper {
	namespace calculate {


		template<typename T, typename... Args>
		inline T bestValue(T start, Args... others) {
			int best = start;
			((best = (others > best ? others : best)), ...);

			return T(best);
		}


		template<typename T, typename... Args>
		inline T worstValue(T start, Args... others) {
			int worst = start;
			((worst = (others < worst ? others : worst)), ...);

			return T(worst);
		}
	}
}

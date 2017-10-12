#include "systemx/hw/clock.hpp"

namespace systemx {
	namespace hw {
		IClock::value_type Clock::get_value(void)
		{
			return os::chrono::system_clock::now();
		}
	}
}
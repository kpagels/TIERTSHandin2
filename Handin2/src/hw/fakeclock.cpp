#include "systemx/hw/fakeclock.hpp"

namespace systemx {
	namespace hw {
		IClock::value_type FakeClock::get_value(void)
		{
			return os::chrono::system_clock::now() - std::chrono::minutes(1);
		}
	}
}
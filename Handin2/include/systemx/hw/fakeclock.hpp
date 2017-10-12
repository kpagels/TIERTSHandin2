#ifndef FAKECLOCK_HPP_
#define FAKECLOCK_HPP_

#include "systemx/hw/iclock.hpp"

namespace systemx {
	namespace hw {
		class FakeClock : public IClock {
		public:
			IClock::value_type get_value(void);
		};
	}
}

#endif // !FAKECLOCK_HPP_
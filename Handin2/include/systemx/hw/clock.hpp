#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "systemx/hw/iclock.hpp"

namespace systemx {
	namespace hw {
		class Clock : public IClock {
		public:
			IClock::value_type get_value(void);
		};
	}
}

#endif // !CLOCK_HPP_
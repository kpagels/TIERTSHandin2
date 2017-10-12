#ifndef ICLOCK_HPP_
#define ICLOCK_HPP_

#include "systemx/os/chrono.hpp"

namespace systemx {
namespace hw {

	class IClock {
	public:
		using value_type = os::chrono::time_point<os::chrono::system_clock>;
		
		virtual value_type get_value(void) = 0;
	};

}
}

#endif // !ICLOCK_HPP_
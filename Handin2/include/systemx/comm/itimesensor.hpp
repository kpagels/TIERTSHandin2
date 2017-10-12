#ifndef ITIMESENSOR_HPP_
#define ITIMESENSOR_HPP_

#include "systemx/os/chrono.hpp"

namespace systemx {
namespace comm {

	class ITimeSensor {
	public:
		using value_type = std::chrono::seconds::rep;
		
		virtual value_type get_value(void) = 0;
	};

}
}

#endif // !ITIMESENSOR_HPP_
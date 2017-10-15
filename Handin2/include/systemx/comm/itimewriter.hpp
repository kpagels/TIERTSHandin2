#ifndef ITIMEWRITER_HPP_
#define ITIMEWRITER_HPP_

#include "systemx/os/chrono.hpp"

namespace systemx {
namespace comm {

	class ITimeWriter {
	public:
		using value_type = os::chrono::seconds::rep;
		
		virtual void set_value(value_type) = 0;
	};

}
}

#endif // !ITIMEWRITER_HPP_
#ifndef TIMEWRITER_HPP_
#define TIMEWRITER_HPP_

#include "systemx/comm/itimewriter.hpp"
#include "systemx/os/chrono.hpp"

namespace systemx {
namespace comm {

	class TimeWriter : public ITimeWriter {
	public:		
		virtual void set_value(value_type) {};
	};

}
}

#endif // !TIMEWRITER_HPP_
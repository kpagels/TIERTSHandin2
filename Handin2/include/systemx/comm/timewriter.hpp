#ifndef TIMEWRITER_HPP_
#define TIMEWRITER_HPP_

#include "systemx/comm/itimewriter.hpp"
#include "systemx/os/chrono.hpp"
#include "systemx/os/iostream.hpp"

namespace systemx {
namespace comm {

	class TimeWriter : public ITimeWriter {
	public:		

		TimeWriter(std::string name) : name(name) {}

		virtual void set_value(value_type value) {
			os::cout << name.c_str() << " " << value << std::endl;
		};

		std::string name;
	};

}
}

#endif // !TIMEWRITER_HPP_
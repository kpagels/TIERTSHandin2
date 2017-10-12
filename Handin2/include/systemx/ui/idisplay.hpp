#ifndef IDISPLAY_HPP_
#define IDISPLAY_HPP_

#include "systemx/os/ostream.hpp"

namespace systemx {
namespace ui {

	class IDisplay {
	public:		
		virtual os::ostream& get_cout() = 0;
		

	};

}
}

#endif // !IDISPLAY_HPP_
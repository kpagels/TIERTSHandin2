#ifndef CONSOLEDISPLAY_HPP_
#define CONSOLEDISPLAY_HPP_

#include "systemx/ui/idisplay.hpp"
#include "systemx/os/ostream.hpp"

namespace systemx {
namespace ui {

	class ConsoleDisplay : public IDisplay {
	public:		
		os::ostream& get_cout();
	};

}
}

#endif // !CONSOLEDISPLAY_HPP_
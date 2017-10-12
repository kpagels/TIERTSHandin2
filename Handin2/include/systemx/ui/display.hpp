#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include "systemx/ui/idisplay.hpp"
#include "systemx/os/ostream.hpp"

namespace systemx {
namespace ui {

	class Display {
	public:
		Display(IDisplay* ptr) : cout(ptr->get_cout()), ptr(ptr) {};

		os::ostream& cout;

	private:
		IDisplay* ptr;

	};

}
}

#endif // !DISPLAY_HPP_
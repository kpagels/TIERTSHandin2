#include "systemx/app/app.hpp"

#include "systemx/app/discrete/state/poweronselftest.hpp"
#include "systemx/app/discrete/state/failure.hpp"
#include "systemx/app/discrete/state/initializing.hpp"

#include "systemx/hw/clock.hpp"
#include "systemx/hw/fakeclock.hpp"
#include "systemx/comm/itimesensor.hpp"
#include "systemx/comm/clocktimesensor.hpp"
#include "systemx/comm/timewriter.hpp"
#include "systemx/ui/consoledisplay.hpp"
#include "systemx/ui/display.hpp"
#include "systemx/os/iostream.hpp"
#include "systemx/os/chrono.hpp"


namespace systemx {
	namespace app {

			App::App(ui::IDisplay* display) :
				statemachine(this, state::PowerOnSelfTest::Instance()),
				display(display)
				{
				}

			void App::start(void) {
				

				systemSelftest_ = true;

				display.cout << " Event: Restart" << os::endl;
				Restart();

				display.cout << " Event: Start" << os::endl;
				Start();

				display.cout << " Event: Suspend" << os::endl;
				Suspend();

				display.cout << " Event: Stop" << os::endl;
				Stop();

				display.cout << " Event: Start" << os::endl;
				Start();

			}
		

	}
}

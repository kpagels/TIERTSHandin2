#include "systemx/app/app.hpp"

#include "systemx/app/states/poweronselftest.hpp"
#include "systemx/app/states/failure.hpp"
#include "systemx/app/states/initializing.hpp"

#include "systemx/hw/clock.hpp"
#include "systemx/hw/fakeclock.hpp"
#include "systemx/comm/itimesensor.hpp"
#include "systemx/comm/clocktimesensor.hpp"
#include "systemx/ui/consoledisplay.hpp"
#include "systemx/ui/display.hpp"
#include "systemx/os/iostream.hpp"
#include "systemx/statemachine/istatemachine.hpp"


namespace systemx {
	namespace app {

			App::App(ui::IDisplay* display) : statemachine(this, state::PowerOnSelfTest::Instance()), display(display) {}

			void App::run(void) {
				comm::ITimeSensor* fake = new comm::ClockTimeSensor<hw::FakeClock>();
				comm::ITimeSensor* real = new comm::ClockTimeSensor<hw::Clock>();
				display.cout << "Fake " << fake->get_value() << os::endl;
				display.cout << "Real " << real->get_value() << os::endl;
				delete fake;
				delete real;
				statemachine.Restart();
				statemachine.Restart();
			}
		

	}
}

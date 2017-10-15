#include "systemx/app/app.hpp"

#include "systemx/app/state/poweronselftest.hpp"
#include "systemx/app/state/failure.hpp"
#include "systemx/app/state/initializing.hpp"

#include "systemx/hw/clock.hpp"
#include "systemx/hw/fakeclock.hpp"
#include "systemx/comm/itimesensor.hpp"
#include "systemx/comm/clocktimesensor.hpp"
#include "systemx/comm/timewriter.hpp"
#include "systemx/ui/consoledisplay.hpp"
#include "systemx/ui/display.hpp"
#include "systemx/os/iostream.hpp"
#include "systemx/os/chrono.hpp"
#include "systemx/statemachine/istatemachine.hpp"


namespace systemx {
	namespace app {

			App::App(ui::IDisplay* display) :
				statemachine(this, state::PowerOnSelfTest::Instance()),
				display(display),
				real_input(new comm::ClockTimeSensor<hw::Clock>()),
				sim_input(new comm::ClockTimeSensor<hw::FakeClock>()),
				input(nullptr),
				real_output(new comm::TimeWriter("Real")),
				sim_output(new comm::TimeWriter("Sim")),
				output(nullptr),
				strategy(nullptr),
				strategy1(new TimeStrategy1()),
				strategy2(new TimeStrategy2()),
				strategy3(new TimeStrategy3()),
				real_runner(nullptr)
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


				using namespace std::chrono_literals;

				os::this_thread::sleep_for(1s);
				display.cout << " Event: Simulate" << os::endl;
				Simulate();

				os::this_thread::sleep_for(2s);
				display.cout << " Event: RunRealTime" << os::endl;
				RunRealTime();

			}
		

	}
}

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
				
				while (running) {
					os::unique_lock<os::mutex> lock{ mutex };
					cv.wait(lock, [this] {return !this->queue.empty(); });
					std::function<void()> func = queue.front();
					queue.pop_front();
					lock.unlock();
					func();
				}
				

			}
		

	}
}

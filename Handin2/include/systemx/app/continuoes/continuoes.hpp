#ifndef CONTINUES_HPP_
#define CONTINUES_HPP_

#include "systemx/hw/iclock.hpp"
#include "systemx/hw/clock.hpp"
#include "systemx/hw/fakeclock.hpp"

#include "systemx/comm/itimesensor.hpp"
#include "systemx/comm/clocktimesensor.hpp"

#include "systemx/comm/itimewriter.hpp"
#include "systemx/comm/timewriter.hpp"

#include "systemx/os/thread.hpp"
#include "systemx/os/chrono.hpp"
#include "systemx/os/mutex.hpp"

#include "systemx/app/continuoes/itimestrategy.hpp"

#include "systemx/app/continuoes/realtimethread.hpp"

namespace systemx {
	namespace app {
		namespace continues {

			class RealTimeThread;

			class IContinues {
			public:
				IContinues();

				void set_mode_real(void);

				void set_mode_sim(void);

				void set_mode_1(void);

				void set_mode_2(void);

				void set_mode_3(void);

				bool get_loop_data(comm::ITimeSensor*& input, comm::ITimeWriter*& output, ITimeStrategy*& strategy);

				void start(void);

				void stop(void);

				void run(void);
				
			private:

				bool isInRealTimeLoop = false;

				comm::ITimeSensor* real_input = nullptr;
				comm::ITimeSensor* sim_input = nullptr;
				comm::ITimeSensor* input = nullptr;

				comm::ITimeWriter* real_output = nullptr;
				comm::ITimeWriter* sim_output = nullptr;
				comm::ITimeWriter* output = nullptr;

				ITimeStrategy* strategy = nullptr;
				ITimeStrategy* strategy1 = nullptr;
				ITimeStrategy* strategy2 = nullptr;
				ITimeStrategy* strategy3 = nullptr;

				RealTimeThread* real_runner;

				os::mutex mutex;

			};

			

		}
	}
}

#endif // !APP_HPP_
#include "systemx/app/continuoes/continuoes.hpp"
namespace systemx {
	namespace app {
		namespace continues {

			IContinues::IContinues() :
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

			void IContinues::set_mode_real(void) {
				os::lock_guard<os::mutex> lock{ mutex };
				input = real_input;
				output = real_output;
			}

			void IContinues::set_mode_sim(void) {
				os::lock_guard<os::mutex> lock{ mutex };
				input = sim_input;
				output = sim_output;
			}

			void IContinues::set_mode_1(void) {
				os::lock_guard<os::mutex> lock{ mutex };
				strategy = strategy1;
			}

			void IContinues::set_mode_2(void) {
				os::lock_guard<os::mutex> lock{ mutex };
				strategy = strategy2;
			}

			void IContinues::set_mode_3(void) {
				os::lock_guard<os::mutex> lock{ mutex };
				strategy = strategy3;
			}

			bool IContinues::get_loop_data(comm::ITimeSensor*& input, comm::ITimeWriter*& output, ITimeStrategy*& strategy) {
				os::lock_guard<os::mutex> lock{ mutex };
				input = this->input;
				output = this->output;
				strategy = this->strategy;
				return isInRealTimeLoop;
			}

			void IContinues::start(void) {
				isInRealTimeLoop = true;
				real_runner = new RealTimeThread(this);
				real_runner->start();
			}

			void IContinues::stop(void) {
				{
					os::lock_guard<os::mutex> lock{ mutex };
					isInRealTimeLoop = false;
				}
				delete real_runner;
			}

			void IContinues::run(void) {
				using value_type = comm::ITimeSensor::value_type;
				using namespace std::chrono_literals;

				comm::ITimeSensor* input;
				comm::ITimeWriter* output;
				ITimeStrategy* strategy;

				while (get_loop_data(input, output, strategy)) {
					value_type data = input->get_value();
					data = strategy->calc(data);
					output->set_value(data);
					os::this_thread::sleep_for(2s);
				}

			};

		}
	}
}
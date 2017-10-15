#ifndef APP_HPP_
#define APP_HPP_

#include "systemx/app/iapp.hpp"
#include "systemx/ui/idisplay.hpp"
#include "systemx/ui/display.hpp"
#include "systemx/os/iostream.hpp"
#include "systemx/os/thread.hpp"
#include "systemx/os/chrono.hpp"
#include "systemx/statemachine/statemachine.hpp"
#include "systemx/comm/itimesensor.hpp"
#include "systemx/comm/itimewriter.hpp"

namespace systemx {
	namespace app {

		class RealTimeThread : public os::thread {
		public:
			RealTimeThread(std::function<void()> run) : run_(run) {}

			void run() {
				run_();
			}

		private:
			std::function<void()> run_;
		};

		class ITimeStrategy {
		public:
			using value_type = comm::ITimeSensor::value_type;
			virtual ~ITimeStrategy() = default;
			virtual value_type calc(value_type data) {
				return data;
			}
			
		};

		class TimeStrategy1 : public ITimeStrategy {
		
		};

		class TimeStrategy2 : public ITimeStrategy {

		};

		class TimeStrategy3 : public ITimeStrategy {

		};
		
		class App : public IApp, public statemachine::ISystem  {
		public:
			App(ui::IDisplay* display);
			
			void start(void);

			void display_value(int value) {
				display.cout << value << os::endl;
			}

			
			void systemSelftest(void) {
				display.cout << "  Running systemSelftest: ";
				if (systemSelftest_) {
					display.cout << "OK!" << os::endl;
					SelftestOk();
				}
				else {
					display.cout << "ERROR!" << os::endl;
					SelfTestFailed();
				}
			}

			void startInitializing(void) {
				display.cout << "startInitializing" << os::endl;
				Initalized();
			}

			void display_error(int ErrorNo) {}

			void readConfigurationInfo(void) {}

			void PerformConfigurationX(void) {}

			void set_mode_real(void) {
				// Lock
				input = real_input;
				output = real_output;
			}

			void set_mode_sim(void) {
				// Lock
				input = sim_input;
				output = sim_output;
			}

			void set_mode_1(void) {
				// Lock
				strategy = strategy1;
			}

			void set_mode_2(void) {
				// Lock
				strategy = strategy2;
			}

			void set_mode_3(void) {
				// Lock
				strategy = strategy3;
			}

			bool get_loop_data(comm::ITimeSensor*& input, comm::ITimeWriter*& output, ITimeStrategy*& strategy) {
				// Lock
				input = this->input;
				output = this->output;
				strategy = this->strategy;
				return isInRealTimeLoop;
			}

			void run(void) {
				using value_type = comm::ITimeSensor::value_type;
				using namespace std::chrono_literals;
				display.cout << "Running!" << os::endl;

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

			void startRealTimeLoop(void) {
				isInRealTimeLoop = true;
				real_runner = new RealTimeThread([this]() {this->run(); });
				real_runner->start();
			}

			void stopRealTimeLoop(void) {
				isInRealTimeLoop = false;
				delete real_runner;
			}

			os::ostream& logger() {
				return display.cout;
			}

			void Exit() {
				statemachine.Exit();
			}

			void Start() {
				statemachine.Start();
			}

			void Restart() {
				statemachine.Restart();
			}

			void Stop() {
				statemachine.Stop();
			}

			void Suspend() {
				statemachine.Suspend();
			}

			void Resume() {
				statemachine.Resume();
			}

			void SelfTestFailed() {
				statemachine.SelfTestFailed();
			}

			void SelftestOk() {
				statemachine.SelftestOk();
			}

			void Initalized() {
				statemachine.Initalized();
			}

			void ConfigX() {
				statemachine.ConfigX();
			}

			void Configure() {
				statemachine.Configure();
			}

			void ConfigurationEnded() {
				statemachine.ConfigurationEnded();
			}

			void EventX() {
				statemachine.EventX();
			}

			void EventY() {
				statemachine.EventY();
			}

			void chMode() {
				statemachine.chMode();
			}

			void RunRealTime() {
				statemachine.RunRealTime();
			}

			void Simulate() {
				statemachine.Simulate();
			}

			bool systemSelftest_ = false;
			

		private:
			ui::Display display;
			statemachine::StateMachine statemachine;

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

		};

	}
}

#endif // !APP_HPP_

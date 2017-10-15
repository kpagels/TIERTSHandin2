#ifndef APP_HPP_
#define APP_HPP_

#include <deque>

#include "systemx/app/iapp.hpp"
#include "systemx/ui/idisplay.hpp"
#include "systemx/ui/display.hpp"
#include "systemx/os/iostream.hpp"
#include "systemx/os/mutex.hpp"
#include "systemx/app/discrete/istatemachine.hpp"
#include "systemx/app/discrete/statemachine.hpp"
#include "systemx/app/discrete/isystem.hpp"

#include "systemx/app/continuoes/continuoes.hpp"

namespace systemx {
	namespace app {
		
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

			void run(void) {
				display.cout << "Running system" << os::endl;
			}

			os::ostream& logger() {
				return display.cout;
			}

			void add_event(std::function<void()> func) {
				os::lock_guard<os::mutex> lock{ mutex };
				queue.push_back(func);
				cv.notify_one();
			}

			void Exit() {
				add_event([this]() {this->statemachine.Exit(); });
			}

			void Start() {
				add_event([this]() {this->statemachine.Start(); });
			}

			void Restart() {
				add_event([this]() {this->statemachine.Restart(); });
			}

			void Stop() {
				add_event([this]() {this->statemachine.Stop(); });
			}

			void Suspend() {
				add_event([this]() {this->statemachine.Suspend(); });
			}

			void Resume() {
				add_event([this]() {this->statemachine.Resume(); });
			}

			void SelfTestFailed() {
				add_event([this]() {this->statemachine.SelfTestFailed(); });
			}

			void SelftestOk() {
				add_event([this]() {this->statemachine.SelftestOk(); });
			}

			void Initalized() {
				add_event([this]() {this->statemachine.Initalized(); });
			}

			void ConfigX() {
				add_event([this]() {this->statemachine.ConfigX(); });
			}

			void Configure() {
				add_event([this]() {this->statemachine.Configure(); });
			}

			void ConfigurationEnded() {
				add_event([this]() {this->statemachine.ConfigurationEnded(); });
			}

			void EventX() {
				add_event([this]() {this->statemachine.EventX(); });
			}

			void EventY() {
				add_event([this]() {this->statemachine.EventY(); });
			}

			void chMode() {
				add_event([this]() {this->statemachine.chMode(); });
			}

			void RunRealTime() {
				add_event([this]() {this->statemachine.RunRealTime(); });
			}

			void Simulate() {
				add_event([this]() {this->statemachine.Simulate(); });
			}

			bool systemSelftest_ = false;
			

		private:
			std::deque<std::function<void()>> queue;
			os::mutex mutex;
			os::condition_variable cv;
			ui::Display display;
			statemachine::StateMachine statemachine;		
			bool running = true;

		};

	}
}

#endif // !APP_HPP_

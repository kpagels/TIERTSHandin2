#ifndef APP_HPP_
#define APP_HPP_

#include "systemx/app/iapp.hpp"
#include "systemx/ui/idisplay.hpp"
#include "systemx/ui/display.hpp"
#include "systemx/os/iostream.hpp"
#include "systemx/statemachine/statemachine.hpp"
#include "systemx/comm/itimesensor.hpp"
#include "systemx/comm/itimewriter.hpp"

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
				display.cout << "Running!" << os::endl;

			};

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

			comm::ITimeSensor* input = nullptr;
			comm::ITimeWriter* output = nullptr;
			//ITimeStrategy* strategy;

		};

	}
}

#endif // !APP_HPP_
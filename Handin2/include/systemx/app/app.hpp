#ifndef APP_HPP_
#define APP_HPP_

#include "systemx/app/iapp.hpp"
#include "systemx/ui/idisplay.hpp"
#include "systemx/ui/display.hpp"
#include "systemx/os/iostream.hpp"
#include "systemx/statemachine/statemachine.hpp"

namespace systemx {
	namespace app {

		class App : public IApp, public statemachine::ISystem  {
		public:
			App(ui::IDisplay* display);
			void run(void);

			void display_value(int value) {
				display.cout << value << os::endl;
			}

			
			bool systemSelftest(void) {
				display.cout << "  Running systemSelftest: ";
				if (systemSelftest_)
					display.cout << "OK!";
				else
					display.cout << "ERROR!";
				display.cout << os::endl;
				return systemSelftest_;
			}


			os::ostream& logger() {
				return display.cout;
			}

			void Restart() {
				statemachine.Restart();
			}

			bool systemSelftest_ = false;

		private:
			ui::Display display;
			statemachine::StateMachine statemachine;
		};

	}
}

#endif // !APP_HPP_
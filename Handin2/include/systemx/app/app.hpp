#ifndef APP_HPP_
#define APP_HPP_

#include "systemx/app/iapp.hpp"
#include "systemx/ui/idisplay.hpp"
#include "systemx/ui/display.hpp"
#include "systemx/statemachine/statemachine.hpp"

namespace systemx {
	namespace app {

		class App : public IApp, public statemachine::StateMachine {
		public:
			App(ui::IDisplay* display);
			void run(void);


			
		private:
			ui::Display display;
		};

	}
}

#endif // !APP_HPP_
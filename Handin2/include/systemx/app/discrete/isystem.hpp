#ifndef ISYSTEM_HPP_
#define ISYSTEM_HPP_

#include "systemx/app/continuoes/continuoes.hpp"


namespace systemx {
	namespace statemachine {

		class ISystem {
		public:
			virtual os::ostream& logger() = 0;

			virtual void display_value(int value) = 0;
			virtual void systemSelftest(void) = 0;
			virtual void startInitializing(void) = 0;
			virtual void display_error(int ErrorNo) = 0;
			virtual void readConfigurationInfo(void) = 0;
			virtual void PerformConfigurationX(void) = 0;
			virtual void run(void) = 0;

			app::continues::IContinues continues;

		};

	}
}

#endif // !ISYSTEM_HPP_
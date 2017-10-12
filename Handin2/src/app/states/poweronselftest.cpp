#include "systemx/os/iostream.hpp"
#include "systemx/app/states/poweronselftest.hpp"

namespace systemx {
	namespace app {
		namespace state {
			namespace base {
				void PowerOnSelfTest::EnterState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "EnterState: PowerOnSelfTest" << os::endl;
				}

				void PowerOnSelfTest::ExitState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "ExitState: PowerOnSelfTest" << os::endl;
				}

				void PowerOnSelfTest::Restart(ISystem* system, IStateMachine* statemachine) {
					system->display_value(10);
				}
			}
		}
	}
}


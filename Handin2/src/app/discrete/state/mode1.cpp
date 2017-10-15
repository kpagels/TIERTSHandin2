#include "systemx/os/iostream.hpp"

#include "systemx/app/discrete/isystem.hpp"
#include "systemx/app/discrete/istatemachine.hpp"

#include "systemx/app/discrete/state/mode1.hpp"

namespace systemx {
	namespace app {
		namespace state {
			namespace base {

				void Mode1Base::EnterState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "EnterState: Mode1" << os::endl;
					system->continues.set_mode_1();
				}

				void Mode1Base::ExitState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "ExitState: Mode1" << os::endl;
				}
			}
		}
	}
}


#include "systemx/os/iostream.hpp"

#include "systemx/app/discrete/isystem.hpp"
#include "systemx/app/discrete/istatemachine.hpp"

#include "systemx/app/discrete/state/mode3.hpp"
#include "systemx/app/discrete/state/mode1.hpp"

namespace systemx {
	namespace app {
		namespace state {
			namespace base {

				void Mode3Base::EnterState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "EnterState: Mode3" << os::endl;
					system->continues.set_mode_3();
				}

				void Mode3Base::ExitState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "ExitState: Mode3" << os::endl;
				}

				void Mode3Base::chMode(ISystem* system, IStateMachine* statemachine) {
					statemachine->ChangeState(Mode1::Instance());
				}
			}
		}
	}
}


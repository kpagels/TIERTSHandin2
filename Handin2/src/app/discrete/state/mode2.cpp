#include "systemx/os/iostream.hpp"

#include "systemx/app/discrete/isystem.hpp"
#include "systemx/app/discrete/istatemachine.hpp"

#include "systemx/app/discrete/state/mode2.hpp"
#include "systemx/app/discrete/state/mode3.hpp"

namespace systemx {
	namespace app {
		namespace state {
			namespace base {

				void Mode2Base::EnterState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "EnterState: Mode2" << os::endl;
					system->continues.set_mode_2();
				}

				void Mode2Base::ExitState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "ExitState: Mode2" << os::endl;
				}

				void Mode2Base::chMode(ISystem* system, IStateMachine* statemachine) {
					statemachine->ChangeState(Mode3::Instance());
				}
			}
		}
	}
}


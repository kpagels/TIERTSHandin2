#include "systemx/os/iostream.hpp"

#include "systemx/app/discrete/isystem.hpp"
#include "systemx/app/discrete/istatemachine.hpp"

#include "systemx/app/discrete/state/initializing.hpp"
#include "systemx/app/discrete/state/operational.hpp"

namespace systemx {
	namespace app {
		namespace state {
			namespace base {

				void InitializingBase::EnterState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "EnterState: Initializing" << os::endl;
					system->startInitializing();
				}

				void InitializingBase::ExitState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "ExitState: Initializing" << os::endl;
				}

				void InitializingBase::Initalized(ISystem* system, IStateMachine* statemachine) {
					statemachine->ChangeState(Operational::Instance());
				}
			}
		}
	}
}


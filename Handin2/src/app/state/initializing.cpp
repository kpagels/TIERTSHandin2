#include "systemx/os/iostream.hpp"
#include "systemx/app/state/initializing.hpp"

namespace systemx {
	namespace app {
		namespace state {
			namespace base {

				void InitializingBase::EnterState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "EnterState: Initializing" << os::endl;
				}

				void InitializingBase::ExitState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "ExitState: Initializing" << os::endl;
				}
			}
		}
	}
}


#include "systemx/os/iostream.hpp"
#include "systemx/app/state/initializing.hpp"
#include "systemx/app/state/operational.hpp"
#include "systemx/app/state/realtimeexecution.hpp"
#include "systemx/app/state/realtimeloop.hpp"
#include "systemx/statemachine/statemachine.hpp"

namespace systemx {
	namespace app {
		namespace state {
			namespace base {

				void RealTimeExecutionBase::EnterState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "EnterState: RealTimeExecution" << os::endl;
					system->set_mode_real();
				}

				void RealTimeExecutionBase::ExitState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "ExitState: RealTimeExecution" << os::endl;
					
				}
			}
		}
	}
}


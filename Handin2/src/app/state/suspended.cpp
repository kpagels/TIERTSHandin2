#include "systemx/os/iostream.hpp"
#include "systemx/app/state/initializing.hpp"
#include "systemx/app/state/realtimeloop.hpp"
#include "systemx/app/state/suspended.hpp"
#include "systemx/app/state/ready.hpp"
#include "systemx/statemachine/statemachine.hpp"

namespace systemx {
	namespace app {
		namespace state {
			namespace base {

				void SuspendedBase::EnterState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "EnterState: Suspended" << os::endl;
				}

				void SuspendedBase::ExitState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "ExitState: Suspended" << os::endl;
				}

				void SuspendedBase::Stop(ISystem* system, IStateMachine* statemachine) {
					statemachine->ChangeState(Ready::Instance());
				}

				void SuspendedBase::Resume(ISystem* system, IStateMachine* statemachine) {
					statemachine->ChangeState(RealTimeLoop::Instance());
				}

			}
		}
	}
}


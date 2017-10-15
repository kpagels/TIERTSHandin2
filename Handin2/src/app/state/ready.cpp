#include "systemx/os/iostream.hpp"
#include "systemx/app/state/initializing.hpp"
#include "systemx/app/state/operational.hpp"
#include "systemx/app/state/ready.hpp"
#include "systemx/app/state/realtimeloop.hpp"
#include "systemx/statemachine/statemachine.hpp"

namespace systemx {
	namespace app {
		namespace state {
			namespace base {

				void ReadyBase::EnterState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "EnterState: Ready" << os::endl;
				}

				void ReadyBase::ExitState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "ExitState: Ready" << os::endl;
				}

				void ReadyBase::Start(ISystem* system, IStateMachine* statemachine) {
					statemachine->ChangeState(RealTimeLoop::Instance());
				}

			}
		}
	}
}


#include "systemx/os/iostream.hpp"

#include "systemx/app/discrete/isystem.hpp"
#include "systemx/app/discrete/istatemachine.hpp"

#include "systemx/app/discrete/state/ready.hpp"
#include "systemx/app/discrete/state/realtimeloop.hpp"


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


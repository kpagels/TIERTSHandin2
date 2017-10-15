#include "systemx/os/iostream.hpp"

#include "systemx/app/discrete/isystem.hpp"
#include "systemx/app/discrete/istatemachine.hpp"

#include "systemx/app/discrete/state/failure.hpp"
#include "systemx/app/discrete/state/poweronselftest.hpp"


namespace systemx {
	namespace app {
		namespace state {
			namespace base {

				void FailureBase::EnterState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "EnterState: Failure" << os::endl;
				}

				void FailureBase::ExitState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "ExitState: Failure" << os::endl;
				}

				void FailureBase::Restart(ISystem* system, IStateMachine* statemachine) {
					statemachine->ChangeState(PowerOnSelfTest::Instance());
				}
			}
		}
	}
}


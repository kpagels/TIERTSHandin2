#include "systemx/os/iostream.hpp"
#include "systemx/app/state/poweronselftest.hpp"
#include "systemx/app/state/failure.hpp"
#include "systemx/app/state/initializing.hpp"

namespace systemx {
	namespace app {
		namespace state {
			namespace base {
				void PowerOnSelfTestBase::EnterState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "EnterState: PowerOnSelfTest" << os::endl;
					system->systemSelftest();
				}

				void PowerOnSelfTestBase::ExitState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "ExitState: PowerOnSelfTest" << os::endl;
				}



				void PowerOnSelfTestBase::SelftestOk(ISystem* system, IStateMachine* statemachine) {
					statemachine->ChangeState(Initializing::Instance());
				}

				void PowerOnSelfTestBase::SelfTestFailed(ISystem* system, IStateMachine* statemachine) {
					statemachine->ChangeState(Failure::Instance());
				}
			}
		}
	}
}


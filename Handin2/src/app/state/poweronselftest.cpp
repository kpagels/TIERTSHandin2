#include "systemx/os/iostream.hpp"
#include "systemx/app/states/poweronselftest.hpp"
#include "systemx/app/states/failure.hpp"

namespace systemx {
	namespace app {
		namespace state {
			namespace base {
				void PowerOnSelfTestBase::EnterState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "EnterState: PowerOnSelfTest" << os::endl;
					if (system->systemSelftest())
						statemachine->SelftestOk();
					else
						statemachine->SelfTestFailed();
				}

				void PowerOnSelfTestBase::ExitState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "ExitState: PowerOnSelfTest" << os::endl;
				}

				void PowerOnSelfTestBase::SelftestOk(ISystem* system, IStateMachine* statemachine) {
					statemachine->ChangeState(Failure::Instance());
				}

				void PowerOnSelfTestBase::SelfTestFailed(ISystem* system, IStateMachine* statemachine) {
					statemachine->ChangeState(Failure::Instance());
				}

				void PowerOnSelfTestBase::Restart(ISystem* system, IStateMachine* statemachine) {
					system->display_value(10);
				}
			}
		}
	}
}


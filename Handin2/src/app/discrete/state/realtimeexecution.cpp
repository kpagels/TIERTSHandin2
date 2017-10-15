#include "systemx/os/iostream.hpp"

#include "systemx/app/discrete/isystem.hpp"
#include "systemx/app/discrete/istatemachine.hpp"

#include "systemx/app/discrete/state/realtimeexecution.hpp"
#include "systemx/app/discrete/state/simulation.hpp"


namespace systemx {
	namespace app {
		namespace state {
			namespace base {

				void RealTimeExecutionBase::EnterState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "EnterState: RealTimeExecution" << os::endl;
					system->continues.set_mode_real();
				}

				void RealTimeExecutionBase::ExitState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "ExitState: RealTimeExecution" << os::endl;
					
				}

				void RealTimeExecutionBase::Simulate(ISystem* system, IStateMachine* statemachine) {
					statemachine->ChangeState(Simulation::Instance());
				}
			}
		}
	}
}


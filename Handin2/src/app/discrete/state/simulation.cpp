#include "systemx/os/iostream.hpp"

#include "systemx/app/discrete/isystem.hpp"
#include "systemx/app/discrete/istatemachine.hpp"

#include "systemx/app/discrete/state/simulation.hpp"
#include "systemx/app/discrete/state/realtimeexecution.hpp"


namespace systemx {
	namespace app {
		namespace state {
			namespace base {

				void SimulationBase::EnterState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "EnterState: Simulation" << os::endl;
					system->continues.set_mode_sim();
				}

				void SimulationBase::ExitState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "ExitState: Simulation" << os::endl;
				}

				void SimulationBase::RunRealTime(ISystem* system, IStateMachine* statemachine) {
					statemachine->ChangeState(RealTimeExecution::Instance());
				}
			}
		}
	}
}


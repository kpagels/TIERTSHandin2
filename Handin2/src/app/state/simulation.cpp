#include "systemx/os/iostream.hpp"
#include "systemx/app/state/initializing.hpp"
#include "systemx/app/state/simulation.hpp"
#include "systemx/app/state/realtimeexecution.hpp"
#include "systemx/app/state/realtimeloop.hpp"
#include "systemx/statemachine/statemachine.hpp"

namespace systemx {
	namespace app {
		namespace state {
			namespace base {

				void SimulationBase::EnterState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "EnterState: Simulation" << os::endl;
					system->set_mode_sim();
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


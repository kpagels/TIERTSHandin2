#ifndef SIMULATION_HPP_
#define SIMULATION_HPP_

#include "systemx/app/statemachine.hpp"
#include "systemx/os/ostream.hpp"

namespace systemx {
	namespace app {
		namespace state {
			namespace base {
				class SimulationBase : public IState {
				public:

					void EnterState(ISystem* system, IStateMachine* statemachine);

					void ExitState(ISystem* system, IStateMachine* statemachine);

					void RunRealTime(ISystem* system, IStateMachine* statemachine);

				};
			}

			using Simulation = Singleton<base::SimulationBase>;
		}
	}
}

#endif // !SIMULATION_HPP_
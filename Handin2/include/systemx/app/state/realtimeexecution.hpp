#ifndef REALTIMEEXECUTION_HPP_
#define REALTIMEEXECUTION_HPP_

#include "systemx/app/statemachine.hpp"
#include "systemx/os/ostream.hpp"

namespace systemx {
	namespace app {
		namespace state {
			namespace base {
				class RealTimeExecutionBase : public IState {
				public:

					void EnterState(ISystem* system, IStateMachine* statemachine);

					void ExitState(ISystem* system, IStateMachine* statemachine);


				};
			}

			using RealTimeExecution = Singleton<base::RealTimeExecutionBase>;
		}
	}
}

#endif // !REALTIMEEXECUTION_HPP_
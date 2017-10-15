#ifndef SUSPENDED_HPP_
#define SUSPENDED_HPP_

#include "systemx/app/discrete/singleton.hpp"
#include "systemx/app/discrete/statemachine.hpp"
#include "systemx/os/ostream.hpp"

namespace systemx {
	namespace app {
		namespace state {
			namespace base {
				class SuspendedBase : public IState {
				public:

					void EnterState(ISystem* system, IStateMachine* statemachine);

					void ExitState(ISystem* system, IStateMachine* statemachine);

					void Stop(ISystem* system, IStateMachine* statemachine);

					void Resume(ISystem* system, IStateMachine* statemachine);

				};
			}

			using Suspended = Singleton<base::SuspendedBase>;
		}
	}
}

#endif // !SUSPENDED_HPP_
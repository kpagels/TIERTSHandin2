#ifndef FAILURE_HPP_
#define FAILURE_HPP_

#include "systemx/app/discrete/statemachine.hpp"
#include "systemx/app/discrete/singleton.hpp"
#include "systemx/os/ostream.hpp"

namespace systemx {
	namespace app {
		namespace state {
			namespace base {
				class FailureBase : public IState {
				public:

					void EnterState(ISystem* system, IStateMachine* statemachine);

					void ExitState(ISystem* system, IStateMachine* statemachine);

					void Restart(ISystem* system, IStateMachine* statemachine);
				};
			}

			using Failure = Singleton<base::FailureBase>;
		}
	}
}

#endif // !FAILURE_HPP_
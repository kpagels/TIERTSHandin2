#ifndef INITIALIZING_HPP_
#define INITIALIZING_HPP_

#include "systemx/app/statemachine.hpp"
#include "systemx/os/ostream.hpp"

namespace systemx {
	namespace app {
		namespace state {
			namespace base {
				class InitializingBase : public IState {
				public:

					void EnterState(ISystem* system, IStateMachine* statemachine);

					void ExitState(ISystem* system, IStateMachine* statemachine);

				};
			}

			using Initializing = Singleton<base::InitializingBase>;
		}
	}
}

#endif // !INITIALIZING_HPP_
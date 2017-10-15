#ifndef MODE3_HPP_
#define MODE3_HPP_

#include "systemx/app/discrete/statemachine.hpp"
#include "systemx/app/discrete/singleton.hpp"
#include "systemx/os/ostream.hpp"

namespace systemx {
	namespace app {
		namespace state {
			namespace base {
				class Mode3Base : public IState {
				public:

					void EnterState(ISystem* system, IStateMachine* statemachine);

					void ExitState(ISystem* system, IStateMachine* statemachine);

					void chMode(ISystem* system, IStateMachine* statemachine);

				};
			}

			using Mode3 = Singleton<base::Mode3Base>;
		}
	}
}

#endif // !MODE3_HPP_
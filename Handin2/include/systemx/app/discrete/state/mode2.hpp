#ifndef MODE2_HPP_
#define MODE2_HPP_

#include "systemx/app/discrete/statemachine.hpp"
#include "systemx/app/discrete/singleton.hpp"
#include "systemx/os/ostream.hpp"

namespace systemx {
	namespace app {
		namespace state {
			namespace base {
				class Mode2Base : public IState {
				public:

					void EnterState(ISystem* system, IStateMachine* statemachine);

					void ExitState(ISystem* system, IStateMachine* statemachine);

					void chMode(ISystem* system, IStateMachine* statemachine);

				};
			}

			using Mode2= Singleton<base::Mode2Base>;
		}
	}
}

#endif // !MODE2_HPP_
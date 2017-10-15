#ifndef MODE1_HPP_
#define MODE1_HPP_

#include "systemx/app/discrete/statemachine.hpp"
#include "systemx/app/discrete/singleton.hpp"
#include "systemx/os/ostream.hpp"

namespace systemx {
	namespace app {
		namespace state {
			namespace base {
				class Mode1Base : public IState {
				public:

					void EnterState(ISystem* system, IStateMachine* statemachine);

					void ExitState(ISystem* system, IStateMachine* statemachine);

				};
			}

			using Mode1 = Singleton<base::Mode1Base>;
		}
	}
}

#endif // !MODE1_HPP_
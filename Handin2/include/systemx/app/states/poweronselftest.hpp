#ifndef POWERONSELFTEST_HPP_
#define POWERONSELFTEST_HPP_

#include "systemx/app/statemachine.hpp"
#include "systemx/os/ostream.hpp"

namespace systemx {
	namespace app {
		namespace state {
			namespace base {
				class PowerOnSelfTest : public IState {
				public:

					void EnterState(ISystem* system, IStateMachine* statemachine);

					void ExitState(ISystem* system, IStateMachine* statemachine);

					void Restart(ISystem* system, IStateMachine* statemachine);
				};
			}
			
			using PowerOnSelfTest = Singleton<base::PowerOnSelfTest>;
		}
	}
}

#endif // !POWERONSELFTEST_HPP_
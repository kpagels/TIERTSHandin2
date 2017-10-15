#ifndef POWERONSELFTEST_HPP_
#define POWERONSELFTEST_HPP_

#include "systemx/app/discrete/statemachine.hpp"
#include "systemx/app/discrete/singleton.hpp"
#include "systemx/os/ostream.hpp"

namespace systemx {
	namespace app {
		namespace state {
			namespace base {
				class PowerOnSelfTestBase : public IState {
				public:

					void EnterState(ISystem* system, IStateMachine* statemachine);

					void ExitState(ISystem* system, IStateMachine* statemachine);



					void SelftestOk(ISystem* system, IStateMachine* statemachine);

					void SelfTestFailed(ISystem* system, IStateMachine* statemachine);
				};
			}
			
			using PowerOnSelfTest = Singleton<base::PowerOnSelfTestBase>;
		}
	}
}

#endif // !POWERONSELFTEST_HPP_
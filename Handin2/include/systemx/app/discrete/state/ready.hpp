#ifndef READY_HPP_
#define READY_HPP_

#include "systemx/app/discrete/singleton.hpp"
#include "systemx/app/discrete/statemachine.hpp"
#include "systemx/os/ostream.hpp"

namespace systemx {
	namespace app {
		namespace state {
			namespace base {
				class ReadyBase : public IState {
				public:

					void EnterState(ISystem* system, IStateMachine* statemachine);

					void ExitState(ISystem* system, IStateMachine* statemachine);

					void Start(ISystem* system, IStateMachine* statemachine);

				};
			}

			using Ready = Singleton<base::ReadyBase>;
		}
	}
}

#endif // !READY_HPP_
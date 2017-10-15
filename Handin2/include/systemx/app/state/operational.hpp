#ifndef OPERATIONAL_HPP_
#define OPERATIONAL_HPP_

#include "systemx/app/statemachine.hpp"
#include "systemx/os/ostream.hpp"

namespace systemx {
	namespace app {
		namespace state {
			namespace base {
				class OperationalBase : public IState {
				public:

					void EnterState(ISystem* system, IStateMachine* statemachine);

					void ExitState(ISystem* system, IStateMachine* statemachine);

					void Exit(ISystem* system, IStateMachine* statemachine);

					void Start(ISystem* system, IStateMachine* statemachine);
					void Restart(ISystem* system, IStateMachine* statemachine);
					void Stop(ISystem* system, IStateMachine* statemachine);
					void Suspend(ISystem* system, IStateMachine* statemachine);
					void Resume(ISystem* system, IStateMachine* statemachine);

					void SelfTestFailed(ISystem* system, IStateMachine* statemachine);
					void SelftestOk(ISystem* system, IStateMachine* statemachine);
					void Initalized(ISystem* system, IStateMachine* statemachine);

					void ConfigX(ISystem* system, IStateMachine* statemachine);
					void Configure(ISystem* system, IStateMachine* statemachine);
					void ConfigurationEnded(ISystem* system, IStateMachine* statemachine);

					void EventX(ISystem* system, IStateMachine* statemachine);
					void EventY(ISystem* system, IStateMachine* statemachine);
					void chMode(ISystem* system, IStateMachine* statemachine);
					void RunRealTime(ISystem* system, IStateMachine* statemachine);
					void Simulate(ISystem* system, IStateMachine* statemachine);

				private:
					IStateMachine* substatemachine(IStateMachine* statemachine);

				};
			}

			using Operational = Singleton<base::OperationalBase>;
		}
	}
}

#endif // !OPERATIONAL_HPP_
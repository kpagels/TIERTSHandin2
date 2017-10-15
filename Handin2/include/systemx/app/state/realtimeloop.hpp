#ifndef REALTIMELOOP_HPP_
#define REALTIMELOOP_HPP_

#include "systemx/app/statemachine.hpp"
#include "systemx/os/ostream.hpp"

namespace systemx {
	namespace app {
		namespace state {
			namespace base {
				struct AndStates : IStateData {
					AndStates(IStateMachine* statemachine1, IStateMachine* statemachine2) : statemachine1(statemachine1), statemachine2(statemachine2) {}
					IStateMachine* statemachine1;
					IStateMachine* statemachine2;
				};

				class RealTimeLoopBase : public IState {
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
					AndStates* substatemachines(IStateMachine* statemachine);

				};
			}

			using RealTimeLoop = Singleton<base::RealTimeLoopBase>;
		}
	}
}

#endif // !REALTIMELOOP_HPP_
#ifndef ISTATE_HPP_
#define ISTATE_HPP_

#include "systemx/app/discrete/isystem.hpp"
#include "systemx/app/discrete/istatemachine.hpp"


namespace systemx {
	namespace statemachine {

		class IStateMachine;

		class IState {
		public:
			virtual void EnterState(ISystem* system, IStateMachine* statemachine) {}
			virtual void ExitState(ISystem* system, IStateMachine* statemachine) {}

			virtual void Exit(ISystem* system, IStateMachine* statemachine) {}

			virtual void Start(ISystem* system, IStateMachine* statemachine) {}
			virtual void Restart(ISystem* system, IStateMachine* statemachine) {}
			virtual void Stop(ISystem* system, IStateMachine* statemachine) {}
			virtual void Suspend(ISystem* system, IStateMachine* statemachine) {}
			virtual void Resume(ISystem* system, IStateMachine* statemachine) {}

			virtual void SelfTestFailed(ISystem* system, IStateMachine* statemachine) {}
			virtual void SelftestOk(ISystem* system, IStateMachine* statemachine) {}
			virtual void Initalized(ISystem* system, IStateMachine* statemachine) {}

			virtual void ConfigX(ISystem* system, IStateMachine* statemachine) {}
			virtual void Configure(ISystem* system, IStateMachine* statemachine) {}
			virtual void ConfigurationEnded(ISystem* system, IStateMachine* statemachine) {}

			virtual void EventX(ISystem* system, IStateMachine* statemachine) {}
			virtual void EventY(ISystem* system, IStateMachine* statemachine) {}
			virtual void chMode(ISystem* system, IStateMachine* statemachine) {}
			virtual void RunRealTime(ISystem* system, IStateMachine* statemachine) {}
			virtual void Simulate(ISystem* system, IStateMachine* statemachine) {}


		};

		class IStateData {
		public:
			virtual ~IStateData() = default;
		};

	}
}

#endif // !ISYSTEM_HPP_
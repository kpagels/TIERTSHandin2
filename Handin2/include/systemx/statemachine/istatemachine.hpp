#ifndef ISTATEMACHINE_HPP_
#define ISTATEMACHINE_HPP_

#include "systemx/os/ostream.hpp"

namespace systemx {
		namespace statemachine {

			class ISystem {
			public:
				virtual os::ostream& logger() = 0;
				virtual void display_value(int value) = 0;
				virtual bool systemSelftest(void) = 0;
			};

			class IStateMachine;

			class IState {
			public:
				virtual void EnterState(ISystem* system, IStateMachine* statemachine) {}
				virtual void ExitState(ISystem* system, IStateMachine* statemachine) {}

				virtual void Restart(ISystem* system, IStateMachine* statemachine) {}
				virtual void SelfTestFailed(ISystem* system, IStateMachine* statemachine) {}
				virtual void SelftestOk(ISystem* system, IStateMachine* statemachine) {}
			};

			class IStateMachine {
			public:
				virtual void EnterState() = 0;
				virtual void ExitState() = 0;
				
				virtual void Restart() = 0;
				virtual void SelfTestFailed() = 0;
				virtual void SelftestOk() = 0;

				virtual void ChangeState(IState* state) = 0;
			};

			

			

			class IStateData {
			
			};
		}
}

#endif // !ISTATEMACHINE_HPP_
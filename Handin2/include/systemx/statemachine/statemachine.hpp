#ifndef STATEMACHINE_HPP_
#define STATEMACHINE_HPP_

#include "systemx/statemachine/istatemachine.hpp"

namespace systemx {
	namespace statemachine {
		
		class StateMachine : public IStateMachine {
		public:
			StateMachine(ISystem* system, IState* state) : system(system), state(state) {
				EnterState();
			}

			~StateMachine() {
				ExitState();
			}

			void ChangeState(IState* state);

			void Restart() {
				state->Restart(system, this);
			}

			void SelfTestFailed() {
				state->SelfTestFailed(system, this);
			}

			void SelftestOk() {
				state->SelftestOk(system, this);
			}


		private:

			void EnterState();
			void ExitState();

			ISystem* system;
			IState* state;
			IStateData* state_data;
		};
	}
}

#endif // !STATEMACHINE_HPP_
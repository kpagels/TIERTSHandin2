#include "systemx/statemachine/statemachine.hpp"

namespace systemx {
	namespace statemachine {
		
		void StateMachine::ChangeState(IState* state) {
			ExitState();
			this->state = state;
			EnterState();
		}

		void StateMachine::ExitState(void) {};
		void StateMachine::EnterState(void) {};
	}
}


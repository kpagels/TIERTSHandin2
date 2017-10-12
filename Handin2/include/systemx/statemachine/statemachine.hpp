#ifndef STATEMACHINE_HPP_
#define STATEMACHINE_HPP_

#include "systemx/statemachine/istatemachine.hpp"

namespace systemx {
	namespace statemachine {
		
		class StateMachine {
		public:
			void ChangeState(IState* state);
		private:

			void EnterState();
			void ExitState();

			IState* state;
			IStateData* state_data;
		};
	}
}

#endif // !STATEMACHINE_HPP_
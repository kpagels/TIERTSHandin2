#ifndef STATEMACHINE_HPP_
#define STATEMACHINE_HPP_

#include "systemx/statemachine/istate.hpp"
#include "systemx/statemachine/istatemachine.hpp"


namespace systemx {
	namespace statemachine {
		
		class StateMachine : public IStateMachine, public IStateData {
		public:
			StateMachine(ISystem* system, IState* state);

			~StateMachine();

			void ChangeState(IState* state);

			void Exit();

			void Start();

			void Restart();

			void Stop();

			void Suspend();

			void Resume();

			void SelfTestFailed();

			void SelftestOk();

			void Initalized();

			void ConfigX();

			void Configure();

			void ConfigurationEnded();

			void EventX();

			void EventY();

			void chMode();

			void RunRealTime();

			void Simulate();

		private:

			void EnterState();
			void ExitState();

			ISystem* system;
			IState* state;
			
		};
	}
}

#endif // !STATEMACHINE_HPP_
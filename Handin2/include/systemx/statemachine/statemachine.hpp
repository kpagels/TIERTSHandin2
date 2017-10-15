#ifndef STATEMACHINE_HPP_
#define STATEMACHINE_HPP_

#include "systemx/statemachine/istatemachine.hpp"

namespace systemx {
	namespace statemachine {
		
		class StateMachine : public IStateMachine, public IStateData {
		public:
			StateMachine(ISystem* system, IState* state) : system(system), state(state) {
				EnterState();
			}

			~StateMachine() {
				ExitState();
			}

			void ChangeState(IState* state);

			void Exit() {
				state->Exit(system, this);
			}

			void Start() {
				state->Start(system, this);
			}

			void Restart() {
				state->Restart(system, this);
			}

			void Stop() {
				state->Stop(system, this);
			}

			void Suspend() {
				state->Suspend(system, this);
			}

			void Resume() {
				state->Resume(system, this);
			}

			void SelfTestFailed() {
				state->SelfTestFailed(system, this);
			}

			void SelftestOk() {
				state->SelftestOk(system, this);
			}

			void Initalized() {
				state->Initalized(system, this);
			}

			void ConfigX() {
				state->ConfigX(system, this);
			}

			void Configure() {
				state->Configure(system, this);
			}

			void ConfigurationEnded() {
				state->ConfigurationEnded(system, this);
			}

		private:

			void EnterState();
			void ExitState();

			ISystem* system;
			IState* state;
			
		};
	}
}

#endif // !STATEMACHINE_HPP_
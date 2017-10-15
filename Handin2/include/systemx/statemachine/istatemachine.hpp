#ifndef ISTATEMACHINE_HPP_
#define ISTATEMACHINE_HPP_

#include "systemx/os/ostream.hpp"
#include "systemx/statemachine/isystem.hpp"
#include "systemx/statemachine/istate.hpp"


namespace systemx {
		namespace statemachine {
			class IState;
			class IStateData;

			class IStateMachine {
			public:
				virtual ~IStateMachine() = default;

				virtual void EnterState() = 0;
				virtual void ExitState() = 0;
				
				virtual void Exit() = 0;

				virtual void Start() = 0;
				virtual void Restart() = 0;
				virtual void Stop() = 0;
				virtual void Suspend() = 0;
				virtual void Resume() = 0;

				virtual void SelfTestFailed() = 0;
				virtual void SelftestOk() = 0;
				virtual void Initalized() = 0;
				
				virtual void ConfigX() = 0;
				virtual void Configure() = 0;
				virtual void ConfigurationEnded() = 0;

				virtual void EventX() = 0;
				virtual void EventY() = 0;
				virtual void chMode() = 0;
				virtual void RunRealTime() = 0;
				virtual void Simulate() = 0;

				virtual void ChangeState(IState* state) = 0;

				IStateData* state_data;
			};

			
		}
}

#endif // !ISTATEMACHINE_HPP_
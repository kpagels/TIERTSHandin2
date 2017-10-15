#ifndef ISTATEMACHINE_HPP_
#define ISTATEMACHINE_HPP_

#include "systemx/os/ostream.hpp"

namespace systemx {
		namespace statemachine {

			class ISystem {
			public:
				virtual os::ostream& logger() = 0;
				virtual void display_value(int value) = 0;
				virtual void systemSelftest(void) = 0;
				virtual void startInitializing(void) = 0;
				virtual void display_error(int ErrorNo) = 0;
				virtual void readConfigurationInfo(void) = 0;
				virtual void PerformConfigurationX(void) = 0;
				virtual void run(void) = 0;
			};

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

			};

			class IStateData {
			public:
				virtual ~IStateData() = default;
			};


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

				virtual void ChangeState(IState* state) = 0;

				IStateData* state_data;
			};

			

			

			
		}
}

#endif // !ISTATEMACHINE_HPP_
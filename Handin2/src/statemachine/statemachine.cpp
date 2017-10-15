#include "systemx/statemachine/statemachine.hpp"

namespace systemx {
	namespace statemachine {
		
		void StateMachine::ChangeState(IState* state) {
			ExitState();
			this->state = state;
			EnterState();
		}

		void StateMachine::ExitState() {
			state->ExitState(system, this);
		};

		void StateMachine::EnterState() {
			state->EnterState(system, this);
		};

		StateMachine::StateMachine(ISystem* system, IState* state) : system(system), state(state) {
			EnterState();
		}

		StateMachine::~StateMachine() {
			ExitState();
		}


		void StateMachine::Exit() {
			state->Exit(system, this);
		}

		void StateMachine::Start() {
			state->Start(system, this);
		}

		void StateMachine::StateMachine::Restart() {
			state->Restart(system, this);
		}

		void StateMachine::Stop() {
			state->Stop(system, this);
		}

		void StateMachine::Suspend() {
			state->Suspend(system, this);
		}

		void StateMachine::Resume() {
			state->Resume(system, this);
		}

		void StateMachine::SelfTestFailed() {
			state->SelfTestFailed(system, this);
		}

		void StateMachine::SelftestOk() {
			state->SelftestOk(system, this);
		}

		void StateMachine::Initalized() {
			state->Initalized(system, this);
		}

		void StateMachine::ConfigX() {
			state->ConfigX(system, this);
		}

		void StateMachine::Configure() {
			state->Configure(system, this);
		}

		void StateMachine::ConfigurationEnded() {
			state->ConfigurationEnded(system, this);
		}

		void StateMachine::EventX() {
			state->EventX(system, this);
		}

		void StateMachine::EventY() {
			state->EventY(system, this);
		}

		void StateMachine::chMode() {
			state->chMode(system, this);
		}

		void StateMachine::RunRealTime() {
			state->RunRealTime(system, this);
		}

		void StateMachine::Simulate() {
			state->Simulate(system, this);
		}
	}
}


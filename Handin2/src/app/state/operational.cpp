#include "systemx/os/iostream.hpp"
#include "systemx/app/state/initializing.hpp"
#include "systemx/app/state/operational.hpp"
#include "systemx/app/state/poweronselftest.hpp"
#include "systemx/app/state/ready.hpp"
#include "systemx/statemachine/statemachine.hpp"

namespace systemx {
	namespace app {
		namespace state {
			namespace base {

				void OperationalBase::EnterState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "EnterState: Operational" << os::endl;
					statemachine->state_data = new StateMachine(system, Ready::Instance());
				}

				void OperationalBase::ExitState(ISystem* system, IStateMachine* statemachine) {
					delete statemachine->state_data;
					system->logger() << "ExitState: Operational" << os::endl;
				}

				IStateMachine* OperationalBase::substatemachine(IStateMachine* statemachine) {
					return static_cast<StateMachine*>(statemachine->state_data);
				}

				void OperationalBase::Restart(ISystem* system, IStateMachine* statemachine) {
					statemachine->ChangeState(PowerOnSelfTest::Instance());
				}

				void OperationalBase::Exit(ISystem* system, IStateMachine* statemachine) {
					substatemachine(statemachine)->Exit();
				};

				void OperationalBase::Start(ISystem* system, IStateMachine* statemachine) {
					substatemachine(statemachine)->Start();
				};
				void OperationalBase::Stop(ISystem* system, IStateMachine* statemachine) {
					substatemachine(statemachine)->Stop();
				};
				void OperationalBase::Suspend(ISystem* system, IStateMachine* statemachine) {
					substatemachine(statemachine)->Suspend();
				};
				void OperationalBase::Resume(ISystem* system, IStateMachine* statemachine) {
					substatemachine(statemachine)->Resume();
				};

				void OperationalBase::SelfTestFailed(ISystem* system, IStateMachine* statemachine) {
					substatemachine(statemachine)->SelfTestFailed();
				};
				void OperationalBase::SelftestOk(ISystem* system, IStateMachine* statemachine) {
					substatemachine(statemachine)->SelftestOk();
				};
				void OperationalBase::Initalized(ISystem* system, IStateMachine* statemachine) {
					substatemachine(statemachine)->Initalized();
				};

				void OperationalBase::ConfigX(ISystem* system, IStateMachine* statemachine) {
					substatemachine(statemachine)->ConfigX();
				};
				void OperationalBase::Configure(ISystem* system, IStateMachine* statemachine) {
					substatemachine(statemachine)->Configure();
				};
				void OperationalBase::ConfigurationEnded(ISystem* system, IStateMachine* statemachine) {
					substatemachine(statemachine)->ConfigurationEnded();
				};

				void OperationalBase::EventX(ISystem* system, IStateMachine* statemachine) {
					substatemachine(statemachine)->EventX();
				};

				void OperationalBase::EventY(ISystem* system, IStateMachine* statemachine) {
					substatemachine(statemachine)->EventY();
				};

				void OperationalBase::chMode(ISystem* system, IStateMachine* statemachine) {
					substatemachine(statemachine)->chMode();
				};

				void OperationalBase::RunRealTime(ISystem* system, IStateMachine* statemachine) {
					substatemachine(statemachine)->RunRealTime();
				};

				void OperationalBase::Simulate(ISystem* system, IStateMachine* statemachine) {
					substatemachine(statemachine)->Simulate();
				};



			}
		}
	}
}


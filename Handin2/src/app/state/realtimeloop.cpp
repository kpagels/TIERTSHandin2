#include "systemx/os/iostream.hpp"
#include "systemx/app/state/initializing.hpp"
#include "systemx/app/state/realtimeloop.hpp"
#include "systemx/app/state/poweronselftest.hpp"
#include "systemx/app/state/ready.hpp"
#include "systemx/app/state/suspended.hpp"
#include "systemx/app/state/mode1.hpp"
#include "systemx/app/state/realtimeexecution.hpp"
#include "systemx/statemachine/statemachine.hpp"

namespace systemx {
	namespace app {
		namespace state {
			namespace base {

				void RealTimeLoopBase::EnterState(ISystem* system, IStateMachine* statemachine) {
					system->logger() << "EnterState: RealTimeLoop" << os::endl;
					statemachine->state_data = new AndStates{
						new StateMachine(system, Mode1::Instance()),
						new StateMachine(system, RealTimeExecution::Instance())
					};

					system->continues.start();
				}

				void RealTimeLoopBase::ExitState(ISystem* system, IStateMachine* statemachine) {

					system->continues.stop();

					delete substatemachines(statemachine)->statemachine1;
					delete substatemachines(statemachine)->statemachine2;
					delete statemachine->state_data;
					system->logger() << "ExitState: RealTimeLoop" << os::endl;
				}

				AndStates* RealTimeLoopBase::substatemachines(IStateMachine* statemachine) {
					return static_cast<AndStates*>(statemachine->state_data);
				}

				void RealTimeLoopBase::Restart(ISystem* system, IStateMachine* statemachine) {
					substatemachines(statemachine)->statemachine1->Restart();
					substatemachines(statemachine)->statemachine2->Restart();
				}

				void RealTimeLoopBase::Exit(ISystem* system, IStateMachine* statemachine) {
					substatemachines(statemachine)->statemachine1->Exit();
					substatemachines(statemachine)->statemachine2->Exit();
				};

				void RealTimeLoopBase::Start(ISystem* system, IStateMachine* statemachine) {
					substatemachines(statemachine)->statemachine1->Start();
					substatemachines(statemachine)->statemachine2->Start();
				};
				void RealTimeLoopBase::Stop(ISystem* system, IStateMachine* statemachine) {
					statemachine->ChangeState(Ready::Instance());
				};
				void RealTimeLoopBase::Suspend(ISystem* system, IStateMachine* statemachine) {
					statemachine->ChangeState(Suspended::Instance());
				};
				void RealTimeLoopBase::Resume(ISystem* system, IStateMachine* statemachine) {
					substatemachines(statemachine)->statemachine1->Resume();
					substatemachines(statemachine)->statemachine2->Resume();
				};

				void RealTimeLoopBase::SelfTestFailed(ISystem* system, IStateMachine* statemachine) {
					substatemachines(statemachine)->statemachine1->SelfTestFailed();
					substatemachines(statemachine)->statemachine2->SelfTestFailed();
				};
				void RealTimeLoopBase::SelftestOk(ISystem* system, IStateMachine* statemachine) {
					substatemachines(statemachine)->statemachine1->SelftestOk();
					substatemachines(statemachine)->statemachine2->SelftestOk();
				};
				void RealTimeLoopBase::Initalized(ISystem* system, IStateMachine* statemachine) {
					substatemachines(statemachine)->statemachine1->Initalized();
					substatemachines(statemachine)->statemachine2->Initalized();
				};

				void RealTimeLoopBase::ConfigX(ISystem* system, IStateMachine* statemachine) {
					substatemachines(statemachine)->statemachine1->ConfigX();
					substatemachines(statemachine)->statemachine2->ConfigX();
				};
				void RealTimeLoopBase::Configure(ISystem* system, IStateMachine* statemachine) {
					substatemachines(statemachine)->statemachine1->Configure();
					substatemachines(statemachine)->statemachine2->Configure();
				};
				void RealTimeLoopBase::ConfigurationEnded(ISystem* system, IStateMachine* statemachine) {
					substatemachines(statemachine)->statemachine1->ConfigurationEnded();
					substatemachines(statemachine)->statemachine2->ConfigurationEnded();
				};

				void RealTimeLoopBase::EventX(ISystem* system, IStateMachine* statemachine) {
					substatemachines(statemachine)->statemachine1->EventX();
					substatemachines(statemachine)->statemachine2->EventX();
				};

				void RealTimeLoopBase::EventY(ISystem* system, IStateMachine* statemachine) {
					substatemachines(statemachine)->statemachine1->EventY();
					substatemachines(statemachine)->statemachine2->EventY();
				};

				void RealTimeLoopBase::chMode(ISystem* system, IStateMachine* statemachine) {
					substatemachines(statemachine)->statemachine1->chMode();
					substatemachines(statemachine)->statemachine2->chMode();
				};

				void RealTimeLoopBase::RunRealTime(ISystem* system, IStateMachine* statemachine) {
					substatemachines(statemachine)->statemachine1->RunRealTime();
					substatemachines(statemachine)->statemachine2->RunRealTime();
				};

				void RealTimeLoopBase::Simulate(ISystem* system, IStateMachine* statemachine) {
					substatemachines(statemachine)->statemachine1->Simulate();
					substatemachines(statemachine)->statemachine2->Simulate();
				};

			}
		}
	}
}


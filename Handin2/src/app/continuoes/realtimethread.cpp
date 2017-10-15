#include "systemx/app/continuoes/realtimethread.hpp"

namespace systemx {
	namespace app {
		namespace continues {


			
				RealTimeThread::RealTimeThread(IContinues* continues) : continues(continues) {}

				void RealTimeThread::run() {
					continues->run();
				}
		}
	}
}
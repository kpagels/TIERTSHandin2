#ifndef REALTIMETHREAD_HPP_
#define REALTIMETHREAD_HPP_

#include "systemx/app/continuoes/continuoes.hpp"

namespace systemx {
	namespace app {
		namespace continues {

			class IContinues;

			class RealTimeThread : public os::thread {
			public:
				RealTimeThread(IContinues* continues);

				void run();

			private:
				IContinues* continues;
			};
		}
	}
}

#endif // !APP_HPP_
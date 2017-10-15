#ifndef DISCRETEPROCESSINGTHREAD_HPP_
#define DISCRETEPROCESSINGTHREAD_HPP_

#include "systemx/os/thread.hpp"

namespace systemx {
	namespace app {

		class DiscreteProcessingThread : public os::thread {
		public:

		private:
			virtual void run(){}
		};

	}
}

#endif // !DISCRETEPROCESSINGTHREAD_HPP_
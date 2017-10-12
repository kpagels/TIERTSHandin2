#ifndef IAPP_HPP_
#define IAPP_HPP_

namespace systemx {
	namespace app {

		class IApp {
		public:
			virtual void run(void) = 0;
		};

	}
}

#endif // !IAPP_HPP_
#ifndef ITIMESTRATEGY_HPP_
#define ITIMESTRATEGY_HPP_


#include "systemx/os/thread.hpp"
#include "systemx/comm/itimesensor.hpp"

namespace systemx {
	namespace app {
		namespace continues {

			class ITimeStrategy {
			public:
				using value_type = comm::ITimeSensor::value_type;
				virtual ~ITimeStrategy() = default;
				virtual value_type calc(value_type data) {
					return data;
				}

			};

			class TimeStrategy1 : public ITimeStrategy {
				virtual value_type calc(value_type data) {
					return data / 2;
				}
			};

			class TimeStrategy2 : public ITimeStrategy {
				virtual value_type calc(value_type data) {
					return data;
				}
			};

			class TimeStrategy3 : public ITimeStrategy {
				virtual value_type calc(value_type data) {
					return data * 2;
				}
			};
		}
	}
}

#endif // !ITIMESTRATEGY_HPP_
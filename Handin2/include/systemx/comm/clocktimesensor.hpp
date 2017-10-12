#ifndef CLOCKTIMESENSOR_HPP_
#define CLOCKTIMESENSOR_HPP_

#include "systemx/comm/itimesensor.hpp"

namespace systemx {
namespace comm {

   template<typename CLOCK>
	class ClockTimeSensor : public ITimeSensor {
	public:
      value_type get_value(void) {
		  return os::chrono::duration_cast<os::chrono::seconds>(clock.get_value().time_since_epoch()).count();
      };
      
   private:
      CLOCK clock;
	};

}
}

#endif // !CLOCKTIMESENSOR_HPP_
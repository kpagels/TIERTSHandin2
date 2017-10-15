#ifndef MUTEX_HPP_
#define MUTEX_HPP_

#include <mutex>

namespace systemx {
    namespace os {
    
    using mutex = std::mutex;

	template< class Mutex >
	using lock_guard = std::lock_guard<Mutex>;

    }
}

#endif // !MUTEX_HPP_
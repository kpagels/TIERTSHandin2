#ifndef MUTEX_HPP_
#define MUTEX_HPP_

#include <mutex>
#include <condition_variable>

namespace systemx {
    namespace os {
    
    using mutex = std::mutex;

	using condition_variable = std::condition_variable;

	template< class Mutex >
	using lock_guard = std::lock_guard<Mutex>;

	template< class Mutex >
	using unique_lock = std::unique_lock<Mutex>;

    }
}

#endif // !MUTEX_HPP_
#ifndef THREAD_HPP_
#define THREAD_HPP_

#include <thread>
#include <mutex>

namespace systemx {
    namespace os {
        class thread{
        public:
            virtual void start(){
                _thread = std::thread(&thread::run, this)
            }
            ~thread(){
                thread_.join();
            }
        protected:
            virtual void run() = 0;
            
            std::mutex _mutex;
            std::thread _thread;
            
        };
    }
}

#endif // !THREAD_HPP_

#ifndef THREAD_HPP_
#define THREAD_HPP_

#include <thread>

namespace systemx {
    namespace os {
        class thread{
        public:
            virtual void start(){
				_thread = std::thread(&thread::run, this);
            }

            ~thread(){
                _thread.join();
            }
        protected:
            virtual void run() = 0;

            std::thread _thread;
            
        };
    }
}

#endif // !THREAD_HPP_

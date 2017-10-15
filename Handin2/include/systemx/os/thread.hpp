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
                std::lock_guard<std::mutex> guard(_mutex);
                thread_.join();
            }
        private:
            virtual void run() = 0;

            std::thread _thread;
            std::mutex _mutex;
        };
    }
}

#endif // !THREAD_HPP_

#ifndef APP_STATEMACHINE_HPP_
#define APP_STATEMACHINE_HPP_

#include "systemx/statemachine/istatemachine.hpp"

namespace systemx {
	namespace app {
		namespace state {

			template <typename T>
			class Singleton {
			public:
				static T* Instance() {
					if (Singleton::ptr == nullptr)
						Singleton::ptr = new T();
					return Singleton::ptr;
				}

			public:
				Singleton();

			private:
				static T* ptr;
			};

			template <typename T>
			T* Singleton<T>::ptr = nullptr;
			
			using namespace statemachine;
          
        }
    }
}

#endif // !APP_STATEMACHINE_HPP_
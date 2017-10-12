cmake_minimum_required (VERSION 3.6)
project (systemx)

set(HEADERS 
include/systemx/app/app.hpp
include/systemx/app/iapp.hpp
include/systemx/app/statemachine.hpp
include/systemx/app/states/failure.hpp
include/systemx/app/states/initializing.hpp
include/systemx/app/states/poweronselftest.hpp
include/systemx/comm/clocktimesensor.hpp
include/systemx/comm/itimesensor.hpp
include/systemx/hw/clock.hpp
include/systemx/hw/fakeclock.hpp
include/systemx/hw/iclock.hpp
include/systemx/os/chrono.hpp
include/systemx/os/iostream.hpp
include/systemx/os/istream.hpp
include/systemx/os/ostream.hpp
include/systemx/statemachine/istatemachine.hpp
include/systemx/statemachine/statemachine.hpp
include/systemx/ui/consoledisplay.hpp
include/systemx/ui/display.hpp
include/systemx/ui/idisplay.hpp
)

set(SOURCES
src/app/app.cpp
src/app/states/failure.cpp
src/app/states/initializing.cpp
src/app/states/poweronselftest.cpp
src/hw/clock.cpp
src/hw/fakeclock.cpp
src/main.cpp
src/statemachine/statemachine.cpp
src/ui/consoledisplay.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC include)
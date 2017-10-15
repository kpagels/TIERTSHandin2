cmake_minimum_required (VERSION 3.6)
project (systemx)

set(HEADERS 
include/systemx/app/app.hpp
include/systemx/app/iapp.hpp
include/systemx/app/state/failure.hpp
include/systemx/app/state/initializing.hpp
include/systemx/app/state/mode1.hpp
include/systemx/app/state/operational.hpp
include/systemx/app/state/poweronselftest.hpp
include/systemx/app/state/ready.hpp
include/systemx/app/state/realtimeloop.hpp
include/systemx/app/state/realtimeexecution.hpp
include/systemx/app/state/suspended.hpp
include/systemx/app/statemachine.hpp
include/systemx/comm/clocktimesensor.hpp
include/systemx/comm/itimesensor.hpp
include/systemx/hw/clock.hpp
include/systemx/hw/fakeclock.hpp
include/systemx/hw/iclock.hpp
include/systemx/os/chrono.hpp
include/systemx/os/iostream.hpp
include/systemx/os/istream.hpp
include/systemx/os/ostream.hpp
include/systemx/os/thread.hpp
include/systemx/statemachine/istatemachine.hpp
include/systemx/statemachine/statemachine.hpp
include/systemx/ui/consoledisplay.hpp
include/systemx/ui/display.hpp
include/systemx/ui/idisplay.hpp
)

set(SOURCES
src/app/app.cpp
src/app/state/failure.cpp
src/app/state/initializing.cpp
src/app/state/mode1.cpp
src/app/state/operational.cpp
src/app/state/poweronselftest.cpp
src/app/state/ready.cpp
src/app/state/realtimeloop.cpp
src/app/state/realtimeexecution.cpp
src/app/state/suspended.cpp
src/hw/clock.cpp
src/hw/fakeclock.cpp
src/main.cpp
src/statemachine/statemachine.cpp
src/ui/consoledisplay.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC include)
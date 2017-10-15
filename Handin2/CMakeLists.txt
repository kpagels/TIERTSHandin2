cmake_minimum_required (VERSION 3.6)
project (systemx)

set(HEADERS 
include/systemx/app/app.hpp
include/systemx/app/continuoes/continuoes.hpp
include/systemx/app/continuoes/itimestrategy.hpp
include/systemx/app/continuoes/realtimethread.hpp
include/systemx/app/iapp.hpp

include/systemx/app/discrete/istatemachine.hpp
include/systemx/app/discrete/isystem.hpp
include/systemx/app/discrete/istate.hpp
include/systemx/app/discrete/statemachine.hpp
include/systemx/app/discrete/singleton.hpp

include/systemx/app/discrete/state/failure.hpp
include/systemx/app/discrete/state/initializing.hpp
include/systemx/app/discrete/state/mode1.hpp
include/systemx/app/discrete/state/mode2.hpp
include/systemx/app/discrete/state/mode3.hpp
include/systemx/app/discrete/state/operational.hpp
include/systemx/app/discrete/state/poweronselftest.hpp
include/systemx/app/discrete/state/ready.hpp
include/systemx/app/discrete/state/realtimeloop.hpp
include/systemx/app/discrete/state/realtimeexecution.hpp
include/systemx/app/discrete/state/simulation.hpp
include/systemx/app/discrete/state/suspended.hpp

include/systemx/app/DiscreteProcessingThread.hpp
include/systemx/comm/clocktimesensor.hpp
include/systemx/comm/itimesensor.hpp
include/systemx/comm/itimewriter.hpp
include/systemx/comm/timewriter.hpp
include/systemx/hw/clock.hpp
include/systemx/hw/fakeclock.hpp
include/systemx/hw/iclock.hpp
include/systemx/os/chrono.hpp
include/systemx/os/iostream.hpp
include/systemx/os/istream.hpp
include/systemx/os/ostream.hpp
include/systemx/os/thread.hpp
include/systemx/os/mutex.hpp
include/systemx/os/scoped_lock.hpp

include/systemx/ui/consoledisplay.hpp
include/systemx/ui/display.hpp
include/systemx/ui/idisplay.hpp
)

set(SOURCES
src/app/app.cpp
src/app/continuoes/continuoes.cpp
src/app/continuoes/realtimethread.cpp
src/app/discrete/state/failure.cpp
src/app/discrete/state/initializing.cpp
src/app/discrete/state/mode1.cpp
src/app/discrete/state/mode2.cpp
src/app/discrete/state/mode3.cpp
src/app/discrete/state/operational.cpp
src/app/discrete/state/poweronselftest.cpp
src/app/discrete/state/ready.cpp
src/app/discrete/state/realtimeloop.cpp
src/app/discrete/state/realtimeexecution.cpp
src/app/discrete/state/simulation.cpp
src/app/discrete/state/suspended.cpp
src/app/discrete/statemachine.cpp
src/hw/clock.cpp
src/hw/fakeclock.cpp
src/main.cpp

src/ui/consoledisplay.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC include)
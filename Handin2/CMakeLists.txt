cmake_minimum_required (VERSION 3.6)
project (systemx)

add_executable(${PROJECT_NAME}
                  src/main.cpp
                  src/app/app.cpp
                  src/hw/clock.cpp
                  src/hw/fakeclock.cpp
                  src/ui/consoledisplay.cpp
                  src/statemachine/statemachine.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC include)
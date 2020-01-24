cmake_minimum_required (VERSION 2.6)

find_package(PkgConfig)

project(Othello CXX)
enable_language(C)

set(CMAK_CXX_COMPILER "clang++")
set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -Wno-unknown-pragmas -fPIC -msse4.1 -D_GLFW_X11")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0 -pg -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG -march=x86-64")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-g3 -Og -pg")
set(CMAKE_CXX_FLAGS_MINSIZEREL "-Os -DNDEBUG -march=x86-64")

set(SOURCE_FILES
  "src/main.cpp"
  "src/field.cpp"
  "src/beamSearch.cpp"
)

add_executable(Othello ${SOURCE_FILES})

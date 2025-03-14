cmake_minimum_required(VERSION 3.22)
project(find-all-distances)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(find-all-distances
    main.cpp
    graph.cpp
    except.cpp
    tests.cpp
)
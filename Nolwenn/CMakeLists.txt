cmake_minimum_required(VERSION 3.9)
project(Indie)

set(CMAKE_CXX_STANDARD 11)

add_executable(Indie main.cpp Map.cpp Map.hpp Utils.hpp Chunk.cpp Chunk.hpp Entity.cpp Entity.hpp Dimension.cpp Dimension.hpp Position.cpp Position.hpp Range.cpp Range.hpp Mask.cpp Mask.hpp)
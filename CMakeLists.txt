cmake_minimum_required(VERSION 3.0)

project(bomberman)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ilibinclude -Iincludes -std=c++17")

set(SRC_FILE
        gui/Camera.cpp
        gui/Control.cpp
        gui/Core.cpp
        gui/Mesh.cpp
        gui/Terrain.cpp
        src/Game.cpp
        src/main.cpp
        menu/MainMenu.cpp
        menu/MenuEvent.cpp
        menu/PlayMenu.cpp
        menu/MapMenu.cpp
        menu/OptionMenu.cpp
        Game/Bomb.cpp
        Game/Chunk.cpp
        Game/Dimension.cpp
        Game/Entity.cpp
        Game/Map.cpp
        Game/Mask.cpp
        Game/Player.cpp
        Game/Position.cpp
        Game/Range.cpp)

set(HEADERS
        includes/Camera.hpp
        includes/Control.hpp
        includes/Core.hpp
        includes/Mesh.hpp
        includes/Terrain.hpp
        includes/Game.hpp
        includes/Bomb.hpp
        includes/Chunk.hpp
        includes/Dimension.hpp
        includes/Entity.hpp
        includes/Map.hpp
        includes/Mask.hpp
        includes/Player.hpp
        includes/Position.hpp
        includes/Range.hpp
        includes/indie.hpp
        includes/Utils.hpp
        includes/MainMenu.hpp)

find_package(OpenGL REQUIRED)
find_package(X11 REQUIRED)
find_package(GLUT REQUIRED)

include_directories(lib/
        ${OPENGL_INCLUDE_DIR}
        ${X11_INCLUDE_DIR}
        ${GLUT_INCLUDE_DIR}
        "/usr/lib/"
        ./audio/
        ./includes
        )

link_directories(
        ${CMAKE_SOURCE_DIR}
        ${OPENGL_LIBRARIES}
        ${X11_LIBRARIES}
        ${X11_Xxf86vm_LIB}
        ${GLUT_LIBRERY}
        "/usr/lib"
        ./audio/
        ./includes
        )

add_executable(bomberman ${SRC_FILE} ${HEADERS})

target_link_libraries(bomberman
        Irrlicht
        IrrKlang
        )

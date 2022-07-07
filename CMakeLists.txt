cmake_minimum_required(VERSION 3.22)
project(proyecto_final_proyecto_grupo6)

set(CMAKE_CXX_STANDARD 17)

add_executable(proyecto_final_proyecto_grupo6 main.cpp application.cpp application.h Keyboard.h Keyboard.cpp Mouse.cpp Mouse.h Display.h components.cpp components.h button.cpp button.h interface.cpp interface.h textbox.cpp textbox.h block.cpp block.h item.cpp item.h player.cpp player.h label.cpp label.h playerA.h playerB.h bot.h tsp.cpp)

SET(ALLEGRO_ROOT /usr/local/)

INCLUDE_DIRECTORIES( ${ALLEGRO_ROOT}/include/allegro5 )
LINK_DIRECTORIES( ${ALLEGRO_ROOT}/lib)

TARGET_INCLUDE_DIRECTORIES(proyecto_final_proyecto_grupo6 PUBLIC ${ALLEGRO_ROOT})
TARGET_LINK_LIBRARIES(proyecto_final_proyecto_grupo6 allegro
        allegro_color
        allegro_main
        allegro_primitives
        allegro_ttf
        allegro_acodec
        allegro_audio
        allegro_font
        allegro_image)



file(GLOB LIBRARIES "/usr/local/")
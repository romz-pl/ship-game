SET( EXE_NAME ship )

add_executable( ${EXE_NAME}
    Actor.cpp
    AnimSpriteComponent.cpp
    BGSpriteComponent.cpp
    Component.cpp
    Game.cpp
    Main.cpp
    Math.cpp
    Ship.cpp
    SpriteComponent.cpp
)

target_link_libraries( ${EXE_NAME}
    SDL2
    SDL2_image
)




add_executable(${projectName} main.cpp)

# This gets the Cadmium path from the server's environment settings
set(CADMIUM_DIR $ENV{CADMIUM})

target_include_directories(${projectName} PUBLIC
    "."
    "../include"                       # Points to your socialCell.hpp and socialState.hpp
    ${CADMIUM_DIR}                     # Points to Cadmium headers
    "${CADMIUM_DIR}/../json/include"   # Points to JSON library headers
)

# Uses C++23 standards required by Cadmium v2
target_compile_options(${projectName} PUBLIC -std=gnu++2b)
project(logger)

add_library(logger logger_backend.c)

target_include_directories(logger
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include)

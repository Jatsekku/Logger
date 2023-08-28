project(logger)

add_executable(main module1.c module2.c main.c)

target_link_libraries(main
    PRIVATE
    logger)

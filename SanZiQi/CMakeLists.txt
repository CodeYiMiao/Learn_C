project(main)

aux_source_directory(./src SRCS)

add_executable(${PROJECT_NAME} ${SRCS})
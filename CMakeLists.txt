cmake_minimum_required(VERSION 3.10)
project(CatenateUtility VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_EXTENSIONS OFF)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(
  ${CMAKE_SOURCE_DIR}/model
)

set(HEADERS
  model/cat_utility.h
)

set(SOURCES
  model/cat_utility.c
)

add_executable(${PROJECT_NAME}
  ${HEADERS}
  ${SOURCES}
  main.c
)

target_compile_options(
  ${PROJECT_NAME}
  PRIVATE
  -Wall
  -Werror
  -Wextra
  -Wpedantic
  -fsanitize=address
)

target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE
  -fsanitize=address
)

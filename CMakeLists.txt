set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

cmake_minimum_required(VERSION 3.23)

project(MyProject)

# Add your source files here
set(SOURCES 
    main.c
    src/map.c
)

find_package(cjson REQUIRED)
find_library(CJSON_LIB cjson)
# Add your header files here
set(HEADERS 
    include/map.h
)
# 定义 DEBUG 宏
# target_compile_definitions(MyTargetName PRIVATE DEBUG)

# Add any libraries or dependencies here
include_directories(${CMAKE_INCLUDE_PATH})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories("C:/msys64/mingw64/include")# 添加头文件路径, 用于查找头文件,minjw64是我的mingw64的安装路径

# Set the output directory for the build artifacts
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/)

# Add the executable target
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})


# Link any libraries or dependencies
target_link_libraries(${PROJECT_NAME} ${LIBRARY_OUTPUT_PATH})
target_link_libraries(${PROJECT_NAME} ${CJSON_LIB})

# 将.res文件夹复制到输出目录
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/.res
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/.res
)
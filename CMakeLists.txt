cmake_minimum_required(VERSION 3.23)

project(MyProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# 添加源文件
set(SOURCES 
    main.c
    src/players.c
    src/tool_house.c
    src/earthup.c
    src/map.c
#    src/useprops.c
#    src/help.c
    src/pass_road_money.c
)

# 查找cjson库
find_package(cjson REQUIRED)
find_library(CJSON_LIB cjson)

# 添加头文件
set(HEADERS 
    include/players.h
    include/tool_house.h
    include/earthup.h
    include/map.h
#    include/useprops.h
    include/help.h
    include/pass_road_money.h
)

# 添加头文件路径
include_directories(${CMAKE_INCLUDE_PATH})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories("C:/msys64/mingw64/include")

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out/)

# 添加可执行目标
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# 链接库
target_link_libraries(${PROJECT_NAME} ${LIBRARY_OUTPUT_PATH})
target_link_libraries(${PROJECT_NAME} ${CJSON_LIB})

# 将.res文件夹复制到输出目录
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/.res
    ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/.res
)

# 启用测试
enable_testing()

# 查找 Python3
find_package(Python3 REQUIRED)

# 获取所有测试目录
file(GLOB TEST_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/.test/*)

# 创建输出目录
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/testout)

# 为每个测试目录添加一个测试
foreach(TEST_DIR ${TEST_DIRS})
    # 提取目录名称
    get_filename_component(TEST_NAME ${TEST_DIR} NAME)

    # 创建测试特定的输出目录
    file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/testout/${TEST_NAME})

    # 添加测试
    add_test(
        NAME ${TEST_NAME}
        COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/test.py ${TEST_DIR}
        WORKING_DIRECTORY ${TEST_DIR}
    )

    # 设置测试属性，重定向输出和错误输出
    set_tests_properties(${TEST_NAME} PROPERTIES
        PASS_REGULAR_EXPRESSION "Test Passed"
        FAIL_REGULAR_EXPRESSION "Test Failed"
        ENVIRONMENT "PYTHONUNBUFFERED=1"
        PROCESSORS 1
        # 重定向输出
        TEST_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/testout/${TEST_NAME}
    )
endforeach()

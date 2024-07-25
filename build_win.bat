@echo off

REM 安装依赖项
conan install . --build=missing --profile=conan_profile_x64

REM 创建构建目录
if not exist build (
    mkdir build
)

cd build

REM 配置 CMake 项目
cmake .. -G "Ninja" ^
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ^
    -DCMAKE_BUILD_TYPE=Debug ^
    -DCMAKE_TOOLCHAIN_FILE="%CD%\Release\generators\conan_toolchain.cmake" ^
    -DCMAKE_PREFIX_PATH="%CD%\Release\generators"

REM 构建项目
cmake --build . --config Debug

cd ../out

echo ============Running MyProject.exe=============
.\MyProject

pause
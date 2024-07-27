@echo off

chcp 65001

conan install . --build=missing --profile=conan_profile_x64

if not exist build (
    mkdir build
)

cd build

cmake .. -G "Ninja" ^
    -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ^
    -DCMAKE_BUILD_TYPE=Debug ^
    -DCMAKE_TOOLCHAIN_FILE="%CD%\Release\generators\conan_toolchain.cmake" ^
    -DCMAKE_PREFIX_PATH="%CD%\Release\generators"

cmake --build . --config Debug

cd ../out

echo ============Running MyProject.exe=============

@REM .\MyProject

echo ============Running MyProject.exe with argument=============

@REM .\MyProject ".res/users.json"

echo ============test MyProject.exe with parallel 10=============

pause

cd ../build

ctest --parallel 10

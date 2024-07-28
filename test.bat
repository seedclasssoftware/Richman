@echo off
chcp 65001

cd ./build

ctest --parallel 10

cd ..
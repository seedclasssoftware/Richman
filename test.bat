@echo off
chcp 65001

cd ./build

ctest --parallel 20

cd ..
@echo off
chcp 65001

cd ./build

ctest --parallel 10 --rerun-failed --output-on-failure

cd ..
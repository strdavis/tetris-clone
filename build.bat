@echo off

if not exist "build" mkdir build
cmake -B build
cmake --build build
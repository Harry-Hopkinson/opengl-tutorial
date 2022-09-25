cd ..
del /q CMakeFiles, CMakeCache.txt, cmake_install.cmake, Makefile, main.exe
cmake . -G "MinGW Makefiles"
make
main.exe
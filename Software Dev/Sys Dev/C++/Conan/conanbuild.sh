conan install . --output-folder=build --build=missing
cmake -S . -B ./build/ -DCMAKE_BUILD_TYPE=RELEASE -DCMAKE_EXPORT_COMPILE_COMMANDS=1
cd build
make

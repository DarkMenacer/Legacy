conan install . --output-folder=build --build=missing
cd build
cmake -S .. -B . -DCMAKE_BUILD_TYPE=RELEASE -DCMAKE_EXPORT_COMPILE_COMMANDS=1
make

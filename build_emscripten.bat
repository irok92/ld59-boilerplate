call 3rdparty\emsdk\emsdk_env.bat

call emcmake cmake -S . -B .build_emscripten -DCMAKE_BUILD_TYPE=Release

call cmake --build .build_emscripten --config Debug

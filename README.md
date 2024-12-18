build using g++
`powershell
g++ -L"include/libwebp-1.4.0-windows-x64/lib/libwebp.lib" -I"include/libwebp-1.4.0-windows-x64/include" -I"include/stb" src/main.cpp src/cms.cpp src/converter.cpp -o conv.exe
`


WIP cmd

g++ -L"include/libwebp-1.4.0-windows-x64/lib/libwebp.lib" -I"include/libwebp-1.4.0-windows-x64/include" -I"include/stb" src/main.cpp src/converter.cpp -o conv.exe
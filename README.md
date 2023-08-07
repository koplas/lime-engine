# WIP Vulkan Engine
## Building
Note: Only tested with clang 18 and cmake 3.26

The Vulkan SDK has to be installed and Vulkan 1.3 or higher needs to be supported.

On Linux execute:

```
cmake -G Ninja -B build -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang
cmake --build build/
```

The engine should now be runnable with
```
./build/lime-engine
```
## Third party used
- [glm](https://github.com/g-truc/glm)
- [glfw](https://www.glfw.org/)
- [VMA](https://gpuopen.com/vulkan-memory-allocator/)
- [EnTT](https://github.com/skypjack/entt)
- [tinygltf](https://github.com/syoyo/tinygltf)
- [nhlohmann-json](https://github.com/nlohmann/json)
- [stb](http://nothings.org/stb)

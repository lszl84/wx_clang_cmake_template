# wx_clang_cmake_template

## Building

```
cmake --preset default
cmake --build --preset default
```

On Windows this links libc++ and libunwind statically — the resulting executable does not require any DLLs.

## VSCode / VSCodium

Your mingw-clang installation should be in PATH. 

Recommended plugins:
- CMake (from Microsoft) - automatic preset detection, required by `launch.json`
- lldb-dap (from LLVM) - for debugging with lldb,
- clangd (from LLVM) - for code navigation.


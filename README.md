# wx_clang_cmake_template

## Building on Windows

This links libstc++ and libundwind statically - the resulting executable does not require any DLLs.

```
cmake --preset windows-static
cmake --build --preset build-windows
```

## VSCode template

Your mingw-clang installation should be in PATH. 

Recommended plugins:
- CMake (from Microsoft) - automatic preset detection, required by `launch.json`
- lldb-dap (from LLVM) - for debugging with lldb,
- clangd (from LLVM) - for code navigation.


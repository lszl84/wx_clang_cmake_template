# wx_clang_cmake_template

## Building on Windows

This links libstc++ and libundwind statically - the resulting executable does not require any DLLs.

```
cmake --preset windows-static
cmake --build --preset build-windows
```

## VSCode template

Requires lldb-dap for debugging. Your mingw-lldb installation should be in PATH.

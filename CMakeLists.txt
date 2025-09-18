cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(wx_clang_cmake_template LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# wxWidgets configuration
set(wxWidgets_REQUIRED_VERSION "3.2.8")
set(wxWidgets_REQUIRED_COMPONENTS core base)

find_package(wxWidgets ${wxWidgets_REQUIRED_VERSION} QUIET COMPONENTS ${wxWidgets_REQUIRED_COMPONENTS})

if(wxWidgets_FOUND)
    message(STATUS "Found pre-installed wxWidgets")
    include(${wxWidgets_USE_FILE})
    message(STATUS "-- libraries: ${wxWidgets_LIBRARIES}")
else()
    message(STATUS "wxWidgets ${wxWidgets_REQUIRED_VERSION}+ not found, fetching from GitHub...")

    include(FetchContent)
    set(wxBUILD_SHARED OFF)

    FetchContent_Declare(
        wxWidgets
        GIT_REPOSITORY https://github.com/wxWidgets/wxWidgets.git
        GIT_TAG v${wxWidgets_REQUIRED_VERSION}
    )
    FetchContent_MakeAvailable(wxWidgets)

    foreach(component ${wxWidgets_REQUIRED_COMPONENTS})
        list(APPEND wxWidgets_LIBRARIES wx${component})
    endforeach()
endif()

set(SRCS src/main.cpp)


if(APPLE)
    # create bundle on apple compiles
    add_executable(main MACOSX_BUNDLE ${SRCS})

    # Set a custom plist file for the app bundle - needed for Mac OS Retina display
    set_target_properties(main PROPERTIES MACOSX_BUNDLE_INFO_PLIST ${CMAKE_CURRENT_SOURCE_DIR}/Info.plist)
elseif(WIN32)
    # the WIN32 is needed for Windows in order for it to look for WinMain
    # instead of the main function.
    add_executable(main WIN32 ${SRCS} src/main.exe.manifest src/resources.rc)
else()
    add_executable(main ${SRCS})
endif()


target_link_libraries(main PRIVATE ${wxWidgets_LIBRARIES})

# Project setup
cmake_minimum_required(VERSION 3.15)
project(ServeEngine)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)                   # Enable FetchContent for dependencies

# Get xlnt library (Excel handling)
FetchContent_Declare(
  xlnt
  GIT_REPOSITORY https://github.com/tfussell/xlnt.git
  GIT_TAG master
)
FetchContent_MakeAvailable(xlnt)

# Get tabulate library (table formatting)
FetchContent_Declare(
  tabulate
  GIT_REPOSITORY https://github.com/p-ranav/tabulate.git
  GIT_TAG master
)
FetchContent_MakeAvailable(tabulate)

# Add executable
add_executable(ServeEngine main.cpp src/models/admin.cpp src/models/menu.cpp src/models/staff.cpp src/models/staffAccount.cpp src/models/staffManagement.cpp src/models/excelUtils.cpp src/models/menuInfo.cpp src/models/menuManagement.cpp src/models/orderInfo.cpp src/ui/homepage.cpp )

# Include directories (for header files)
include_directories(include)
# or (modern way)
target_include_directories(ServeEngine PRIVATE include)

# Link libraries
target_link_libraries(ServeEngine PRIVATE xlnt tabulate)

# Disable warnings for dependencies
if (MSVC)
    add_compile_options(/wd4100)   # ignore unreferenced formal parameter
endif()


# Copy xlnt.dll after build (Windows)
add_custom_command(TARGET ServeEngine POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_SOURCE_DIR}/build/_deps/xlnt-build/source/Release/xlnt.dll"
    $<TARGET_FILE_DIR:ServeEngine>)
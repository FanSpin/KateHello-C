cmake_minimum_required(VERSION 3.14)
project(ClockGUI LANGUAGES C)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)   # ← this line

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED IMPORTED_TARGET gtk4)

add_executable(clock_gui clock_gui.c)
target_link_libraries(clock_gui PRIVATE PkgConfig::GTK4)

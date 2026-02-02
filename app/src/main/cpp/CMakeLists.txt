# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

cmake_minimum_required(VERSION 3.22.1)
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)

# project name from gradle.properties
project("${APP_LIB_NAME}")

# raylib and raymod directories
add_subdirectory(${CMAKE_SOURCE_DIR}/deps/raylib)
add_subdirectory(${CMAKE_SOURCE_DIR}/deps/raymob)

# add source files
list(APPEND SOURCES
	    ${CMAKE_SOURCE_DIR}/main.c
)

include_directories(${ANDROID_NDK}/sources/android/native_app_glue/)
list(APPEND SOURCES ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c)

# Create a shared library with game source files
add_library(${APP_LIB_NAME} SHARED ${SOURCES})

# Define compiler macros for the library
target_compile_definitions(${APP_LIB_NAME} PRIVATE PLATFORM_ANDROID)

# Apply flags depending on the build type
if(CMAKE_BUILD_TYPE MATCHES "Debug")
    target_compile_definitions(${APP_LIB_NAME} PRIVATE _DEBUG DEBUG)
endif()

# header files
target_include_directories(${APP_LIB_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/deps/raylib")
target_include_directories(${APP_LIB_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/deps/raymob")
target_include_directories(${APP_LIB_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/deps/raygui/src")

# Link required libraries to the native application
target_link_libraries(${APP_LIB_NAME} raylib raymoblib)

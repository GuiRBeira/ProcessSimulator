cmake_minimum_required(VERSION 3.7.0)

project(Application)

# Set project version
set (VERSION_MAJOR 0)
set (VERSION_MINOR 1)
set (VERSION_PATCH 0)

# Set compiler flags
set (CMAKE_C_FLAGS "-D_GNU_SOURCE -Wall -std=c99")  # Corrected definition of GNU_SOURCE
set (CMAKE_EXE_LINKER_FLAGS "-rdynamic")
# Set output directories
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)  # Corrected variable syntax
set (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)  # Corrected variable name

# Set build type
set (CMAKE_BUILD_TYPE Debug)

# Find package PkgConfig
find_package(PkgConfig)
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
# Check if PkgConfig is found
if(PKG_CONFIG_FOUND)
    pkg_check_modules(GTK REQUIRED gtk+-3.0)  # Use REQUIRED to fail if GTK is not found
    if(GTK_FOUND)
        # Add executable and specify source files
        add_executable(application ${CMAKE_CURRENT_LIST_DIR}/src/main.c
                           ${CMAKE_CURRENT_LIST_DIR}/src/file_reader.c
                           ${CMAKE_CURRENT_LIST_DIR}/src/tree_view.c
                           ${CMAKE_CURRENT_LIST_DIR}/src/widgets.c
                           ${CMAKE_CURRENT_LIST_DIR}/src/functions.c)


        # Link GTK libraries to the executable
        target_link_libraries(application PUBLIC ${GTK_LIBRARIES})  # Corrected variable name

        # Add GTK definitions to compiler flags
        target_compile_options(application PUBLIC ${GTK_CFLAGS} ${GTK_CFLAGS_OTHER})  # Corrected variable name
    endif()
endif()

add_custom_command(TARGET application POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_SOURCE_DIR}/glade ${CMAKE_BINARY_DIR}/bin/glade)
cmake_minimum_required(VERSION 3.26)

include(cmake/modules.cmake)
include(GitVersion)

project(uri
    VERSION ${GIT_VERSION_ABBREV}
    DESCRIPTION "C++ wrapper for the uriparser C library"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS NO)

include(packages.cmake)

add_library(uri "")
add_library(uri::uri ALIAS uri)

target_sources(uri PUBLIC FILE_SET HEADERS BASE_DIRS include)
target_link_libraries(uri
    PRIVATE
        ext::ext
    PUBLIC
        uriparser
)

add_subdirectory(include)
add_subdirectory(src)

include(Sanitizers)
enable_asan()

include(EasyInstall)
easy_install(TARGETS uri DEPENDENCIES uriparser)

if(PROJECT_IS_TOP_LEVEL)
    add_custom_target(docker
        docker build --progress=plain --no-cache .
        WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
        USES_TERMINAL
    )
endif()

include(FetchContent)

cmake_policy(PUSH)
cmake_policy(SET CMP0150 NEW)

FetchContent_Declare(ext
    GIT_REPOSITORY ../libext.git
    GIT_TAG        76265c1325028676ae3219505bb362a0b28ad1ea # 0.3.0
)

set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)

if(NOT DEFINED BUILD_SHARED_LIBS)
    set(BUILD_SHARED_LIBS OFF)
endif()

set(URIPARSER_BUILD_DOCS OFF)
set(URIPARSER_BUILD_TESTS OFF)
set(URIPARSER_BUILD_TOOLS OFF)

FetchContent_Declare(uriparser
    GIT_REPOSITORY https://github.com/uriparser/uriparser.git
    GIT_TAG        634b678fa858abf1d1ebc0634e96e9e29596e92a # 0.9.7
)

FetchContent_MakeAvailable(ext uriparser)

cmake_policy(POP)

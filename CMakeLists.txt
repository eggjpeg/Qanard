cmake_minimum_required(VERSION 3.11)
project(abeille CXX)

# Get FetchContent for downloading dependencies
include(FetchContent)

#===============================================================================
# Get XTL
message(STATUS "Downloading xtl v0.7.7")
FetchContent_Declare(xtl
  GIT_REPOSITORY https://github.com/xtensor-stack/xtl.git
  GIT_TAG        0.7.7
)
FetchContent_MakeAvailable(xtl)

#===============================================================================
# Get XSIMD
message(STATUS "Downloading xsimd v12.1.1")
FetchContent_Declare(xsimd
  GIT_REPOSITORY https://github.com/xtensor-stack/xsimd.git
  GIT_TAG        12.1.1
)
FetchContent_MakeAvailable(xsimd)

#===============================================================================
# Get XTENSOR
message(STATUS "Downloading xtensor v0.24.7")
FetchContent_Declare(xtensor
  GIT_REPOSITORY https://github.com/xtensor-stack/xtensor.git
  GIT_TAG        0.24.7
)
FetchContent_MakeAvailable(xtensor)

#===============================================================================
# Get XTENSOR-BLAS
message(STATUS "Downloading xtensor-blas v0.20.0")
FetchContent_Declare(xtensor-blas
  GIT_REPOSITORY https://github.com/xtensor-stack/xtensor-blas.git
  GIT_TAG        0.20.0
)
FetchContent_MakeAvailable(xtensor-blas)


#===============================================================================

# Get the Git hash for define
execute_process(COMMAND git describe --dirty --always
                WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
                OUTPUT_VARIABLE ABEILLE_GIT_HASH_RAW
                OUTPUT_STRIP_TRAILING_WHITESPACE
               )

add_executable(qanard src/main.cpp)
target_include_directories(qanard PRIVATE include)
target_compile_features(qanard PRIVATE cxx_std_17)
target_link_libraries(qanard PUBLIC xtl xsimd xtensor xtensor-blas)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC") # Compile options for Windows
  target_compile_options(qanard PRIVATE /W3)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GNU") # Compile options for GCC
  target_compile_options(qanard PRIVATE -W -Wall -Wextra -Wconversion -Wpedantic)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang") # Compile options for Clang
  target_compile_options(qanard PRIVATE -W -Wall -Wextra -Wconversion -Wpedantic)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Intel") # Compile options for Intel
  target_compile_options(qanard PRIVATE -W -Wall -Wextra -Wconversion -Wpedantic)
endif()

#===============================================================================
# Allow for install of executable
install(TARGETS qanard
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

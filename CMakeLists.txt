cmake_minimum_required(VERSION 3.16)

project(test_vulkan_hpp_my)

# globally add VKB_DEBUG for the debug build
add_compile_definitions($<$<CONFIG:DEBUG>:VKB_DEBUG>)

# Add path for local cmake scripts
list(APPEND CMAKE_MODULE_PATH
    ${CMAKE_CURRENT_SOURCE_DIR}/bldsys/cmake
    ${CMAKE_CURRENT_SOURCE_DIR}/bldsys/cmake/module)

include(sample_helper)
include(component_helper)

# Add third party libraries
add_subdirectory(third_party)

vkb__enable_testing()

# Framework v2.0 components directory
add_subdirectory(components)

# Add vulkan framework
add_subdirectory(framework)

if(VKB_BUILD_TESTS)
    # Add vulkan tests
    add_subdirectory(tests)
endif()

add_subdirectory(hpp_hello_triangle)

add_subdirectory(src)

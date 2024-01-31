# create sample app project
project(test_vulkan_hpp_my LANGUAGES C CXX)

add_subdirectory(plugins)
add_subdirectory(apps)

set(SRC
    main.cpp
)

add_executable(${CMAKE_PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} PRIVATE vkb__core apps plugins hpp_hello_triangle)

target_include_directories(${PROJECT_NAME} PRIVATE
    ../hpp_hello_triangle
)

# create sample app project
project(test_vulkan_hpp_my LANGUAGES C CXX)

add_subdirectory(plugins)
add_subdirectory(apps)

set(SRC
    main.cpp
)

source_group("\\" FILES ${SRC})

add_executable(${PROJECT_NAME} WIN32 ${SRC})

target_link_libraries(${PROJECT_NAME} PRIVATE vkb__core apps plugins)

#include <core/platform/entrypoint.hpp>

#include "hello_triangle.h"
#include "hpp_texture_loading.h"
#include "platform/unix/unix_platform.h"
#include "platform/glfw_window.h"
#include "hpp_hello_triangle.h"
#include <memory.h>

extern std::unique_ptr<vkb::PlatformContext> create_platform_context(int argc, char **argv);

int main(int argc, char *argv[])
{
    auto context = create_platform_context(argc, argv);
    vkb::UnixPlatform platform{*context, vkb::UnixType::Linux};
    auto window = std::make_unique<vkb::GlfwWindow>(&platform, vkb::Window::Properties());
    std::unique_ptr<vkb::Application> active_app = std::make_unique<HelloTriangle>();
    active_app->prepare({false, window.get()});

    vkb::Timer timer;

    while (!window->should_close())
    {
        try
        {
            auto delta_time = static_cast<float>(timer.tick<vkb::Timer::Seconds>());
            active_app->update(delta_time);

            if (active_app && active_app->should_close())
            {
                std::string id = active_app->get_name();
                active_app->finish();
            }

            window->process_events();
        }
        catch (std::exception &e)
        {
            LOGE("Error Message: {}", e.what());
        }
    }

    return 0;
}

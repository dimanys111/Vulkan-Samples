#include "core/platform/context.hpp"
#include "hpp_hello_triangle.h"
#include "platform/application.h"
#include "platform/glfw_window.h"
#include "platform/unix/unix_platform.h"

using namespace vkb;

extern std::unique_ptr<PlatformContext> create_platform_context(int argc, char** argv);

int main(int argc, char* argv[])
{
    Application* application = new HPPHelloTriangle();
    Window::Properties properties;
    auto context = create_platform_context(argc, argv);
    UnixPlatform platform { *context.get(), UnixType::Linux };
    auto window = std::make_unique<GlfwWindow>(&platform, properties);
    application->prepare({ false, window.get() });

    return 0;
}

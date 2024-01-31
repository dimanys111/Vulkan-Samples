#include "platform/platform.h"
#include "plugins/plugins.h"

#include <core/platform/entrypoint.hpp>

#include "platform/unix/unix_platform.h"

extern std::unique_ptr<vkb::PlatformContext> create_platform_context(int argc, char** argv);

int main(int argc, char* argv[])
{
    auto context = create_platform_context(argc, argv);
    vkb::UnixPlatform platform { *context, vkb::UnixType::Linux };
    auto code = platform.initialize(plugins::get_all());

    if (code == vkb::ExitCode::Success) {
        code = platform.main_loop();
    }

    platform.terminate(code);

    return 0;
}

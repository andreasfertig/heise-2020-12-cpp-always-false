// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


#include <cstddef>
#include <cstdio>
#include <type_traits>

[[maybe_unused]] static void linux_api_call()
{
    printf("linux\n");
}

extern void mac_api_call();

extern void windows_api_call();

template<class...>
inline constexpr bool always_false_v = false;

enum class OS
{
    Linux,
    Mac,
    Windows,
    native = Linux
};

#ifdef WILL_NOT_COMPILE
template<typename T>
void Init()
{
    if constexpr(OS::native == OS::Linux) {
        // Linux specific code
        linux_api_call();

    } else if constexpr(OS::native == OS::Mac) {
        // OS X specific code
        mac_api_call();

    } else if constexpr(OS::native == OS::Windows) {
        // Windows specific code
        windows_api_call();

    } else {
        static_assert(false, "Unknown OS");
    }
}

#endif

int main() {}
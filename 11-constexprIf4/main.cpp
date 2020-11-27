// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


#include <cstddef>
#include <cstdio>

template<auto...>
inline constexpr bool always_false_n_v = false;

template<size_t PHASE>
void Init()
{
    if constexpr(0 == PHASE) {
        // ...

    } else {
        static_assert(always_false_n_v<PHASE>, "Unsupported phase");
    }
}

int main()
{
    Init<0>();
}
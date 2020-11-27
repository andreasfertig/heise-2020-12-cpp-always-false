// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


#include <cstddef>

template<typename... T>
constexpr bool always_false()
{
    return false;
}

static_assert(not always_false<int>(), "always_false negated");

int main() {}
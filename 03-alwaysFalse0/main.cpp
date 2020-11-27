// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


#include <cstddef>

template<typename... T>
struct always_false
{
    static constexpr bool value = false;
};

static_assert(not always_false<int>::value, "always_false negated");

int main() {}
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

template<typename... T>
constexpr bool always_false_v = always_false<T...>::value;

static_assert(not always_false_v<int>, "always_false negated");

int main() {}
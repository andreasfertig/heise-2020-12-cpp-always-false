// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


#include <cstddef>

template<typename... T>
constexpr bool always_false_v = false;

class Cat
{
};

class Dog
{
};

template<typename T>
struct Hash
{
    static_assert(always_false_v<T>,
                  "You need to provide a specialization for your type T");
};

template<>
struct Hash<Cat>
{
    static size_t get() { return 1; }
};

template<>
struct Hash<Dog>
{
    static size_t get() { return 2; }
};

int main()
{
    Cat cat{};

    return Hash<Cat>::get();
}
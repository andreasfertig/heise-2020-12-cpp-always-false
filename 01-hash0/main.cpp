// Copyright (c) Andreas Fertig.
// SPDX-License-Identifier: MIT



#if defined (_MSC_VER)
#  define not !
#endif /* MSVC */


#include <cstddef>

class Cat
{
};

class Dog
{
};

template<typename T>
struct Hash;

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
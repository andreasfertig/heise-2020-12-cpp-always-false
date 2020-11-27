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

#ifdef WILL_NOT_COMPILE
template<typename T>
struct Hash
{
    static_assert(false,
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
#endif

int main() {}
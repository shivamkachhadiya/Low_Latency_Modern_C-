#include <iostream>

/*
    Goal:
    - Understand lifetime
    - Avoid dangling references
*/

// ❌ NEVER do this
const int &bad()
{
    int x = 10;
    return x; // dangling reference
}

// ✅ Safe: return by value
int good_value()
{
    int x = 20;
    return x; // NRVO, no copy
}

// ✅ Safe: static lifetime
const int &good_static()
{
    static int x = 30;
    x++;
    return x;
}

int main()
{
    std::cout << good_value() << '\n';
    std::cout << good_static() << '\n';

    return 0;
}

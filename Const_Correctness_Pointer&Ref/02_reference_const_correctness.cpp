#include <iostream>

/*
    Goal:
    - Understand const references
    - Enforce read-only access
*/

void print_value(const int &x)
{
    
    // x = 10; // ❌ compile-time protection
    std::cout << x << '\n';
}

int main()
{
    int value = 100;

    const int &ref = value; // read-only alias
    value = 200;
    value = 9;

    print_value(ref); // prints 200

    return 0;
}

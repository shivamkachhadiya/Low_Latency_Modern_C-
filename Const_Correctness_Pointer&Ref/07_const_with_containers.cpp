#include <vector>
#include <iostream>

/*
    Goal:
    - Const iteration
    - Prevent accidental mutation
*/

int main()
{
    std::vector<int> prices{100, 101, 102};

    for (const auto &p : prices)
    {
        // p++; // ❌ protected
        std::cout << p << '\n';
    }

    return 0;
}

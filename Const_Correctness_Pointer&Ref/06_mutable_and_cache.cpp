#include <iostream>

/*
    Goal:
    - Learn mutable
    - Logical constness
*/

class Cache
{
    mutable int hits{0};

public:
    int get() const
    {
        ++hits; // allowed
        return 42;
    }

    int get_hits() const
    {
        return hits;
    }
};

int main()
{
    const Cache c;
    c.get();
    c.get();

    std::cout << c.get_hits() << '\n'; // 2
    return 0;
}

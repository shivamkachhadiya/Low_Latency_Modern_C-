#include <iostream>
#include <string>

/*
    Goal:
    - Avoid copies
    - Express intent
*/

struct Order
{
    int id;
    std::string symbol;
};

// ❌ Bad: copy + mutable
void process_bad(Order o)
{
    o.id = 999;
}

// ✅ Good: no copy + no mutation
void process_good(const Order &o)
{
    std::cout << o.id << " " << o.symbol << '\n';
}

int main()
{
    Order ord{1, "AAPL"};

    process_good(ord);
    // process_bad(ord); // avoid in HFT

    return 0;
}

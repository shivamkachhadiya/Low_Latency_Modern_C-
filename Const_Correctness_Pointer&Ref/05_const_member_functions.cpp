#include <iostream>

/*
    Goal:
    - Understand const member functions
    - Enable const objects
*/

class OrderBook
{
    int best_bid{100};

public:
    int get_best_bid() const
    {
        // best_bid++; // ❌ not allowed
        return best_bid;
    }

    void update_bid(int bid)
    {
        best_bid = bid;
    }
};

int main()
{
    const OrderBook book;
    std::cout << book.get_best_bid() << '\n';

    // book.update_bid(200); // ❌ const object
    return 0;
}

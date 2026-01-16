#include <iostream>
#include <memory>  // unique_ptr, make_unique
#include <utility> // move
using namespace std;
// A simple resource class
class Order
{
    int qty;

public:
    // Constructor
    Order(int q) : qty(q)
    {
        cout << "Order constructed, qty = " << qty << "\n";
    }

    // Destructor
    ~Order()
    {
        cout << "Order destroyed, qty = " << qty << "\n";
    }

    void print() const
    {
        cout << "Qty = " << qty << "\n";
    }
};

// Function that TAKES ownership
void takeOwnership(unique_ptr<Order> o)
{
    cout << "Inside takeOwnership()\n";
    o->print();
    // o will be destroyed automatically when function ends
}

// Function that only OBSERVES (no ownership)
void observe(const unique_ptr<Order> &o)
{
    cout << "Inside observe()\n";
    o->print();
}

int main()
{
    cout << "---- Create unique_ptr ----\n";

    // Best practice: make_unique
    auto p1 = make_unique<Order>(100);

    cout << "\n---- Observe (no ownership transfer) ----\n";
    observe(p1);

    cout << "\n---- Transfer ownership using move ----\n";
    auto p2 = move(p1);

    if (!p1)
    {
        cout << "p1 is now null after move\n";
    }

    cout << "\n---- Use new owner ----\n";
    p2->print();

    cout << "\n---- Pass ownership to function ----\n";
    takeOwnership(move(p2));

    if (!p2)
    {
        cout << "p2 is now null after ownership transfer\n";
    }

    cout << "\n---- End of main ----\n";
    return 0;
}

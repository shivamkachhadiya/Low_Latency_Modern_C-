#include <iostream>
#include <memory>
using namespace std;
class Order
{
public:
    Order(int q) : qty(q)
    {
        cout << "Order constructed\n";
    }
    ~Order()
    {
        cout << "Order destroyed\n";
    }
    void print() const
    {
        cout << "Qty = " << qty << "\n";
    }

private:
    int qty;
};

int main()
{
    auto p1 = make_shared<Order>(100);
    auto p2 = p1; // shared ownership
    auto p3 = p2;

    p1->print();

    p2.reset(); // release one owner

    p3->print(); // still alive

    return 0; // last owner dies → destructor runs
}

#include <iostream>
#include <vector>
using namespace std;
class Order
{
    int *qty;

public:
    Order(int q)
    {
        qty = new int(q);
        std::cout << "Constructor is called values assign is" << *qty << endl;
    }

    ~Order()
    {
        delete qty;
        std::cout << "Destructor\n";
    }

    // Copy assign
    Order &operator=(const Order &other)
    {
        if (this != &other)
        {
            cout << "deleting qty..." << *qty << endl;
            delete qty;
            cout << "* other qty in :" << *other.qty << endl;
            qty = new int(*other.qty);
            cout << "qty is now..." << *qty << endl;
        }
        std::cout << "Copy Assignment\n";
        cout << "* this is: " << this;
        return *this;
    }
    void print()
    {
        cout << *qty << endl;
    }
};
int main()
{
    Order o1(10);
    Order o2(20);

    o2 = o1; // COPY ASSIGNMENT OPERATOR
    o1.print();
    o2.print();
    return 0;
}
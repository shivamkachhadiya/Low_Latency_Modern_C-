#include <iostream>
#include <utility> // for std::move
using namespace std;

// HFT-style Order class demonstrating Rule of 5
class Order
{
    int *qty; // Pointer to quantity (dynamic memory)

public:
    // Constructor
    Order(int q)
    {
        qty = new int(q); // Allocate memory for quantity
        cout << "Constructor called: qty = " << *qty << endl;
    }
    // Destructor
    ~Order()
    {
        delete qty; // Free allocated memory
        cout << "Destructor called" << endl;
    }

    // Copy Constructor
    Order(const Order &other)
    {
        qty = new int(*other.qty); // Allocate new memory and copy value
        cout << "Copy Constructor called: qty = " << *qty << endl;
    }

    // Copy Assignment Operator
    Order &operator=(const Order &other)
    {
        if (this != &other)
        {                              // Avoid self-assignment
            delete qty;                // Delete old memory
            qty = new int(*other.qty); // Allocate new memory and copy
        }
        cout << "Copy Assignment called: qty = " << *qty << endl;
        return *this;
    }

    // Move Constructor
    Order(Order &&other) noexcept
    {
        qty = other.qty;     // Take ownership of memory
        other.qty = nullptr; // Nullify source to prevent double free
        cout << "Move Constructor called" << endl;
    }

    // Move Assignment Operator
    Order &operator=(Order &&other) noexcept
    {
        if (this != &other)
        {                        // Avoid self-assignment
            delete qty;          // Delete old memory
            qty = other.qty;     // Take ownership
            other.qty = nullptr; // Nullify source
        }
        cout << "Move Assignment called" << endl;
        return *this;
    }

    // Utility: Print quantity
    void print() const
    {
        if (qty)
            cout << "Order qty = " << *qty << endl;
        else
            cout << "Order qty = nullptr" << endl;
    }
};

int main()
{
    cout << "=== Constructor Test ===" << endl;
    Order o1(100); // Calls constructor
    o1.print();

    cout << "\n=== Copy Constructor Test ===" << endl;
    Order o2 = o1; // Calls copy constructor
    o2.print();

    cout << "\n=== Copy Assignment Test ===" << endl;
    Order o3(50);
    o3 = o1; // Calls copy assignment
    o3.print();

    cout << "\n=== Move Constructor Test ===" << endl;
    Order o4 = std::move(o1); // Calls move constructor
    o4.print();
    o1.print(); // o1's qty should be nullptr

    cout << "\n=== Move Assignment Test ===" << endl;
    Order o5(200);
    o5 = std::move(o2); // Calls move assignment
    o5.print();
    o2.print(); // o2's qty should be nullptr

    cout << "\n=== End of Program ===" << endl;
    return 0;
}

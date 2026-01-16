#include <iostream>
#include <type_traits>
using namespace std;
/*
    TEMPLATE:
    ---------
    Template allows writing generic code.
    Compiler generates type-specific code at compile time.
*/

// ---------------- FUNCTION TEMPLATE ----------------

template <typename T>
T add(T a, T b)
{
    return a + b;
}

// ---------------- CLASS TEMPLATE ----------------

template <typename T>
class Box
{
    T value;

public:
    Box(T v) : value(v) {}

    T get() const
    {
        return value;
    }
};

// ---------------- TEMPLATE SPECIALIZATION ----------------

template <>
class Box<const char *>
{
public:
    Box(const char *s)
    {
        cout << "Specialized Box for const char*\n";
    }
};

// ---------------- if constexpr (COMPILE-TIME BRANCH) ----------------

template <typename T>
void process(T value)
{
    if constexpr (is_integral_v<T>)
    {
        cout << "Integral type: " << value << "\n";
    }
    else
    {
        cout << "Non-integral type\n";
    }
}

int main()
{

    cout << "==== FUNCTION TEMPLATE ====\n";

    cout << add<int>(3, 4) << "\n";
    cout << add<double>(2.5, 3.5) << "\n";

    // Compiler generates:
    // int add(int,int)
    // double add(double,double)

    // ------------------------------------------------------------

    cout << "\n==== CLASS TEMPLATE ====\n";

    Box<int> b1(10);
    Box<double> b2(3.14);

    cout << b1.get() << "\n";
    cout << b2.get() << "\n";

    // ------------------------------------------------------------

    cout << "\n==== TEMPLATE SPECIALIZATION ====\n";

    Box<const char *> b3("hello");

    // ------------------------------------------------------------

    cout << "\n==== IF CONSTEXPR ====\n";

    process(10);   // integral
    process(3.14); // non-integral

    /*
        PERFORMANCE NOTES (INTERVIEW):
        ------------------------------
        - Templates are resolved at compile time
        - No virtual table
        - No runtime dispatch
        - Zero runtime overhead
        - Preferred in HFT systems
    */

    return 0;
}

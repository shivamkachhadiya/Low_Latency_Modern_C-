#include <iostream>
#include <vector>
#include <algorithm>

/*
    LAMBDA FUNCTION:
    ----------------
    A lambda is an anonymous function object created by the compiler.
    It can capture variables from its surrounding scope.
*/

int main()
{

    std::cout << "==== BASIC LAMBDA ====\n";

    // Lambda with no capture
    // []      -> capture list (empty)
    // (int a) -> parameters
    // { }     -> function body
    auto square = [](int a)
    {
        return a * a;
    };

    std::cout << "Square of 5 = " << square(5) << "\n";

    // ------------------------------------------------------------

    std::cout << "\n==== LAMBDA WITH CAPTURE BY VALUE ====\n";

    int x = 10;

    // Capture x by value (copy)
    auto byValue = [x]()
    {
        // x here is a COPY
        return x + 5;
    };

    std::cout << "Captured by value result = " << byValue() << "\n";
    std::cout << "Original x still = " << x << "\n";

    // ------------------------------------------------------------

    std::cout << "\n==== LAMBDA WITH CAPTURE BY REFERENCE ====\n";

    // Capture x by reference
    auto byRef = [&x]()
    {
        x = x + 5; // modifies original x
    };

    byRef();
    std::cout << "x after reference capture = " << x << "\n";

    // ------------------------------------------------------------

    std::cout << "\n==== MUTABLE LAMBDA ====\n";

    int y = 20;

    // By default, value captures are const
    // mutable allows modification of copied value
    auto mutableLambda = [y]() mutable
    {
        y += 10; // modifies local copy
        return y;
    };

    std::cout << "Mutable lambda result = " << mutableLambda() << "\n";
    std::cout << "Original y still = " << y << "\n";

    // ------------------------------------------------------------

    std::cout << "\n==== LAMBDA WITH STL (REAL USE) ====\n";

    std::vector<int> v{1, 2, 3, 4, 5};

    // Lambda passed to algorithm
    std::for_each(v.begin(), v.end(),
                  [](int n)
                  {
                      std::cout << n << " ";
                  });

    std::cout << "\n";

    /*
        PERFORMANCE NOTES (INTERVIEW):
        - Lambda is a compiler-generated functor
        - Usually inlined
        - No heap allocation
        - Faster than function pointers
        - Faster than std::function
    */

    return 0;
}

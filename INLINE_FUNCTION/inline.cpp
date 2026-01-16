#include <iostream>

/*
    INLINE FUNCTION:
    ----------------
    Inline is a request to the compiler to replace
    a function call with the function body.
*/

// Inline function
inline int add(int a, int b)
{
    return a + b;
}

// Large functions usually NOT inlined
inline int largeFunction(int x)
{
    int sum = 0;
    for (int i = 0; i < x; i++)
    {
        sum += i;
    }
    return sum;
}

int main()
{

    std::cout << "==== INLINE FUNCTION DEMO ====\n";

    int a = 10, b = 20;

    // Function call MAY be replaced by "a + b"
    int result = add(a, b);

    std::cout << "Add result = " << result << "\n";

    std::cout << "\n==== INLINE LIMITATION ====\n";

    // Compiler may refuse to inline this
    std::cout << "Large function result = " << largeFunction(10) << "\n";

    /*
        IMPORTANT INTERVIEW POINTS:
        ---------------------------
        1. inline is NOT a guarantee
        2. Compiler decides
        3. Inlining removes function call overhead
        4. Too much inline increases code size
        5. May hurt instruction cache (I-cache)
    */

    return 0;
}

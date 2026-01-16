#include <iostream>
using namespace std;
// Goal
// -> understand const with pointers

int main()
{
    int a = 10;
    int b = 20;

    // Pointer to const data (data is read-only)

    const int *p1 = &a;
    //*p1=30;    ERROR data is const
    p1 = &b; // POINTER can change

    // Const pointer to data (pointer is fixed)
    int *const p2 = &a;
    *p2 = 40; // DATA can be change
    // p2=&b;   ERROR pointer is const

    // Const pointer to const data
    const int *const p3 = &a;
    // *p3 = 50;        // ERROR
    // p3 = &b;         // ERROR

    std::cout << a << '\n'; // 40
    return 0;
}
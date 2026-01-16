#include <iostream>
#include <memory>

using namespace std;

int main()
{
    auto ptr = make_unique<int>(100);
    cout << "before lambda ,ptr is=>" << *ptr << endl;

    // move unique ptr in lambda
    auto lambda = [p = move(ptr)]()
    {
        cout << "inside lambda ,value->" << *p << endl;
    };

    if (!ptr)
    {
        cout << "ptr is null after move...!" << endl;
    }

    lambda();

    return 0;
}
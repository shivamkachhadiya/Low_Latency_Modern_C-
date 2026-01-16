#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct Order
{
    int id;
    std::string symbol;

    Order(int i, const std::string &s)
    {
        //s = "bbb";
        id = i;
        symbol = s;
    }
};

int main()
{
    Order *o = new Order(1, "AAPL");

    cout << o->id << " " << o->symbol << endl;
    // return 0;
}

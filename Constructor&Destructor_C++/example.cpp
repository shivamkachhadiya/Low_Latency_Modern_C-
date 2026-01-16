#include <iostream>
#include <string>
class Order
{
    int id;             // plain data
    std::string symbol; // RAII resource (heap inside)
public:
    Order(int i, const std::string &s)
        : id(i), symbol(s)
    {
        std::cout << "Order constructed\n";
    }
    ~Order()
    {
        std::cout << "Order destroyed\n";
    }
};
void trade()
{
    Order o(1, "AAPL");
    std::cout << "Trading...\n";
}
int main()
{
    trade();
    return 0;
}

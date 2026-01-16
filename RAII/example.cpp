#include <iostream>
#include <mutex>
#include <string>

std::mutex globalMutex;

class LockGuard
{
    std::mutex &mtx;

public:
    LockGuard(std::mutex &m) : mtx(m)
    {
        mtx.lock();
        std::cout << "mutex lock..." << std::endl;
    }

    ~LockGuard()
    {
        mtx.unlock();
        std::cout << "mutex unlock..." << std::endl;
    }
};

class order
{
public:
    int id;
    std::string symbol;

    order(int i, const std::string &s) : id(i), symbol(s)
    {
        std::cout << "order constructed..." << std::endl;
    }

    ~order()
    {
        std::cout << "order destroyed..." << std::endl;
    }
};

void processOrder()
{
    LockGuard lg(globalMutex);
    order *o = new order(1, "AIRTEL");
    std::cout << "processing order.. " << o->id << " " << o->symbol << std::endl;
    delete o;
}

int main()
{
    processOrder();
    return 0;
}

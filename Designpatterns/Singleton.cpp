#include<iostream>
using namespace std;

class Singleton {
private:
    Singleton()
    {
        cout << "singleton creation:";
    }

    ~Singleton()
    {
        cout << "destroy";
    }

    static Singleton* instance;
    int count;
public:
    static Singleton& getInstance()
    {
        if(!instance){
            instance = new Singleton();
        }
        return *instance;
    }

    void SomeInfo()
    {
        cout << "Data for fn" << endl;
    }

    void Setcount(int value)
    {
        count = value;
    }

    int getcount() const{
        return count;
    }

    void increment()
    {
        count++;
    }
Singleton(const Singleton&) = delete;
Singleton& operator = (const Singleton&) = delete;
};

Singleton* Singleton::instance = nullptr;

int main()
{
    // Access Singleton
    Singleton& singleton = Singleton::getInstance();

    // Use the new functionality
    singleton.Setcount(10);
    std::cout << "Counter: " << singleton.getcount() << std::endl;

    singleton.increment();
    std::cout << "Counter after increment: " << singleton.getcount() << std::endl;

    singleton.SomeInfo();

    // Another reference to Singleton shows same state
    Singleton& ref2 = Singleton::getInstance();
    std::cout << "Counter from second reference: " << ref2.getcount() << std::endl;

    return 0;
}
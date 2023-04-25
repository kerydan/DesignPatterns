/*
Design Pattern Adapter. 
Adapter provides a compartible interface to an object with incompartible interface
*/
#include <iostream>
#include <memory>

using namespace std;

class Specific
{
public:
    void PrintSpecific() 
    {
        cout << "Specific printing\n";
    }
};

class iAdapter
{
public:
    virtual void Print() = 0;
    
};

class Adapter : public iAdapter, private Specific
{
public:
    void Print()
    {
        PrintSpecific();
    }
    
};

int main()
{
    unique_ptr<iAdapter> p = make_unique<Adapter>();
    p->Print();
}

/*
Design Pattern Adapter. 
Adapter provides a compartible interface to an object with incompartible interface
*/
#include <iostream>
#include <memory>

using namespace std;

// Adaptee (the class that needs adapting)
class Specific
{
public:
    void PrintSpecific() 
    {
        cout << "Specific printing\n";
    }
};

// This is what client expects. Interface
class iAdapter
{
public:
    virtual void Print() = 0;
    
};

class Adapter1 : public iAdapter
{
    Specific* specific;
public:
    Adapter1(Specific* s): specific(s) {}
    void Print()
    {
        specific->PrintSpecific();
    }    
};

class Adapter2 : public iAdapter, private Specific
{
public:
    void Print()
    {
        PrintSpecific();
    }    
};

int main()
{
    Specific s;
    Adapter1 a1(s);
    a1.Print();

    unique_ptr<iAdapter> p = make_unique<Adapter2>();
    p->Print();
}

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

class Adapter1 : public iAdaptor
{
    Specific* specific;
public:
    Adaptor1(Specific* s): specific(s) {}
    void Print()
    {
        specific->PrintSpecific();
    }    
};

class Adaptor2 : public iAdaptor, private Specific
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
    Adaptor1 a1(s);
    a1.Print();

    unique_ptr<iAdaptor> p = make_unique<Adaptor2>();
    p->Print();
}

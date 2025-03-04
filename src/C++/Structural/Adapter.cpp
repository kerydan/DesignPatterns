/*
Design Pattern Adapter. 
Adapter provides a compartible interface to an object with incompartible interface
*/
#include <iostream>
#include <print>

using namespace std;

// We adopt Car to Boat. We want to use car on sea.
// Ultimately client wats to use object Car with method Sail()

// This is what client expects. 
class Boat
{
public:
    virtual void Sail(){println("We sail!!");} 
};

// Adaptee. This car needs to be adopted to Boat
class Car
{
    string name;
    public:
    Car(string str) : name(str) {}
    void Drive(){println("We driving {}", name);} 
};


// Adaptor 
class CarToBoat : public Boat
{
    Car *car;
    public:
    CarToBoat(Car* c) : car(c){};
    virtual void Sail() override
    {
        println("First put the car on boat and then ...");
        car->Drive();
    } 
};

int main()
{
    // Normal boat is used as boat
    Boat *b1 = new Boat();
    b1->Sail();

    // Car is used as boat
    Car car("Toyota");
    Boat *b2 = new CarToBoat(&car);
    b2->Sail();

    return 0;
}

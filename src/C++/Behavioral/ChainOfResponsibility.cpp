#include <iostream>

/**
 * Chain of Responsibility Design Pattern
 *
 * The pattern has the intent to avoid coupling the sender of a request to its receiver
 * by giving more than one object a chance to handle the request. Chains the receiving
 * objects and passes the requests along the chain until an object handles it.
 */


using namespace std;

class Facility
{
protected:
    Facility* next;
public:
    Facility* addNext(Facility* f)
    {
        next = f;
        return next;
    }
    virtual void apply(int age) = 0;
};

class KinderGarden : public Facility
{
    int age1 = 3;
    int age2 = 7;
public:
    void apply(int age)
    {
        if (age >= age1 && age <= age2)
        {
            std::cout << "Enrolled in Kinder Garden \n";
        }
        else if (next)
        {
            next->apply(age);
        }
    }
};

class PrimarySchool : public Facility
{
    int age1 = 8;
    int age2 = 12;
public:
    void apply(int age)
    {
        if (age >= age1 && age <= age2)
        {
            std::cout << "Enrolled in Primary School \n";
        }
        else if (next)
        {
            next->apply(age);
        }
    }
};

class SecondarySchool : public Facility
{
    int age1 = 13;
public:
    void apply(int age)
    {
        if (age >= age1)
        {
            std::cout << "Enrolled in Secondary School \n";
        }
        else if (next)
        {
            next->apply(age);
        }
    }
};


int main()
{
    Facility* educationFacility = new KinderGarden();
    educationFacility->addNext(new PrimarySchool())->addNext(new SecondarySchool());

    educationFacility->apply(15);
    educationFacility->apply(9);
    educationFacility->apply(4);

    return 0;
}

/**
   Output:

    Enrolled in Secondary School
    Enrolled in Primary School
    Enrolled in Kinder Garden
*/

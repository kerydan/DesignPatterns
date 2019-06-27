/**
 * Mediator Design Pattern
 *
 * Communication between objects is encapsulated within a mediator object.
 * Objects no longer communicate directly with each other, but instead communicate through the mediator.
 * This reduces the dependencies between communicating objects, thereby reducing coupling.
 */

#include <iostream>
#include <string>
#include <vector>

class Colleague;
class Runaway;

class Mediator
{
public:
    virtual bool RequestLanging(Colleague *colleague) const = 0;
    virtual void Parked(Colleague *colleague) = 0;
};

class Colleague
{
protected:
        Mediator* mediator;
        std::string name;

public:
        explicit Colleague(std::string n, Mediator *m):mediator(m), name(n)
        {
        }
        std::string GetName() const
        {
            return name;
        }
};

// ConcreteColleagueA
class Flight:public Colleague
{
    Colleague* runaway;

public:
        explicit Flight(std::string name, Mediator* mediator):Colleague(name, mediator)
        {
        }

        void RequestLanding()
        {
            std::cout << GetName() << ": Requesting landing" << std::endl;
            mediator->RequestLanging(this);
        }
        void Landing()
        {
            mediator->Parked(this);
        }
};

// ConcreteColleagueA
class Runaway:public Colleague
{
    bool available = true;
public:
        explicit Runaway(std::string name, Mediator *mediator):Colleague(name, mediator)
        {
        }

        bool IsAvailable()
        {
            return available;
        }

        void SetStatus(bool avail)
        {
            available = avail;
        }
};

// ConcreteMediator
class ATC : public Mediator
{
protected:
        std::vector<Flight*> flights;
        Runaway* runaway;
public:
        void SetFlight(Flight *f)
        {
              flights.push_back(f);
        }

        void SetRunway(Runaway *r)
        {
              runaway = r;
        }
        virtual bool RequestLanging(Colleague *flight) const
        {
            if (runaway->IsAvailable())
            {
                std::cout << "ATC: " << flight->GetName() << " landing granted on " << runaway->GetName() << std::endl;
                runaway->SetStatus(false);
                return true;
            }
            else
            {
                std::cout << "ATC: " << flight->GetName() << " stand by. Landing is not permitted" << std::endl;
                return false;
            }
        }

        virtual void Parked(Colleague *flight)
        {
            std::cout << flight->GetName() << " landed" << std::endl;
            runaway->SetStatus(true);
        }

};

int main()
{
        ATC atc;

        Flight klm079("KLM079", &atc);
        Flight panam192("PanAm192", &atc);
        Runaway runaway01("Runaway1", &atc);

        atc.SetFlight(&klm079);
        atc.SetFlight(&panam192);
        atc.SetRunway(&runaway01);

        klm079.RequestLanding();
        panam192.RequestLanding();
        klm079.Landing();
        panam192.RequestLanding();
        panam192.Landing();

        return 0;
}

/**
   Output:

        KLM079: Requesting landing
        ATC: KLM079 landing granted on Runaway1
        PanAm192: Requesting landing
        ATC: PanAm192 stand by. Landing is not permitted
        KLM079 landed
        PanAm192: Requesting landing
        ATC: PanAm192 landing granted on Runaway1
        PanAm192 landed
*/

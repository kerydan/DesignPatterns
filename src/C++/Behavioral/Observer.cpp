/**
 * Observer Design Pattern
 *
 * An object, called the subject, maintains a list of its dependents, called observers, and notifies them
 * automatically of any state changes, usually by calling one of their methods.
 */

#include <iostream>
#include <vector>

class Observer;

class Subject
{
    std::vector <class Observer*> views;
    int oldPrice;
    int newPrice;

  public:

    void Attach(Observer *obs)
    {
        views.push_back(obs);
    }

    void SetPrice(int price)
    {
        oldPrice = newPrice;
        newPrice = price;
        Notify();
    }

    int GetOldPrice()
    {
        return oldPrice;
    }

    int GetNewPrice()
    {
        return newPrice;
    }

    void Notify();
};

class Observer
{
    Subject *subject;
  public:
    Observer(Subject *subj)
    {
        subject = subj;
        subject->Attach(this);
    }
    virtual void Update() = 0;
  protected:
    Subject *GetSubject()
    {
        return subject;
    }
};

void Subject::Notify()
{
    for (auto& i : views)
    {
        i->Update();
    }
}

class PriceObserver: public Observer
{
  public:
    PriceObserver(Subject *subj): Observer(subj){}
    void Update()
    {
        std::cout << "PriceObserver: The new car price is " << GetSubject()->GetNewPrice() << "$"  << std::endl;
    }
};

class PriceDynamicObserver: public Observer {
  public:
    PriceDynamicObserver(Subject *subj): Observer(subj){}
    void Update()
    {
        int newPrice = GetSubject()->GetNewPrice();
        int oldPrice = GetSubject()->GetOldPrice();
        if (newPrice < oldPrice)
        {
            std::cout << "PriceDynamicObserver: The price dropped by " << oldPrice - newPrice << "$" << std::endl;
        }
        else
        {
            std::cout << "PriceDynamicObserver: The price increased by " << oldPrice - newPrice << "$" << std::endl;
        }
    }
};

int main() {
  Subject car;
  car.SetPrice(35000);
  PriceObserver priceObserver(&car);
  PriceDynamicObserver priceDynamicObserver(&car);
  car.SetPrice(32000);
}

/**
  Output:

    PriceObserver: The new car price is 32000$
    PriceDynamicObserver: The price dropped by 3000$
*/

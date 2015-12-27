#include <iostream>

class TravelStrategy{
public:
    virtual void Action() = 0;
};

class BudgetStrategy:public TravelStrategy{
public:
    virtual void Action(){ std::cout << "Take backpack and go camping" << std::endl; }
};

class ExpensiveStrategy :public TravelStrategy{
public:
    virtual void Action(){ std::cout << "Book 5 stars hotel and flight to the Maldivas" << std::endl; }
};


class TravelPreparations{
public:
    void SetStrategy(TravelStrategy* pStrategy){ strategy = pStrategy; }
    void MakePreparations(){
        if (strategy){
            strategy->Action();
        }
    }
private:
    TravelStrategy* strategy = nullptr;
};

int main()
{
    TravelPreparations travel;
    BudgetStrategy budgetStrategy;
    ExpensiveStrategy expensiveStrategy;
    travel.SetStrategy(&budgetStrategy);
    travel.MakePreparations();
    travel.SetStrategy(&expensiveStrategy);
    travel.MakePreparations();

    return 0;
}
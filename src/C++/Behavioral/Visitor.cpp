#include <iostream>
#include <vector>

// Pattern Visitor

class Street;
class Building;

class Visitor
{
public:
    virtual void visit(Street &) = 0;
    virtual void visit(Building &) = 0;
};

class Element
{
  public:
    virtual void accept(Visitor& v) = 0;
};

class Street : public Element
{
public:
    void accept(Visitor& v)
    {
        v.visit(*this);
    };
    void hurry(){std::cout << " hurry";}
    void walk(){std::cout << " walk";}
};

class Building : public Element
{
public:
    void accept(Visitor& v)
    {
        v.visit(*this);
    };
    void work(){std::cout << " work\n";}
    void see(){std::cout << " see\n";}
};

class TravelVisitor : public Visitor
{
  public:
    void visit(Street &s)
    {
        std::cout << "Relaxing go throught the street\n";
        s.walk();
    }
    void visit(Building &b)
    {
        std::cout << "Enjoing architechture\n";
        b.see();
    }
};

class BusinessVisitor : public Visitor
{
  public:
    void visit(Street &s)
    {
        std::cout << "Hurring to the office\n";
        s.hurry();
    }
    void visit(Building &b)
    {
        std::cout << "Entering the buildding and work as hell \n";
        b.work();
    }
};

int main(int argc, char *argv[])
{

    std::vector<Element *> city{new Street, new Building};
    TravelVisitor   traveller;
    BusinessVisitor businessman;

    for(auto el : city)
    {
        el->accept(traveller);
    }

    return 0;
}

/*
Design Pattern Prototype. 


*/

class AbstractBase{
public:
    virtual AbstractBase* Clone() = 0;
    int k = 9;
};

class Concrete : public AbstractBase{
public:
    virtual AbstractBase* Clone(){ return new Concrete(*this); }

};

int main(){

    AbstractBase *pBase;
    Concrete concrete;
    pBase = concrete.Clone();

}
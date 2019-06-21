/*
Design Pattern Facade. 

Simplifies interface to a set of objects or packages
*/

class Package1{
public:
    void Shift(){}
};

class Package2{
public:
    int Rotate(int i){ return i + 2; }

};

class Package3{
public:
    int Calc(){ return 3; }

};

class Facade{
private:
    Package1 pack1;
    Package2 pack2;
    Package3 pack3;
public:
    void DoSomething(){
        pack1.Shift();
        pack2.Rotate(pack3.Calc());
        pack1.Shift();
    }
};


int main(){

    Facade facade;
    facade.DoSomething();

}
/*
Design Pattern Builder. 

The builder pattern is an object creation software design pattern. Unlike the abstract factory pattern and the factory method pattern 
whose intention is to enable polymorphism, the intention of the builder pattern is to find a solution to the telescoping constructor 
anti-pattern[citation needed]. The telescoping constructor anti-pattern occurs when the increase of object constructor parameter 
combination leads to an exponential list of constructors. Instead of using numerous constructors, the builder pattern uses another 
object, a builder, that receives each initialization parameter step by step and then returns the resulting constructed object at once.

*/

#include <string>
#include <memory>

// Product
class Castle{
public:
    void AddWall(int height){};
    void AddTower(int window){};
    void AddBridge(const std::string& material){};
};

// Abstract Builder
class CastleBuilder{
public:
    void CreateCastle(){ 
        castle.reset( new Castle); 
    }
    std::shared_ptr<Castle> GetCastle() { return castle; }
    virtual void AddWall() = 0;
    virtual void AddTower() = 0;
    virtual void AddBridge() = 0;
protected:
    std::shared_ptr<Castle> castle;
};

// Concrete Builder
class RomanCastleBuilder : public CastleBuilder{
public:
    virtual void AddWall() { castle->AddWall(40); };
    virtual void AddTower(){ castle->AddTower(4); };
    virtual void AddBridge(){ castle->AddBridge("wood"); };
};

// Director
class CastleEngineer{
public:
    void SetBuilder(CastleBuilder* _builder){ builder = _builder; }
    std::shared_ptr<Castle> BuildCastle(){
        builder->CreateCastle();
        builder->AddTower();
        builder->AddWall();
        builder->AddTower();
        builder->AddWall();
        builder->AddBridge();
        return builder->GetCastle();
    }

private:
    CastleBuilder* builder;
};

int main(){
    CastleEngineer engineer;
    RomanCastleBuilder builder;
    engineer.SetBuilder(&builder);
    std::shared_ptr<Castle> castle = engineer.BuildCastle();

}

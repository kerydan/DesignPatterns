//------------- Abstract products and factory
class Armor{
};

class Arrow{
};


class AbstractFactory{
public:
    virtual Armor* CreateArmor() = 0;
    virtual Arrow* CreateArrow() = 0;
};

//------------- Roman products and factory
class RomanArmor: public Armor{
};

class RomanArrow: public Arrow {
};

class RomanFactory : public AbstractFactory{
public:
    virtual Armor* CreateArmor(){ return new RomanArmor; }
    virtual Arrow* CreateArrow(){ return new RomanArrow; }
};


void EquipArmy(AbstractFactory* factory){
    Armor& armor = *factory->CreateArmor();
    Arrow& arrow = *factory->CreateArrow();
    // do something with created weapon
}

int main()
{
    RomanFactory romanFactory;
    EquipArmy(&romanFactory);

    return 0;
}
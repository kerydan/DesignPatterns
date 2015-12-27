// Template method implementation

//------------- Abstract product
class Weapon{
};

// ------------ Abstract product factory
class WeaponFactory{
public:
    virtual Weapon* CreateWeapon() = 0;
};

//--------------  Concrete products
class Arrow: public Weapon{
};

class Armor : public Weapon{
};

// ------------ Concrete products factories
class ArmorFactory: public WeaponFactory{
public:
    virtual Weapon* CreateWeapon(){ return new Armor; };
};

class ArrowFactory : public WeaponFactory{
public:
    virtual Weapon* CreateWeapon(){ return new Arrow; };
};


int main()
{
    ArrowFactory arrowFactory;
    ArmorFactory armorFactory;

    Weapon* arrow = arrowFactory.CreateWeapon();
    Weapon* armor = armorFactory.CreateWeapon();

    return 0;
}
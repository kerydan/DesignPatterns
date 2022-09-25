/*
Design Pattern Proxy. 

Provides a surrogate or placeholder for another object to control access to it.
 A proxy is a wrapper or agent object that is being called by the client to access the real serving object behind the scenes.
*/


#include <iostream>
#include <memory>

class Beer {
public:
	virtual void Drink() = 0;
	virtual ~Beer() {};	
};

class RealBeer : public Beer {
	void Drink() override {
		std::cout << "Enjoy your drink!" << std::endl;
	}
};

class Barman : public Beer {
private:
	std::unique_ptr<Beer> realBeer=std::make_unique<RealBeer>();
	int clientAge;

public:
	Barman(int age) : clientAge(age) {}

	void Drink() {
		if (clientAge > 16)
			realBeer->Drink();
		else
			std::cout << "Sorry, you are too young. Come over later" << std::endl;
	}
};


int main()
{
    std::unique_ptr<Beer> beer = std::make_unique<Barman>(15);
    beer->Drink();
    
    beer = std::make_unique<Barman>(23);
    beer->Drink();
}

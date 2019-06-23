/*
Design Pattern Proxy. 

Provides a surrogate or placeholder for another object to control access to it.
 A proxy is a wrapper or agent object that is being called by the client to access the real serving object behind the scenes.
*/


#include <iostream>

class Beer {
public:
	virtual void Drink() = 0;
};

class RealBeer : public Beer {
	void Drink() override {
		std::cout << "Enjoy your drink!" << std::endl;
	}
};

class Barmen : public Beer {
private:
	Beer* realBeer;
	int clientAge;

public:
	Barmen(int age) : realBeer(new RealBeer()), clientAge(age) {}

	void Drink() {
		if (clientAge > 16)
			realBeer->Drink();
		else
			std::cout << "Sorry, you are too young. Come over later" << std::endl;
	}
};


int main()
{
	Beer* proxyBeer = new Barmen(15);
	proxyBeer->Drink();
	delete proxyBeer;

	proxyBeer = new Barmen(23);
	proxyBeer->Drink();
	delete proxyBeer;
}
/*
Design Pattern Decorator. 

allows behavior to be added to an individual object, dynamically, without affecting the behavior of other objects from the same class
*/

#include <iostream>

class ICar
{
public:
	virtual void Report() = 0;
};

class Car : public ICar
{
public:
	void Report() { std::cout << "A car."; };
};

class DecoratedSpoiler : public ICar
{
	ICar* pCar;
public:
	DecoratedSpoiler(ICar* car) : pCar(car) { ; }
	void Report()
	{
		pCar->Report();
		std::cout << " Decorated with spoiler.";
	};
};

class RedCar : public ICar
{
	ICar* pCar;
public:
	RedCar(ICar* car) : pCar(car) { ; }
	void Report()
	{
		pCar->Report();
		std::cout << " Painted vivid red.";
	};
};


int main()
{
	Car car;
	car.Report();
	std::cout << std::endl;
	DecoratedSpoiler decoratedCar(new RedCar(&car));
	decoratedCar.Report();
}
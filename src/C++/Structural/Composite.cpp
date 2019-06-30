/**
 *
 * Composite design pattern
 *
 * Describes a group of objects that is treated the same way as a single instance of the same type of object.
 * The intent of a composite is to "compose" objects into tree structures to represent part-whole hierarchies.
 */

#include <iostream>
#include <list>

class Component
{
protected:
	std::string name;
public:
	Component(std::string n) : name(n) {}
	virtual void Display() = 0;
};

class Leaf : public Component
{
public:
	Leaf(std::string n) : Component(n) {}
	virtual void Display() { std::cout << name << "  "; };
};

class Composite : public Component
{
	std::list<Component*> components;
public:
	Composite(std::string n) : Component(n) {}
	void Add(Component* c)
	{
		components.push_back(c);
	}
	virtual void Display()
	{
		std::cout << std::endl << name << " contains ";
		for (auto n : components)
		{
			n->Display();
		}
		std::cout << std::endl;
	};

};

int main()
{
	Composite* backpack = new Composite("backpack");
	Leaf* pencil = new Leaf("pencil");
	Leaf* notebook = new Leaf("notebook");
	Leaf* sandwich = new Leaf("sandwich");

	backpack->Add(pencil);
	backpack->Add(notebook);

	backpack->Add(sandwich);
	std::cout << std::endl << "A single Leaf displays: " << std::endl << std::endl;
	sandwich->Display();
	std::cout << std::endl << std::endl;
	std::cout << std::endl << "A Composite displays: " << std::endl;
	backpack->Display();
}

/**
Output:

A single Leaf displays:

sandwich


A Composite displays:

backpack contains pencil  notebook  sandwich
*/
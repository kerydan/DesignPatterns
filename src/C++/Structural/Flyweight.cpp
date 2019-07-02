/**
 * Flyweight Design Pattern
 *
 * A flyweight is an object that minimizes memory usage by sharing as much data as possible with other
 * similar objects; it is a way to use objects in large numbers when a simple repeated representation
 * would use an unacceptable amount of memory.
 */

#include <iostream>
#include <map>


class Flyweight
{
protected:
    char symbol;
public:
    virtual void Display(int state) = 0;

};

class ConcreteFlyweight : public Flyweight
{
public:
    ConcreteFlyweight(char c) {symbol = c;}

    virtual void Display(int state)
    {
        std::cout << "Displaying Character " << symbol << " in state " << state << std::endl;
    }
};

class FlyweightFactory
{
    std::map<char, Flyweight*> characters;

public:
    Flyweight& GetChar(char c)
    {
        if ( characters.find( c ) != characters.end() )
        {
            std::cout << std::endl <<"Flyweight object " << c << " has been REUSED" << std::endl;
            return *characters[c];
        }
        Flyweight *character = new ConcreteFlyweight( c );
        characters.insert( std::make_pair(c, character ) );
        std::cout << std::endl << "Flyweight object " << c << " has been CREATED" << std::endl;
        return *character;
    }

};

int main()
{
    FlyweightFactory characters;
    characters.GetChar('A').Display(1);   // new object created. red - is extrinsic(variant) State.
    characters.GetChar('A').Display(5);   // no need to create object. Prevously created object returned.
    characters.GetChar('B').Display(4);   // new object created.
}

/**
  Output:

    Flyweight object A has been CREATED
    Displaying Character A in state 1

    Flyweight object A has been REUSED
    Displaying Character A in state 5

    Flyweight object B has been CREATED
    Displaying Character B in state 4
*/

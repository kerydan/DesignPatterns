/**
 * Memento Design Pattern
 *
 * Provides the ability to restore an object to one of its previous states
 */

#include <iostream>

class Memento
{
    int state;
public:
    Memento(int s): state(s){}
    int GetState() {return state;}
};

class Originator
{
    int state;
public:
    void SetState(int s)
    {
        state = s;
        std::cout << "The game in state " << state << std::endl;
    }
    Memento* CreateMemento(){ return new Memento(state);}
    void RestoreMemento(Memento* m)\
    {
        std::cout << "The game restored from state " << state << " to state " << m->GetState() << std::endl;
        state = m->GetState();
    }
};

int main()
{
    Originator game;
    game.SetState(1);
    game.SetState(2);
    Memento* save2 = game.CreateMemento();
    game.SetState(3);
    game.RestoreMemento(save2);
    delete save2;
}

/**
  Output:

    The game in state 1
    The game in state 2
    The game in state 3
    The game restored from state 3 to state 2
*/

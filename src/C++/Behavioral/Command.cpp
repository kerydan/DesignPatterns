/**
 * Command Design Pattern
 *
 * Encapsulates an action and its parameters.
 */

#include <iostream>
#include <vector>
#include <memory>

class Receiver
{
public:
    void Start(){ std::cout << "Engine is On" << std::endl; }
};

class Command
{
protected:
Receiver* receiver;

public:
    Command(Receiver *rec) : receiver(rec) {}
    virtual void Action() = 0;
};

class ConcreteCommand : public Command
{
public:
    ConcreteCommand(Receiver *rec) : Command(rec) {}
    virtual void Action() {receiver->Start();}
};

class Invoker
{
    unique_ptr<Command> command;
public:
    void SetCommand(unique_ptr<Command> com) { command = move(com); }
    void Execute() {command->Action();}
};

int main() {

    Receiver engine;
    ConcreteCommand ;
    Invoker onBoardComputer;
    onBoardComputer.SetCommand(make_unique<commandOn>(&engine));
    onBoardComputer.Execute();
}

/**
  Output:

        Engine is On
*/

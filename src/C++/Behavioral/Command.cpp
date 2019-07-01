/**
 * Command Design Pattern
 *
 * Encapsulates an action and its parameters.
 */

#include <iostream>
#include <vector>

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
    Command* command;
public:
    void SetCommand(Command* com) { command = com; }
    void Execute() {command->Action();}
};

int main() {

    Receiver engine;
    ConcreteCommand commandOn(&engine);
    Invoker onBoardComputer;
    onBoardComputer.SetCommand(&commandOn);
    onBoardComputer.Execute();
}

/**
  Output:

        Engine is On
*/

﻿Design Patterns 1
===============

Implementation of [Design Patterns](https://en.wikipedia.org/wiki/Design_Patterns#Patterns_by_Type) in C++

# 2 Left

### Creational Patterns
- [x] [Abstract Factory](https://github.com/kerydan/DesignPatterns/blob/master/src/C++/Creational/AbstractFactory.cpp)
- [x] [Builder](https://github.com/kerydan/DesignPatterns/blob/master/src/C++/Creational/Builder.cpp)
- [x] [Factory Method](https://github.com/kerydan/DesignPatterns/blob/master/src/C++/Creational/FactoryMethod.cpp)
- [x] [Prototype](https://github.com/kerydan/DesignPatterns/blob/master/src/C++/Creational/Prototype.cpp)
- [x]  Singleton  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  [C++][Singleton_C]  &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; [Python][Singleton_P]

### Structural Patterns
- [x] [Adapter](https://github.com/kerydan/DesignPatterns/blob/master/src/C++/Structural/Adapter.cpp)
- [x] [Bridge](https://github.com/kerydan/DesignPatterns/blob/master/src/C++/Structural/Bridge.cpp)
- [x] [Composite](https://github.com/kerydan/DesignPatterns/blob/master/src/C++/Structural/Composite.cpp)
- [x] [Decorator](https://github.com/kerydan/DesignPatterns/blob/master/src/C++/Structural/Decorator.cpp)
- [x] [Facade](https://github.com/kerydan/DesignPatterns/blob/master/src/C++/Structural/Facade.cpp)
- [x] [Flyweight](https://github.com/kerydan/DesignPatterns/blob/master/src/C++/Structural/Flyweight.cpp)
- [x] [Proxy](https://github.com/kerydan/DesignPatterns/blob/master/src/C++/Structural/Proxy.cpp)

### Behavioral Patterns
- [x] [Chain of responsibility](https://github.com/kerydan/DesignPatterns/blob/master/src/C++/Behavioral/ChainOfResponsibility.cpp)
- [x] [Command](https://github.com/kerydan/DesignPatterns/blob/master/src/C++/Behavioral/Command.cpp)
- [ ] [Interpreter](https://github.com/kerydan/DesignPatterns/blob/master/src/C++/Behavioral/Interpreter.cpp)
- [ ] [Iterator](https://github.com/kerydan/DesignPatterns/blob/master/src/C++/Behavioral/Iterator.cpp)
- [x] [Mediator](https://github.com/kerydan/DesignPatterns/blob/master/src/C++/Behavioral/Mediator.cpp)
- [x] [Memento](https://github.com/kerydan/DesignPatterns/blob/master/src/C++/Behavioral/Memento.cpp)
- [x] [Observer](https://github.com/kerydan/DesignPatterns/blob/master/src/C++/Behavioral/Observer.cpp)
- [x] [State](https://github.com/kerydan/DesignPatterns/blob/master/src/C++/Behavioral/State.cpp)
- [x] [Strategy](https://github.com/kerydan/DesignPatterns/blob/master/src/C++/Behavioral/Strategy.cpp)
- [x] [Template Method](https://github.com/kerydan/DesignPatterns/blob/master/src/C++/Behavioral/TemplateMethod.cpp)
- [x] [Visitor](https://github.com/kerydan/DesignPatterns/blob/master/src/C++/Behavioral/Visitor.cpp)

[Singleton_C]: https://github.com/kerydan/DesignPatterns/blob/master/src/C++/Creational/Singleton.cpp/
[Singleton_P]: https://github.com/kerydan/DesignPatterns/blob/master/src/Py/Creational/Singleton.py/
[7_spaces]: &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;/



```mermaid
classDiagram
    class Boat {
        <<interface>>
        +Sail() void
    }
    
    class Car {
        -name: string
        +Car(str: string)
        +Drive() void
    }
    
    class CarToBoat {
        -car: Car*
        +CarToBoat(c: Car*)
        +Sail() void
    }

    CarToBoat --|> Boat : inherits
    CarToBoat o--> Car : adapts
```

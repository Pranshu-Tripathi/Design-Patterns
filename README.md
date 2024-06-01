This project contains example-based basic implementations of different LLD patterns using modern C++.

[Refactoring GURU - Design Patterns
](https://refactoring.guru/design-patterns)


### SOLID
 - Single Responsibility Principle
    - Different classes handle different tasks and problems
 - Open Closed Principle
    - Open for extension and closed for modification
 - Liskov Substitution Principle
    - Able to substitute the derived class object at any place where we use the base class object.
 - Interface Segregation Principle
    - Slip interface to separate interface
    - States no code should be forced to depend on methods it doesn’t use.
 - Dependency Inversion Principle
    - High-level modules should not depend on the low-level modules and vice versa. They should depend on the abstraction.
    - Abstraction should not depend on any details but the other way around must be followed.



### Builder Design Pattern
Subclassing for every edge case will cause too many classes to handle.
Massive constructors are a false sense of security and smell in client code.
When piecewise object construction is complicated, provide an API for doing that.
To make the builder fluent return this
Different facets of an object can be built with different builders working in tandem via a base class.
Potential for Incomplete Objects: If the client code forgets to call certain builder methods, it’s possible to create incomplete or inconsistent objects, leading to runtime errors.

### Factory Design Pattern
Creates objects without exposing the creation logic to the client (Creator) and refers to the newly created object using a common interface (Product)
Flexibility to programmer - what, who, how, and when are all definable
A creator interface that creates and instantiates different objects of a family as per the requirements.
This interface is inherited or implemented by each concrete object class with its implementation.
Factory Method
One method takes a parameter as input and creates an object based on that.
One can have multiple methods to do the same thing.
Inner Factory
An inner class in a data class also has itself as a data member of that class. (Not that much in use and not helpful when dealing with factory of factories)
Abstract Factory
Abstract Factory is a creational design pattern, which solves the problem of creating entire product families without specifying their concrete classes.
A way in which one factory delegates tasks to different types of factories that eventually return the object.
In Abstract Factory we have the privilege to create objects and also perform some post creation operations.

### Prototype Pattern
When it’s easier to copy an existing object to fully initialize a new one.
They reiterate existing designs
Requires deep copy support
Make cloning convenient
A partially or fully initialized object that you copy and make use of.
One can also use Serialization De-Serialization to get deep copy objects.
Always need to see the object graph cause the copy constructor with pointers will simply copy the pointer addresses and not the data.
Create_invalid_structure is an example

### Singleton Pattern
Implemented when we don’t want repetitive construction of objects and want them to work on a single instance.
Hide/delete the type’s constructor, copy constructor, and copy assignment operator.
Example: Database Access Handler Class. (should maintain consistent object across a session)
Problem:
Makes testing tough because of the hard dependency it adds to clients' implementation.
The solution is dependency inversion by using a mock class that overrides these methods and provides dummy implementations. (almost all of the maestro-src mock files)

### Adapter Pattern

  - `Getting the interface you want from the interface you have.`
  - Two types of implementation: Class Adapter, and Object Adapter.
  - A construct/mechanism that adapts an existing interface X to conform to the required interface Y.
  - With growing adapters in a designed system, we can have an abstract-level pluggable adapter that will be the interface for adapters.
  - Adapters can be used to cache the temporary objects.
     - Intermediate representation can pile up: use caching and other optimizations
     - Maintain a hash of already created objects.
     - We can return objects from the cache if they were already created.
        - Example:
           Resizing of window for drawing a rectangle should not regenerate the lines of the rectangle. 
           We have an adapter here that takes care of drawing lines that adapt the drawPoints interface.
           We can hash and cache these lines so that the issue of repetitive generation can be avoided.

### Bridge Design Pattern
Connecting components through abstraction
If a hierarchy has 3 classes, and it is using a hierarchy of 3 classes then a simple inheritance approach will create 9 classes (called Cartesian Product Duplication - One product class duplicated solely to confide with another product class). To avoid this we use a bridge pattern.
A mechanism that decouples an interface hierarchy from an implementation hierarchy.
Pimpl Implementation:
Used when we don’t want to expose implementation details in .h files.

### Composite Design Pattern
A mechanism for treating individual (scalar) objects and composition (group) of objects in a similar manner.
We hold instances of objects of the base class to get this working.
CRTP -> Curiously Recurring Template Pattern
C++ allows duck typing-> if a class implements begin() and end() then it is treated as a container.

### Decorator Design Pattern
Used to facilitate a behavior to an existing object
Follows SRP and OCP
Dynamic Decorator
We can keep base class reference and then each created object can have overlying functionality added to it.
The issue with this approach is that we have APIs exposed through some interface so we cannot call methods of respective classes on the object that is decorating them.
Static Decorator
They would work for C++ classes only
Works using C++ provided
Concepts
Mixin Inheritance
Perfect Forwarding.
Functional Decorators
Seems complicated
Logging entry exit to a function.
Template Return types and Args are used to implement a class that provides post and pre-functionality to a function.

### Facade (pronounced Fasade):
Exposing several components through a single interface.
Provides a simple, easy-to-understand/user interface over a large and sophisticated boy of code.
Use the Facade pattern when you need to have a limited but straightforward interface to a complex subsystem.
The facade shows how to make a single object represent an entire sub-system.

### Flyweight
A space optimization technique that lets us use less memory by storing externally the data associated with similar objects.
Boost flyweight is available
Store common data externally
Define the idea of “ranges” on homogeneous collections.
Intrinsic state = something belonging to an object that the outside world only reads
Extrinsic state = something affected by the outside world.
The Flyweight pattern suggests that you stop storing the extrinsic state inside the object. Instead, you should pass this state to specific methods which rely on it. Only the intrinsic state stays within the object, letting you reuse it in different contexts.
A good example of using flyweight is when you render a forest of trees in a game. Now you have trees of some specific color and texture repeated over a large area. Keeping the same color and texture details in every tree is memory inefficient. So rather you have an enum-based high-level static object that stores this data. The colors and texture are intrinsic states here, they don’t change over a tenure of time (constants).

### Proxy
An interface for accessing a particular resource.
Proxy acts like a local interface mimicking the object that is present at a remote location. -> same interface but entirely different behavior.
A class that functions as an interface to a particular resource. That resource may be remote, expensive to construct, or may require logging or some other added functionality.
A proxy looks and behaves like it is the current object, but underlying it has some extra functionality and features. ( Smart pointers are the best example of this in C++: they look and behave like normal raw pointers, but underlying they are so much more than that.
#### Proxy vs Decorator
Proxy tries to provide the same interface, decorator enhances that interface.
The decorator has an aggregate to the object it is decorating, but a proxy can be a solely independent object that mimics some other object.
The proxy doesn’t even have to materialize or provide the same background implementation (for example: a virtual proxy)
Different proxies like logging, communication, etc have completely different behaviors.
To create a proxy just focus on replicating the interface of the underlying object.

### Chain Of Responsibility
The sequence of handlers processing an event one after another.
A chain of components that will get a chance to process a command or a query, optionally having a default implementation and the ability to terminate the processing chain.
The approach can be of two types:
Centralized list.
De-Centralized list.

### Command Design Pattern
An object which represents a set of instructions to perform a particular action. Contains all the necessary information to act.
C++ statements are perishable and do not provide a way to record the operations once performed.
Also sometimes we want to serialize a set of operations, there the command pattern comes in handy.
Undo Infrastructure is traversing backward and forward on a set of commands.
#### Command Query Separation
The command is an object-mutating set of instructions that perform some operation on an object.  eg-> Batman please set your health to 50%
Commands in general don’t have any return value.
Query is a nonmutable operation that gets some values from the current database. Eg -> Batman what's your health?
A lot of designs follow command query separations where the implementation for such is segregated into different components for more control on how each of them works (query is majorly read operation, command is majorly write operation ).
GoF doesn’t segregate the two on certain abstraction levels both are the same only.
Command Pattern allows you to encapsulate all the details of a certain operation in a separate object.

### Interpreter Design Pattern
A component that processes structured text data. Does so by turning it into separate lexical tokens(lexing) and interpreting the sequences of said tokens(parsing)
Interpreters are everywhere -> programming language interpretation, regex interpretation.
Haven’t implemented it but is pretty much parsing only.
Iterator Design Pattern
How traversal of data structures happens and who makes it happen.
Make objects iterable with begin() end() operator!= operator++
Cannot be recursive with operator++ -> sporadic calls make it tough to maintain the stack
We can use a coroutine and generator for a recursive approach

### Mediator Design Pattern
Facilitates communication between components without them being aware of each other's presence or absence.
A component that facilitates communication between other components without them necessarily being aware of each other or having direct reference(access) to each other.
Create the mediator and have each object in the system refer to it.
Chat rooms or multiplayer-only games are examples of this.
Mediator engages in bidirectional communication with its components
Mediator has functions that the components can call
Components have functions that the mediator can call.

### Memento Design Pattern
A token/handle representing the system state. Let us roll back to the state when the token was generated. May or may not directly expose state information.
It is kind of an undo state -> but more extensive regarding checkpoint rollback.
Useful in undo redo - only when the sizes of operations are small.
Mementos are used to roll back states arbitrarily.
A memento is a simple token/handle class with no functions of its own.

### Observer Design pattern
An observer is an object that wishes to be informed about events happening in the system. The entity generating the events is observable.
Event <-> Subscriber / Signal <-> slot
Use Mutex to make the pattern thread-safe.

### State Design Pattern
A pattern in which the object’s behavior is determined by its state. An object transitions from one state to another (something needs to trigger a transition).
A formalized construct that manages state and transitions is called a state machine.

### Template Method Pattern
It has a blueprint method that calls all pure virtual functions.
Define an algorithm at a high level.
Define constituent parts as abstract methods.
Inherit the algorithm class and define the abstract methods as required.

### Strategy Design pattern (Policy pattern in C++)
System behavior is partially specified at runtime and is augmented later on.
Enables the exact behavior of a system at runtime (dynamic) or at compile time (static).

### Visitor Design Pattern
A pattern where a component (visitor) is allowed to traverse the entire inheritance hierarchy. Implemented by propagating a single visit() method throughout the entire hierarchy.
Intrusive Visitor: Simply pass the visitor object around.
Reflective Visitor: Have a separate class that based on the dynamic cast will get the correct object type and then perform the required operation.
Classic Double Dispatch: Visitables override accept and Visitors override visit. This is a kind of hacking around to get the correct object type called through compile time polymorphism. Also called the Cyclic visitor. It is useful when a visitor is needed on a stable hierarchy.
Acyclic Visitor: Uses the Reccuring Template pattern, and is useful with unstable hierarchy. With minimal change, one can add and remove visitables.
MultiMethod Visitor: This is a complicated way of basically overloading signatures for multiple argument type inference. (Example: Collision of asteroid, planet, and spaceship)
std::variant: Using std::visit kind of allows one to perform operations based on type inference.

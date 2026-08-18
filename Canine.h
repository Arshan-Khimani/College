/*
Pseudocode:

1. **Canine Class** (inherits from Animal):
   - **Constructors**:
     - **Default Constructor** (`Canine()`):
       - Calls the default constructor of the `Animal` class using `Animal()`.
       - Prints a message indicating that the object is a `Canine`.

   - **Member Function**:
     - **eat()** (overridden):
       - Overrides the `eat()` function from the `Animal` class to provide `Canine`-specific behavior.
       - Prints a message that describes the canine's eating habits, with a special mention of not liking a specific type of food (e.g., "pedigree").
*/

#ifndef CANINE_H
#define CANINE_H
#include "Animal.h"
#include <iostream>

// Defines the Canine class that publicly inherits from Animal
class Canine : public Animal 
{
    public:
        // Inherit constructors from the Animal class
        using Animal::Animal;
        
        // Default constructor that calls Animal's default constructor and prints a message
        Canine() : Animal() 
        {
            std::cout << "I am a canine!!\n";
        }
    
        // Override the eat() function to provide Canine-specific behavior
        void eat() override 
        {
            std::cout << "From C: I am a nice canine you know.I eat whatever you feed me.\n" << "But please please don't serve that pedigree!!\n";
        }
};

#endif

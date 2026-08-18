/*
Pseudocode:

1. **Feline Class** (inherits from Animal):
   - **Constructors**:
     - **Default Constructor** (`Feline()`):
       - Calls the default constructor of the `Animal` class using `Animal()`.
       - Prints a message indicating that the object is a `Feline`.

   - **Member Functions**:
     - **makeNoise()** (overridden):
       - Overrides the `makeNoise()` function from the `Animal` class to provide `Feline`-specific behavior.
       - Prints a message that the feline makes a scary noise.

     - **eat()** (overridden):
       - Overrides the `eat()` function from the `Animal` class to provide `Feline`-specific behavior.
       - Prints a message that describes the feline's eating habits, with a humorous reference to eating whatever is in sight, including "you".
*/

#ifndef FELINE_H
#define FELINE_H
#include "Animal.h"
#include <iostream>

// Defines the Feline class, derived publicly from Animal
class Feline : public Animal 
{
    public:
        // Inherits all constructors from the Animal class
        using Animal::Animal;
        
        // Default constructor that calls the Animal default constructor and prints a message
        Feline() : Animal() 
        {
            std::cout << "I am a Feline!!\n";
        }
    
        // Overrides the makeNoise() method to provide Feline-specific behavior
        void makeNoise() override 
        {
            std::cout << "From F: I make a scary noise\n";
        }
    
        // Overrides the eat() method to provide Feline-specific eating behavior
        void eat() override 
        {
            std::cout << "From F: I am a nice Feline you know.\n" << "I eat whatever I see and that means YOU! Haha!!\n";
        }
};

#endif 

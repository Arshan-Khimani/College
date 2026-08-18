/*
Pseudocode:

1. **Lion Class** (inherits from Feline):
   - **Constructors**:
     - **Default Constructor** (`Lion()`):
       - Calls the default constructor of the `Feline` class using `Feline()`.
       - Sets the `picture` attribute to "Lion".
       - Prints a message specific to the `Lion` class, highlighting the lion's kingly status.

   - **Member Functions**:
     - **makeNoise()** (overridden):
       - Overrides the `makeNoise()` function from the `Feline` class to define `Lion`-specific behavior.
       - Prints a message indicating that lions roar.

     - **eat()** (overridden):
       - Calls the `eat()` function from the base `Feline` class to maintain feline-specific behavior.
       - Adds a `Lion`-specific message about its hunger, portraying impatience.
*/

#ifndef LION_H
#define LION_H
#include "Feline.h"
#include <iostream>

// Defines the Lion class, which is derived publicly from Feline
class Lion : public Feline 
{
    public:
        // Default constructor that calls Feline's default constructor
        Lion() : Feline() 
        {
            // Sets the picture attribute to "Lion"
            setPicture("Lion");
        
            // Prints a message specific to the Lion class
            std::cout << "Lion: I am the king of my animal kingdom!!\n";
        }
    
        // Overrides the makeNoise() method to define Lion-specific behavior
        void makeNoise() override
        {
            std::cout << "Lions roar!!\n";
        }
    
        // Overrides the eat() method to extend Feline's behavior
        void eat() override 
        {
            // Calls the base Feline class's eat() method
            Feline::eat();
        
            // Adds a Lion-specific message about its hunger
            std::cout << "Watch your back. My hunger gets impatient.\n";
        }
};

#endif  

/*
Pseudocode:

1. **Dog Class** (inherits from Canine):
   - **Constructors**:
     - **Default Constructor** (`Dog()`):
       - Calls the default constructor of the `Canine` class using `Canine()`.
       - Sets the `picture` attribute to "Dog".
       - Prints a message about the dog's affectionate nature and its love for cuddles and unconditional love for its owner.

   - **Member Functions**:
     - **makeNoise()** (overridden):
       - Overrides the `makeNoise()` function from the `Canine` class to define the dog-specific sound ("WOOF WOOF").

     - **eat()** (overridden):
       - Calls the base `Canine` class's `eat()` function.
       - Adds a dog-specific message indicating its acceptance of dog food ("I am okay with dog food! I promise.").
*/

#ifndef DOG_H
#define DOG_H
#include "Canine.h"
#include <iostream>

// Defines the Dog class, which is publicly derived from Canine
class Dog : public Canine
{
    public:
        // Inherits all constructors from the Canine class
        using Canine::Canine;
        
        // Default constructor that initializes Dog-specific attributes
        Dog() : Canine() 
        {
            // Sets the picture attribute to "Dog"
            setPicture("Dog");
          
            // Prints a message about the dog's affectionate nature
            std::cout << "Dog: I love being petted! I love cuddles!\n" << "I'd love my owner unconditionally!!\n";
        }
    
        // Overrides the makeNoise() method with dog-specific sound
        void makeNoise() override
        {
            std::cout << "WOOF WOOF\n";
        }
    
        // Overrides the eat() method to extend Canine behavior with Dog preferences
        void eat() override 
        {
            // Calls the base Canine class's eat method
            Canine::eat();
           
            // Prints a message indicating dog's acceptance of dog food
            std::cout << "I am okay with dog food! I promise.\n";
        }
};

#endif  

/*
Pseudocode:

1. **Wolf Class** (inherits from Canine):
   - **Constructors**:
     - **Default Constructor** (`Wolf()`):
       - Calls the default constructor of the `Canine` class using `Canine()`.
       - Sets the `picture` attribute to "Wolf".
       - Prints a message unique to the `Wolf` class, expressing some character traits or behavior.

   - **Member Functions**:
     - **makeNoise()** (overridden):
       - Overrides the `makeNoise()` function from the `Canine` class to provide `Wolf`-specific behavior.
       - Prints a message indicating that wolves howl, cry, and yell.

     - **eat()** (overridden):
       - Calls the `eat()` function from the base `Canine` class to retain canine-specific behavior.
       - Adds `Wolf`-specific behavior, such as a preference for fresh meals.
*/

#ifndef WOLF_H
#define WOLF_H
#include "Canine.h"
#include <iostream>

// Defines the Wolf class, which is derived publicly from Canine
class Wolf : public Canine 
{
    public:
        // Inherits all constructors from the Canine class
        using Canine::Canine;
        
        // Default constructor that calls Canine's default constructor
        Wolf() : Canine() 
        {
            // Sets the picture attribute to "Wolf"
            setPicture("Wolf");
           
            // Prints a message specific to the Wolf class
            std::cout << "Wolf: Why don't take me as your pet? Why is dog so special?\n";
        }
    
        // Overrides the makeNoise() method with Wolf-specific behavior
        void makeNoise() override
        {
            std::cout << "Wolves howl, cry and yell!!\n";
        }
    
        // Overrides the eat() method, calls Canine's version, and adds more behavior
        void eat() override 
        {
            // Call the base Canine class's eat() method
            Canine::eat();
        
            // Add a Wolf-specific message about eating preferences
            std::cout << "I only like my meals fresh, if I am being honest.\n";
        }
};

#endif

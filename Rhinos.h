/*
Pseudocode:

1. **Rhinos Class** (inherits from Animal):
   - **Constructors**:
     - **Default Constructor** (`Rhinos()`):
       - Calls the default constructor of the `Animal` class using `Animal()`.
       - Sets the `picture` attribute to "Rhino".
       - Sets the `food` attribute to "Veg".
       - Sets the `hunger` level to 10.
       - Sets the `boundaries` to "Water".
       - Prints a friendly introduction message specific to Rhinos.
    
     - **Parameterized Constructor** (`Rhinos(const std::string& pic, const std::string& f, int h, const std::string& b)`):
       - Calls the `Animal` constructor with parameters to initialize attributes.
       - Prints a message indicating the Rhino is photogenic and harmless.

   - **Member Functions**:
     - **makeNoise()** (overridden):
       - Overrides the `makeNoise()` function from the `Animal` class to define Rhino-specific behavior.
       - Prints a message indicating that Rhinos bellow and are vegetarians.

     - **eat()** (overridden):
       - Overrides the `eat()` function to provide a Rhino-specific dietary message, emphasizing their vegetarian nature.
*/

#ifndef RHINOS_H
#define RHINOS_H
#include "Animal.h"
#include <iostream>

// Defines the Rhinos class, which is publicly derived from Animal
class Rhinos : public Animal
{
    public:
        // Inherits all constructors from the Animal class
        using Animal::Animal;
        
        // Default constructor that initializes the Rhino with specific values
        Rhinos() : Animal() 
        {
            // Sets the picture attribute to "Rhino"
            setPicture("Rhino");
        
            // Sets the food preference to "Veg"
            setFood("Veg");
        
            // Sets the hunger level to 10
            setHunger(10);
        
            // Sets the habitat boundaries to "Water"
            setBoundaries("Water");
        
            // Prints a friendly introduction message specific to Rhinos
            std::cout << "Rhinos: I am super friendly! Just be careful of my huge horn!!\n";
        }
    
        // Parameterized constructor that initializes attributes using the base class constructor
        Rhinos(const std::string& pic, const std::string& f, int h, const std::string& b) : Animal(pic, f, h, b) 
        {
            // Prints a message indicating the Rhino is photogenic and harmless
            std::cout << "I don't harm anyone. I pose good for pictures!!\n";
        }
    
        // Overrides the makeNoise() method with Rhino-specific behavior
        void makeNoise() override
        {
            std::cout << "Rhinos bellow!!\nFrom R: I am a vegetarian.\n";
        }
    
        // Overrides the eat() method with Rhino-specific dietary message
        void eat() override 
        {
            std::cout << "I can eat even the grass, but please don't serve me Non-veg!!\n";
        }
};

#endif  

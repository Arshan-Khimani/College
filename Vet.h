/*
Pseudocode:

1. **Vet Class**:
   - **Constructor**:
     - **Default Constructor** (`Vet()`):
       - Prints a message indicating the Vet is ready to treat animals when a `Vet` object is created.

   - **Member Function**:
     - **giveShot(Animal &a)**:
       - Simulates the action of giving a shot to an `Animal` object. Outputs a message to inform the user about the shot being given.
*/

#ifndef VET_H
#define VET_H
#include "Animal.h"
#include <iostream>

// Defines the Vet class
class Vet 
{
    public:
        // Default constructor that prints a message when a Vet object is created
        Vet()
        {
            std::cout << "\nHey I am the Vet for treating your animals!!\n";
        }
    
        // Member function that simulates giving a shot to an Animal object
        void giveShot(Animal &a) 
        {
            std::cout << "I am going to give a shot.\nPlease bear with me baby.";
        }
};

#endif  

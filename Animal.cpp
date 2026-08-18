/*
Pseudocode:

1. **Default Constructor**:
   - Initializes member variables with default values.
     - `picture = "animal"`
     - `food = "human"`
     - `hunger = 1`
     - `boundaries = "Jungle"`
   - Outputs a message: "I am part of my animal kingdom. Welcome!!"

2. **Parameterized Constructor**:
   - Initializes member variables with provided values for `picture`, `food`, `hunger`, and `boundaries`.

3. **Copy Constructor**:
   - Creates a copy of another Animal object.
   - Copies the values of `picture`, `food`, `hunger`, and `boundaries` from another `Animal` object.
   - Outputs a message: "My job is to copy" to indicate when the copy constructor is being used.

4. **Assignment Operator Overload**:
   - Used to assign one `Animal` object to another.
   - First, it checks for self-assignment (when an object is assigned to itself) by comparing object addresses (`this != &other`).
   - If not self-assignment, the member variables (`picture`, `food`, `hunger`, `boundaries`) are copied from the source object to the current object.

5. **Stream Insertion Operator Overload**:
   - Overloads the `<<` operator for outputting an `Animal` object to the stream.
   - Calls the `print()` function of the `Animal` object to display its details.
   - Returns the output stream to allow chaining of operations.
*/

#include "Animal.h"
#include <iostream>

// Define the default constructor for Animal, initializing member variables with default values
Animal::Animal() : picture("animal"), food("human"), hunger(1), boundaries("Jungle") 
{
    // Print a welcome message when an Animal object is created using the default constructor
    std::cout << "I am part of my animal kingdom. Welcome!!\n";
}

Animal::Animal(const std::string& pic, const std::string& f, int h, const std::string& b) : picture(pic), food(f), hunger(h), boundaries(b)
{
    // Define a parameterized constructor that initializes member variables 
}
    
// Define a copy constructor that initializes the current object using another Animal object
Animal::Animal(const Animal& other) : picture(other.picture), food(other.food), hunger(other.hunger), boundaries(other.boundaries) 
{
    // Print a message indicating the copy constructor is being used
    std::cout << "My job is to copy\n";
}

// Define the assignment operator overload for the Animal class
void Animal::operator=(const Animal& other) 
{
    // Check for self-assignment by comparing addresses
    if (this != &other)
    {
        // Copy the picture from the other Animal object
        picture = other.picture;
      
        // Copy the food from the other Animal object
        food = other.food;
      
        // Copy the hunger value from the other Animal object
        hunger = other.hunger;
      
        // Copy the boundaries from the other Animal object
        boundaries = other.boundaries;
    }
}

// Define the stream insertion operator overload for the Animal class
std::ostream& operator<<(std::ostream& os, const Animal& animal) 
{
    // Call the print function of the Animal object to display its details
    animal.print();

    // Return the output stream to allow chaining
    return os;
}

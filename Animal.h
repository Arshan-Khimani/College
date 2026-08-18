/*
Pseudocode:

1. **Private Member Variables**:
   - `picture`: Stores the animal's picture (represented as a string).
   - `food`: Stores the animal's food type (represented as a string).
   - `hunger`: Stores the animal's hunger level (represented as an integer).
   - `boundaries`: Stores the animal's habitat (represented as a string).

2. **Public Member Functions**:
   
   - **Constructors**:
     - **Default Constructor** (`Animal()`):
       Initializes the member variables with default values.

     - **Parameterized Constructor** (`Animal(const std::string& pic, const std::string& f, int h, const std::string& b)`):
       Initializes the member variables with provided values for `picture`, `food`, `hunger`, and `boundaries`.

     - **Copy Constructor** (`Animal(const Animal& other)`):
       Initializes the current object with the values of another `Animal` object.

   - **Destructor**:
     - **Virtual Destructor** (`~Animal()`): Ensures proper cleanup in derived classes.
   
   - **Assignment Operator Overload** (`void operator=(const Animal& other)`):
     - Copies the member variables from one `Animal` object to another.
   
   - **Getter and Setter Functions**:
     - `getPicture()`: Returns the `picture` member variable.
     - `getFood()`: Returns the `food` member variable.
     - `getHunger()`: Returns the `hunger` member variable.
     - `getBoundaries()`: Returns the `boundaries` member variable.
     - `setPicture(const std::string& pic)`: Sets the `picture` member variable.
     - `setFood(const std::string& f)`: Sets the `food` member variable.
     - `setHunger(int h)`: Sets the `hunger` member variable.
     - `setBoundaries(const std::string& b)`: Sets the `boundaries` member variable.

   - **Virtual Functions**:
     - **makeNoise()**: Defines how the animal makes noise (default implementation in the base class).
     - **eat()**: Defines how the animal eats (calls `roam()` in this case).
     - **roam()**: Defines how the animal roams (default implementation in the base class).
     - **sleep()**: Defines how the animal sleeps (final virtual function in the base class).
     - **print()**: Prints the animal's information (final virtual function in the base class).

   - **Friend Function**:
     - **Operator Overload for Output Stream** (`std::ostream& operator<<(std::ostream& os, const Animal& animal)`):
       Allows printing the `Animal` object using the `<<` operator by calling its `print()` method.
*/

#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
#include <iostream>

// Define the Animal class
class Animal 
{
    private:
        // Private member variable to store the animal's picture
        std::string picture;
      
        // Private member variable to store the animal's food type
        std::string food;
      
        // Private member variable to store the animal's hunger level
        int hunger;
      
        // Private member variable to store the animal's boundaries (habitat)
        std::string boundaries;
    
    public:
        // Default constructor declaration
        Animal();
      
        // Parameterized constructor declaration
        Animal(const std::string& pic, const std::string& f, int h, const std::string& b);
      
        // Copy constructor declaration
        Animal(const Animal& other);
      
        // Virtual default destructor to ensure proper cleanup in derived classes
        virtual ~Animal() = default;
    
        // Overloaded assignment operator declaration
        void operator=(const Animal& other);
    
        // Getter function for picture
        std::string getPicture() const { return picture; }
    
        // Getter function for food
        std::string getFood() const { return food; }
    
        // Getter function for hunger level
        int getHunger() const { return hunger; }
    
        // Getter function for boundaries
        std::string getBoundaries() const { return boundaries; }
    
        // Setter function for picture
        void setPicture(const std::string& pic) { picture = pic; }
    
        // Setter function for food
        void setFood(const std::string& f) { food = f; }
    
        // Setter function for hunger
        void setHunger(int h) { hunger = h; }
    
        // Setter function for boundaries
        void setBoundaries(const std::string& b) { boundaries = b; }
    
        // Virtual function to define how the animal makes noise
        virtual void makeNoise() 
        { 
            std::cout << "From A: I am extremely friendly! I will eat anything I am given!!\n";
        }
        
        // Virtual function to define how the animal eats (calls roam in this case)
        virtual void eat() 
        {
            Animal::roam();
        }
        
        // Virtual function to define how the animal roams
        virtual void roam() 
        {
            std::cout << "From A: I like to roam in forest. But the humans destroyed my habitat\n";
        }
        
        // Final virtual function to define how the animal sleeps
        virtual void sleep() final 
        {
            std::cout << "From A: ZZZZ I am sleeping. Don't disturb me.\n" << "I can get wild if you disturb me during my sleep!!\n";
        }
        
        // Final virtual function to print the animal's information
        virtual void print() const final 
        {
            std::cout << "Picture: " << picture << "\nFood: " << food << "\nHunger Level: " << hunger << "\nBoundaries: " << boundaries << std::endl;
        }
    
        // Friend function to overload the output stream operator for Animal
        friend std::ostream& operator<<(std::ostream& os, const Animal& animal);
};

#endif

/*
Pseudocode:

1. **Animal Objects Creation:**
   - **Rhinos (r1)**: Instantiate with parameters and call methods: makeNoise(), eat(), roam(), sleep(). Display food type.
   - **Rhinos (r2)**: Instantiate using default constructor. Call the same methods and display food.
   - **Rhinos (r3)**: Instantiate using copy constructor, copy r2 and display it.

2. **Lion Object Creation (l):**
   - Instantiate a Lion object with the default constructor.
   - Display details and call animal-specific methods: makeNoise(), eat(), roam(), sleep().

3. **Wolf Object Creation (w):**
   - Instantiate a Wolf object with parameters and display.
   - Call animal methods.
   - Change food using setter and copy wolf object into another wolf (w2).
   - Display copied wolf.

4. **Animal Array of 5 Elements (animal):**
   - Declare an array of 5 Animal objects (generic array, mixed types).
   - Assign objects of different animal types (Dog, Wolf, Rhinos, Tiger, Lion) to array elements using constructors.
   - Loop through array and call methods on each animal: makeNoise(), eat(), roam(), sleep().

5. **Animal Pointer Array of 5 Elements (animal1):**
   - Declare an array of pointers to Animal.
   - Dynamically allocate objects for Dog, Wolf, Rhinos, Tiger, Lion using new.
   - Loop through pointers and call methods: print(), makeNoise(), eat(), roam(), sleep().

6. **Vet Object (v):**
   - Instantiate a Vet object.
   - For each animal type (Dog, Rhinos, Feline), call Vet’s giveShot() method and print response based on animal type.

7. **Functionality Description:**
   - For each type of animal (Dog, Wolf, Rhinos, Tiger, Lion), display its behavior by calling relevant methods such as makeNoise(), eat(), roam(), and sleep.
   - For the Vet, simulate interaction with different animals by calling giveShot() method and printing animal's response after the shot.

8. **Program Conclusion:**
   - The program will output details and behaviors of multiple animals and show interaction with a Vet, simulating a zoo or animal behavior scenario.
*/

#include <iostream>
#include "Rhinos.h"
#include "Lion.h"
#include "Tiger.h"
#include "Wolf.h"
#include "Dog.h"
#include "Vet.h"

using namespace std;

int main()
{
    // Instantiate a Rhino object with parameters
    Rhinos r1 ("Rhino", "Grass", 2, "Jungle");
    cout<<r1;
    cout << endl << endl;
	r1.makeNoise();
	r1.eat();
	r1.roam();
	r1.sleep();
	cout << "The food I eat is " << r1.getFood() <<endl <<endl;

	// Instantiate a Rhino object with no parameters
	cout << "\nRhinos with no parameters \n";
	Rhinos r2 ;
	cout<<r2;
	r2.makeNoise();
	r2.eat();
	r2.roam();
	r2.sleep();
	cout << "The food I eat is " << r2.getFood() <<endl <<endl;

	// Instantiate a Rhino object  by copying another Rhino object
	cout << "\nNew Rhino: \n";
	Rhinos r3(r2);
	cout<<r3;
    cout << endl;

    // Instantiate a Lion object with no parameters
	cout << "\nLION \n";
	Lion l ;
	cout<<l;
	cout << endl << endl;
	l.makeNoise();
	l.eat();
	l.roam();
	cout << "From F: I can be a scaredy cat. I find comfort in roaming areas away from everyone\n";
	cout << "Do not approach me.\n";
	l.sleep();
    cout << endl << endl;

    // Instantiate a Wolf object with parameters
	cout << "\nWOLF \n";
	cout << "I am part of my animal kingdom with all parameters set!!\n";
	Wolf w ("Wolfe", "Meat", 10, "Fields");
	cout<<w;
	cout << endl << endl;
	w.makeNoise();
	w.eat();
	w.roam();
	cout << "From C: I like to roam in a group.You are welcome to be part of my group\n";
	w.sleep();
	cout << endl << endl;
	w.setFood("Rabbit");
    cout << "\nCopying another WOLF object\n";
	Wolf w2 = w;
    cout<<w2;


	// Declare an array of 5 Animal objects
    Animal animal[5];
    
    // Print a heading for the DOG section
    cout << "\nDOG:" << endl;
    
    // Print a message indicating the Dog is being initialized with parameters
    cout << "I am part of my animal kingdom with all parameters set!!\n";
    
    // Create a Dog object with given parameters and assign it to the first element of the array
    animal[0] = Dog("Tommy", "YogurtRice", 12, "Home");
    
    // Print a heading for the WOLF section
    cout << " \nWOLF:"<< endl;
    
    // Create a Wolf object using the default constructor and assign it to the second element
    animal[1] =  Wolf();
    
    // Print a heading for the RHINOS section
    cout << "\nRHINOS:"<< endl;
    
    // Create a Rhinos object using the default constructor and assign to third element
    animal[2] = Rhinos();
    
    // Print a heading for the TIGER section
    cout << "\nTIGER:"<< endl;
    
    // Create a Tiger object using the default constructor and assign to fourth element
    animal[3] = Tiger();
    
    // Print a heading for the LION section
    cout << "\nLION:"<< endl;
    
    // Create a Lion object using the default constructor and assign to fifth element
    animal[4] =  Lion();
    
    // Print an extra newline for spacing
    cout << endl;
    
    // Print section heading for animal behavior
    cout << ("\nEating, roaming and noise Habbits:\n");
    
    // Print a visual separator
    cout << "----------------------------------\n";
    
    // Start a loop to process each animal in the array
    for(int i = 0; i < 5; i++)
    {
        // Print the animal using overloaded operator<<
        cout<<animal[i];
    
        // Call the animal's makeNoise method
        animal[i].makeNoise();
    
        // Call the animal's eat method
        animal[i].eat();
    
        // Call the animal's sleep method
        animal[i].sleep();
    
        // Print a newline for spacing
        cout << endl;
    }

    // Declare an array of 5 pointers to Animal
    Animal *animal1[5];
    
    // Print a heading for the Dog section
    cout << "Dog: \n";
    
    // Print a message indicating Dog is initialized with parameters
    cout << "I am part of my animal kingdom with all parameters set!!\n";
    
    // Dynamically allocate a Dog object with parameters and assign to first pointer
    animal1[0] = new Dog("Tommy", "YogurtRice", 12, "Home");
    
    // Print a newline for spacing
    cout << endl;
    
    // Print a heading for the Wolf section
    cout << "Wolf: \n";
    
    // Dynamically allocate a Wolf object and assign to second pointer
    animal1[1] =  new Wolf();
    
    // Print a newline for spacing
    cout << endl;
    
    // Print a heading for the Rhinos section
    cout << "Rhinos: \n";
    
    // Dynamically allocate a Rhinos object and assign to third pointer
    animal1[2] = new Rhinos();
    
    // Print a newline for spacing
    cout << endl;
    
    // Print a heading for the Tiger section
    cout << "Tiger: \n";
    
    // Print a message indicating Tiger is initialized with parameters
    cout << "I am part of my animal kingdom with all parameters set!!\n";
    
    // Dynamically allocate a Tiger with parameters and assign to fourth pointer
    animal1[3] = new Tiger("Tigger", "you", 15, "Sambal Forest");
    
    // Print a newline for spacing
    cout << endl;
    
    // Print a heading for the Lion section
    cout << "Lion: \n";
    
    // Dynamically allocate a Lion and assign to fifth pointer
    animal1[4] = new Lion();
    
    // Print a newline for spacing
    cout << endl;
    
    // Print section heading for animal behavior
    cout << ("\nEating, roaming and noise Habbits:\n");
    
    // Print a visual separator
    cout << "----------------------------------\n";
    
    // Start a loop to process each animal pointer
    for(int i = 0; i < 5; i++)
    {
        // Call print function using pointer dereferencing
        animal1[i]->print();
    
        // Print a newline for spacing
        cout << endl;
    
        // Call makeNoise through pointer
        animal1[i]->makeNoise();
    
        // Call eat through pointer
        animal1[i]->eat();
    
        // Call roam through pointer
        animal1[i]->roam();
    
        // Call sleep through pointer
        animal1[i]->sleep();
    
        // Print two newlines for separation
        cout << endl << endl;
    }
    
    // Create a Vet object
    Vet v;
    
    // Print heading for DOG section
    cout << "\nDOG:" << endl;
    
    // Create a Dog object using default constructor
    Dog d;
    
    // Print heading for Vet section
    cout << "\nVet:" << endl;
    
    // Call the giveShot method of Vet, passing the Dog object
    v.giveShot(d);
    
    // Print the Dog's response to the shot
    cout << "WOOF WOOF" << endl;
    
    // Print heading for Rhinos section
    cout << "\nRhinos:" << endl;
    
    // Create a Rhinos object using default constructor
    Rhinos r;
    
    // Print heading for Vet section
    cout << "\nVet:" << endl;
    
    // Call the giveShot method of Vet, passing the Rhinos object
    v.giveShot(r);
    
    // Print the Rhinos' response to the shot
    cout << "Rhinos bellow!!" << endl;
    
    // Print heading for Feline section
    cout << "\nFeline:" << endl;
    
    // Create a Feline object using default constructor
    Feline f;
    
    // Print heading for Vet section
    cout << "\nVet:" << endl;
    
    // Call the giveShot method of Vet, passing the Feline object
    v.giveShot(f);
    
    // Print the Feline's response to the shot
    cout << "From F: I make a scary noise";
    
    // Print final newline
    cout << endl;

    return 0;
}
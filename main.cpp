/* This program will read a file containing sales data and write a bar 
chart to represent the data read to a file named “saleschart.txt”.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
   
   
   unsigned int storeNumber;
   long long int salesValue;
   long long int sales;
   
   // string fileName to store the name of the input file
   
   string fileName;
   
   // int num variable to use inside a for loop  
   
   int num;
    
   ifstream inputFile;
   ofstream outputFile;
    
   cout << "Please enter the input file name." << endl;
   cin >> fileName;
   
   inputFile.open(fileName);
   
   // if statement to to check wheather the file exists or not
   
   if(inputFile)
   {
      outputFile.open("saleschart.txt");
      
      cout << "SALES BAR CHART" << endl;
      cout << "(Each * equals 5,000 dollars)" << endl;
      
      // assigning the store number and sales value of that store form the input file
      
      while(inputFile >> storeNumber >> salesValue)
      {
         // Error statement if the store number not is range
         
         if(storeNumber < 1 || storeNumber > 99)
         {   
            cout << storeNumber << " is not in the range 1 through 99." << endl;
         }
         
         // store with less than 0 sales value are skipped 
         
         else if (salesValue < 0)
         {
            cout << "Skipped store #" << storeNumber << "." << endl;
         }
         else
         {
            sales = salesValue / 5000;
            cout << "Store " << setw(2) << storeNumber << ": ";
               
               // for loop to ouput "*" to represent the number of sales 
               
               for(num = 0; num < sales; num++)
               {
                  cout << "*";
               } 
               cout << endl;
         }
      }
   }
   else
   {
      // Error satatement of the file doesn't exist
      
      outputFile.close();
      cout << "\"" << fileName << "\" could not be opened." << endl;
   }
    
   inputFile.close();
   outputFile.close();

   return 0;
}
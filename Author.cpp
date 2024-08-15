#include "Author.h"
#include <iostream>
#include <string>
using namespace std;

// TODO: Define default constructor
   Author::Author(string authorName, int birthYear, int deathYear) {
   this->authorName = authorName;
   this->birthYear = birthYear;
   this->deathYear = deathYear;
   }

   Author::Author() {
   authorName = "unknown";
   birthYear = -1;
   deathYear = -1;
   }

   
   string Author::GetName() const {
       return authorName;  
      }
   
   int Author::GetBirthYear() const {
       return birthYear;  
      }

   int Author::GetDeathYear() const {
      return deathYear;
      }
   void Author::PrintInfo() const {
      cout << "Author: "<< authorName << " ("; 
   if (birthYear > 0 && deathYear > 0) {	
   cout << birthYear << " to " << deathYear; 
   }
   else if (birthYear > 0 && deathYear < 0) {
   cout<< birthYear << " to present"; 
   }
   else {
      cout << "unknown";
   }
      
      cout << ")" <<endl;
   
      }

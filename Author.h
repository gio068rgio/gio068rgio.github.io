#ifndef AUTHORH
#define AUTHORH

#include <string>
using namespace std;

class Author {
   public:
   
   Author();
   Author(string authorName, int birthYear, int deathYear);
   string GetName() const;
   int GetBirthYear() const;
   int GetDeathYear() const;
   void PrintInfo() const;

   private:

   string authorName;
   int birthYear;
   int deathYear;
   };

#endif

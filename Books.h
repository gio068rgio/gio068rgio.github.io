#ifndef BOOKSH
#define BOOKSH 

#include "Author.h" 
class Books { 
  public: 
    Books();
    Books(string bookTitle, int yearCreated, Author bookmaker);
    int GetYearCreated();
    void PrintTitle();
    string getTitle();

  private:
    string title;
    Author bookMaker;
    int yearCreated;

};

#endif

#include <iostream>
#include "Books.h"
using namespace std;

Books::Books() { 
  title = "unknown";
  bookMaker = Author();
  yearCreated = -1;
}
Books::Books(string bookTitle, int yearCreated, Author bookMaker) {
  this->title = bookTitle;
  this->bookMaker = bookMaker;
  this->yearCreated = yearCreated;
}
string Books::getTitle() { 
  return title;
}
int Books::GetYearCreated() {
  return yearCreated;
}
void Books::PrintTitle() { 
  cout << "Title: " << title << ", " << yearCreated << endl;
  bookMaker.PrintInfo();
}


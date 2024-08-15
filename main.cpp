#include <cmath>
#include <cctype>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include "Author.h"
#include "Books.h"

using namespace std;
bool haveKey = false;
bool catcherInTheRye = false;
bool theBluestEyes = false;
bool theGreatGatsby = false;
bool boysWhoCry = false;
bool mansionNotComplete = true;
bool neko = true;
void help();
void DogHouseEvent();
void inventtory();
void SouthQuest();
void north();
void NorthEscape();
void DogHouse();
void south();
void PrintStartingPoint();
void Mansion();
void MansionEvent();
void west();
void endSequence();
bool mansion = false;
bool doghouse = false;
int bookCount = 0;
vector<string> inventory;
vector<string> bookBag;
string name;
int startingPoint = 0;
bool goldCoin = false;
string action;
void LostFather();
bool NotHatedByKid = true;
bool haveTorch = false;
bool wentWest = false;

bool isDigits(const string& input) {
  for (char digit : input) {
    if (!isdigit(digit)) {
    return false;
    }
  }
return true;
}
void LostFather() {
  cout << "You talk to that homeless man who was indeed a father until he for some reason got separated." << endl;
  cout << "You decided to take him to the son who lost his father." << endl;
  cout << "You take that person to the son and he seems to be upset."<< endl;
  cout << "That homeless man is not his father but a complete stranger to him." << endl;
  cout << "The kid got angry that he threw stuffs at you." << endl;
  cout << "By luck, you got both The Catcher in the Rye and The Bluest Eyes from him throwing stuffs at you." << endl;
  bookBag.push_back("The Catcher in the Rye");
  bookBag.push_back("The Bluest Eyes");
  catcherInTheRye = true;
  theBluestEyes = true;
  bookCount += 2;
  cout << "You got both The Catcher in the Rye and The Bluest Eyes." << endl;
  NotHatedByKid = false;
  PrintStartingPoint();
  
}

void SouthQuest() {
  cout << "The only clue you have is that he last went to the grocery store years ago to buy some milk." << endl;
  cout << "You can ask a staff, or be an absolute karen and ask for the manager. Or you could talk to people." << endl;
  cin >> action;
  while (action != "staff" || action != "manager" || action != "people") {
  if (action == "staff") {
    cout << "You decided to pull the Big Smoke Order prank which they find it hilarious that they handed you a key for any car." << endl;
    cout << "You received a car key." << endl << endl;
    inventory.push_back("Car Key");
    haveKey = true;
    cout << "The staff has no clue about the missing father." << endl;
    cout << "The manager arrived and couldn't help you with the investigation as the manager had just started yesterday." << endl;
    cout << "You decided to leave and stumbled upon a homeless man who claims to be looking for his son." << endl;
    LostFather();
    break;
  }
  else if (action == "manager") {
    cout << "You talk to the manager and the manager has no clue about the missing father as the manager had just started yesterday.";
    cout << "You decided to leave and stumbled upon a homeless man who claims to be looking for his son." << endl;
    LostFather();
    break;
  }
  else if (action == "people") {
    cout << "You talk to people around and most of them don't have any clues about the father's disappearance." << endl;
    cout << "One person points tells you about a homeless man nearby who claims to be looking for his son." << endl;
    cout << "You decided to leave and stumbled upon a homeless man who claims to be looking for his son." << endl;
    LostFather();
    break;
  }
    else if (action == "inventory") {
      inventtory();
      cin >> action;
    }
    else if (action == "help") {
      help();
      cin >> action;
    }
  else {
    cout << "huh?" << endl;
    cin >> action;
  }
    
  }
  
  
}

void south() {
  if (NotHatedByKid) {
  cout << "You ask around if anyone seen any of the " << 4 - bookCount << " books you're looking for." << endl;
  cout << "A fatherless person said that he have The Catcher in the Rye which is the last thing his father gave him before his sudden disappearance. " << endl;
   cout << "He might be willing to give it to you if you can find his missing dad." << endl;
  cout << "Would you like to look for his missing father?" << endl;
  cin >> action;

  while (action != "y" || action != "n" || action != "yes" || action != "no") {
    if (action == "y" || action == "yes") {
    cout << "You decided to look for his missing dad." << endl;
      SouthQuest();
      break;
    }
    else if (action == "n" || action == "no") {
      cout << "You decided not to help him." << endl;
      PrintStartingPoint();
      break;
    }
      else if (action == "inventory") {
      inventtory();
      cin >> action;
    }
    else if (action == "help") {
      help();
      cin >> action;
    }
    else {
      cout << "huh?" << endl;
      cin >> action;
    }

  }
  }
  else {
    cout << "That kid wouldn't talk to you as he's still upset about what just happened." << endl;
    cout << "It's best that you don't try to talk to him." << endl;
    PrintStartingPoint();
  }
}


void MansionEvent() {
  vector<int> coin(3);
  string guess;
  bool luck = false;
  cout << "You stumbled upon a magician who asks you for your lucky number."
       << endl;
  string number;
  int i = 0;
  cin >> number;
  while (!luck) {
    
    if (isDigits(number)) {
      luck = true;
      
      break;
    }
      else if (number == "inventory") {
      inventtory();
      cin >> number;
    }
    else if (number == "help") {
      help();
      cin >> number;
    }
    else {
      cout << "huh?" << endl;
      cin >> number;
    }
  }
  int numo = rand();
  srand(numo);
  int random;
  cout << "That magician shows you a gold coin that you could win." << endl;
  cout << "Only if you can guess heads or tails correctly for three times in a "
          "row."
       << endl;
  vector<string> factor(3);

  int win = 0;
  while (win < 3) {
    bool isNumber = false;

      cout << "Pick heads or tails: " << endl;
      cout << "Type 0 for heads, type 1 for tails." << endl;
      cin >> guess;
      if(isDigits(guess)) {
        isNumber = true;
      }
      if (isNumber) {
        int yourGuess = rand() % 2;
      
      if (yourGuess == rand() % 2) {
        cout << "Correct." << endl;
        ++win;
        if (win == 3) {
      break;
    }
      } else {
        cout << "Too bad! You'll have to start again from the beginning."
             << endl;
        i = 0;
        win = 0;
      }
      }
    else {
      cout << "Invalid! Put in another lucky number:" << endl;
      cin >> guess;
    }
    
    
  }
  cout << "You got some gold coin!" << endl;
  inventory.push_back("Gold Coin");
  goldCoin = true;
  mansionNotComplete = false;
}

void Mansion() {
  if (mansionNotComplete) {
    MansionEvent();
    north();
  }
  else {
    cout << "The magician is nowhere to be seen." << endl;
    cout << "As you walked around the mansion, all you can see is very empty space." << endl;
    cout << "It will be wise to turn back as you'll just waste your time here." << endl;
  
  cin >> action;

  while (action != "back") {
    
  
  if (action == "back") {
  break;
    
    
  }
  else if (action == "inventory") {
    inventtory();
    cin >> action;
  }
    
    else if (action == "help") {
      help();
      cin >> action;
    }
  else {
    cout << "huh?" << endl;
    cin >> action;
  }
    
  }
  cout << "Exiting mansion." << endl;
    north();
  }
}
void NorthEscape() {
  string justDoIt;
  cout << "You happen to stumble upon a car." << endl;
  cin >> justDoIt;

  while (justDoIt != "back") {

    if (justDoIt == "car") {
      if (haveKey) {
        cout << "You drove the car back home." << endl;
        
          cout << "You ended up reaching home safe and sound." << endl;
          cout << "Congratulations, " << name << " you have won this game." << endl;
        break;
      }
      else {
        cout << "You don't have the keys for that." << endl;
        cin >> justDoIt;
      }
    }
    else if (justDoIt == "back") {
      break;
      
    }
    else if (justDoIt == "inventory") {
      inventtory();
      cin >> justDoIt;
    }
      
    else if (justDoIt == "help") {
      help();
      cin >> justDoIt;
    }
    else {
      cout << "huh?" << endl;
      cin >> justDoIt;
    }
    
  }
  if (justDoIt == "back") {
    PrintStartingPoint();
  }
  
}
void DogHouse() {
  if (!theGreatGatsby) {
    DogHouseEvent();
  }
  else {
    cout << "You can see that kid happily writing his report." << endl;
    cout << "It's best not to bother him as you go back to where you came from." << endl;
    north();
  }
}
void DogHouseEvent() {
  string choice;

  cout << "That man is called Madao by a kid who seems to be the owner."
       << endl;
  cout << "The kid is writing an observation report on the person he refers to "
          "as Madao."
       << endl;
  cout << "That kid used to work on his report on a gold coin until it went "
          "missing."
       << endl;
  if (goldCoin) {
    cout << "You have a gold coin and you gave one to him." << endl;
    cout << "He continued his observation report on the gold coin and gave you "
            "Madao as a pet."
         << endl;
    cout << "Inside Madao's house, you found The Great Gatsby." << endl;
    bookBag.push_back("The Great Gatsby");
    theGreatGatsby = true;
    cout << "The Great Gatsby is added to your inventory." << endl << endl;
    ++bookCount;
    if (bookCount == 4) {
      cout << "Congratulations, you have found all four books." << endl;
      cout << "Now all you have to do is... GET OUT WHILE YOU STILL CAN!!!!!"
           << endl;
      NorthEscape();
    }
    else {
      
      
      cin >> choice;
      while (choice != "back") {
        
      
      if (choice == "back") {
        if (neko) {
        cout << "You happen to witness something scribbled on the wall."
             << endl;
        cout << "   __________________    " << endl;
        cout << "  /     ___  ___     \\ " << endl;
        cout << " /   __/   \\/   \\__   \\" << endl;
        cout << "|   / | o ||  o |  \\   |" << endl;
        cout << "|  /  \\__/  \\__/    \\  |" << endl;
        cout << "| |       \\_/        | |" << endl;
        cout << "| \\   _____|____    /  |" << endl;
        cout << " \\ \\  \\________/   /  /" << endl;
        cout << "  \\_\\_____________/__/" << endl;
        cout << "Someone must've forgot to draw his whiskers." << endl;
        neko = false;
      }
        break;
      }
        else if (choice == "inventory") {
          inventtory();
          cin >> choice;
        }
          else if (choice == "help") {
            help();
            cin >> choice;
          }
        else {
          cout << "huh?" << endl;
          cin >> choice;
        }
    }
      north();
    }

  }
  else {
    cout << "Looks like you might have a good fortune coming for you if you "
            "can find a gold coin."
         << endl;
    cin >> choice;
    while (choice != "back") {
    if (choice == "back") {
      if (neko) {
        cout << "You happen to witness something scribbled on the wall."
             << endl;
        cout << "   __________________    " << endl;
        cout << "  /     ___  ___     \\ " << endl;
        cout << " /   __/   \\/   \\__   \\" << endl;
        cout << "|   / | o ||  o |  \\   |" << endl;
        cout << "|  /  \\__/  \\__/    \\  |" << endl;
        cout << "| |       \\_/        | |" << endl;
        cout << "| \\   _____|____    /  |" << endl;
        cout << " \\ \\  \\________/   /  /" << endl;
        cout << "  \\_\\_____________/__/" << endl;
        cout << "Someone must've forgot to draw his whiskers." << endl;
        neko = false;
      }
      break;
    }
      else if (choice == "inventory") {
          inventtory();
          cin >> choice;
        }
          else if (choice == "help") {
            help();
            cin >> choice;
          }
        else {
          cout << "huh?" << endl;
          cin >> choice;
        }
    }
    north();
  }
}

void north() {
  string appr;
  int location = 0;
  cout << "As you walk north, you can see a mansion that happens to be the "
          "most mansion out of many other mansions."
       << endl;
  cout << "You could also see a man living in a literal doghouse." << endl;
  cin >> appr;

   while (appr != "doghouse" || appr != "mansion" || appr != "back")
  if (appr == "doghouse") {
    DogHouse();
    break;
  } else if (appr == "mansion") {
    Mansion();
    break;
  }
  else if (appr == "back") {
    PrintStartingPoint();
    break;
  }
  else if (appr == "inventory") {
    inventtory();
    cin >> appr;
  }
    else if (appr == "help") {
      help();
      cin >> appr;
    }
   else {
     cout << "huh?" << endl;
     cin >> appr;
   }
}
void east() {
  cout << endl;
  string decision;
  if (!haveTorch) {
  cout << "You embark in a direction in what seems like it is east and "
          "suddenly everything around you falls into darkness.\nHowever you "
          "see a place in front of with a bit of light..."
       << endl;
  cout << endl
       << "You walk to the light to find it to be a torch. Do you want to pick "
          "it up (y/n)?"
       << endl;
  cin >> decision;
  while (true) {
    if (decision == "y" || decision == "n" || decision == "yes" || decision == "no") {
      break;
    }
    cout << "Invalid Input\nDo you want to pick up the torch (y/n)?" << endl;
    cin >> decision;
  }
  if (decision == "n" || decision == "no") {
    cout << "The darkness around you makes you go crazy and you lose your only "
            "sense of direction and are eternally lost in the darkness."
         << endl
         << endl;
    cout << "Loading last save..." << endl << endl;
    PrintStartingPoint();
  } else {
    string num1;
    string num2;
    string num3;
    string num4;
    cout << endl << "Picked up torch!" << endl;
    cout << "You continue striaght seeing the following numbers "
            "100,99,13,27.\n As you continue in your way, a door is before you "
            "with a numberpad on its right"
         << endl;
    cout << "You decide to enter the numbers you saw from before. Enter the "
            "first number."
         << endl;

    cin >> num1;
    while (true) {
      
      if (num1 == "100") {  
        break;
      }
      else { 
      cout << "Incorrect number! Maybe you will get it this time." << endl;
        cin >> num1;
      }
      
    }
    if (num1 == "100") {
      cout << "CORRECT! One of the locks have been lifted. Only 3 more to go. "
              "Enter the second number."
           << endl;
    }

    cin >> num2;
    while (num2 != "99") {
      cout << "Incorrect number! Try to enter the second number again" << endl;
      cin >> num2;
    }
    if (num2 == "99") {
      cout << "CORRECT! Another lock has been lifted. Only 2 more to go. Enter "
              "the third number."
           << endl;
    }

    cin >> num3;
    while (num3 != "13") {
      cout << "Incorrect number! Try to enter the third number again" << endl;
      cin >> num3;
    }
    if (num3 == "13") {
      cout << "CORRECT! Yet another lock has been lifted. Only 1 more to go. "
              "Enter the final number."
           << endl;
    }

    cin >> num4;
    while (num4 != "27") {
      cout << "It is the final number. You must not get it wrong this time"
           << endl;
      cin >> num4;
    }
    if (num4 == "27") {
      cout << "Congratulations! You have been given the Torch of Darkness. "
              "Perhaps you can bring it to use in the future"
           << endl
           << endl;
      inventory.push_back("Torch of Darkness");
      haveTorch = true;
      cout << "Sucessfully added Torch of Darkness to inventory." << endl;
      cout << "Darkness leaves you and you find yourself back where you came "
              "from"
           << endl
           << endl;
      PrintStartingPoint();
    }
    }
  }
  else {
    cout << "You walk around here this time with a torch." << endl;
    cout << "There is nothing here." << endl;
    PrintStartingPoint();
  }
}
void west() {
  if (wentWest) { 
  cout << "You already went this way. There is nothing else to find at this moment" << endl;
    PrintStartingPoint();
  }
  else {
  string inWest;
  wentWest = true;
  cout << endl << "So you wish to travel west huh?" << endl;
  cout << "Time is of the essense. Hurry!!!" << endl;
  cout << "In the west you find a village with rivers flowing and a waterfall" << endl;
  cin >> inWest;
  while (true) { 
    if (inWest == "village") { 
      cout << "You enter the village and ask the villagers about the lost books" << endl;
      cout << "\"In order to gain knowledge, one must enter the waterfall.\" " << endl;
      cout << "You go back and have the choice to go to the village, river, or waterfall." << endl;
      cin >> inWest;
    }
    else if ((inWest == "rivers") || (inWest == "river")) { 
      cout << "You head to the river only to find nothing. The best option is to go back" << endl;
      cout << "You go back and have the choice to go to the village, river, or waterfall." << endl;
      cin >> inWest;
      
    }
    else if (inWest == "waterfall") { 
      string freedom;
      cout << "You enter the waterfall." << endl;
      cout << "You hear a voice speaking to you.\"So you are in pursuit of knowledge, huh? But are you worthy\"\n " << endl;
      cout << "The ground cracks open and you get swallowed into the Earth" << endl << "You find yourself conscious and you hear crying. A boy is standing in a cage." << endl;
      cout << "Do you wish to free him? (y/n)" << endl;
      while (true) {
        cin >> freedom;
        if (freedom == "n" || freedom == "no") { 
          cout << "\"Are you really going to leave me here, " << name <<"?\"\n(Rethink your decision again) Do you wish to free him? (y/n)" << endl;
        }
        else if (freedom == "y" || freedom == "yes") { 
          cout << "The boy never stops crying but you hold each others hands and go on your way" << endl;
          break;
        }
        else { 
          cout << "what" << endl;
        }
      }
      break;
    }
    else if (inWest == "inventory") {
      inventtory();
      cin >> inWest;
    }
      else if (inWest == "help") {
      help();
      cin >> inWest;
    }
    else { 
    cout << "Huh" << endl;
    cin >> inWest;}
  }
  cout << "After some time walking with the boy who is still crying, the boy suddenly starts running and you lose sight of him. You yell out \n\"Why are you running?\"" << endl;
  cout << "You chase him into a room but you notice that the crying has stopped" << endl;
  cout << "A book is placed on a podium and you hear the voice from before" << endl;
  cout << "\"YOU ARE WORTHY. Accept the book with determination!\"" << endl;
  cout << "Acquired Boys Who Cry" << endl;
  bookBag.push_back("Boys Who Cry");
  boysWhoCry = true;
  bookCount++;
  cout << "Sucessfully added to inventory" << endl;
  cout << "You decide to immediately return to your original location.\n" << endl << endl;
  
  PrintStartingPoint(); 
}
}


void PrintStartingPoint() {

  string daway;
  if (bookCount == 4) { 
    ++bookCount;
    endSequence();
  } 
  else {
  if (startingPoint == 0) {
    cout << "You just got out from the train station." << endl;
    ++startingPoint;
  }
  cout << "There are four direction in your path." << endl;
  cout << "You can go north, east, south, or west." << endl;
  if (bookCount >= 4) {
    cout << "Or you can go to the train station." << endl;
  }
  cout << "Pick a direction you wanna go to." << endl;
  cout << "Type n/e/w/s?" << endl;

  cin >> daway;
  while (daway != "n" || daway != "e" || daway != "w" || daway != "s" || daway != "north" || daway != "east" || daway != "west" || daway != "south") {
    if (daway == "n" || daway == "north") {
      north();
      break;
    } else if (daway == "e" || daway == "east") {
      east();
      break;

    } else if (daway == "w" || daway == "west") {
      west();
      break;
    } else if (daway == "s" || daway == "south") {
      south();
      break;
      
    } 
      else if (daway == "inventory") {
        inventtory();
        cin >> daway;
      }
      else if (daway == "help") {
        help();
        cin >> daway;
      }
      else if (daway == "train") {
        if (theGreatGatsby && theBluestEyes && catcherInTheRye && boysWhoCry) {
          cout << "You decided to take the train back home." << endl;
          cout << "You reached home safe and sound." << endl;
          cout << "Congratulations, " << name << " you have won this game." << endl;
          break;
        }
        else {
          cout << "huh?" << endl;
          cin >> daway;
        }
      }
      else {
      cout << "huh?" << endl;
      cin >> daway;
    }
  }
  }
}

void PrintIntro() {

  cout << "Welcome, you have just moved in from..." << endl;
  cout << "Do I even care where you came from to Crazy Noisy Bizarre Town."
       << endl;
  cout << "Your mission is to look for your someone special's four favorite "
          "books!"
       << endl;
  cout << "You have to look for The Catcher in the Rye, The Bluest Eyes,"
       << endl;
  cout << "The Great Gatsby, and Boys Who Cry." << endl;
  cout << "Once you found all those four books, all you have to do is..."
       << endl;
  cout << "GET OUT WHILE YOU STILL CAN!!!" << endl;
  cout << "Shall we start now?" << endl << endl;
}

void inventtory() {
  int i;
  Author author;
  Books book;
  string goBack;
  cout << "Inventory display:" << endl;
  for (i = 0; i < inventory.size(); ++i) {
    cout << inventory.at(i) << endl;
  }
  cout << endl;
  cout << "Book bag display:" << endl;
  for (i = 0; i < bookBag.size(); ++i) {
    cout << bookBag.at(i) << endl;
  }
  cout << endl;
  cout << "Type in book# to display book information." << endl << endl;
  cin >> goBack;
  while (goBack != "back") {
  if (goBack == "back") {
    
    break;
  }
  else if (goBack == "book4") {
    if (theGreatGatsby)  {
      author = Author("F. Scott Fitzgerald", 1896, 1940);
      book = Books("The Great Gatsby", 1925, author);
      book.PrintTitle();
      cin >> goBack;
    }
    else {
      cout << "huh?" << endl;
      cin >> goBack;
    }
    
  }
    else if (goBack == "help") {
      help();
      cin >> goBack;
    }
  else if (goBack == "book3") {
      if (catcherInTheRye) {
        author = Author("J. D. Salinger", 1919, 2010);
        book = Books("The Catcher in the Rye", 1951, author); 
        book.PrintTitle();
        cin >> goBack;
      }
      else {
        cout << "huh?" << endl;
        cin >> goBack;
      }
  }
  else if (goBack == "book1") {
      if (theBluestEyes) {
        author = Author("Toni Morrison", 1931, 2019);
        book = Books("The Bluest Eyes", 1970, author); 
        book.PrintTitle();
        cin >> goBack;        
      }
      else {
        cout << "huh?" << endl;
        cin >> goBack;
      }
  }
  else if (goBack == "book2") {
      if (boysWhoCry) {
        author = Author("Stephen Hillenburg", 1961, 2018);
        book = Books("Boys Who Cry", 2006, author); 
        book.PrintTitle();
        cin >> goBack;
      }
      else {
        cout << "huh?" << endl;
        cin >> goBack;
      }
  }
  else {
    cout << "huh?" << endl;
    cin >> goBack;
  }
    
  }
  cout << "Exiting inventory" << endl;
  
}
void endSequence() { 
  cout << "Congratulations, you have collected all four books you've been looking for." << endl;
  cout << "Now all you have to do is... GET OUT WHILE YOU STILL CAN!!!" << endl;
  PrintStartingPoint();
}

void help() {
  cout << "Try typing whatever word can you see." << endl;
  cout << "Try typing inventory to check the inventory." << endl;
  cout << "Type back to go back to where you came from." << endl;
}
int main() {
  
  string intro;
  cout << "Created by Giorgio Wirawan and Mohammed A. Al-Muqsit" << endl << endl;
  cout << "What's your name?" << endl;
  cin >> name;
  cout << "Do you want an introduction?" << endl;
  cin >> intro;
  while (intro != "yes" || intro != "no" || intro != "y" || intro != "n") {

    if (intro == "yes" || intro == "y") {

      PrintIntro();

      PrintStartingPoint();
       break;
    } else if (intro == "no" || intro == "n") {

      PrintStartingPoint();
       break;
    } else {
      cout << "huh?" << endl;
      cin >> intro;
    }
  }
}

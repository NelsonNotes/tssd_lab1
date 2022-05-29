#include <iostream>
#include <string>
#include "List.h"

using namespace std;

int main() {
  List *list = new List("Deus vult.");
  list->add("The quick brown fox jumps over the lazy dog.");
  list->add("Timbs for my hooligans in Brooklyn.");
  list->add("Ave Maria.");
  list->add("So now where are you?");
  list->add("Were you lonely too?");
  list->add("Drawning like a fish and music only thing i knew.");
  list->add("How can I back to life if my memories still abused");
  list->add("If nobody tells me what I really need to do?");
  list->add("Relax and take notes.");
  list->add("Why merge-sort is better than quicksort for linked lists?");
  list->add("Why is crystal anisotropic?");
  list->add("Alabama is a state in the United States.");
  list->add("Nevermind, I will find.");
  list->push("Mix a little bit of this with a little bit of that.");
  list->push("We gon be alright.");
  list->push("Best Beer Halls and Beer Gardens in Munich.");
  list->push("Zimbabwe.");
  list->push("What is love?");
  list->push("Last Christmas, I gave you my heart.");
  list->push("But the very next day, you gave it away.");
  list->push("This year, to save me from tears.");
  list->push("I will give it to someone special.");
  list->push("All the weather outside is frigtful.");
  list->push("But the fire is so delightful.");
  list->push("And since we have no place to go.");
  list->push("Let it snow, let it snow, let it snow.");
  list->push("Such a lonely day.");
  list->push("And it is mine.");
  list->push("The most loneliest day of my life.");
  list->push("What a lonely day.");
  list->push("Should be banned.");
  list->push("It is a day that i can stand.");
  list->push("Someone like you.");
  list->push("Never gonna give you up.");
  list->push("Never gonna let you down.");
  list->push("Never gonna run around and desert you.");
  list->push("Never gonna make you cry.");
  list->push("Never gonna say goodbye.");
  list->push("Never gonna tell a lie and hurt you.");
  cout << "---------------------------------------------------------" << endl;
  cout << "Source list:" << endl;
  list->show();
  cout << "---------------------------------------------------------" << endl;
  int found = list->find("Zimbabwe.");
  cout << "find(\"Zimbabwe.\") returns " << found << endl;
  cout << "---------------------------------------------------------" << endl;
  cout << "Let's delete it and check" << endl;
  list->del(found);
  cout << "Deleted " << found << " element." << endl << endl;
  list->show();
  cout << "---------------------------------------------------------" << endl;
  cout << "If we try find(\"No matter what.\"), it returns: " << list->find("No matter what.") << endl;
  cout << "---------------------------------------------------------" << endl;
  cout << "Deleting first and last element and get: " << endl;
  list->del(0);
  list->del(5);
  cout << "Deleted 0 and 5 element." << endl << endl;
  list->show();
  cout << "---------------------------------------------------------" << endl;
  cout << "Let's try merge-sort on our linked list: " << endl;
  list->sort();
  cout << "List has been sorted." << endl << endl;
  list->show();
  cout << "---------------------------------------------------------" << endl;
  cout << "Now deleting list: " << endl;
  delete list;
  cout << "deleted" << endl << endl;
  return 0;
}
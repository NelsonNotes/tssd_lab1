#include <iostream>
#include <string>
#include "NestList.h"

using namespace std;

int main() {
  NestList *list = new NestList("Deus vult.");
  list->add("The quick brown fox jumps over the lazy dog.");
  list->add("Ave Maria.");
  list->add("Why merge-sort is better than quicksort for linked lists?");
  list->add("Why is crystal anisotropic?");
  list->add("Alabama is a state in the United States.");
  list->push("Best Beer Halls and Beer Gardens in Munich.");
  list->push("Zimbabwe.");
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
  cout << "Let's try merge-sort on our nested list: " << endl;
  list->sort();
  cout << "List has been sorted." << endl << endl;
  list->show();
  cout << "---------------------------------------------------------" << endl;
  cout << "Now deleting nested list: " << endl;
  delete list;
  cout << "deleted" << endl << endl;
  return 0;
}
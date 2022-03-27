#include <iostream>
#include <string>
#include "List.h"

using namespace std;

int main() {
  List *list = new List("a");
  list->add("b");
  list->add("c");
  list->add("d");
  list->add("e");
  list->add("f");
  list->push("z");
  list->show();
  int found = list->find("d");
  cout << found << endl;
  list->del(found);
  list->show();
  list->del(5);  
  list->show();
  cout << list->find("f") << endl;
  list->del(0);
  list->show();
  delete list;
  return 0;
}
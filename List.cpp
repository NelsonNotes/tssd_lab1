#include <iostream>
#include <string>
#include "List.h"

using namespace std;

List::List(string _text) {
  head = new Node;
  head->text = _text;
  head->next = nullptr;
}

List::~List() {
  Node *cur;
  while (head) {
    cur = head->next;
    delete head;
    head = cur;
  }
}

void List::push(string _text) {
  Node *cur = new Node;
  cur->text = _text;
  cur->next = head;
  head = cur;
}

void List::add(string _text) {
  Node *cur = head;
  while (cur->next) {
    cur = cur->next;
  }
  cur->next = new Node;
  cur = cur->next;
  cur->next = nullptr;
  cur->text = _text;
}

void List::del(int num) {
  Node *cur = head;
  Node *hook = nullptr;
  if (num == 0) {
    head = cur->next;
    delete cur;
    return;
  }
  for (int i = 0; i < num-1; i++) {
    cur = cur->next;
  }
  if (cur->next->next) {
    hook = cur->next->next;
  } else {
    hook = nullptr;
  }
  delete cur->next;
  cur->next = hook;
}

int List::find(string _text) {
  Node *cur = head;
  int cnt = 0;
  while (cur) {
    if (cur->text == _text) {
      return cnt;
    }
    cur = cur->next;
    cnt++;
  }
  return -1;
}

void List::show() {
  Node *cur = head;
  cout << "Head is: '" << head->text << "'" << endl;
  while (cur) {
    cout << cur->text << " ";
    cur = cur->next;
  }
  cout << endl;
}

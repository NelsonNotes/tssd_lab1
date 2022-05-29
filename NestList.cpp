#include <iostream>
#include <string>
#include "List.h"
#include "NestList.h"

using namespace std;


int get_nest_idx_by_letter(char letter) {
  letter = tolower(letter);
  return (int)letter - 97;
}


NestList::NestList() {
  for (int i = 0; i < 26; i++) {
    nest_nodes[i] = new List();
  }
}

NestList::NestList(string _text) {
  int nest = get_nest_idx_by_letter(_text[0]);
  for (int i = 0; i < 26; i++) {
    if (i == nest) {
      nest_nodes[i] = new List(_text);
    } else {
      nest_nodes[i] = new List();
    }
  }
}

NestList::~NestList() {
  cout << "Implicit call of ~NestList() destructor" << endl;
  for (int i = 0; i < 26; i++) {
    delete nest_nodes[i];
  }
}

void NestList::push(string _text) {
  int nest = get_nest_idx_by_letter(_text[0]); 
  nest_nodes[nest]->push(_text);
}

void NestList::add(string _text) {
  int nest = get_nest_idx_by_letter(_text[0]);
  nest_nodes[nest]->add(_text);
}

void NestList::del(int position) {
  int cur_list_length;
  for (int i = 0; i < 26; i++) {
    cur_list_length = nest_nodes[i]->length();
    if (position >= cur_list_length) {
      position -= cur_list_length;
    } else {
      nest_nodes[i]->del(position);
      return;
    }
  }
}

void NestList::del_by_val(string _text) {
  int nest = get_nest_idx_by_letter(_text[0]);
  nest_nodes[nest]->del_by_val(_text);
}

int NestList::find(string _text) {
  int base = 0;
  int move;
  int nest = get_nest_idx_by_letter(_text[0]);
  for (int i = 0; i <= nest; i++) {
    base += nest_nodes[i]->length();
  }
  move = nest_nodes[nest]->find(_text);
  return move == -1 ? move : base + move - 1;
}

void NestList::show() {
  int cnt = 0;
  for (int i = 0; i < 26; i++) {
    if (nest_nodes[i]->length()) {
      cout << "Current nest is: " << i << endl;
      nest_nodes[i]->show();
      cnt++;
    } 
  }
  if (!cnt) {
    cout << "Nested list is empty" << endl;
  }
}

void NestList::sort() {
  for (int i = 0; i < 26; i++) {
    if (nest_nodes[i]) {
      nest_nodes[i]->sort();
    } 
  }
}
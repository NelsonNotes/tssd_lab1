#pragma once
#ifndef LIST_H
#define LIST_H

using namespace std;

  struct Node {
    string text;
    Node *next;
  };

class List {
  Node *head;
  int list_length = 0;

public:
  List();
  List(string);
  ~List();
  void push(string);
  void add(string);
  void del(int);
  void del_by_val(string);
  int find(string);
  void show();
  void sort();
  int length();
  // int length(bool);
};
#endif // LIST_H
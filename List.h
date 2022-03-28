#pragma once
#ifndef LIST_H
#define LIST_H

using namespace std;

class List {
  struct Node {
    string text;
    Node *next;
  };
  Node *head;

public:
  List(string);
  ~List();
  void push(string);
  void add(string);
  void del(int);
  int find(string);
  void show();
  void sort();
  bool cmp(Node *, Node *);
};
#endif // LIST_H
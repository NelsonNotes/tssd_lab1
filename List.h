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
  List(string _text);
  ~List();
  void push(string _text);
  void add(string _text);
  void del(int num);
  int find(string _text);
  void show();
};
#endif // LIST_H
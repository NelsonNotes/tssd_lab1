#pragma once
#ifndef NESTLIST_H
#define NESTLIST_H
#include "List.h"


using namespace std;

class NestList {
  List *nest_nodes[26];

public:
  NestList();
  NestList(string);
  ~NestList();
  void push(string);
  void add(string);
  void del(int);
  void del_by_val(string);
  int find(string);
  void show();
  void sort();
  bool cmp(Node *, Node *);
};
#endif // NESTLIST_H
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
  if (!head) {
    cout << "List is empty";
    return;
  }
  cout << "Head is: '" << head->text << "'" << endl;
  while (cur) {
    cout << cur->text << endl;
    cur = cur->next;
  }
  cout << endl;
}

bool List::cmp(Node *p, Node *q) {
  return p->text <= q->text;
}

void List::sort() {               // merge sort
  Node *p, *q, *e, *tail;
  Node *list = head;
  int insize, nmerges, psize, qsize, i;
  /*
   * Silly special case: if `list' was passed in as NULL, return
   * NULL immediately.
   */
  if (!list)
	  return;

  insize = 1;

  while (1) {
    p = list;
    list = NULL;
    tail = NULL;

    nmerges = 0;  /* count number of merges we do in this pass */

    while (p) {
      nmerges++;  /* there exists a merge to be done */
                  /* step `insize' places along from p */
      q = p;
      psize = 0;
      for (i = 0; i < insize; i++) {
        psize++;
		    q = q->next;
        if (!q) break;
      }

      /* if q hasn't fallen off end, we have two lists to merge */
      qsize = insize;

      /* now we have two lists; merge them */
      while (psize > 0 || (qsize > 0 && q)) {
        /* decide whether next element of merge comes from p or q */
        if (psize == 0) {
		      /* p is empty; e must come from q. */
		      e = q; q = q->next; qsize--;
		    } else if (qsize == 0 || !q) {
		      /* q is empty; e must come from p. */
		      e = p; p = p->next; psize--;
		    } else if (cmp(p,q)) {
		      /* First element of p is lower (or same);
		       * e must come from p. */
		      e = p; p = p->next; psize--;
		    } else {
		      /* First element of q is lower; e must come from q. */
		      e = q; q = q->next; qsize--;
		    }
                  /* add the next element to the merged list */
		    if (tail) {
		      tail->next = e;
		    } else {
		      list = e;
		    }
		    tail = e;
      }

      /* now p has stepped `insize' places along, and q has too */
      p = q;
    }
	  tail->next = NULL;

    /* If we have done only one merge, we're finished. */
    if (nmerges <= 1) {   /* allow for nmerges==0, the empty list case */
      head = list;
      return;
    }

    /* Otherwise repeat, merging lists twice the size */
    insize *= 2;
  }
}
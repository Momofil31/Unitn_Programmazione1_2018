#include <iostream>
#include "stack.h"

using namespace std;

retval empty(const stack &s) {
  return (s == NULL ? TRUE : FALSE);
}

void init(stack &s) {
  s = NULL;
}

void deinit(stack &s) {
  while (empty(s) == FALSE)
    pop(s);
}

void push(stack &s, int val) {
  node * tmp = new node;
  tmp->val = val;
  tmp->next = s;
  s = tmp;
}

retval pop(stack &s) {
  retval res = TRUE;
  if (empty(s))
    res = FALSE;
  else {
    node * tmp = s;
    s = s->next;
    delete tmp;
  }
  return res;
}

retval top(const stack &s, int &result) {
  retval res = TRUE;
  if (empty(s))
    res = FALSE;
  else {
    result = s->val;
  }
  return res;
}

void   print  (const stack &s) {
  node * tmp = s;
  while (tmp != NULL) {
    cout << tmp->val << " ";
    tmp = tmp->next;
  }
  cout << endl;
  delete tmp;
}

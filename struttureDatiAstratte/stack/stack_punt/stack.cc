#include <iostream>
#include "stack.h"
using namespace std;


static bool isEmpty(const stack &s) {
  return s == NULL;
}


void init(stack &s) {
  s = NULL;
}

void deinit(stack &s) {
  while (!isEmpty(s)) {
    pop(s);
  }
}

bool push(stack &s, float val) {
  bool res = true;
  node * tmp = new (nothrow) node;
  if (tmp == NULL) {
    res = false;
  } else {
    tmp->value = val;
    tmp->next = s;
    s = tmp;
  }
  return res;
}

bool pop(stack &s) {
  bool res = true;
  if (isEmpty(s)) {
    res = false;
  } else {
    node * tmp = s;
    s = tmp->next;
    delete tmp;
  }
  return res;
}

bool top(const stack &s, float &out) {
  bool res = true;
  if (isEmpty(s)) {
    res = false;
  } else {
    out = s->value;
  }
  return res;
}

void print(const stack &s) {
  node * tmp = s;
  while (tmp != NULL) {
    cout << tmp->value << endl;
    tmp = tmp->next;
  }
  delete tmp;
}

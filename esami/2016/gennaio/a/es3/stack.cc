#include "stack.h"
#include <iostream>

using namespace std;

static bool isFull(const stack &s) {
  return s.index == s.dim;
}

static bool isEmpty(const stack &s) {
  return s.index == 0;
}

void init(stack &s, int maxdim) {
  s.dim = maxdim;
  s.index = 0;
  s.elem = new double [s.dim];
}

void deinit(stack &s) {
  delete [] s.elem;
}

bool push(stack &s, double n) {
  bool res = true;
  if (isFull(s)){
    res = false;
  } else {
    s.elem[s.index] = n;
    s.index++;
  }
    return res;
}

bool pop(stack &s) {
  bool res = true;
  if (isEmpty(s)){
    res = false;
  } else {
    s.index--;
  }
  return res;
}

bool top(const stack &s, float &out) {
  bool res = true;
  if (isEmpty(s)){
    res = false;
  } else {
    out = s.elem[s.index-1];
  }
  return res;
}

void print(const stack &s) {
  for (int i=0; i<s.index; i++) {
    cout << s.elem[i] << endl;
  }
}

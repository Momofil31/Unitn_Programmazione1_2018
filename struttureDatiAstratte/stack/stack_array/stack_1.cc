#include <iostream>
#include "stack.h"

using namespace std;

static bool isFull(const stack &s) {
  return s.indice == s.dim;
}

static bool isEmpty(const stack &s) {
  return s.indice == 0;
}

void init(stack &s, int maxDim) {
  s.dim = maxDim;
  s.indice = 0;
  s.value = new float[maxDim];
}

void deinit(stack &s) {
  delete [] s.value;
}

bool push(stack &s, float value) {
  bool res = true;
  if (isFull(s)) {
    res = false;
  } else {
    s.value[s.indice] = value;
    s.indice++;
  }
  return res;
}

bool pop(stack &s) {
  bool res = true;
  if (isEmpty(s)) {
    res = false;
  } else {
    s.indice--;
  }
  return res;
}

bool top(const stack &s, float &out) {
  bool res = true;
  if (isEmpty(s)) {
    res = false;
  } else {
    out = s.value[s.indice-1];
  }
  return res;
}

void print(const stack &s) {
  for (int i=0; i<s.indice; i++){
    cout << s.value[i] << endl;
  }
}

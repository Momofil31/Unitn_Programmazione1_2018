#include "albero.h"

#include <iostream>

using namespace std;

bool isEmpty(const Albero &t) { return t == NULL; }

void init(Albero &t) { t = NULL; }

bool inserisci(Albero &t, int val) {
  bool res = true;
  if (isEmpty(t)) {
    t = new (nothrow) node;
    if (t == NULL) {
      res = false;
    } else {
      t->val = val;
      t->sx = NULL;
      t->dx = NULL;
    }
  } else {
    if (val <= t->val)
      res = inserisci(t->sx, val);
    else
      res = inserisci(t->dx, val);
  }
  return res;
}

bool cerca(const Albero &t, int val) {
  bool res;
  if (isEmpty(t)) {
    res = false;
  } else {
    if (val == t->val) res = true;
    if (val < t->val) res = cerca(t->sx, val);
    if (val > t->val) res = cerca(t->dx, val);
  }
  return res;
}

int max(int a, int b) { return a > b ? a : b; }

int height(Albero &t) {
  if (isEmpty(t)) {
    return 0;
  } else { 
    int altezzaSX = height(t->sx);
    int altezzaDX = height(t->dx);
    int altezzaTot = max(altezzaSX, altezzaDX) + 1;
    return altezzaTot;
    // return max(height(t->sx), height(t->dx)) + 1;
  }
}

void stampa(const Albero &t) {
  if (!isEmpty(t)) {
    cout << t->val << " ";
    stampa(t->sx);
    stampa(t->dx);
  }
}
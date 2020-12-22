#include <iostream>
#include "albero.h"

using namespace std;

void inizializza(Albero &t) {
  t = NULL;
}

boolean vuoto(const Albero &t) {
  boolean res = FALSO;
  if (t == NULL)
    res = VERO;
  return res;
}

boolean inserisci(Albero &t, int val) {
  boolean res;
  if (vuoto(t) == VERO) {
    t = new (nothrow) Nodo;
    if (t == NULL)
      res = FALSO;
    else {
      t->val = val;
      t->sx = NULL;
      t->dx = NULL;
      res = VERO;
    }
  } else {
    if (val <= t->val)
      res = inserisci(t->sx, val);
    else
      res = inserisci(t->dx, val);
  }
  return res;
}

boolean cerca(const Albero &t, int val) {
  boolean res;
  if (vuoto(t) == VERO) {
    res = FALSO;
  } else {
    if (val == t->val)
      res = VERO;
    if (val < t->val)
      res = cerca(t->sx, val);
    if (val > t->val)
      res = cerca(t->dx, val);
  }
  return res;
}

void stampa(const Albero &t) {
  if (vuoto(t) == FALSO) {
    stampa(t->sx);
    cout << t->val << " ";
    stampa(t->dx);
  }
}

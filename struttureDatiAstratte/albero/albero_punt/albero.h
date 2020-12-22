#ifndef ALBERO_H
#define ALBERO_H

#include <vector>

struct node {
  int val;
  node *sx;  // Albero sx
  node *dx;  // ALbero dx
};

typedef node *Albero;

void init(Albero &t);
bool isEmpty(const Albero &t);
bool inserisci(Albero &t, int val);
bool cerca(const Albero &t, int val);
void stampa(const Albero &t);
int height(Albero &t);

#endif

struct nodeNC {
  int val;
  node *lChild;
  node *sibling;
};

struct nodeNC {
  int val;
  vector<node *> children;
};
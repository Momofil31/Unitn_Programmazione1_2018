#include <iostream>
#include "tree.h"

using namespace std;

void init(tree &t) {
  t = NULL;
}

void deinit(tree &t) {
  if (t != NULL) {
    deinit(t->left);
    deinit(t->right);
    delete t;
  }
}

tree inserisci(tree t, persona * p) {
  if (t == NULL) {
    t = new nodo;
    t->p = p;
    t-> left = NULL;
    t-> right = NULL;
  } else {
    if (strcmp(p->cognome, t->p->cognome) <= 0) {
      t->left = inserisci(t->left, p);
    } else {
      t->right = inserisci(t->right, p);
    }
  }
  return t;
}

tree cerca (tree t,char * ch) {
  tree res;
  if (t == NULL || strcmp(ch, t->p->cognome) == 0) {
    res = t;
  } else {
    if (strcmp(ch, t->p->cognome) < 0) {
      res = cerca(t->left, ch);
    } else {
      res = cerca(t->right, ch);
    }
  }
  return res;
}

void stampa_ordinata(tree t) {
  if (t != NULL) {
    stampa_ordinata(t->left);
    stampa_persona(t->p);
    stampa_ordinata(t->right);
  }
}

tree modifica_indirizzo (tree t,char * cognome, char * indirizzo) {
  tree tmp = cerca(t, cognome);
  if (tmp != NULL) {
    strcpy(tmp->p->indirizzo, indirizzo);
  }
  return tmp;
}

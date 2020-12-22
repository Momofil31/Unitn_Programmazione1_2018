#include "list.h"

#include <iostream>
using namespace std;

static bool isEmpty(const list &l) { return l == NULL; }

void init(list &l) { l = NULL; }

void deinit(list &l) {
  while (!isEmpty(l)) {
    pop_front(l);
  }
}

bool pop_front(list &l) {
  bool res = true;
  if (isEmpty(l)) {
    res = false;
  } else {
    node *tmp = l;
    l = tmp->next;
    delete tmp;
  }
  return res;
}

bool pop_back(list &l) {
  bool res = true;

  if (isEmpty(l)) {
    res = false;
  } else {
    node *current = l;

    if (current->next == NULL) {  // se sono sul primo elemento della lista lo
                                  // dealloco e rendo NULL la lista
      l = NULL;
      delete current;
    } else {
      // imposto current come "penultimo nodo"
      while (current->next->next != NULL) {
        current = current->next;
      }
      delete current->next;  // elimino l'ultimo elemento
      current->next = NULL;
    }
  }
  return res;
}

bool push_front(list &l, float val) {
  bool res = true;
  node *tmp = new (nothrow) node;
  if (tmp == NULL) {
    res = false;
  } else {
    tmp->value = val;
    tmp->next = l;
    l = tmp;
  }
  return res;
}

bool push_back(list &l, float val) {
  bool res = true;

  node *tmp = new (nothrow) node;
  cout << "tmp creata" << endl;
  if (tmp == NULL) {
    res = false;
  } else {
    tmp->value = val;
    tmp->next = NULL;
    if (isEmpty(l)) {  // se la lista è vuota inserisco l'elemento in testa
      l = tmp;
    } else {
      node *cursor = l;
      while (cursor->next !=
             NULL) {  // scorro la lista fino all'ultima posizione
        cursor = cursor->next;
      }
      cursor->next = tmp;  // inserisco l'elemento
    }
  }
  return res;
}

bool front(const list &l, float &out) {
  bool res = true;
  if (isEmpty(l)) {
    res = false;
  } else {
    out = l->value;
  }
  return res;
}

bool back(const list &l, float &out) {
  bool res = true;
  node *cursor = l;
  if (isEmpty(l)) {
    res = false;
  } else {
    while (cursor->next != NULL) {  // scorro tutta la lista fino in forndo
      cursor = cursor->next;
    }
    out = cursor->value;
  }
  return res;
}

bool remove(list &l, const float &elem) {
  bool res = true;
  if (isEmpty(l)) {
    res = false;
  } else {
    node *current = l;
    node *prev = NULL;

    // Se il primo elemento della lista è quello da rimuovere (come pop_front())
    if (current != NULL && current->value == elem) {
      l = current->next;
      delete current;
    } else {
      // Itero sulla lista finchè non trovo l'elemento da rimuovere o finisco la
      // lista
      while (current != NULL && current->value != elem) {
        prev = current;
        current = current->next;
      }
      if (current != NULL) {  // se non ho terminato la lista, ovvero ho trovato
                              // l'elemento rimuovo
        prev->next = current->next;
        delete current;
      } else {
        res = false;
      }
    }
  }
  return res;
}

bool reverse(list &l) {
  bool res = true;
  node *current = l;
  node *prev = NULL;
  node *next = NULL;

  while (current != NULL) {
    // Salvo il prossimo elemento
    next = current->next;

    // Rovescio il puntatore dell'elemento corrente (sul precedente)
    current->next = prev;

    // Mi muovo di una posizione in avanti sulla lista
    prev = current;
    current = next;
  }
  l = prev;  // assegno la testa della lista
  return res;
}

void print(const list &l) {
  node *tmp = l;
  while (tmp != NULL) {
    cout << tmp->value << endl;
    tmp = tmp->next;
  }
  delete tmp;
}
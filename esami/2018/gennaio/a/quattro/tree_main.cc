#include <iostream>
#include "tree.h"

using namespace std;

void stampa(const tree &t);

int main()
{
  char option,val;
  tree t, tmp;
  retval res;
  init(t);
  do {
    cout << "\nOperazioni possibili:\n"
         << "Inserimento (i)\n"
         << "Ricerca (r)\n"
         << "Stampa ordinata (s)\n"
         << "Stampa indentata (e)\n"
         << "Fine (f)\n";
    cin >> option;
    switch (option) {
    case 'i':
      cout << "Val? : ";
      cin >> val;
      res = insert(t,val);
      if (res == FAIL)
        cout << "spazio insufficiente!\n";
      break;
    case 'r':
      cout << "Val? : ";
      cin >> val;
      tmp=cerca(t,val);
      if (!nullp(tmp))
        cout << "Valore trovato!: " << val << endl;
      else
        cout << "Valore non trovato!\n";
      break;
    case 's':
      cout << "Stampa ordinata:\n";
      stampa(t);
      break;
    case 'f':
      break;
    default:
      cout << "Opzione errata\n";
    }
  } while (option != 'f');
}

// Si scrivano qui sotto le definizioni della funzione *NON RICORSIVA*:
// void stampa(const tree &)
// e di tutte le funzioni e strutture dati ausiliarie richieste.

// definizione di uno stack ausiliario

struct stacknode {
  tree val;
  stacknode * next;
};

typedef stacknode * stack;

bool isEmpty(const stack &s) {
  return s == NULL;
}

void init(stack &s) {
  s = NULL;
}

bool push(stack &s, tree &val) {
  bool res = true;
  stacknode * tmp = new (nothrow) stacknode;
  if (tmp == NULL) {
    res = false;
  } else {
    tmp->val = val;
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
    stacknode * tmp = s;
    s = s->next;
    delete tmp;
  }
  return res;
}

bool top(stack &s, tree &out) {
  bool res = true;
  if (isEmpty(s)) {
    res = false;
  } else {
    out = s->val;
  }
  return res;
}

void deinit(stack &s) {
  while(!isEmpty(s)) {
    pop(s);
  }
}

//FUNZIONE Stampa
void stampa(const tree &t) {
  tree tmp = t;
  stack s;
  init(s);
  while (!isEmpty(s) || tmp != NULL) {
    if (tmp != NULL) {
      push(s, tmp);
      tmp = tmp->left;
    } else {
      top(s, tmp);
      pop(s);
      cout << tmp->item << endl;
      tmp = tmp->right;
    }
  }
  deinit(s);
}

#include <iostream>
#include "queue.h"

using namespace std;

void init (queue &q) {
  //inizializzo testa a NULL
  q.head = NULL;
}

retval empty (const queue &q) {
  retval res = FALSE;

  //se la testa e' NULL allora la coda e' vuota
  if (q.head == NULL)
    res = TRUE;
  return res;
}

retval enqueue (queue &q, char val) {
  retval res = TRUE;
  //creo puntatore a nodo temporaneo
  node * tmp = new (nothrow) node;

  //se l'allocazione non va a buon fine res = FALSE
  if (tmp == NULL) {
    res = FALSE;
  } else {
    //assegno al nodo temporaneo il valore passato
    //e faccio puntare il campo next a NULL
    tmp->val = val;
    tmp->next = NULL;
    //se la coda e' vuota allora tmp e' sia testa che coda
    //altrimenti il successivo della coda e' tmp
    //e tmp diventa la coda
    if (empty(q)) {
      q.head = q.tail = tmp;
    } else {
      q.tail->next = tmp;
      q.tail = tmp;
    }
  }
  return res;
}

retval dequeue (queue &q) {
  retval res = TRUE;
  if (empty(q)) {
    res = FALSE;
  } else {
    //creo nodo temporaneo per "aggirare" la testa
    //e poi deallocarla
    node * tmp = q.head;
    q.head = q.head->next;
    delete tmp;
  }
  return res;
}

retval first (const queue &q, char &result) {
  retval res = TRUE;
  if (empty(q)) {
    res = FALSE;
  } else {
    // result e' il valore del nodo di testa
    result = q.head->val;
  }
  return res;
}

void print (const queue &q) {
  //creo nodo temporaneo per scorrere la coda
  node * tmp = q.head;
  //scorro la coda fino a che tmp diventa NULL e stampo il valore
  while (tmp != NULL) {
    cout << tmp->val << endl;
    tmp = tmp->next;
  }
  //dealloco tmp perche' non serve piu
  delete tmp;
}

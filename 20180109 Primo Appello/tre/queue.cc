#include <iostream>
#include "queue.h"

using namespace std;

static int next(const queue &q, int indice) {
  return (indice+1) % q.size;
}

static bool isEmpty(const queue &q) {
  return q.head == q.tail;
}
static bool isFull(const queue &q) {
  return next(q, q.tail) == q.head;
}

void init(queue &q, int maxdim) {
  //"spreco" un posto in piu', che comunque non sara' utilizzato
  //per gestire il caso coda piena
  q.size = maxdim+1;
  q.head = q.tail = 0;
  //allocazione array dinamico
  q.elem = new double[q.size];
}

void deinit(queue &q) {
  //deallocazione array dinamico
  delete [] q.elem;
}

void print(const queue &q) {
  //scorro il buffer circolare e stampo
  for (int i=q.head; i!=q.tail; i = next(q, i)) {
    cout << q.elem[i] << endl;
  }
}

bool enqueue(queue &q, double n) {
  bool res = true;
  if (isFull(q)) {
    res = false;
  } else {
    //inserisco il nuovo elemento in coda al buffer circolare
    //e sposto avanti di una posizione l'indice q.tail
    q.elem[q.tail] = n;
    q.tail = next(q, q.tail);
  }
  return res;
}

bool first(queue &q, double &out) {
  bool res = true;
  if (isEmpty(q)) {
    res = false;
  } else {
    //assegno a out il valore dell'elemento di testa
    out  = q.elem[q.head];
  }
  return res;
}

bool dequeue(queue &q) {
  bool res = true;
  if (isEmpty(q)) {
    res = false;
  } else {
    //sposto avanti di uno l'indice di testa
    q.head = next(q, q.head);
  }
  return res;
}

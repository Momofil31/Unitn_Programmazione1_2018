#include <iostream>
#include "queue.h"

using namespace std;

static int next(const queue &q, int index) {
  return (index+1) % q.dim;
}

static bool isEmpty(const queue &q) {
  return q.tail == q.head;
}

static bool isFull(const queue &q) {
  return next(q, q.tail) == q.head;
}

void init(queue &q, int maxdim) {
  q.head = q.tail = 0;
  q.dim = maxdim+1;
  q.elem = new float [q.dim];
}

void deinit(queue &q) {
  delete [] q.elem;
}

bool enqueue(queue &q, float n) {
  bool res = true;
  if (isFull(q))
    res = false;
  else {
    q.elem[q.tail] = n;
    q.tail = next(q, q.tail);
  }
  return res;
}

bool dequeue(queue &q) {
  bool res = true;
  if (isEmpty(q))
    res = false;
  else {
    q.head = next(q, q.head);
  }
  return res;
}

bool first(queue &q, float &out) {
  bool res = true;
  if (isEmpty(q))
    res = false;
  else {
    out = q.elem[q.head];
  }
  return res;
}

void print(const queue &q) {
  for (int i=q.head; i!=q.tail; i=next(q, i))
    cout << q.elem[i] << endl;
}

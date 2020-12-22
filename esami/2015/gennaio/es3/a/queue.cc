#include "queue.h"
#include <iostream>

using namespace std;

static int next(const queue &q, int index) {
  return (index+1)%q.dim;
}

static bool isEmpty(queue &q) {
  return q.tail == q.head;
}

static bool isFull(queue &q) {
  return q.head == next(q, q.tail);
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
  bool res;
  if (isFull(q)) {
    res = false;
  } else {
    q.elem[q.tail] = n;
    q.tail = next(q, q.tail);
    res = true;
  }
  return res;
}

bool dequeue(queue &q) {
  bool res;
  if (isEmpty(q)) {
    res = false;
  } else {
    q.head = next(q, q.head);
    res = true;
  }
  return res;
}

bool first(queue &q, float &out) {
  bool res;
  if (isEmpty(q)) {
    res = false;
  } else {
    out = q.elem[q.head];
    res = true;
  }
  return res;
}

void print(const queue &q) {
  for (int i = q.head; i != q.tail; i = next(q, i)) {
    cout << q.elem[i] << endl;
  }
  cout << endl;
}

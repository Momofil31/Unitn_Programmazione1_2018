#include "queue.h"
#include <iostream>

using namespace std;

static int next(int i, const queue &q) {
  return (i+1) % q.dim;
}

static bool isEmpty(const queue &q) {
  return q.tail == q.head;
}

static bool isFull(const queue &q) {
  return next(q.tail, q) == q.head;
}

void init(queue &q, int maxdim) {
  q.head = 0;
  q.tail = 0;
  q.dim = maxdim+1;
  q.elem  = new float[q.dim];
}

void deinit(queue &q) {
  delete [] q.elem;
}

bool enqueue(queue &q, float n){
  bool res;
  if (isFull(q)) {
    res = false;
  } else {
    q.elem[q.tail] = n;
    q.tail = next(q.tail, q);
    res = true;
  }
  return res;
}

bool dequeue(queue &q) {
  bool res;
  if (isEmpty(q)) {
    res = false;
  } else {
    q.head = next(q.head, q);
    res = true;
  }
  return res;
}

bool first(queue &q, float &out) {
  bool res;
  if (isEmpty(q))
    res = false;
  else
    out = q.head;

  return res;
}

void print(const queue &q) {
  for(int i = q.head; i != q.tail; i = next(i, q)) {
    cout << q.elem[i] << endl;
  }
  cout << endl;
}

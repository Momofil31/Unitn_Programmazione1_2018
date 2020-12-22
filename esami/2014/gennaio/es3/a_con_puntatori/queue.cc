#include "queue.h"
#include <iostream>

using namespace std;

static bool isEmpty(const queue &q) {
  bool res = false;
  if (q.head == NULL)
    res = true;
  return res;
}

void init(queue &q) {
  q.head = NULL;
}

bool enqueue(queue &q, float n) {
  bool res;
  node * tmp = new (nothrow) node;
  if (tmp == NULL) {
    res = false;
  } else {
    tmp->value = n;
    tmp->next = NULL;
    if (isEmpty(q)) {
      q.head = tmp;
    } else {
      q.tail->next = tmp;
    }
    q.tail = tmp;
    res = true;
  }
  return res;
}

void deinit(queue &q){
  while(!isEmpty(q)){
    dequeue(q);
  }
}
bool dequeue(queue &q){
  bool res;
  if (isEmpty(q)) {
    res = false;
  } else {
    node * first = q.head;
    q.head = q.head->next;
    delete first;
    res = true;
  }
  return res;
}
bool first(queue &q, float &out){
  bool res;
  if (isEmpty(q)) {
    res = false;
  } else {
    out = q.head->value;
    res = true;
  }
  return res;
}


void print(const queue &q){
  if (!isEmpty(q)) {
    node * first = q.head;
    do {
      cout << first->value << endl;
      first = first->next;
    } while (first != NULL);
  }
}

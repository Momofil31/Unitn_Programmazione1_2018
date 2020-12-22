#include <iostream>
#include "queue.h"

using namespace std;

static bool isEmpty(const queue &q) {
  return q.head == NULL;
}

void init(queue &q) {
  q.head = NULL;
}

void deinit(queue &q) {
  while(!isEmpty(q)) {
    dequeue(q);
  }
}

bool enqueue(queue &q, float n) {
  bool res = true;
  elem * tmp = new (nothrow) elem;
  if (tmp == NULL) {
    res = false;
  } else {
    tmp->value = n;
    tmp->next = NULL;
    if (isEmpty(q)) {
      q.head = q.tail = tmp;
    } else {
      q.tail->next = tmp;
      q.tail = tmp;
    }
  }
  return res;
}

bool dequeue(queue &q) {
  bool res = true;
  if (isEmpty(q)) {
    res = false;
  } else {
    elem * tmp = q.head;
    q.head = q.head->next;
    delete tmp;
  }
  return res;
}

bool first(const queue &q, float &out) {
  bool res = true;
  if (isEmpty(q)) {
    res = false;
  } else {
    out = q.head->value;
  }
  return res;
}

void print(const queue &q) {
  elem * tmp = q.head;
  while (tmp != NULL) {
    cout << tmp->value << " ";
    tmp = tmp->next;
  }
  delete tmp;
}

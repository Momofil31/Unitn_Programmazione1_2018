#include <iostream>
#include "queue.h"

using namespace std;

static bool isEmpty(const queue &q) {
  return q.head == NULL;
}

void init (queue &q) {
  q.head = NULL;
}

void deinit (queue &q) {
  while(!isEmpty(q))
    dequeue(q);
}

bool enqueue (queue &q, char val) {
  bool res = true;
  node * tmp = new (nothrow) node;
  if (tmp == NULL) {
    res = false;
  } else {
    tmp->val = val;
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

bool dequeue (queue &q) {
  bool res = true;
  if (isEmpty(q)) {
    res = false;
  } else {
    node * tmp = q.head;
    q.head = q.head->next;
    delete tmp;
  }
  return res;
}

bool first (const queue &q, char &result) {
  bool res = true;
  if (isEmpty(q)) {
    res = false;
  } else {
    result = q.head->val;
  }
  return res;
}

void print (const queue &q) {
  node * tmp = q.head;
  while (tmp != NULL) {
    cout << tmp->val << endl;
    tmp = tmp->next;
  }
}

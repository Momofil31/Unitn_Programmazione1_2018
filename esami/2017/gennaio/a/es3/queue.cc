#include "queue.h"
#include <iostream>

using namespace std;

retval empty(const queue &q) {
  retval res = FALSE;
  if (q.head == NULL)
    res = TRUE;
  return res;
}

void init (queue &q) {
  q.head = NULL;
}

retval enqueue (queue &q, char val) {
  retval res;
  node * tmp = new (nothrow) node;
  if (tmp == NULL) {
    res = FALSE;
  } else {
    tmp->val = val;
    tmp->next = NULL;
    if (empty(q)) {
      q.tail = q.head = tmp;
    } else {
      q.tail->next = tmp;
      q.tail = tmp;
    }
    res = TRUE;
  }
  return res;
}

retval dequeue (queue &q) {
  retval res;
  if (empty(q)) {
    res = FALSE;
  } else {
    node * primo = q.head;
    q.head = q.head->next;
    delete primo;
    res = TRUE;
  }
  return res;
}

retval first (const queue &q, char &result) {
  retval res;
  if (empty(q)) {
    res = FALSE;
  } else {
    result = q.head->val;
    res = TRUE;
  }
  return res;
}

void print (const queue &q) {
  node * tmp = q.head;
  while (tmp != NULL) {
    cout << tmp->val << endl;
    tmp = tmp->next;
  }
  delete tmp;
}

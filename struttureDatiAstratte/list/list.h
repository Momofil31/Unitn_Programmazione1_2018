#ifndef LIST_H
#define LIST_H

struct node {
  float value;
  node *next;
};

typedef node *list;

void init(list &);
void deinit(list &);
bool push_back(list &, float);
bool push_front(list &, float);
bool pop_front(list &);
bool pop_back(list &);
bool front(const list &, float &);
bool back(const list &, float &);
bool remove(list &, const float &);
bool reverse(list &);
void print(const list &);

#endif
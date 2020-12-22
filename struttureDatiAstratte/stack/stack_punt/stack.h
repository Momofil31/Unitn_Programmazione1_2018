#ifndef STACK_H
#define STACK_H

struct node {
	float value;
	node * next;
};

typedef node* stack;

void init(stack &);
void deinit(stack &);
bool push(stack &, float);
bool pop(stack &);
bool top(const stack &, float &);
void print(const stack &);

#endif

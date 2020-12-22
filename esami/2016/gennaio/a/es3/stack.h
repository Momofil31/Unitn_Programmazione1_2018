#ifndef STRUCT_STACK_H
#define STRUCT_STACK_H

struct stack {
	int index;
	int dim;
	double * elem;
};

void init(stack &s, int maxdim);
void deinit(stack &s);
bool push(stack &s, double n);
bool pop(stack &s);
bool top(const stack &s, float &out);
void print(const stack &s);

#endif

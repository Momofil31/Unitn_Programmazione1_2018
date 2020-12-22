#ifndef STACK_H
#define STACK_H

struct stack {
	int indice;
	int dim;
	float * value;
};

void init(stack &s, int maxDim);
void deinit(stack &s);
bool push(stack &s, float value);
bool pop(stack &s);
bool top(const stack &s, float &out);
void print(const stack &s);

#endif

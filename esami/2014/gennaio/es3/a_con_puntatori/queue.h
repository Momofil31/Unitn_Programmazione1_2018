#ifndef STRUCT_QUEUE_H
#define STRUCT_QUEUE_H

struct node {
	float value;
	node * next;
};

struct queue {
	node * head;
	node * tail;
};

void init(queue &q);
void deinit(queue &q);
bool enqueue(queue &q, float n);
bool dequeue(queue &q);
bool first(queue &q, float &out);
void print(const queue &q);

#endif

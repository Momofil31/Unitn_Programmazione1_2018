#ifndef QUEUE_H
#define QUEUE_H

struct node {
	char val;
	node *next;
};

struct queue {
	node *head;
	node *tail;
};

void init (queue &q);
bool enqueue (queue &q, char val);
bool dequeue (queue &q);
bool first (const queue &q, char &result);
void print (const queue &q);
void deinit (queue &q);

#endif // QUEUE_H

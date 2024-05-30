#ifndef QUEUE_H
#define QUEUE_H

typedef struct {
    int max;
    int start;
    int end;
    int total;
    char **items;
} t_queue;

t_queue* createQueue(int max);
void destroyQueue(t_queue *queue);
void add(t_queue *queue, char person[]);
char* removeOfQueue(t_queue *queue);
void printQueue(t_queue *queue);

#endif

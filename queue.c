#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

t_queue* createQueue(int max){
    t_queue *queue = (t_queue*) malloc(sizeof(t_queue));
    queue->max = max;
    queue->start = 0;
    queue->end = 0;
    queue->total = 0;
    queue->items = (char**) malloc(sizeof(char*) * max);

    for (int i = 0; i < max; i++) {
        queue->items[i] = (char*) malloc(50 * sizeof(char));
    }

    return queue;
}

void destroyQueue(t_queue *queue) {
    for (int i = 0; i < queue->max; i++) {
        free(queue->items[i]);
    }
    free(queue->items);
    free(queue);
}

void add(t_queue *queue, char person[]){
    strcpy(queue->items[queue->end], person);
    
    queue->end = (queue->end + 1) % queue->max;
    queue->total++;
}

char* removeOfQueue(t_queue *queue){
    char *person = queue->items[queue->start];

    queue->start = (queue->start + 1) % queue->max;
    queue->total--;
    return person;
}

void printQueue(t_queue *queue){
    int i = queue->start;
    int count = queue->total;

    while (count > 0) {
        printf("%s\n", queue->items[i]);
        i = (i + 1) % queue->max;
        count--;
    }
}

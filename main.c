#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

t_queue* bankQueue(char *queue[], int size){
    int i = 0;
    t_queue *priorityQueue = createQueue(size);
    t_queue *generalQueue = createQueue(size);
    t_queue *bankQueue = createQueue(size);

    int priorityCount = 0;

    while(strcmp(queue[i], "f") != 0){
        if(strcmp(queue[i], "g") == 0) {
            add(generalQueue, queue[i+1]);
            i += 2;
            
        } else if(strcmp(queue[i], "p") == 0) {
            add(priorityQueue, queue[i+1]);
            i += 2;

        } else if(strcmp(queue[i], "s") == 0) {
            if (priorityCount < 3 && priorityQueue->total > 0) {
                add(bankQueue, removeOfQueue(priorityQueue));
                priorityCount++;

            } else if (generalQueue->total > 0) {
                add(bankQueue, removeOfQueue(generalQueue));
                priorityCount = 0;

            }
        
            i++;

        } else {
            i++;
        }
    }

    printQueue(bankQueue);

    destroyQueue(priorityQueue);
    destroyQueue(generalQueue);

    return bankQueue;
}

int main(){
    char input[100];
    char category[2];
    char name[50]; 
    char *queue[100];
    int i = 0;

    for (int i = 0; i < 100; i++) {
        queue[i] = (char*) malloc(50 * sizeof(char));
        if (queue[i] == NULL) {
            fprintf(stderr, "Erro de alocação de memória\n");
            return 1;
        }
    }

    while(1){
        fgets(input, 100, stdin);

        if(strncmp(input, "p", 1) == 0 || strncmp(input, "g", 1) == 0) {
            sscanf(input, "%s %s", category, name);
            strcpy(queue[i], category);
            strcpy(queue[++i], name);
            i++;
        }

        if(strncmp(input, "s", 1) == 0) {
            sscanf(input, "%s", category);
            strcpy(queue[i], category);
            i++;
        }

        if(strncmp(input, "f", 1) == 0) {
            sscanf(input, "%s", category);   
            strcpy(queue[i++], category);
            break;
        }
    }

    bankQueue(queue, 100);

    for (int i = 0; i < 100; i++) {
        free(queue[i]);
    }
}

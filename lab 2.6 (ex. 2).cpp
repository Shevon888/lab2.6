#include <stdio.h>
#include <stdlib.h>


typedef struct DequeNode {
    int data;
    struct DequeNode *prev;
    struct DequeNode *next;
} DequeNode;


typedef struct {
    DequeNode *front;
    DequeNode *rear;
} Deque;


void init_deque(Deque *d) {
    d->front = NULL;
    d->rear = NULL;
}


void push_front(Deque *d, int value) {
    DequeNode *new_node = (DequeNode *)malloc(sizeof(DequeNode));
    if (new_node == NULL) {
        printf("Помилка виділення пам'яті!\n");
        return;
    }
    new_node->data = value;
    new_node->prev = NULL;
    new_node->next = d->front;

    if (d->front == NULL) {
        d->rear = new_node;
    } else {
        d->front->prev = new_node;
    }
    d->front = new_node;
}


void push_back(Deque *d, int value) {
    DequeNode *new_node = (DequeNode *)malloc(sizeof(DequeNode));
    if (new_node == NULL) {
        printf("Помилка виділення пам'яті!\n");
        return;
    }
    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = d->rear;

    if (d->rear == NULL) {
        d->front = new_node;
    } else {
        d->rear->next = new_node;
    }
    d->rear = new_node;
}


int pop_front(Deque *d, int *out_value) {
    if (d->front == NULL) {
        printf("Дек порожній! Неможливо видалити елемент з початку.\n");
        return 0;
    }
    DequeNode *temp = d->front;
    *out_value = temp->data;
    d->front = temp->next;

    if (d->front == NULL) {
        d->rear = NULL;
    } else {
        d->front->prev = NULL;
    }

    free(temp);
    return 1;
}


int pop_back(Deque *d, int *out_value) {
    if (d->rear == NULL) {
        printf("Дек порожній! Неможливо видалити елемент з кінця.\n");
        return 0;
    }
    DequeNode *temp = d->rear;
    *out_value = temp->data;
    d->rear = temp->prev;

    if (d->rear == NULL) {
        d->front = NULL;
    } else {
        d->rear->next = NULL;
    }

    free(temp);
    return 1;
}

int main(void) {
    Deque dq;
    init_deque(&dq);


    printf("=== Запис у дек (Операція_1) ===\n");
    push_back(&dq, 10);
    printf("Додано у кінець: 10\n");
    push_back(&dq, 20);
    printf("Додано у кінець: 20\n");
    push_front(&dq, 5);
    printf("Додано у початок: 5\n");
    push_front(&dq, 1);
    printf("Додано у початок: 1\n");
    printf("\n=== Видалення з дека (Операція_2) ===\n");
    int removed;

    if (pop_front(&dq, &removed)) {
        printf("Видалено з початку: %d\n", removed); 
    }
    if (pop_back(&dq, &removed)) {
        printf("Видалено з кінця: %d\n", removed);    
    }
    if (pop_front(&dq, &removed)) {
        printf("Видалено з початку: %d\n", removed); 
    }
    if (pop_back(&dq, &removed)) {
        printf("Видалено з кінця: %d\n", removed);    
    }

  
    while (pop_front(&dq, &removed)) {
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    char data;
    struct Node *next;
} Node;


typedef struct {
    Node *top;
} Stack;


void init_stack(Stack *s) {
    s->top = NULL;
}


void push(Stack *s, char value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Помилка виділення пам'яті!\n");
        return;
    }
    new_node->data = value;
    new_node->next = s->top;
    s->top = new_node;
}


int pop(Stack *s, char *out_value) {
    if (s->top == NULL) {
        printf("Стек порожній! Неможливо видалити елемент.\n");
        return 0;
    }
    Node *temp = s->top;
    *out_value = temp->data;
    s->top = temp->next;
    free(temp);
    return 1;
}

int main(void) {
    Stack st;
    init_stack(&st);


    char items[] = {'A', 'B', 'C', 'D'};
    int count = 4;

    printf("=== Запис у вершину стека (Операція_1) ===\n");
    for (int i = 0; i < count; i++) {
        push(&st, items[i]);
        printf("Додано у вершину: '%c'\n", items[i]);
    }

   
    printf("\n=== Видалення з вершини стека (Операція_2) ===\n");
    char removed;
    while (pop(&st, &removed)) {
        printf("Видалено з вершини: '%c'\n", removed);
    }

    return 0;
}

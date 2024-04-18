#include <stdio.h>
#include <stdlib.h>

typedef struct Cell
{
    struct Cell *prev;
    int value;
    struct Cell *next;
}Cell;

typedef struct
{
    int qtd;
    Cell *head;
    Cell *tail;
} Queue;

Cell *cell_create(const int value)
{
    Cell *c = malloc(sizeof(Cell));
    
    c->value = value;
    c->prev = NULL;
    c->next = NULL;

    return c;
}

Queue *queue_create()
{
    Queue *q = malloc(sizeof(Queue));

    q->qtd = 0;
    q->head = NULL;
    q->tail = NULL;

    return q;
}

void enqueue(Queue *q, int value)
{   
    Cell *new_cell = cell_create(value);

    if(q->qtd == 0)
    {
        q->head = new_cell;
    }
    else
    {
        new_cell->prev = q->tail;
        q->tail->next = new_cell;
    }
    q->tail = new_cell;
    
    q->qtd ++;
}

int dequeue(Queue *q)
{
    if(q->qtd == 0)
    {
        return -1;
    }
    
    Cell *removed_item = q->head;
    int value = removed_item->value;

    if(q->qtd == 1)
    {
        q->tail = NULL;
    }
    else
    {
        q->head->next->prev = NULL;
    }
    q->head = q->head->next;

    free(removed_item);
    q->qtd --;

    return value;
}

void queue_print(Queue *q)
{
    Cell *atual = q->head;

    while (atual != NULL)
    {
        printf("%d ", atual->value);
        atual = atual->next;
    }
    printf("\n");
}

void queue_print_inv(Queue *q)
{
    Cell *atual = q->tail;

    while (atual != NULL)
    {
        printf("%d ", atual->value);
        atual = atual->prev;
    }
    printf("\n");
}

int main()
{
    Queue *queue = queue_create();
    for(int i=0; i<10; i++)
    {
        enqueue(queue, i);
        queue_print(queue);
        queue_print_inv(queue);
    }
    
    for(int i=0; i<10; i++)
    {
        printf("Removido %d\n", dequeue(queue));
        queue_print(queue);
        queue_print_inv(queue);        
    }

    return 0;
}
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

Queue *queue_sum(Queue *q1, Queue *q2)
{
    Queue *result = queue_create();

    Cell *atual1 = q1->tail;
    Cell *atual2 = q2->tail;
    
    int rest = 0;

    while (atual1 != NULL)
    {
        enqueue(result, (atual1->value + atual2->value + rest) % 10);
        rest = (atual1->value + atual2->value + rest) / 10;
        atual1 =  atual1->prev;
        atual2 =  atual2->prev;
    }
    
    if(rest != 0)
    {
        enqueue(result, rest);
    }

    return result;
    
    
}

int main(void) {
	Queue *qnum1 = queue_create();
	Queue *qnum2 = queue_create();
	Queue *res;
	
	char num1[100];
	char num2[100];
	fgets(num1, sizeof(num1), stdin);
	fgets(num2, sizeof(num2), stdin);

	int i = 0;
	while(num1[i] != '\n'){		
		enqueue(qnum1, (int)(num1[i]) - 48);
		enqueue(qnum2, (int)(num2[i]) - 48);
		i++;
		}

    res = queue_sum(qnum1, qnum2);

    queue_print_inv(res);
	
}
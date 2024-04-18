#include <stdio.h>
#include <stdlib.h>

#define K 10

typedef struct
{
  int head, tail, qtd;
  int values[K];
}Queue;

Queue *cria_fila()
{
  Queue *queue = malloc(sizeof(Queue));
  queue->qtd = 0;
  queue->tail = 0;
  queue->head = 0;

  return queue;
};

int is_empy(Queue *q)
{
  return q->head == q->tail;
}

int is_full(Queue *q)
{
  return q->qtd == K;
}

void enqueue(Queue *queue, int value)
{
  if(is_full(queue))
  {
    return;
  }

  queue->values[queue->tail % K] = value;
  queue->tail ++;

  queue->qtd ++;
}

int dequeue(Queue *queue)
{
  int aux;

  if(is_empy(queue))
  {
    return -1;
  }

  aux = queue->values[queue->head % K];
  queue->head ++;

  queue->qtd --;
  
  return aux;

}

void print_queue(Queue *queue)
{
  int atual = queue->head;

  while(atual != queue->tail)
  {
    printf("%d ", queue->values[atual%K]);
    atual++;
  }

  printf("\n");

}
int main(void)
{
  Queue *queue = cria_fila();
  int values[] = {1, 7, 9, 12, 6, 8, 3, 5, 0, 10};
  for(int i=0; i<K; i++)
  {
    enqueue(queue, values[i]);
    print_queue(queue);
  }

  enqueue(queue, 20);

  for(int i=0; i <= K+10; i++)
  {
    printf("%d\n", dequeue(queue));
  }
 
}

#include <stdio.h>
#include <stdlib.h>

#define CAP 100

typedef struct
{
  int head, tail, qtd;
  char values[CAP];
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
  return q->qtd == CAP;
}

void enqueue(Queue *queue, char value)
{
  if(is_full(queue))
  {
    return;
  }

  

  queue->values[queue->tail % CAP] = value;
  queue->tail ++;

  queue->qtd ++;
}

char dequeue(Queue *queue)
{
  char aux;

  if(is_empy(queue))
  {
    return '\0';
  }

  aux = queue->values[queue->head % CAP];
  queue->head ++;

  queue->qtd --;
  
  return aux;

}

void print_queue(Queue *queue)
{
  int atual = queue->head;

  while(atual != queue->tail)
  {
    printf("%c ", queue->values[atual%CAP]);
    atual++;
  }

}
int main(void)
{
  Queue *eq = cria_fila();
  
  char s[CAP];
  fgets(s, sizeof(s), stdin);
  
  for(int i=0; s[i] != '\0'; i++)
  {
    enqueue(eq, s[i]);
  }

  int c_par = 0; 
  char c; 
  do
  {
    c = dequeue(eq);  
    if(c == '(')
    {
      c_par ++;
    }
    else if (c == ')')
    {
      c_par --;
      if (c_par < 0) break;
    }    
    print_queue(eq);

  }while (c != '\0');

  if(c_par != 0)
  {
    printf("incorreto\n");
  }
  else
  {
    printf("correto\n");
  }

  // Queue *par = cria_fila();
  

  // while (dequeue(eq) != '\0')
  // {
  //   // print_queue(eq);
  //   if(eq->head == '(') enqueue(par, eq->head);
  //   else if (eq->head == ')')
  //   {
  //     if(dequeue(par) == '\0')
  //     {
  //       enqueue(par, '(');
  //       break;
  //     }
  //     print_queue(par);
  //   }
  // }

  // if(is_empy(par))
  // {
  //   printf("correto");
  // }
  // else 
  // {
  //   printf("incorreto");
  // }


  
}

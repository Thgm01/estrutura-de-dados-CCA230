#include <stdio.h>
#include <stdlib.h>

typedef struct Cell
{
  struct Cell *next;
  struct Cell *prev;
  int value;
}Cell;

typedef struct
{
  Cell *top;
}Stack;
 

Cell *create_cell(int value)
{
  Cell *new_cell = malloc(sizeof(Cell));
  new_cell->value = value;
  new_cell->next = NULL;
  new_cell->prev = NULL;

  return new_cell;
}

Stack *create_stack()
{
  Stack *stack = malloc(sizeof(Stack));
  stack->top = NULL;

  return stack;
}

int is_empty(Stack *stack)
{
  return stack->top == NULL;
}

void push(Stack *s, int value)
{
  Cell *new_cell = create_cell(value);
  
  if(!is_empty(s))
  {
    s->top->prev = new_cell;
    new_cell->next = s->top;
  }

  s->top = new_cell;
}



int pop(Stack *stack)
{
  if(is_empty(stack))
  {
    return -1;
  }
  
  Cell *remove_cell = stack->top;
  int value = remove_cell->value;

  if(stack->top->next != NULL)
  {
    stack->top->next->prev = NULL;  
  }

  stack->top = stack->top->next;
  free(remove_cell);

  return value;
}

void print_stack(Stack *stack)
{
  Cell *c = stack->top;
  printf("<Top> ");

  while (c != NULL)
  {
    printf("%d ", c->value);
    c = c->next;
  }

  printf("<Base>\n");
}

void print_stack_inv(Stack *stack)
{
  Cell *c = stack->top;

  while(c->next != NULL)
  {
    c = c->next;
  }

  printf("<Base> ");
  while (c != NULL)
  {
    printf("%d ", c->value);
    c = c->prev;
  }

  printf("<Top>\n");
}

int main()
{
  Stack *stack = create_stack();
  push(stack, 1);
  push(stack, 2);
  push(stack, 3);
  push(stack, 4);
  push(stack, 5);
  push(stack, 6);

  print_stack_inv(stack);

  printf("removed: %d\n", pop(stack));
  printf("removed: %d\n", pop(stack));
  print_stack_inv(stack);
  printf("removed: %d\n", pop(stack));
  printf("removed: %d\n", pop(stack));
  print_stack_inv(stack);
  printf("removed: %d\n", pop(stack));
  printf("removed: %d\n", pop(stack));
  printf("removed: %d\n", pop(stack));
  printf("removed: %d\n", pop(stack));
  
  print_stack(stack);
  return 1;
}

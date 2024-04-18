#include <stdio.h>
#include <stdlib.h>

typedef struct Cell
{
  struct Cell *next;
  struct Cell *prev;
  char value;
}Cell;

typedef struct
{
  Cell *top;
}Stack;
 

Cell *create_cell(char value)
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

void push(Stack *s, char value)
{
  Cell *new_cell = create_cell(value);
  
  if(!is_empty(s))
  {
    s->top->prev = new_cell;
    new_cell->next = s->top;
  }

  s->top = new_cell;
}



char pop(Stack *stack)
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
    printf("%c ", c->value);
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
    printf("%c ", c->value);
    c = c->prev;
  }

  printf("<Top>\n");
}

int main(void) {
    
    char expr[100];
    fgets(expr, sizeof(expr), stdin);


    char hierarquia[9] = "{[(}])";
    int h_num = 0;

    int j=0;
    Stack *parenteses = create_stack();

    while(expr[j] != '\n')
    {
        char c = expr[j];

        if(c == '{' || c == '[' || c == '(' )
        {
            if(parenteses->top == NULL)
            {
                switch (c)
                {
                case '{':
                    h_num = 0;
                    break;
                case '[':
                    h_num = 1;
                    break;
                case '(':
                    h_num = 2;
                    break;
                

                default:
                    break;
                }
            }
            push(parenteses, c);
            if(c != hierarquia[h_num] && c != hierarquia[h_num+1])
            {
                break;
            }
            h_num ++;
        }
        else if (c == '}' || c == ']' || c == ')' )
        {
            if(c != hierarquia[h_num+2] && c != hierarquia[h_num+3])
            {
                break;
            }
            pop(parenteses);
            h_num--;
        }
        j++;

        
    }
    if(parenteses->top != NULL)     printf("incorreto");
    else                            printf("correto");

    
}


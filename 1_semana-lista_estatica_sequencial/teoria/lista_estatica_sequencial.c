#include <stdio.h>
#define LEN 10

typedef struct
{
    int values[LEN];
    int qtd;
} List;

int is_full(List *list){
    return list->qtd == LEN;
}

int is_empty(List *list){
    return list->qtd == 0;
}

int get_idx(List *list, int value){
    int idx = 0;
    while (idx < list->qtd && list->values[idx] < value){
        idx++;     
    }

    return idx;
}

void move_right(List *list, int idx){
    for (int i = list->qtd; i > idx; i--)
    {
        list->values[i] = list->values[i-1];
    }
    

}


void insert(List *list, int value){
    if (is_full(list))
        return;
    
    int idx = 0;
    
    if(!is_empty(list)){
        idx = get_idx(list, value);
        move_right(list, idx);
    }


    list->values[idx] = value;
    list->qtd++;

    
}

void show(List *list){
    for (int i = 0; i < list->qtd; i++)
        printf("%d ", list->values[i]);
    printf("\n");
    
    
}



int main(void){
    List list;
    list.qtd = 0;
    List *pt_list = &list;

    int values[] = {3, 6, 1, 8, 9, 0, 4, 2, 7, 5};
    int len_values = sizeof(values) / sizeof(int);
    for (int i = 0; i < len_values; i++){
        insert(pt_list,values[i]);
        show(pt_list);
    }
    return 0;

}

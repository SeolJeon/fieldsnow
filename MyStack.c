#include <stdio.h>
#include <stdlib.h>

typedef struct {
    struct objec *next;
    struct objec *pre;
    int data;
}objec;

void Push(objec**point){
    objec*newo=(objec*)malloc(sizeof(objec));
    int num;
    printf_s("Insert Data: ");
    scanf_s("%d",&num);
    newo->data = num;
    newo->next = NULL;

    if (*point == NULL) {
        newo->pre=NULL;
        *point=newo;
    }
    else {
        (*point)->next = newo;
        newo->pre = *point;
        *point = newo;
    }
}

void Pop(objec**point) {
    if (*point == NULL)
        printf("Stack is Empty\n");
    else {
        printf_s("Output Data: %d\n",(*point)->data);
        objec* temp = *point;
        if ((*point)->pre == NULL) {
            *point = NULL;
        }
        else {
            *point = (*point)->pre;
            (*point)->next = NULL;
        }
        free(temp);
    }
}

int main() {
    objec* point = NULL;
    int menu;
    int op = 1;
    
    while (op) 
    {
        printf_s("Select Menu\n--------------------\n");
        printf_s("Push: 1\n");
        printf_s("Pop: 2\n");
        printf_s("Exit: Other Number\n--------------------\n");
        printf_s("-> ");
        scanf_s("%d", &menu);

        switch (menu)
        {
        case 1:
            Push(&point);
            break;
        case 2:
            Pop(&point);
            break;
        default:
            printf("closing.....\n");
            op = 0;
            break;
        }
    }
    while (point != NULL) {
        objec* temp = point;
        point = point->pre;
        free(temp);
    }
    return 0;
}
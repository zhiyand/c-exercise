#include <stdio.h>
#include <stdlib.h>

struct stackNode{
    int    data;
    struct stackNode * next;
};

typedef struct stackNode * Node;

struct listStack{
    Node root;
};

typedef struct listStack * ListStack;

ListStack list_stack_create(void){
    ListStack stack = (ListStack) malloc(sizeof(struct listStack));
    stack->root     = NULL;

    return stack;
}

int list_stack_empty(ListStack stack){
    if(stack == NULL){
        return -1;
    }
    if(stack->root == NULL){
        return 1;
    }
    return 0;
}

int list_stack_push(ListStack stack, int number){
    Node node   = (Node) malloc(sizeof(struct stackNode));

    node->data  = number;
    node->next  = stack->root;

    stack->root = node;

    return number;
}

int list_stack_pop(ListStack stack){
    if(stack == NULL || stack->root == NULL){
        return 0;
    }

    int data    = stack->root->data;
    Node root   = stack->root;
    stack->root = stack->root->next;

    free(root);
    return data;
}

void list_stack_destroy(ListStack stack){
    if(stack == NULL){
        return;
    }
    while(list_stack_empty(stack) == 0){
        list_stack_pop(stack);
    }
    free(stack);
}

void list_stack_display(ListStack stack){
    Node node = stack->root;

    printf("+------+\n");
    while(node != NULL){
        printf("|%6d|\n", node->data);
        node = node->next;
    }
    printf("+------+\n");
}

int main(void){
    ListStack stack = list_stack_create();

    list_stack_push(stack, 100);
    list_stack_push(stack, 200);
    list_stack_push(stack, 300);

    list_stack_display(stack);

    while(list_stack_empty(stack) == 0){
        int number = list_stack_pop(stack);

        printf("Popped: %d\n", number);
        list_stack_display(stack);
    }

    for(int i = 0; i < 5; i++){
        printf("Pushing: %d\n", i*10);
        list_stack_push(stack, i*10);
        list_stack_display(stack);
    }

    list_stack_destroy(stack);

    return 0;
}

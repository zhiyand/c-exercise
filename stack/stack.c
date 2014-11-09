#include <stdio.h>
#include <stdlib.h>

struct intStack{
    int * numbers;
    int top;
    int size;
};

typedef struct intStack* Stack;

Stack stack_create(int size){
    Stack stack = (Stack) malloc(sizeof(struct intStack));

    stack->numbers = (int *) malloc(sizeof(int) * size);
    stack->size = size;
    stack->top = 0;

    return stack;
}

int push(Stack stack, int number){
    if(stack->top >= stack->size){
        return -1;
    }

    stack->numbers[stack->top] = number;
    stack->top += 1;

    return number;
}

int pop(Stack stack){
    if(stack->top < 1){
        return 0;
    }
    int number = stack->numbers[stack->top-1];

    stack->top -= 1;

    return number;
}

void stack_display(Stack stack){
    int i = 0;
    printf("+------+\n");
    for(i = stack->size - 1; i >= 0; i--){
        if(stack->top > i){
            printf("|%6d|\n", stack->numbers[i]);
        }else{
            printf("|     -|\n");
        }
    }
    printf("+------+\n");
}

void stack_destroy(Stack stack){
    if(stack != NULL){
        if(stack->numbers != NULL){
            free(stack->numbers);
        }
        free(stack);
    }
}

int main(void){
    int i = 0;
    Stack stack = stack_create(6);

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);

    stack_display(stack);

    printf("Pop: %d\n", pop(stack));
    stack_display(stack);

    printf("Push: %d\n", push(stack, 50));
    stack_display(stack);

    for(i = 0; i < 5; i++){
        printf("Pop: %d\n", pop(stack));
        stack_display(stack);
    }

    for(i = 0; i < 7; i++){
        printf("Push: %d\n", push(stack, 9 -i));
        stack_display(stack);
    }

    for(i = 0; i < 7; i++){
        printf("Pop: %d\n", pop(stack));
        stack_display(stack);
    }

    printf("Push: %d\n", push(stack, 100));
    stack_display(stack);

    stack_destroy(stack);
    return 0;
}

#include<stdio.h> 
#include<stdlib.h> 
typedef struct { 
    int key; 
} element; 
struct stack { 
    element data; 
    struct stack *link; 
}; 
typedef struct stack *stckptr; 
stckptr top = NULL;  
void push(element item) { 
    stckptr temp; 
    temp = (stckptr)malloc(sizeof(struct stack)); 
    temp->data = item; 
    temp->link = top; 
    top = temp; 
} 
element pop() { 
    stckptr temp; 
    element item; 
    if (top == NULL) { 
        item.key = -1;  
        return item; 
    } 
    else { 
        temp = top; 
        top = top->link; 
        item = temp->data; 
        free(temp); 
        return item; 
    } 
} 
void display() { 
    stckptr temp = top; 
    while (temp != NULL) { 
        printf("%d\t", temp->data.key); 
        temp = temp->link; 
    } 
} 
int main() { 
    element item; 
    int choice; 
    while (1) { 
        printf("\nEnter\n1. Push\n2. Pop\n3. Display\n4. Exit\n"); 
        scanf("%d", &choice); 
        switch (choice) { 
            case 1: 
                printf("\nEnter element to push: "); 
                scanf("%d", &item.key); 
                push(item); 
                break; 
            case 2: 
                item = pop(); 
                if (item.key == -1) 
                    printf("\nStack Underflow!\n"); 
                else 
                    printf("\nPopped element: %d\n", item.key); 
                break; 
            case 3: 
                printf("\nStack: "); 
                display(); 
                break; 
            case 4: 
                exit(0); 
            default: 
                printf("\nInvalid choice!\n"); 
        } 
    } 
    return 0; 
}
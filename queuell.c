#include <stdio.h> 
#include <stdlib.h> 
typedef struct { 
    int key; 
} element; 
struct queue { 
    element data; 
    struct queue* link; 
}; 
typedef struct queue* queueptr; 
queueptr front = NULL; 
queueptr rear = NULL; 
void insert(element item) { 
    queueptr temp; 
    temp = (queueptr)malloc(sizeof(struct queue)); 
    temp->data = item; 
    temp->link = NULL; 
    if (rear) 
        rear->link = temp; 
    else 
        front = temp; 
    rear = temp; 
} 
element delete() { 
    queueptr temp; 
    element item; 
    if (front) { 
        temp = front; 
        item = front->data; 
        front = front->link; 
        if (front == NULL) 
            rear = NULL; 
        free(temp); 
    } else { 
        item.key = -1; 
    } 
    return item; 
} 
void display() { 
    queueptr temp = front; 
    if (temp == NULL) { 
        printf("Queue empty\n"); 
        return; 
    } 
    while (temp) { 
        printf("%d\t", temp->data.key); 
        temp = temp->link; 
    } 
    printf("\n"); 
} 
int main(void) { 
    int choice; 
    element item; 
    while (1) { 
        printf("Enter\n 1. Insert\n 2. Delete\n 3. Display\n 4. Exit\n"); 
        scanf("%d", &choice); 
        switch (choice) { 
            case 1: 
                printf("Enter data to be inserted: "); 
                scanf("%d", &item.key); 
                insert(item); 
                break; 
            case 2: 
                item = delete(); 
                if (item.key == -1) 
                    printf("Queue empty\n"); 
                else 
                    printf("Element deleted: %d\n", item.key); 
                break; 
            case 3: 
                display(); 
                break; 
            case 4: 
exit(0); 
default: 
printf("Invalid choice\n"); 
} 
} 
return 0; 
} 
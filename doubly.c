#include <stdio.h> 
#include <stdlib.h> 
typedef struct node *nodepointer; 
typedef struct node { 
    nodepointer llink; 
    int data; 
    nodepointer rlink; 
} Node; 
void dinsert(nodepointer node, nodepointer newnode) { 
    newnode->llink = node; 
    newnode->rlink = node->rlink; 
    if (node->rlink != NULL) 
        node->rlink->llink = newnode; 
    node->rlink = newnode; 
} 
void delete(nodepointer deleted) { 
    if (deleted->llink != NULL) 
        deleted->llink->rlink = deleted->rlink; 
    if (deleted->rlink != NULL) 
        deleted->rlink->llink = deleted->llink; 
    free(deleted); 
} 
void display(nodepointer header) { 
    nodepointer current = header->rlink; 
    if (current == NULL) { 
        printf("List is empty\n"); 
        return; 
    } 
    printf("List: "); 
    while (current != NULL) { 
        printf("%d ", current->data); 
        current = current->rlink; 
    } 
    printf("\n"); 
} 
int main(void) { 
    nodepointer header = (nodepointer)malloc(sizeof(Node)); 
    header->llink = header->rlink = NULL; 
    int choice; 
    int item; 
    while (1) { 
        printf("Enter\n 1. Insert\n 2. Delete\n 3. Display\n 4. Exit\n"); 
        scanf("%d", &choice); 
        switch (choice) { 
            case 1: 
                printf("Enter data to be inserted: "); 
                scanf("%d", &item); 
                nodepointer newnode = (nodepointer)malloc(sizeof(Node)); 
                newnode->data = item; 
                dinsert(header, newnode); 
                break; 
            case 2: 
                if (header->rlink == NULL) { 
                    printf("List is empty. Cannot delete.\n"); 
                    break; 
                } 
                printf("Enter data to be deleted: "); 
                scanf("%d", &item); 
                nodepointer current = header->rlink; 
                while (current != NULL && current->data != item) { 
                    current = current->rlink; 
                } 
                if (current == NULL) { 
                    printf("Element not found in the list\n"); 
                } else { 
                    delete(current); 
                    printf("Element deleted: %d\n", item); 
                } 
                break; 
            case 3: 
                display(header); 
                break; 
            case 4: 
                free(header); 
                exit(0); 
            default: 
                printf("Invalid choice\n"); 
        } 
    } 
    return 0; 
}
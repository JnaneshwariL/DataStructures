#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node* createNode(int data) {
    struct node *p = (struct node*)malloc(sizeof(struct node));
    if (p == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    p->data = data;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

void insertEnd(struct node **head, int data) {
    struct node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void insertLeft(struct node **head, int target, int data) {
    struct node *temp = *head;
    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL) {
        printf("Target node %d not found!\n", target);
        return;
    }

    struct node *newNode = createNode(data);
    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newNode;
    else
        *head = newNode; 

    temp->prev = newNode;
}

void deleteNode(struct node **head, int target) {
    struct node *temp = *head;
    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL) {
        printf("Node with value %d not found!\n", target);
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head = temp->next; 

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node with value %d deleted.\n", target);
}

void displayList(struct node *head) {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    printf("List contents: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;
    int choice, data, target;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert at end (create list)\n");
        printf("2. Insert to the left of a node\n");
        printf("3. Delete a node by value\n");
        printf("4. Display list\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            case 2:
                printf("Enter target node value: ");
                scanf("%d", &target);
                printf("Enter new data to insert: ");
                scanf("%d", &data);
                insertLeft(&head, target, data);
                break;
            case 3:
                printf("Enter node value to delete: ");
                scanf("%d", &target);
                deleteNode(&head, target);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

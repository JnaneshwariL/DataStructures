#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node* createNode(int value) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
}

void push(int value) {
    struct node *newnode = createNode(value);
    newnode->next = head;
    head = newnode;
    printf("Pushed %d\n", value);
}

void pop() {
    if (head == NULL) {
        printf("Stack Underflow (Empty)\n");
        return;
    }
    struct node *temp = head;
    printf("Popped %d\n", temp->data);
    head = head->next;
    free(temp);
}

void enqueue(int value) {
    struct node *newnode = createNode(value);

    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }

    printf("Enqueued %d\n", value);
}

void dequeue() {
    if (head == NULL) {
        printf("Queue Underflow (Empty)\n");
        return;
    }
    struct node *temp = head;
    printf("Dequeued %d\n", temp->data);
    head = head->next;
    free(temp);
}

void display() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is Empty\n");
        return;
    }
    printf("List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Enqueue (Queue)\n");
        printf("4. Dequeue (Queue)\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
                break;

            case 3:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 4:
                dequeue();
                break;

            case 5:
                display();
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* next;
};

struct node* start = NULL;


void insertAtBeginning(int item) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->info = item;
    p->next = start;
    start = p;
}


void insertAtEnd(int item) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->info = item;
    p->next = NULL;

    if (start == NULL) {
        start = p;
        return;
    }

    struct node* temp = start;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = p;
}


void insertAtPosition(int item, int pos) {
    if (pos == 1) {
        insertAtBeginning(item);
        return;
    }

    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->info = item;

    struct node* temp = start;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(p);
        return;
    }

    p->next = temp->next;
    temp->next = p;
}


void deleteBeginning() {
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node* temp = start;
    start = start->next;
    free(temp);
}

void deleteEnd() {
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (start->next == NULL) {
        free(start);
        start = NULL;
        return;
    }

    struct node* temp = start;
    while (temp->next->next != NULL)
        temp = temp->next;

    free(temp->next);
    temp->next = NULL;
}


void deletePosition(int pos) {
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (pos == 1) {
        deleteBeginning();
        return;
    }

    struct node* temp = start;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range!\n");
        return;
    }

    struct node* del = temp->next;
    temp->next = del->next;
    free(del);
}

 void display() {
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node* temp = start;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, item, pos;

    while (1) {
        printf("\n--- LINKED LIST MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Display List\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &item);
                insertAtBeginning(item);
                break;

            case 2:
                printf("Enter element: ");
                scanf("%d", &item);
                insertAtEnd(item);
                break;

            case 3:
                printf("Enter element: ");
                scanf("%d", &item);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(item, pos);
                break;

            case 4:
                deleteBeginning();
                break;

            case 5:
                deleteEnd();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &pos);
                deletePosition(pos);
                break;

            case 7:
                display();
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}


#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* next;
};

struct node* start1 = NULL;
struct node* start2 = NULL;


void insertEnd(struct node** start, int item) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->info = item;
    p->next = NULL;

    if (*start == NULL) {
        *start = p;
        return;
    }

    struct node* temp = *start;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = p;
}


void sortList(struct node** start) {
    if (*start == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node *i, *j;
    int temp;

    for (i = *start; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->info > j->info) {
                temp = i->info;
                i->info = j->info;
                j->info = temp;
            }
        }
    }

    printf("List sorted successfully.\n");
}


void reverseList(struct node** start) {
    struct node *prev = NULL, *curr = *start, *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }

    *start = prev;
    printf("List reversed successfully.\n");
}

void concatenate() {
    if (start1 == NULL) {
        start1 = start2;
        start2 = NULL;
        printf("Lists concatenated.\n");
        return;
    }

    struct node* temp = start1;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = start2;
    start2 = NULL;

    printf("Lists concatenated.\n");
}

void display(struct node* start) {
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node* temp = start;
    printf("List: ");

    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice, item;

    while (1) {
        printf("\n--- SINGLE LINKED LIST MENU ---\n");
        printf("1. Insert in List 1\n");
        printf("2. Insert in List 2\n");
        printf("3. Sort List 1\n");
        printf("4. Reverse List 1\n");
        printf("5. Concatenate List 1 and List 2\n");
        printf("6. Display List 1\n");
        printf("7. Display List 2\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &item);
                insertEnd(&start1, item);
                break;

            case 2:
                printf("Enter element: ");
                scanf("%d", &item);
                insertEnd(&start2, item);
                break;

            case 3:
                sortList(&start1);
                break;

            case 4:
                reverseList(&start1);
                break;

            case 5:
                concatenate();
                break;

            case 6:
                display(start1);
                break;

            case 7:
                display(start2);
                break;

            case 8:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

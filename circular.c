#include <stdio.h>
#define SIZE 5

int queue[SIZE];
front = -1, rear = -1;

void insert(int data) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1)
        front = rear = 0;
    else rear = (rear + 1) % SIZE;
        queue[rear] = data;
        printf("Inserted %d\n", data);
}

void delete() {
    if (front == -1) {
        printf("Queue Underflow!\n");
        return;
    }
    printf("Deleted %d\n", queue[front]);
    if (front == rear)
        front = rear = -1;
    else front = (front + 1) % SIZE;
}

void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    int i = front;
    while (i != rear) {
        printf("%d ", queue[i]);
        i = (i + 1) % SIZE;
    }
    printf("%d\n", queue[rear]);
}
int main() {
    int choice, data;
    while (1) {
        printf("1. Insert 2. Delete 3. Display 4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

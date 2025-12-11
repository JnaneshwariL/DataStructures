#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

void push(int value) {
    if (top == SIZE - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        top=top+1;
        stack[top] = value;
        printf("%d pushed to stack.\n",value);
    }
}


void pop() {
    if (top == -1) {
        printf("Stack Underflow! No element to pop.\n");
    } else {
        printf("%d popped from stack.\n", stack[top]);
        top=top-1;
    }
}


void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements are: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {

    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);

    display();

    pop();
    pop();

    display();

    pop();
    pop();
    pop();
    pop();

    return 0;
}

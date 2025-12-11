#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    int arr[MAX], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d numbers: ", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);


    for(i = 0; i < n; i++)
        push(arr[i]);

    for(i = 0; i < n; i++)
        arr[i] = pop();

    printf("Reversed list: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

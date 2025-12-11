#include<stdio.h>
#define MAX 3
int queue_array[MAX];
int front =-1;
int rear =-1;

insert()
{
    int add_item;
    if (rear==MAX-1)
    printf("queue overflow");
    else
    {
        if(front==-1)
        front=0;
        printf("insert the element in queue: ");
        scanf("%d",&add_item);
        rear=rear+1;
        queue_array[rear]=add_item;
    }
}
delete()

{
    if (front==-1 || front>rear)
    {
        printf("queue underflow");
        return;
    }
    else
    {
        printf("deleted element is %d",queue_array[front]);
        front=front+1;
    }
}
void display()
{
    int i;
    if (front==-1)
    printf("queue is empty");
    else
    {
        printf("queue elements are: ");
        for(i=front;i<=rear;i++)
        printf("%d ",queue_array[i]);
        printf("\n");
    }
}
main ()
{
    int choice;
    while(1)
    {
        printf("\n 1.Insert: ");
        printf("\n 2.Delete: ");
        printf("\n 3.Display: ");
        printf("\n 4.Exit: ");
        printf("Enter your choice: \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            insert();
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("invalid choice");


    }
}
}

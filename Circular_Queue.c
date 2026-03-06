#include <stdio.h>
#define MS 4
typedef struct queue
{
    int arr[MS];
    int front;
    int rear;
} queue;

void init(queue *q)
{
    q->front = -1;
    q->rear = -1;
}

void push(queue *q, int x)
{
    if ((q->front == 0 && q->rear == MS - 1) || (q->front == q->rear + 1))
    {
        printf("Check your input, it's invalid\n");
        return;
    }
    if (q->front == -1 && q->rear == -1)
    {
        q->front = (q->front + 1) % MS;
        q->rear = (q->rear + 1) % MS;
    }
    else
    {
        q->rear = (q->rear + 1) % MS;
    }
    q->arr[q->rear] = x;
}

void pop(queue *q)
{
    if (q->front == -1)
    {
        printf(" Underflow condition\n");
        return;
    }
    if (q->front == q->rear)
    {
        q->front = -1;
        q->rear = -1;
        return;
    }
    q->front = (q->front + 1) % MS;
}

void display(queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is Empty\n");
        return;
    }
    if (q->front <= q->rear)
    {
        printf("Queue elements: ");

        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = MS - 1; i >= q->front; i--)
        {
            printf("%d ", q->arr[i]);
        }
        // to get 0 to rear
        for (int i = q->rear; i >= 0; i--)
        {
            printf("%d ", q->arr[i]);
        }
        printf("\n");

        for (int i = q->front; i != q->rear;)
        {
            printf("%d ", q->arr[q->rear]);
            printf("\n");
        }
    }
}

int main()
{
    queue q;

    init(&q);

    printf("Insert 10\n");
    push(&q, 10);
    display(&q);

    printf("Insert 20\n");
    push(&q, 20);
    display(&q);

    printf("Insert 30\n");
    push(&q, 30);
    display(&q);

    printf("Insert 40\n");
    push(&q, 40);
    display(&q);

    printf("Delete element\n");
    pop(&q);
    display(&q);

    printf("Delete element\n");
    pop(&q);
    display(&q);

    printf("Delete element\n");
    pop(&q);
    display(&q);

    printf("Delete element\n");
    pop(&q); // This will show Underflow
    display(&q);

    return 0;
}

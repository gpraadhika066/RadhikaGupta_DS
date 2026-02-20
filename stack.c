#include<stdio.h>
#include<stdlib.h>
#define MS 5

typedef struct
{
    int arr[MS];
    int top;

} stack;

void init (stack *s)
{
    s->top= -1;
}

void push (stack *s)
{
    if (s-> top == MS-1)
    {
        printf("Invalid input \n");
        return;
    }
    int x;
    s-> top++;
    s-> arr[s-> top] = x;

}

void display (stack *s)
{
    for (int i =0; i<= s-> top; i++)
    {
        printf("%d ", s-> arr[i]);

    }
    printf("\n");
}

void pop (stack *s)
{
    if (s->top== -1)
    {
        printf ("Underflow\n");
        return;
    }
    --s->top;
}

int getSize (stack *s)
{
    int size = s-> top+1;
    return size;
}

int main ()
{
    stack s;
    init (&s);

    push (&s, 10);
    
    push (&s, 20);
   
    push (&s, 30);

    display(&s);
    
    
    pop (&s);
    display (&s);
    pop (&s);
    display (&s);
    pop (&s);
    display (&s);
    pop (&s);
    display (&s);
   
    return 0;
}
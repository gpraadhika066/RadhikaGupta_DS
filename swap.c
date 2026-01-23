#include<stdio.h>

int main ()
{
    int a=6,b=10,temp;
    printf("The given numbers are : %d %d", a,b);
    temp=a;
    a=b;
    b=temp;
    printf("\nNow a= %d, b=%d", a,b);
    return 0;
    
}
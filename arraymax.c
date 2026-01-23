#include<stdio.h>
int main()
{
    int a[5]= {1,3,4,5,6};
    printf("The given array is %d", a[5]);
    int max1= INT_MIN, max2=INT_MIN;
    for(int i=0; i<5; i++)
    if(a[i]>max1)
     {max1=max2;
      max1= a[i];
     }
     else if(a[i]>max2 && a[i] !=max1)
       {max2=a[i];
       }
    if (max2== INT_MIN)
      printf("Second maximum doesnot exist");
    else 
      printf("Second maximum=%d", max2);
    
    return 0;
    

}
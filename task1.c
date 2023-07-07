#include<stdio.h>
#include<stdlib.h>

void swap_int (int *,int*);

int * ptr1;
int * ptr2;
int num1;
int num2;

int main()
{

    void swap_int(int * a,int * b){
        int temp = *a;
        *a = *b;
        *b = temp;

    }

    num1 = 6;
    num2 = 10;
    ptr1 = &num1;
    ptr2 = &num2;

    swap_int(ptr1,ptr2);
    printf("ptr1 points to %d\n: ",*ptr1);
    printf("ptr2 points to %d\n: ",*ptr2);
    return 0;
}
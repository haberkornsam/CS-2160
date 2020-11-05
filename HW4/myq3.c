#include<stdio.h>


struct S1 {

long Arr[10];
};

typedef struct S1 TYPE;

int main(){
struct S1 Brr[10];

TYPE *ptr1 = (TYPE *) Brr[6].Arr;
TYPE *ptr2 = (TYPE *) Brr[2].Arr;
printf("ptr 1 - ptr2 = %ld\n", ptr1-ptr2);
return 0;
}



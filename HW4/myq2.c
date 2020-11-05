#include<stdio.h>

#define NUM 235

int main(){

struct S1 {
long Arr[NUM];
};

struct S1 Brr[10];
long *ptr1 = Brr[6].Arr;
long *ptr2 = Brr[2].Arr;

long te[4];
printf("%d\n", sizeof(te));
printf("ptr-ptr = %ld\n", ptr1-ptr2);


return 0;
}



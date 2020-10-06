#include<stdio.h>



int func1(int a, int b) {
 printf("executing func1\n");
 
return  a*((3*a)+2 + (4*b));


//Returns 1120 when a=10
}


int func4(int a, int b) {
 printf("executing func4\n");
return (getc(stdin) & 0xf5) == '4' ? 1 : 0;

//Returns 1 whenever the input begins with '4' possible inputs are 4, 41, 42
}

int func3(int a, int b) {
//Returns 1 if a = 10
 printf("executing func3\n");
if(a<=0){
return 0xffffffff;
}
int temp = 0;
if (b>4){
temp = 1;


}

return (2*temp)-1;
}
int func2(int a, int b) 
//returns 2 when a = 10

{
 printf("executing func2\n");
 if(a>0){
do {
b >>=  1;
a -= 4;
} while(a>0);
}
return b;
}






int main() {
 int a;
 int b = 20;

 printf("make the variable a equals to:\n");
 scanf("%d\n", &a);

 func1(a,b);
 func2(a,b);
 func3(a,b);

 printf("func4 returns: %d\n", func4(a,b));
 return 0;
}

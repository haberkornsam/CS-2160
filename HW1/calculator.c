#include<stdio.h>
#include"hex_plus.h"


#define NUM_DIGIT 4

int main() {
	char num1[NUM_DIGIT+1];		// extra 1 byte to hold a char of null
	char num2[NUM_DIGIT+1];

	printf("enter the first hex number (4-digit, unsigned):\n");
	scanf("%s", num1);

	printf("enter the second hex number (4-digit, unsigned):\n");
	scanf("%s", num2);

	printf("unsigned summation result: 0x%x\n", hex_plus_unsigned(num1, num2, NUM_DIGIT));

	return 0;
}

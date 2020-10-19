#include<stdio.h>
#include "func.h"


int main() {

int num = 5;

printf("returned value: %d\n", func(0xa, 0x14, 0x3, 0xa1, 'a', &num, 0x31, 0x27, 0xc, 0xa ));
	return 0;
}

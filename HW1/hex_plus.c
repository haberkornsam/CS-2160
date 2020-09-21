#include "hex_plus.h"
#include "stdio.h"

unsigned int power_function(int number, int power);

unsigned int hex_plus_unsigned(char *num1, char *num2, int digit_num) {
	unsigned int decimal_num = 0;
	for(int i=0; i<digit_num; i++){
	    if(num1[i] >= '0' && num1[i] <= '9'){
	        decimal_num += (num1[i]-'0') * power_function(16, digit_num-i-1);
	    }
	    else if(num1[i] >= 'A' && num1[i]<='Z'){
	        decimal_num += ((num1[i]-'A')+10) * power_function(16, digit_num-i-1);
	    }
        else if(num1[i] >= 'a' && num1[i]<='z'){
            decimal_num += ((num1[i]-'a')+10) * power_function(16, digit_num-i-1);
        }
	}
    for(int j=0; j<digit_num; j++){
        if(num2[j] >= '0' && num2[j] <= '9'){
            decimal_num += (num2[j]-'0') * power_function(16, digit_num-j-1);
        }
        else if(num2[j] >= 'A' && num2[j]<='Z'){
            decimal_num += ((num2[j]-'A')+10) * power_function(16, digit_num-j-1);
        }
        else if(num2[j] >= 'a' && num2[j]<='z'){
            decimal_num += ((num2[j]-'a')+10) * power_function(16, digit_num-j-1);
        }
    }
	return decimal_num;
}

unsigned int power_function(int number, int power){
    unsigned int sum = 1;
    for (int i=0; i<power; i++){
        sum *= number;
    }
    return sum;
}


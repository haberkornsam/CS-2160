#include <stdio.h>

int main() {
    unsigned short int te = 1;

    //Check the size of a pointer as that is the size of a memory address
    printf("This is a %lu bit machine", sizeof(int*)*8);

    //take the char version of a short int. (this is the first half of the number)
    // If they are the same then it is lil endian
    unsigned char* temp = &te;
    if (*temp == 1){
        printf("\nThis is little endian");
    }
    else {
        printf("\nThis is big endian");
    }
    return 0;
}

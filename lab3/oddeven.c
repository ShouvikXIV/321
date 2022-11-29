#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argv) {

        if(argv % 2 == 0)
            printf("%d is even.", argv);
        else
            printf("%d is odd.", argv);
    
    
    
    return 0;
}
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
    fork();
    const char *str;
    scanf("%s",str);
    execl("oddeven",str);
    // execl("sort","1","2","3");
    return 0;
}
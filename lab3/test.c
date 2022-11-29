#include<stdio.h>
#include<string.h>
#include<sys/types.h>
int main()
{
    pid_t s = fork();
    printf("%d\n",s);
    if(s==0)
    {
        int x = getpid();
        printf("%d",x);
    }

return 0;
}
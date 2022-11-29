#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
    pid_t q;
    q = fork();
    if(q==0)
    {
        
        printf("I am a grandchild\n");
        
    }
    else
    {
        q = fork();
        if(q==0)
        {
            printf("I am a child\n");
        }
        else
        {
            q = fork();
            if(q==0)
            {
                printf("I am a parent");
            }
        }
    }
    return 0;
}
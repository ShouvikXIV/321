#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int g = 0;
int h = 0;
int y = 0;
int fun(long long int x,int c)
{
    

    if(x%2==0)
    {
        // printf("%d\n",c);
        return c;
    }
    else
    {
        c+=1;
        pid_t n = fork();
        if(n==0)
        {
            int x = getpid();
            fun(x,c);
        }
        
    }
}


int main()
{
    int counter = 0;
    pid_t a = fork();
    pid_t b = fork();
    pid_t c = fork();
    if(a==0)
    {
        int x = getpid();
        // printf("%d\n",x);
        if(x%2!=0)
        {
           g = fun(x,counter);
        //    printf("%d",g);
        }
    }

    

    // printf("%d\n",d1);
    if(b==0)
    {
        int x = getpid();
        // printf("%d\n",x);
        if(x%2!=0)
        {
            h = fun(x,counter);
        }
    }
    if(c==0)
    {
        int x = getpid();
        if(x%2!=0)
        {
            y = fun(x,counter);
        }
    }

    counter = g+h+y;
    printf("%d\n",counter);
    return 0;
}
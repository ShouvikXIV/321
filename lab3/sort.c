#include <stdio.h>
#include<unistd.h>>
#include<stdlib.h>
int main (int argc,char* argv[])
{
int i, j, a, n;
for (i = 0; i < argc; ++i) 
{
    for (j = i + 1; j < argc; ++j) 
    {
        if (argv[i] < argv[j]) 
        {
            a = argv[i];
            argv[i] = argv[j];
            argv[j] = a;
        }
    }
}
for (i = 0; i < argc; ++i) 
{
    printf("%d ", argv[i]);
}
return 0;
}
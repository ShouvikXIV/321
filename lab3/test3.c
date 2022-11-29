#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
#include<stdbool.h>
int main()
{

int n,fd;

fd = open("test.txt",O_CREAT|O_WRONLY,0642);
bool c = true;
while(c)
{
char buff[1000];
scanf("%s",buff);
printf("%s\n",buff);
if(buff=="-1\n")
{
break;
}
else
{
strcat(buff,"\n");
puts(buff);
write(fd,buff,strlen(buff)); 
}

}





return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>
int j = 0;
int p = 1;
void *ThreadFun(void *vargp)
{
    
	printf("thread-%d prints %d\n",j,p);
	j+=1;
    p+=1;
    return NULL;

}

int main()
{
	
    for (int i = 0; i <= 5; i++)
    {
    j+=1;
    pthread_t thread_id;
	pthread_create(&thread_id, NULL, ThreadFun, NULL);
	pthread_join(thread_id, NULL);
	printf("Thread %d prints %d\n",j,p);
    }
    exit(0);
    
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>
#include <string.h>

int *ThreadFun(void *vargp)
{
    
	char name[100];
    scanf("%s",name);
    int sum = 0;
    int n = strlen(name);
    int i;
for (i = 0; i < n; i++) {

sum += (int)(name[i]);
}

printf("%d",sum);

}

int *ThreadFun2(void *vargp)
{
    
	char name[100];
    scanf("%s",name);
    int sum = 0;
    int n = strlen(name);
    int i;
for (i = 0; i < n; i++) {

sum += (int)(name[i]);
}

printf("%d",sum);

}

int *ThreadFun3(void *vargp)
{
    
	char name[100];
    scanf("%s",name);
    int sum = 0;
    int n = strlen(name);
    int i;
for (i = 0; i < n; i++) {

sum += (int)(name[i]);
}

printf("%d",sum);

}

int main()
{
	
    pthread_t thread_id;
	pthread_create(&thread_id, NULL, ThreadFun, NULL);
	pthread_join(thread_id, NULL);
    exit(0);
    pthread_t thread_id2;
	pthread_create(&thread_id2, NULL, ThreadFun2, NULL);
	pthread_join(thread_id2, NULL);
    exit(0);
    pthread_t thread_id3;
	pthread_create(&thread_id3, NULL, ThreadFun3, NULL);
	pthread_join(thread_id3, NULL);
    exit(0);
    
}


#include <stdio.h>
#include<stdbool.h>


void queueUpdate(int queue[],int timer,int arrival[],int n, int maxProccessIndex){
	int zeroIndex, i;
	for( i = 0; i < n; i++){
		if(queue[i] == 0){
			zeroIndex = i;
			break;
		}
	}
	queue[zeroIndex] = maxProccessIndex + 1;
}

void queueMaintain(int queue[], int n){
	int i;
	for( i = 0; (i < n-1) && (queue[i+1] != 0) ; i++){
		int temp = queue[i];
		queue[i] = queue[i+1];
		queue[i+1] = temp;
	}
}

void checkNewArrival(int timer, int arrival[], int n, int maxProccessIndex,int queue[]){
	if(timer <= arrival[n-1]){
	bool newArrival = false;
	int j;
	for( j = (maxProccessIndex+1); j < n; j++){
			if(arrival[j] <= timer){
			if(maxProccessIndex < j){
				maxProccessIndex = j;
				newArrival = true;
			}
		}
	}	
	if(newArrival)
		queueUpdate(queue,timer,arrival,n, maxProccessIndex);
	}
}

int main(){
	int n,tq, timer = 0, maxProccessIndex = 0,i;
	float avgWait = 0, avgTT = 0;
    tq = 20;
	printf( "\nNumber of processes : ");
	scanf("%d",&n);
	int arrival[n], burst[n], wait[n], turn[n], queue[n], temp_burst[n];
	bool complete[n];

	printf( "\nArrival time of the processes : ");
	for(i = 0; i < n; i++)
		scanf("%d",&arrival[i]);

	printf("\nBurst time of the processes : ");
	for( i = 0; i < n; i++){
		scanf("%d",&burst[i]);
		temp_burst[i] = burst[i];
	}

	for( i = 0; i < n; i++){ 
		complete[i] = false;
		queue[i] = 0;
	}
	while(timer < arrival[0]) 
		timer++;
	queue[0] = 1;
	
	while(true){
		bool flag = true;
		for( i = 0; i < n; i++){
			if(temp_burst[i] != 0){
				flag = false;
				break;
			}
		}
		if(flag)
			break;

		for( i = 0; (i < n) && (queue[i] != 0); i++){
			int ctr = 0;
			while((ctr < tq) && (temp_burst[queue[0]-1] > 0)){
				temp_burst[queue[0]-1] -= 1;
				timer += 1;
				ctr++;

				checkNewArrival(timer, arrival, n, maxProccessIndex, queue);
			}
			
			if((temp_burst[queue[0]-1] == 0) && (complete[queue[0]-1] == false)){
				
				turn[queue[0]-1] = timer;	
				complete[queue[0]-1] = true;
			}
			
			bool idle = true;
			if(queue[n-1] == 0){
				for(int i = 0; i < n && queue[i] != 0; i++){
					if(complete[queue[i]-1] == false){
						idle = false;
					}
				}
			}
			else
				idle = false;

			if(idle){
				timer++;
				checkNewArrival(timer, arrival, n, maxProccessIndex, queue);
			}
	
			
			queueMaintain(queue,n);
		}
	}

	for(i = 0; i < n; i++){
		turn[i] = turn[i] - arrival[i];
		wait[i] = turn[i] - burst[i];
	}

	printf("\nAT\t BT\t WT\t TAT\n");
		
	for( i = 0; i < n; i++){
		printf("%d\t %d\t %d\t %d\n",i+1, arrival[i],burst[i],wait[i],turn[i]);
		
		
	}
	for( i =0; i< n; i++){
		avgWait += wait[i];
		avgTT += turn[i];
	}
	printf("\nAverage wait time : %d\nAverage Turn Around Time : %d ",(avgWait),(avgTT));

	return 0;
	
}


/*쓰레드 인자 전달하기*/

#include <stdio.h>
#include <pthread.h>

#define NUMBER 5

void *create_thread(void *arg){
	printf("안녕하세요!! %d번째 쓰레드입니다.\n", arg+1);
	return arg;
}

int main(){
	pthread_t tid[NUMBER];
	int status;
	
	for(int i =0; i<NUMBER; i++){
		status = pthread_create(&tid[i], NULL, create_thread,(void *)i);
		if(status != 0){
			fprintf(stderr,"Create thread %d : %d", i, status);
			exit(1);
		}
	}
	pthread_exit(NULL);
}


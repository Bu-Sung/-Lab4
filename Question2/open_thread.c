/*쓰레드 열고 닫기 예제*/

#include <pthread.h>
#include <stdio.h>

void *create_thread(void *arg){
	printf("쓰레드를 생성했어요!!ㅎㅎ\n");
	return arg;
}

int main(){
	pthread_t tid;
	int status;
	
	/*쓰레드 생성하기*/
	status = pthread_create(&tid,NULL,create_thread,NULL);
	if(status != 0)
		perror("Create thread");
	/*쓰레드 종료하기*/
	pthread_exit(NULL);

}

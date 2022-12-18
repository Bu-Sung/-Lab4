#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

#define CLIENT_NUM 3 //클라이언트 수

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_t ctid[CLIENT_NUM]; //클라이언트 쓰레드
pthread_t stid; //서버 쓰레드

int status = 0;
int co = 1; //메시지가 전송된 클라이언트 수
int num;

/*클라이언트(자식) 쓰레드 함수*/
void *child_thread(void *arg){
	while(1){
		sleep(1);	
		pthread_mutex_lock(&mutex); // 뮤텍스 락
		if(status==0){ 
			num = rand()%100;
			printf("===========================================================\n\n");
			printf("쓰레드[%d] 메시지 전송 요청 : %d\n", arg, num);
			status=2; //메시지 전송 요청이 된 상태
		}
		/*모든 클라이언트가 대기 상태가 되어야 조건변수 broadcast로 쓰레드를 모두 깨워서 공지*/
		co++; // 클라이언트 수 추가
		if(co == CLIENT_NUM) // 총 클라이언트 수 충족
			status = 1;  // 서버가 메시지를 공지하는 상태
		pthread_cond_wait(&cond, &mutex); // 클라이언트 대기
		printf("\t\t\t\t쓰레드[%d] 메시지 수신 : %d\n", arg, num);
		status = 0;
		pthread_mutex_unlock(&mutex); // 뮤텍스 언락
	}
}

/*서버(부모) 쓰레드 함수*/
void *parent_thread(){
	while(1){
		sleep(1);
		if(status==1){ // 클라이언트의 전송 요청
			pthread_mutex_lock(&mutex); // 뮤텍스 락
			printf("-----------------------------------------------------------\n");
			printf("\t\t서버 : 메세지 전송 요청이 왔습니다!\n");
			printf("-----------------------------------------------------------\n");
			pthread_cond_broadcast(&cond); // 대기 중인 쓰레드 모두 깨우기
			status = 0;// 메시지 요청을 받을 수 있는 상태	
			co = 0; // 클라이언트 수 초기화
			pthread_mutex_unlock(&mutex); // 뮤텍스 언락
		}
	}
}

void main(){

	srand((unsigned)time(NULL));
	
	for(int i=0; i <CLIENT_NUM; i++){
		pthread_create(&ctid[i], NULL, child_thread, (void*)i);
	}
	
	pthread_create(&stid, NULL, parent_thread, NULL);
	
	pthread_join(stid,NULL);
	for(int i=0;i<CLIENT_NUM;i++){
		pthread_join(ctid[i],NULL);
	}
	
	pthread_mutex_destroy(&mutex);
	pthread_cond_destroy(&cond);
}

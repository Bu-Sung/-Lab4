#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define BUFFER_SIZE 5
#define NUMITEMS 10
#define TXT_NUM 50 //전송 글자 수
#define CLIENT_NUM 3 //클라이언트 수

typedef struct{
	char *item[BUFFER_SIZE];
	int totalitems;
	int in,out;
	pthread_mutex_t mutex;
	pthread_cond_t full;
	pthread_cond_t empty;
} buufer_t;


buffer_t bb = { {NULL,NULL,NULL,NULL,NULL}, 0,0,0,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_COND_INITIALIZER,
	PTHREAD_COND_INITIALIZER
};

int client_item(void* arg,char txt[TXT_NUM]){
	sleep((unsigned long)(5.0*rand()/(RAND_MAX+1.0)));
	printf("%s째 클라이언트가 메시지를 요청합니다.",arg);
	return txt;
}

insert_item(char txt[TXT_NUM]){
	int status;
	status = pthread_mutex_lock (&bb.mutex);
	if (status != 0)
		return status;
	while (bb.totalitems >= BUFFER_SIZE && status ==NULL)
		status = pthread_cond_wait (&bb.empty,&bb.mutex);
	
	if (status != 0) {
		pthread_mutex_unlock(&bb.mutex);
		return status;
	}

	bb.item[bb.in] = item;
	bb.in = (bb.in + 1) % BUFFER_SIZE;
	bb.totalitems++;

	if (status = pthread_cond_signal(&bb.full)) {
		pthread_mutex_unlock (&bb.mutex);
		return status;
	}
	return pthread_mutex_unlock (&bb.mutex);
}

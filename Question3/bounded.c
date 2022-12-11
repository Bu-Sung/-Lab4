#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

#define BUFFER_SIZE 20
#define NUMITEMS 30
#define PRODUCE_NUM 3 //생상자 3명
#define CONSUME_NUM 3 // 소비자 3명

/*버퍼 구조체*/
typedef struct {
	int item[BUFFER_SIZE];
	int totalitems;
	int in, out;
	pthread_mutex_t mutex;
	pthread_cond_t full;
	pthread_cond_t empty;
} buffer_t;

/*버퍼 공간 생성*/
buffer_t bb = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 0, 0, 0,
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_COND_INITIALIZER,
	PTHREAD_COND_INITIALIZER
};

/*생산자 아이템 생성*/
int produce_item (void *arg)
{
	int item = (int) (100.0*rand()/(RAND_MAX+1.0));
	sleep((unsigned long) (5.0*rand()/(RAND_MAX+1.0)));
	printf("%d번째 생산자 : item = %d\n", arg,item);
	return item;
}

/*생산자 아이템 집어넣기*/
insert_item (int item)
{
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

/*소비자가 가져간 아이템 출력*/
consume_item (int item, void* arg){
	sleep((unsigned long) (5.0*rand()/(RAND_MAX+1.0)));
	printf("\t\t\t%d번째 소비자 : item = %d\n",arg, item);
}

/*소비자가 아이템 가져가기*/
remove_item (int *temp){
	int status;
	status = pthread_mutex_lock (&bb.mutex);
	if (status != 0)
		return status;
	while (bb.totalitems <= 0 && status == NULL) status = pthread_cond_wait (&bb.full, &bb.mutex);
	if (status != 0) {
		pthread_mutex_unlock(&bb.mutex);
		return status;
	}
	
	*temp = bb.item[bb.out];
	bb.out = (bb.out + 1) % BUFFER_SIZE;
	bb.totalitems--;
	if (status = pthread_cond_signal(&bb.empty)) {
		pthread_mutex_unlock (&bb.mutex);
		return status;
	}
	return pthread_mutex_unlock (&bb.mutex);
}

/*생산자*/
void * producer(void *arg){
	int item;
	while (1) {
		item = produce_item (arg);
		insert_item(item);
	}
}

/*소비자*/
void * consumer(void *arg){
	int item;
	while (1) {
		remove_item (&item);
		consume_item (item, arg);
	}
}

int main (){
	int status;
	void *result;
	pthread_t producer_tid[PRODUCE_NUM], consumer_tid[CONSUME_NUM];
	
	
	/* 생산자 쓰레드 배열 생성 */
	for(int i=0 ;i<PRODUCE_NUM;i++){
		/*생산자 쓰레드 생성*/
		status = pthread_create (&producer_tid[i], NULL, producer, (void *) i);
		if (status != 0)
			perror ("Create producer thread");		
	}
	
	/*소비자 쓰레드 배열 생성*/
	for(int i=0; i <CONSUME_NUM; i++){
		/*소비자 쓰레드 생성*/
		status = pthread_create (&consumer_tid[i], NULL, consumer, (void *)i);
		if (status != 0)
			perror ("Create consumer thread");
	}		
	
	/*생산자 쓰레드 결합*/
	for(int i=0 ;i<PRODUCE_NUM;i++){
		status = pthread_join (producer_tid[i], NULL);
		if (status != 0)
			perror ("Join producer thread");
	}	
	
	/*소비자 쓰레드 결합*/
	for(int i=0; i <CONSUME_NUM; i++){
		status = pthread_join (consumer_tid[i], NULL);
		if (status != 0)
			perror ("Join consumer thread");
	}
}


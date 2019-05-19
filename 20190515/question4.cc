#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <pthread.h>
#include <unistd.h>

class MutexLock{
	public:
		MutexLock();
		pthread_mutex_t *getMutex();
		void lock();
		void unlock();
		~MutexLock();
	private:
		pthread_mutex_t *_mutex;
};

MutexLock::MutexLock()
:_mutex(new pthread_mutex_t){
	printf("MutexLock()\n");
	pthread_mutex_init(_mutex, NULL);
}

pthread_mutex_t *MutexLock::getMutex(){
	return _mutex;
}

void MutexLock::lock(){
	pthread_mutex_lock(_mutex);
}

void MutexLock::unlock(){
	pthread_mutex_unlock(_mutex);
}

MutexLock::~MutexLock(){
	delete _mutex;
	printf("~MutexLock()\n");
}


class Condition{
	public:
		Condition();
		void wait();
		void notify();
		void notifyall();
		~Condition();
	private:
		pthread_cond_t *_cond;
		MutexLock _condMutex;
		pthread_mutex_t *mutex;
};

Condition::Condition()
:_cond(new pthread_cond_t()), _condMutex(), _mutex(new pthread_cond_t()){
	pthread_cond_init(_cond, NULL);
	_mutex = _condMutex.getMutex();
	printf("Condition()\n");
}


void Condition::wait(){
	pthread_cond_wait(_cond, _mutex);
}

void Condition::notify(){
	pthread_cond_signal(_cond);
}

void Condition::notifyall(){
	pthread_cond_broadcast(_cond);
}

Condition::~Condition(){
	delete _cond;
	delete _mutex;
	_condMutex.~MutexLock();
	printf("~Condition()\n");
}



//typedef struct{
//	int tickets;
//	pthread_mutex_t mutex;
//	pthread_cond_t cond;
//}Train;
class Ticket{
	public:
		Ticket();
		~Ticket();
	public:
		int tickets;
		Condition cond;
};

Ticket::Ticket()
:cond(), {
	printf("Ticket()\n");
}

Ticket::~Ticket(){
	printf("~Ticket()\n");
}


void* saleWindows1(void* p)
{
	Ticket *pSale = (Ticket *)p;
	int count=0;
	while(1)
	{
		pSale->cond._condMutex.lock();
		if(pSale->tickets>0)
		{
			pSale->tickets--;
			if(0==pSale->tickets)
			{
				pSale->cond.notify();
			}
			count++;
			pSale->cond._condMutex.unlock();
		}else{
			pSale->cond._condMutex.unlock();
			printf("I am windows1 sale %d\n",count);
			break;
		}
	}
	return NULL;
}


//void* saleWindows1(void* p)
//{
//	Ticket *pSale = (Ticket *)p;
//	int count=0;
//	while(1)
//	{
//		pSale->cond._condMutex.lock();
//		if(pSale->tickets>0)
//		{
//			pSale->tickets--;
//			if(0==pSale->tickets)
//			{
//				pSale->cond.notify();
//			}
//			count++;
//			pSale->cond._condMutex.unlock();
//		}else{
//			pSale->cond._condMutex.lock();
//			printf("I am windows1 sale %d\n",count);
//			break;
//		}
//	}
//	return NULL;
//}
void* saleWindows2(void* p)
{
	Ticket *pSale = (Ticket *)p;
	int count=0;
	while(1)
	{
		pSale->cond._condMutex.lock();
		if(pSale->tickets>0)
		{
			pSale->tickets--;
			if(0==pSale->tickets)
			{
				pSale->cond.notify();
			}
			count++;
			pSale->cond._condMutex.unlock();
		}else{
			pSale->cond._condMutex.unlock();
			printf("I am windows2 sale %d\n",count);
			break;
		}
	}
	return NULL;
}
void* setTickets(void* p)
{
	Ticket *pSale = (Ticket *)p;
	pSale->cond._condMutex.lock();
	if(pSale->tickets>0)
	{
		pSale->cond.wait();
	}
	pSale->tickets = 5000;

	pSale->cond._condMutex.unlock();
	return NULL;
}
typedef void* (*threadFunc)(void*);
#define N 3
int main()
{
	Ticket tk;

	pthread_t pthId[N];
	int i;
	threadFunc pthreadFunc[N]={saleWindows1,saleWindows2,setTickets};
	for(i=0;i<N;i++)
	{
		pthread_create(pthId+i,NULL,pthreadFunc[i],&tk);
	}
	for(i=0;i<N;i++)
	{
		pthread_join(pthId[i],NULL);
	}
	printf("sale over\n");
}


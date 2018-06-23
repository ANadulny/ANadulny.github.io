#include <iostream>
#include "monitor.h"
#include<time.h>

#define PRODUCER_NR 3
#define CONSUMER_NR 4
#define MAX_SIZE 21 // max elementów w buforze
#define SLEEP_TIME 300 // 0.5s

using namespace std;

class MyMonitor : private Monitor
{

private:

	Condition empty, full, producer, consumer;
    int count;

    int producerCounter;
    int consumerCounter;

    int que[MAX_SIZE];
    std::size_t head, tail;

    void remove()
    {
        head = (head+1) % (MAX_SIZE);
    }

public:

    MyMonitor()
    {
        count=tail=head=0;
        producerCounter = 0;
        consumerCounter = 0;
    }

	//producerN
    void producerN(int num, int item)
    {
        //cout<<"Producer"<< num <<" tries to enter critical section\n";
        //puts("Producer tries to enter critical section");
        enter();

        if(producerCounter > 0) wait(producer);

        producerCounter++;

        cout<<"Producer"<< num <<" entered critical section\n";
        //while(count>MAX_SIZE-num) wait(full);

        //if(count>MAX_SIZE-num) wait(full);

        for(int i=0; i<num*2 ; i++)
        {
            //if(count>MAX_SIZE-num) wait(full);
            if(count==MAX_SIZE) wait(full);

            que[tail] = item;
            tail = (tail+1) %(MAX_SIZE);
            count++;
            cout<<"P: add "<<count<<'\n';
            if(count==1) signal(empty);
        }

        cout<<"Producer"<< num <<" produced "<<num*2<<" items                 "<<count<<'\n';

        //if(count>0) signal(empty);


        producerCounter--;
        if (producerCounter > 0) signal (producer);

        cout<<"Producer"<< num <<" leaves critical section\n";
        leave();
    }

    //consumerN
    void consumerN(int num)
    {
        //cout<<"Consumer"<< num <<" tries to enter critical section\n";
        //puts("Consumer tries to enter critical section");

        //while(consumerCounter == false) wait(consumer);

        enter();
        if(consumerCounter > 0) wait(consumer);
        consumerCounter++;

        cout<<"Consumer"<< num <<" entered critical section\n";
        //while(count<num) wait(empty);

        for(int i=0; i<num+2; i++)
        {
            if(count==0) wait(empty);

            remove();
            --count;
            cout<<"C: remove "<<count<<'\n';
            if(count == MAX_SIZE-1) signal(full);
        }

        consumerCounter--;

        cout<<"Consumer"<< num <<" removed "<<num+2<<" items                "<<count<<'\n';

        if (consumerCounter > 0) signal(consumer);

        cout<<"Consumer"<< num <<" leaves critical section\n";
        leave();
    }
};

void* producer(void *arg);
void* consumer(void* arg);

MyMonitor mon;

int main()
{
/*
    pthread_t threads[PRODUCER_NR + CONSUMER_NR];
    int rc;
    int i;

    for( i = 0; i < PRODUCER_NR; i++ ) {
       cout << "main() : creating thread for producer, " << i << endl;
       rc = pthread_create(&threads[i], NULL, producer, &i);

       if (rc) {
          cout << "Error:unable to create thread," << rc << endl;
          exit(-1);
       }
    }

    for(int j=0  ; i < PRODUCER_NR + CONSUMER_NR; i++, j++ ) {
       cout << "main() : creating thread for consumer, " << i << endl;
       rc = pthread_create(&threads[i], NULL, consumer, &j);

       if (rc) {
          cout << "Error:unable to create thread," << rc << endl;
          exit(-1);
       }
    }

    for(i=0  ; i < PRODUCER_NR + CONSUMER_NR; i++) {
       pthread_join(threads[i], NULL);
    }
*/
    pthread_t consA, consB, prodA, prodB, consC, prodC;
    int i = 0 ;
    int j = 1;
    int c = 2;
    pthread_create(&prodA, NULL, producer, &i);
    pthread_create(&consA, NULL, consumer, &i);
    pthread_create(&prodB, NULL, producer, &j);
    pthread_create(&consB, NULL, consumer, &j);
    pthread_create(&prodC, NULL, producer, &c);
    //pthread_create(&consC, NULL, consumer , &c);
    pthread_exit(NULL);
}

void* producer(void* arg)
{
    int num = *((int *)arg);
    num++;
    int item = num * 2 + 1;
    while(true)
    {
        Sleep(SLEEP_TIME);
        mon.producerN(num, item);
    }
}

void* consumer(void* arg)
{
    int num = *((int *)arg);
    num++;
    while(true)
    {
        Sleep(SLEEP_TIME);
        mon.consumerN(num);
    }
}

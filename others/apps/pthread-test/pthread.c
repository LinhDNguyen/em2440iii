/*************************************

NAME:pthread.c
COPYRIGHT:www.embedsky.net

*************************************/

#include<stddef.h>
#include<stdio.h>
#include<unistd.h>
#include"pthread.h"

void reader_function(void);
void writer_function(void);
char buffer;
int buffer_has_item=0;
pthread_mutex_t mutex;
main()
{
    pthread_t reader;
    pthread_mutex_init(&mutex,NULL);
    pthread_create(&reader,NULL,(void*)&reader_function,NULL);
    writer_function();
return 0;
}
void writer_function(void)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        if(buffer_has_item==0)
        {
	    buffer='s';
            printf("write test\n");
            buffer_has_item=1;
        }
        pthread_mutex_unlock(&mutex);
    }
}
void reader_function(void)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        if(buffer_has_item==1)
        {
	    buffer='\0';
            printf("read test\n");
            buffer_has_item=0;
        }
        pthread_mutex_unlock(&mutex);
    }
}

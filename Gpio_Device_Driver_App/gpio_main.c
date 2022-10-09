#include "user_basic.h"
#include "user_ioctl.h"
#include "user_poll.h"

int main(void)
{
    pthread_t thread[2];
    int thread_id;
    int status;

    thread_id = pthread_create(&thread[0],NULL,pthread_ioctl,(void*)0);

    if(thread_id < 0)
    {
        perror("thread create err\r\n");
        exit(1);
    }
#if 0
    thread_id = pthread_create(&thread[1],NULL,pthread_poll,(void*)0);

    if(thread_id < 0)
    {
        perror("thread create err\r\n");
        exit(1);
    }
#endif
    pthread_join(thread[0],(void**)status);
//    pthread_join(thread[1],(void**)status);

    return 0;
}
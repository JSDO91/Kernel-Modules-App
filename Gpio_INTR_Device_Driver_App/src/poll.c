#include "user_poll.h"

int GpioINTRDevInit(struct pollfd* pfds, short events)
{
    pfds->fd = open(INTR_DEVICE_PATH, O_RDWR|O_NONBLOCK);
    if(pfds->fd < 0) 
    {
        printf("Cannot open %s...\n",INTR_DEVICE_PATH);
        return -1;
    }

    pfds->events = events;

    return 0;
}

int GpioINTRWait(struct pollfd* pfds, unsigned long int numberfd, int timeouttime)
{
    int ret;
    static int timeout = 0;
    int donecnt = 0;
    struct timeval start,end;
    double diff;

    gettimeofday(&start, NULL);
    ret = poll(pfds,numberfd,timeouttime);
    gettimeofday(&end, NULL);
    diff = end.tv_sec + end.tv_usec / 1000000.0 - start.tv_sec - start.tv_usec / 1000000.0;
    
    if( ret > 0 ) 
    {
        if(pfds->revents == (POLLIN | POLLRDNORM))
        {
            donecnt++;
        }
    }
    else if(ret == 0)
    {
        timeout++;
        printf("[%d]intr time out %d interval %f\n",ret,timeout,diff);
    }
    else
    {
        printf("poll return failed %d\n",ret);
        return -1;
    }

    return ret;
}
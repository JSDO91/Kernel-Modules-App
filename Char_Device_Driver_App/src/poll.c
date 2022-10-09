#include "user_poll.h"

void* pthread_poll(void* data)
{
    struct pollfd pfds;
    int ret;
    int timeout = 0;
    int donecnt = 0;

    pfds.fd = open(DEVICE_PATH, O_RDWR|O_NONBLOCK);
    printf("[%s]%s:%d\r\n",__func__,DEVICE_PATH,pfds.fd);

    if(pfds.fd < 0) 
    {
        printf("Cannot open device file...\n");
        exit(1);
    }

    pfds.events = (POLLIN | POLLRDNORM | POLLOUT | POLLWRNORM);

    while(1)
    {
        printf("timeout:%5d, donecnt:%5d 0x%5X\r\n", timeout, donecnt, pfds.revents);
        ret = poll(&pfds,1,5000);

        if( ret > 0 ) 
        {
            if(pfds.revents == (POLLIN | POLLRDNORM))
            {
                donecnt++;
            }
        }
        else if(ret == 0)
        {
            timeout++;
        }
        else
        {
            perror("poll");
            exit(1);
        }
    }

    close(pfds.fd);
}
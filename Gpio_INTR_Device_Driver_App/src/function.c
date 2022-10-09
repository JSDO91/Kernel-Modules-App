#include "user_ioctl.h"
#include "user_poll.h"

void* pthread_ioctl(void* data)
{
#if 0
    int fd;
    int ret_val;

    printf("IOCTL Thread Start\n");

    fd = GpioDevInit();
    
    if(fd < 0)
    {
        exit(1);
    }

    GpioAssign(fd,17);
    GpioAssign(fd,18);

    GpioDir(fd,17,GPIO_DIR_IN);
    GpioDir(fd,18,GPIO_DIR_OUT);

    GpioSet(fd,18,GPIO_VAL_HI);
    ret_val = GpioGet(fd,17);

    printf("Read Gpio 17 : %d\n",ret_val);

    close(fd);

    printf("end thread\n");
#endif
    while(1);
}


void* pthread_poll(void* data)
{
    struct pollfd pfd;
    int intrcnt = 0;
    int ret;
    short events =  (POLLIN | POLLRDNORM | POLLOUT | POLLWRNORM);

    ret = GpioINTRDevInit(&pfd, events);
    if(ret < 0)
        return ;

    for(;;)
    {
        ret = GpioINTRWait(&pfd, 1, 5000);
        printf("intr release\n");

        if(ret == -1)
        {
            break;
        }

        intrcnt++;
    }
}
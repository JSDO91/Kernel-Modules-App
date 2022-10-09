#include "user_ioctl.h"

void* pthread_ioctl(void* data)
{
    int input;
    int fd;
    IOCTL_INFO ioctl_val;

    fd = open(DEVICE_PATH, O_RDWR|O_NONBLOCK);
    printf("[%s]%s:%d\r\n",__func__,DEVICE_PATH,fd);

    if(fd < 0) 
    {
        printf("Cannot open device file...\n");
        exit(1);
    }

    while(1)
    {
        scanf("%d",&input);
        ioctl(fd,IOCTL_WRITE,(IOCTL_INFO*)&ioctl_val);
    }

    close(fd);
}
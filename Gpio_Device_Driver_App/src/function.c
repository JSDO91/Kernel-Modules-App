#include "user_ioctl.h"

void* pthread_ioctl(void* data)
{
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

    while(1);
}
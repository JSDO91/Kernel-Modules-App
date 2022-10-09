#include "user_ioctl.h"

unsigned short gSizeOfGpioUserInfo = sizeof(GpioUserInfo);

int GpioDevInit()
{
    int fd;
    fd = open(DEVICE_PATH, O_RDWR|O_NONBLOCK);
    if(fd < 0) 
    {
        printf("Cannot open %s...\n",DEVICE_PATH);
        return -1;
    }

    return fd;
}

int GpioAssign(int fd, unsigned char GpioNum)
{
    int ret;
    GpioUserInfo GpioInterface;

    GpioInterface.cmd       = GPIO_ASSIGN;
    GpioInterface.gpioNum   = GpioNum;

    ret = ioctl(fd,IOCTL_WRITE,(GpioUserInfo*)&GpioInterface);
    if(ret < 0)
    {
        printf("IOCTL Assign Config Failed GPIO[%d]\n",GpioInterface.gpioNum);
        return -1;
    }

    return 1;
};

int GpioDir(int fd, unsigned char GpioNum, unsigned char Dir)
{
    int ret;
    GpioUserInfo GpioInterface;

    GpioInterface.cmd       = GPIO_DIR_CONFIG;
    GpioInterface.gpioNum   = GpioNum;
    GpioInterface.gpioDir   = Dir;
    GpioInterface.gpioValue = 0;

    ret = ioctl(fd,IOCTL_WRITE,(GpioUserInfo*)&GpioInterface);
    if(ret < 0)
    {
        printf("IOCTL Dir Config Failed GPIO[%d]\n",GpioInterface.gpioNum);
        return -1;
    }

    return ret;
}

int GpioSet(int fd, unsigned char GpioNum, unsigned char val)
{
    int ret;
    GpioUserInfo GpioInterface;

    GpioInterface.cmd       = GPIO_WR_CONFIG;
    GpioInterface.gpioNum   = GpioNum;
    GpioInterface.gpioValue = val;

    ret = write(fd,(GpioUserInfo*)&GpioInterface,gSizeOfGpioUserInfo);

    if(ret < 0)
    {
        printf("IOCTL Set Config Failed GPIO[%d]\n",GpioInterface.gpioNum);
        return -1;
    }

    return ret;
}

int GpioGet(int fd, unsigned char GpioNum)
{
    int ret;
    GpioUserInfo GpioInterface;

    GpioInterface.cmd       = GPIO_RD_CONFIG;
    GpioInterface.gpioNum   = GpioNum;

    ret = read(fd,(GpioUserInfo*)&GpioInterface,gSizeOfGpioUserInfo);

    if(ret < 0)
    {
        printf("IOCTL Get Config Failed GPIO[%d]\n",GpioInterface.gpioNum);
        return -1;
    }

    return ret;
}
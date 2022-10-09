#ifndef __USER_IOCTL_H__
#define __USER_IOCTL_H__

#include "user_basic.h"

// GPIO_USER_INTERFACE 
#define DEVICE_PATH "/dev/gpio_device"

#define GPIO_ASSIGN     0x10
#define GPIO_DIR_CONFIG 0x20
#define GPIO_WR_CONFIG  0x30
#define GPIO_RD_CONFIG  0x40

#define GPIO_DIR_IN     0x20
#define GPIO_DIR_OUT    0x21

#define GPIO_VAL_LO    0x00
#define GPIO_VAL_HI    0x01

typedef struct _gpiouserinfo_
{
  unsigned char cmd;
  unsigned char gpioNum;
  unsigned char gpioDir;
  unsigned char gpioValue;
}GpioUserInfo;
///////////////////////
extern unsigned short gSizeOfGpioUserInfo;

extern int GpioDevInit();
extern int GpioAssign(int fd,unsigned char GpioNum);
extern int GpioDir(int fd, unsigned char GpioNum, unsigned char Dir);
extern int GpioSet(int fd, unsigned char GpioNum, unsigned char val);
extern int GpioGet(int fd, unsigned char GpioNum);

#define IOCTL_MAGIC     'G'
#define IOCTL_READ      _IOR(IOCTL_MAGIC, 0, GpioUserInfo)
#define IOCTL_WRITE     _IOW(IOCTL_MAGIC, 1, GpioUserInfo)
#define IOCTL_STATUS    _IO(IOCTL_MAGIC, 2)
#define IOCTL_RW        _IOWR(IOCTL_MAGIC, 3, GpioUserInfo)
#define IOCTL_NR        4

#endif
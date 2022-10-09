#ifndef __USER_POLL_H__
#define __USER_POLL_H__
#include "user_function.h"
#include<sys/time.h>

#define INTR_DEVICE_PATH "/dev/intr_device"

extern int GpioINTRDevInit(struct pollfd* pfds, short events);
extern int GpioINTRWait(struct pollfd* pfds, unsigned long int numberfd, int timeout);

#endif
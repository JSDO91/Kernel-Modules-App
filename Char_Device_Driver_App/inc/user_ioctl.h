#ifndef __USER_IOCTL_H__
#define __USER_IOCTL_H__

#include "user_basic.h"

typedef struct _ioctl_info
{
    unsigned int size;
    unsigned char buff[USER_DATA_LEN];
}IOCTL_INFO;

extern void* pthread_ioctl(void* data);


#define IOCTL_MAGIC     'G'
#define IOCTL_READ      _IOR(IOCTL_MAGIC, 0, IOCTL_INFO)
#define IOCTL_WRITE     _IOW(IOCTL_MAGIC, 1, IOCTL_INFO)
#define IOCTL_STATUS    _IO(IOCTL_MAGIC, 2)
#define IOCTL_RW        _IOWR(IOCTL_MAGIC, 3, IOCTL_INFO)
#define IOCTL_NR        4

#endif
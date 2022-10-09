#ifndef __USER_BASIC_H__
#define __USER_BASIC_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <pthread.h>
#include <poll.h>

extern void* pthread_ioctl(void* data);

#endif
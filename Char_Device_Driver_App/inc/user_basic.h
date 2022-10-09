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

#define DEVICE_PATH "/dev/jchardev"
#define MAX_BUFF_SIZE   1024

#define USER_DATA_LEN 1500

extern void Fn_Create_Pattern(unsigned char* buff_ptr, int size);
extern int Fn_Compare_Pattern(unsigned char* write_buff_ptr, unsigned char* read_buff_ptr,int size);
extern void Fn_Print_Buff(unsigned char *buff_ptr, int size);

#endif
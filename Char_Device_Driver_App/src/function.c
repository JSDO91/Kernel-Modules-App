#include "user_basic.h"

void Fn_Create_Pattern(unsigned char* buff_ptr, int size)
{
    int init   = 0;
    int seq    = 0;

    seq = rand()%0xFF;

    for(init = 0; init < size; init++, seq++)
    {
        buff_ptr[init] = seq&0xFF;
    }
}

int Fn_Compare_Pattern(unsigned char* write_buff_ptr, unsigned char* read_buff_ptr,int size)
{
    int init   = 0;
    int seq    = 0;

    for(init = 0; init < size; init++)
    {
        if(write_buff_ptr[init] != read_buff_ptr[init])
            return -init;
    }

    return 0;
}

void Fn_Print_Buff(unsigned char *buff_ptr, int size)
{
    int init = 0;
    for(init; init < size; init++)
        printf("[%5d]: %5d\r\n",init, buff_ptr[init]);
}
.SUFFIXES : .c .o
PRJ_ROOT_PATH=$(shell pwd)
PRJ_SRC_PATH=$(PRJ_ROOT_PATH)/src

CC=aarch64-linux-gnu-gcc

INC=-I$(PRJ_ROOT_PATH)/inc
LIBS=-lpthread
CFLAGS=-g -Wall $(INC)

OBJS=gpio_main.o $(PRJ_SRC_PATH)/ioctl.o $(PRJ_SRC_PATH)/poll.o $(PRJ_SRC_PATH)/function.o
SRCS=$(OBJS:.o=.c)

TARGET=gpio_main

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

dep: 
	$(CC) -M $(INC) $(SRCS) > .depend

clean:
	clear
	rm  -rf $(OBJS) $(TARGET) core

#include <stdio.h>
#include <fcntl.h> 
#include <stdlib.h> 
#define PATH "/sys/class/hwmon/hwmon2/temp1_input"


int main()
{
    int fd;
    int ret;
    char buf[250] = {0,};
    
    while(1)
    {
        fd = open(PATH, O_RDONLY);
        if(fd < 0)
        {
            printf("%s open error\r\n",PATH);
            exit(0);
        }
        
        ret = read(fd,buf,250);
        if (ret < 0)
        {
            printf("%s read Error\r\n",PATH);
            exit(0);
        }

        printf("[%d] temp:%s\r\n",ret,buf);

        sleep(5);
    }

    close(fd);

    return 0;
}
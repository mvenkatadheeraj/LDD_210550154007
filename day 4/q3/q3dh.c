#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int qd, k =0;
	char d_rd_buff[50];
	char *d_wr_buff = "this data is writing from user to kernel";
	while(d_wr_buff[k] != '\0')
	{
		k++;
	}

	qd = open("/dev/MyCharDevice",O_RDWR,0666);
	if(qd < 0)
	{
		printf("not able to open the device\n");
		return -1;
	}
	write(qd,d_wr_buff,i);
	read(qd,d_rd_buff,50);
	printf("the data the we got from kernel:\n\n%s\n",d_rd_buff);
	close(qd);
	return 0;
}

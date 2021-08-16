#include <sys/types.h> 
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int qd, d =0;
	char d_rd_buff[50];
	char *d_wr_buff = "the data  from user to kernel";

	while(d_wr_buff[d] != '\0')
	{
		d++;
	}

	fd = open("/dev/MyCharDevice",O_RDWR,666);
	if(qd < 0)  
	{
		printf("not able to open the device\n");
		return -1;
	}
	write(qd,d_wr_buff,d); 
	read(qd,d_rd_buff,50); 
	printf("the data the we got from kernel:\n\n%s\n",d_rd_buff); 
	close(qd); 
	return 0;
}

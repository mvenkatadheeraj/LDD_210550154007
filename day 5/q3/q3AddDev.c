#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int qd;
	int n[2];
	int result;
	printf("Enter two number for addition operation: ");
	scanf("%d %d",&n[0],&n[1]); 

	qd = open("/dev/AddDev",O_RDWR,0666); 
	if(qd < 0)
	{
		printf("Not able to open the device\n");
		return -1;
	}

	write(qd,n,sizeof(n));
	read(qd,&result,sizeof(result));
	printf("the result of addtion from kernel: %d\n",(int)result);
	close(qd);
	return 0;
}

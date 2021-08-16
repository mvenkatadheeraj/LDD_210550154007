#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int qd;
	int result;
	int n[2];
	
	printf("Enter the two number for multiplication operation: ");
	scanf("%d %d",&n[0],&n[1]);

	fd = open("/dev/MulDev",O_RDWR,0666);
	if(qd <0)
	{
		printf("the device not open\n");
		return -1;
	}

	write(qd,n,sizeof(n));
	read(qd,&result,sizeof(result));
	printf("the result of multiplication from kernel side: %d\n",result);
	close(qd);
	return 0;
}

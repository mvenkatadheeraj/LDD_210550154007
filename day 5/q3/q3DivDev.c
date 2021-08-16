#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int qd,result,n[2];
	printf("Enter two number for division operation: ");
	scanf("%d %d",&n[0],&n[1]);

	qd = open("/dev/DivDev",O_RDWR, 0777);
	if(qd <0)
	{
		printf("error opening device\n");
		return -1;
	}

	write(qd,num,sizeof(n));
	read(qd,&result,sizeof(result));
	printf("the result of division from kernel side: %d\n",result);
	close(qd);
	return 0;
}

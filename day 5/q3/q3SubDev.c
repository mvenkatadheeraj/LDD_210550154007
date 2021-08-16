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
	printf("enter two number for subtraction: ");
	scanf("%d %d",&n[0],&n[1]);

	qd = open("/dev/SubDev",O_RDWR,0777);
	if(qd <0)
	{
		printf("not able to oprn device\n");
		return -1;
	}

	write(qd,n,sizeof(n));
	read(qd,&result,sizeof(result));
	printf("the result of subtraction from kernel is: %d\n",result);
	close(qd);
	return 0;
}

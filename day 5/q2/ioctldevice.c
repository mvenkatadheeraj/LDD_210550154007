#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include "ioctl_cal_head.h" 


struct operator
{
	int n1;
	int n2;
	char operator;
};

int main()
{
	int qd, result;
	struct operator val;
	printf("Enter two number: ");
	scanf("%d %d",&val.num1,&val.num2); 
	
	printf("Enter the operation you want to do:\n'+' : Addition\n'-' : Subtraction\n'*' : Multiplication\n'/' : Division\n\nEnter Now:  ");
	scanf(" %c",&val.operator); 

	qd = open("/dev/MyIoctlCalDevice",O_RDWR,0666); 
	if(qd<0) 
	{
		printf("not able to open the device\n");
		return -1;
	}
	
	ioctl(qd, OPERATION, &val); 
	close(qd);
	return 0;
}

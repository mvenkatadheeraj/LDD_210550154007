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
};

int main()
{
	char op;
	int qd, result;
	struct operator val;
	printf("Enter two number: ");
	scanf("%d %d",&val.n1,&val.n2); 

	printf("Enter the operation you want to do\nEnter:\n'+' for Addition\n'-' for Subtraction\n'*' for Multiplication\n'/' for Division\n");
	scanf(" %c",&op); 

	qd = open("/dev/MyIoctlCalDevice",O_RDWR,0777); 
	if(fd<0) 
	{
		printf("not able to open the device\n");
		return -1;
	}
	
	switch(op) 
	{
		case '+': ioctl(qd, ADD, &val);
			  break;
		case '-': ioctl(qd,SUB, &val);
			  break;
		case '*': ioctl(qd, MUL,&val);
			  break;
		case '/': ioctl(qd,DIV,&val);
			  break;
		default:printf("invalid input\n");
			return -1;
			break;
	}
	close(qd); /
	return 0;
}

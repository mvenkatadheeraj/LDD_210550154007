#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int pd;
	
	pd = open("/dev/MyCharDevice",O_RDWR,666);
	 
	if(pd < 0)
	{
		printf("not able to open a device");
		return -1;
	}
	
	
	close(pd);
	
	
	return 0;
}

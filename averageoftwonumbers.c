#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include"headers.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("m venkata Dheeraj");

static int num1 = 7;
static int num2 = 67;

static int my_avg(void)
{
	static int aver;
	aver = my_avg(num1,num2);
	aver=aver/2;

	printk(KERN_ALERT "Average of two numbers :%d",aver);
	return 0;
}

static void my_exit(void)
{
	printk(KERN_ALERT"exit of averge of two numbers");
}


module_init(my_avg);
module_exit(my_exit);


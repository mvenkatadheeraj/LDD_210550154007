#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/string.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("m venkata dheeraj");

static int add(int,int);
static int mul(int,int);
static int sub(int,int);
static int div(int,int);

static char* opt ="add";
static int num1 =7;
static int num2 =9;

module_param(opt,charp,S_IRUGO);
module_param(num1,int,S_IRUGO);
module_param(num2,int,S_IRUGO);


static int param_init(void)
{
	if(strcmp(opt,"add")==0)
	{
	 printk(KERN_ALERT"add : %d\n",add(num1,num2));
	}
	else if(strcmp(opt,"sub")==0)
	{	
	 printk(KERN_ALERT "sub: %d\n",mul(num1,num2));
	}
	else if(strcmp(opt,"mul")==0)
	{

	 printk(KERN_ALERT "mul : %d\n",sub(num1,num2));
	}
	else if(strcmp(opt,"div")==0)
	{
	 printk(KERN_ALERT"div :%d\n",div(num1,num2));
	}	
	return 0;
}


static void param_exit(void)
{
	printk(KERN_ALERT "exiting from module");
}

static int add(int num1,int num2)
{
	return (num1+num2);
}

static int mul(int num1,int num2)
{
	return (num1*num2);
}

static int sub(int num1,int num2)
{
	return (num1-num2);
}

static int div(int num1,int num2)
{
	return (num1/num2);
}




module_init(param_init);
module_exit(param_exit);



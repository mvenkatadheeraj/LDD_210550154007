#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("m venkata dheeraj");

static int var_int = 2;

module_param(var_int,int,S_IRUGO);


static int param_int(void)
{
	
	printk(KERN_ALERT "int value : %d\n",var_int);

	return 0;
}

static void param_exit(void)
{
	printk(KERN_ALERT "exit module\n");
}


module_init(param_int);
module_exit(param_exit);

MODULE_DESCRIPTION("module parameter");

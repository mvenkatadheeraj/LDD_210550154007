#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("m venkata dheeraj");

int my_div(int ,int);

int my_div(num1,num2)
{
	printk(KERN_ALERT "Im in div\n");

	return (num1/num2);
}

EXPORT_SYMBOL_GPL(my_div);


static int my_fun(void)
{
	printk("hiii\n");
	return 0;
}
static void my_exit(void)
{
	printk(KERN_ALERT "exit from div");

}


module_init(my_fun);
module_exit(my_exit);



#include<linux/module.h>
#include<linux/init.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("m venkata Dheeraj");
static int  hello_init(void)
{
        printk("Hello World\n");
        return 0;
}

static void  hello_cleanup(void)
{
        printk("Good Bye all\n");
}

module_init(hello_init);
module_exit(hello_cleanup);

MODULE_DESCRIPTION(" hello_world ");

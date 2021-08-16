#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/kdev_t.h>
#include <linux/types.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/uaccess.h>
#include "ioctl_cal_head.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("m venkata dheeraj");


int my_open_fn(struct inode *inode, struct file *file_ioctl);
int my_release_fn(struct inode *inode, struct file *file_ioctl);
long my_ioctl_fn(struct file *file_ioctl,unsigned int cmd, unsigned long arg );


struct file_operations calop=
{
	.owner = THIS_MODULE,
	.open = my_open_fn,
	.unlocked_ioctl = my_ioctl_fn,
	.release = my_release_fn,
};


struct operator
{
	int n1;
	int n2;
};


int my_open_fn(struct inode *inode, struct file *file_ioctl)
{
	printk("ioctl device using ioctl cal driver\n");
	return 0;
}


long my_ioctl_fn(struct file *file_ioctl, unsigned int cmd,unsigned long arg)
{
	int o1,o2;
	struct operator *data;
	char u_buff[20];
	data = (struct operator *)u_buff; 
	copy_from_user(u_buff,(struct operator *)arg,sizeof(struct operator)); 
	o1 = data->n1;
	o2 = data->n2;
	switch(cmd) 
	{
		case ADD:printk("Addition operation begin\n");
			 int add_result = o1 + o2;
			 printk("the result of addtion: %d\n",add_result);
			 return 0;
			 break;
		case SUB:printk("Subtraction operation begin\n");
			 int sub_result = o1-o2;
			 printk("the result of subtraction: %d\n",sub_result);
			 return 0;
			 break;
		case MUL:printk("multiplication operation begin\n");
			 int mul_result =  o1*o2;
			 printk("the result of multiplication: %d\n",mul_result);
			 return 0;
			 break;
		case DIV:printk("division operation begin\n");
			 int div_result = o1/o2;
			 printk("the result of division: %d\n",div_result);
			 return 0;
			 break;
		default:printk("invalid option\n");
			return -1;
			break;
	}
	return 0;
}


int my_release_fn(struct inode *inode, struct file *file_ioctl)
{
	printk("the ioctl device now logg off from ioctl cal driver\n");
	return 0;
}

struct cdev *MyIoctlCalDevice; 
dev_t ioctl_cal_dn;

static int ioctl_driver_on(void)
{
	printk("welcome to ioctl based calculator driver module\n");
	int reg_result;
	int major,minor;
	reg_result = alloc_chrdev_region(&ioctl_cal_dn,0,1,"MyIoctlCalDriver"); 
	if(reg_result < 0)
	{
		printk("Driver not allocated any region by kernel\n");
		return -1;
	}

	major = MAJOR(ioctl_cal_dn); 
	minor = MINOR(ioctl_cal_dn);
	printk("the driver is allocated region by the kernel with major number: %d and minor number: %d\n",major,minor);
	printk("\nFor ioctl based calculator driver, driver expected the following device:\nMyIoctlCalDevice\n");

	MyIoctlCalDevice = cdev_alloc();
	MyIoctlCalDevice->ops = &calop; 

	int chdev_add_result = cdev_add(MyIoctlCalDevice,ioctl_cal_dn,1);
	if(chdev_add_result <0)
	{
		printk("the device is not added by kernel\n");
		return -1;
	}
	return 0;
}


static void ioctl_driver_off(void)
{
	printk("your ioctl cal driver is about to log off from kernel space\n");
	cdev_del(MyIoctlCalDevice);  
	printk("the ioctl cal device logged off\n");
	unregister_chrdev_region(ioctl_cal_dn,1); 
	printk("the ioctl cal driver unregister\nthank you\n");
}

module_init(ioctl_driver_on);
module_exit(ioctl_driver_off);

#include <linux/module.h>

//make -C /lib/modules/4.19.94-ti-r42/build/ M=/home/debian/Documents/Drivers/001hello_world modules

static int __init helloworld_init(void)
{
	//wrapper around printk
	printk(KERN_EMERG"Hello world\n");
	return 0;	
}

static void __exit helloworld_cleanup(void)
{
	pr_info("Goodbye World\n");	
}

module_init(helloworld_init);
module_exit(helloworld_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("KEITH");
MODULE_DESCRIPTION("HELLO WORLD");
MODULE_INFO(board,"Beaglebone black");

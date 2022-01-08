#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>

#define DEV_MEM_SIZE 512

char device_buffer[DEV_MEM_SIZE];

//holds device number
dev_t device_number;

//cdev variable
struct cdev pcd_cdev;

loff_t pcd_lseek(struct file *filp, loff_t off, int whence)
{
	return 0;
}

ssize_t pcd_read(struct file *filp, char __user *buff, size_t count, loff_t *f_pos)
{
	return 0;
}

ssize_t pcd_write(struct file *filp, const char __user *buff, size_t count, loff_t *f_pos)
{
	return 0;
}

int pcd_open(struct inode *inode, struct file *filp)
{
	return 0;
}

int pcd_release(struct inode *inode, struct file *filp)
{
	return 0;
}

//file operations of the driver
struct file_operations pcd_fops = {
	.open = pcd_open,
	.write = pcd_write,
	.read = pcd_read,
	.llseek = pcd_lseek,
	.release = pcd_release,
	.owner = THIS_MODULE
};

static int __init pcd_driver_init(void)
{
	/*1. Dynamically allocate device number*/	
	alloc_chrdev_region(&device_number, 0, 1, "pcd");

	/*2. Initialize cdev structure with fops*/
	cdev_init(&pcd_cdev, &pcd_fops);
	
	/*3. Register a device (cdev) structure with VFS*/
	cdev_add(&pcd_cdev, device_number, 1);
	printk("Psuedo device driver registers\n");

	return 0;
}

static void __exit pcd_driver_cleanup(void)
{

}

module_init(pcd_driver_init);
module_exit(pcd_driver_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("KEITH");
MODULE_DESCRIPTION("A psuedo char driver");

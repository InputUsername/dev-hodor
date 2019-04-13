#include <linux/fs.h>
#include <linux/init.h>
#include <linux/miscdevice.h>
#include <linux/module.h>

#include <asm/uaccess.h>

static ssize_t hodor_read(struct file * file, char * buf, 
			  size_t count, loff_t *ppos)
{
	char *hodor_str = "Hodor\n";
	int len = strlen(hodor_str);
	
	if (count < len)
		return -EINVAL;
	
	if (*ppos != 0)
		return 0;
	
	if (raw_copy_to_user(buf, hodor_str, len))
		return -EINVAL;
	
	*ppos = len;

	return len;
}

static const struct file_operations hodor_fops = {
	.owner		= THIS_MODULE,
	.read		= hodor_read,
};

static struct miscdevice hodor_dev = {
	MISC_DYNAMIC_MINOR,
	"hodor",
	&hodor_fops
};

static int __init
hodor_init(void)
{
	int ret;

	ret = misc_register(&hodor_dev);
	if (ret)
		printk(KERN_ERR
		       "Unable to register \"Hodor\" misc device\n");

	return ret;
}

module_init(hodor_init);

static void __exit
hodor_exit(void)
{
	misc_deregister(&hodor_dev);
}

module_exit(hodor_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("");
MODULE_DESCRIPTION("Hodor");
MODULE_VERSION("dev");

#include<linux/module.h>
#include<linux/init.h>
#include<linux/fs.h>
static int major;
static ssize_t myread (struct file *, char __user *, size_t, loff_t *){
    printk("Cdev:read called. . . .\n");
    return 0;
}
static struct  file_operations fops={
    .read = myread

};
static int __init myinit(void)
{
   major = register_chrdev(0,"Cdev",&fops);
   if(major < 0){
    printk("Cdev:error registering device. . . .\n");
    return major;
   }
   printk("Cdev :entering kernal major number = %d. . . . .\n",major);
   return 0;
}

static void __exit myexit(void)
{
    unregister_chrdev(major,"Cdev...\n");
    printk("Cdev:exiting  .. . . . ..\n");
}
module_init(myinit);
module_exit(myexit);

MODULE_AUTHOR("adin");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Char device module");
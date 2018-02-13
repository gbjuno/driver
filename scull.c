#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kdev_t.h>
#include <linux/module.h>
#include <linux/types.h>

MODULE_LICENSE("Dual BSD/GPL");

int areaDataSize = 10;
int areaLinkSize = 10;
module_param(areaDataSize, int, S_IRUGO);
module_param(areaLinkSize, int, S_IRUGO);

/*
struct Area {
    char *data;
    struct Area *next;
}

struct MyScull {
    strcut Area *area; // first area
    int areaDataSize;
    int areaLinkSize;
    dev_t *dev;
};

int scull_setup_cdev() {
    dev_t dev;
    int ret = 0;
    ret = alloc_chrdev_region(&dev, 2, 3, "scull");
    if (ret != 0) {
        printk(KERN_ALERT "alloc_chrDev_region failed\n");
        return 1;
    }
    return 0
}

int scull_remove_cdev() { unregister_chrdev_region() }
*/

static int hello_init(void) {
    printk(KERN_ALERT "hello world, areaLinkSize %d, areaDataSize %d\n",
           areaDataSize, areaLinkSize);
    return 0;
}

static void hello_exit(void) {
    printk(KERN_ALERT "goodbye world\n");
    return;
}

module_exit(hello_exit);
module_init(hello_init);

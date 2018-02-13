ifneq ($(KERNELRELEASE),)
    obj-m := scull.o
else
    KERNELDIR ?= $(shell uname -r)
    PWD := $(shell pwd)
default:
	$(MAKE) -C /lib/modules/$(KERNELDIR)/build M=$(PWD) modules
endif
clean:
	$(MAKE) -C /lib/modules/$(KERNELDIR)/build M=$(PWD) clean

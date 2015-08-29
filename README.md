# /dev/hodor

## About
This is a device that behaves like Hodor.

It answers to your calls with nothing but `Hodor`.

Really useful for, uh... Not much. Oh well.

This repo contains code to build a Linux kernel module that creates a device, `/dev/hodor`.
Has been tested on Ubuntu 14.04 and should work on Debian too.

Largely based on http://www.linuxdevcenter.com/pub/a/linux/2007/07/05/devhelloworld-a-simple-introduction-to-device-drivers-under-linux.html.

## How to build/use
The module-assistant package for Debian installs packages and configures the system to build out-of-kernel modules. Install it with:
```
$ sudo apt-get install module-assistant
```
(This also works on Ubuntu)

That should be enough to build the module. To build it, run:
```
$ make
```

Then, to install the module, use:
```
$ sudo insmod ./hodor_dev.ko
```

Now you should be able to read from `/dev/hodor`. Note that this requires root.

To uninstall the module again, use:
```
$ sudo rmmod hodor_dev
```

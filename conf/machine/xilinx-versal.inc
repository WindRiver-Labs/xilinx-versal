#@TYPE: Machine inc.
#@NAME: versal layer

DEFAULTTUNE = "cortexa72"
require conf/machine/include/tune-cortexa72.inc

MACHINE_FEATURES += "ext3 pci usbgadget usbhost vfat keyboard network"

KERNEL_IMAGETYPE = "Image"
KERNEL_DEVICETREE_xilinx-versal = "xilinx/versal/system-top.dtb"

SERIAL_CONSOLE = "115200;ttyAMA0"

PREFERRED_PROVIDER_virtual/kernel ??= "linux-yocto"

MACHINE_EXTRA_RRECOMMENDS = " kernel-modules kernel-devicetree"
IMAGE_FSTYPES += "tar.bz2 wic wic.bmap"

# wic support
WKS_FILE ?= "versal-sdimage.wks"
IMAGE_INSTALL_append = " ${@bb.utils.contains('UBOOT_SIGN_ENABLE', '1', 'kernel-devicetree kernel-image-fitimage', 'kernel-devicetree kernel-image-image', d)}"
do_image_wic[depends] += "mtools-native:do_populate_sysroot dosfstools-native:do_populate_sysroot"
IMAGE_BOOT_FILES ?= " Image system-top.dtb"

# multilib support
MULTILIBS ?= "multilib:lib32"
DEFAULTTUNE_virtclass-multilib-lib32 ?= "armv7athf-neon"

XSERVER_append += "xf86-video-armsoc"

XILINX_VER_MAIN = "2020.2"

#
# Copyright (C) 2021 Wind River Systems, Inc.
#

COMPATIBLE_MACHINE_xilinx-versal = "xilinx-versal"

TARGET_SUPPORTED_KTYPES_xilinx-versal = "standard"

KERNEL_VERSION_SANITY_SKIP = "1"
SRCREV_machine_xilinx-versal ?= "${AUTOREV}"
SRCREV_meta_xilinx-versal ?= "${AUTOREV}"

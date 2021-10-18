BRANCH_xilinx-versal = "2021.1"
PV_xilinx-versal = "202110.2.11.634"
SRCREV_xilinx-versal = "0dc9f505a3a910dea96166db7b5df8530b9ae38e"

pkg_postinst_ontarget_${PN}_xilinx-versal() {
  #!/bin/sh
  echo "Unloading old XRT Linux kernel modules"
  ( rmmod zocl || true ) > /dev/null 2>&1
  echo "Loading new XRT Linux kernel modules"
  modprobe zocl
}

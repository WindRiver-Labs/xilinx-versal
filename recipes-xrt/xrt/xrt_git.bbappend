BRANCH_xilinx-versal = "2021.1"
PV_xilinx-versal = "202110.2.11.634"
SRCREV_xilinx-versal = "0dc9f505a3a910dea96166db7b5df8530b9ae38e"

FILES_SOLIBSDEV = ""
FILES_${PN} += "\
    ${libdir}/lib*.so \
    ${libdir}/lib*.so.* \
    /lib/*.so* "
INSANE_SKIP_${PN} += "dev-so"

do_install_append_xilinx-versal() {
    mv ${D}/usr/lib ${D}${libdir}
}

!isEmpty(QBS_LIBEXEC_DESTDIR):DESTDIR=$${QBS_LIBEXEC_DESTDIR}
else:DESTDIR = ../../../libexec

!isEmpty(QBS_LIBEXEC_INSTALL_DIR):target.path = $${QBS_LIBEXEC_INSTALL_DIR}
else:target.path = $${QBS_INSTALL_PREFIX}/libexec
INSTALLS += target

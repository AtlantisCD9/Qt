CONFIG          += warn_on console
CONFIG          -= qt app_bundle

include(../../../qtcreator.pri)

TEMPLATE = app
DESTDIR = $$IDE_LIBEXEC_PATH
SOURCES = winrtdebughelper.cpp

build_all:!build_pass {
    CONFIG -= build_all
    CONFIG += release
}

TARGET = winrtdebughelper
target.path = $$QTC_PREFIX/bin # FIXME: libexec, more or less
INSTALLS += target


LIB_VERSION = 1.0.1
LD_VERSION = 1:1:0

SNMPLIBS=@SNMPLIBS@

AM_CFLAGS = -Wall -Wsign-compare -I$(top_builddir)/include \
	-I$(top_srcdir)/include -DIPMI_CHECK_LOCKS -DBUILDING_IPMI_UI_DLL

bin_PROGRAMS = ipmi_ui

noinst_HEADERS = ui_keypad.h ui_command.h

lib_LTLIBRARIES = libOpenIPMIui.la

libOpenIPMIui_la_SOURCES = ui.c ui_os.c ui_keypad.c ui_command.c 
libOpenIPMIui_la_LIBADD = $(top_builddir)/utils/libOpenIPMIutils.la $(top_builddir)/lib/libOpenIPMI.la $(top_builddir)/unix/libOpenIPMIposix.la $(TERM_LIBS) $(SNMPLIBS) $(OPENSSLLIBS) $(GDBM_LIB)
libOpenIPMIui_la_LDFLAGS = -version-info $(LD_VERSION) -no-undefined

ipmi_ui_SOURCES = basic_ui.c
ipmi_ui_LDADD = libOpenIPMIui.la $(top_builddir)/utils/libOpenIPMIutils.la $(top_builddir)/lib/libOpenIPMI.la $(top_builddir)/unix/libOpenIPMIposix.la $(TERM_LIBS) $(SNMPLIBS) $(OPENSSLLIBS) $(GDBM_LIB)
ipmi_ui_CFLAGS = -Wall -Wsign-compare -I$(top_builddir)/include \
	-I$(top_srcdir)/include -DIPMI_CHECK_LOCKS

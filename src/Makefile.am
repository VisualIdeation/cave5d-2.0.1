SUBDIRS=c5dSupport

bin_PROGRAMS=cave5d

cave5d_header_files = $(srcdir)/include/cave5d.h \
                      $(srcdir)/include/font.h \
                      $(srcdir)/include/vrlib.h

cave5d_source_files = cave5d.c \
                      clock.c \
                      config.c \
                      gobj.c \
                      vrlib.c

cave5d_ui_header_files = $(srcdir)/include/panelUI.h \
                         $(srcdir)/include/puiSupport.h

cave5d_ui_source_files = panelUI.c \
                         puiSupport.c

cave5d_SOURCES = $(cave5d_header_files) $(cave5d_source_files) \
                 $(cave5d_ui_header_files) $(cave5d_ui_source_files)

# According to the ACX_PTHREAD documentation, PTHREAD_CFLAGS and PTHREAD_LIBS
# both need to go in CFLAGS and LDADD As an aside ... if Vis5d is compiled with
# pthreads, the VIS5D_CFLAGS/LIBS has the PTHREAD stuff already So
# the PTHREAD_CFLAGS and PTHREAD_LIBS stuff is probably redundant.
cave5d_CFLAGS   = $(vr_cflags) $(VIS5D_CFLAGS) $(PTHREAD_CFLAGS) \
                  $(PTHREAD_LIBS) -I$(srcdir)/include
cave5d_CPPFLAGS = $(PTHREAD_CPPFLAGS)
cave5d_LDADD    = $(vr_ldflags) $(VIS5D_LIBS) $(PTHREAD_CFLAGS) $(PTHREAD_LIBS)

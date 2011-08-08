AC_PREREQ(2.61)
AC_INIT([cave5d], [2.0.1], [Phil.McDonald@dri.edu])
AC_CONFIG_SRCDIR([src/clock.c])
AC_CONFIG_AUX_DIR([aux-configure])
AC_CONFIG_HEADER([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_MAKE_SET
AC_PROG_RANLIB

# Find X11 libs and flags:
AC_PATH_X
AC_PATH_XTRA
CFLAGS="$CFLAGS $X_CFLAGS"
LIBS="$LIBS $X_LIBS $X_PRE_LIBS -lXext -lX11 -lXi $X_EXTRA_LIBS"

# Automake initialization
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# Checks for libraries.
###############################################################################
# Libraries needed by FreeVR
#
AC_CHECK_LIB([GL], [main],[],[AC_MSG_WARN([Unable to find libGL])] )
AC_CHECK_LIB([GLU], [main],[],[AC_MSG_WARN([Unable to find libGLU])])
AC_CHECK_LIB([m], [main],[],[AC_MSG_WARN([Unable to find libm])])
AC_CHECK_LIB([png], [main],[],[AC_MSG_WARN([Unable to find libpng])])

#
###############################################################################
# Determine whether to use Cavelib or FreeVR

# These macros are defined as a work-around for AS_HELP_STRING (which only
# expands macros, and not shell variables
AC_DEFUN([DEFAULT_CAVELIB_PATH],/usr/local/CAVE)
AC_DEFUN([DEFAULT_FREEVR_PATH],/usr/local/freevr/src)

AC_ARG_WITH([vrlib],
  [AS_HELP_STRING([--with-vrlib=@<:@freevr|cavelib@:>@],
    [Set equal to either 'freevr' or 'cavelib'.  To specify an alternate path to the VR library see --with-cavelib and/or --with-freevr @<:@default='freevr'@:>@])],
    [with_vrlib=$withval],
    [with_vrlib=freevr])
    
AC_ARG_WITH([cavelib],
  [AS_HELP_STRING([--with-cavelib=@<:@/path/to/cavelib@:>@],
    [Specify the path to libcavelib @<:@default = ]DEFAULT_CAVELIB_PATH[@:>@])],
    [with_cavelib=$withval],
    [with_cavelib=DEFAULT_CAVELIB_PATH])

AC_ARG_WITH([freevr],
  [AS_HELP_STRING([--with-freevr=@<:@/path/to/freevr@:>@],
    [Specify the path to libfreevr and freevr includes; this sets both --with-freevr-include and --with-freevr-lib to the value specified. @<:@default = ]DEFAULT_FREEVR_PATH[@:>@])],
    [with_freevr=$withval],
    [with_freevr=DEFAULT_FREEVR_PATH])

AC_ARG_WITH([freevr-include],
  [AS_HELP_STRING([--with-freevr-include=@<:@/path/to/freevr@:>@],
    [Specify the path to freevr includes, overrides --with-freevr @<:@default = ]DEFAULT_FREEVR_PATH[@:>@])],
    [with_freevr_include=$withval],
    [with_freevr_include=$with_freevr])
    
AC_ARG_WITH([freevr-lib],
  [AS_HELP_STRING([--with-freevr-lib=@<:@/path/to/freevr@:>@],
    [Specify the path to libfreevr, overrides --with-freevr @<:@default = ]DEFAULT_FREEVR_PATH[@:>@])],
    [with_freevr_lib=$withval],
    [with_freevr_lib=$with_freevr])
    
# Check whether the user wants to use freevr or cavelib and specify the flags/libs
# given their choice ...

# Make the following three variables available to the child makefiles
AC_SUBST([vr_cflags])
AC_SUBST([vr_ldflags])

AS_IF(
  [test "x$with_vrlib" = "xcavelib"],
  [vr_path="$with_cavelib"
   vr_cflags="-I$vr_path -DCAVE"
   vr_ldflags="-L$vr_path"
   AC_MSG_NOTICE([using path to cavelib... $vr_path])
   AC_CHECK_LIB([cave_ogl],[main],[],
      [AC_MSG_ERROR([Unable to find libcave_ogl, see help for --with-vrlib and --with-cavelib])],[$vr_ldflags])],
   
  [test "x$with_vrlib" = "xfreevr"],
  [vr_path=$with_freevr
   vr_cflags="-I$with_freevr_include -DFREEVR"
   vr_ldflags="-L$with_freevr_lib"
   AC_MSG_NOTICE([using include path to freevr... $with_freevr_include])
   AC_MSG_NOTICE([using library path to freevr... $with_freevr_lib])
   AC_SEARCH_LIBS([vrStart],[freevr freevr_32 freevr_64],[],
      [AC_MSG_ERROR([Unable to find libfreevr, see help for --with-vrlib and --with-freevr])],[$vr_ldflags])],
  
  [AC_MSG_ERROR([the VR lib $with_vrlib was not recognized.])]
)
###############################################################################

###############################################################################
# Find Vis5d

AC_ARG_WITH([vis5d],
  [AS_HELP_STRING([--with-vis5d=@<:@/path/to/vis5d+.pc@:>@],
    [Specify the path to vis5d+.pc if it is in a non-standard location (requires pkg-config)])],
    [with_vis5d=$withval],
    [with_vis5d=""])
    
AC_ARG_WITH([vis5d-include],
  [AS_HELP_STRING([--with-vis5d-include=@<:@/path/to/vis5dincludes@:>@],
    [(DEPRECATED, use --with-vis5d) Specify the path to libvis5d headers (if unspecified, the pkg-config tool will be used to determine the path) (must also specify --with-vis5d-lib)])],
    [with_vis5d_include=$withval],
    [with_vis5d_include=""])
    
AC_ARG_WITH([vis5d-lib],
  [AS_HELP_STRING([--with-vis5d-lib=@<:@/path/to/vis5dlibs@:>@],
    [(DEPRECATED, use --with-vis5d) Specify the path to libvis5d (if unspecified, the pkg-config tool will be used to determine the path)  (must also specify --with-vis5d-include)])],
    [with_vis5d_lib=$withval],
    [with_vis5d_lib=""])
    
AC_SUBST([VIS5D_CFLAGS])
AC_SUBST([VIS5D_LIBS])

AS_IF([test ! "x$with_vis5d_include" = "x" -o ! "x$with_vis5d_lib" = "x"],
      [AC_MSG_ERROR( [--with-vis5d-include and --with-vis5d-lib are both deprecated, please use --with-vis5d to specify the path to vis5d+.pc] )],
      [:])

PKG_CONFIG_PATH="$with_vis5d:$PKG_CONFIG_PATH"
export PKG_CONFIG_PATH
PKG_CHECK_MODULES(VIS5D, vis5d+ >= 1.3.1)
    
# If the user compiled vis5d with threads, cave5d needs to do so as well
#PTHREAD_CFLAGS=""
PTHREAD_CPPFLAGS=""
#PTHREAD_LIBS=""

AC_CHECK_LIB([vis5d],[vis5d_sync_set_funcs],
  [
    # vis5d was compiled with pthreads ... check if we can find pthreads and set flags
    AC_MSG_NOTICE([FreeVR was compiled with threads, so Cave5d must also.])
    tempLIBS=$LIBS
    LIBS=""
    ACX_PTHREAD([PTHREAD_CPPFLAGS="-DHAVE_PTHREADS"],AC_MSG_ERROR([Pthreads not found!]))
    LIBS=$tempLIBS
  ],
  [],
  [$XLIB_PATH $vr_ldflags $VIS5D_LIBS])
  
AC_SUBST([PTHREAD_CFLAGS])
AC_SUBST([PTHREAD_CPPFLAGS])
AC_SUBST([PTHREAD_LIBS])

###############################################################################

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([malloc.h stdlib.h string.h strings.h sys/time.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_C_INLINE
AC_HEADER_TIME

# Checks for library functions.
AC_CHECK_FUNCS([gettimeofday memset sqrt strchr strdup strrchr])

AC_CONFIG_FILES([Makefile src/Makefile src/c5dSupport/Makefile])
AC_OUTPUT

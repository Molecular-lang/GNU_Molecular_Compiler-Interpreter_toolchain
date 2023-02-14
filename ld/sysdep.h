/* sysdep.h -- handle host dependencies for the GNU linker */

#ifndef LD_SYSDEP_H
#define LD_SYSDEP_H

#ifdef PACKAGE
#error sysdep.h must be included in lieu of config.h
#endif

#include "config.h"

#include <stdio.h>
#ifdef HAVE_SYS_TYPES_H
#include <sys/types.h>
#endif
#ifdef HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef HAVE_REALPATH
# define REALPATH(a,b) realpath (a, b)
#else
# define REALPATH(a,b) NULL
#endif

#ifdef USE_BINARY_FOPEN
#include "fopen-bin.h"
#else
#include "fopen-same.h"
#endif

#ifdef HAVE_FCNTL_H
#include <fcntl.h>
#else
#ifdef HAVE_SYS_FILE_H
#include <sys/file.h>
#endif
#endif

#ifdef HAVE_DLFCN_H
#include <dlfcn.h>
#endif

#ifndef O_RDONLY
#define O_RDONLY 0
#endif
#ifndef O_WRONLY
#define O_WRONLY 1
#endif
#ifndef O_RDWR
#define O_RDWR 2
#endif
#ifndef O_ACCMODE
#define O_ACCMODE (O_RDONLY | O_WRONLY | O_RDWR)
#endif
/* Systems that don't already define this, don't need it.  */
#ifndef O_BINARY
#define O_BINARY 0
#endif

#ifndef SEEK_SET
#define SEEK_SET 0
#endif
#ifndef SEEK_CUR
#define SEEK_CUR 1
#endif
#ifndef SEEK_END
#define SEEK_END 2
#endif

#if !HAVE_DECL_ENVIRON
extern char **environ;
#endif

#define POISON_BFD_BOOLEAN 1

#endif /* ! defined (LD_SYSDEP_H) */

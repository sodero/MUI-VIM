/* vi:set ts=8 sts=4 sw=4 noet:
 *
 * VIM - Vi IMproved	by Bram Moolenaar
 *
 * Do ":help uganda"  in Vim to read copying and usage conditions.
 * Do ":help credits" in Vim to see a list of people who contributed.
 */

/*
 * Amiga Machine-dependent things
 */

#define CASE_INSENSITIVE_FILENAME   // ignore case when comparing file names
#define SPACE_IN_FILENAME
#define USE_FNAME_CASE		    // adjust case of file names
#define USE_TERM_CONSOLE
#define HAVE_AVAIL_MEM

#ifndef HAVE_CONFIG_H
# if defined(AZTEC_C) || defined(__amigaos4__)
#  define HAVE_STAT_H
# endif
# define HAVE_STDLIB_H
# define HAVE_STRING_H
# define HAVE_FCNTL_H
# define HAVE_STRCSPN
# define HAVE_STRICMP
# define HAVE_STRNICMP
# define HAVE_STRFTIME	    // guessed
# define HAVE_SETENV
# define HAVE_MEMSET
# define HAVE_QSORT
# if defined(__DATE__) && defined(__TIME__)
#  define HAVE_DATE_TIME
# endif
# define HAVE_STDARG_H
# define HAVE_STDINT_H
# define HAVE_TGETENT
# define HAVE_TERMCAP
# define OSPEED_EXTERN
# define UP_BC_PC_EXTERN
# define HAVE_GETTIMEOFDAY
# define HAVE_SYS_TIME_H
#endif // !HAVE_CONFIG_H

#ifndef	DFLT_ERRORFILE
# define DFLT_ERRORFILE		"AztecC.Err"	// Should this change?
#endif

#ifndef	DFLT_RUNTIMEPATH
# define DFLT_RUNTIMEPATH "$VIM/vimfiles,$VIMRUNTIME,$VIM/vimfiles/after"
#endif
#ifndef	CLEAN_RUNTIMEPATH
# define CLEAN_RUNTIMEPATH "$VIM/vimfiles,$VIMRUNTIME,$VIM/vimfiles/after"
#endif

#ifndef	BASENAMELEN
# define BASENAMELEN	26	// Amiga
#endif

#ifndef	TEMPNAME
# define TEMPNAME	"t:v?XXXXXX"
# define TEMPNAMELEN	12
#endif

// cproto fails on missing include files
#ifndef PROTO

#include <exec/types.h>
#include <libraries/dos.h>
#include <libraries/dosextens.h>

// Currently, all Amiga compilers except AZTEC C have these...
#ifndef AZTEC_C
# include <proto/exec.h>
# include <proto/dos.h>
# include <proto/intuition.h>
#endif

#endif // PROTO

#define FNAME_ILLEGAL ";*?`#%" // illegal characters in a file name

/*
 * Manx doesn't have off_t, define it here.
 */
#ifdef AZTEC_C
typedef long off_t;
#endif

#ifdef LATTICE
# define USE_TMPNAM	// use tmpnam() instead of mktemp()
#endif

#ifdef __GNUC__
# include <sys/stat.h>
# include <unistd.h>
# include <limits.h>
# include <errno.h>
# include <pwd.h>
# include <grp.h>
# include <dirent.h>
#endif

#include <time.h>	// for strftime() and others

#ifndef PROTO
/*
 * arpbase.h must be included before functions.h
 */
#ifdef FEAT_ARP
# include <libraries/arpbase.h>
#endif

#endif // PROTO

/*
 * This won't be needed if you have a version of Lattice 4.01 without broken
 * break signal handling.
 */
#include <signal.h>

/*
 * Names for the EXRC, HELP and temporary files.
 * Some of these may have been defined in the makefile.
 */
#ifndef SYS_VIMRC_FILE
# define SYS_VIMRC_FILE "$VIM/vimrc"
#endif
#ifndef SYS_GVIMRC_FILE
# define SYS_GVIMRC_FILE "$VIM/gvimrc"
#endif
#ifndef SYS_MENU_FILE
# define SYS_MENU_FILE	"$VIMRUNTIME/menu.vim"
#endif
#ifndef DFLT_HELPFILE
# define DFLT_HELPFILE	"$VIMRUNTIME/doc/help.txt"
#endif
#ifndef FILETYPE_FILE
# define FILETYPE_FILE	"filetype.vim"
#endif
#ifndef FTPLUGIN_FILE
# define FTPLUGIN_FILE	"ftplugin.vim"
#endif
#ifndef INDENT_FILE
# define INDENT_FILE	"indent.vim"
#endif
#ifndef FTOFF_FILE
# define FTOFF_FILE	"ftoff.vim"
#endif
#ifndef FTPLUGOF_FILE
# define FTPLUGOF_FILE	"ftplugof.vim"
#endif
#ifndef INDOFF_FILE
# define INDOFF_FILE	"indoff.vim"
#endif
#ifndef SYNTAX_FNAME
# define SYNTAX_FNAME	"$VIMRUNTIME/syntax/%s.vim"
#endif

#ifndef USR_EXRC_FILE
# define USR_EXRC_FILE	"$VIM/.exrc"
#endif
#ifndef USR_EXRC_FILE2
# define USR_EXRC_FILE2	"home:.exrc"
#endif

#ifndef USR_VIMRC_FILE
# define USR_VIMRC_FILE	"$VIM/.vimrc"
#endif
#ifndef USR_VIMRC_FILE2
# define USR_VIMRC_FILE2 "home:.vimrc"
#endif
#ifndef USR_VIMRC_FILE3
# define USR_VIMRC_FILE3 "home:vimfiles:vimrc"
#endif
#ifndef USR_VIMRC_FILE4
# define USR_VIMRC_FILE4 "s:.vimrc"
#endif
#ifndef VIM_DEFAULTS_FILE
# define VIM_DEFAULTS_FILE "$VIMRUNTIME/defaults.vim"
#endif
#ifndef EVIM_FILE
# define EVIM_FILE	"$VIMRUNTIME/evim.vim"
#endif

#ifndef USR_GVIMRC_FILE
# define USR_GVIMRC_FILE "$VIM/.gvimrc"
#endif
#ifndef USR_GVIMRC_FILE2
# define USR_GVIMRC_FILE2 "home:.gvimrc"
#endif
#ifndef USR_GVIMRC_FILE3
# define USR_GVIMRC_FILE3 "home:vimfiles:gvimrc"
#endif
#ifndef USR_GVIMRC_FILE4
# define USR_GVIMRC_FILE4 "s:.gvimrc"
#endif

#ifndef VIMINFO_FILE
# define VIMINFO_FILE	"$VIM/.viminfo"
#endif

#ifndef EXRC_FILE
# define EXRC_FILE	".exrc"
#endif

#ifndef VIMRC_FILE
# define VIMRC_FILE	".vimrc"
#endif

#ifndef GVIMRC_FILE
# define GVIMRC_FILE	".gvimrc"
#endif

#ifndef DFLT_BDIR
# define DFLT_BDIR	".,t:"		// default for 'backupdir'
#endif

#ifndef DFLT_DIR
# define DFLT_DIR	".,t:"		// default for 'directory'
#endif

#ifndef DFLT_VDIR
# define DFLT_VDIR	"$VIM/vimfiles/view"	// default for 'viewdir'
#endif

#ifndef DFLT_MAXMEM
# if defined(__amigaos4__) || defined(__AROS__) || defined(__MORPHOS__)
#  define DFLT_MAXMEM	(5*1024)	// use up to 5 Mbyte for buffer
# else
#  define DFLT_MAXMEM	256		// use up to 256Kbyte for buffer
# endif
#endif

#ifndef DFLT_MAXMEMTOT
# if defined(__amigaos4__) || defined(__AROS__) || defined(__MORPHOS__)
#  define DFLT_MAXMEMTOT	(10*1024)	// use up to 10 Mbyte for Vim
# else
#  define DFLT_MAXMEMTOT	512		// use up to 512Kbyte for Vim
# endif
#endif

// Use OS4 FIB_* macros on MorphOS and AROS as well.
#ifndef FIB_IS_FILE
# define FIB_IS_FILE(FIB)	((FIB)->fib_DirEntryType < 0)
#endif
#ifndef FIB_IS_DRAWER
# define FIB_IS_DRAWER(FIB)	((FIB)->fib_DirEntryType >= 0 && \
				 (FIB)->fib_DirEntryType != ST_SOFTLINK)
#endif

#if defined(SASC)
int setenv(const char *, const char *);
#endif

#define mch_remove(x) remove((const char *) x)
#define mch_rename(s, d) rename((const char *) s, (const char *) d)
#define mch_chdir(s) chdir((const char *) s)
#define mch_rmdir(s) rmdir((const char *) s)
#define vim_mkdir(x, m) mkdir((const char *) x, m)

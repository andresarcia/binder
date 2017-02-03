# 1 "client2.C"
# 1 "../../../../src/aleph/aleph.H" 1
# 50 "../../../../src/aleph/aleph.H"
# 1 "../../../../src/aleph/ahDefs.H" 1
# 50 "../../../../src/aleph/ahDefs.H"
# 1 "/usr/include/unistd.h" 1 3
# 26 "/usr/include/unistd.h" 3
# 1 "/usr/include/features.h" 1 3
# 283 "/usr/include/features.h" 3
# 1 "/usr/include/sys/cdefs.h" 1 3
# 284 "/usr/include/features.h" 2 3
# 312 "/usr/include/features.h" 3
# 1 "/usr/include/gnu/stubs.h" 1 3
# 313 "/usr/include/features.h" 2 3
# 27 "/usr/include/unistd.h" 2 3

extern "C" {
# 175 "/usr/include/unistd.h" 3
# 1 "/usr/include/bits/posix_opt.h" 1 3
# 176 "/usr/include/unistd.h" 2 3



# 1 "/usr/include/bits/environments.h" 1 3
# 23 "/usr/include/bits/environments.h" 3
# 1 "/usr/include/bits/wordsize.h" 1 3
# 24 "/usr/include/bits/environments.h" 2 3
# 180 "/usr/include/unistd.h" 2 3
# 190 "/usr/include/unistd.h" 3
# 1 "/usr/include/bits/types.h" 1 3
# 26 "/usr/include/bits/types.h" 3
# 1 "/usr/include/features.h" 1 3
# 27 "/usr/include/bits/types.h" 2 3


# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stddef.h" 1 3
# 199 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stddef.h" 3
typedef unsigned int size_t;
# 30 "/usr/include/bits/types.h" 2 3


typedef unsigned char __u_char;
typedef unsigned short __u_short;
typedef unsigned int __u_int;
typedef unsigned long __u_long;

__extension__ typedef unsigned long long int __u_quad_t;
__extension__ typedef long long int __quad_t;
# 49 "/usr/include/bits/types.h" 3
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;

__extension__ typedef signed long long int __int64_t;
__extension__ typedef unsigned long long int __uint64_t;

typedef __quad_t *__qaddr_t;

typedef __u_quad_t __dev_t;
typedef __u_int __uid_t;
typedef __u_int __gid_t;
typedef __u_long __ino_t;
typedef __u_int __mode_t;
typedef __u_int __nlink_t;
typedef long int __off_t;
typedef __quad_t __loff_t;
typedef int __pid_t;
typedef int __ssize_t;
typedef __u_long __rlim_t;
typedef __u_quad_t __rlim64_t;
typedef __u_int __id_t;

typedef struct
  {
    int __val[2];
  } __fsid_t;


typedef int __daddr_t;
typedef char *__caddr_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;
typedef long int __swblk_t;

typedef long int __clock_t;


typedef int __clockid_t;


typedef int __timer_t;






typedef int __key_t;


typedef unsigned short int __ipc_pid_t;



typedef long int __blksize_t;




typedef long int __blkcnt_t;
typedef __quad_t __blkcnt64_t;


typedef __u_long __fsblkcnt_t;
typedef __u_quad_t __fsblkcnt64_t;


typedef __u_long __fsfilcnt_t;
typedef __u_quad_t __fsfilcnt64_t;


typedef __u_quad_t __ino64_t;


typedef __loff_t __off64_t;


typedef long int __t_scalar_t;
typedef unsigned long int __t_uscalar_t;


typedef int __intptr_t;


typedef unsigned int __socklen_t;




# 1 "/usr/include/bits/pthreadtypes.h" 1 3
# 23 "/usr/include/bits/pthreadtypes.h" 3
# 1 "/usr/include/bits/sched.h" 1 3
# 68 "/usr/include/bits/sched.h" 3
struct __sched_param
  {
    int __sched_priority;
  };
# 24 "/usr/include/bits/pthreadtypes.h" 2 3


struct _pthread_fastlock
{
  long int __status;
  int __spinlock;

};



typedef struct _pthread_descr_struct *_pthread_descr;





typedef struct __pthread_attr_s
{
  int __detachstate;
  int __schedpolicy;
  struct __sched_param __schedparam;
  int __inheritsched;
  int __scope;
  size_t __guardsize;
  int __stackaddr_set;
  void *__stackaddr;
  size_t __stacksize;
} pthread_attr_t;



typedef struct
{
  struct _pthread_fastlock __c_lock;
  _pthread_descr __c_waiting;
} pthread_cond_t;



typedef struct
{
  int __dummy;
} pthread_condattr_t;


typedef unsigned int pthread_key_t;





typedef struct
{
  int __m_reserved;
  int __m_count;
  _pthread_descr __m_owner;
  int __m_kind;
  struct _pthread_fastlock __m_lock;
} pthread_mutex_t;



typedef struct
{
  int __mutexkind;
} pthread_mutexattr_t;



typedef int pthread_once_t;




typedef struct _pthread_rwlock_t
{
  struct _pthread_fastlock __rw_lock;
  int __rw_readers;
  _pthread_descr __rw_writer;
  _pthread_descr __rw_read_waiting;
  _pthread_descr __rw_write_waiting;
  int __rw_kind;
  int __rw_pshared;
} pthread_rwlock_t;



typedef struct
{
  int __lockkind;
  int __pshared;
} pthread_rwlockattr_t;




typedef volatile int pthread_spinlock_t;


typedef struct {
  struct _pthread_fastlock __ba_lock;
  int __ba_required;
  int __ba_present;
  _pthread_descr __ba_waiting;
} pthread_barrier_t;


typedef struct {
  int __pshared;
} pthread_barrierattr_t;





typedef unsigned long int pthread_t;
# 144 "/usr/include/bits/types.h" 2 3
# 191 "/usr/include/unistd.h" 2 3


typedef __ssize_t ssize_t;





# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stddef.h" 1 3
# 200 "/usr/include/unistd.h" 2 3





typedef __gid_t gid_t;




typedef __uid_t uid_t;





typedef __off_t off_t;






typedef __off64_t off64_t;




typedef __useconds_t useconds_t;




typedef __pid_t pid_t;






typedef __intptr_t intptr_t;






typedef __socklen_t socklen_t;
# 260 "/usr/include/unistd.h" 3
extern int access (__const char *__name, int __type) throw ();




extern int euidaccess (__const char *__name, int __type) throw ();
# 290 "/usr/include/unistd.h" 3
extern __off_t lseek (int __fd, __off_t __offset, int __whence) throw ();
# 302 "/usr/include/unistd.h" 3
extern __off64_t lseek64 (int __fd, __off64_t __offset, int __whence) throw ();



extern int close (int __fd) throw ();



extern ssize_t read (int __fd, void *__buf, size_t __nbytes) throw ();


extern ssize_t write (int __fd, __const void *__buf, size_t __n) throw ();



extern ssize_t pread (int __fd, void *__buf, size_t __nbytes, __off_t __offset)
     throw ();
extern ssize_t pwrite (int __fd, __const void *__buf, size_t __n,
                       __off_t __offset) throw ();
# 340 "/usr/include/unistd.h" 3
extern ssize_t pread64 (int __fd, void *__buf, size_t __nbytes,
                        __off64_t __offset) throw ();


extern ssize_t pwrite64 (int __fd, __const void *__buf, size_t __n,
                         __off64_t __offset) throw ();







extern int pipe (int __pipedes[2]) throw ();
# 362 "/usr/include/unistd.h" 3
extern unsigned int alarm (unsigned int __seconds) throw ();
# 371 "/usr/include/unistd.h" 3
extern unsigned int sleep (unsigned int __seconds) throw ();






extern __useconds_t ualarm (__useconds_t __value, __useconds_t __interval)
     throw ();



extern int usleep (__useconds_t __useconds) throw ();





extern int pause (void) throw ();



extern int chown (__const char *__file, __uid_t __owner, __gid_t __group)
     throw ();



extern int fchown (int __fd, __uid_t __owner, __gid_t __group) throw ();




extern int lchown (__const char *__file, __uid_t __owner, __gid_t __group)
     throw ();




extern int chdir (__const char *__path) throw ();



extern int fchdir (int __fd) throw ();
# 423 "/usr/include/unistd.h" 3
extern char *getcwd (char *__buf, size_t __size) throw ();





extern char *get_current_dir_name (void) throw ();






extern char *getwd (char *__buf) throw ();




extern int dup (int __fd) throw ();


extern int dup2 (int __fd, int __fd2) throw ();


extern char **__environ;

extern char **environ;





extern int execve (__const char *__path, char *__const __argv[],
                   char *__const __envp[]) throw ();




extern int fexecve (int __fd, char *__const __argv[], char *__const __envp[])
     throw ();




extern int execv (__const char *__path, char *__const __argv[]) throw ();



extern int execle (__const char *__path, __const char *__arg, ...) throw ();



extern int execl (__const char *__path, __const char *__arg, ...) throw ();



extern int execvp (__const char *__file, char *__const __argv[]) throw ();




extern int execlp (__const char *__file, __const char *__arg, ...) throw ();




extern int nice (int __inc) throw ();




extern void _exit (int __status) __attribute__ ((__noreturn__));





# 1 "/usr/include/bits/confname.h" 1 3
# 25 "/usr/include/bits/confname.h" 3
enum
  {
    _PC_LINK_MAX,

    _PC_MAX_CANON,

    _PC_MAX_INPUT,

    _PC_NAME_MAX,

    _PC_PATH_MAX,

    _PC_PIPE_BUF,

    _PC_CHOWN_RESTRICTED,

    _PC_NO_TRUNC,

    _PC_VDISABLE,

    _PC_SYNC_IO,

    _PC_ASYNC_IO,

    _PC_PRIO_IO,

    _PC_SOCK_MAXBUF,

    _PC_FILESIZEBITS,

    _PC_REC_INCR_XFER_SIZE,

    _PC_REC_MAX_XFER_SIZE,

    _PC_REC_MIN_XFER_SIZE,

    _PC_REC_XFER_ALIGN,

    _PC_ALLOC_SIZE_MIN,

    _PC_SYMLINK_MAX

  };


enum
  {
    _SC_ARG_MAX,

    _SC_CHILD_MAX,

    _SC_CLK_TCK,

    _SC_NGROUPS_MAX,

    _SC_OPEN_MAX,

    _SC_STREAM_MAX,

    _SC_TZNAME_MAX,

    _SC_JOB_CONTROL,

    _SC_SAVED_IDS,

    _SC_REALTIME_SIGNALS,

    _SC_PRIORITY_SCHEDULING,

    _SC_TIMERS,

    _SC_ASYNCHRONOUS_IO,

    _SC_PRIORITIZED_IO,

    _SC_SYNCHRONIZED_IO,

    _SC_FSYNC,

    _SC_MAPPED_FILES,

    _SC_MEMLOCK,

    _SC_MEMLOCK_RANGE,

    _SC_MEMORY_PROTECTION,

    _SC_MESSAGE_PASSING,

    _SC_SEMAPHORES,

    _SC_SHARED_MEMORY_OBJECTS,

    _SC_AIO_LISTIO_MAX,

    _SC_AIO_MAX,

    _SC_AIO_PRIO_DELTA_MAX,

    _SC_DELAYTIMER_MAX,

    _SC_MQ_OPEN_MAX,

    _SC_MQ_PRIO_MAX,

    _SC_VERSION,

    _SC_PAGESIZE,


    _SC_RTSIG_MAX,

    _SC_SEM_NSEMS_MAX,

    _SC_SEM_VALUE_MAX,

    _SC_SIGQUEUE_MAX,

    _SC_TIMER_MAX,




    _SC_BC_BASE_MAX,

    _SC_BC_DIM_MAX,

    _SC_BC_SCALE_MAX,

    _SC_BC_STRING_MAX,

    _SC_COLL_WEIGHTS_MAX,

    _SC_EQUIV_CLASS_MAX,

    _SC_EXPR_NEST_MAX,

    _SC_LINE_MAX,

    _SC_RE_DUP_MAX,

    _SC_CHARCLASS_NAME_MAX,


    _SC_2_VERSION,

    _SC_2_C_BIND,

    _SC_2_C_DEV,

    _SC_2_FORT_DEV,

    _SC_2_FORT_RUN,

    _SC_2_SW_DEV,

    _SC_2_LOCALEDEF,


    _SC_PII,

    _SC_PII_XTI,

    _SC_PII_SOCKET,

    _SC_PII_INTERNET,

    _SC_PII_OSI,

    _SC_POLL,

    _SC_SELECT,

    _SC_UIO_MAXIOV,

    _SC_IOV_MAX = _SC_UIO_MAXIOV,

    _SC_PII_INTERNET_STREAM,

    _SC_PII_INTERNET_DGRAM,

    _SC_PII_OSI_COTS,

    _SC_PII_OSI_CLTS,

    _SC_PII_OSI_M,

    _SC_T_IOV_MAX,



    _SC_THREADS,

    _SC_THREAD_SAFE_FUNCTIONS,

    _SC_GETGR_R_SIZE_MAX,

    _SC_GETPW_R_SIZE_MAX,

    _SC_LOGIN_NAME_MAX,

    _SC_TTY_NAME_MAX,

    _SC_THREAD_DESTRUCTOR_ITERATIONS,

    _SC_THREAD_KEYS_MAX,

    _SC_THREAD_STACK_MIN,

    _SC_THREAD_THREADS_MAX,

    _SC_THREAD_ATTR_STACKADDR,

    _SC_THREAD_ATTR_STACKSIZE,

    _SC_THREAD_PRIORITY_SCHEDULING,

    _SC_THREAD_PRIO_INHERIT,

    _SC_THREAD_PRIO_PROTECT,

    _SC_THREAD_PROCESS_SHARED,


    _SC_NPROCESSORS_CONF,

    _SC_NPROCESSORS_ONLN,

    _SC_PHYS_PAGES,

    _SC_AVPHYS_PAGES,

    _SC_ATEXIT_MAX,

    _SC_PASS_MAX,


    _SC_XOPEN_VERSION,

    _SC_XOPEN_XCU_VERSION,

    _SC_XOPEN_UNIX,

    _SC_XOPEN_CRYPT,

    _SC_XOPEN_ENH_I18N,

    _SC_XOPEN_SHM,


    _SC_2_CHAR_TERM,

    _SC_2_C_VERSION,

    _SC_2_UPE,


    _SC_XOPEN_XPG2,

    _SC_XOPEN_XPG3,

    _SC_XOPEN_XPG4,


    _SC_CHAR_BIT,

    _SC_CHAR_MAX,

    _SC_CHAR_MIN,

    _SC_INT_MAX,

    _SC_INT_MIN,

    _SC_LONG_BIT,

    _SC_WORD_BIT,

    _SC_MB_LEN_MAX,

    _SC_NZERO,

    _SC_SSIZE_MAX,

    _SC_SCHAR_MAX,

    _SC_SCHAR_MIN,

    _SC_SHRT_MAX,

    _SC_SHRT_MIN,

    _SC_UCHAR_MAX,

    _SC_UINT_MAX,

    _SC_ULONG_MAX,

    _SC_USHRT_MAX,


    _SC_NL_ARGMAX,

    _SC_NL_LANGMAX,

    _SC_NL_MSGMAX,

    _SC_NL_NMAX,

    _SC_NL_SETMAX,

    _SC_NL_TEXTMAX,


    _SC_XBS5_ILP32_OFF32,

    _SC_XBS5_ILP32_OFFBIG,

    _SC_XBS5_LP64_OFF64,

    _SC_XBS5_LPBIG_OFFBIG,


    _SC_XOPEN_LEGACY,

    _SC_XOPEN_REALTIME,

    _SC_XOPEN_REALTIME_THREADS,


    _SC_ADVISORY_INFO,

    _SC_BARRIERS,

    _SC_BASE,

    _SC_C_LANG_SUPPORT,

    _SC_C_LANG_SUPPORT_R,

    _SC_CLOCK_SELECTION,

    _SC_CPUTIME,

    _SC_THREAD_CPUTIME,

    _SC_DEVICE_IO,

    _SC_DEVICE_SPECIFIC,

    _SC_DEVICE_SPECIFIC_R,

    _SC_FD_MGMT,

    _SC_FIFO,

    _SC_PIPE,

    _SC_FILE_ATTRIBUTES,

    _SC_FILE_LOCKING,

    _SC_FILE_SYSTEM,

    _SC_MONOTONIC_CLOCK,

    _SC_MULTI_PROCESS,

    _SC_SINGLE_PROCESS,

    _SC_NETWORKING,

    _SC_READER_WRITER_LOCKS,

    _SC_SPIN_LOCKS,

    _SC_REGEXP,

    _SC_REGEX_VERSION,

    _SC_SHELL,

    _SC_SIGNALS,

    _SC_SPAWN,

    _SC_SPORADIC_SERVER,

    _SC_THREAD_SPORADIC_SERVER,

    _SC_SYSTEM_DATABASE,

    _SC_SYSTEM_DATABASE_R,

    _SC_TIMEOUTS,

    _SC_TYPED_MEMORY_OBJECTS,

    _SC_USER_GROUPS,

    _SC_USER_GROUPS_R,

    _SC_2_PBS,

    _SC_2_PBS_ACCOUNTING,

    _SC_2_PBS_LOCATE,

    _SC_2_PBS_MESSAGE,

    _SC_2_PBS_TRACK,

    _SC_SYMLOOP_MAX,

    _SC_STREAMS,

    _SC_2_PBS_CHECKPOINT,


    _SC_V6_ILP32_OFF32,

    _SC_V6_ILP32_OFFBIG,

    _SC_V6_LP64_OFF64,

    _SC_V6_LPBIG_OFFBIG,


    _SC_HOST_NAME_MAX,

    _SC_TRACE,

    _SC_TRACE_EVENT_FILTER,

    _SC_TRACE_INHERIT,

    _SC_TRACE_LOG

  };





enum
  {
    _CS_PATH,




    _CS_LFS_CFLAGS = 1000,

    _CS_LFS_LDFLAGS,

    _CS_LFS_LIBS,

    _CS_LFS_LINTFLAGS,

    _CS_LFS64_CFLAGS,

    _CS_LFS64_LDFLAGS,

    _CS_LFS64_LIBS,

    _CS_LFS64_LINTFLAGS,




    _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,

    _CS_XBS5_ILP32_OFF32_LDFLAGS,

    _CS_XBS5_ILP32_OFF32_LIBS,

    _CS_XBS5_ILP32_OFF32_LINTFLAGS,

    _CS_XBS5_ILP32_OFFBIG_CFLAGS,

    _CS_XBS5_ILP32_OFFBIG_LDFLAGS,

    _CS_XBS5_ILP32_OFFBIG_LIBS,

    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS,

    _CS_XBS5_LP64_OFF64_CFLAGS,

    _CS_XBS5_LP64_OFF64_LDFLAGS,

    _CS_XBS5_LP64_OFF64_LIBS,

    _CS_XBS5_LP64_OFF64_LINTFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_CFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_LIBS,

    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,



    _CS_POSIX_V6_ILP32_OFF32_CFLAGS,

    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS,

    _CS_POSIX_V6_ILP32_OFF32_LIBS,

    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_LIBS,

    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,

    _CS_POSIX_V6_LP64_OFF64_CFLAGS,

    _CS_POSIX_V6_LP64_OFF64_LDFLAGS,

    _CS_POSIX_V6_LP64_OFF64_LIBS,

    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS,



    _CS_V6_WIDTH_RESTRICTED_ENVS

  };
# 501 "/usr/include/unistd.h" 2 3


extern long int pathconf (__const char *__path, int __name) throw ();


extern long int fpathconf (int __fd, int __name) throw ();


extern long int sysconf (int __name) throw () __attribute__ ((__const__));



extern size_t confstr (int __name, char *__buf, size_t __len) throw ();




extern __pid_t getpid (void) throw ();


extern __pid_t getppid (void) throw ();




extern __pid_t getpgrp (void) throw ();
# 536 "/usr/include/unistd.h" 3
extern __pid_t __getpgid (__pid_t __pid) throw ();

extern __pid_t getpgid (__pid_t __pid) throw ();






extern int setpgid (__pid_t __pid, __pid_t __pgid) throw ();
# 562 "/usr/include/unistd.h" 3
extern int setpgrp (void) throw ();
# 580 "/usr/include/unistd.h" 3
extern __pid_t setsid (void) throw ();



extern __pid_t getsid (__pid_t __pid) throw ();



extern __uid_t getuid (void) throw ();


extern __uid_t geteuid (void) throw ();


extern __gid_t getgid (void) throw ();


extern __gid_t getegid (void) throw ();




extern int getgroups (int __size, __gid_t __list[]) throw ();



extern int group_member (__gid_t __gid) throw ();






extern int setuid (__uid_t __uid) throw ();




extern int setreuid (__uid_t __ruid, __uid_t __euid) throw ();




extern int seteuid (__uid_t __uid) throw ();






extern int setgid (__gid_t __gid) throw ();




extern int setregid (__gid_t __rgid, __gid_t __egid) throw ();




extern int setegid (__gid_t __gid) throw ();






extern __pid_t fork (void) throw ();






extern __pid_t vfork (void) throw ();





extern char *ttyname (int __fd) throw ();



extern int ttyname_r (int __fd, char *__buf, size_t __buflen) throw ();



extern int isatty (int __fd) throw ();





extern int ttyslot (void) throw ();




extern int link (__const char *__from, __const char *__to) throw ();



extern int symlink (__const char *__from, __const char *__to) throw ();




extern int readlink (__const char *__restrict __path, char *__restrict __buf,
                     size_t __len) throw ();



extern int unlink (__const char *__name) throw ();


extern int rmdir (__const char *__path) throw ();



extern __pid_t tcgetpgrp (int __fd) throw ();


extern int tcsetpgrp (int __fd, __pid_t __pgrp_id) throw ();



extern char *getlogin (void) throw ();




extern int getlogin_r (char *__name, size_t __name_len) throw ();




extern int setlogin (__const char *__name) throw ();
# 726 "/usr/include/unistd.h" 3
# 1 "/usr/include/getopt.h" 1 3
# 38 "/usr/include/getopt.h" 3
extern "C" {
# 47 "/usr/include/getopt.h" 3
extern char *optarg;
# 61 "/usr/include/getopt.h" 3
extern int optind;




extern int opterr;



extern int optopt;
# 145 "/usr/include/getopt.h" 3
extern int getopt (int ___argc, char *const *___argv, const char *__shortopts);
# 175 "/usr/include/getopt.h" 3
}
# 727 "/usr/include/unistd.h" 2 3







extern int gethostname (char *__name, size_t __len) throw ();






extern int sethostname (__const char *__name, size_t __len) throw ();



extern int sethostid (long int __id) throw ();





extern int getdomainname (char *__name, size_t __len) throw ();
extern int setdomainname (__const char *__name, size_t __len) throw ();





extern int vhangup (void) throw ();


extern int revoke (__const char *__file) throw ();







extern int profil (unsigned short int *__sample_buffer, size_t __size,
                   size_t __offset, unsigned int __scale) throw ();





extern int acct (__const char *__name) throw ();



extern char *getusershell (void) throw ();
extern void endusershell (void) throw ();
extern void setusershell (void) throw ();





extern int daemon (int __nochdir, int __noclose) throw ();






extern int chroot (__const char *__path) throw ();



extern char *getpass (__const char *__prompt) throw ();





extern int fsync (int __fd) throw ();






extern long int gethostid (void) throw ();


extern void sync (void) throw ();




extern int getpagesize (void) throw () __attribute__ ((__const__));




extern int truncate (__const char *__file, __off_t __length) throw ();
# 836 "/usr/include/unistd.h" 3
extern int truncate64 (__const char *__file, __off64_t __length) throw ();




extern int ftruncate (int __fd, __off_t __length) throw ();
# 851 "/usr/include/unistd.h" 3
extern int ftruncate64 (int __fd, __off64_t __length) throw ();





extern int getdtablesize (void) throw ();
# 866 "/usr/include/unistd.h" 3
extern int brk (void *__addr) throw ();





extern void *sbrk (intptr_t __delta) throw ();
# 887 "/usr/include/unistd.h" 3
extern long int syscall (long int __sysno, ...) throw ();
# 907 "/usr/include/unistd.h" 3
extern int lockf (int __fd, int __cmd, __off_t __len) throw ();
# 917 "/usr/include/unistd.h" 3
extern int lockf64 (int __fd, int __cmd, __off64_t __len) throw ();
# 938 "/usr/include/unistd.h" 3
extern int fdatasync (int __fildes) throw ();







extern char *crypt (__const char *__key, __const char *__salt) throw ();



extern void encrypt (char *__block, int __edflag) throw ();






extern void swab (__const void *__restrict __from, void *__restrict __to,
                  ssize_t __n) throw ();







extern char *ctermid (char *__s) throw ();
# 983 "/usr/include/unistd.h" 3
extern int pthread_atfork (void (*__prepare) (void),
                           void (*__parent) (void),
                           void (*__child) (void)) throw ();


}
# 51 "../../../../src/aleph/ahDefs.H" 2
# 1 "/usr/include/time.h" 1 3
# 28 "/usr/include/time.h" 3
# 1 "/usr/include/features.h" 1 3
# 29 "/usr/include/time.h" 2 3

extern "C" {







# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stddef.h" 1 3
# 39 "/usr/include/time.h" 2 3



# 1 "/usr/include/bits/time.h" 1 3
# 43 "/usr/include/time.h" 2 3
# 56 "/usr/include/time.h" 3
# 1 "/usr/include/bits/types.h" 1 3
# 57 "/usr/include/time.h" 2 3


typedef __clock_t clock_t;







# 1 "/usr/include/bits/types.h" 1 3
# 68 "/usr/include/time.h" 2 3


typedef __time_t time_t;
# 79 "/usr/include/time.h" 3
# 1 "/usr/include/bits/types.h" 1 3
# 80 "/usr/include/time.h" 2 3


typedef __clockid_t clockid_t;
# 91 "/usr/include/time.h" 3
# 1 "/usr/include/bits/types.h" 1 3
# 92 "/usr/include/time.h" 2 3


typedef __timer_t timer_t;
# 106 "/usr/include/time.h" 3
struct timespec
  {
    __time_t tv_sec;
    long int tv_nsec;
  };







struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;


  long int tm_gmtoff;
  __const char *tm_zone;




};




struct itimerspec
  {
    struct timespec it_interval;
    struct timespec it_value;
  };


struct sigevent;
# 163 "/usr/include/time.h" 3
extern clock_t clock (void) throw ();


extern time_t time (time_t *__timer) throw ();


extern double difftime (time_t __time1, time_t __time0)
     throw () __attribute__ ((__const__));


extern time_t mktime (struct tm *__tp) throw ();





extern size_t strftime (char *__restrict __s, size_t __maxsize,
                        __const char *__restrict __format,
                        __const struct tm *__restrict __tp) throw ();




extern char *strptime (__const char *__restrict __s,
                       __const char *__restrict __fmt, struct tm *__tp)
     throw ();





extern struct tm *gmtime (__const time_t *__timer) throw ();



extern struct tm *localtime (__const time_t *__timer) throw ();




extern struct tm *gmtime_r (__const time_t *__restrict __timer,
                            struct tm *__restrict __tp) throw ();



extern struct tm *localtime_r (__const time_t *__restrict __timer,
                               struct tm *__restrict __tp) throw ();




extern char *asctime (__const struct tm *__tp) throw ();


extern char *ctime (__const time_t *__timer) throw ();






extern char *asctime_r (__const struct tm *__restrict __tp,
                        char *__restrict __buf) throw ();


extern char *ctime_r (__const time_t *__restrict __timer,
                      char *__restrict __buf) throw ();




extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;




extern char *tzname[2];



extern void tzset (void) throw ();



extern int daylight;
extern long int timezone;





extern int stime (__const time_t *__when) throw ();
# 271 "/usr/include/time.h" 3
extern time_t timegm (struct tm *__tp) throw ();


extern time_t timelocal (struct tm *__tp) throw ();


extern int dysize (int __year) throw () __attribute__ ((__const__));





extern int nanosleep (__const struct timespec *__requested_time,
                      struct timespec *__remaining) throw ();



extern int clock_getres (clockid_t __clock_id, struct timespec *__res) throw ();


extern int clock_gettime (clockid_t __clock_id, struct timespec *__tp) throw ();


extern int clock_settime (clockid_t __clock_id, __const struct timespec *__tp)
     throw ();



extern int clock_nanosleep (clockid_t __clock_id, int __flags,
                            __const struct timespec *__req,
                            struct timespec *__rem) throw ();


extern int clock_getcpuclockid (pid_t __pid, clockid_t *__clock_id) throw ();




extern int timer_create (clockid_t __clock_id,
                         struct sigevent *__restrict __evp,
                         timer_t *__restrict __timerid) throw ();


extern int timer_delete (timer_t __timerid) throw ();


extern int timer_settime (timer_t __timerid, int __flags,
                          __const struct itimerspec *__restrict __value,
                          struct itimerspec *__restrict __ovalue) throw ();


extern int timer_gettime (timer_t __timerid, struct itimerspec *__value)
     throw ();


extern int timer_getoverrun (timer_t __timerid) throw ();
# 342 "/usr/include/time.h" 3
extern int getdate_err;





extern struct tm *getdate (__const char *__string) throw ();
# 357 "/usr/include/time.h" 3
extern int getdate_r (__const char *__restrict __string,
                      struct tm *__restrict __resbufp) throw ();



}
# 52 "../../../../src/aleph/ahDefs.H" 2
# 1 "/usr/include/stdlib.h" 1 3
# 25 "/usr/include/stdlib.h" 3
# 1 "/usr/include/features.h" 1 3
# 26 "/usr/include/stdlib.h" 2 3







# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stddef.h" 1 3
# 34 "/usr/include/stdlib.h" 2 3

extern "C" {






# 1 "/usr/include/bits/waitflags.h" 1 3
# 43 "/usr/include/stdlib.h" 2 3
# 1 "/usr/include/bits/waitstatus.h" 1 3
# 63 "/usr/include/bits/waitstatus.h" 3
# 1 "/usr/include/endian.h" 1 3
# 22 "/usr/include/endian.h" 3
# 1 "/usr/include/features.h" 1 3
# 23 "/usr/include/endian.h" 2 3
# 37 "/usr/include/endian.h" 3
# 1 "/usr/include/bits/endian.h" 1 3
# 38 "/usr/include/endian.h" 2 3
# 64 "/usr/include/bits/waitstatus.h" 2 3

union wait
  {
    int w_status;
    struct
      {

        unsigned int __w_termsig:7;
        unsigned int __w_coredump:1;
        unsigned int __w_retcode:8;
        unsigned int:16;







      } __wait_terminated;
    struct
      {

        unsigned int __w_stopval:8;
        unsigned int __w_stopsig:8;
        unsigned int:16;






      } __wait_stopped;
  };
# 44 "/usr/include/stdlib.h" 2 3
# 94 "/usr/include/stdlib.h" 3
typedef struct
  {
    int quot;
    int rem;
  } div_t;



typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;





__extension__ typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;
# 133 "/usr/include/stdlib.h" 3
extern size_t __ctype_get_mb_cur_max (void) throw ();



extern double atof (__const char *__nptr) throw () __attribute__ ((__pure__));

extern int atoi (__const char *__nptr) throw () __attribute__ ((__pure__));

extern long int atol (__const char *__nptr) throw () __attribute__ ((__pure__));



__extension__ extern long long int atoll (__const char *__nptr)
     throw () __attribute__ ((__pure__));



extern double strtod (__const char *__restrict __nptr,
                      char **__restrict __endptr) throw ();



extern float strtof (__const char *__restrict __nptr,
                     char **__restrict __endptr) throw ();

extern long double strtold (__const char *__restrict __nptr,
                            char **__restrict __endptr) throw ();



extern long int strtol (__const char *__restrict __nptr,
                        char **__restrict __endptr, int __base) throw ();

extern unsigned long int strtoul (__const char *__restrict __nptr,
                                  char **__restrict __endptr, int __base)
     throw ();



__extension__
extern long long int strtoq (__const char *__restrict __nptr,
                             char **__restrict __endptr, int __base) throw ();

__extension__
extern unsigned long long int strtouq (__const char *__restrict __nptr,
                                       char **__restrict __endptr, int __base)
     throw ();






__extension__
extern long long int strtoll (__const char *__restrict __nptr,
                              char **__restrict __endptr, int __base) throw ();

__extension__
extern unsigned long long int strtoull (__const char *__restrict __nptr,
                                        char **__restrict __endptr, int __base)
     throw ();
# 211 "/usr/include/stdlib.h" 3
# 1 "/usr/include/xlocale.h" 1 3
# 28 "/usr/include/xlocale.h" 3
typedef struct __locale_struct
{

  struct locale_data *__locales[13];


  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;
} *__locale_t;
# 212 "/usr/include/stdlib.h" 2 3



extern long int __strtol_l (__const char *__restrict __nptr,
                            char **__restrict __endptr, int __base,
                            __locale_t __loc) throw ();

extern unsigned long int __strtoul_l (__const char *__restrict __nptr,
                                      char **__restrict __endptr,
                                      int __base, __locale_t __loc) throw ();

__extension__
extern long long int __strtoll_l (__const char *__restrict __nptr,
                                  char **__restrict __endptr, int __base,
                                  __locale_t __loc) throw ();

__extension__
extern unsigned long long int __strtoull_l (__const char *__restrict __nptr,
                                            char **__restrict __endptr,
                                            int __base, __locale_t __loc)
     throw ();

extern double __strtod_l (__const char *__restrict __nptr,
                          char **__restrict __endptr, __locale_t __loc)
     throw ();

extern float __strtof_l (__const char *__restrict __nptr,
                         char **__restrict __endptr, __locale_t __loc) throw ();

extern long double __strtold_l (__const char *__restrict __nptr,
                                char **__restrict __endptr,
                                __locale_t __loc) throw ();






extern double __strtod_internal (__const char *__restrict __nptr,
                                 char **__restrict __endptr, int __group)
     throw ();
extern float __strtof_internal (__const char *__restrict __nptr,
                                char **__restrict __endptr, int __group)
     throw ();
extern long double __strtold_internal (__const char *__restrict __nptr,
                                       char **__restrict __endptr,
                                       int __group) throw ();

extern long int __strtol_internal (__const char *__restrict __nptr,
                                   char **__restrict __endptr,
                                   int __base, int __group) throw ();



extern unsigned long int __strtoul_internal (__const char *__restrict __nptr,
                                             char **__restrict __endptr,
                                             int __base, int __group) throw ();




__extension__
extern long long int __strtoll_internal (__const char *__restrict __nptr,
                                         char **__restrict __endptr,
                                         int __base, int __group) throw ();



__extension__
extern unsigned long long int __strtoull_internal (__const char *
                                                   __restrict __nptr,
                                                   char **__restrict __endptr,
                                                   int __base, int __group)
     throw ();







extern __inline double
strtod (__const char *__restrict __nptr, char **__restrict __endptr) throw ()
{
  return __strtod_internal (__nptr, __endptr, 0);
}
extern __inline long int
strtol (__const char *__restrict __nptr, char **__restrict __endptr,
        int __base) throw ()
{
  return __strtol_internal (__nptr, __endptr, __base, 0);
}
extern __inline unsigned long int
strtoul (__const char *__restrict __nptr, char **__restrict __endptr,
         int __base) throw ()
{
  return __strtoul_internal (__nptr, __endptr, __base, 0);
}


extern __inline float
strtof (__const char *__restrict __nptr, char **__restrict __endptr) throw ()
{
  return __strtof_internal (__nptr, __endptr, 0);
}
extern __inline long double
strtold (__const char *__restrict __nptr, char **__restrict __endptr) throw ()
{
  return __strtold_internal (__nptr, __endptr, 0);
}



__extension__ extern __inline long long int
strtoq (__const char *__restrict __nptr, char **__restrict __endptr,
        int __base) throw ()
{
  return __strtoll_internal (__nptr, __endptr, __base, 0);
}
__extension__ extern __inline unsigned long long int
strtouq (__const char *__restrict __nptr, char **__restrict __endptr,
         int __base) throw ()
{
  return __strtoull_internal (__nptr, __endptr, __base, 0);
}



__extension__ extern __inline long long int
strtoll (__const char *__restrict __nptr, char **__restrict __endptr,
         int __base) throw ()
{
  return __strtoll_internal (__nptr, __endptr, __base, 0);
}
__extension__ extern __inline unsigned long long int
strtoull (__const char * __restrict __nptr, char **__restrict __endptr,
          int __base) throw ()
{
  return __strtoull_internal (__nptr, __endptr, __base, 0);
}


extern __inline double
atof (__const char *__nptr) throw ()
{
  return strtod (__nptr, (char **) __null);
}
extern __inline int
atoi (__const char *__nptr) throw ()
{
  return (int) strtol (__nptr, (char **) __null, 10);
}
extern __inline long int
atol (__const char *__nptr) throw ()
{
  return strtol (__nptr, (char **) __null, 10);
}


__extension__ extern __inline long long int
atoll (__const char *__nptr) throw ()
{
  return strtoll (__nptr, (char **) __null, 10);
}
# 384 "/usr/include/stdlib.h" 3
extern char *l64a (long int __n) throw ();


extern long int a64l (__const char *__s) throw () __attribute__ ((__pure__));


# 1 "/usr/include/sys/types.h" 1 3
# 26 "/usr/include/sys/types.h" 3
# 1 "/usr/include/features.h" 1 3
# 27 "/usr/include/sys/types.h" 2 3

extern "C" {

# 1 "/usr/include/bits/types.h" 1 3
# 31 "/usr/include/sys/types.h" 2 3



typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;




typedef __loff_t loff_t;



typedef __ino_t ino_t;






typedef __ino64_t ino64_t;




typedef __dev_t dev_t;
# 71 "/usr/include/sys/types.h" 3
typedef __mode_t mode_t;




typedef __nlink_t nlink_t;
# 104 "/usr/include/sys/types.h" 3
typedef __id_t id_t;
# 115 "/usr/include/sys/types.h" 3
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;
# 132 "/usr/include/sys/types.h" 3
# 1 "/usr/include/time.h" 1 3
# 133 "/usr/include/sys/types.h" 2 3







typedef __suseconds_t suseconds_t;





# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stddef.h" 1 3
# 147 "/usr/include/sys/types.h" 2 3



typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
# 190 "/usr/include/sys/types.h" 3
typedef int int8_t __attribute__ ((__mode__ (__QI__)));
typedef int int16_t __attribute__ ((__mode__ (__HI__)));
typedef int int32_t __attribute__ ((__mode__ (__SI__)));
typedef int int64_t __attribute__ ((__mode__ (__DI__)));


typedef unsigned int u_int8_t __attribute__ ((__mode__ (__QI__)));
typedef unsigned int u_int16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int u_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int u_int64_t __attribute__ ((__mode__ (__DI__)));

typedef int register_t __attribute__ ((__mode__ (__word__)));
# 212 "/usr/include/sys/types.h" 3
# 1 "/usr/include/endian.h" 1 3
# 213 "/usr/include/sys/types.h" 2 3


# 1 "/usr/include/sys/select.h" 1 3
# 25 "/usr/include/sys/select.h" 3
# 1 "/usr/include/features.h" 1 3
# 26 "/usr/include/sys/select.h" 2 3


# 1 "/usr/include/bits/types.h" 1 3
# 29 "/usr/include/sys/select.h" 2 3


# 1 "/usr/include/bits/select.h" 1 3
# 32 "/usr/include/sys/select.h" 2 3


# 1 "/usr/include/bits/sigset.h" 1 3
# 23 "/usr/include/bits/sigset.h" 3
typedef int __sig_atomic_t;




typedef struct
  {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
  } __sigset_t;
# 35 "/usr/include/sys/select.h" 2 3



typedef __sigset_t sigset_t;





# 1 "/usr/include/time.h" 1 3
# 45 "/usr/include/sys/select.h" 2 3

# 1 "/usr/include/bits/time.h" 1 3
# 63 "/usr/include/bits/time.h" 3
# 1 "/usr/include/bits/types.h" 1 3
# 64 "/usr/include/bits/time.h" 2 3



struct timeval
  {
    __time_t tv_sec;
    __suseconds_t tv_usec;
  };
# 47 "/usr/include/sys/select.h" 2 3
# 55 "/usr/include/sys/select.h" 3
typedef long int __fd_mask;







typedef struct
  {



    __fd_mask fds_bits[1024 / (8 * sizeof (__fd_mask))];





  } fd_set;






typedef __fd_mask fd_mask;
# 95 "/usr/include/sys/select.h" 3
extern "C" {






extern int select (int __nfds, fd_set *__restrict __readfds,
                   fd_set *__restrict __writefds,
                   fd_set *__restrict __exceptfds,
                   struct timeval *__restrict __timeout) throw ();





extern int pselect (int __nfds, fd_set *__restrict __readfds,
                    fd_set *__restrict __writefds,
                    fd_set *__restrict __exceptfds,
                    const struct timespec *__restrict __timeout,
                    const __sigset_t *__restrict __sigmask) throw ();


}
# 216 "/usr/include/sys/types.h" 2 3


# 1 "/usr/include/sys/sysmacros.h" 1 3
# 219 "/usr/include/sys/types.h" 2 3




typedef __blksize_t blksize_t;






typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
# 257 "/usr/include/sys/types.h" 3
typedef __blkcnt64_t blkcnt64_t;
typedef __fsblkcnt64_t fsblkcnt64_t;
typedef __fsfilcnt64_t fsfilcnt64_t;


}
# 391 "/usr/include/stdlib.h" 2 3






extern long int random (void) throw ();


extern void srandom (unsigned int __seed) throw ();





extern char *initstate (unsigned int __seed, char *__statebuf,
                        size_t __statelen) throw ();



extern char *setstate (char *__statebuf) throw ();







struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };

extern int random_r (struct random_data *__restrict __buf,
                     int32_t *__restrict __result) throw ();

extern int srandom_r (unsigned int __seed, struct random_data *__buf) throw ();

extern int initstate_r (unsigned int __seed, char *__restrict __statebuf,
                        size_t __statelen,
                        struct random_data *__restrict __buf) throw ();

extern int setstate_r (char *__restrict __statebuf,
                       struct random_data *__restrict __buf) throw ();





extern int rand (void) throw ();

extern void srand (unsigned int __seed) throw ();



extern int rand_r (unsigned int *__seed) throw ();







extern double drand48 (void) throw ();
extern double erand48 (unsigned short int __xsubi[3]) throw ();


extern long int lrand48 (void) throw ();
extern long int nrand48 (unsigned short int __xsubi[3]) throw ();


extern long int mrand48 (void) throw ();
extern long int jrand48 (unsigned short int __xsubi[3]) throw ();


extern void srand48 (long int __seedval) throw ();
extern unsigned short int *seed48 (unsigned short int __seed16v[3]) throw ();
extern void lcong48 (unsigned short int __param[7]) throw ();





struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    unsigned long long int __a;
  };


extern int drand48_r (struct drand48_data *__restrict __buffer,
                      double *__restrict __result) throw ();
extern int erand48_r (unsigned short int __xsubi[3],
                      struct drand48_data *__restrict __buffer,
                      double *__restrict __result) throw ();


extern int lrand48_r (struct drand48_data *__restrict __buffer,
                      long int *__restrict __result) throw ();
extern int nrand48_r (unsigned short int __xsubi[3],
                      struct drand48_data *__restrict __buffer,
                      long int *__restrict __result) throw ();


extern int mrand48_r (struct drand48_data *__restrict __buffer,
                      long int *__restrict __result) throw ();
extern int jrand48_r (unsigned short int __xsubi[3],
                      struct drand48_data *__restrict __buffer,
                      long int *__restrict __result) throw ();


extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     throw ();

extern int seed48_r (unsigned short int __seed16v[3],
                     struct drand48_data *__buffer) throw ();

extern int lcong48_r (unsigned short int __param[7],
                      struct drand48_data *__buffer) throw ();
# 527 "/usr/include/stdlib.h" 3
extern void *malloc (size_t __size) throw () __attribute__ ((__malloc__));

extern void *calloc (size_t __nmemb, size_t __size)
     throw () __attribute__ ((__malloc__));





extern void *realloc (void *__ptr, size_t __size) throw () __attribute__ ((__malloc__));

extern void free (void *__ptr) throw ();



extern void cfree (void *__ptr) throw ();



# 1 "/usr/include/alloca.h" 1 3
# 22 "/usr/include/alloca.h" 3
# 1 "/usr/include/features.h" 1 3
# 23 "/usr/include/alloca.h" 2 3


# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stddef.h" 1 3
# 26 "/usr/include/alloca.h" 2 3

extern "C" {





extern void *alloca (size_t __size) throw ();





}
# 547 "/usr/include/stdlib.h" 2 3




extern void *valloc (size_t __size) throw () __attribute__ ((__malloc__));




extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     throw () __attribute__ ((__malloc__));



extern void abort (void) throw () __attribute__ ((__noreturn__));



extern int atexit (void (*__func) (void)) throw ();




extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     throw ();





extern void exit (int __status) throw () __attribute__ ((__noreturn__));




extern void _Exit (int __status) throw () __attribute__ ((__noreturn__));




extern char *getenv (__const char *__name) throw ();



extern char *__secure_getenv (__const char *__name) throw ();





extern int putenv (char *__string) throw ();





extern int setenv (__const char *__name, __const char *__value, int __replace)
     throw ();


extern int unsetenv (__const char *__name) throw ();






extern int clearenv (void) throw ();
# 623 "/usr/include/stdlib.h" 3
extern char *mktemp (char *__template) throw ();







extern int mkstemp (char *__template) throw ();
# 640 "/usr/include/stdlib.h" 3
extern int mkstemp64 (char *__template) throw ();
# 650 "/usr/include/stdlib.h" 3
extern char *mkdtemp (char *__template) throw ();




extern int system (__const char *__command) throw ();






extern char *canonicalize_file_name (__const char *__name) throw ();
# 672 "/usr/include/stdlib.h" 3
extern char *realpath (__const char *__restrict __name,
                       char *__restrict __resolved) throw ();






typedef int (*__compar_fn_t) (__const void *, __const void *);


typedef __compar_fn_t comparison_fn_t;





extern void *bsearch (__const void *__key, __const void *__base,
                      size_t __nmemb, size_t __size, __compar_fn_t __compar);



extern void qsort (void *__base, size_t __nmemb, size_t __size,
                   __compar_fn_t __compar);



extern int abs (int __x) throw () __attribute__ ((__const__));
extern long int labs (long int __x) throw () __attribute__ ((__const__));

__extension__ extern long long int llabs (long long int __x)
     throw () __attribute__ ((__const__));






extern div_t div (int __numer, int __denom)
     throw () __attribute__ ((__const__));
extern ldiv_t ldiv (long int __numer, long int __denom)
     throw () __attribute__ ((__const__));

__extension__ extern lldiv_t lldiv (long long int __numer,
                                    long long int __denom)
     throw () __attribute__ ((__const__));
# 728 "/usr/include/stdlib.h" 3
extern char *ecvt (double __value, int __ndigit, int *__restrict __decpt,
                   int *__restrict __sign) throw ();




extern char *fcvt (double __value, int __ndigit, int *__restrict __decpt,
                   int *__restrict __sign) throw ();




extern char *gcvt (double __value, int __ndigit, char *__buf) throw ();




extern char *qecvt (long double __value, int __ndigit,
                    int *__restrict __decpt, int *__restrict __sign) throw ();
extern char *qfcvt (long double __value, int __ndigit,
                    int *__restrict __decpt, int *__restrict __sign) throw ();
extern char *qgcvt (long double __value, int __ndigit, char *__buf) throw ();




extern int ecvt_r (double __value, int __ndigit, int *__restrict __decpt,
                   int *__restrict __sign, char *__restrict __buf,
                   size_t __len) throw ();
extern int fcvt_r (double __value, int __ndigit, int *__restrict __decpt,
                   int *__restrict __sign, char *__restrict __buf,
                   size_t __len) throw ();

extern int qecvt_r (long double __value, int __ndigit,
                    int *__restrict __decpt, int *__restrict __sign,
                    char *__restrict __buf, size_t __len) throw ();
extern int qfcvt_r (long double __value, int __ndigit,
                    int *__restrict __decpt, int *__restrict __sign,
                    char *__restrict __buf, size_t __len) throw ();






extern int mblen (__const char *__s, size_t __n) throw ();


extern int mbtowc (wchar_t *__restrict __pwc,
                   __const char *__restrict __s, size_t __n) throw ();


extern int wctomb (char *__s, wchar_t __wchar) throw ();



extern size_t mbstowcs (wchar_t *__restrict __pwcs,
                        __const char *__restrict __s, size_t __n) throw ();

extern size_t wcstombs (char *__restrict __s,
                        __const wchar_t *__restrict __pwcs, size_t __n)
     throw ();







extern int rpmatch (__const char *__response) throw ();
# 808 "/usr/include/stdlib.h" 3
extern int getsubopt (char **__restrict __optionp,
                      char *__const *__restrict __tokens,
                      char **__restrict __valuep) throw ();





extern void setkey (__const char *__key) throw ();







extern int posix_openpt (int __oflag) throw ();







extern int grantpt (int __fd) throw ();



extern int unlockpt (int __fd) throw ();




extern char *ptsname (int __fd) throw ();






extern int ptsname_r (int __fd, char *__buf, size_t __buflen) throw ();


extern int getpt (void) throw ();






extern int getloadavg (double __loadavg[], int __nelem) throw ();





}
# 53 "../../../../src/aleph/ahDefs.H" 2
# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdio.h" 1 3
# 37 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdio.h" 3
# 1 "/usr/include/features.h" 1 3
# 38 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdio.h" 2 3

extern "C" {



# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stddef.h" 1 3
# 44 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdio.h" 2 3

# 1 "/usr/include/bits/types.h" 1 3
# 46 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdio.h" 2 3
# 54 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdio.h" 3
typedef struct _IO_FILE FILE;
# 64 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdio.h" 3
typedef struct _IO_FILE __FILE;
# 74 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdio.h" 3
# 1 "/usr/include/libio.h" 1 3
# 32 "/usr/include/libio.h" 3
# 1 "/usr/include/_G_config.h" 1 3
# 9 "/usr/include/_G_config.h" 3
# 1 "/usr/include/bits/types.h" 1 3
# 10 "/usr/include/_G_config.h" 2 3




# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stddef.h" 1 3
# 312 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stddef.h" 3
typedef unsigned int wint_t;
# 15 "/usr/include/_G_config.h" 2 3
# 24 "/usr/include/_G_config.h" 3
# 1 "/usr/include/wchar.h" 1 3
# 48 "/usr/include/wchar.h" 3
# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stddef.h" 1 3
# 49 "/usr/include/wchar.h" 2 3

# 1 "/usr/include/bits/wchar.h" 1 3
# 51 "/usr/include/wchar.h" 2 3
# 67 "/usr/include/wchar.h" 3
typedef struct
{
  int __count;
  union
  {
    wint_t __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
# 25 "/usr/include/_G_config.h" 2 3

typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
# 44 "/usr/include/_G_config.h" 3
# 1 "/usr/include/gconv.h" 1 3
# 26 "/usr/include/gconv.h" 3
# 1 "/usr/include/features.h" 1 3
# 27 "/usr/include/gconv.h" 2 3

# 1 "/usr/include/wchar.h" 1 3
# 48 "/usr/include/wchar.h" 3
# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stddef.h" 1 3
# 49 "/usr/include/wchar.h" 2 3

# 1 "/usr/include/bits/wchar.h" 1 3
# 51 "/usr/include/wchar.h" 2 3
# 29 "/usr/include/gconv.h" 2 3


# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stddef.h" 1 3
# 32 "/usr/include/gconv.h" 2 3





enum
{
  __GCONV_OK = 0,
  __GCONV_NOCONV,
  __GCONV_NODB,
  __GCONV_NOMEM,

  __GCONV_EMPTY_INPUT,
  __GCONV_FULL_OUTPUT,
  __GCONV_ILLEGAL_INPUT,
  __GCONV_INCOMPLETE_INPUT,

  __GCONV_ILLEGAL_DESCRIPTOR,
  __GCONV_INTERNAL_ERROR
};



enum
{
  __GCONV_IS_LAST = 0x0001,
  __GCONV_IGNORE_ERRORS = 0x0002
};



struct __gconv_step;
struct __gconv_step_data;
struct __gconv_loaded_object;
struct __gconv_trans_data;



typedef int (*__gconv_fct) (struct __gconv_step *, struct __gconv_step_data *,
                            __const unsigned char **, __const unsigned char *,
                            unsigned char **, size_t *, int, int);


typedef int (*__gconv_init_fct) (struct __gconv_step *);
typedef void (*__gconv_end_fct) (struct __gconv_step *);



typedef int (*__gconv_trans_fct) (struct __gconv_step *,
                                  struct __gconv_step_data *, void *,
                                  __const unsigned char *,
                                  __const unsigned char **,
                                  __const unsigned char *, unsigned char **,
                                  size_t *);


typedef int (*__gconv_trans_context_fct) (void *, __const unsigned char *,
                                          __const unsigned char *,
                                          unsigned char *, unsigned char *);


typedef int (*__gconv_trans_query_fct) (__const char *, __const char ***,
                                        size_t *);


typedef int (*__gconv_trans_init_fct) (void **, const char *);
typedef void (*__gconv_trans_end_fct) (void *);

struct __gconv_trans_data
{

  __gconv_trans_fct __trans_fct;
  __gconv_trans_context_fct __trans_context_fct;
  __gconv_trans_end_fct __trans_end_fct;
  void *__data;
  struct __gconv_trans_data *__next;
};



struct __gconv_step
{
  struct __gconv_loaded_object *__shlib_handle;
  __const char *__modname;

  int __counter;

  char *__from_name;
  char *__to_name;

  __gconv_fct __fct;
  __gconv_init_fct __init_fct;
  __gconv_end_fct __end_fct;



  int __min_needed_from;
  int __max_needed_from;
  int __min_needed_to;
  int __max_needed_to;


  int __stateful;

  void *__data;
};



struct __gconv_step_data
{
  unsigned char *__outbuf;
  unsigned char *__outbufend;



  int __flags;



  int __invocation_counter;



  int __internal_use;

  __mbstate_t *__statep;
  __mbstate_t __state;



  struct __gconv_trans_data *__trans;
};



typedef struct __gconv_info
{
  size_t __nsteps;
  struct __gconv_step *__steps;
  __extension__ struct __gconv_step_data __data [];
} *__gconv_t;
# 45 "/usr/include/_G_config.h" 2 3
typedef union
{
  struct __gconv_info __cd;
  struct
  {
    struct __gconv_info __cd;
    struct __gconv_step_data __data;
  } __combined;
} _G_iconv_t;

typedef int _G_int16_t __attribute__ ((__mode__ (__HI__)));
typedef int _G_int32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int _G_uint16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int _G_uint32_t __attribute__ ((__mode__ (__SI__)));
# 33 "/usr/include/libio.h" 2 3
# 53 "/usr/include/libio.h" 3
# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdarg.h" 1 3
# 43 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdarg.h" 3
typedef __builtin_va_list __gnuc_va_list;
# 54 "/usr/include/libio.h" 2 3
# 160 "/usr/include/libio.h" 3
struct _IO_jump_t; struct _IO_FILE;
# 170 "/usr/include/libio.h" 3
typedef void _IO_lock_t;





struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;



  int _pos;
# 193 "/usr/include/libio.h" 3
};


enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};
# 261 "/usr/include/libio.h" 3
struct _IO_FILE {
  int _flags;




  char* _IO_read_ptr;
  char* _IO_read_end;
  char* _IO_read_base;
  char* _IO_write_base;
  char* _IO_write_ptr;
  char* _IO_write_end;
  char* _IO_buf_base;
  char* _IO_buf_end;

  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;
  int _blksize;
  __off_t _old_offset;



  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];



  _IO_lock_t *_lock;
# 305 "/usr/include/libio.h" 3
  __off64_t _offset;





  void *__pad1;
  void *__pad2;

  int _mode;

  char _unused2[15 * sizeof (int) - 2 * sizeof (void *)];

};





struct _IO_FILE_plus;

extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
# 344 "/usr/include/libio.h" 3
typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);







typedef __ssize_t __io_write_fn (void *__cookie, __const char *__buf,
                                 size_t __n);







typedef int __io_seek_fn (void *__cookie, __off64_t *__pos, int __w);


typedef int __io_close_fn (void *__cookie);




typedef __io_read_fn cookie_read_function_t;
typedef __io_write_fn cookie_write_function_t;
typedef __io_seek_fn cookie_seek_function_t;
typedef __io_close_fn cookie_close_function_t;


typedef struct
{
  __io_read_fn *read;
  __io_write_fn *write;
  __io_seek_fn *seek;
  __io_close_fn *close;
} _IO_cookie_io_functions_t;
typedef _IO_cookie_io_functions_t cookie_io_functions_t;

struct _IO_cookie_file;


extern void _IO_cookie_init (struct _IO_cookie_file *__cfile, int __read_write,
                             void *__cookie, _IO_cookie_io_functions_t __fns);




extern "C" {


extern int __underflow (_IO_FILE *) throw ();
extern int __uflow (_IO_FILE *) throw ();
extern int __overflow (_IO_FILE *, int) throw ();
extern wint_t __wunderflow (_IO_FILE *) throw ();
extern wint_t __wuflow (_IO_FILE *) throw ();
extern wint_t __woverflow (_IO_FILE *, wint_t) throw ();
# 426 "/usr/include/libio.h" 3
extern int _IO_getc (_IO_FILE *__fp) throw ();
extern int _IO_putc (int __c, _IO_FILE *__fp) throw ();
extern int _IO_feof (_IO_FILE *__fp) throw ();
extern int _IO_ferror (_IO_FILE *__fp) throw ();

extern int _IO_peekc_locked (_IO_FILE *__fp) throw ();





extern void _IO_flockfile (_IO_FILE *) throw ();
extern void _IO_funlockfile (_IO_FILE *) throw ();
extern int _IO_ftrylockfile (_IO_FILE *) throw ();
# 456 "/usr/include/libio.h" 3
extern int _IO_vfscanf (_IO_FILE * __restrict, const char * __restrict,
                        __gnuc_va_list, int *__restrict) throw ();
extern int _IO_vfprintf (_IO_FILE *__restrict, const char *__restrict,
                         __gnuc_va_list) throw ();
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t) throw ();
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t) throw ();

extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int) throw ();
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int) throw ();

extern void _IO_free_backup_area (_IO_FILE *) throw ();
# 514 "/usr/include/libio.h" 3
}
# 75 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdio.h" 2 3




typedef __gnuc_va_list __not_va_list__;
# 89 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdio.h" 3
typedef _G_fpos_t fpos_t;




typedef _G_fpos64_t fpos64_t;
# 138 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdio.h" 3
# 1 "/usr/include/bits/stdio_lim.h" 1 3
# 139 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdio.h" 2 3



extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
# 153 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdio.h" 3
extern int remove (__const char *__filename) throw ();

extern int rename (__const char *__old, __const char *__new) throw ();




extern FILE *tmpfile (void) throw ();
# 169 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdio.h" 3
extern FILE *tmpfile64 (void) throw ();


extern char *tmpnam (char *__s) throw ();




extern char *tmpnam_r (char *__s) throw ();
# 189 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdio.h" 3
extern char *tempnam (__const char *__dir, __const char *__pfx)
     throw () __attribute__ ((__malloc__));




extern int fclose (FILE *__stream) throw ();

extern int fflush (FILE *__stream) throw ();



extern int fflush_unlocked (FILE *__stream) throw ();




extern int fcloseall (void) throw ();





extern FILE *fopen (__const char *__restrict __filename,
                    __const char *__restrict __modes) throw ();

extern FILE *freopen (__const char *__restrict __filename,
                      __const char *__restrict __modes,
                      FILE *__restrict __stream) throw ();
# 233 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdio.h" 3
extern FILE *fopen64 (__const char *__restrict __filename,
                      __const char *__restrict __modes) throw ();
extern FILE *freopen64 (__const char *__restrict __filename,
                        __const char *__restrict __modes,
                        FILE *__restrict __stream) throw ();




extern FILE *fdopen (int __fd, __const char *__modes) throw ();





extern FILE *fopencookie (void *__restrict __magic_cookie,
                          __const char *__restrict __modes,
                          _IO_cookie_io_functions_t __io_funcs) throw ();


extern FILE *fmemopen (void *__s, size_t __len, __const char *__modes) throw ();




extern FILE *open_memstream (char **__restrict __bufloc,
                             size_t *__restrict __sizeloc) throw ();





extern void setbuf (FILE *__restrict __stream, char *__restrict __buf) throw ();



extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
                    int __modes, size_t __n) throw ();




extern void setbuffer (FILE *__restrict __stream, char *__restrict __buf,
                       size_t __size) throw ();


extern void setlinebuf (FILE *__stream) throw ();




extern int fprintf (FILE *__restrict __stream,
                    __const char *__restrict __format, ...) throw ();

extern int printf (__const char *__restrict __format, ...) throw ();

extern int sprintf (char *__restrict __s,
                    __const char *__restrict __format, ...) throw ();


extern int vfprintf (FILE *__restrict __s, __const char *__restrict __format,
                     __gnuc_va_list __arg) throw ();

extern int vprintf (__const char *__restrict __format, __gnuc_va_list __arg)
     throw ();

extern int vsprintf (char *__restrict __s, __const char *__restrict __format,
                     __gnuc_va_list __arg) throw ();



extern int snprintf (char *__restrict __s, size_t __maxlen,
                     __const char *__restrict __format, ...)
     throw () __attribute__ ((__format__ (__printf__, 3, 4)));

extern int vsnprintf (char *__restrict __s, size_t __maxlen,
                      __const char *__restrict __format, __gnuc_va_list __arg)
     throw () __attribute__ ((__format__ (__printf__, 3, 0)));





extern int vasprintf (char **__restrict __ptr, __const char *__restrict __f,
                      __gnuc_va_list __arg)
     throw () __attribute__ ((__format__ (__printf__, 2, 0)));
extern int __asprintf (char **__restrict __ptr,
                       __const char *__restrict __fmt, ...)
     throw () __attribute__ ((__format__ (__printf__, 2, 3)));
extern int asprintf (char **__restrict __ptr,
                     __const char *__restrict __fmt, ...)
     throw () __attribute__ ((__format__ (__printf__, 2, 3)));


extern int vdprintf (int __fd, __const char *__restrict __fmt,
                     __gnuc_va_list __arg)
     throw () __attribute__ ((__format__ (__printf__, 2, 0)));
extern int dprintf (int __fd, __const char *__restrict __fmt, ...)
     throw () __attribute__ ((__format__ (__printf__, 2, 3)));




extern int fscanf (FILE *__restrict __stream,
                   __const char *__restrict __format, ...) throw ();

extern int scanf (__const char *__restrict __format, ...) throw ();

extern int sscanf (__const char *__restrict __s,
                   __const char *__restrict __format, ...) throw ();



extern int vfscanf (FILE *__restrict __s, __const char *__restrict __format,
                    __gnuc_va_list __arg)
     throw () __attribute__ ((__format__ (__scanf__, 2, 0)));


extern int vscanf (__const char *__restrict __format, __gnuc_va_list __arg)
     throw () __attribute__ ((__format__ (__scanf__, 1, 0)));


extern int vsscanf (__const char *__restrict __s,
                    __const char *__restrict __format, __gnuc_va_list __arg)
     throw () __attribute__ ((__format__ (__scanf__, 2, 0)));




extern int fgetc (FILE *__stream) throw ();
extern int getc (FILE *__stream) throw ();


extern int getchar (void) throw ();







extern int getc_unlocked (FILE *__stream) throw ();
extern int getchar_unlocked (void) throw ();




extern int fgetc_unlocked (FILE *__stream) throw ();




extern int fputc (int __c, FILE *__stream) throw ();
extern int putc (int __c, FILE *__stream) throw ();


extern int putchar (int __c) throw ();







extern int fputc_unlocked (int __c, FILE *__stream) throw ();




extern int putc_unlocked (int __c, FILE *__stream) throw ();
extern int putchar_unlocked (int __c) throw ();





extern int getw (FILE *__stream) throw ();


extern int putw (int __w, FILE *__stream) throw ();




extern char *fgets (char *__restrict __s, int __n, FILE *__restrict __stream)
     throw ();



extern char *fgets_unlocked (char *__restrict __s, int __n,
                             FILE *__restrict __stream) throw ();




extern char *gets (char *__s) throw ();
# 437 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdio.h" 3
extern __ssize_t __getdelim (char **__restrict __lineptr,
                               size_t *__restrict __n, int __delimiter,
                               FILE *__restrict __stream) throw ();
extern __ssize_t getdelim (char **__restrict __lineptr,
                             size_t *__restrict __n, int __delimiter,
                             FILE *__restrict __stream) throw ();


extern __ssize_t getline (char **__restrict __lineptr,
                            size_t *__restrict __n,
                            FILE *__restrict __stream) throw ();




extern int fputs (__const char *__restrict __s, FILE *__restrict __stream)
     throw ();



extern int fputs_unlocked (__const char *__restrict __s,
                           FILE *__restrict __stream) throw ();



extern int puts (__const char *__s) throw ();



extern int ungetc (int __c, FILE *__stream) throw ();



extern size_t fread (void *__restrict __ptr, size_t __size,
                     size_t __n, FILE *__restrict __stream) throw ();

extern size_t fwrite (__const void *__restrict __ptr, size_t __size,
                      size_t __n, FILE *__restrict __s) throw ();



extern size_t fread_unlocked (void *__restrict __ptr, size_t __size,
                              size_t __n, FILE *__restrict __stream) throw ();
extern size_t fwrite_unlocked (__const void *__restrict __ptr, size_t __size,
                               size_t __n, FILE *__restrict __stream) throw ();




extern int fseek (FILE *__stream, long int __off, int __whence) throw ();

extern long int ftell (FILE *__stream) throw ();

extern void rewind (FILE *__stream) throw ();
# 500 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdio.h" 3
extern int fseeko (FILE *__stream, __off_t __off, int __whence) throw ();

extern __off_t ftello (FILE *__stream) throw ();



extern int fgetpos (FILE *__restrict __stream, fpos_t *__restrict __pos)
     throw ();

extern int fsetpos (FILE *__stream, __const fpos_t *__pos) throw ();
# 534 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdio.h" 3
extern int fseeko64 (FILE *__stream, __off64_t __off, int __whence) throw ();
extern __off64_t ftello64 (FILE *__stream) throw ();
extern int fgetpos64 (FILE *__restrict __stream, fpos64_t *__restrict __pos)
     throw ();
extern int fsetpos64 (FILE *__stream, __const fpos64_t *__pos) throw ();



extern void clearerr (FILE *__stream) throw ();

extern int feof (FILE *__stream) throw ();

extern int ferror (FILE *__stream) throw ();



extern void clearerr_unlocked (FILE *__stream) throw ();
extern int feof_unlocked (FILE *__stream) throw ();
extern int ferror_unlocked (FILE *__stream) throw ();




extern void perror (__const char *__s) throw ();




extern int sys_nerr;
extern __const char *__const sys_errlist[];


extern int _sys_nerr;
extern __const char *__const _sys_errlist[];





extern int fileno (FILE *__stream) throw ();




extern int fileno_unlocked (FILE *__stream) throw ();






extern FILE *popen (__const char *__command, __const char *__modes) throw ();


extern int pclose (FILE *__stream) throw ();





extern char *ctermid (char *__s) throw ();





extern char *cuserid (char *__s) throw ();




struct obstack;


extern int obstack_printf (struct obstack *__restrict __obstack,
                           __const char *__restrict __format, ...) throw ();
extern int obstack_vprintf (struct obstack *__restrict __obstack,
                            __const char *__restrict __format,
                            __gnuc_va_list __args) throw ();







extern void flockfile (FILE *__stream) throw ();



extern int ftrylockfile (FILE *__stream) throw ();


extern void funlockfile (FILE *__stream) throw ();
# 641 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdio.h" 3
# 1 "/usr/include/bits/stdio.h" 1 3
# 33 "/usr/include/bits/stdio.h" 3
inline int
vprintf (__const char *__restrict __fmt, __gnuc_va_list __arg) throw ()
{
  return vfprintf (stdout, __fmt, __arg);
}


inline int
getchar (void) throw ()
{
  return _IO_getc (stdin);
}




inline int
getc_unlocked (FILE *__fp) throw ()
{
  return ((__fp)->_IO_read_ptr >= (__fp)->_IO_read_end ? __uflow (__fp) : *(unsigned char *) (__fp)->_IO_read_ptr++);
}


inline int
getchar_unlocked (void) throw ()
{
  return ((stdin)->_IO_read_ptr >= (stdin)->_IO_read_end ? __uflow (stdin) : *(unsigned char *) (stdin)->_IO_read_ptr++);
}




inline int
putchar (int __c) throw ()
{
  return _IO_putc (__c, stdout);
}




inline int
fputc_unlocked (int __c, FILE *__stream) throw ()
{
  return (((__stream)->_IO_write_ptr >= (__stream)->_IO_write_end) ? __overflow (__stream, (unsigned char) (__c)) : (unsigned char) (*(__stream)->_IO_write_ptr++ = (__c)));
}





inline int
putc_unlocked (int __c, FILE *__stream) throw ()
{
  return (((__stream)->_IO_write_ptr >= (__stream)->_IO_write_end) ? __overflow (__stream, (unsigned char) (__c)) : (unsigned char) (*(__stream)->_IO_write_ptr++ = (__c)));
}


inline int
putchar_unlocked (int __c) throw ()
{
  return (((stdout)->_IO_write_ptr >= (stdout)->_IO_write_end) ? __overflow (stdout, (unsigned char) (__c)) : (unsigned char) (*(stdout)->_IO_write_ptr++ = (__c)));
}





inline __ssize_t
getline (char **__lineptr, size_t *__n, FILE *__stream) throw ()
{
  return __getdelim (__lineptr, __n, '\n', __stream);
}





inline int
feof_unlocked (FILE *__stream) throw ()
{
  return (((__stream)->_flags & 0x10) != 0);
}


inline int
ferror_unlocked (FILE *__stream) throw ()
{
  return (((__stream)->_flags & 0x20) != 0);
}
# 642 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdio.h" 2 3


}
# 54 "../../../../src/aleph/ahDefs.H" 2
# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdarg.h" 1 3
# 110 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdarg.h" 3
typedef __gnuc_va_list va_list;
# 55 "../../../../src/aleph/ahDefs.H" 2

enum EmptyCtor { emptyCtor };

enum SentinelCtor { sentinelCtor };

namespace Aleph
{
  struct Empty_Class
  {
    Empty_Class() { }

    Empty_Class(EmptyCtor) { }

    Empty_Class(SentinelCtor) { }

    bool operator == (const Empty_Class &) const
    {
      return true;
    }

    bool operator != (const Empty_Class &) const
    {
      return false;
    }
  };

  const int UnknownSize = -1;
  const int UnknownLine = -1;
  const int UnknownLoad = -1;

  extern bool daemonized;

  extern void message(const char * file, int line, const char *format, ...);

  extern void error(const char * file, int line, const char *format, ...);

  extern void exit(const char * file, int line, const char *format, ...);

  extern void warning(const char * file, int line, const char *format, ...);

  extern void syslog(const char * format, va_list ap);
}
# 51 "../../../../src/aleph/aleph.H" 2
# 1 "../../../../src/aleph/ahAssert.H" 1
# 81 "../../../../src/aleph/ahAssert.H"
# 1 "/usr/include/stdlib.h" 1 3
# 82 "../../../../src/aleph/ahAssert.H" 2
# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdio.h" 1 3
# 83 "../../../../src/aleph/ahAssert.H" 2





# 1 "/usr/local/include/nana.h" 1
# 35 "/usr/local/include/nana.h"
# 1 "/usr/local/include/I.h" 1
# 36 "/usr/local/include/I.h"
extern "C" {
# 228 "/usr/local/include/I.h"
}
# 36 "/usr/local/include/nana.h" 2
# 1 "/usr/local/include/DI.h" 1
# 35 "/usr/local/include/DI.h"
extern "C" {
# 260 "/usr/local/include/DI.h"
}
# 37 "/usr/local/include/nana.h" 2

# 1 "/usr/local/include/L.h" 1
# 36 "/usr/local/include/L.h"
extern "C" {
# 201 "/usr/local/include/L.h"
}
# 39 "/usr/local/include/nana.h" 2
# 1 "/usr/local/include/DL.h" 1
# 35 "/usr/local/include/DL.h"
extern "C" {
# 219 "/usr/local/include/DL.h"
}
# 40 "/usr/local/include/nana.h" 2

# 1 "/usr/local/include/Q.h" 1
# 40 "/usr/local/include/Q.h"
extern "C" {
# 156 "/usr/local/include/Q.h"
}
# 42 "/usr/local/include/nana.h" 2

# 1 "/usr/local/include/GDB.h" 1
# 35 "/usr/local/include/GDB.h"
extern "C" {
# 86 "/usr/local/include/GDB.h"
}
# 44 "/usr/local/include/nana.h" 2
# 89 "../../../../src/aleph/ahAssert.H" 2
# 1 "/usr/local/include/eiffel.h" 1
# 36 "/usr/local/include/eiffel.h"
extern "C" {


# 1 "/usr/local/include/nana.h" 1
# 40 "/usr/local/include/eiffel.h" 2







typedef enum {
  CHECK_NO,
  CHECK_REQUIRE,
  CHECK_ENSURE,
  CHECK_INVARIANT,
  CHECK_LOOP,
  CHECK_ALL
} EIFFEL_CHECK_LEVEL;
# 73 "/usr/local/include/eiffel.h"
static inline bool invariant() {
  return true;
}
# 160 "/usr/local/include/eiffel.h"
}
# 90 "../../../../src/aleph/ahAssert.H" 2
# 1 "/usr/local/include/L.h" 1
# 91 "../../../../src/aleph/ahAssert.H" 2
# 52 "../../../../src/aleph/aleph.H" 2
# 1 "../../../../src/aleph/ahExceptions.H" 1
# 54 "../../../../src/aleph/ahExceptions.H"
# 1 "/usr/include/string.h" 1 3
# 26 "/usr/include/string.h" 3
# 1 "/usr/include/features.h" 1 3
# 27 "/usr/include/string.h" 2 3

extern "C" {




# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stddef.h" 1 3
# 34 "/usr/include/string.h" 2 3



extern void *memcpy (void *__restrict __dest,
                     __const void *__restrict __src, size_t __n) throw ();


extern void *memmove (void *__dest, __const void *__src, size_t __n)
     throw ();





extern void *memccpy (void *__restrict __dest, __const void *__restrict __src,
                      int __c, size_t __n)
     throw ();




extern void *memset (void *__s, int __c, size_t __n) throw ();


extern int memcmp (__const void *__s1, __const void *__s2, size_t __n)
     throw () __attribute__ ((__pure__));


extern void *memchr (__const void *__s, int __c, size_t __n)
      throw () __attribute__ ((__pure__));




extern void *rawmemchr (__const void *__s, int __c) throw () __attribute__ ((__pure__));


extern void *memrchr (__const void *__s, int __c, size_t __n)
      throw () __attribute__ ((__pure__));




extern char *strcpy (char *__restrict __dest, __const char *__restrict __src)
     throw ();

extern char *strncpy (char *__restrict __dest,
                      __const char *__restrict __src, size_t __n) throw ();


extern char *strcat (char *__restrict __dest, __const char *__restrict __src)
     throw ();

extern char *strncat (char *__restrict __dest, __const char *__restrict __src,
                      size_t __n) throw ();


extern int strcmp (__const char *__s1, __const char *__s2)
     throw () __attribute__ ((__pure__));

extern int strncmp (__const char *__s1, __const char *__s2, size_t __n)
     throw () __attribute__ ((__pure__));


extern int strcoll (__const char *__s1, __const char *__s2)
     throw () __attribute__ ((__pure__));

extern size_t strxfrm (char *__restrict __dest,
                       __const char *__restrict __src, size_t __n) throw ();





# 1 "/usr/include/xlocale.h" 1 3
# 109 "/usr/include/string.h" 2 3


extern int __strcoll_l (__const char *__s1, __const char *__s2, __locale_t __l)
     throw () __attribute__ ((__pure__));

extern size_t __strxfrm_l (char *__dest, __const char *__src, size_t __n,
                           __locale_t __l) throw ();




extern char *strdup (__const char *__s) throw () __attribute__ ((__malloc__));






extern char *strndup (__const char *__string, size_t __n)
     throw () __attribute__ ((__malloc__));
# 155 "/usr/include/string.h" 3
extern char *strchr (__const char *__s, int __c) throw () __attribute__ ((__pure__));

extern char *strrchr (__const char *__s, int __c) throw () __attribute__ ((__pure__));




extern char *strchrnul (__const char *__s, int __c) throw () __attribute__ ((__pure__));




extern size_t strcspn (__const char *__s, __const char *__reject)
     throw () __attribute__ ((__pure__));


extern size_t strspn (__const char *__s, __const char *__accept)
     throw () __attribute__ ((__pure__));

extern char *strpbrk (__const char *__s, __const char *__accept)
     throw () __attribute__ ((__pure__));

extern char *strstr (__const char *__haystack, __const char *__needle)
     throw () __attribute__ ((__pure__));



extern char *strcasestr (__const char *__haystack, __const char *__needle)
     throw () __attribute__ ((__pure__));



extern char *strtok (char *__restrict __s, __const char *__restrict __delim)
     throw ();



extern char *__strtok_r (char *__restrict __s,
                         __const char *__restrict __delim,
                         char **__restrict __save_ptr) throw ();

extern char *strtok_r (char *__restrict __s, __const char *__restrict __delim,
                       char **__restrict __save_ptr) throw ();






extern void *memmem (__const void *__haystack, size_t __haystacklen,
                     __const void *__needle, size_t __needlelen)
     throw () __attribute__ ((__pure__));



extern void *__mempcpy (void *__restrict __dest,
                        __const void *__restrict __src, size_t __n) throw ();
extern void *mempcpy (void *__restrict __dest,
                      __const void *__restrict __src, size_t __n) throw ();




extern size_t strlen (__const char *__s) throw () __attribute__ ((__pure__));




extern size_t strnlen (__const char *__string, size_t __maxlen)
     throw () __attribute__ ((__pure__));




extern char *strerror (int __errnum) throw ();



extern char *strerror_r (int __errnum, char *__buf, size_t __buflen) throw ();




extern void __bzero (void *__s, size_t __n) throw ();



extern void bcopy (__const void *__src, void *__dest, size_t __n) throw ();


extern void bzero (void *__s, size_t __n) throw ();


extern int bcmp (__const void *__s1, __const void *__s2, size_t __n)
     throw () __attribute__ ((__pure__));


extern char *index (__const char *__s, int __c) throw () __attribute__ ((__pure__));


extern char *rindex (__const char *__s, int __c) throw () __attribute__ ((__pure__));



extern int ffs (int __i) throw () __attribute__ ((__const__));




extern int ffsl (long int __l) throw () __attribute__ ((__const__));

__extension__ extern int ffsll (long long int __ll)
     throw () __attribute__ ((__const__));




extern int strcasecmp (__const char *__s1, __const char *__s2)
     throw () __attribute__ ((__pure__));


extern int strncasecmp (__const char *__s1, __const char *__s2, size_t __n)
     throw () __attribute__ ((__pure__));





extern int __strcasecmp_l (__const char *__s1, __const char *__s2,
                           __locale_t __loc) throw () __attribute__ ((__pure__));

extern int __strncasecmp_l (__const char *__s1, __const char *__s2,
                            size_t __n, __locale_t __loc)
     throw () __attribute__ ((__pure__));





extern char *strsep (char **__restrict __stringp,
                     __const char *__restrict __delim) throw ();




extern int strverscmp (__const char *__s1, __const char *__s2)
     throw () __attribute__ ((__pure__));


extern char *strsignal (int __sig) throw ();


extern char *__stpcpy (char *__restrict __dest, __const char *__restrict __src)
     throw ();
extern char *stpcpy (char *__restrict __dest, __const char *__restrict __src)
     throw ();



extern char *__stpncpy (char *__restrict __dest,
                        __const char *__restrict __src, size_t __n) throw ();
extern char *stpncpy (char *__restrict __dest,
                      __const char *__restrict __src, size_t __n) throw ();


extern char *strfry (char *__string) throw ();


extern void *memfrob (void *__s, size_t __n) throw ();






extern char *basename (__const char *__filename) throw ();
# 364 "/usr/include/string.h" 3
}
# 55 "../../../../src/aleph/ahExceptions.H" 2
# 1 "/usr/local/include/g++-v3/exception" 1 3
# 39 "/usr/local/include/g++-v3/exception" 3
extern "C++" {

namespace std
{






  class exception
  {
  public:
    exception() throw() { }
    virtual ~exception() throw();


    virtual const char* what() const throw();
  };



  class bad_exception : public exception
  {
  public:
    bad_exception() throw() { }
    virtual ~bad_exception() throw();
  };


  typedef void (*terminate_handler) ();

  typedef void (*unexpected_handler) ();


  terminate_handler set_terminate(terminate_handler) throw();


  void terminate() __attribute__ ((__noreturn__));


  unexpected_handler set_unexpected(unexpected_handler) throw();


  void unexpected() __attribute__ ((__noreturn__));
# 95 "/usr/local/include/g++-v3/exception" 3
  bool uncaught_exception() throw();
}

}
# 56 "../../../../src/aleph/ahExceptions.H" 2
# 1 "../../../../src/aleph/ahDefs.H" 1
# 57 "../../../../src/aleph/ahExceptions.H" 2
# 1 "../../../../src/aleph/ahAssert.H" 1
# 58 "../../../../src/aleph/ahExceptions.H" 2

using namespace Aleph;


class AlephExc : public std::exception
{
protected:

  static const size_t TimeLen = 27;

private:

  const char* const exceptionName;
  const char* file;
  int line;
  const char *site;
  pid_t pid;
  time_t timeOfException;
  const char dateOfException[TimeLen];

  void initException();

public:


  enum ExcCode {
    ALEPH_EXCEPTION,
    ALEPH_UNEXPECTED_EXCEPTION,
    ALEPH_NOT_INITIALIZED,
    ALEPH_PANIC,
    ALEPH_NOT_IMPLEMENTED,
    ALEPH_SERVER_CRASH,
    ALEPH_REFUSED_SERVICE,
    ALEPH_LOAD_REACHED,
    ALEPH_UNAVAILABLE_SERVICE,
    ALEPH_DISCONNECTED_SERVICE,
    ALEPH_DEBUG,
    ALEPH_TIMEOUT,
    ALEPH_ADDRESS_UNKNOWN,
    ALEPH_OVERFLOW,
    ALEPH_UNDERFLOW,
    ALEPH_ADDRESS_FAULT,
    ALEPH_ABORT,
    ALEPH_ADDRESS_OVERLAP,
    ALEPH_NO_MEMORY,
    ALEPH_MEMORY_LEAK,
    ALEPH_SIZE_FAULT,
    ALEPH_RANGE_INDEX,
    ALEPH_DUPLICATED,
    ALEPH_NOT_FOUND,
    ALEPH_INVALID,
    ALEPH_OUT_ORDER,
    ALEPH_LOCK,
    ALEPH_NULL_POINTER,
    ALEPH_MATH_ERROR,
    ALEPH_POSIX_ERROR,
    CORBA_EXCEPTION,

    OTHER,



    LAST





  };

private:


  ExcCode excCode;

public:







  AlephExc(const char* const m, ExcCode c)
    : exceptionName(m), excCode(c)
  {
    Aleph::error("../../../../src/aleph/ahExceptions.H", 144, "An not compliant Aleph code has thrown an exception with \"throw\"\n" "Compliant Aleph exceptions must be thrown with :\n\n" "    Throw (Exception Name) (Exception parameters) ... \n\n" "instead of traditional throw \n" "Please use Throw with all Aleph exception\n" "The exception was: %s (file name and line unknowns) \n" , m);
# 153 "../../../../src/aleph/ahExceptions.H"
  }
# 163 "../../../../src/aleph/ahExceptions.H"
  AlephExc(const char* const m, const char* _file, int _line, ExcCode _code) :
    exceptionName(m), file(_file), line(_line), excCode(_code)
  {
    initException();
  }


  virtual ~AlephExc() throw() { }


  virtual const char* what() const throw()
  {
    return exceptionName;
  }


  virtual const ExcCode getExcCode() const { return excCode; }


  time_t getTime() const { return timeOfException; }


  const char* getSite() const { return site; }


  const pid_t getPid() const { return pid; }


  const char * getFileName() const { return file; }


  int getLineNumber() const { return line; }
};







class UnexpectedException : public AlephExc
{
public:

  UnexpectedException() :
    AlephExc("An unexpected exception has been thrown",
             ALEPH_UNEXPECTED_EXCEPTION)
  {

  }

  UnexpectedException(const char* _file, int _line) :
    AlephExc("An unexpected exception has been thrown",
             _file, _line, ALEPH_UNEXPECTED_EXCEPTION)
  {

  }
};






class NotInitialized : public AlephExc
{
public:

  NotInitialized() :
    AlephExc("Object has not been initialized", ALEPH_NOT_INITIALIZED)
  {

  }

  NotInitialized(const char* _file, int _line) :
    AlephExc("Object has not been initialized",
             _file, _line, ALEPH_NOT_INITIALIZED)
  {

  }
};






class Panic : public AlephExc
{
public:


  Panic() : AlephExc("System is in panic mode", ALEPH_PANIC)
  {

  }


  Panic(const char * reason) : AlephExc(reason, ALEPH_PANIC)
  {

  }

  Panic(const char * reason, const char* _file, int _line) :
    AlephExc(reason, _file, _line, ALEPH_PANIC)
  {

  }

  Panic(const char* _file, int _line) :
    AlephExc("System is in panic mode", _file, _line, ALEPH_PANIC)
  {

  }
};






class NotImplemented : public AlephExc
{
  const char *serviceName;
public:


  NotImplemented() :
    AlephExc("Service not implemented", ALEPH_NOT_IMPLEMENTED),
    serviceName(__null)
  {

  }

  NotImplemented(const char* _file, int _line) :
    AlephExc("Service not implemented", _file, _line, ALEPH_NOT_IMPLEMENTED),
    serviceName(__null)
  {

  }


  NotImplemented(const char *name) :
    AlephExc("Service not implemented", ALEPH_NOT_IMPLEMENTED),
    serviceName(name)
  {

  }

  NotImplemented(const char *name, const char* _file, int _line) :
    AlephExc("Service not implemented", _file, _line, ALEPH_NOT_IMPLEMENTED),
      serviceName(name)
  {

  }
};






class ServerCrash : public AlephExc
{
  const char *serverName;
  const char *reason;

public:







  ServerCrash(const char* name = "Unknown server name",
              const char* _reason = "Unknown reason") :
    AlephExc("Server has crashed", ALEPH_SERVER_CRASH),
    serverName(name), reason(_reason)
  {

  }

  ServerCrash(const char* _file, int _line) :
    AlephExc("Server has crashed", _file, _line, ALEPH_SERVER_CRASH),
    serverName("Unknown server name"),
    reason("Unknown reason")
  {

  }

  ServerCrash(const char* name,
              const char* _reason,
              const char* _file, int _line) :
    AlephExc("Server has crashed", _file, _line, ALEPH_SERVER_CRASH),
    serverName(name), reason(_reason)
  {

  }


  const char* getReason() const { return reason; }


  const char* getServerName() const { return serverName; }
};






class RefusedService : public AlephExc
{
  const char* reason;

public:






  RefusedService(const char* _reason = "Unknown reason") :
    AlephExc("Requested service has been refused",
             ALEPH_REFUSED_SERVICE),
    reason(_reason)
  {

  }

  RefusedService(const char* _reason,
                 const char* _file, int _line) :
    AlephExc("Requested service has been refused", _file, _line,
             ALEPH_REFUSED_SERVICE),
    reason(_reason)
  {

  }

  RefusedService(const char* _file, int _line) :
    AlephExc("Requested service has been refused", _file, _line,
             ALEPH_REFUSED_SERVICE),
    reason("Unknown reason")
  {

  }


  const char* getReason() const { return reason; }
};






class LoadReached : public AlephExc
{
  long currentLoad;

public:






  LoadReached(long _currentLoad = UnknownLoad) :
    AlephExc("Maximum load has been reached in server",
             ALEPH_LOAD_REACHED),
    currentLoad(_currentLoad)
  {

  }

  LoadReached(long _currentLoad, const char* _file, int _line) :
    AlephExc("Maximum load has been reached in server", _file,
             _line, ALEPH_LOAD_REACHED),
    currentLoad(_currentLoad)
  {

  }

  LoadReached(const char* _file, int _line) :
    AlephExc("Maximum load has been reached in server", _file,
             _line, ALEPH_LOAD_REACHED),
    currentLoad(UnknownLoad)
  {

  }


  long getLoad() const { return currentLoad; }
};






class UnavailableService : public AlephExc
{

public:

  UnavailableService() :
    AlephExc("Unavailable service", ALEPH_UNAVAILABLE_SERVICE)
  {

  }

  UnavailableService(const char* _file, int _line) :
    AlephExc("Unavailable service", _file, _line, ALEPH_UNAVAILABLE_SERVICE)
  {

  }
};






class DisconnectedService : public AlephExc
{

  const char * reason;

public:

  DisconnectedService(const char * _reason) :
    AlephExc("Disconnected service", ALEPH_DISCONNECTED_SERVICE),
    reason(_reason)
  {

  }

  DisconnectedService(const char * _reason,
                      const char* _file, int _line) :
    AlephExc("Disconnected service", _file, _line, ALEPH_DISCONNECTED_SERVICE),
    reason(_reason)
  {

  }

  const char * get_reason() const { return reason; }
};





class DebugExc : public AlephExc
{
public:

  DebugExc() :
    AlephExc("System is a debugging state that doesn't"
             "allow the requested action", ALEPH_DEBUG)
  {

  }

  DebugExc(const char* _file, int _line) :
    AlephExc("System is a debugging state that doesn't"
             "allow the requested action", _file, _line, ALEPH_DEBUG)
  {

  }
};






class Timeout : public AlephExc
{
private:

  long timeout;

public:






  Timeout(const long _timeout = 0) :
    AlephExc("Timeout expired", ALEPH_TIMEOUT),
    timeout(_timeout)
  {

  }

  Timeout(const long _timeout, const char* _file, int _line) :
    AlephExc("Timeout expired", _file, _line, ALEPH_TIMEOUT),
    timeout(_timeout)
  {

  }


  const long getTimeout() const { return timeout; }
};






class AddrUnknown : public AlephExc
{
private:

  const void* const addr;

public:






  AddrUnknown(const void* const _addr) :
    AlephExc("Address unknown", ALEPH_ADDRESS_UNKNOWN),
    addr(_addr)
  {

  }

  AddrUnknown(const void* const _addr, const char* _file, int _line) :
    AlephExc("Address unknown", _file, _line, ALEPH_ADDRESS_UNKNOWN),
    addr(_addr)
  {

  }


  const void* const getAddr() const { return addr; }
};






class Overflow : public AlephExc
{
  int size;
public:






  Overflow(int sz = UnknownSize) :
    AlephExc("overflow", ALEPH_OVERFLOW), size(sz)
  {

  }

  Overflow(const char* _file, int _line) :
    AlephExc("overflow", _file, _line, ALEPH_OVERFLOW), size(UnknownSize)
  {

  }

  Overflow(int sz, const char* _file, int _line) :
    AlephExc("overflow", _file, _line, ALEPH_OVERFLOW),
    size(sz)
  {

  }


  int getSize() const { return size; }
};






class Underflow : public AlephExc
{
  int size;
public:






  Underflow(int sz = UnknownSize) :
    AlephExc("underflow", ALEPH_UNDERFLOW), size(sz)
  {

  }

  Underflow(const char* _file, int _line) :
    AlephExc("underflow", _file, _line, ALEPH_UNDERFLOW),
    size(UnknownSize)
  {

  }

  Underflow(int sz, const char* _file, int _line) :
    AlephExc("underflow", _file, _line, ALEPH_UNDERFLOW),
    size(sz)
  {

  }


  int getSize() const { return size; }
};






class AddrFault : public AlephExc
{
private:
  const void* const addr;

public:






  AddrFault(const void* const _addr) :
    AlephExc("Address faulting", ALEPH_ADDRESS_FAULT),
    addr(_addr)
  {

  }

  AddrFault(const void* const _addr, const char* _file, int _line) :
    AlephExc("Address faulting", _file, _line, ALEPH_ADDRESS_FAULT),
    addr(_addr)
  {

  }


  const void* const getAddr() const { return addr; }
};






class Abort : public AlephExc
{
public:

  Abort() : AlephExc("Operation aborted", ALEPH_ABORT)
  {

  }

  Abort(const char* _file, int _line) :
    AlephExc("Operation aborted", _file, _line, ALEPH_ABORT)
  {

  }
};







class AddrOverlap : public AlephExc
{
  const void * const startAddr1, * const endAddr1;
  const void * const startAddr2, * const endAddr2;

public:
# 761 "../../../../src/aleph/ahExceptions.H"
  AddrOverlap(const void * const start1,
              const void * const end1,
              const void * const start2,
              const void * const end2) :
    AlephExc("Overlapping addresses ranges", ALEPH_ADDRESS_OVERLAP),
    startAddr1(start1), endAddr1(end1),
    startAddr2(start2), endAddr2(end2)
  {

  }

  AddrOverlap(const void * const start1,
              const void * const end1,
              const void * const start2,
              const void * const end2,
              const char* _file, int _line) :
    AlephExc("Overlapping addresses ranges", _file, _line,
             ALEPH_ADDRESS_OVERLAP),
    startAddr1(start1), endAddr1(end1),
    startAddr2(start2), endAddr2(end2)
  {

  }


  const void * const getStartAddr1() const { return startAddr1; }


  const void * const getEndAddr1() const { return endAddr1; }


  const void * const getStartAddr2() const { return startAddr2; }


  const void * const getEndAddr2() const { return endAddr2; }
};





class Nomem : public AlephExc
{
private:

  size_t requestedSize;

public:

  Nomem(int size) :
    AlephExc("No available memory", ALEPH_NO_MEMORY),
    requestedSize(size)
  {

  }

  Nomem(int size, const char* _file, int _line) :
    AlephExc("No available memory", _file, _line, ALEPH_NO_MEMORY),
    requestedSize(size)
  {

  }

  const size_t getSize() const { return static_cast<size_t>(requestedSize); }
};





class Memory_Leak : public AlephExc
{

public:

  Memory_Leak() : AlephExc("Memory leak detected", ALEPH_MEMORY_LEAK)
  {

  }

  Memory_Leak(const char* _file, int _line) :
    AlephExc("Memory leak detected", _file, _line, ALEPH_NO_MEMORY)
  {

  }
};






class SizeFault : public AlephExc
{
private:

  size_t size;

public:


  SizeFault(size_t _size) : AlephExc("Bad size", ALEPH_SIZE_FAULT),
    size(_size)
  {

  }

  SizeFault(size_t _size, const char* _file, int _line) :
    AlephExc("Bad size", _file, _line, ALEPH_SIZE_FAULT),
    size(_size)
  {

  }

  SizeFault(const char* _file, int _line) :
    AlephExc("Bad size", _file, _line, ALEPH_SIZE_FAULT),
    size(0)
  {

  }


  const size_t getSize() const { return size; }
};






class RangeIndex : public AlephExc
{
private:

  int limit;
  int badIndex;

public:







  RangeIndex(int _limit, int _badIndex) :
    AlephExc("Index out of range", ALEPH_RANGE_INDEX),
    limit(_limit), badIndex(_badIndex)
  {

  }

  RangeIndex(int _limit,
             int _badIndex,
             const char* _file, int _line) :
    AlephExc("Index out of range", _file, _line, ALEPH_RANGE_INDEX),
    limit(_limit), badIndex(_badIndex)
  {

  }


  const int getLimit() const { return limit; }


  const int getBadIndex() const { return badIndex; }

};






class Duplicated : public AlephExc
{
private:

  const char* name;

public:






  Duplicated(const char* _name)
    : AlephExc("Duplicated object or operation", ALEPH_DUPLICATED),
    name(_name)
  {

  }

  Duplicated(const char* _name, const char* _file, int _line) :
    AlephExc("Duplicated object or operation",
             _file, _line, ALEPH_DUPLICATED),
      name(_name)
  {

  }

  Duplicated() :
    AlephExc("Duplicated object or operation", ALEPH_DUPLICATED),
    name("Name unknown")
  {

  }

  Duplicated(const char* _file, int _line) :
    AlephExc("Duplicated object or operation",
             _file, _line, ALEPH_DUPLICATED),
      name("Name unknown")
  {

  }


  const char* getName() const { return name; }

};





class NotFound : public AlephExc
{
public:

  NotFound() :
    AlephExc("Not found", ALEPH_NOT_FOUND)
  { }

  NotFound(const char* _file, int _line) :
    AlephExc("Not found", _file, _line, ALEPH_NOT_FOUND)
  { }
};







class Invalid : public AlephExc
{
public:

  Invalid() :
    AlephExc("Invalid", ALEPH_INVALID)
  { }

  Invalid(const char* _file, int _line) :
    AlephExc("Invalid", _file, _line, ALEPH_INVALID)
  { }
};






class Lock : public AlephExc
{
public:

  Lock() : AlephExc("Lock", ALEPH_LOCK)
  { }

  Lock(const char* _file, int _line) :
    AlephExc("Lock", _file, _line, ALEPH_LOCK)
  { }
};






class OutOrder : public AlephExc
{
public:

  OutOrder() : AlephExc("OutOrder", ALEPH_OUT_ORDER)
  { }

  OutOrder(const char* _file, int _line) :
    AlephExc("OutOrder", _file, _line, ALEPH_OUT_ORDER)
  { }
};


class NullPointer : public AlephExc
{
public:

  NullPointer() :
    AlephExc("Access to a NULL pointer", ALEPH_NULL_POINTER)
  { }

  NullPointer(const char* _file, int _line = __null) :
    AlephExc("Access to a NULL pointer", _file, _line, ALEPH_NULL_POINTER)
  { }
};


class MathError : public AlephExc
{
public:

  enum Error_Code { Divide_By_Zero, Conversion, Convergence };

private:

  Error_Code error_code;

public:

  MathError(Error_Code code) :
    AlephExc("Mathematical error", ALEPH_MATH_ERROR),
    error_code(code)
  { }

  MathError(Error_Code code, const char* _file, int _line) :
    AlephExc("Mathematical error", _file, _line, ALEPH_MATH_ERROR),
    error_code(code)
  { }

  Error_Code getErrorCode() const { return error_code; }
};


class Posix_Error : public AlephExc
{
  int error_number;

public:

  Posix_Error(int error) :
    AlephExc("Posix error reported for internal libraries", ALEPH_POSIX_ERROR),
    error_number(error)
  {

  }

  Posix_Error(int error, const char* _file, int _line) :
    AlephExc("Posix error reported for internal libraries",
             _file, _line, ALEPH_POSIX_ERROR),
    error_number(error)
  {
                                               ;
  }

  int get_error_number() const { return error_number; }
};


class Corba_Exception : public AlephExc
{
public:

  Corba_Exception() : AlephExc("Corba exception", CORBA_EXCEPTION)
  { }

  Corba_Exception(const char* _file, int _line) :
    AlephExc("Corba exception", _file, _line, CORBA_EXCEPTION)
  { }
};


namespace Aleph {



  extern const char *lastExceptionName;



  extern const char *lastFile;



  extern int lastLine;
}
# 1161 "../../../../src/aleph/ahExceptions.H"
    template <class T>
class Thrower
{
private:

  friend Thrower throwException<T>(const char *, int, const char*);

  bool threw;
  const char* file;
  const char* excName;
  int line;

  Thrower(const char* _file, int _line, const char *_excName) :
    threw(false), file(_file), excName(_excName),
    line(_line)
  {
                                                             ;
    Aleph::lastExceptionName = const_cast<char*>(excName);
    Aleph::lastFile = const_cast<char*>(file);
    Aleph::lastLine = line;
  }

  Thrower& operator = (const Thrower&);
  Thrower(const Thrower&);

public:
# 1210 "../../../../src/aleph/ahExceptions.H"
  ~Thrower()
  {
    if (!threw)
      Aleph::error("../../../../src/aleph/ahExceptions.H", 1213, "Bad syntax in thrown exception %s at %s:%d\n" "This error has been detected in %s:%d (look at it!)\n" "Possibly you have put Throw (T); instead of Throw (T) ();\n" , excName, file, line, "../../../../src/aleph/ahExceptions.H", 1213);



  }

  void operator() ()
  {
    threw = true;
    throw T(file, line);
  }

  template <class T1>
  void operator () (const T1& t1)
  {
    threw = true;
    throw T(t1, file, line);

  }
# 1241 "../../../../src/aleph/ahExceptions.H"
  template <class T1, class T2>
  void operator () (const T1& t1, const T2& t2)
  { threw = true; throw T(t1, t2, file, line); }

  template <class T1, class T2, class T3>
  void operator () (const T1& t1, const T2& t2, const T3& t3)
  { threw = true; throw T(t1, t2, t3, file, line); }

  template <class T1, class T2, class T3, class T4>
  void operator () (const T1& t1, const T2& t2, const T3& t3,
                    const T4& t4)
  { threw = true; throw T(t1, t2, t3, t4, file, line); }

  template <class T1, class T2, class T3, class T4, class T5>
  void operator () (const T1& t1, const T2& t2, const T3& t3,
                    const T4& t4, const T5& t5)
  { threw = true; throw T(t1, t2, t3, t4, t5, file, line); }

  template <class T1, class T2, class T3, class T4, class T5,
    class T6>
  void operator () (const T1& t1, const T2& t2, const T3& t3,
                    const T4& t4, const T5& t5, const T6& t6)
  { threw = true; throw T(t1, t2, t3, t4, t5, t6, file, line); }

  template <class T1, class T2, class T3, class T4, class T5,
    class T6, class T7>
  void operator () (const T1& t1, const T2& t2, const T3& t3,
                    const T4& t4, const T5& t5, const T6& t6,
                    const T7& t7)
  { threw = true; throw T(t1, t2, t3, t4, t5, t6, t7, file, line); }

  template <class T1, class T2, class T3, class T4, class T5,
    class T6, class T7, class T8>
  void operator () (const T1& t1, const T2& t2, const T3& t3,
                    const T4& t4, const T5& t5, const T6& t6,
                    const T7& t7, const T8& t8)
  {
    threw = true;
    throw T(t1, t2, t3, t4, t5, t6, t7, t8, file, line);
  }

  template <class T1, class T2, class T3, class T4, class T5,
    class T6, class T7, class T8, class T9>
  void operator () (const T1& t1, const T2& t2, const T3& t3,
                    const T4& t4, const T5& t5, const T6& t6,
                    const T7& t7, const T8& t8, const T9& t9)
  {
    threw = true;
    throw T(t1, t2, t3, t4, t5, t6, t7, t8, t9, file, line);
  }

  template <class T0, class T1, class T2, class T3, class T4,
    class T5, class T6, class T7, class T8, class T9>
  void operator () (const T0& t0, const T1& t1, const T2& t2,
                    const T3& t3, const T4& t4, const T5& t5,
                    const T6& t6, const T7& t7, const T8& t8,
                    const T9& t9)
  {
    threw = true;
    throw T(t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, file, line);
  }
};
# 1313 "../../../../src/aleph/ahExceptions.H"
    template <class T> inline
Thrower<T> throwException(const char *file, int line, const char *excName)
{
  return Thrower<T>(file, line, excName);
}

    template <class T> inline
Thrower<T> throwDistException(const char *file, int line, const char *excName)
{
  return Thrower<T>(file, line, excName);
}
# 1332 "../../../../src/aleph/ahExceptions.H"
typedef void (*PFV)();
# 1344 "../../../../src/aleph/ahExceptions.H"
class AlephUnexpectedHandler
{
  PFV old;

  static unsigned instanceCounter;

public:

  AlephUnexpectedHandler(PFV fct)
  {
    if (instanceCounter >= 1)
      Aleph::error("../../../../src/aleph/ahExceptions.H", 1355, "Double instantiation of AlephUnexpectedHandler");
    instanceCounter++;
    old = std::set_unexpected(fct);
  }

  ~AlephUnexpectedHandler()
  {
    std::set_unexpected(old);
  }
};
# 1375 "../../../../src/aleph/ahExceptions.H"
class AlephUncaughtHandler
{
  PFV old;

  static unsigned instanceCounter;

public:

  AlephUncaughtHandler(PFV fct)
  {
    if (instanceCounter >= 1)
      Aleph::error("../../../../src/aleph/ahExceptions.H", 1386, "Double instantiation of AlephUncaughtHandler");
    instanceCounter++;
    old = std::set_terminate(fct);
  }

  ~AlephUncaughtHandler()
  {
    std::set_terminate(old);
  }
};

namespace Aleph {

  extern void alephUnexpectedHandler();

  extern void alephUncaughtHandler();

  extern AlephUnexpectedHandler unexpectedHandler;

  extern AlephUncaughtHandler uncaughtHandler;
};
# 53 "../../../../src/aleph/aleph.H" 2
# 1 "../../../../src/aleph/ahNew.H" 1
# 54 "../../../../src/aleph/ahNew.H"
# 1 "../../../../src/aleph/ahAlloc.H" 1
# 50 "../../../../src/aleph/ahAlloc.H"
# 1 "/usr/include/pthread.h" 1 3
# 18 "/usr/include/pthread.h" 3
# 1 "/usr/include/features.h" 1 3
# 19 "/usr/include/pthread.h" 2 3

# 1 "/usr/include/sched.h" 1 3
# 23 "/usr/include/sched.h" 3
# 1 "/usr/include/features.h" 1 3
# 24 "/usr/include/sched.h" 2 3


# 1 "/usr/include/bits/types.h" 1 3
# 27 "/usr/include/sched.h" 2 3


# 1 "/usr/include/time.h" 1 3
# 30 "/usr/include/sched.h" 2 3


# 1 "/usr/include/bits/sched.h" 1 3
# 47 "/usr/include/bits/sched.h" 3
struct sched_param
  {
    int __sched_priority;
  };

extern "C" {



extern int clone (int (*__fn) (void *__arg), void *__child_stack,
                  int __flags, void *__arg) throw ();


}
# 33 "/usr/include/sched.h" 2 3




extern "C" {


extern int sched_setparam (__pid_t __pid, __const struct sched_param *__param)
     throw ();


extern int sched_getparam (__pid_t __pid, struct sched_param *__param) throw ();


extern int sched_setscheduler (__pid_t __pid, int __policy,
                               __const struct sched_param *__param) throw ();


extern int sched_getscheduler (__pid_t __pid) throw ();


extern int sched_yield (void) throw ();


extern int sched_get_priority_max (int __algorithm) throw ();


extern int sched_get_priority_min (int __algorithm) throw ();


extern int sched_rr_get_interval (__pid_t __pid, struct timespec *__t) throw ();

}
# 21 "/usr/include/pthread.h" 2 3
# 1 "/usr/include/time.h" 1 3
# 22 "/usr/include/pthread.h" 2 3


# 1 "/usr/include/signal.h" 1 3
# 29 "/usr/include/signal.h" 3
# 1 "/usr/include/features.h" 1 3
# 30 "/usr/include/signal.h" 2 3

extern "C" {

# 1 "/usr/include/bits/sigset.h" 1 3
# 34 "/usr/include/signal.h" 2 3
# 371 "/usr/include/signal.h" 3
}
# 25 "/usr/include/pthread.h" 2 3
# 1 "/usr/include/bits/pthreadtypes.h" 1 3
# 26 "/usr/include/pthread.h" 2 3
# 1 "/usr/include/bits/initspin.h" 1 3
# 27 "/usr/include/pthread.h" 2 3


extern "C" {
# 59 "/usr/include/pthread.h" 3
enum
{
  PTHREAD_CREATE_JOINABLE,

  PTHREAD_CREATE_DETACHED

};

enum
{
  PTHREAD_INHERIT_SCHED,

  PTHREAD_EXPLICIT_SCHED

};

enum
{
  PTHREAD_SCOPE_SYSTEM,

  PTHREAD_SCOPE_PROCESS

};

enum
{
  PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_ADAPTIVE_NP

  ,
  PTHREAD_MUTEX_NORMAL = PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE = PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK = PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_DEFAULT = PTHREAD_MUTEX_NORMAL



  , PTHREAD_MUTEX_FAST_NP = PTHREAD_MUTEX_ADAPTIVE_NP

};

enum
{
  PTHREAD_PROCESS_PRIVATE,

  PTHREAD_PROCESS_SHARED

};


enum
{
  PTHREAD_RWLOCK_PREFER_READER_NP,
  PTHREAD_RWLOCK_PREFER_WRITER_NP,
  PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP,
  PTHREAD_RWLOCK_DEFAULT_NP = PTHREAD_RWLOCK_PREFER_WRITER_NP
};
# 131 "/usr/include/pthread.h" 3
struct _pthread_cleanup_buffer
{
  void (*__routine) (void *);
  void *__arg;
  int __canceltype;
  struct _pthread_cleanup_buffer *__prev;
};



enum
{
  PTHREAD_CANCEL_ENABLE,

  PTHREAD_CANCEL_DISABLE

};
enum
{
  PTHREAD_CANCEL_DEFERRED,

  PTHREAD_CANCEL_ASYNCHRONOUS

};
# 163 "/usr/include/pthread.h" 3
extern int pthread_create (pthread_t *__restrict __thread,
                           __const pthread_attr_t *__restrict __attr,
                           void *(*__start_routine) (void *),
                           void *__restrict __arg) throw ();


extern pthread_t pthread_self (void) throw ();


extern int pthread_equal (pthread_t __thread1, pthread_t __thread2) throw ();


extern void pthread_exit (void *__retval)
     throw () __attribute__ ((__noreturn__));




extern int pthread_join (pthread_t __th, void **__thread_return) throw ();





extern int pthread_detach (pthread_t __th) throw ();







extern int pthread_attr_init (pthread_attr_t *__attr) throw ();


extern int pthread_attr_destroy (pthread_attr_t *__attr) throw ();


extern int pthread_attr_setdetachstate (pthread_attr_t *__attr,
                                        int __detachstate) throw ();


extern int pthread_attr_getdetachstate (__const pthread_attr_t *__attr,
                                        int *__detachstate) throw ();


extern int pthread_attr_setschedparam (pthread_attr_t *__restrict __attr,
                                       __const struct sched_param *__restrict
                                       __param) throw ();


extern int pthread_attr_getschedparam (__const pthread_attr_t *__restrict
                                       __attr,
                                       struct sched_param *__restrict __param)
     throw ();


extern int pthread_attr_setschedpolicy (pthread_attr_t *__attr, int __policy)
     throw ();


extern int pthread_attr_getschedpolicy (__const pthread_attr_t *__restrict
                                        __attr, int *__restrict __policy)
     throw ();


extern int pthread_attr_setinheritsched (pthread_attr_t *__attr,
                                         int __inherit) throw ();


extern int pthread_attr_getinheritsched (__const pthread_attr_t *__restrict
                                         __attr, int *__restrict __inherit)
     throw ();


extern int pthread_attr_setscope (pthread_attr_t *__attr, int __scope)
     throw ();


extern int pthread_attr_getscope (__const pthread_attr_t *__restrict __attr,
                                  int *__restrict __scope) throw ();



extern int pthread_attr_setguardsize (pthread_attr_t *__attr,
                                      size_t __guardsize) throw ();


extern int pthread_attr_getguardsize (__const pthread_attr_t *__restrict
                                      __attr, size_t *__restrict __guardsize)
     throw ();






extern int pthread_attr_setstackaddr (pthread_attr_t *__attr,
                                      void *__stackaddr) throw ();


extern int pthread_attr_getstackaddr (__const pthread_attr_t *__restrict
                                      __attr, void **__restrict __stackaddr)
     throw ();





extern int pthread_attr_setstack (pthread_attr_t *__attr, void *__stackaddr,
                                  size_t __stacksize) throw ();


extern int pthread_attr_getstack (__const pthread_attr_t *__restrict __attr,
                                  void **__restrict __stackaddr,
                                  size_t *__restrict __stacksize) throw ();





extern int pthread_attr_setstacksize (pthread_attr_t *__attr,
                                      size_t __stacksize) throw ();


extern int pthread_attr_getstacksize (__const pthread_attr_t *__restrict
                                      __attr, size_t *__restrict __stacksize)
     throw ();



extern int pthread_getattr_np (pthread_t __th, pthread_attr_t *__attr) throw ();






extern int pthread_setschedparam (pthread_t __target_thread, int __policy,
                                  __const struct sched_param *__param)
     throw ();


extern int pthread_getschedparam (pthread_t __target_thread,
                                  int *__restrict __policy,
                                  struct sched_param *__restrict __param)
     throw ();



extern int pthread_getconcurrency (void) throw ();


extern int pthread_setconcurrency (int __level) throw ();







extern int pthread_yield (void) throw ();






extern int pthread_mutex_init (pthread_mutex_t *__restrict __mutex,
                               __const pthread_mutexattr_t *__restrict
                               __mutex_attr) throw ();


extern int pthread_mutex_destroy (pthread_mutex_t *__mutex) throw ();


extern int pthread_mutex_trylock (pthread_mutex_t *__mutex) throw ();


extern int pthread_mutex_lock (pthread_mutex_t *__mutex) throw ();



extern int pthread_mutex_timedlock (pthread_mutex_t *__restrict __mutex,
                                    __const struct timespec *__restrict
                                    __abstime) throw ();



extern int pthread_mutex_unlock (pthread_mutex_t *__mutex) throw ();






extern int pthread_mutexattr_init (pthread_mutexattr_t *__attr) throw ();


extern int pthread_mutexattr_destroy (pthread_mutexattr_t *__attr) throw ();


extern int pthread_mutexattr_getpshared (__const pthread_mutexattr_t *
                                         __restrict __attr,
                                         int *__restrict __pshared) throw ();


extern int pthread_mutexattr_setpshared (pthread_mutexattr_t *__attr,
                                         int __pshared) throw ();





extern int pthread_mutexattr_settype (pthread_mutexattr_t *__attr, int __kind)
     throw ();


extern int pthread_mutexattr_gettype (__const pthread_mutexattr_t *__restrict
                                      __attr, int *__restrict __kind) throw ();







extern int pthread_cond_init (pthread_cond_t *__restrict __cond,
                              __const pthread_condattr_t *__restrict
                              __cond_attr) throw ();


extern int pthread_cond_destroy (pthread_cond_t *__cond) throw ();


extern int pthread_cond_signal (pthread_cond_t *__cond) throw ();


extern int pthread_cond_broadcast (pthread_cond_t *__cond) throw ();



extern int pthread_cond_wait (pthread_cond_t *__restrict __cond,
                              pthread_mutex_t *__restrict __mutex) throw ();





extern int pthread_cond_timedwait (pthread_cond_t *__restrict __cond,
                                   pthread_mutex_t *__restrict __mutex,
                                   __const struct timespec *__restrict
                                   __abstime) throw ();




extern int pthread_condattr_init (pthread_condattr_t *__attr) throw ();


extern int pthread_condattr_destroy (pthread_condattr_t *__attr) throw ();


extern int pthread_condattr_getpshared (__const pthread_condattr_t *
                                        __restrict __attr,
                                        int *__restrict __pshared) throw ();


extern int pthread_condattr_setpshared (pthread_condattr_t *__attr,
                                        int __pshared) throw ();







extern int pthread_rwlock_init (pthread_rwlock_t *__restrict __rwlock,
                                __const pthread_rwlockattr_t *__restrict
                                __attr) throw ();


extern int pthread_rwlock_destroy (pthread_rwlock_t *__rwlock) throw ();


extern int pthread_rwlock_rdlock (pthread_rwlock_t *__rwlock) throw ();


extern int pthread_rwlock_tryrdlock (pthread_rwlock_t *__rwlock) throw ();



extern int pthread_rwlock_timedrdlock (pthread_rwlock_t *__restrict __rwlock,
                                       __const struct timespec *__restrict
                                       __abstime) throw ();



extern int pthread_rwlock_wrlock (pthread_rwlock_t *__rwlock) throw ();


extern int pthread_rwlock_trywrlock (pthread_rwlock_t *__rwlock) throw ();



extern int pthread_rwlock_timedwrlock (pthread_rwlock_t *__restrict __rwlock,
                                       __const struct timespec *__restrict
                                       __abstime) throw ();



extern int pthread_rwlock_unlock (pthread_rwlock_t *__rwlock) throw ();





extern int pthread_rwlockattr_init (pthread_rwlockattr_t *__attr) throw ();


extern int pthread_rwlockattr_destroy (pthread_rwlockattr_t *__attr) throw ();


extern int pthread_rwlockattr_getpshared (__const pthread_rwlockattr_t *
                                          __restrict __attr,
                                          int *__restrict __pshared) throw ();


extern int pthread_rwlockattr_setpshared (pthread_rwlockattr_t *__attr,
                                          int __pshared) throw ();


extern int pthread_rwlockattr_getkind_np (__const pthread_rwlockattr_t *__attr,
                                          int *__pref) throw ();


extern int pthread_rwlockattr_setkind_np (pthread_rwlockattr_t *__attr,
                                          int __pref) throw ();
# 509 "/usr/include/pthread.h" 3
extern int pthread_spin_init (pthread_spinlock_t *__lock, int __pshared)
     throw ();


extern int pthread_spin_destroy (pthread_spinlock_t *__lock) throw ();


extern int pthread_spin_lock (pthread_spinlock_t *__lock) throw ();


extern int pthread_spin_trylock (pthread_spinlock_t *__lock) throw ();


extern int pthread_spin_unlock (pthread_spinlock_t *__lock) throw ();




extern int pthread_barrier_init (pthread_barrier_t *__restrict __barrier,
                                 __const pthread_barrierattr_t *__restrict
                                 __attr, unsigned int __count) throw ();

extern int pthread_barrier_destroy (pthread_barrier_t *__barrier) throw ();

extern int pthread_barrierattr_init (pthread_barrierattr_t *__attr) throw ();

extern int pthread_barrierattr_destroy (pthread_barrierattr_t *__attr) throw ();

extern int pthread_barrierattr_getpshared (__const pthread_barrierattr_t *
                                           __restrict __attr,
                                           int *__restrict __pshared) throw ();

extern int pthread_barrierattr_setpshared (pthread_barrierattr_t *__attr,
                                           int __pshared) throw ();

extern int pthread_barrier_wait (pthread_barrier_t *__barrier) throw ();
# 556 "/usr/include/pthread.h" 3
extern int pthread_key_create (pthread_key_t *__key,
                               void (*__destr_function) (void *)) throw ();


extern int pthread_key_delete (pthread_key_t __key) throw ();


extern int pthread_setspecific (pthread_key_t __key,
                                __const void *__pointer) throw ();


extern void *pthread_getspecific (pthread_key_t __key) throw ();
# 576 "/usr/include/pthread.h" 3
extern int pthread_once (pthread_once_t *__once_control,
                         void (*__init_routine) (void)) throw ();






extern int pthread_setcancelstate (int __state, int *__oldstate) throw ();



extern int pthread_setcanceltype (int __type, int *__oldtype) throw ();


extern int pthread_cancel (pthread_t __thread) throw ();




extern void pthread_testcancel (void) throw ();
# 610 "/usr/include/pthread.h" 3
extern void _pthread_cleanup_push (struct _pthread_cleanup_buffer *__buffer,
                                   void (*__routine) (void *),
                                   void *__arg) throw ();







extern void _pthread_cleanup_pop (struct _pthread_cleanup_buffer *__buffer,
                                  int __execute) throw ();
# 631 "/usr/include/pthread.h" 3
extern void _pthread_cleanup_push_defer (struct _pthread_cleanup_buffer *__buffer,
                                         void (*__routine) (void *),
                                         void *__arg) throw ();
# 642 "/usr/include/pthread.h" 3
extern void _pthread_cleanup_pop_restore (struct _pthread_cleanup_buffer *__buffer,
                                          int __execute) throw ();





extern int pthread_getcpuclockid (pthread_t __thread_id,
                                  clockid_t *__clock_id) throw ();




# 1 "/usr/include/bits/sigthread.h" 1 3
# 31 "/usr/include/bits/sigthread.h" 3
extern int pthread_sigmask (int __how,
                            __const __sigset_t *__restrict __newmask,
                            __sigset_t *__restrict __oldmask)throw ();


extern int pthread_kill (pthread_t __thread, int __signo) throw ();
# 656 "/usr/include/pthread.h" 2 3
# 671 "/usr/include/pthread.h" 3
extern int pthread_atfork (void (*__prepare) (void),
                           void (*__parent) (void),
                           void (*__child) (void)) throw ();




extern void pthread_kill_other_threads_np (void) throw ();

}
# 51 "../../../../src/aleph/ahAlloc.H" 2
# 1 "../../../../src/aleph/genAlloc.H" 1
# 54 "../../../../src/aleph/genAlloc.H"
# 1 "/usr/local/include/g++-v3/new" 1 3
# 40 "/usr/local/include/g++-v3/new" 3
# 1 "/usr/local/include/g++-v3/cstddef" 1 3
# 31 "/usr/local/include/g++-v3/cstddef" 3
# 1 "/usr/local/include/g++-v3/bits/std_cstddef.h" 1 3
# 38 "/usr/local/include/g++-v3/bits/std_cstddef.h" 3
# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stddef.h" 1 3
# 147 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stddef.h" 3
typedef int ptrdiff_t;
# 39 "/usr/local/include/g++-v3/bits/std_cstddef.h" 2 3

namespace std
{
  using ::ptrdiff_t;
  using ::size_t;
}
# 32 "/usr/local/include/g++-v3/cstddef" 2 3
# 41 "/usr/local/include/g++-v3/new" 2 3
# 1 "/usr/local/include/g++-v3/exception" 1 3
# 42 "/usr/local/include/g++-v3/new" 2 3

extern "C++" {

namespace std
{


  class bad_alloc : public exception
  {
  public:
    bad_alloc() throw() { }
    virtual ~bad_alloc() throw();
  };

  struct nothrow_t { };
  extern const nothrow_t nothrow;


  typedef void (*new_handler)();

  new_handler set_new_handler(new_handler);
}
# 76 "/usr/local/include/g++-v3/new" 3
void *operator new(std::size_t) throw (std::bad_alloc);
void *operator new[](std::size_t) throw (std::bad_alloc);
void operator delete(void *) throw();
void operator delete[](void *) throw();
void *operator new(std::size_t, const std::nothrow_t&) throw();
void *operator new[](std::size_t, const std::nothrow_t&) throw();
void operator delete(void *, const std::nothrow_t&) throw();
void operator delete[](void *, const std::nothrow_t&) throw();


inline void *operator new(std::size_t, void *place) throw() { return place; }
inline void *operator new[](std::size_t, void *place) throw() { return place; }

}
# 55 "../../../../src/aleph/genAlloc.H" 2
# 1 "../../../../src/aleph/ahExceptions.H" 1
# 56 "../../../../src/aleph/genAlloc.H" 2
# 1 "../../../../src/aleph/ahAssert.H" 1
# 57 "../../../../src/aleph/genAlloc.H" 2

typedef void* Pointer;
typedef const void* Const_Pointer;
# 98 "../../../../src/aleph/genAlloc.H"
class GenAlloc
{
private:






  union Align
  {
    int i;
    long l;
    long *lp;
    void *p;
    void (*fp)(void);
    float f;
  };

  static const size_t alignTwoPower = sizeof(Align) == 4 ? 2 : 3;

public:


  static const size_t minAlign = sizeof(Align);

private:

  static const size_t alignMask = minAlign - 1;

public:




  static size_t roundAlign(size_t n)
  {


                                                               ;


    return ((n + alignMask)>>alignTwoPower)<<alignTwoPower;
  }

  static bool addressIsAligned(void *addr)
  {
    size_t address = reinterpret_cast<size_t>(addr);
                                                          ;

    return (address & alignMask) == 0;
  }

protected:


  const bool isArena;


  GenAlloc(bool _isArena = false) : isArena(_isArena) { }

public:


  virtual ~GenAlloc() { }
# 174 "../../../../src/aleph/genAlloc.H"
  virtual Pointer alloc(size_t) throw(std::exception, AlephExc, Nomem, SizeFault) = 0;
# 187 "../../../../src/aleph/genAlloc.H"
  virtual void dealloc(Pointer) throw(std::exception, AlephExc, AddrUnknown) = 0;
# 204 "../../../../src/aleph/genAlloc.H"
  virtual void dealloc(Pointer, size_t)
    throw(std::exception, AlephExc, AddrUnknown, SizeFault) = 0;
# 231 "../../../../src/aleph/genAlloc.H"
  virtual Pointer ralloc(Pointer, size_t)
    throw(std::exception, AlephExc, Nomem, AddrUnknown, SizeFault) = 0;
# 246 "../../../../src/aleph/genAlloc.H"
  virtual Pointer alloc(size_t,
                        const char* ,
                        int )
    throw(std::exception, AlephExc, Nomem, SizeFault) = 0;
# 264 "../../../../src/aleph/genAlloc.H"
  virtual void dealloc(Pointer,
                       const char* ,
                       int )
    throw(std::exception, AlephExc, AddrUnknown) = 0;
# 286 "../../../../src/aleph/genAlloc.H"
  virtual void dealloc(Pointer,
                       size_t,
                       const char* ,
                       int )
    throw(std::exception, AlephExc, AddrUnknown, SizeFault) = 0;
# 318 "../../../../src/aleph/genAlloc.H"
  virtual Pointer ralloc(Pointer,
                         size_t,
                         const char* ,
                         int )
    throw(std::exception, AlephExc, Nomem, AddrUnknown, SizeFault) = 0;


  const bool IsArena() const { return isArena; }
};
# 346 "../../../../src/aleph/genAlloc.H"
template<class T> struct SimpleType
{
  enum { value = 0 };
};

template<class T> struct SimpleType<T*>
{
  enum { value = 1 };
};

template<class T> struct SimpleType<const T>
{
  enum { value = SimpleType<T>::value };
};

template<class T, size_t n> struct SimpleType<T[n]>
{
  enum { value = SimpleType<T>::value };
};
# 375 "../../../../src/aleph/genAlloc.H"
template<> struct SimpleType<bool> { union { bool t; } catcherr; enum { value = 1 }; };
template<> struct SimpleType<char> { union { char t; } catcherr; enum { value = 1 }; };
template<> struct SimpleType<unsigned char> { union { unsigned char t; } catcherr; enum { value = 1 }; };
template<> struct SimpleType<short> { union { short t; } catcherr; enum { value = 1 }; };
template<> struct SimpleType<unsigned short> { union { unsigned short t; } catcherr; enum { value = 1 }; };
template<> struct SimpleType<int> { union { int t; } catcherr; enum { value = 1 }; };
template<> struct SimpleType<unsigned int> { union { unsigned int t; } catcherr; enum { value = 1 }; };
template<> struct SimpleType<long> { union { long t; } catcherr; enum { value = 1 }; };
template<> struct SimpleType<unsigned long> { union { unsigned long t; } catcherr; enum { value = 1 }; };
template<> struct SimpleType<long long> { union { long long t; } catcherr; enum { value = 1 }; };
template<> struct SimpleType<unsigned long long> { union { unsigned long long t; } catcherr; enum { value = 1 }; };
template<> struct SimpleType<float> { union { float t; } catcherr; enum { value = 1 }; };
template<> struct SimpleType<double> { union { double t; } catcherr; enum { value = 1 }; };
template<> struct SimpleType<long double> { union { long double t; } catcherr; enum { value = 1 }; };
# 407 "../../../../src/aleph/genAlloc.H"
template <class T> class Constructor;
# 427 "../../../../src/aleph/genAlloc.H"
template <class T> inline Constructor<T> construct(GenAlloc&);
# 447 "../../../../src/aleph/genAlloc.H"
template <class T> inline Constructor<T> construct(GenAlloc&, size_t);
# 463 "../../../../src/aleph/genAlloc.H"
template <class T> inline void destruct(GenAlloc&, T*);
# 479 "../../../../src/aleph/genAlloc.H"
template <class T> inline void destructArray(GenAlloc&, T*);
# 496 "../../../../src/aleph/genAlloc.H"
template <class T> inline
Constructor<T> construct(GenAlloc&, const char*, int);
# 519 "../../../../src/aleph/genAlloc.H"
template <class T> inline Constructor<T> construct(GenAlloc&,
                                                   const char *, int, size_t);
# 537 "../../../../src/aleph/genAlloc.H"
template <class T> inline void destruct(GenAlloc&, T*, const char*, int);
# 555 "../../../../src/aleph/genAlloc.H"
template <class T> inline void destructArray(GenAlloc&, T*, const char*, int);
# 585 "../../../../src/aleph/genAlloc.H"
    template <class T>
class Constructor
{
private:

  friend Constructor<T> construct<T>(GenAlloc&);
  friend Constructor<T> construct<T>(GenAlloc&, size_t);
  friend void destruct<>(GenAlloc&, T*);
  friend void destructArray<>(GenAlloc&, T*);
  friend Constructor<T> construct<T>(GenAlloc&, const char *, int);
  friend Constructor<T> construct<T>(GenAlloc&, const char *, int, size_t);
  friend void destruct<>(GenAlloc&, T*, const char *, int);
  friend void destructArray<>(GenAlloc&, T*, const char *, int);


  GenAlloc& allocator;


  size_t size;

protected:
# 619 "../../../../src/aleph/genAlloc.H"
  Constructor();



  Constructor& operator = (const Constructor&);


  Constructor(GenAlloc& _allocator, size_t sz = sizeof(T))
    : allocator(_allocator), size(sz)
  { }
# 643 "../../../../src/aleph/genAlloc.H"
public:

  Constructor(const Constructor& ctor) :
    allocator (ctor.allocator), size(ctor.size)



  { }




  operator T* () { void *p = (allocator.alloc(size)); try { return new (p) T; } catch (...) { (allocator.dealloc(p)); throw; }; }
# 671 "../../../../src/aleph/genAlloc.H"
  T* operator() () { void *p = (allocator.alloc(size)); try { return new (p) T (); } catch (...) { (allocator.dealloc(p)); throw; }; }


      template <class T1>
  T* operator () (const T1& t1) { void *p = (allocator.alloc(size)); try { return new (p) T (t1); } catch (...) { (allocator.dealloc(p)); throw; }; }


      template <class T1>
  T* operator () (T1& t1) { void *p = (allocator.alloc(size)); try { return new (p) T (t1); } catch (...) { (allocator.dealloc(p)); throw; }; }


      template <class T1, class T2>
  T* operator () (T1& t1, T2& t2) { void *p = (allocator.alloc(size)); try { return new (p) T (t1, t2); } catch (...) { (allocator.dealloc(p)); throw; }; }


      template <class T1, class T2>
  T* operator () (const T1& t1, const T2& t2) { void *p = (allocator.alloc(size)); try { return new (p) T (t1, t2); } catch (...) { (allocator.dealloc(p)); throw; }; }


      template <class T1, class T2>
  T* operator () (T1& t1, const T2& t2) { void *p = (allocator.alloc(size)); try { return new (p) T (t1, t2); } catch (...) { (allocator.dealloc(p)); throw; }; }


      template <class T1, class T2>
  T* operator () (const T1& t1, T2& t2) { void *p = (allocator.alloc(size)); try { return new (p) T (t1, t2); } catch (...) { (allocator.dealloc(p)); throw; }; }


      template <class T1, class T2, class T3>
  T* operator () (const T1& t1, const T2& t2, const T3& t3)
  { void *p = (allocator.alloc(size)); try { return new (p) T (t1, t2, t3); } catch (...) { (allocator.dealloc(p)); throw; }; }


      template <class T1, class T2, class T3>
  T* operator () (const T1& t1, const T2& t2, T3& t3)
  { void *p = (allocator.alloc(size)); try { return new (p) T (t1, t2, t3); } catch (...) { (allocator.dealloc(p)); throw; }; }


      template <class T1, class T2, class T3>
  T* operator () (T1& t1, T2& t2, T3& t3)
  { void *p = (allocator.alloc(size)); try { return new (p) T (t1, t2, t3); } catch (...) { (allocator.dealloc(p)); throw; }; }


      template <class T1, class T2, class T3, class T4>
  T* operator () (const T1& t1, const T2& t2, const T3& t3,
                  const T4& t4)
  { void *p = (allocator.alloc(size)); try { return new (p) T (t1, t2, t3, t4); } catch (...) { (allocator.dealloc(p)); throw; }; }


      template <class T1, class T2, class T3, class T4>
  T* operator () (T1& t1, T2& t2, T3& t3, T4& t4)
  { void *p = (allocator.alloc(size)); try { return new (p) T (t1, t2, t3, t4); } catch (...) { (allocator.dealloc(p)); throw; }; }


      template <class T1, class T2, class T3, class T4, class T5>
  T* operator () (const T1& t1, const T2& t2, const T3& t3,
                  const T4& t4, const T5& t5)
  { void *p = (allocator.alloc(size)); try { return new (p) T (t1, t2, t3, t4, t5); } catch (...) { (allocator.dealloc(p)); throw; }; }


      template <class T1, class T2, class T3, class T4, class T5>
  T* operator () (T1& t1, T2& t2, T3& t3, T4& t4, T5& t5)
  { void *p = (allocator.alloc(size)); try { return new (p) T (t1, t2, t3, t4, t5); } catch (...) { (allocator.dealloc(p)); throw; }; }


      template <class T1, class T2, class T3, class T4, class T5>
  T* operator () (T1 * t1, T2 * t2, T3 * t3, T4 * t4, T5 * t5)
  { void *p = (allocator.alloc(size)); try { return new (p) T (t1, t2, t3, t4, t5); } catch (...) { (allocator.dealloc(p)); throw; }; }


      template <class T1, class T2, class T3, class T4, class T5>
  T* operator () (T1 * t1, T2 * t2, T3 * t3, T4 * t4, T5 t5)
  { void *p = (allocator.alloc(size)); try { return new (p) T (t1, t2, t3, t4, t5); } catch (...) { (allocator.dealloc(p)); throw; }; }


      template <class T1, class T2, class T3, class T4, class T5, class T6>
  T* operator () (const T1& t1, const T2& t2, const T3& t3,
                  const T4& t4, const T5& t5, const T6& t6)
  { void *p = (allocator.alloc(size)); try { return new (p) T (t1, t2, t3, t4, t5, t6); } catch (...) { (allocator.dealloc(p)); throw; }; }


      template <class T1, class T2, class T3, class T4, class T5, class T6>
  T* operator () (T1& t1, T2& t2, T3& t3, T4& t4, T5& t5, T6& t6)
  { void *p = (allocator.alloc(size)); try { return new (p) T (t1, t2, t3, t4, t5, t6); } catch (...) { (allocator.dealloc(p)); throw; }; }


      template <class T1, class T2, class T3, class T4, class T5,
                class T6, class T7>
  T* operator () (const T1& t1, const T2& t2, const T3& t3,
                  const T4& t4, const T5& t5, const T6& t6,
                  const T7& t7)
  { void *p = (allocator.alloc(size)); try { return new (p) T (t1, t2, t3, t4, t5, t6, t7); } catch (...) { (allocator.dealloc(p)); throw; }; }


      template <class T1, class T2, class T3, class T4, class T5,
                class T6, class T7, class T8>
  T* operator () (const T1& t1, const T2& t2, const T3& t3,
                  const T4& t4, const T5& t5, const T6& t6,
                  const T7& t7, const T8& t8)
  { void *p = (allocator.alloc(size)); try { return new (p) T (t1, t2, t3, t4, t5, t6, t7, t8); } catch (...) { (allocator.dealloc(p)); throw; }; }


      template <class T1, class T2, class T3, class T4, class T5,
                class T6, class T7, class T8, class T9>
  T* operator () (const T1& t1, const T2& t2, const T3& t3,
                  const T4& t4, const T5& t5, const T6& t6,
                  const T7& t7, const T8& t8, const T9& t9)
  { void *p = (allocator.alloc(size)); try { return new (p) T (t1, t2, t3, t4, t5, t6, t7, t8, t9); } catch (...) { (allocator.dealloc(p)); throw; }; }


      template <class T0, class T1, class T2, class T3, class T4,
                class T5, class T6, class T7, class T8, class T9>
  T* operator () (const T0& t0, const T1& t1, const T2& t2,
                  const T3& t3, const T4& t4, const T5& t5,
                  const T6& t6, const T7& t7, const T8& t8,
                  const T9& t9)
  { void *p = (allocator.alloc(size)); try { return new (p) T (t0, t1, t2, t3, t4, t5, t6, t7, t8, t9); } catch (...) { (allocator.dealloc(p)); throw; }; }


      template <class T0, class T1, class T2, class T3, class T4,
                class T5, class T6, class T7, class T8, class T9, class T10>
  T* operator () (const T0& t0, const T1& t1, const T2& t2,
                  const T3& t3, const T4& t4, const T5& t5,
                  const T6& t6, const T7& t7, const T8& t8,
                  const T9& t9, const T10& t10)
  { void *p = (allocator.alloc(size)); try { return new (p) T (t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10); } catch (...) { (allocator.dealloc(p)); throw; }; }


      template <class T0, class T1, class T2, class T3, class T4,
                class T5, class T6, class T7, class T8, class T9,
                class T10, class T11>
  T* operator () (const T0& t0, const T1& t1, const T2& t2,
                  const T3& t3, const T4& t4, const T5& t5,
                  const T6& t6, const T7& t7, const T8& t8,
                  const T9& t9, const T10& t10, const T11& t11)
  { void *p = (allocator.alloc(size)); try { return new (p) T (t0, t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11); } catch (...) { (allocator.dealloc(p)); throw; }; }

private:






  static T* base2first(void* base)
  {
    return reinterpret_cast<T*>
      (reinterpret_cast<char*>(base) + sizeof(size_t));
  }





  static void* first2base(T* first)
  {
    return reinterpret_cast<void*>
      (reinterpret_cast<char*>(first) - sizeof(size_t));
  }

public:
# 849 "../../../../src/aleph/genAlloc.H"
  T* operator [] (int n) throw(std::exception, AlephExc, SizeFault)
  {
    if (n <= 0)
      throwException<SizeFault>("../../../../src/aleph/genAlloc.H", 852, "SizeFault") ();


    if ((static_cast<bool>(SimpleType<T>::value)))
      return reinterpret_cast<T*>((allocator.alloc(n*sizeof(T))));



    char *base = reinterpret_cast<char*>
      ((allocator.alloc((sizeof(size_t) + n*sizeof(T)))));

    T *first = base2first(base);
    *reinterpret_cast<size_t*>(base) = n;


    long i;
    try
      {
                                   ;
        for (i = 0; i < n; i++)
          new (&first[i]) T;

        return first;
      }
    catch (...)
      {

                                  ;
        if (not allocator.IsArena())
          while (i--)
            first[i].~T();

        (allocator.dealloc(base));
        throw;
      }
  }




  void del(T *ptr)
  {
    if ((static_cast<bool>(not (static_cast<bool>(SimpleType<T>::value)))) and not allocator.IsArena())
      ptr->~T();

    (allocator.dealloc(ptr));
  }




  void delArray(T* first)
  {
    if ((static_cast<bool>(SimpleType<T>::value)))
      {

        (allocator.dealloc(first));
        return;
      }

    void *base = first2base(first);
    size_t n = * reinterpret_cast<size_t*>(base);


    if (not allocator.IsArena())
      {
        unsigned long i;

        for (i = 0; i < n; i++)
          first[i].~T();
      }

    (allocator.dealloc(base));
  }
};
# 944 "../../../../src/aleph/genAlloc.H"
template <class T> class Constructor_T_ptr{};

    template <class T>
class Constructor <T*>
{
private:

  friend Constructor<T*> construct<T*>(GenAlloc&);
  friend Constructor<T*> construct<T*>(GenAlloc&, size_t);
  friend void destruct<>(GenAlloc&, T**);
  friend void destructArray<>(GenAlloc&, T**);
  friend Constructor<T*> construct<T*>(GenAlloc&, const char *, int);
  friend Constructor<T*> construct<T*>(GenAlloc&, const char *, int, size_t);
  friend void destruct<>(GenAlloc&, T**, const char *, int);
  friend void destructArray<>(GenAlloc&, T**, const char *, int);

  GenAlloc& allocator;
# 969 "../../../../src/aleph/genAlloc.H"
  Constructor();
  Constructor& operator = (const Constructor&);

  Constructor(const Constructor&);

  Constructor(GenAlloc& _allocator)
    : allocator(_allocator)
  { }
# 985 "../../../../src/aleph/genAlloc.H"
public:


  operator T** ()
  {
    return reinterpret_cast<T**>((allocator.alloc(sizeof(T*))));
  }


  T** operator() ()
  {
    return reinterpret_cast<T**>((allocator.alloc(sizeof(T*))));
  }


  T** operator [] (int n) throw(std::exception, AlephExc, SizeFault)
  {
    if (n <= 0)
      throwException<SizeFault>("../../../../src/aleph/genAlloc.H", 1003, "SizeFault") ();

    return reinterpret_cast<T**>((allocator.alloc(n*sizeof(T*))));
  }


  void del(T **ptr)
  {
    (allocator.dealloc(ptr));
  }


  void delArray(T** first)
  {
    (allocator.dealloc(first));
  }
};
# 1042 "../../../../src/aleph/genAlloc.H"
template < class T, const size_t n > class Constructor_Tn{};

    template < class T, const size_t n >
class Constructor< T [n] >
{
private:

  typedef T Array[n];

  friend Constructor<T[n]> construct<T[n]>(GenAlloc&);
  friend Constructor<T[n]> construct<T[n]>(GenAlloc&, size_t);
  friend void destruct<>(GenAlloc&, Array*);
  friend void destructArray<>(GenAlloc&, Array*);
  friend Constructor<T[n]> construct<T[n]>(GenAlloc&, const char *, int);
  friend Constructor<T[n]> construct<T[n]>(GenAlloc&, const char *, int, size_t);
  friend void destruct<>(GenAlloc&, Array*, const char *, int);
  friend void destructArray<>(GenAlloc&, Array*, const char *, int);

  GenAlloc& allocator;
  size_t size;
# 1070 "../../../../src/aleph/genAlloc.H"
  Constructor();
  Constructor& operator = (const Constructor&);

  Constructor(const Constructor&);

  Constructor(GenAlloc& _allocator, size_t sz = sizeof(T))
    : allocator(_allocator), size(sz)
  {

  }
# 1093 "../../../../src/aleph/genAlloc.H"
public:


  operator Array * ()
  {




    return reinterpret_cast<Array*>(construct<T>(allocator, size)[n]);

  }


  Array* operator [] (int dim) throw(std::exception, AlephExc, SizeFault)
  {
    if (dim <= 0)
      throwException<SizeFault>("../../../../src/aleph/genAlloc.H", 1110, "SizeFault") ();







    return reinterpret_cast<Array*>(construct<T>(allocator, size)[n*dim]);

  }


  void del(Array *ptr)
  {



    destructArray<T>(allocator, reinterpret_cast<T*>(ptr));

  }


  void delArray(Array *ptr)
  {



    destructArray<T>(allocator, reinterpret_cast<T*>(ptr));

  }
};


    template <class T> inline
Constructor<T> construct(GenAlloc& allocator)
{
  return Constructor<T>(allocator);
}

    template <class T> inline
Constructor<T> construct(GenAlloc& allocator, size_t sz)
{
  return Constructor<T>(allocator, sz);
}

    template <class T> inline
void destruct(GenAlloc& allocator, T* ptr)
{
  return Constructor<T>(allocator).del(ptr);
}

    template <class T> inline
void destructArray(GenAlloc& allocator, T* ptr)
{
  return Constructor<T>(allocator).delArray(ptr);
}

    template <class T> inline
Constructor<T> construct(GenAlloc& allocator, const char *file, int line)
{
  return Constructor<T>(allocator, file, line);
}

    template <class T> inline
Constructor<T> construct(GenAlloc& allocator,
                         const char *file, int line, size_t sz)
{
  return Constructor<T>(allocator, file, line, sz);
}

    template <class T> inline
void destruct(GenAlloc& allocator, T* ptr, const char *file, int line)
{
  return Constructor<T>(allocator, file, line).del(ptr);
}

    template <class T> inline
void destructArray(GenAlloc& allocator, T* ptr, const char *file, int line)
{
  return Constructor<T>(allocator, file, line).delArray(ptr);
}
# 52 "../../../../src/aleph/ahAlloc.H" 2

namespace Aleph {
  extern GenAlloc* objectAlloc;
}
# 229 "../../../../src/aleph/ahAlloc.H"
# 1 "../../../../src/aleph/ahMem.H" 1
# 59 "../../../../src/aleph/ahMem.H"
# 1 "/usr/include/stdlib.h" 1 3
# 60 "../../../../src/aleph/ahMem.H" 2
# 230 "../../../../src/aleph/ahAlloc.H" 2

class ObjectAlloc : public GenAlloc
{

public:

  virtual Pointer alloc(size_t size) throw(std::exception, AlephExc, Nomem)
  {
    Pointer ptr = malloc(size);

    if (ptr == __null)
      throwException<Nomem>("../../../../src/aleph/ahAlloc.H", 241, "Nomem") (size);

    return ptr;
  }

  virtual void dealloc(Pointer ptr)
    throw(std::exception, AlephExc, AddrUnknown, SizeFault)
  {
    free(ptr);
  }

  virtual void dealloc(Pointer ptr, size_t size)
    throw(std::exception, AlephExc, AddrUnknown, SizeFault)
  {
    free(ptr);
  }

  virtual Pointer ralloc(Pointer ptr, size_t size)
    throw(std::exception, AlephExc, Nomem)
  {
    Pointer newPtr = realloc(ptr, size);

    if (newPtr == __null)
      throwException<Nomem>("../../../../src/aleph/ahAlloc.H", 264, "Nomem") (size);

    return newPtr;
  }

  virtual Pointer alloc(size_t, const char*, int)
    throw(std::exception, AlephExc, NotImplemented)
  {
    throwException<NotImplemented>("../../../../src/aleph/ahAlloc.H", 272, "NotImplemented") ();
    return __null;
  }

  virtual void dealloc(Pointer, const char*, int)
    throw(std::exception, AlephExc, NotImplemented)
  {
    throwException<NotImplemented>("../../../../src/aleph/ahAlloc.H", 279, "NotImplemented") ();
  }

  virtual void dealloc(Pointer, size_t, const char*, int)
    throw(std::exception, AlephExc, NotImplemented)
  {
    throwException<NotImplemented>("../../../../src/aleph/ahAlloc.H", 285, "NotImplemented") ();
  }

  virtual Pointer ralloc(Pointer, size_t, const char*, int)
    throw(std::exception, AlephExc, NotImplemented)
  {
    throwException<NotImplemented>("../../../../src/aleph/ahAlloc.H", 291, "NotImplemented") ();
    return __null;
  }

};
# 55 "../../../../src/aleph/ahNew.H" 2
# 54 "../../../../src/aleph/aleph.H" 2
# 1 "../../../../src/aleph/bootstrap.H" 1
# 55 "../../../../src/aleph/bootstrap.H"
# 1 "/usr/include/sys/socket.h" 1 3
# 23 "/usr/include/sys/socket.h" 3
# 1 "/usr/include/features.h" 1 3
# 24 "/usr/include/sys/socket.h" 2 3

extern "C" {

# 1 "/usr/include/sys/uio.h" 1 3
# 22 "/usr/include/sys/uio.h" 3
# 1 "/usr/include/features.h" 1 3
# 23 "/usr/include/sys/uio.h" 2 3

# 1 "/usr/include/sys/types.h" 1 3
# 25 "/usr/include/sys/uio.h" 2 3

extern "C" {


# 1 "/usr/include/bits/uio.h" 1 3
# 24 "/usr/include/bits/uio.h" 3
# 1 "/usr/include/sys/types.h" 1 3
# 25 "/usr/include/bits/uio.h" 2 3
# 42 "/usr/include/bits/uio.h" 3
struct iovec
  {
    void *iov_base;
    size_t iov_len;
  };
# 30 "/usr/include/sys/uio.h" 2 3







extern ssize_t readv (int __fd, __const struct iovec *__vector, int __count)
     throw ();






extern ssize_t writev (int __fd, __const struct iovec *__vector, int __count)
     throw ();

}
# 28 "/usr/include/sys/socket.h" 2 3

# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stddef.h" 1 3
# 30 "/usr/include/sys/socket.h" 2 3





# 1 "/usr/include/bits/socket.h" 1 3
# 29 "/usr/include/bits/socket.h" 3
# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stddef.h" 1 3
# 30 "/usr/include/bits/socket.h" 2 3

# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/limits.h" 1 3
# 11 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/limits.h" 3
# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/syslimits.h" 1 3






# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/limits.h" 1 3
# 125 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/limits.h" 3
# 1 "/usr/include/limits.h" 1 3
# 26 "/usr/include/limits.h" 3
# 1 "/usr/include/features.h" 1 3
# 27 "/usr/include/limits.h" 2 3
# 144 "/usr/include/limits.h" 3
# 1 "/usr/include/bits/posix1_lim.h" 1 3
# 126 "/usr/include/bits/posix1_lim.h" 3
# 1 "/usr/include/bits/local_lim.h" 1 3
# 36 "/usr/include/bits/local_lim.h" 3
# 1 "/usr/include/linux/limits.h" 1 3
# 37 "/usr/include/bits/local_lim.h" 2 3
# 127 "/usr/include/bits/posix1_lim.h" 2 3
# 145 "/usr/include/limits.h" 2 3



# 1 "/usr/include/bits/posix2_lim.h" 1 3
# 149 "/usr/include/limits.h" 2 3



# 1 "/usr/include/bits/xopen_lim.h" 1 3
# 34 "/usr/include/bits/xopen_lim.h" 3
# 1 "/usr/include/bits/stdio_lim.h" 1 3
# 35 "/usr/include/bits/xopen_lim.h" 2 3
# 136 "/usr/include/bits/xopen_lim.h" 3
# 1 "/usr/include/bits/wordsize.h" 1 3
# 137 "/usr/include/bits/xopen_lim.h" 2 3
# 153 "/usr/include/limits.h" 2 3
# 126 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/limits.h" 2 3
# 8 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/syslimits.h" 2 3
# 12 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/limits.h" 2 3
# 32 "/usr/include/bits/socket.h" 2 3
# 1 "/usr/include/sys/types.h" 1 3
# 33 "/usr/include/bits/socket.h" 2 3
# 41 "/usr/include/bits/socket.h" 3
enum __socket_type
{
  SOCK_STREAM = 1,


  SOCK_DGRAM = 2,


  SOCK_RAW = 3,

  SOCK_RDM = 4,

  SOCK_SEQPACKET = 5,


  SOCK_PACKET = 10



};
# 142 "/usr/include/bits/socket.h" 3
# 1 "/usr/include/bits/sockaddr.h" 1 3
# 29 "/usr/include/bits/sockaddr.h" 3
typedef unsigned short int sa_family_t;
# 143 "/usr/include/bits/socket.h" 2 3


struct sockaddr
  {
    sa_family_t sa_family;
    char sa_data[14];
  };
# 162 "/usr/include/bits/socket.h" 3
struct sockaddr_storage
  {
    sa_family_t ss_family;
    __uint32_t __ss_align;
    char __ss_padding[(128 - (2 * sizeof (__uint32_t)))];
  };



enum
  {
    MSG_OOB = 0x01,

    MSG_PEEK = 0x02,

    MSG_DONTROUTE = 0x04,



    MSG_TRYHARD = MSG_DONTROUTE,


    MSG_CTRUNC = 0x08,

    MSG_PROXY = 0x10,

    MSG_TRUNC = 0x20,

    MSG_DONTWAIT = 0x40,

    MSG_EOR = 0x80,

    MSG_WAITALL = 0x100,

    MSG_FIN = 0x200,

    MSG_SYN = 0x400,

    MSG_CONFIRM = 0x800,

    MSG_RST = 0x1000,

    MSG_ERRQUEUE = 0x2000,

    MSG_NOSIGNAL = 0x4000,

    MSG_MORE = 0x8000

  };




struct msghdr
  {
    void *msg_name;
    socklen_t msg_namelen;

    struct iovec *msg_iov;
    int msg_iovlen;

    void *msg_control;
    socklen_t msg_controllen;

    int msg_flags;
  };


struct cmsghdr
  {
    size_t cmsg_len;

    int cmsg_level;
    int cmsg_type;
    __extension__ unsigned char __cmsg_data [];

  };
# 256 "/usr/include/bits/socket.h" 3
extern struct cmsghdr *__cmsg_nxthdr (struct msghdr *__mhdr,
                                      struct cmsghdr *__cmsg) throw ();




extern __inline struct cmsghdr *
__cmsg_nxthdr (struct msghdr *__mhdr, struct cmsghdr *__cmsg) throw ()
{
  if ((size_t) __cmsg->cmsg_len < sizeof (struct cmsghdr))

    return 0;

  __cmsg = (struct cmsghdr *) ((unsigned char *) __cmsg
                               + (((__cmsg->cmsg_len) + sizeof (size_t) - 1) & (size_t) ~(sizeof (size_t) - 1)));
  if ((unsigned char *) (__cmsg + 1) > ((unsigned char *) __mhdr->msg_control
                                        + __mhdr->msg_controllen)
      || ((unsigned char *) __cmsg + (((__cmsg->cmsg_len) + sizeof (size_t) - 1) & (size_t) ~(sizeof (size_t) - 1))
          > ((unsigned char *) __mhdr->msg_control + __mhdr->msg_controllen)))

    return 0;
  return __cmsg;
}




enum
  {
    SCM_RIGHTS = 0x01,


    SCM_CREDENTIALS = 0x02,


    __SCM_CONNECT = 0x03
  };



struct ucred
{
  pid_t pid;
  uid_t uid;
  gid_t gid;
};


# 1 "/usr/include/asm/socket.h" 1 3



# 1 "/usr/include/asm/sockios.h" 1 3
# 5 "/usr/include/asm/socket.h" 2 3
# 305 "/usr/include/bits/socket.h" 2 3



struct linger
  {
    int l_onoff;
    int l_linger;
  };
# 36 "/usr/include/sys/socket.h" 2 3




struct osockaddr
  {
    unsigned short int sa_family;
    unsigned char sa_data[14];
  };




enum
{
  SHUT_RD = 0,

  SHUT_WR,

  SHUT_RDWR

};
# 100 "/usr/include/sys/socket.h" 3
extern int socket (int __domain, int __type, int __protocol) throw ();





extern int socketpair (int __domain, int __type, int __protocol,
                       int __fds[2]) throw ();


extern int bind (int __fd, __const struct sockaddr * __addr, socklen_t __len)
     throw ();


extern int getsockname (int __fd, struct sockaddr *__restrict __addr,
                        socklen_t *__restrict __len) throw ();





extern int connect (int __fd, __const struct sockaddr * __addr, socklen_t __len)
     throw ();



extern int getpeername (int __fd, struct sockaddr *__restrict __addr,
                        socklen_t *__restrict __len) throw ();



extern ssize_t send (int __fd, __const void *__buf, size_t __n, int __flags)
     throw ();



extern ssize_t recv (int __fd, void *__buf, size_t __n, int __flags)
     throw ();



extern ssize_t sendto (int __fd, __const void *__buf, size_t __n,
                       int __flags, __const struct sockaddr * __addr,
                       socklen_t __addr_len) throw ();





extern ssize_t recvfrom (int __fd, void *__restrict __buf, size_t __n, int __flags,
                         struct sockaddr *__restrict __addr, socklen_t *__restrict __addr_len)
     throw ();




extern ssize_t sendmsg (int __fd, __const struct msghdr *__message, int __flags)
     throw ();



extern ssize_t recvmsg (int __fd, struct msghdr *__message, int __flags)
     throw ();





extern int getsockopt (int __fd, int __level, int __optname,
                       void *__restrict __optval,
                       socklen_t *__restrict __optlen) throw ();




extern int setsockopt (int __fd, int __level, int __optname,
                       __const void *__optval, socklen_t __optlen) throw ();





extern int listen (int __fd, int __n) throw ();






extern int accept (int __fd, struct sockaddr *__restrict __addr,
                   socklen_t *__restrict __addr_len)
     throw ();







extern int shutdown (int __fd, int __how) throw ();




extern int sockatmark (int __fd) throw ();







extern int isfdtype (int __fd, int __fdtype) throw ();


}
# 56 "../../../../src/aleph/bootstrap.H" 2
# 1 "/usr/include/netinet/in.h" 1 3
# 22 "/usr/include/netinet/in.h" 3
# 1 "/usr/include/features.h" 1 3
# 23 "/usr/include/netinet/in.h" 2 3
# 1 "/usr/include/stdint.h" 1 3
# 26 "/usr/include/stdint.h" 3
# 1 "/usr/include/features.h" 1 3
# 27 "/usr/include/stdint.h" 2 3
# 1 "/usr/include/bits/wchar.h" 1 3
# 28 "/usr/include/stdint.h" 2 3
# 1 "/usr/include/bits/wordsize.h" 1 3
# 29 "/usr/include/stdint.h" 2 3
# 49 "/usr/include/stdint.h" 3
typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;

typedef unsigned int uint32_t;





__extension__
typedef unsigned long long int uint64_t;






typedef signed char int_least8_t;
typedef short int int_least16_t;
typedef int int_least32_t;



__extension__
typedef long long int int_least64_t;



typedef unsigned char uint_least8_t;
typedef unsigned short int uint_least16_t;
typedef unsigned int uint_least32_t;



__extension__
typedef unsigned long long int uint_least64_t;






typedef signed char int_fast8_t;





typedef int int_fast16_t;
typedef int int_fast32_t;
__extension__
typedef long long int int_fast64_t;



typedef unsigned char uint_fast8_t;





typedef unsigned int uint_fast16_t;
typedef unsigned int uint_fast32_t;
__extension__
typedef unsigned long long int uint_fast64_t;
# 129 "/usr/include/stdint.h" 3
typedef unsigned int uintptr_t;
# 138 "/usr/include/stdint.h" 3
__extension__
typedef long long int intmax_t;
__extension__
typedef unsigned long long int uintmax_t;
# 24 "/usr/include/netinet/in.h" 2 3
# 1 "/usr/include/bits/types.h" 1 3
# 25 "/usr/include/netinet/in.h" 2 3


extern "C" {


enum
  {
    IPPROTO_IP = 0,

    IPPROTO_HOPOPTS = 0,

    IPPROTO_ICMP = 1,

    IPPROTO_IGMP = 2,

    IPPROTO_IPIP = 4,

    IPPROTO_TCP = 6,

    IPPROTO_EGP = 8,

    IPPROTO_PUP = 12,

    IPPROTO_UDP = 17,

    IPPROTO_IDP = 22,

    IPPROTO_TP = 29,

    IPPROTO_IPV6 = 41,

    IPPROTO_ROUTING = 43,

    IPPROTO_FRAGMENT = 44,

    IPPROTO_RSVP = 46,

    IPPROTO_GRE = 47,

    IPPROTO_ESP = 50,

    IPPROTO_AH = 51,

    IPPROTO_ICMPV6 = 58,

    IPPROTO_NONE = 59,

    IPPROTO_DSTOPTS = 60,

    IPPROTO_MTP = 92,

    IPPROTO_ENCAP = 98,

    IPPROTO_PIM = 103,

    IPPROTO_COMP = 108,

    IPPROTO_RAW = 255,

    IPPROTO_MAX
  };



typedef uint16_t in_port_t;


enum
  {
    IPPORT_ECHO = 7,
    IPPORT_DISCARD = 9,
    IPPORT_SYSTAT = 11,
    IPPORT_DAYTIME = 13,
    IPPORT_NETSTAT = 15,
    IPPORT_FTP = 21,
    IPPORT_TELNET = 23,
    IPPORT_SMTP = 25,
    IPPORT_TIMESERVER = 37,
    IPPORT_NAMESERVER = 42,
    IPPORT_WHOIS = 43,
    IPPORT_MTP = 57,

    IPPORT_TFTP = 69,
    IPPORT_RJE = 77,
    IPPORT_FINGER = 79,
    IPPORT_TTYLINK = 87,
    IPPORT_SUPDUP = 95,


    IPPORT_EXECSERVER = 512,
    IPPORT_LOGINSERVER = 513,
    IPPORT_CMDSERVER = 514,
    IPPORT_EFSSERVER = 520,


    IPPORT_BIFFUDP = 512,
    IPPORT_WHOSERVER = 513,
    IPPORT_ROUTESERVER = 520,


    IPPORT_RESERVED = 1024,


    IPPORT_USERRESERVED = 5000
  };



typedef uint32_t in_addr_t;
struct in_addr
  {
    in_addr_t s_addr;
  };
# 190 "/usr/include/netinet/in.h" 3
struct in6_addr
  {
    union
      {
        uint8_t u6_addr8[16];
        uint16_t u6_addr16[8];
        uint32_t u6_addr32[4];
      } in6_u;



  };

extern const struct in6_addr in6addr_any;
extern const struct in6_addr in6addr_loopback;







# 1 "/usr/include/bits/socket.h" 1 3
# 213 "/usr/include/netinet/in.h" 2 3



struct sockaddr_in
  {
    sa_family_t sin_family;
    in_port_t sin_port;
    struct in_addr sin_addr;


    unsigned char sin_zero[sizeof (struct sockaddr) -
                           (sizeof (unsigned short int)) -
                           sizeof (in_port_t) -
                           sizeof (struct in_addr)];
  };


struct sockaddr_in6
  {
    sa_family_t sin6_family;
    in_port_t sin6_port;
    uint32_t sin6_flowinfo;
    struct in6_addr sin6_addr;
    uint32_t sin6_scope_id;
  };


struct ipv6_mreq
  {

    struct in6_addr ipv6mr_multiaddr;


    unsigned int ipv6mr_interface;
  };


# 1 "/usr/include/bits/in.h" 1 3
# 66 "/usr/include/bits/in.h" 3
struct ip_opts
  {
    struct in_addr ip_dst;
    char ip_opts[40];
  };


struct ip_mreq
  {
    struct in_addr imr_multiaddr;
    struct in_addr imr_interface;
  };


struct ip_mreqn
  {
    struct in_addr imr_multiaddr;
    struct in_addr imr_address;
    int imr_ifindex;
  };


struct in_pktinfo
  {
    int ipi_ifindex;
    struct in_addr ipi_spec_dst;
    struct in_addr ipi_addr;
  };
# 251 "/usr/include/netinet/in.h" 2 3
# 259 "/usr/include/netinet/in.h" 3
extern uint32_t ntohl (uint32_t __netlong) throw () __attribute__ ((__const__));
extern uint16_t ntohs (uint16_t __netshort)
     throw () __attribute__ ((__const__));
extern uint32_t htonl (uint32_t __hostlong)
     throw () __attribute__ ((__const__));
extern uint16_t htons (uint16_t __hostshort)
     throw () __attribute__ ((__const__));

# 1 "/usr/include/endian.h" 1 3
# 268 "/usr/include/netinet/in.h" 2 3


# 1 "/usr/include/bits/byteswap.h" 1 3
# 271 "/usr/include/netinet/in.h" 2 3
# 333 "/usr/include/netinet/in.h" 3
extern int bindresvport (int __sockfd, struct sockaddr_in *__sock_in) throw ();


extern int bindresvport6 (int __sockfd, struct sockaddr_in6 *__sock_in)
     throw ();
# 361 "/usr/include/netinet/in.h" 3
struct in6_pktinfo
  {
    struct in6_addr ipi6_addr;
    unsigned int ipi6_ifindex;
  };

}
# 57 "../../../../src/aleph/bootstrap.H" 2
# 1 "/usr/include/arpa/inet.h" 1 3
# 22 "/usr/include/arpa/inet.h" 3
# 1 "/usr/include/features.h" 1 3
# 23 "/usr/include/arpa/inet.h" 2 3
# 1 "/usr/include/netinet/in.h" 1 3
# 24 "/usr/include/arpa/inet.h" 2 3







extern "C" {



extern in_addr_t inet_addr (__const char *__cp) throw ();


extern in_addr_t inet_lnaof (struct in_addr __in) throw ();



extern struct in_addr inet_makeaddr (in_addr_t __net, in_addr_t __host)
     throw ();


extern in_addr_t inet_netof (struct in_addr __in) throw ();



extern in_addr_t inet_network (__const char *__cp) throw ();



extern char *inet_ntoa (struct in_addr __in) throw ();




extern int inet_pton (int __af, __const char *__restrict __cp,
                      void *__restrict __buf) throw ();




extern __const char *inet_ntop (int __af, __const void *__restrict __cp,
                                char *__restrict __buf, socklen_t __len)
     throw ();






extern in_addr_t inet_aton (__const char *__cp, struct in_addr *__inp) throw ();



extern char *inet_neta (in_addr_t __net, char *__buf, size_t __len) throw ();




extern char *inet_net_ntop (int __af, __const void *__cp, int __bits,
                            char *__buf, size_t __len) throw ();




extern int inet_net_pton (int __af, __const char *__cp,
                          void *__buf, size_t __len) throw ();




extern unsigned int inet_nsap_addr (__const char *__cp,
                                    unsigned char *__buf, int __len) throw ();



extern char *inet_nsap_ntoa (int __len, __const unsigned char *__cp,
                             char *__buf) throw ();


}
# 58 "../../../../src/aleph/bootstrap.H" 2

# 1 "../../../../src/aleph/dataSgAlloc.H" 1
# 50 "../../../../src/aleph/dataSgAlloc.H"
# 1 "../../../../src/aleph/staticAlloc.H" 1
# 57 "../../../../src/aleph/staticAlloc.H"
# 1 "../../../../src/aleph/genAlloc.H" 1
# 58 "../../../../src/aleph/staticAlloc.H" 2


class StaticAlloc : public GenAlloc
{
private:

  char *baseAddr;
  char *currAddr;
  char *maxAddr;

public:

  StaticAlloc(void* base, size_t size)
    : GenAlloc(true),
      baseAddr(static_cast<char*> (base)),
      currAddr(baseAddr),
      maxAddr(baseAddr + size)
    {

    }

  size_t getAllocatedSize() const { return currAddr - baseAddr; }

  size_t getAvailableSize() const { return maxAddr - currAddr; }

  size_t getCapacity() const { return maxAddr - baseAddr; }

  virtual Pointer alloc(size_t size)
    throw(std::exception, AlephExc, Nomem, SizeFault)
    {
      if (size == 0)
        throwException<SizeFault>("../../../../src/aleph/staticAlloc.H", 89, "SizeFault") (size);

      size_t neededSize = roundAlign(size);

      if (currAddr + neededSize > maxAddr)
        throwException<Nomem>("../../../../src/aleph/staticAlloc.H", 94, "Nomem") (size);

      Pointer retVal = currAddr;

      currAddr += neededSize;

      return retVal;
    }

  virtual void dealloc(Pointer) throw ()
    {

    }

  virtual void dealloc(Pointer, size_t) throw ()
    {

    }

  virtual Pointer ralloc(Pointer, size_t)
    throw ()
    {
      return __null;
    }

  virtual Pointer alloc(size_t size,
                        const char* ,
                        int )
    throw(std::exception, AlephExc, Nomem, SizeFault)
    {
      return alloc(size);
    }

  virtual void dealloc(Pointer,
                       const char* ,
                       int )
    throw ()
    {

    }

  virtual void dealloc(Pointer,
                       size_t,
                       const char* ,
                       int )
    throw ()
    {

    }

  virtual Pointer ralloc(Pointer,
                         size_t,
                         const char* ,
                         int )
    throw ()
    {
      return __null;
    }

};
# 51 "../../../../src/aleph/dataSgAlloc.H" 2

class DataSgAlloc;


class DataSgAlloc : public StaticAlloc
{
  static unsigned int instanceCounter;
  static const size_t dataSgSize = 1932;
  static char arena[dataSgSize];

public:

  DataSgAlloc() : StaticAlloc(&arena[0], dataSgSize)
    {
                                                  ;
      if (instanceCounter++ > 0)
        Aleph::error("../../../../src/aleph/dataSgAlloc.H", 67, "Double instantiation of DataSgAlloc class");
    }

  virtual ~DataSgAlloc()
    {
                                             ;
# 81 "../../../../src/aleph/dataSgAlloc.H"
    }
};
# 60 "../../../../src/aleph/bootstrap.H" 2


class Bootstrapper
{
private:

  static unsigned int instanceCounter;

  static const char *file;
  static int line;
  static pid_t pid;
  static pid_t parentPid;

  static const size_t host_name_len = 256;
  static const size_t ip_string_len = 40;
  static char host_name[host_name_len];
  static char ip_string[ip_string_len];
  static struct in_addr in_addr;

  void get_host_name();

public:

  Bootstrapper(const char *_file = "../../../../src/aleph/bootstrap.H", int _line = 83);

  virtual ~Bootstrapper();

  static void bootstrap();

  static void exit();

  static pid_t getPid() { return pid; }

  static pid_t getParentPid() { return pid; }
};
# 55 "../../../../src/aleph/aleph.H" 2
# 2 "client2.C" 2
# 1 "../../../../src/Binder/include/locator_calls.H" 1



# 1 "../../../../src/aleph/aleph.H" 1
# 5 "../../../../src/Binder/include/locator_calls.H" 2
# 1 "../../../../src/Binder/include/locator_exceptions.H" 1



# 1 "../../../../src/aleph/ahExceptions.H" 1
# 5 "../../../../src/Binder/include/locator_exceptions.H" 2
# 1 "../../../../src/Binder/include/binder.H" 1





# 1 "/usr/include/unistd.h" 1 3
# 7 "../../../../src/Binder/include/binder.H" 2

# 1 "../../../../src/aleph/port.H" 1
# 49 "../../../../src/aleph/port.H"
# 1 "../../../../src/aleph/uid.H" 1
# 49 "../../../../src/aleph/uid.H"
# 1 "/usr/include/stdint.h" 1 3
# 50 "../../../../src/aleph/uid.H" 2
# 1 "/usr/local/include/g++-v3/iostream" 1 3
# 31 "/usr/local/include/g++-v3/iostream" 3
# 1 "/usr/local/include/g++-v3/bits/std_iostream.h" 1 3
# 38 "/usr/local/include/g++-v3/bits/std_iostream.h" 3

# 1 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/c++config.h" 1 3
# 34 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/c++config.h" 3
# 1 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/os_defines.h" 1 3
# 37 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/os_defines.h" 3
# 1 "/usr/include/features.h" 1 3
# 38 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/os_defines.h" 2 3
# 35 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/c++config.h" 2 3

# 1 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/limits.h" 1 3
# 37 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/c++config.h" 2 3
# 40 "/usr/local/include/g++-v3/bits/std_iostream.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_ostream.h" 1 3
# 38 "/usr/local/include/g++-v3/bits/std_ostream.h" 3

# 1 "/usr/local/include/g++-v3/bits/std_ios.h" 1 3
# 38 "/usr/local/include/g++-v3/bits/std_ios.h" 3

# 1 "/usr/local/include/g++-v3/bits/std_iosfwd.h" 1 3
# 38 "/usr/local/include/g++-v3/bits/std_iosfwd.h" 3

# 1 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/c++config.h" 1 3
# 40 "/usr/local/include/g++-v3/bits/std_iosfwd.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/stringfwd.h" 1 3
# 38 "/usr/local/include/g++-v3/bits/stringfwd.h" 3

# 1 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/c++config.h" 1 3
# 40 "/usr/local/include/g++-v3/bits/stringfwd.h" 2 3

namespace std
{
  template<class _CharT>
    struct char_traits;

  template<> struct char_traits<char>;

  template<> struct char_traits<wchar_t>;


  template<typename _Alloc>
    class allocator;

  template<typename _CharT, typename _Traits = char_traits<_CharT>,
           typename _Alloc = allocator<_CharT> >
    class basic_string;

  typedef basic_string<char> string;

  typedef basic_string<wchar_t> wstring;

}
# 41 "/usr/local/include/g++-v3/bits/std_iosfwd.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/fpos.h" 1 3
# 38 "/usr/local/include/g++-v3/bits/fpos.h" 3

# 1 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/c++io.h" 1 3
# 35 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/c++io.h" 3
# 1 "/usr/local/include/g++-v3/cstdio" 1 3
# 31 "/usr/local/include/g++-v3/cstdio" 3
# 1 "/usr/local/include/g++-v3/bits/std_cstdio.h" 1 3
# 37 "/usr/local/include/g++-v3/bits/std_cstdio.h" 3
# 1 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/c++config.h" 1 3
# 38 "/usr/local/include/g++-v3/bits/std_cstdio.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_cstddef.h" 1 3
# 39 "/usr/local/include/g++-v3/bits/std_cstdio.h" 2 3
# 41 "/usr/local/include/g++-v3/bits/std_cstdio.h" 3
# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdio.h" 1 3
# 42 "/usr/local/include/g++-v3/bits/std_cstdio.h" 2 3
# 86 "/usr/local/include/g++-v3/bits/std_cstdio.h" 3
namespace std
{
  using ::FILE;
  using ::fpos_t;

  using ::clearerr;
  using ::fclose;
  using ::feof;
  using ::ferror;
  using ::fflush;
  using ::fgetc;
  using ::fgetpos;
  using ::fgets;
  using ::fopen;
  using ::fprintf;
  using ::fputc;
  using ::fputs;
  using ::fread;
  using ::freopen;
  using ::fscanf;
  using ::fseek;
  using ::fsetpos;
  using ::ftell;
  using ::fwrite;
  using ::getc;
  using ::getchar;
  using ::gets;
  using ::perror;
  using ::printf;
  using ::putc;
  using ::putchar;
  using ::puts;
  using ::remove;
  using ::rename;
  using ::rewind;
  using ::scanf;
  using ::setbuf;
  using ::setvbuf;
  using ::sprintf;
  using ::sscanf;
  using ::tmpfile;
  using ::tmpnam;
  using ::ungetc;
  using ::vfprintf;
  using ::vprintf;
  using ::vsprintf;
}
# 142 "/usr/local/include/g++-v3/bits/std_cstdio.h" 3
namespace __gnu_cxx
{
  using ::snprintf;
  using ::vfscanf;
  using ::vscanf;
  using ::vsnprintf;
  using ::vsscanf;
}

namespace std
{
  using __gnu_cxx::snprintf;
  using __gnu_cxx::vfscanf;
  using __gnu_cxx::vscanf;
  using __gnu_cxx::vsnprintf;
  using __gnu_cxx::vsscanf;
}
# 32 "/usr/local/include/g++-v3/cstdio" 2 3
# 36 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/c++io.h" 2 3
# 1 "/usr/local/include/g++-v3/cstddef" 1 3
# 37 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/c++io.h" 2 3
# 1 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/gthr.h" 1 3
# 98 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/gthr.h" 3
# 1 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/gthr-default.h" 1 3
# 37 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/gthr-default.h" 3
# 1 "/usr/include/pthread.h" 1 3
# 38 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/gthr-default.h" 2 3

typedef pthread_key_t __gthread_key_t;
typedef pthread_once_t __gthread_once_t;
typedef pthread_mutex_t __gthread_mutex_t;






#pragma weak pthread_once
#pragma weak pthread_key_create
#pragma weak pthread_key_delete
#pragma weak pthread_getspecific
#pragma weak pthread_setspecific
#pragma weak pthread_create

#pragma weak pthread_mutex_lock
#pragma weak pthread_mutex_trylock
#pragma weak pthread_mutex_unlock
# 80 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/gthr-default.h" 3
static void *__gthread_active_ptr = (void *) &pthread_create;

static inline int
__gthread_active_p (void)
{
  return __gthread_active_ptr != 0;
}
# 438 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/gthr-default.h" 3
static inline int
__gthread_once (__gthread_once_t *once, void (*func) (void))
{
  if (__gthread_active_p ())
    return pthread_once (once, func);
  else
    return -1;
}

static inline int
__gthread_key_create (__gthread_key_t *key, void (*dtor) (void *))
{
  return pthread_key_create (key, dtor);
}

static inline int
__gthread_key_dtor (__gthread_key_t key, void *ptr)
{

  if (ptr)
    return pthread_setspecific (key, 0);
  else
    return 0;
}

static inline int
__gthread_key_delete (__gthread_key_t key)
{
  return pthread_key_delete (key);
}

static inline void *
__gthread_getspecific (__gthread_key_t key)
{
  return pthread_getspecific (key);
}

static inline int
__gthread_setspecific (__gthread_key_t key, const void *ptr)
{
  return pthread_setspecific (key, ptr);
}

static inline int
__gthread_mutex_lock (__gthread_mutex_t *mutex)
{
  if (__gthread_active_p ())
    return pthread_mutex_lock (mutex);
  else
    return 0;
}

static inline int
__gthread_mutex_trylock (__gthread_mutex_t *mutex)
{
  if (__gthread_active_p ())
    return pthread_mutex_trylock (mutex);
  else
    return 0;
}

static inline int
__gthread_mutex_unlock (__gthread_mutex_t *mutex)
{
  if (__gthread_active_p ())
    return pthread_mutex_unlock (mutex);
  else
    return 0;
}
# 99 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/gthr.h" 2 3
# 38 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/c++io.h" 2 3

namespace std
{

  typedef long streamoff;
  typedef ptrdiff_t streamsize;

  typedef ptrdiff_t wstreamsize;

  typedef fpos_t __c_streampos;

  typedef __gthread_mutex_t __c_lock;



  typedef FILE __c_file_type;


  struct __ios_flags
  {
    typedef short __int_type;

    static const __int_type _S_boolalpha = 0x0001;
    static const __int_type _S_dec = 0x0002;
    static const __int_type _S_fixed = 0x0004;
    static const __int_type _S_hex = 0x0008;
    static const __int_type _S_internal = 0x0010;
    static const __int_type _S_left = 0x0020;
    static const __int_type _S_oct = 0x0040;
    static const __int_type _S_right = 0x0080;
    static const __int_type _S_scientific = 0x0100;
    static const __int_type _S_showbase = 0x0200;
    static const __int_type _S_showpoint = 0x0400;
    static const __int_type _S_showpos = 0x0800;
    static const __int_type _S_skipws = 0x1000;
    static const __int_type _S_unitbuf = 0x2000;
    static const __int_type _S_uppercase = 0x4000;
    static const __int_type _S_adjustfield = 0x0020 | 0x0080 | 0x0010;
    static const __int_type _S_basefield = 0x0002 | 0x0040 | 0x0008;
    static const __int_type _S_floatfield = 0x0100 | 0x0004;


    static const __int_type _S_badbit = 0x01;
    static const __int_type _S_eofbit = 0x02;
    static const __int_type _S_failbit = 0x04;


    static const __int_type _S_app = 0x01;
    static const __int_type _S_ate = 0x02;
    static const __int_type _S_bin = 0x04;
    static const __int_type _S_in = 0x08;
    static const __int_type _S_out = 0x10;
    static const __int_type _S_trunc = 0x20;
  };
}
# 40 "/usr/local/include/g++-v3/bits/fpos.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_cwchar.h" 1 3
# 37 "/usr/local/include/g++-v3/bits/std_cwchar.h" 3
# 1 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/c++config.h" 1 3
# 38 "/usr/local/include/g++-v3/bits/std_cwchar.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_cstddef.h" 1 3
# 39 "/usr/local/include/g++-v3/bits/std_cwchar.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_ctime.h" 1 3
# 37 "/usr/local/include/g++-v3/bits/std_ctime.h" 3
# 1 "/usr/local/include/g++-v3/bits/std_cstddef.h" 1 3
# 38 "/usr/local/include/g++-v3/bits/std_ctime.h" 2 3
# 40 "/usr/local/include/g++-v3/bits/std_ctime.h" 3
# 1 "/usr/include/time.h" 1 3
# 41 "/usr/local/include/g++-v3/bits/std_ctime.h" 2 3
# 53 "/usr/local/include/g++-v3/bits/std_ctime.h" 3
namespace std
{
  using ::clock_t;
  using ::time_t;
  using ::tm;

  using ::clock;
  using ::difftime;
  using ::mktime;
  using ::time;
  using ::asctime;
  using ::ctime;
  using ::gmtime;
  using ::localtime;
  using ::strftime;
}
# 40 "/usr/local/include/g++-v3/bits/std_cwchar.h" 2 3
# 43 "/usr/local/include/g++-v3/bits/std_cwchar.h" 3
# 1 "/usr/include/wchar.h" 1 3
# 28 "/usr/include/wchar.h" 3
# 1 "/usr/include/features.h" 1 3
# 29 "/usr/include/wchar.h" 2 3
# 37 "/usr/include/wchar.h" 3
# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdio.h" 1 3
# 38 "/usr/include/wchar.h" 2 3


# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdarg.h" 1 3
# 41 "/usr/include/wchar.h" 2 3







# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stddef.h" 1 3
# 49 "/usr/include/wchar.h" 2 3

# 1 "/usr/include/bits/wchar.h" 1 3
# 51 "/usr/include/wchar.h" 2 3
# 85 "/usr/include/wchar.h" 3
typedef __mbstate_t mbstate_t;
# 105 "/usr/include/wchar.h" 3
struct tm;


extern "C" {


extern wchar_t *wcscpy (wchar_t *__restrict __dest,
                        __const wchar_t *__restrict __src) throw ();

extern wchar_t *wcsncpy (wchar_t *__restrict __dest,
                         __const wchar_t *__restrict __src, size_t __n)
     throw ();


extern wchar_t *wcscat (wchar_t *__restrict __dest,
                        __const wchar_t *__restrict __src) throw ();

extern wchar_t *wcsncat (wchar_t *__restrict __dest,
                         __const wchar_t *__restrict __src, size_t __n)
     throw ();


extern int wcscmp (__const wchar_t *__s1, __const wchar_t *__s2)
     throw () __attribute__ ((__pure__));

extern int wcsncmp (__const wchar_t *__s1, __const wchar_t *__s2, size_t __n)
     throw () __attribute__ ((__pure__));



extern int wcscasecmp (__const wchar_t *__s1, __const wchar_t *__s2) throw ();


extern int wcsncasecmp (__const wchar_t *__s1, __const wchar_t *__s2,
                        size_t __n) throw ();



# 1 "/usr/include/xlocale.h" 1 3
# 144 "/usr/include/wchar.h" 2 3

extern int __wcscasecmp_l (__const wchar_t *__s1, __const wchar_t *__s2,
                           __locale_t __loc) throw ();

extern int __wcsncasecmp_l (__const wchar_t *__s1, __const wchar_t *__s2,
                            size_t __n, __locale_t __loc) throw ();




extern int wcscoll (__const wchar_t *__s1, __const wchar_t *__s2) throw ();



extern size_t wcsxfrm (wchar_t *__restrict __s1,
                       __const wchar_t *__restrict __s2, size_t __n) throw ();







extern int __wcscoll_l (__const wchar_t *__s1, __const wchar_t *__s2,
                        __locale_t __loc) throw ();



extern size_t __wcsxfrm_l (wchar_t *__s1, __const wchar_t *__s2,
                           size_t __n, __locale_t __loc) throw ();


extern wchar_t *wcsdup (__const wchar_t *__s) throw () __attribute__ ((__malloc__));



extern wchar_t *wcschr (__const wchar_t *__wcs, wchar_t __wc)
     throw () __attribute__ ((__pure__));

extern wchar_t *wcsrchr (__const wchar_t *__wcs, wchar_t __wc)
     throw () __attribute__ ((__pure__));




extern wchar_t *wcschrnul (__const wchar_t *__s, wchar_t __wc)
     throw () __attribute__ ((__pure__));




extern size_t wcscspn (__const wchar_t *__wcs, __const wchar_t *__reject)
     throw () __attribute__ ((__pure__));


extern size_t wcsspn (__const wchar_t *__wcs, __const wchar_t *__accept)
     throw () __attribute__ ((__pure__));

extern wchar_t *wcspbrk (__const wchar_t *__wcs, __const wchar_t *__accept)
     throw () __attribute__ ((__pure__));

extern wchar_t *wcsstr (__const wchar_t *__haystack, __const wchar_t *__needle)
     throw () __attribute__ ((__pure__));



extern wchar_t *wcswcs (__const wchar_t *__haystack, __const wchar_t *__needle)
     throw () __attribute__ ((__pure__));



extern wchar_t *wcstok (wchar_t *__restrict __s,
                        __const wchar_t *__restrict __delim,
                        wchar_t **__restrict __ptr) throw ();


extern size_t wcslen (__const wchar_t *__s) throw () __attribute__ ((__pure__));



extern size_t wcsnlen (__const wchar_t *__s, size_t __maxlen)
     throw () __attribute__ ((__pure__));




extern wchar_t *wmemchr (__const wchar_t *__s, wchar_t __c, size_t __n)
     throw () __attribute__ ((__pure__));


extern int wmemcmp (__const wchar_t *__restrict __s1,
                    __const wchar_t *__restrict __s2, size_t __n)
     throw () __attribute__ ((__pure__));


extern wchar_t *wmemcpy (wchar_t *__restrict __s1,
                         __const wchar_t *__restrict __s2, size_t __n) throw ();



extern wchar_t *wmemmove (wchar_t *__s1, __const wchar_t *__s2, size_t __n)
     throw ();


extern wchar_t *wmemset (wchar_t *__s, wchar_t __c, size_t __n) throw ();




extern wchar_t *wmempcpy (wchar_t *__restrict __s1,
                          __const wchar_t *__restrict __s2, size_t __n)
     throw ();





extern wint_t btowc (int __c) throw ();



extern int wctob (wint_t __c) throw ();



extern int mbsinit (__const mbstate_t *__ps) throw ();



extern size_t mbrtowc (wchar_t *__restrict __pwc,
                       __const char *__restrict __s, size_t __n,
                       mbstate_t *__p) throw ();


extern size_t wcrtomb (char *__restrict __s, wchar_t __wc,
                       mbstate_t *__restrict __ps) throw ();


extern size_t __mbrlen (__const char *__restrict __s, size_t __n,
                        mbstate_t *__restrict __ps) throw ();
extern size_t mbrlen (__const char *__restrict __s, size_t __n,
                      mbstate_t *__restrict __ps) throw ();



extern __inline size_t mbrlen (__const char *__restrict __s, size_t __n,
                               mbstate_t *__restrict __ps) throw ()
{ return (__ps != __null
          ? mbrtowc (__null, __s, __n, __ps) : __mbrlen (__s, __n, __null)); }




extern size_t mbsrtowcs (wchar_t *__restrict __dst,
                         __const char **__restrict __src, size_t __len,
                         mbstate_t *__restrict __ps) throw ();



extern size_t wcsrtombs (char *__restrict __dst,
                         __const wchar_t **__restrict __src, size_t __len,
                         mbstate_t *__restrict __ps) throw ();





extern size_t mbsnrtowcs (wchar_t *__restrict __dst,
                          __const char **__restrict __src, size_t __nmc,
                          size_t __len, mbstate_t *__restrict __ps) throw ();



extern size_t wcsnrtombs (char *__restrict __dst,
                          __const wchar_t **__restrict __src,
                          size_t __nwc, size_t __len,
                          mbstate_t *__restrict __ps) throw ();






extern int wcwidth (wchar_t __c) throw ();



extern int wcswidth (__const wchar_t *__s, size_t __n) throw ();





extern double wcstod (__const wchar_t *__restrict __nptr,
                      wchar_t **__restrict __endptr) throw ();



extern float wcstof (__const wchar_t *__restrict __nptr,
                     wchar_t **__restrict __endptr) throw ();
extern long double wcstold (__const wchar_t *__restrict __nptr,
                            wchar_t **__restrict __endptr) throw ();





extern long int wcstol (__const wchar_t *__restrict __nptr,
                        wchar_t **__restrict __endptr, int __base) throw ();



extern unsigned long int wcstoul (__const wchar_t *__restrict __nptr,
                                  wchar_t **__restrict __endptr, int __base)
     throw ();




__extension__
extern long long int wcstoq (__const wchar_t *__restrict __nptr,
                             wchar_t **__restrict __endptr, int __base)
     throw ();



__extension__
extern unsigned long long int wcstouq (__const wchar_t *__restrict __nptr,
                                       wchar_t **__restrict __endptr,
                                       int __base) throw ();





__extension__
extern long long int wcstoll (__const wchar_t *__restrict __nptr,
                              wchar_t **__restrict __endptr, int __base)
     throw ();



__extension__
extern unsigned long long int wcstoull (__const wchar_t *__restrict __nptr,
                                        wchar_t **__restrict __endptr,
                                        int __base) throw ();
# 406 "/usr/include/wchar.h" 3
# 1 "/usr/include/xlocale.h" 1 3
# 407 "/usr/include/wchar.h" 2 3



extern long int __wcstol_l (__const wchar_t *__restrict __nptr,
                            wchar_t **__restrict __endptr, int __base,
                            __locale_t __loc) throw ();

extern unsigned long int __wcstoul_l (__const wchar_t *__restrict __nptr,
                                      wchar_t **__restrict __endptr,
                                      int __base, __locale_t __loc) throw ();

__extension__
extern long long int __wcstoll_l (__const wchar_t *__restrict __nptr,
                                  wchar_t **__restrict __endptr,
                                  int __base, __locale_t __loc) throw ();

__extension__
extern unsigned long long int __wcstoull_l (__const wchar_t *__restrict __nptr,
                                            wchar_t **__restrict __endptr,
                                            int __base, __locale_t __loc)
     throw ();

extern double __wcstod_l (__const wchar_t *__restrict __nptr,
                          wchar_t **__restrict __endptr, __locale_t __loc)
     throw ();

extern float __wcstof_l (__const wchar_t *__restrict __nptr,
                         wchar_t **__restrict __endptr, __locale_t __loc)
     throw ();

extern long double __wcstold_l (__const wchar_t *__restrict __nptr,
                                wchar_t **__restrict __endptr,
                                __locale_t __loc) throw ();





extern double __wcstod_internal (__const wchar_t *__restrict __nptr,
                                 wchar_t **__restrict __endptr, int __group)
     throw ();
extern float __wcstof_internal (__const wchar_t *__restrict __nptr,
                                wchar_t **__restrict __endptr, int __group)
     throw ();
extern long double __wcstold_internal (__const wchar_t *__restrict __nptr,
                                       wchar_t **__restrict __endptr,
                                       int __group) throw ();


extern long int __wcstol_internal (__const wchar_t *__restrict __nptr,
                                   wchar_t **__restrict __endptr,
                                   int __base, int __group) throw ();



extern unsigned long int __wcstoul_internal (__const wchar_t *__restrict __npt,
                                             wchar_t **__restrict __endptr,
                                             int __base, int __group) throw ();



__extension__
extern long long int __wcstoll_internal (__const wchar_t *__restrict __nptr,
                                         wchar_t **__restrict __endptr,
                                         int __base, int __group) throw ();



__extension__
extern unsigned long long int __wcstoull_internal (__const wchar_t *
                                                   __restrict __nptr,
                                                   wchar_t **
                                                   __restrict __endptr,
                                                   int __base,
                                                   int __group) throw ();







extern __inline double wcstod (__const wchar_t *__restrict __nptr,
                               wchar_t **__restrict __endptr) throw ()
{ return __wcstod_internal (__nptr, __endptr, 0); }
extern __inline long int wcstol (__const wchar_t *__restrict __nptr,
                                 wchar_t **__restrict __endptr,
                                 int __base) throw ()
{ return __wcstol_internal (__nptr, __endptr, __base, 0); }
extern __inline unsigned long int wcstoul (__const wchar_t *__restrict __nptr,
                                           wchar_t **__restrict __endptr,
                                           int __base) throw ()
{ return __wcstoul_internal (__nptr, __endptr, __base, 0); }


extern __inline float wcstof (__const wchar_t *__restrict __nptr,
                              wchar_t **__restrict __endptr) throw ()
{ return __wcstof_internal (__nptr, __endptr, 0); }
extern __inline long double wcstold (__const wchar_t *__restrict __nptr,
                                     wchar_t **__restrict __endptr) throw ()
{ return __wcstold_internal (__nptr, __endptr, 0); }


__extension__
extern __inline long long int wcstoq (__const wchar_t *__restrict __nptr,
                                      wchar_t **__restrict __endptr,
                                      int __base) throw ()
{ return __wcstoll_internal (__nptr, __endptr, __base, 0); }
__extension__
extern __inline unsigned long long int wcstouq (__const wchar_t *
                                                __restrict __nptr,
                                                wchar_t **__restrict __endptr,
                                                int __base) throw ()
{ return __wcstoull_internal (__nptr, __endptr, __base, 0); }







extern wchar_t *wcpcpy (wchar_t *__dest, __const wchar_t *__src) throw ();



extern wchar_t *wcpncpy (wchar_t *__dest, __const wchar_t *__src, size_t __n)
     throw ();







extern int fwide (__FILE *__fp, int __mode) throw ();



extern int fwprintf (__FILE *__restrict __stream,
                     __const wchar_t *__restrict __format, ...)
     throw () ;

extern int wprintf (__const wchar_t *__restrict __format, ...)
     throw () ;

extern int swprintf (wchar_t *__restrict __s, size_t __n,
                     __const wchar_t *__restrict __format, ...)
     throw () ;


extern int vfwprintf (__FILE *__restrict __s,
                      __const wchar_t *__restrict __format,
                      __gnuc_va_list __arg)
     throw () ;

extern int vwprintf (__const wchar_t *__restrict __format,
                     __gnuc_va_list __arg)
     throw () ;


extern int vswprintf (wchar_t *__restrict __s, size_t __n,
                      __const wchar_t *__restrict __format,
                      __gnuc_va_list __arg)
     throw () ;



extern int fwscanf (__FILE *__restrict __stream,
                    __const wchar_t *__restrict __format, ...)
     throw () ;

extern int wscanf (__const wchar_t *__restrict __format, ...)
     throw () ;

extern int swscanf (__const wchar_t *__restrict __s,
                    __const wchar_t *__restrict __format, ...)
     throw () ;




extern int vfwscanf (__FILE *__restrict __s,
                     __const wchar_t *__restrict __format,
                     __gnuc_va_list __arg)
     throw () ;

extern int vwscanf (__const wchar_t *__restrict __format,
                    __gnuc_va_list __arg)
     throw () ;

extern int vswscanf (__const wchar_t *__restrict __s,
                     __const wchar_t *__restrict __format,
                     __gnuc_va_list __arg)
     throw () ;




extern wint_t fgetwc (__FILE *__stream) throw ();
extern wint_t getwc (__FILE *__stream) throw ();


extern wint_t getwchar (void) throw ();



extern wint_t fputwc (wchar_t __wc, __FILE *__stream) throw ();
extern wint_t putwc (wchar_t __wc, __FILE *__stream) throw ();


extern wint_t putwchar (wchar_t __wc) throw ();




extern wchar_t *fgetws (wchar_t *__restrict __ws, int __n,
                        __FILE *__restrict __stream) throw ();


extern int fputws (__const wchar_t *__restrict __ws,
                   __FILE *__restrict __stream) throw ();



extern wint_t ungetwc (wint_t __wc, __FILE *__stream) throw ();





extern wint_t getwc_unlocked (__FILE *__stream) throw ();
extern wint_t getwchar_unlocked (void) throw ();


extern wint_t fgetwc_unlocked (__FILE *__stream) throw ();


extern wint_t fputwc_unlocked (wchar_t __wc, __FILE *__stream) throw ();



extern wint_t putwc_unlocked (wchar_t __wc, __FILE *__stream) throw ();
extern wint_t putwchar_unlocked (wchar_t __wc) throw ();



extern wchar_t *fgetws_unlocked (wchar_t *__restrict __ws, int __n,
                                 __FILE *__restrict __stream) throw ();


extern int fputws_unlocked (__const wchar_t *__restrict __ws,
                            __FILE *__restrict __stream) throw ();






extern size_t wcsftime (wchar_t *__restrict __s, size_t __maxsize,
                        __const wchar_t *__restrict __format,
                        __const struct tm *__restrict __tp) throw ();
# 680 "/usr/include/wchar.h" 3
}
# 44 "/usr/local/include/g++-v3/bits/std_cwchar.h" 2 3
# 58 "/usr/local/include/g++-v3/bits/std_cwchar.h" 3
namespace std
{
  using ::mbstate_t;
}
# 122 "/usr/local/include/g++-v3/bits/std_cwchar.h" 3
namespace std
{
  using ::wint_t;

  using ::btowc;
  using ::fgetwc;
  using ::fgetws;
  using ::fputwc;
  using ::fputws;
  using ::fwide;
  using ::fwprintf;
  using ::fwscanf;
  using ::getwc;
  using ::getwchar;
  using ::mbrlen;
  using ::mbrtowc;
  using ::mbsinit;
  using ::mbsrtowcs;
  using ::putwc;
  using ::putwchar;
  using ::swprintf;
  using ::swscanf;
  using ::ungetwc;
  using ::vfwprintf;
  using ::vfwscanf;
  using ::vswprintf;
  using ::vswscanf;
  using ::vwprintf;
  using ::vwscanf;
  using ::wcrtomb;
  using ::wcscat;
  using ::wcscmp;
  using ::wcscoll;
  using ::wcscpy;
  using ::wcscspn;
  using ::wcsftime;
  using ::wcslen;
  using ::wcsncat;
  using ::wcsncmp;
  using ::wcsncpy;
  using ::wcsrtombs;
  using ::wcsspn;
  using ::wcstod;
  using ::wcstof;
  using ::wcstok;
  using ::wcstol;
  using ::wcstoul;
  using ::wcsxfrm;
  using ::wctob;
  using ::wmemcmp;
  using ::wmemcpy;
  using ::wmemmove;
  using ::wmemset;
  using ::wprintf;
  using ::wscanf;

  using ::wcschr;

  inline wchar_t*
  wcschr(wchar_t* __p, wchar_t __c)
  { return wcschr(const_cast<const wchar_t*>(__p), __c); }

  using ::wcspbrk;

  inline wchar_t*
  wcspbrk(wchar_t* __s1, wchar_t* __s2)
  { return wcspbrk(const_cast<const wchar_t*>(__s1), __s2); }

  using ::wcsrchr;

  inline wchar_t*
  wcsrchr(wchar_t* __p, wchar_t __c)
  { return wcsrchr(const_cast<const wchar_t*>(__p), __c); }

  using ::wcsstr;

  inline wchar_t*
  wcsstr(wchar_t* __s1, wchar_t* __s2)
  { return wcsstr(const_cast<const wchar_t*>(__s1), __s2); }

  using ::wmemchr;

  inline wchar_t*
  wmemchr(wchar_t* __p, wchar_t __c, size_t __n)
  { return wmemchr(const_cast<const wchar_t*>(__p), __c, __n); }
}







namespace __gnu_cxx
{
  using ::wcstold;
  using ::wcstoll;
  using ::wcstoull;
}

namespace std
{
  using __gnu_cxx::wcstold;
  using __gnu_cxx::wcstoll;
  using __gnu_cxx::wcstoull;
}
# 41 "/usr/local/include/g++-v3/bits/fpos.h" 2 3

namespace std
{



  template<typename _StateT>
    class fpos
    {
    public:

      typedef _StateT __state_type;

    private:
      streamoff _M_off;
      __state_type _M_st;

    public:
      __state_type
      state() const { return _M_st; }

      void
      state(__state_type __st) { _M_st = __st; }



      fpos(): _M_off(streamoff()), _M_st(__state_type()) { }

      fpos(streamoff __off, __state_type __st = __state_type())
      : _M_off(__off), _M_st(__st) { }

      operator streamoff() const { return _M_off; }

      fpos&
      operator+=(streamoff __off) { _M_off += __off; return *this; }

      fpos&
      operator-=(streamoff __off) { _M_off -= __off; return *this; }

      fpos
      operator+(streamoff __off)
      {
        fpos __t(*this);
        __t += __off;
        return __t;
      }

      fpos
      operator-(streamoff __off)
      {
        fpos __t(*this);
        __t -= __off;
        return __t;
      }

      bool
      operator==(const fpos& __pos) const
      { return _M_off == __pos._M_off; }

      bool
      operator!=(const fpos& __pos) const
      { return _M_off != __pos._M_off; }

      streamoff
      _M_position() const { return _M_off; }

      void
      _M_position(streamoff __off) { _M_off = __off; }
    };


  typedef fpos<mbstate_t> streampos;

  typedef fpos<mbstate_t> wstreampos;

}
# 42 "/usr/local/include/g++-v3/bits/std_iosfwd.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/functexcept.h" 1 3
# 34 "/usr/local/include/g++-v3/bits/functexcept.h" 3
# 1 "/usr/local/include/g++-v3/exception_defines.h" 1 3
# 35 "/usr/local/include/g++-v3/bits/functexcept.h" 2 3

namespace std
{

  void
  __throw_bad_exception(void);


  void
  __throw_bad_alloc(void);


  void
  __throw_bad_cast(void);

  void
  __throw_bad_typeid(void);


  void
  __throw_logic_error(const char* __s);

  void
  __throw_domain_error(const char* __s);

  void
  __throw_invalid_argument(const char* __s);

  void
  __throw_length_error(const char* __s);

  void
  __throw_out_of_range(const char* __s);

  void
  __throw_runtime_error(const char* __s);

  void
  __throw_range_error(const char* __s);

  void
  __throw_overflow_error(const char* __s);

  void
  __throw_underflow_error(const char* __s);


  void
  __throw_ios_failure(const char* __s);
}
# 43 "/usr/local/include/g++-v3/bits/std_iosfwd.h" 2 3

namespace std
{
  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_ios;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_streambuf;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_istream;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_ostream;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_iostream;

  template<typename _CharT, typename _Traits = char_traits<_CharT>,
            typename _Alloc = allocator<_CharT> >
    class basic_stringbuf;

  template<typename _CharT, typename _Traits = char_traits<_CharT>,
           typename _Alloc = allocator<_CharT> >
    class basic_istringstream;

  template<typename _CharT, typename _Traits = char_traits<_CharT>,
           typename _Alloc = allocator<_CharT> >
    class basic_ostringstream;

  template<typename _CharT, typename _Traits = char_traits<_CharT>,
           typename _Alloc = allocator<_CharT> >
    class basic_stringstream;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_filebuf;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_ifstream;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_ofstream;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_fstream;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class istreambuf_iterator;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class ostreambuf_iterator;



  class ios_base;


  typedef basic_ios<char> ios;
  typedef basic_streambuf<char> streambuf;
  typedef basic_istream<char> istream;
  typedef basic_ostream<char> ostream;
  typedef basic_iostream<char> iostream;
  typedef basic_stringbuf<char> stringbuf;
  typedef basic_istringstream<char> istringstream;
  typedef basic_ostringstream<char> ostringstream;
  typedef basic_stringstream<char> stringstream;
  typedef basic_filebuf<char> filebuf;
  typedef basic_ifstream<char> ifstream;
  typedef basic_ofstream<char> ofstream;
  typedef basic_fstream<char> fstream;


  typedef basic_ios<wchar_t> wios;
  typedef basic_streambuf<wchar_t> wstreambuf;
  typedef basic_istream<wchar_t> wistream;
  typedef basic_ostream<wchar_t> wostream;
  typedef basic_iostream<wchar_t> wiostream;
  typedef basic_stringbuf<wchar_t> wstringbuf;
  typedef basic_istringstream<wchar_t> wistringstream;
  typedef basic_ostringstream<wchar_t> wostringstream;
  typedef basic_stringstream<wchar_t> wstringstream;
  typedef basic_filebuf<wchar_t> wfilebuf;
  typedef basic_ifstream<wchar_t> wifstream;
  typedef basic_ofstream<wchar_t> wofstream;
  typedef basic_fstream<wchar_t> wfstream;

}
# 40 "/usr/local/include/g++-v3/bits/std_ios.h" 2 3
# 1 "/usr/local/include/g++-v3/exception" 1 3
# 41 "/usr/local/include/g++-v3/bits/std_ios.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/char_traits.h" 1 3
# 38 "/usr/local/include/g++-v3/bits/char_traits.h" 3

# 1 "/usr/local/include/g++-v3/bits/std_cstring.h" 1 3
# 37 "/usr/local/include/g++-v3/bits/std_cstring.h" 3
# 1 "/usr/local/include/g++-v3/bits/std_cstddef.h" 1 3
# 38 "/usr/local/include/g++-v3/bits/std_cstring.h" 2 3
# 40 "/usr/local/include/g++-v3/bits/std_cstring.h" 3
# 1 "/usr/include/string.h" 1 3
# 41 "/usr/local/include/g++-v3/bits/std_cstring.h" 2 3
# 66 "/usr/local/include/g++-v3/bits/std_cstring.h" 3
namespace std
{
  using ::memcpy;
  using ::memmove;
  using ::strcpy;
  using ::strncpy;
  using ::strcat;
  using ::strncat;
  using ::memcmp;
  using ::strcmp;
  using ::strcoll;
  using ::strncmp;
  using ::strxfrm;
  using ::strcspn;
  using ::strspn;
  using ::strtok;
  using ::memset;
  using ::strerror;
  using ::strlen;

  using ::memchr;

  inline void*
  memchr(void* __p, int __c, size_t __n)
  { return memchr(const_cast<const void*>(__p), __c, __n); }

  using ::strchr;

  inline char*
  strchr(char* __s1, int __n)
  { return __builtin_strchr(const_cast<const char*>(__s1), __n); }

  using ::strpbrk;

  inline char*
  strpbrk(char* __s1, const char* __s2)
  { return __builtin_strpbrk(const_cast<const char*>(__s1), __s2); }

  using ::strrchr;

  inline char*
  strrchr(char* __s1, int __n)
  { return __builtin_strrchr(const_cast<const char*>(__s1), __n); }

  using ::strstr;

  inline char*
  strstr(char* __s1, const char* __s2)
  { return __builtin_strstr(const_cast<const char*>(__s1), __s2); }
}
# 40 "/usr/local/include/g++-v3/bits/char_traits.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/fpos.h" 1 3
# 41 "/usr/local/include/g++-v3/bits/char_traits.h" 2 3

namespace std
{



  template<class _CharT>
    struct char_traits
    {
      typedef _CharT char_type;

      typedef unsigned long int_type;
      typedef streampos pos_type;
      typedef streamoff off_type;
      typedef mbstate_t state_type;

      static void
      assign(char_type& __c1, const char_type& __c2)
      { __c1 = __c2; }

      static bool
      eq(const char_type& __c1, const char_type& __c2)
      { return __c1 == __c2; }

      static bool
      lt(const char_type& __c1, const char_type& __c2)
      { return __c1 < __c2; }

      static int
      compare(const char_type* __s1, const char_type* __s2, size_t __n)
      {
        for (size_t __i = 0; __i < __n; ++__i)
          if (!eq(__s1[__i], __s2[__i]))
            return lt(__s1[__i], __s2[__i]) ? -1 : 1;
        return 0;
      }

      static size_t
      length(const char_type* __s)
      {
        const char_type* __p = __s;
        while (*__p) ++__p;
        return (__p - __s);
      }

      static const char_type*
      find(const char_type* __s, size_t __n, const char_type& __a)
      {
        for (const char_type* __p = __s; size_t(__p - __s) < __n; ++__p)
          if (*__p == __a) return __p;
        return 0;
      }

      static char_type*
      move(char_type* __s1, const char_type* __s2, size_t __n)
      { return (char_type*) memmove(__s1, __s2, __n * sizeof(char_type)); }

      static char_type*
      copy(char_type* __s1, const char_type* __s2, size_t __n)
      { return (char_type*) memcpy(__s1, __s2, __n * sizeof(char_type)); }

      static char_type*
      assign(char_type* __s, size_t __n, char_type __a)
      {
        for (char_type* __p = __s; __p < __s + __n; ++__p)
          assign(*__p, __a);
        return __s;
      }

      static char_type
      to_char_type(const int_type& __c)
      { return char_type(__c); }

      static int_type
      to_int_type(const char_type& __c) { return int_type(__c); }

      static bool
      eq_int_type(const int_type& __c1, const int_type& __c2)
      { return __c1 == __c2; }

      static int_type
      eof() { return static_cast<int_type>(-1); }

      static int_type
      not_eof(const int_type& __c)
      { return eq_int_type(__c, eof()) ? int_type(0) : __c; }
    };



  template<>
    struct char_traits<char>
    {
      typedef char char_type;
      typedef int int_type;
      typedef streampos pos_type;
      typedef streamoff off_type;
      typedef mbstate_t state_type;

      static void
      assign(char_type& __c1, const char_type& __c2)
      { __c1 = __c2; }

      static bool
      eq(const char_type& __c1, const char_type& __c2)
      { return __c1 == __c2; }

      static bool
      lt(const char_type& __c1, const char_type& __c2)
      { return __c1 < __c2; }

      static int
      compare(const char_type* __s1, const char_type* __s2, size_t __n)
      { return memcmp(__s1, __s2, __n); }

      static size_t
      length(const char_type* __s)
      { return strlen(__s); }

      static const char_type*
      find(const char_type* __s, size_t __n, const char_type& __a)
      { return static_cast<const char_type*>(memchr(__s, __a, __n)); }

      static char_type*
      move(char_type* __s1, const char_type* __s2, size_t __n)
      { return static_cast<char_type*>(memmove(__s1, __s2, __n)); }

      static char_type*
      copy(char_type* __s1, const char_type* __s2, size_t __n)
      { return static_cast<char_type*>(memcpy(__s1, __s2, __n)); }

      static char_type*
      assign(char_type* __s, size_t __n, char_type __a)
      { return static_cast<char_type*>(memset(__s, __a, __n)); }

      static char_type
      to_char_type(const int_type& __c)
      { return static_cast<char_type>(__c); }



      static int_type
      to_int_type(const char_type& __c)
      { return static_cast<int_type>(static_cast<unsigned char>(__c)); }

      static bool
      eq_int_type(const int_type& __c1, const int_type& __c2)
      { return __c1 == __c2; }

      static int_type
      eof() { return static_cast<int_type>((-1)); }

      static int_type
      not_eof(const int_type& __c)
      { return (__c == eof()) ? 0 : __c; }
  };



  template<>
    struct char_traits<wchar_t>
    {
      typedef wchar_t char_type;
      typedef wint_t int_type;
      typedef streamoff off_type;
      typedef wstreampos pos_type;
      typedef mbstate_t state_type;

      static void
      assign(char_type& __c1, const char_type& __c2)
      { __c1 = __c2; }

      static bool
      eq(const char_type& __c1, const char_type& __c2)
      { return __c1 == __c2; }

      static bool
      lt(const char_type& __c1, const char_type& __c2)
      { return __c1 < __c2; }

      static int
      compare(const char_type* __s1, const char_type* __s2, size_t __n)
      { return wmemcmp(__s1, __s2, __n); }

      static size_t
      length(const char_type* __s)
      { return wcslen(__s); }

      static const char_type*
      find(const char_type* __s, size_t __n, const char_type& __a)
      { return wmemchr(__s, __a, __n); }

      static char_type*
      move(char_type* __s1, const char_type* __s2, int_type __n)
      { return wmemmove(__s1, __s2, __n); }

      static char_type*
      copy(char_type* __s1, const char_type* __s2, size_t __n)
      { return wmemcpy(__s1, __s2, __n); }

      static char_type*
      assign(char_type* __s, size_t __n, char_type __a)
      { return wmemset(__s, __a, __n); }

      static char_type
      to_char_type(const int_type& __c) { return char_type(__c); }

      static int_type
      to_int_type(const char_type& __c) { return int_type(__c); }

      static bool
      eq_int_type(const int_type& __c1, const int_type& __c2)
      { return __c1 == __c2; }

      static int_type
      eof() { return static_cast<int_type>((0xffffffffu)); }

      static int_type
      not_eof(const int_type& __c)
      { return eq_int_type(__c, eof()) ? 0 : __c; }
  };


  template<typename _CharT, typename _Traits>
    struct _Char_traits_match
    {
      _CharT _M_c;
      _Char_traits_match(_CharT const& __c) : _M_c(__c) { }

      bool
      operator()(_CharT const& __a) { return _Traits::eq(_M_c, __a); }
    };
}
# 42 "/usr/local/include/g++-v3/bits/std_ios.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_cstdio.h" 1 3
# 43 "/usr/local/include/g++-v3/bits/std_ios.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/localefwd.h" 1 3
# 38 "/usr/local/include/g++-v3/bits/localefwd.h" 3

# 1 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/c++config.h" 1 3
# 40 "/usr/local/include/g++-v3/bits/localefwd.h" 2 3
# 1 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/c++locale.h" 1 3
# 36 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/c++locale.h" 3
namespace std
{
  typedef int* __c_locale;
}
# 41 "/usr/local/include/g++-v3/bits/localefwd.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_climits.h" 1 3
# 38 "/usr/local/include/g++-v3/bits/std_climits.h" 3
# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/limits.h" 1 3
# 39 "/usr/local/include/g++-v3/bits/std_climits.h" 2 3
# 42 "/usr/local/include/g++-v3/bits/localefwd.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_string.h" 1 3
# 38 "/usr/local/include/g++-v3/bits/std_string.h" 3

# 1 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/c++config.h" 1 3
# 40 "/usr/local/include/g++-v3/bits/std_string.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/stringfwd.h" 1 3
# 41 "/usr/local/include/g++-v3/bits/std_string.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/char_traits.h" 1 3
# 42 "/usr/local/include/g++-v3/bits/std_string.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_iterator.h" 1 3
# 60 "/usr/local/include/g++-v3/bits/std_iterator.h" 3
# 1 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/c++config.h" 1 3
# 61 "/usr/local/include/g++-v3/bits/std_iterator.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_cstddef.h" 1 3
# 62 "/usr/local/include/g++-v3/bits/std_iterator.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_iosfwd.h" 1 3
# 63 "/usr/local/include/g++-v3/bits/std_iterator.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/stl_iterator_base_types.h" 1 3
# 69 "/usr/local/include/g++-v3/bits/stl_iterator_base_types.h" 3

# 1 "/usr/local/include/g++-v3/bits/std_cstddef.h" 1 3
# 71 "/usr/local/include/g++-v3/bits/stl_iterator_base_types.h" 2 3


namespace std
{

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};






template <class _Tp, class _Distance> struct input_iterator {
  typedef input_iterator_tag iterator_category;
  typedef _Tp value_type;
  typedef _Distance difference_type;
  typedef _Tp* pointer;
  typedef _Tp& reference;
};

struct output_iterator {
  typedef output_iterator_tag iterator_category;
  typedef void value_type;
  typedef void difference_type;
  typedef void pointer;
  typedef void reference;
};

template <class _Tp, class _Distance> struct forward_iterator {
  typedef forward_iterator_tag iterator_category;
  typedef _Tp value_type;
  typedef _Distance difference_type;
  typedef _Tp* pointer;
  typedef _Tp& reference;
};


template <class _Tp, class _Distance> struct bidirectional_iterator {
  typedef bidirectional_iterator_tag iterator_category;
  typedef _Tp value_type;
  typedef _Distance difference_type;
  typedef _Tp* pointer;
  typedef _Tp& reference;
};

template <class _Tp, class _Distance> struct random_access_iterator {
  typedef random_access_iterator_tag iterator_category;
  typedef _Tp value_type;
  typedef _Distance difference_type;
  typedef _Tp* pointer;
  typedef _Tp& reference;
};

template <class _Category, class _Tp, class _Distance = ptrdiff_t,
          class _Pointer = _Tp*, class _Reference = _Tp&>
struct iterator {
  typedef _Category iterator_category;
  typedef _Tp value_type;
  typedef _Distance difference_type;
  typedef _Pointer pointer;
  typedef _Reference reference;
};

template <class _Iterator>
struct iterator_traits {
  typedef typename _Iterator::iterator_category iterator_category;
  typedef typename _Iterator::value_type value_type;
  typedef typename _Iterator::difference_type difference_type;
  typedef typename _Iterator::pointer pointer;
  typedef typename _Iterator::reference reference;
};

template <class _Tp>
struct iterator_traits<_Tp*> {
  typedef random_access_iterator_tag iterator_category;
  typedef _Tp value_type;
  typedef ptrdiff_t difference_type;
  typedef _Tp* pointer;
  typedef _Tp& reference;
};

template <class _Tp>
struct iterator_traits<const _Tp*> {
  typedef random_access_iterator_tag iterator_category;
  typedef _Tp value_type;
  typedef ptrdiff_t difference_type;
  typedef const _Tp* pointer;
  typedef const _Tp& reference;
};
# 172 "/usr/local/include/g++-v3/bits/stl_iterator_base_types.h" 3
template <class _Iter>
inline typename iterator_traits<_Iter>::iterator_category
__iterator_category(const _Iter&)
{
  typedef typename iterator_traits<_Iter>::iterator_category _Category;
  return _Category();
}

template <class _Iter>
inline typename iterator_traits<_Iter>::difference_type*
__distance_type(const _Iter&)
{
  return static_cast<typename iterator_traits<_Iter>::difference_type*>(0);
}

template <class _Iter>
inline typename iterator_traits<_Iter>::value_type*
__value_type(const _Iter&)
{
  return static_cast<typename iterator_traits<_Iter>::value_type*>(0);
}

template <class _Iter>
inline typename iterator_traits<_Iter>::iterator_category
iterator_category(const _Iter& __i) { return __iterator_category(__i); }


template <class _Iter>
inline typename iterator_traits<_Iter>::difference_type*
distance_type(const _Iter& __i) { return __distance_type(__i); }

template <class _Iter>
inline typename iterator_traits<_Iter>::value_type*
value_type(const _Iter& __i) { return __value_type(__i); }

}
# 64 "/usr/local/include/g++-v3/bits/std_iterator.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/stl_iterator_base_funcs.h" 1 3
# 69 "/usr/local/include/g++-v3/bits/stl_iterator_base_funcs.h" 3
# 1 "/usr/local/include/g++-v3/bits/concept_check.h" 1 3
# 34 "/usr/local/include/g++-v3/bits/concept_check.h" 3

# 1 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/c++config.h" 1 3
# 36 "/usr/local/include/g++-v3/bits/concept_check.h" 2 3
# 70 "/usr/local/include/g++-v3/bits/stl_iterator_base_funcs.h" 2 3

namespace std
{





template <class _InputIterator, class _Distance>
inline void __distance(_InputIterator __first, _InputIterator __last,
                       _Distance& __n, input_iterator_tag)
{

                                                                    ;
  while (__first != __last) { ++__first; ++__n; }
}

template <class _RandomAccessIterator, class _Distance>
inline void __distance(_RandomAccessIterator __first,
                       _RandomAccessIterator __last,
                       _Distance& __n, random_access_iterator_tag)
{

                                                                                  ;
  __n += __last - __first;
}

template <class _InputIterator, class _Distance>
inline void distance(_InputIterator __first,
                     _InputIterator __last, _Distance& __n)
{

  __distance(__first, __last, __n, iterator_category(__first));
}

template <class _InputIterator>
inline typename iterator_traits<_InputIterator>::difference_type
__distance(_InputIterator __first, _InputIterator __last, input_iterator_tag)
{

                                                                    ;
  typename iterator_traits<_InputIterator>::difference_type __n = 0;
  while (__first != __last) {
    ++__first; ++__n;
  }
  return __n;
}

template <class _RandomAccessIterator>
inline typename iterator_traits<_RandomAccessIterator>::difference_type
__distance(_RandomAccessIterator __first, _RandomAccessIterator __last,
           random_access_iterator_tag)
{

                                                                                  ;
  return __last - __first;
}

template <class _InputIterator>
inline typename iterator_traits<_InputIterator>::difference_type
distance(_InputIterator __first, _InputIterator __last)
{

  typedef typename iterator_traits<_InputIterator>::iterator_category
    _Category;
  return __distance(__first, __last, _Category());
}

template <class _InputIter, class _Distance>
inline void __advance(_InputIter& __i, _Distance __n, input_iterator_tag)
{

                                                                ;
  while (__n--) ++__i;
}

template <class _BidirectionalIterator, class _Distance>
inline void __advance(_BidirectionalIterator& __i, _Distance __n,
                      bidirectional_iterator_tag)
{

                                                                                  ;
  if (__n > 0)
    while (__n--) ++__i;
  else
    while (__n++) --__i;
}

template <class _RandomAccessIterator, class _Distance>
inline void __advance(_RandomAccessIterator& __i, _Distance __n,
                      random_access_iterator_tag)
{

                                                                                  ;
  __i += __n;
}

template <class _InputIterator, class _Distance>
inline void advance(_InputIterator& __i, _Distance __n)
{

  __advance(__i, __n, iterator_category(__i));
}

}
# 65 "/usr/local/include/g++-v3/bits/std_iterator.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/stl_iterator.h" 1 3
# 63 "/usr/local/include/g++-v3/bits/stl_iterator.h" 3
namespace std
{

template <class _Container>
class back_insert_iterator {
protected:
  _Container* container;
public:
  typedef _Container container_type;
  typedef output_iterator_tag iterator_category;
  typedef void value_type;
  typedef void difference_type;
  typedef void pointer;
  typedef void reference;

  explicit back_insert_iterator(_Container& __x) : container(&__x) {}
  back_insert_iterator<_Container>&
  operator=(const typename _Container::value_type& __value) {
    container->push_back(__value);
    return *this;
  }
  back_insert_iterator<_Container>& operator*() { return *this; }
  back_insert_iterator<_Container>& operator++() { return *this; }
  back_insert_iterator<_Container>& operator++(int) { return *this; }
};

template <class _Container>
inline back_insert_iterator<_Container> back_inserter(_Container& __x) {
  return back_insert_iterator<_Container>(__x);
}

template <class _Container>
class front_insert_iterator {
protected:
  _Container* container;
public:
  typedef _Container container_type;
  typedef output_iterator_tag iterator_category;
  typedef void value_type;
  typedef void difference_type;
  typedef void pointer;
  typedef void reference;

  explicit front_insert_iterator(_Container& __x) : container(&__x) {}
  front_insert_iterator<_Container>&
  operator=(const typename _Container::value_type& __value) {
    container->push_front(__value);
    return *this;
  }
  front_insert_iterator<_Container>& operator*() { return *this; }
  front_insert_iterator<_Container>& operator++() { return *this; }
  front_insert_iterator<_Container>& operator++(int) { return *this; }
};

template <class _Container>
inline front_insert_iterator<_Container> front_inserter(_Container& __x) {
  return front_insert_iterator<_Container>(__x);
}

template <class _Container>
class insert_iterator {
protected:
  _Container* container;
  typename _Container::iterator iter;
public:
  typedef _Container container_type;
  typedef output_iterator_tag iterator_category;
  typedef void value_type;
  typedef void difference_type;
  typedef void pointer;
  typedef void reference;

  insert_iterator(_Container& __x, typename _Container::iterator __i)
    : container(&__x), iter(__i) {}
  insert_iterator<_Container>&
  operator=(const typename _Container::value_type& __value) {
    iter = container->insert(iter, __value);
    ++iter;
    return *this;
  }
  insert_iterator<_Container>& operator*() { return *this; }
  insert_iterator<_Container>& operator++() { return *this; }
  insert_iterator<_Container>& operator++(int) { return *this; }
};

template <class _Container, class _Iterator>
inline
insert_iterator<_Container> inserter(_Container& __x, _Iterator __i)
{
  typedef typename _Container::iterator __iter;
  return insert_iterator<_Container>(__x, __iter(__i));
}

template <class _BidirectionalIterator, class _Tp, class _Reference = _Tp&,
          class _Distance = ptrdiff_t>
class reverse_bidirectional_iterator {
  typedef reverse_bidirectional_iterator<_BidirectionalIterator, _Tp,
                                         _Reference, _Distance> _Self;
protected:
  _BidirectionalIterator current;
public:
  typedef bidirectional_iterator_tag iterator_category;
  typedef _Tp value_type;
  typedef _Distance difference_type;
  typedef _Tp* pointer;
  typedef _Reference reference;

  reverse_bidirectional_iterator() {}
  explicit reverse_bidirectional_iterator(_BidirectionalIterator __x)
    : current(__x) {}
  _BidirectionalIterator base() const { return current; }
  _Reference operator*() const {
    _BidirectionalIterator __tmp = current;
    return *--__tmp;
  }
  pointer operator->() const { return &(operator*()); }
  _Self& operator++() {
    --current;
    return *this;
  }
  _Self operator++(int) {
    _Self __tmp = *this;
    --current;
    return __tmp;
  }
  _Self& operator--() {
    ++current;
    return *this;
  }
  _Self operator--(int) {
    _Self __tmp = *this;
    ++current;
    return __tmp;
  }
};

template <class _BiIter, class _Tp, class _Ref, class _Distance>
inline bool operator==(
    const reverse_bidirectional_iterator<_BiIter, _Tp, _Ref, _Distance>& __x,
    const reverse_bidirectional_iterator<_BiIter, _Tp, _Ref, _Distance>& __y)
{
  return __x.base() == __y.base();
}

template <class _BiIter, class _Tp, class _Ref, class _Distance>
inline bool operator!=(
    const reverse_bidirectional_iterator<_BiIter, _Tp, _Ref, _Distance>& __x,
    const reverse_bidirectional_iterator<_BiIter, _Tp, _Ref, _Distance>& __y)
{
  return !(__x == __y);
}
# 222 "/usr/local/include/g++-v3/bits/stl_iterator.h" 3
template <class _Iterator>
class reverse_iterator
{
protected:
  _Iterator current;
public:
  typedef typename iterator_traits<_Iterator>::iterator_category
          iterator_category;
  typedef typename iterator_traits<_Iterator>::value_type
          value_type;
  typedef typename iterator_traits<_Iterator>::difference_type
          difference_type;
  typedef typename iterator_traits<_Iterator>::pointer
          pointer;
  typedef typename iterator_traits<_Iterator>::reference
          reference;

  typedef _Iterator iterator_type;
  typedef reverse_iterator<_Iterator> _Self;

public:
  reverse_iterator() {}
  explicit reverse_iterator(iterator_type __x) : current(__x) {}

  reverse_iterator(const _Self& __x) : current(__x.current) {}
  template <class _Iter>
  reverse_iterator(const reverse_iterator<_Iter>& __x)
    : current(__x.base()) {}

  iterator_type base() const { return current; }
  reference operator*() const {
    _Iterator __tmp = current;
    return *--__tmp;
  }
  pointer operator->() const { return &(operator*()); }

  _Self& operator++() {
    --current;
    return *this;
  }
  _Self operator++(int) {
    _Self __tmp = *this;
    --current;
    return __tmp;
  }
  _Self& operator--() {
    ++current;
    return *this;
  }
  _Self operator--(int) {
    _Self __tmp = *this;
    ++current;
    return __tmp;
  }

  _Self operator+(difference_type __n) const {
    return _Self(current - __n);
  }
  _Self& operator+=(difference_type __n) {
    current -= __n;
    return *this;
  }
  _Self operator-(difference_type __n) const {
    return _Self(current + __n);
  }
  _Self& operator-=(difference_type __n) {
    current += __n;
    return *this;
  }
  reference operator[](difference_type __n) const { return *(*this + __n); }
};

template <class _Iterator>
inline bool operator==(const reverse_iterator<_Iterator>& __x,
                       const reverse_iterator<_Iterator>& __y) {
  return __x.base() == __y.base();
}

template <class _Iterator>
inline bool operator<(const reverse_iterator<_Iterator>& __x,
                      const reverse_iterator<_Iterator>& __y) {
  return __y.base() < __x.base();
}

template <class _Iterator>
inline bool operator!=(const reverse_iterator<_Iterator>& __x,
                       const reverse_iterator<_Iterator>& __y) {
  return !(__x == __y);
}

template <class _Iterator>
inline bool operator>(const reverse_iterator<_Iterator>& __x,
                      const reverse_iterator<_Iterator>& __y) {
  return __y < __x;
}

template <class _Iterator>
inline bool operator<=(const reverse_iterator<_Iterator>& __x,
                       const reverse_iterator<_Iterator>& __y) {
  return !(__y < __x);
}

template <class _Iterator>
inline bool operator>=(const reverse_iterator<_Iterator>& __x,
                      const reverse_iterator<_Iterator>& __y) {
  return !(__x < __y);
}

template <class _Iterator>
inline typename reverse_iterator<_Iterator>::difference_type
operator-(const reverse_iterator<_Iterator>& __x,
          const reverse_iterator<_Iterator>& __y) {
  return __y.base() - __x.base();
}

template <class _Iterator>
inline reverse_iterator<_Iterator>
operator+(typename reverse_iterator<_Iterator>::difference_type __n,
          const reverse_iterator<_Iterator>& __x) {
  return reverse_iterator<_Iterator>(__x.base() - __n);
}


template <class _Tp,
          class _CharT = char, class _Traits = char_traits<_CharT>,
          class _Dist = ptrdiff_t>
class istream_iterator {
public:
  typedef _CharT char_type;
  typedef _Traits traits_type;
  typedef basic_istream<_CharT, _Traits> istream_type;

  typedef input_iterator_tag iterator_category;
  typedef _Tp value_type;
  typedef _Dist difference_type;
  typedef const _Tp* pointer;
  typedef const _Tp& reference;

  istream_iterator() : _M_stream(0), _M_ok(false) {}
  istream_iterator(istream_type& __s) : _M_stream(&__s) { _M_read(); }

  reference operator*() const { return _M_value; }
  pointer operator->() const { return &(operator*()); }

  istream_iterator& operator++() {
    _M_read();
    return *this;
  }
  istream_iterator operator++(int) {
    istream_iterator __tmp = *this;
    _M_read();
    return __tmp;
  }

  bool _M_equal(const istream_iterator& __x) const
    { return (_M_ok == __x._M_ok) && (!_M_ok || _M_stream == __x._M_stream); }

private:
  istream_type* _M_stream;
  _Tp _M_value;
  bool _M_ok;

  void _M_read() {
    _M_ok = (_M_stream && *_M_stream) ? true : false;
    if (_M_ok) {
      *_M_stream >> _M_value;
      _M_ok = *_M_stream ? true : false;
    }
  }
};

template <class _Tp, class _CharT, class _Traits, class _Dist>
inline bool
operator==(const istream_iterator<_Tp, _CharT, _Traits, _Dist>& __x,
           const istream_iterator<_Tp, _CharT, _Traits, _Dist>& __y) {
  return __x._M_equal(__y);
}

template <class _Tp, class _CharT, class _Traits, class _Dist>
inline bool
operator!=(const istream_iterator<_Tp, _CharT, _Traits, _Dist>& __x,
           const istream_iterator<_Tp, _CharT, _Traits, _Dist>& __y) {
  return !__x._M_equal(__y);
}


template <class _Tp,
          class _CharT = char, class _Traits = char_traits<_CharT> >
class ostream_iterator {
public:
  typedef _CharT char_type;
  typedef _Traits traits_type;
  typedef basic_ostream<_CharT, _Traits> ostream_type;

  typedef output_iterator_tag iterator_category;
  typedef void value_type;
  typedef void difference_type;
  typedef void pointer;
  typedef void reference;

  ostream_iterator(ostream_type& __s) : _M_stream(&__s), _M_string(0) {}
  ostream_iterator(ostream_type& __s, const _CharT* __c)
    : _M_stream(&__s), _M_string(__c) {}
  ostream_iterator<_Tp>& operator=(const _Tp& __value) {
    *_M_stream << __value;
    if (_M_string) *_M_stream << _M_string;
    return *this;
  }
  ostream_iterator<_Tp>& operator*() { return *this; }
  ostream_iterator<_Tp>& operator++() { return *this; }
  ostream_iterator<_Tp>& operator++(int) { return *this; }
private:
  ostream_type* _M_stream;
  const _CharT* _M_string;
};
# 446 "/usr/local/include/g++-v3/bits/stl_iterator.h" 3
template<typename _Iterator, typename _Container>
class __normal_iterator
  : public iterator<iterator_traits<_Iterator>::iterator_category,
                    iterator_traits<_Iterator>::value_type,
                    iterator_traits<_Iterator>::difference_type,
                    iterator_traits<_Iterator>::pointer,
                    iterator_traits<_Iterator>::reference>
{

protected:
  _Iterator _M_current;

public:
  typedef __normal_iterator<_Iterator, _Container> normal_iterator_type;
  typedef iterator_traits<_Iterator> __traits_type;
  typedef typename __traits_type::iterator_category iterator_category;
  typedef typename __traits_type::value_type value_type;
  typedef typename __traits_type::difference_type difference_type;
  typedef typename __traits_type::pointer pointer;
  typedef typename __traits_type::reference reference;

  __normal_iterator() : _M_current(_Iterator()) { }

  explicit __normal_iterator(const _Iterator& __i) : _M_current(__i) { }


  template<typename _Iter>
  inline __normal_iterator(const __normal_iterator<_Iter, _Container>& __i)
    : _M_current(__i.base()) { }


  reference
  operator*() const { return *_M_current; }

  pointer
  operator->() const { return _M_current; }

  normal_iterator_type&
  operator++() { ++_M_current; return *this; }

  normal_iterator_type
  operator++(int) { return __normal_iterator(_M_current++); }


  normal_iterator_type&
  operator--() { --_M_current; return *this; }

  normal_iterator_type
  operator--(int) { return __normal_iterator(_M_current--); }


  reference
  operator[](const difference_type& __n) const
  { return _M_current[__n]; }

  normal_iterator_type&
  operator+=(const difference_type& __n)
  { _M_current += __n; return *this; }

  normal_iterator_type
  operator+(const difference_type& __n) const
  { return __normal_iterator(_M_current + __n); }

  normal_iterator_type&
  operator-=(const difference_type& __n)
  { _M_current -= __n; return *this; }

  normal_iterator_type
  operator-(const difference_type& __n) const
  { return __normal_iterator(_M_current - __n); }

  difference_type
  operator-(const normal_iterator_type& __i) const
  { return _M_current - __i._M_current; }

  const _Iterator&
  base() const { return _M_current; }
};



template<typename _IteratorL, typename _IteratorR, typename _Container>
inline bool
operator==(const __normal_iterator<_IteratorL, _Container>& __lhs,
           const __normal_iterator<_IteratorR, _Container>& __rhs)
{ return __lhs.base() == __rhs.base(); }

template<typename _IteratorL, typename _IteratorR, typename _Container>
inline bool
operator!=(const __normal_iterator<_IteratorL, _Container>& __lhs,
           const __normal_iterator<_IteratorR, _Container>& __rhs)
{ return !(__lhs == __rhs); }



template<typename _IteratorL, typename _IteratorR, typename _Container>
inline bool
operator<(const __normal_iterator<_IteratorL, _Container>& __lhs,
          const __normal_iterator<_IteratorR, _Container>& __rhs)
{ return __lhs.base() < __rhs.base(); }

template<typename _IteratorL, typename _IteratorR, typename _Container>
inline bool
operator>(const __normal_iterator<_IteratorL, _Container>& __lhs,
          const __normal_iterator<_IteratorR, _Container>& __rhs)
{ return __rhs < __lhs; }

template<typename _IteratorL, typename _IteratorR, typename _Container>
inline bool
operator<=(const __normal_iterator<_IteratorL, _Container>& __lhs,
           const __normal_iterator<_IteratorR, _Container>& __rhs)
{ return !(__rhs < __lhs); }

template<typename _IteratorL, typename _IteratorR, typename _Container>
inline bool
operator>=(const __normal_iterator<_IteratorL, _Container>& __lhs,
           const __normal_iterator<_IteratorR, _Container>& __rhs)
{ return !(__lhs < __rhs); }

template<typename _Iterator, typename _Container>
inline __normal_iterator<_Iterator, _Container>
operator+(typename __normal_iterator<_Iterator, _Container>::difference_type __n,
          const __normal_iterator<_Iterator, _Container>& __i)
{ return __normal_iterator<_Iterator, _Container>(__i.base() + __n); }

}
# 66 "/usr/local/include/g++-v3/bits/std_iterator.h" 2 3
# 43 "/usr/local/include/g++-v3/bits/std_string.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_memory.h" 1 3
# 48 "/usr/local/include/g++-v3/bits/std_memory.h" 3

# 1 "/usr/local/include/g++-v3/bits/stl_algobase.h" 1 3
# 64 "/usr/local/include/g++-v3/bits/stl_algobase.h" 3
# 1 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/c++config.h" 1 3
# 65 "/usr/local/include/g++-v3/bits/stl_algobase.h" 2 3

# 1 "/usr/local/include/g++-v3/bits/stl_pair.h" 1 3
# 64 "/usr/local/include/g++-v3/bits/stl_pair.h" 3
namespace std
{


template <class _T1, class _T2>
struct pair {
  typedef _T1 first_type;
  typedef _T2 second_type;

  _T1 first;
  _T2 second;




  pair() : first(), second() {}




  pair(const _T1& __a, const _T2& __b) : first(__a), second(__b) {}


  template <class _U1, class _U2>
  pair(const pair<_U1, _U2>& __p) : first(__p.first), second(__p.second) {}
};


template <class _T1, class _T2>
inline bool operator==(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
{
  return __x.first == __y.first && __x.second == __y.second;
}


template <class _T1, class _T2>
inline bool operator<(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
{
  return __x.first < __y.first ||
         (!(__y.first < __x.first) && __x.second < __y.second);
}


template <class _T1, class _T2>
inline bool operator!=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) {
  return !(__x == __y);
}


template <class _T1, class _T2>
inline bool operator>(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) {
  return __y < __x;
}


template <class _T1, class _T2>
inline bool operator<=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) {
  return !(__y < __x);
}


template <class _T1, class _T2>
inline bool operator>=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) {
  return !(__x < __y);
}
# 139 "/usr/local/include/g++-v3/bits/stl_pair.h" 3
template <class _T1, class _T2>


inline pair<_T1, _T2> make_pair(_T1 __x, _T2 __y)



{
  return pair<_T1, _T2>(__x, __y);
}

}
# 67 "/usr/local/include/g++-v3/bits/stl_algobase.h" 2 3


# 1 "/usr/local/include/g++-v3/bits/type_traits.h" 1 3
# 48 "/usr/local/include/g++-v3/bits/type_traits.h" 3

# 1 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/c++config.h" 1 3
# 50 "/usr/local/include/g++-v3/bits/type_traits.h" 2 3
# 86 "/usr/local/include/g++-v3/bits/type_traits.h" 3
template <bool _Truth> struct _Bool {};
typedef _Bool<true> __true_type;
typedef _Bool<false> __false_type;

template <class _Tp>
struct __type_traits {
   typedef __true_type this_dummy_member_must_be_first;
# 110 "/usr/local/include/g++-v3/bits/type_traits.h" 3
   typedef __false_type has_trivial_default_constructor;
   typedef __false_type has_trivial_copy_constructor;
   typedef __false_type has_trivial_assignment_operator;
   typedef __false_type has_trivial_destructor;
   typedef __false_type is_POD_type;
};




template<> struct __type_traits<bool> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template<> struct __type_traits<char> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template<> struct __type_traits<signed char> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template<> struct __type_traits<unsigned char> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template<> struct __type_traits<wchar_t> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template<> struct __type_traits<short> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template<> struct __type_traits<unsigned short> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template<> struct __type_traits<int> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template<> struct __type_traits<unsigned int> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template<> struct __type_traits<long> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template<> struct __type_traits<unsigned long> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};



template<> struct __type_traits<long long> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template<> struct __type_traits<unsigned long long> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};



template<> struct __type_traits<float> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template<> struct __type_traits<double> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template<> struct __type_traits<long double> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template <class _Tp>
struct __type_traits<_Tp*> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};





template <class _Tp> struct _Is_integer {
  typedef __false_type _Integral;
};

template<> struct _Is_integer<bool> {
  typedef __true_type _Integral;
};

template<> struct _Is_integer<char> {
  typedef __true_type _Integral;
};

template<> struct _Is_integer<signed char> {
  typedef __true_type _Integral;
};

template<> struct _Is_integer<unsigned char> {
  typedef __true_type _Integral;
};

template<> struct _Is_integer<wchar_t> {
  typedef __true_type _Integral;
};

template<> struct _Is_integer<short> {
  typedef __true_type _Integral;
};

template<> struct _Is_integer<unsigned short> {
  typedef __true_type _Integral;
};

template<> struct _Is_integer<int> {
  typedef __true_type _Integral;
};

template<> struct _Is_integer<unsigned int> {
  typedef __true_type _Integral;
};

template<> struct _Is_integer<long> {
  typedef __true_type _Integral;
};

template<> struct _Is_integer<unsigned long> {
  typedef __true_type _Integral;
};



template<> struct _Is_integer<long long> {
  typedef __true_type _Integral;
};

template<> struct _Is_integer<unsigned long long> {
  typedef __true_type _Integral;
};



template<typename _Tp> struct _Is_normal_iterator {
   typedef __false_type _Normal;
};


namespace std {
   template<typename _Iterator, typename _Container> class __normal_iterator;
};

template<typename _Iterator, typename _Container>
struct _Is_normal_iterator< std::__normal_iterator<_Iterator, _Container> > {
   typedef __true_type _Normal;
};
# 70 "/usr/local/include/g++-v3/bits/stl_algobase.h" 2 3

# 1 "/usr/local/include/g++-v3/bits/std_cstring.h" 1 3
# 72 "/usr/local/include/g++-v3/bits/stl_algobase.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_climits.h" 1 3
# 73 "/usr/local/include/g++-v3/bits/stl_algobase.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_cstdlib.h" 1 3
# 37 "/usr/local/include/g++-v3/bits/std_cstdlib.h" 3
# 1 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/c++config.h" 1 3
# 38 "/usr/local/include/g++-v3/bits/std_cstdlib.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_cstddef.h" 1 3
# 39 "/usr/local/include/g++-v3/bits/std_cstdlib.h" 2 3
# 41 "/usr/local/include/g++-v3/bits/std_cstdlib.h" 3
# 1 "/usr/include/stdlib.h" 1 3
# 42 "/usr/local/include/g++-v3/bits/std_cstdlib.h" 2 3
# 73 "/usr/local/include/g++-v3/bits/std_cstdlib.h" 3
namespace std
{
  using ::div_t;
  using ::ldiv_t;

  using ::abort;
  using ::abs;
  using ::atexit;
  using ::atof;
  using ::atoi;
  using ::atol;
  using ::bsearch;
  using ::calloc;
  using ::div;
  using ::exit;
  using ::free;
  using ::getenv;
  using ::labs;
  using ::ldiv;
  using ::malloc;
  using ::mblen;
  using ::mbstowcs;
  using ::mbtowc;
  using ::qsort;
  using ::rand;
  using ::realloc;
  using ::srand;
  using ::strtod;
  using ::strtol;
  using ::strtoul;
  using ::system;
  using ::wcstombs;
  using ::wctomb;

  inline long
  abs(long __i) { return labs(__i); }

  inline ldiv_t
  div(long __i, long __j) { return ldiv(__i, __j); }
}
# 125 "/usr/local/include/g++-v3/bits/std_cstdlib.h" 3
namespace __gnu_cxx
{
  using ::lldiv_t;
  using ::_Exit;

  inline long long
  abs(long long __x) { return __x >= 0 ? __x : -__x; }

  inline long long
  llabs(long long __x) { return __x >= 0 ? __x : -__x; }

  inline lldiv_t
  div(long long __n, long long __d)
  { lldiv_t __q; __q.quot = __n / __d; __q.rem = __n % __d; return __q; }

  inline lldiv_t
  lldiv(long long __n, long long __d)
  { lldiv_t __q; __q.quot = __n / __d; __q.rem = __n % __d; return __q; }

  using ::atoll;
  using ::strtof;
  using ::strtoll;
  using ::strtoull;
  using ::strtold;
}

namespace std
{
  using __gnu_cxx::lldiv_t;
  using __gnu_cxx::_Exit;
  using __gnu_cxx::abs;
  using __gnu_cxx::llabs;
  using __gnu_cxx::div;
  using __gnu_cxx::lldiv;
  using __gnu_cxx::atoll;
  using __gnu_cxx::strtof;
  using __gnu_cxx::strtoll;
  using __gnu_cxx::strtoull;
  using __gnu_cxx::strtold;
}
# 74 "/usr/local/include/g++-v3/bits/stl_algobase.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_cstddef.h" 1 3
# 75 "/usr/local/include/g++-v3/bits/stl_algobase.h" 2 3
# 1 "/usr/local/include/g++-v3/new" 1 3
# 76 "/usr/local/include/g++-v3/bits/stl_algobase.h" 2 3

# 1 "/usr/local/include/g++-v3/bits/std_iosfwd.h" 1 3
# 78 "/usr/local/include/g++-v3/bits/stl_algobase.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/stl_iterator_base_types.h" 1 3
# 79 "/usr/local/include/g++-v3/bits/stl_algobase.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/stl_iterator_base_funcs.h" 1 3
# 80 "/usr/local/include/g++-v3/bits/stl_algobase.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/stl_iterator.h" 1 3
# 81 "/usr/local/include/g++-v3/bits/stl_algobase.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/concept_check.h" 1 3
# 82 "/usr/local/include/g++-v3/bits/stl_algobase.h" 2 3

namespace std
{



template <class _ForwardIter1, class _ForwardIter2, class _Tp>
inline void __iter_swap(_ForwardIter1 __a, _ForwardIter2 __b, _Tp*)
{
  _Tp __tmp = *__a;
  *__a = *__b;
  *__b = __tmp;
}

template <class _ForwardIter1, class _ForwardIter2>
inline void iter_swap(_ForwardIter1 __a, _ForwardIter2 __b)
{

                                                                             ;
                                                                             ;
                                                             ;


                                                             ;



  __iter_swap(__a, __b, __value_type(__a));
}

template <class _Tp>
inline void swap(_Tp& __a, _Tp& __b)
{

                                                         ;

  _Tp __tmp = __a;
  __a = __b;
  __b = __tmp;
}







template <class _Tp>
inline const _Tp& min(const _Tp& __a, const _Tp& __b) {

                                                              ;

  if (__b < __a) return __b; return __a;
}

template <class _Tp>
inline const _Tp& max(const _Tp& __a, const _Tp& __b) {

                                                              ;

  if (__a < __b) return __b; return __a;
}

template <class _Tp, class _Compare>
inline const _Tp& min(const _Tp& __a, const _Tp& __b, _Compare __comp) {

  if (__comp(__b, __a)) return __b; return __a;
}

template <class _Tp, class _Compare>
inline const _Tp& max(const _Tp& __a, const _Tp& __b, _Compare __comp) {

  if (__comp(__a, __b)) return __b; return __a;
}
# 166 "/usr/local/include/g++-v3/bits/stl_algobase.h" 3
template <class _InputIter, class _OutputIter, class _Distance>
inline _OutputIter __copy(_InputIter __first, _InputIter __last,
                          _OutputIter __result,
                          input_iterator_tag, _Distance*)
{
  for ( ; __first != __last; ++__result, ++__first)
    *__result = *__first;
  return __result;
}

template <class _RandomAccessIter, class _OutputIter, class _Distance>
inline _OutputIter
__copy(_RandomAccessIter __first, _RandomAccessIter __last,
       _OutputIter __result, random_access_iterator_tag, _Distance*)
{
  for (_Distance __n = __last - __first; __n > 0; --__n) {
    *__result = *__first;
    ++__first;
    ++__result;
  }
  return __result;
}

template <class _Tp>
inline _Tp*
__copy_trivial(const _Tp* __first, const _Tp* __last, _Tp* __result)
{
  memmove(__result, __first, sizeof(_Tp) * (__last - __first));
  return __result + (__last - __first);
}


template <class _InputIter, class _OutputIter>
inline _OutputIter __copy_aux2(_InputIter __first, _InputIter __last,
                               _OutputIter __result, __false_type)
{
  return __copy(__first, __last, __result,
                __iterator_category(__first),
                __distance_type(__first));
}

template <class _InputIter, class _OutputIter>
inline _OutputIter __copy_aux2(_InputIter __first, _InputIter __last,
                               _OutputIter __result, __true_type)
{
  return __copy(__first, __last, __result,
                __iterator_category(__first),
                __distance_type(__first));
}

template <class _Tp>
inline _Tp* __copy_aux2(_Tp* __first, _Tp* __last, _Tp* __result,
                        __true_type)
{
  return __copy_trivial(__first, __last, __result);
}

template <class _Tp>
inline _Tp* __copy_aux2(const _Tp* __first, const _Tp* __last, _Tp* __result,
                        __true_type)
{
  return __copy_trivial(__first, __last, __result);
}


template <class _InputIter, class _OutputIter, class _Tp>
inline _OutputIter __copy_aux(_InputIter __first, _InputIter __last,
                              _OutputIter __result, _Tp*)
{
  typedef typename __type_traits<_Tp>::has_trivial_assignment_operator
          _Trivial;
  return __copy_aux2(__first, __last, __result, _Trivial());
}

template<typename _InputIter, typename _OutputIter>
inline _OutputIter __copy_ni2(_InputIter __first, _InputIter __last,
                               _OutputIter __result, __true_type)
{
  return _OutputIter(__copy_aux(__first, __last, __result.base(),
                                __value_type(__first)));
}

template<typename _InputIter, typename _OutputIter>
inline _OutputIter __copy_ni2(_InputIter __first, _InputIter __last,
                              _OutputIter __result, __false_type)
{
  return __copy_aux(__first, __last, __result, __value_type(__first));
}

template<typename _InputIter, typename _OutputIter>
inline _OutputIter __copy_ni1(_InputIter __first, _InputIter __last,
                               _OutputIter __result, __true_type)
{
  typedef typename _Is_normal_iterator<_OutputIter>::_Normal __Normal;
  return __copy_ni2(__first.base(), __last.base(), __result, __Normal());
}

template<typename _InputIter, typename _OutputIter>
inline _OutputIter __copy_ni1(_InputIter __first, _InputIter __last,
                               _OutputIter __result, __false_type)
{
  typedef typename _Is_normal_iterator<_OutputIter>::_Normal __Normal;
  return __copy_ni2(__first, __last, __result, __Normal());
}

template <class _InputIter, class _OutputIter>
inline _OutputIter copy(_InputIter __first, _InputIter __last,
                        _OutputIter __result)
{

                                                                ;
                                                          ;


   typedef typename _Is_normal_iterator<_InputIter>::_Normal __Normal;
   return __copy_ni1(__first, __last, __result, __Normal());
}




template <class _BidirectionalIter1, class _BidirectionalIter2,
          class _Distance>
inline _BidirectionalIter2 __copy_backward(_BidirectionalIter1 __first,
                                           _BidirectionalIter1 __last,
                                           _BidirectionalIter2 __result,
                                           bidirectional_iterator_tag,
                                           _Distance*)
{
  while (__first != __last)
    *--__result = *--__last;
  return __result;
}

template <class _RandomAccessIter, class _BidirectionalIter, class _Distance>
inline _BidirectionalIter __copy_backward(_RandomAccessIter __first,
                                          _RandomAccessIter __last,
                                          _BidirectionalIter __result,
                                          random_access_iterator_tag,
                                          _Distance*)
{
  for (_Distance __n = __last - __first; __n > 0; --__n)
    *--__result = *--__last;
  return __result;
}







template <class _BidirectionalIter1, class _BidirectionalIter2,
          class _BoolType>
struct __copy_backward_dispatch
{
  typedef typename iterator_traits<_BidirectionalIter1>::iterator_category
          _Cat;
  typedef typename iterator_traits<_BidirectionalIter1>::difference_type
          _Distance;

  static _BidirectionalIter2 copy(_BidirectionalIter1 __first,
                                  _BidirectionalIter1 __last,
                                  _BidirectionalIter2 __result) {
    return __copy_backward(__first, __last, __result, _Cat(), (_Distance*) 0);
  }
};

template <class _Tp>
struct __copy_backward_dispatch<_Tp*, _Tp*, __true_type>
{
  static _Tp* copy(const _Tp* __first, const _Tp* __last, _Tp* __result) {
    const ptrdiff_t _Num = __last - __first;
    memmove(__result - _Num, __first, sizeof(_Tp) * _Num);
    return __result - _Num;
  }
};

template <class _Tp>
struct __copy_backward_dispatch<const _Tp*, _Tp*, __true_type>
{
  static _Tp* copy(const _Tp* __first, const _Tp* __last, _Tp* __result) {
    return __copy_backward_dispatch<_Tp*, _Tp*, __true_type>
      ::copy(__first, __last, __result);
  }
};

template <class _BI1, class _BI2>
inline _BI2 __copy_backward_aux(_BI1 __first, _BI1 __last, _BI2 __result) {
  typedef typename __type_traits<typename iterator_traits<_BI2>::value_type>
                        ::has_trivial_assignment_operator
          _Trivial;
  return __copy_backward_dispatch<_BI1, _BI2, _Trivial>
              ::copy(__first, __last, __result);
}

template <typename _BI1, typename _BI2>
inline _BI2 __copy_backward_output_normal_iterator(_BI1 __first, _BI1 __last,
                                                   _BI2 __result, __true_type) {
  return _BI2(__copy_backward_aux(__first, __last, __result.base()));
}

template <typename _BI1, typename _BI2>
inline _BI2 __copy_backward_output_normal_iterator(_BI1 __first, _BI1 __last,
                                                   _BI2 __result, __false_type){
  return __copy_backward_aux(__first, __last, __result);
}

template <typename _BI1, typename _BI2>
inline _BI2 __copy_backward_input_normal_iterator(_BI1 __first, _BI1 __last,
                                                  _BI2 __result, __true_type) {
  typedef typename _Is_normal_iterator<_BI2>::_Normal __Normal;
  return __copy_backward_output_normal_iterator(__first.base(), __last.base(),
                                                __result, __Normal());
}

template <typename _BI1, typename _BI2>
inline _BI2 __copy_backward_input_normal_iterator(_BI1 __first, _BI1 __last,
                                                  _BI2 __result, __false_type) {
  typedef typename _Is_normal_iterator<_BI2>::_Normal __Normal;
  return __copy_backward_output_normal_iterator(__first, __last, __result,
                                                __Normal());
}

template <typename _BI1, typename _BI2>
inline _BI2 copy_backward(_BI1 __first, _BI1 __last, _BI2 __result)
{

                                                                  ;
                                                                          ;
                                                    ;



  typedef typename _Is_normal_iterator<_BI1>::_Normal __Normal;
  return __copy_backward_input_normal_iterator(__first, __last, __result,
                                               __Normal());
}




template <class _InputIter, class _Size, class _OutputIter>
pair<_InputIter, _OutputIter> __copy_n(_InputIter __first, _Size __count,
                                       _OutputIter __result,
                                       input_iterator_tag) {
  for ( ; __count > 0; --__count) {
    *__result = *__first;
    ++__first;
    ++__result;
  }
  return pair<_InputIter, _OutputIter>(__first, __result);
}

template <class _RAIter, class _Size, class _OutputIter>
inline pair<_RAIter, _OutputIter>
__copy_n(_RAIter __first, _Size __count,
         _OutputIter __result,
         random_access_iterator_tag) {
  _RAIter __last = __first + __count;
  return pair<_RAIter, _OutputIter>(__last, copy(__first, __last, __result));
}

template <class _InputIter, class _Size, class _OutputIter>
inline pair<_InputIter, _OutputIter>
__copy_n(_InputIter __first, _Size __count, _OutputIter __result) {
  return __copy_n(__first, __count, __result,
                  __iterator_category(__first));
}

template <class _InputIter, class _Size, class _OutputIter>
inline pair<_InputIter, _OutputIter>
copy_n(_InputIter __first, _Size __count, _OutputIter __result)
{

                                                                ;
                                                          ;


  return __copy_n(__first, __count, __result);
}





template <class _ForwardIter, class _Tp>
void fill(_ForwardIter __first, _ForwardIter __last, const _Tp& __value)
{

                                                                            ;

  for ( ; __first != __last; ++__first)
    *__first = __value;
}

template <class _OutputIter, class _Size, class _Tp>
_OutputIter fill_n(_OutputIter __first, _Size __n, const _Tp& __value)
{

                                                                      ;

  for ( ; __n > 0; --__n, ++__first)
    *__first = __value;
  return __first;
}



inline void fill(unsigned char* __first, unsigned char* __last,
                 const unsigned char& __c)
{
  unsigned char __tmp = __c;
  memset(__first, __tmp, __last - __first);
}

inline void fill(signed char* __first, signed char* __last,
                 const signed char& __c)
{
  signed char __tmp = __c;
  memset(__first, static_cast<unsigned char>(__tmp), __last - __first);
}

inline void fill(char* __first, char* __last, const char& __c)
{
  char __tmp = __c;
  memset(__first, static_cast<unsigned char>(__tmp), __last - __first);
}

template <class _Size>
inline unsigned char* fill_n(unsigned char* __first, _Size __n,
                             const unsigned char& __c)
{
  fill(__first, __first + __n, __c);
  return __first + __n;
}

template <class _Size>
inline signed char* fill_n(char* __first, _Size __n,
                           const signed char& __c)
{
  fill(__first, __first + __n, __c);
  return __first + __n;
}

template <class _Size>
inline char* fill_n(char* __first, _Size __n, const char& __c)
{
  fill(__first, __first + __n, __c);
  return __first + __n;
}





template <class _InputIter1, class _InputIter2>
pair<_InputIter1, _InputIter2> mismatch(_InputIter1 __first1,
                                        _InputIter1 __last1,
                                        _InputIter2 __first2)
{

                                                                 ;
                                                                 ;
                                                           ;

                                                           ;


  while (__first1 != __last1 && *__first1 == *__first2) {
    ++__first1;
    ++__first2;
  }
  return pair<_InputIter1, _InputIter2>(__first1, __first2);
}

template <class _InputIter1, class _InputIter2, class _BinaryPredicate>
pair<_InputIter1, _InputIter2> mismatch(_InputIter1 __first1,
                                        _InputIter1 __last1,
                                        _InputIter2 __first2,
                                        _BinaryPredicate __binary_pred)
{

                                                                 ;
                                                                 ;

  while (__first1 != __last1 && __binary_pred(*__first1, *__first2)) {
    ++__first1;
    ++__first2;
  }
  return pair<_InputIter1, _InputIter2>(__first1, __first2);
}

template <class _InputIter1, class _InputIter2>
inline bool equal(_InputIter1 __first1, _InputIter1 __last1,
                  _InputIter2 __first2)
{

                                                                 ;
                                                                 ;
                                                           ;



  for ( ; __first1 != __last1; ++__first1, ++__first2)
    if (!(*__first1 == *__first2))
      return false;
  return true;
}

template <class _InputIter1, class _InputIter2, class _BinaryPredicate>
inline bool equal(_InputIter1 __first1, _InputIter1 __last1,
                  _InputIter2 __first2, _BinaryPredicate __binary_pred)
{

                                                                 ;
                                                                 ;

  for ( ; __first1 != __last1; ++__first1, ++__first2)
    if (!__binary_pred(*__first1, *__first2))
      return false;
  return true;
}





template <class _InputIter1, class _InputIter2>
bool lexicographical_compare(_InputIter1 __first1, _InputIter1 __last1,
                             _InputIter2 __first2, _InputIter2 __last2)
{

                                                                 ;
                                                                 ;
                                                           ;

                                                           ;


  for ( ; __first1 != __last1 && __first2 != __last2
        ; ++__first1, ++__first2) {
    if (*__first1 < *__first2)
      return true;
    if (*__first2 < *__first1)
      return false;
  }
  return __first1 == __last1 && __first2 != __last2;
}

template <class _InputIter1, class _InputIter2, class _Compare>
bool lexicographical_compare(_InputIter1 __first1, _InputIter1 __last1,
                             _InputIter2 __first2, _InputIter2 __last2,
                             _Compare __comp)
{

                                                                 ;
                                                                 ;

  for ( ; __first1 != __last1 && __first2 != __last2
        ; ++__first1, ++__first2) {
    if (__comp(*__first1, *__first2))
      return true;
    if (__comp(*__first2, *__first1))
      return false;
  }
  return __first1 == __last1 && __first2 != __last2;
}

inline bool
lexicographical_compare(const unsigned char* __first1,
                        const unsigned char* __last1,
                        const unsigned char* __first2,
                        const unsigned char* __last2)
{
  const size_t __len1 = __last1 - __first1;
  const size_t __len2 = __last2 - __first2;
  const int __result = memcmp(__first1, __first2, min(__len1, __len2));
  return __result != 0 ? __result < 0 : __len1 < __len2;
}

inline bool lexicographical_compare(const char* __first1, const char* __last1,
                                    const char* __first2, const char* __last2)
{

  return lexicographical_compare((const signed char*) __first1,
                                 (const signed char*) __last1,
                                 (const signed char*) __first2,
                                 (const signed char*) __last2);






}

template <class _InputIter1, class _InputIter2>
int __lexicographical_compare_3way(_InputIter1 __first1, _InputIter1 __last1,
                                   _InputIter2 __first2, _InputIter2 __last2)
{
  while (__first1 != __last1 && __first2 != __last2) {
    if (*__first1 < *__first2)
      return -1;
    if (*__first2 < *__first1)
      return 1;
    ++__first1;
    ++__first2;
  }
  if (__first2 == __last2) {
    return !(__first1 == __last1);
  }
  else {
    return -1;
  }
}

inline int
__lexicographical_compare_3way(const unsigned char* __first1,
                               const unsigned char* __last1,
                               const unsigned char* __first2,
                               const unsigned char* __last2)
{
  const ptrdiff_t __len1 = __last1 - __first1;
  const ptrdiff_t __len2 = __last2 - __first2;
  const int __result = memcmp(__first1, __first2, min(__len1, __len2));
  return __result != 0 ? __result
                       : (__len1 == __len2 ? 0 : (__len1 < __len2 ? -1 : 1));
}

inline int
__lexicographical_compare_3way(const char* __first1, const char* __last1,
                               const char* __first2, const char* __last2)
{

  return __lexicographical_compare_3way(
                                (const signed char*) __first1,
                                (const signed char*) __last1,
                                (const signed char*) __first2,
                                (const signed char*) __last2);






}

template <class _InputIter1, class _InputIter2>
int lexicographical_compare_3way(_InputIter1 __first1, _InputIter1 __last1,
                                 _InputIter2 __first2, _InputIter2 __last2)
{

                                                                 ;
                                                                 ;
                                                           ;

                                                           ;


  return __lexicographical_compare_3way(__first1, __last1, __first2, __last2);
}

}
# 50 "/usr/local/include/g++-v3/bits/std_memory.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/stl_alloc.h" 1 3
# 57 "/usr/local/include/g++-v3/bits/stl_alloc.h" 3
# 1 "/usr/local/include/g++-v3/bits/functexcept.h" 1 3
# 34 "/usr/local/include/g++-v3/bits/functexcept.h" 3
# 1 "/usr/local/include/g++-v3/exception_defines.h" 1 3
# 35 "/usr/local/include/g++-v3/bits/functexcept.h" 2 3

namespace std
{

  void
  __throw_bad_exception(void);


  void
  __throw_bad_alloc(void);


  void
  __throw_bad_cast(void);

  void
  __throw_bad_typeid(void);


  void
  __throw_logic_error(const char* __s);

  void
  __throw_domain_error(const char* __s);

  void
  __throw_invalid_argument(const char* __s);

  void
  __throw_length_error(const char* __s);

  void
  __throw_out_of_range(const char* __s);

  void
  __throw_runtime_error(const char* __s);

  void
  __throw_range_error(const char* __s);

  void
  __throw_overflow_error(const char* __s);

  void
  __throw_underflow_error(const char* __s);


  void
  __throw_ios_failure(const char* __s);
}
# 58 "/usr/local/include/g++-v3/bits/stl_alloc.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_cstddef.h" 1 3
# 59 "/usr/local/include/g++-v3/bits/stl_alloc.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_cstdlib.h" 1 3
# 60 "/usr/local/include/g++-v3/bits/stl_alloc.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_cstring.h" 1 3
# 61 "/usr/local/include/g++-v3/bits/stl_alloc.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_cassert.h" 1 3
# 37 "/usr/local/include/g++-v3/bits/std_cassert.h" 3
# 1 "/usr/include/assert.h" 1 3
# 36 "/usr/include/assert.h" 3
# 1 "/usr/include/features.h" 1 3
# 37 "/usr/include/assert.h" 2 3
# 65 "/usr/include/assert.h" 3
extern "C" {


extern void __assert_fail (__const char *__assertion, __const char *__file,
                           unsigned int __line, __const char *__function)
     throw () __attribute__ ((__noreturn__));


extern void __assert_perror_fail (int __errnum, __const char *__file,
                                  unsigned int __line,
                                  __const char *__function)
     throw () __attribute__ ((__noreturn__));




extern void __assert (const char *__assertion, const char *__file, int __line)
     throw () __attribute__ ((__noreturn__));


}
# 38 "/usr/local/include/g++-v3/bits/std_cassert.h" 2 3
# 62 "/usr/local/include/g++-v3/bits/stl_alloc.h" 2 3





# 1 "/usr/local/include/g++-v3/bits/stl_threads.h" 1 3
# 62 "/usr/local/include/g++-v3/bits/stl_threads.h" 3
# 1 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/gthr.h" 1 3
# 63 "/usr/local/include/g++-v3/bits/stl_threads.h" 2 3
# 80 "/usr/local/include/g++-v3/bits/stl_threads.h" 3
namespace std
{
# 95 "/usr/local/include/g++-v3/bits/stl_threads.h" 3
struct _Refcount_Base
{




  typedef size_t _RC_t;



   volatile _RC_t _M_ref_count;




  __gthread_mutex_t _M_ref_count_lock;
  _Refcount_Base(_RC_t __n) : _M_ref_count(__n)
    {

      __gthread_mutex_t __tmp = {0, 0, 0, PTHREAD_MUTEX_TIMED_NP, { 0, 0 }};
      _M_ref_count_lock = __tmp;





    }
# 141 "/usr/local/include/g++-v3/bits/stl_threads.h" 3
  void _M_incr() {
    __gthread_mutex_lock(&_M_ref_count_lock);
    ++_M_ref_count;
    __gthread_mutex_unlock(&_M_ref_count_lock);
  }
  _RC_t _M_decr() {
    __gthread_mutex_lock(&_M_ref_count_lock);
    volatile _RC_t __tmp = --_M_ref_count;
    __gthread_mutex_unlock(&_M_ref_count_lock);
    return __tmp;
  }
# 192 "/usr/local/include/g++-v3/bits/stl_threads.h" 3
};
# 313 "/usr/local/include/g++-v3/bits/stl_threads.h" 3
template <int __inst>
struct _STL_mutex_spin {
  enum { __low_max = 30, __high_max = 1000 };


  static unsigned __max;
  static unsigned __last;
};

template <int __inst>
unsigned _STL_mutex_spin<__inst>::__max = _STL_mutex_spin<__inst>::__low_max;

template <int __inst>
unsigned _STL_mutex_spin<__inst>::__last = 0;
# 340 "/usr/local/include/g++-v3/bits/stl_threads.h" 3
struct _STL_mutex_lock
{







  __gthread_mutex_t _M_lock;
  void _M_initialize() {
# 371 "/usr/local/include/g++-v3/bits/stl_threads.h" 3
  }
  void _M_acquire_lock() {



    __gthread_mutex_lock(&_M_lock);
  }
  void _M_release_lock() {



    __gthread_mutex_unlock(&_M_lock);
  }
# 482 "/usr/local/include/g++-v3/bits/stl_threads.h" 3
};
# 521 "/usr/local/include/g++-v3/bits/stl_threads.h" 3
struct _STL_auto_lock
{
  _STL_mutex_lock& _M_lock;

  _STL_auto_lock(_STL_mutex_lock& __lock) : _M_lock(__lock)
    { _M_lock._M_acquire_lock(); }
  ~_STL_auto_lock() { _M_lock._M_release_lock(); }

private:
  void operator=(const _STL_auto_lock&);
  _STL_auto_lock(const _STL_auto_lock&);
};

}
# 68 "/usr/local/include/g++-v3/bits/stl_alloc.h" 2 3
# 97 "/usr/local/include/g++-v3/bits/stl_alloc.h" 3
namespace std
{



template <int __inst>
class __malloc_alloc_template {

private:

  static void* _S_oom_malloc(size_t);
  static void* _S_oom_realloc(void*, size_t);
  static void (* __malloc_alloc_oom_handler)();

public:

  static void* allocate(size_t __n)
  {
    void* __result = malloc(__n);
    if (0 == __result) __result = _S_oom_malloc(__n);
    return __result;
  }

  static void deallocate(void* __p, size_t )
  {
    free(__p);
  }

  static void* reallocate(void* __p, size_t , size_t __new_sz)
  {
    void* __result = realloc(__p, __new_sz);
    if (0 == __result) __result = _S_oom_realloc(__p, __new_sz);
    return __result;
  }

  static void (* __set_malloc_handler(void (*__f)()))()
  {
    void (* __old)() = __malloc_alloc_oom_handler;
    __malloc_alloc_oom_handler = __f;
    return(__old);
  }

};



template <int __inst>
void (* __malloc_alloc_template<__inst>::__malloc_alloc_oom_handler)() = 0;

template <int __inst>
void*
__malloc_alloc_template<__inst>::_S_oom_malloc(size_t __n)
{
    void (* __my_malloc_handler)();
    void* __result;

    for (;;) {
        __my_malloc_handler = __malloc_alloc_oom_handler;
        if (0 == __my_malloc_handler) { std::__throw_bad_alloc(); }
        (*__my_malloc_handler)();
        __result = malloc(__n);
        if (__result) return(__result);
    }
}

template <int __inst>
void* __malloc_alloc_template<__inst>::_S_oom_realloc(void* __p, size_t __n)
{
    void (* __my_malloc_handler)();
    void* __result;

    for (;;) {
        __my_malloc_handler = __malloc_alloc_oom_handler;
        if (0 == __my_malloc_handler) { std::__throw_bad_alloc(); }
        (*__my_malloc_handler)();
        __result = realloc(__p, __n);
        if (__result) return(__result);
    }
}

typedef __malloc_alloc_template<0> malloc_alloc;

template<class _Tp, class _Alloc>
class simple_alloc {

public:
    static _Tp* allocate(size_t __n)
      { return 0 == __n ? 0 : (_Tp*) _Alloc::allocate(__n * sizeof (_Tp)); }
    static _Tp* allocate(void)
      { return (_Tp*) _Alloc::allocate(sizeof (_Tp)); }
    static void deallocate(_Tp* __p, size_t __n)
      { if (0 != __n) _Alloc::deallocate(__p, __n * sizeof (_Tp)); }
    static void deallocate(_Tp* __p)
      { _Alloc::deallocate(__p, sizeof (_Tp)); }
};






template <class _Alloc>
class debug_alloc {

private:

  enum {_S_extra = 8};



public:

  static void* allocate(size_t __n)
  {
    char* __result = (char*)_Alloc::allocate(__n + (int) _S_extra);
    *(size_t*)__result = __n;
    return __result + (int) _S_extra;
  }

  static void deallocate(void* __p, size_t __n)
  {
    char* __real_p = (char*)__p - (int) _S_extra;
    (static_cast<void> ((*(size_t*)__real_p == __n) ? 0 : (__assert_fail ("*(size_t*)__real_p == __n", "/usr/local/include/g++-v3/bits/stl_alloc.h", 219, __PRETTY_FUNCTION__), 0)));
    _Alloc::deallocate(__real_p, __n + (int) _S_extra);
  }

  static void* reallocate(void* __p, size_t __old_sz, size_t __new_sz)
  {
    char* __real_p = (char*)__p - (int) _S_extra;
    (static_cast<void> ((*(size_t*)__real_p == __old_sz) ? 0 : (__assert_fail ("*(size_t*)__real_p == __old_sz", "/usr/local/include/g++-v3/bits/stl_alloc.h", 226, __PRETTY_FUNCTION__), 0)));
    char* __result = (char*)
      _Alloc::reallocate(__real_p, __old_sz + (int) _S_extra,
                                   __new_sz + (int) _S_extra);
    *(size_t*)__result = __new_sz;
    return __result + (int) _S_extra;
  }

};
# 270 "/usr/local/include/g++-v3/bits/stl_alloc.h" 3
template <bool threads, int inst>
class __default_alloc_template {

private:


  enum {_ALIGN = 8};
  enum {_MAX_BYTES = 128};
  enum {_NFREELISTS = 16};
  static size_t
  _S_round_up(size_t __bytes)
    { return (((__bytes) + (size_t) _ALIGN-1) & ~((size_t) _ALIGN - 1)); }

  union _Obj {
        union _Obj* _M_free_list_link;
        char _M_client_data[1];
  };

  static _Obj* volatile _S_free_list[];

  static size_t _S_freelist_index(size_t __bytes) {
        return (((__bytes) + (size_t)_ALIGN-1)/(size_t)_ALIGN - 1);
  }


  static void* _S_refill(size_t __n);


  static char* _S_chunk_alloc(size_t __size, int& __nobjs);


  static char* _S_start_free;
  static char* _S_end_free;
  static size_t _S_heap_size;


    static _STL_mutex_lock _S_node_allocator_lock;





    class _Lock;
    friend class _Lock;
    class _Lock {
        public:
            _Lock() { { if (threads) _S_node_allocator_lock._M_acquire_lock(); }; }
            ~_Lock() { { if (threads) _S_node_allocator_lock._M_release_lock(); }; }
    };

public:


  static void* allocate(size_t __n)
  {
    void* __ret = 0;

    if (__n > (size_t) _MAX_BYTES) {
      __ret = malloc_alloc::allocate(__n);
    }
    else {
      _Obj* volatile* __my_free_list
          = _S_free_list + _S_freelist_index(__n);





      _Lock __lock_instance;

      _Obj* __result = *__my_free_list;
      if (__result == 0)
        __ret = _S_refill(_S_round_up(__n));
      else {
        *__my_free_list = __result -> _M_free_list_link;
        __ret = __result;
      }
    }

    return __ret;
  };


  static void deallocate(void* __p, size_t __n)
  {
    if (__n > (size_t) _MAX_BYTES)
      malloc_alloc::deallocate(__p, __n);
    else {
      _Obj* volatile* __my_free_list
          = _S_free_list + _S_freelist_index(__n);
      _Obj* __q = (_Obj*)__p;




      _Lock __lock_instance;

      __q -> _M_free_list_link = *__my_free_list;
      *__my_free_list = __q;

    }
  }

  static void* reallocate(void* __p, size_t __old_sz, size_t __new_sz);

} ;

typedef __default_alloc_template<true, 0> alloc;
typedef __default_alloc_template<false, 0> single_client_alloc;

template <bool __threads, int __inst>
inline bool operator==(const __default_alloc_template<__threads, __inst>&,
                       const __default_alloc_template<__threads, __inst>&)
{
  return true;
}

template <bool __threads, int __inst>
inline bool operator!=(const __default_alloc_template<__threads, __inst>&,
                       const __default_alloc_template<__threads, __inst>&)
{
  return false;
}







template <bool __threads, int __inst>
char*
__default_alloc_template<__threads, __inst>::_S_chunk_alloc(size_t __size,
                                                            int& __nobjs)
{
    char* __result;
    size_t __total_bytes = __size * __nobjs;
    size_t __bytes_left = _S_end_free - _S_start_free;

    if (__bytes_left >= __total_bytes) {
        __result = _S_start_free;
        _S_start_free += __total_bytes;
        return(__result);
    } else if (__bytes_left >= __size) {
        __nobjs = (int)(__bytes_left/__size);
        __total_bytes = __size * __nobjs;
        __result = _S_start_free;
        _S_start_free += __total_bytes;
        return(__result);
    } else {
        size_t __bytes_to_get =
          2 * __total_bytes + _S_round_up(_S_heap_size >> 4);

        if (__bytes_left > 0) {
            _Obj* volatile* __my_free_list =
                        _S_free_list + _S_freelist_index(__bytes_left);

            ((_Obj*)_S_start_free) -> _M_free_list_link = *__my_free_list;
            *__my_free_list = (_Obj*)_S_start_free;
        }
        _S_start_free = (char*)malloc(__bytes_to_get);
        if (0 == _S_start_free) {
            size_t __i;
            _Obj* volatile* __my_free_list;
            _Obj* __p;



            for (__i = __size;
                 __i <= (size_t) _MAX_BYTES;
                 __i += (size_t) _ALIGN) {
                __my_free_list = _S_free_list + _S_freelist_index(__i);
                __p = *__my_free_list;
                if (0 != __p) {
                    *__my_free_list = __p -> _M_free_list_link;
                    _S_start_free = (char*)__p;
                    _S_end_free = _S_start_free + __i;
                    return(_S_chunk_alloc(__size, __nobjs));


                }
            }
            _S_end_free = 0;
            _S_start_free = (char*)malloc_alloc::allocate(__bytes_to_get);



        }
        _S_heap_size += __bytes_to_get;
        _S_end_free = _S_start_free + __bytes_to_get;
        return(_S_chunk_alloc(__size, __nobjs));
    }
}





template <bool __threads, int __inst>
void*
__default_alloc_template<__threads, __inst>::_S_refill(size_t __n)
{
    int __nobjs = 20;
    char* __chunk = _S_chunk_alloc(__n, __nobjs);
    _Obj* volatile* __my_free_list;
    _Obj* __result;
    _Obj* __current_obj;
    _Obj* __next_obj;
    int __i;

    if (1 == __nobjs) return(__chunk);
    __my_free_list = _S_free_list + _S_freelist_index(__n);


      __result = (_Obj*)__chunk;
      *__my_free_list = __next_obj = (_Obj*)(__chunk + __n);
      for (__i = 1; ; __i++) {
        __current_obj = __next_obj;
        __next_obj = (_Obj*)((char*)__next_obj + __n);
        if (__nobjs - 1 == __i) {
            __current_obj -> _M_free_list_link = 0;
            break;
        } else {
            __current_obj -> _M_free_list_link = __next_obj;
        }
      }
    return(__result);
}

template <bool threads, int inst>
void*
__default_alloc_template<threads, inst>::reallocate(void* __p,
                                                    size_t __old_sz,
                                                    size_t __new_sz)
{
    void* __result;
    size_t __copy_sz;

    if (__old_sz > (size_t) _MAX_BYTES && __new_sz > (size_t) _MAX_BYTES) {
        return(realloc(__p, __new_sz));
    }
    if (_S_round_up(__old_sz) == _S_round_up(__new_sz)) return(__p);
    __result = allocate(__new_sz);
    __copy_sz = __new_sz > __old_sz? __old_sz : __new_sz;
    memcpy(__result, __p, __copy_sz);
    deallocate(__p, __old_sz);
    return(__result);
}


    template <bool __threads, int __inst>
    _STL_mutex_lock
    __default_alloc_template<__threads, __inst>::_S_node_allocator_lock
        = { {0, 0, 0, PTHREAD_MUTEX_TIMED_NP, { 0, 0 }} };



template <bool __threads, int __inst>
char* __default_alloc_template<__threads, __inst>::_S_start_free = 0;

template <bool __threads, int __inst>
char* __default_alloc_template<__threads, __inst>::_S_end_free = 0;

template <bool __threads, int __inst>
size_t __default_alloc_template<__threads, __inst>::_S_heap_size = 0;

template <bool __threads, int __inst>
typename __default_alloc_template<__threads, __inst>::_Obj* volatile
__default_alloc_template<__threads, __inst> ::_S_free_list[
    __default_alloc_template<__threads, __inst>::_NFREELISTS
] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };
# 555 "/usr/local/include/g++-v3/bits/stl_alloc.h" 3
template <class _Tp>
class allocator {
  typedef alloc _Alloc;
public:
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef _Tp* pointer;
  typedef const _Tp* const_pointer;
  typedef _Tp& reference;
  typedef const _Tp& const_reference;
  typedef _Tp value_type;

  template <class _Tp1> struct rebind {
    typedef allocator<_Tp1> other;
  };

  allocator() throw() {}
  allocator(const allocator&) throw() {}
  template <class _Tp1> allocator(const allocator<_Tp1>&) throw() {}
  ~allocator() throw() {}

  pointer address(reference __x) const { return &__x; }
  const_pointer address(const_reference __x) const { return &__x; }



  _Tp* allocate(size_type __n, const void* = 0) {
    return __n != 0 ? static_cast<_Tp*>(_Alloc::allocate(__n * sizeof(_Tp)))
                    : 0;
  }


  void deallocate(pointer __p, size_type __n)
    { _Alloc::deallocate(__p, __n * sizeof(_Tp)); }

  size_type max_size() const throw()
    { return size_t(-1) / sizeof(_Tp); }

  void construct(pointer __p, const _Tp& __val) { new(__p) _Tp(__val); }
  void destroy(pointer __p) { __p->~_Tp(); }
};

template<>
class allocator<void> {
public:
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef void* pointer;
  typedef const void* const_pointer;
  typedef void value_type;

  template <class _Tp1> struct rebind {
    typedef allocator<_Tp1> other;
  };
};


template <class _T1, class _T2>
inline bool operator==(const allocator<_T1>&, const allocator<_T2>&)
{
  return true;
}

template <class _T1, class _T2>
inline bool operator!=(const allocator<_T1>&, const allocator<_T2>&)
{
  return false;
}
# 631 "/usr/local/include/g++-v3/bits/stl_alloc.h" 3
template <class _Tp, class _Alloc>
struct __allocator {
  _Alloc __underlying_alloc;

  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef _Tp* pointer;
  typedef const _Tp* const_pointer;
  typedef _Tp& reference;
  typedef const _Tp& const_reference;
  typedef _Tp value_type;

  template <class _Tp1> struct rebind {
    typedef __allocator<_Tp1, _Alloc> other;
  };

  __allocator() throw() {}
  __allocator(const __allocator& __a) throw()
    : __underlying_alloc(__a.__underlying_alloc) {}
  template <class _Tp1>
  __allocator(const __allocator<_Tp1, _Alloc>& __a) throw()
    : __underlying_alloc(__a.__underlying_alloc) {}
  ~__allocator() throw() {}

  pointer address(reference __x) const { return &__x; }
  const_pointer address(const_reference __x) const { return &__x; }


  _Tp* allocate(size_type __n, const void* = 0) {
    return __n != 0
        ? static_cast<_Tp*>(__underlying_alloc.allocate(__n * sizeof(_Tp)))
        : 0;
  }


  void deallocate(pointer __p, size_type __n)
    { __underlying_alloc.deallocate(__p, __n * sizeof(_Tp)); }

  size_type max_size() const throw()
    { return size_t(-1) / sizeof(_Tp); }

  void construct(pointer __p, const _Tp& __val) { new(__p) _Tp(__val); }
  void destroy(pointer __p) { __p->~_Tp(); }
};

template <class _Alloc>
class __allocator<void, _Alloc> {
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;
  typedef void* pointer;
  typedef const void* const_pointer;
  typedef void value_type;

  template <class _Tp1> struct rebind {
    typedef __allocator<_Tp1, _Alloc> other;
  };
};

template <class _Tp, class _Alloc>
inline bool operator==(const __allocator<_Tp, _Alloc>& __a1,
                       const __allocator<_Tp, _Alloc>& __a2)
{
  return __a1.__underlying_alloc == __a2.__underlying_alloc;
}

template <class _Tp, class _Alloc>
inline bool operator!=(const __allocator<_Tp, _Alloc>& __a1,
                       const __allocator<_Tp, _Alloc>& __a2)
{
  return __a1.__underlying_alloc != __a2.__underlying_alloc;
}





template <int inst>
inline bool operator==(const __malloc_alloc_template<inst>&,
                       const __malloc_alloc_template<inst>&)
{
  return true;
}

template <int __inst>
inline bool operator!=(const __malloc_alloc_template<__inst>&,
                       const __malloc_alloc_template<__inst>&)
{
  return false;
}

template <class _Alloc>
inline bool operator==(const debug_alloc<_Alloc>&,
                       const debug_alloc<_Alloc>&) {
  return true;
}

template <class _Alloc>
inline bool operator!=(const debug_alloc<_Alloc>&,
                       const debug_alloc<_Alloc>&) {
  return false;
}
# 761 "/usr/local/include/g++-v3/bits/stl_alloc.h" 3
template <class _Tp, class _Allocator>
struct _Alloc_traits
{
  static const bool _S_instanceless = false;
  typedef typename _Allocator::template rebind<_Tp>::other allocator_type;
};

template <class _Tp, class _Allocator>
const bool _Alloc_traits<_Tp, _Allocator>::_S_instanceless;



template <class _Tp, class _Tp1>
struct _Alloc_traits<_Tp, allocator<_Tp1> >
{
  static const bool _S_instanceless = true;
  typedef simple_alloc<_Tp, alloc> _Alloc_type;
  typedef allocator<_Tp> allocator_type;
};



template <class _Tp, int __inst>
struct _Alloc_traits<_Tp, __malloc_alloc_template<__inst> >
{
  static const bool _S_instanceless = true;
  typedef simple_alloc<_Tp, __malloc_alloc_template<__inst> > _Alloc_type;
  typedef __allocator<_Tp, __malloc_alloc_template<__inst> > allocator_type;
};


template <class _Tp, bool __threads, int __inst>
struct _Alloc_traits<_Tp, __default_alloc_template<__threads, __inst> >
{
  static const bool _S_instanceless = true;
  typedef simple_alloc<_Tp, __default_alloc_template<__threads, __inst> >
          _Alloc_type;
  typedef __allocator<_Tp, __default_alloc_template<__threads, __inst> >
          allocator_type;
};


template <class _Tp, class _Alloc>
struct _Alloc_traits<_Tp, debug_alloc<_Alloc> >
{
  static const bool _S_instanceless = true;
  typedef simple_alloc<_Tp, debug_alloc<_Alloc> > _Alloc_type;
  typedef __allocator<_Tp, debug_alloc<_Alloc> > allocator_type;
};




template <class _Tp, class _Tp1, int __inst>
struct _Alloc_traits<_Tp,
                     __allocator<_Tp1, __malloc_alloc_template<__inst> > >
{
  static const bool _S_instanceless = true;
  typedef simple_alloc<_Tp, __malloc_alloc_template<__inst> > _Alloc_type;
  typedef __allocator<_Tp, __malloc_alloc_template<__inst> > allocator_type;
};


template <class _Tp, class _Tp1, bool __thr, int __inst>
struct _Alloc_traits<_Tp,
                      __allocator<_Tp1,
                                  __default_alloc_template<__thr, __inst> > >
{
  static const bool _S_instanceless = true;
  typedef simple_alloc<_Tp, __default_alloc_template<__thr,__inst> >
          _Alloc_type;
  typedef __allocator<_Tp, __default_alloc_template<__thr,__inst> >
          allocator_type;
};


template <class _Tp, class _Tp1, class _Alloc>
struct _Alloc_traits<_Tp, __allocator<_Tp1, debug_alloc<_Alloc> > >
{
  static const bool _S_instanceless = true;
  typedef simple_alloc<_Tp, debug_alloc<_Alloc> > _Alloc_type;
  typedef __allocator<_Tp, debug_alloc<_Alloc> > allocator_type;
};

}
# 51 "/usr/local/include/g++-v3/bits/std_memory.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/stl_construct.h" 1 3
# 63 "/usr/local/include/g++-v3/bits/stl_construct.h" 3
# 1 "/usr/local/include/g++-v3/new" 1 3
# 64 "/usr/local/include/g++-v3/bits/stl_construct.h" 2 3

namespace std
{
# 76 "/usr/local/include/g++-v3/bits/stl_construct.h" 3
template <class _T1, class _T2>
inline void _Construct(_T1* __p, const _T2& __value) {
new ((void*) __p) _T1(__value);
}

template <class _T1>
inline void _Construct(_T1* __p) {
  new ((void*) __p) _T1();
}

template <class _Tp>
inline void _Destroy(_Tp* __pointer) {
  __pointer->~_Tp();
}

template <class _ForwardIterator>
void
__destroy_aux(_ForwardIterator __first, _ForwardIterator __last, __false_type)
{
  for ( ; __first != __last; ++__first)
    destroy(&*__first);
}

template <class _ForwardIterator>
inline void __destroy_aux(_ForwardIterator, _ForwardIterator, __true_type) {}

template <class _ForwardIterator, class _Tp>
inline void
__destroy(_ForwardIterator __first, _ForwardIterator __last, _Tp*)
{
  typedef typename __type_traits<_Tp>::has_trivial_destructor
          _Trivial_destructor;
  __destroy_aux(__first, __last, _Trivial_destructor());
}

template <class _ForwardIterator>
inline void _Destroy(_ForwardIterator __first, _ForwardIterator __last) {
  __destroy(__first, __last, __value_type(__first));
}

inline void _Destroy(char*, char*) {}
inline void _Destroy(int*, int*) {}
inline void _Destroy(long*, long*) {}
inline void _Destroy(float*, float*) {}
inline void _Destroy(double*, double*) {}
inline void _Destroy(wchar_t*, wchar_t*) {}




template <class _T1, class _T2>
inline void construct(_T1* __p, const _T2& __value) {
  _Construct(__p, __value);
}

template <class _T1>
inline void construct(_T1* __p) {
  _Construct(__p);
}

template <class _Tp>
inline void destroy(_Tp* __pointer) {
  _Destroy(__pointer);
}

template <class _ForwardIterator>
inline void destroy(_ForwardIterator __first, _ForwardIterator __last) {
  _Destroy(__first, __last);
}

}
# 52 "/usr/local/include/g++-v3/bits/std_memory.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/stl_iterator_base_types.h" 1 3
# 53 "/usr/local/include/g++-v3/bits/std_memory.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/stl_tempbuf.h" 1 3
# 63 "/usr/local/include/g++-v3/bits/stl_tempbuf.h" 3
namespace std
{

template <class _Tp>
pair<_Tp*, ptrdiff_t>
__get_temporary_buffer(ptrdiff_t __len, _Tp*)
{
  if (__len > ptrdiff_t(2147483647 / sizeof(_Tp)))
    __len = 2147483647 / sizeof(_Tp);

  while (__len > 0) {
    _Tp* __tmp = (_Tp*) malloc((size_t)__len * sizeof(_Tp));
    if (__tmp != 0)
      return pair<_Tp*, ptrdiff_t>(__tmp, __len);
    __len /= 2;
  }

  return pair<_Tp*, ptrdiff_t>((_Tp*)0, 0);
}

template <class _Tp>
inline pair<_Tp*, ptrdiff_t> get_temporary_buffer(ptrdiff_t __len) {
  return __get_temporary_buffer(__len, (_Tp*) 0);
}






template <class _Tp>
inline pair<_Tp*, ptrdiff_t> get_temporary_buffer(ptrdiff_t __len, _Tp*) {
  return __get_temporary_buffer(__len, (_Tp*) 0);
}

template <class _Tp>
void return_temporary_buffer(_Tp* __p) {
  free(__p);
}

template <class _ForwardIterator, class _Tp>
class _Temporary_buffer {
private:
  ptrdiff_t _M_original_len;
  ptrdiff_t _M_len;
  _Tp* _M_buffer;

  void _M_allocate_buffer() {
    _M_original_len = _M_len;
    _M_buffer = 0;

    if (_M_len > (ptrdiff_t)(2147483647 / sizeof(_Tp)))
      _M_len = 2147483647 / sizeof(_Tp);

    while (_M_len > 0) {
      _M_buffer = (_Tp*) malloc(_M_len * sizeof(_Tp));
      if (_M_buffer)
        break;
      _M_len /= 2;
    }
  }

  void _M_initialize_buffer(const _Tp&, __true_type) {}
  void _M_initialize_buffer(const _Tp& val, __false_type) {
    uninitialized_fill_n(_M_buffer, _M_len, val);
  }

public:
  ptrdiff_t size() const { return _M_len; }
  ptrdiff_t requested_size() const { return _M_original_len; }
  _Tp* begin() { return _M_buffer; }
  _Tp* end() { return _M_buffer + _M_len; }

  _Temporary_buffer(_ForwardIterator __first, _ForwardIterator __last) {

    typedef typename __type_traits<_Tp>::has_trivial_default_constructor
            _Trivial;

    try {
      _M_len = 0;
      distance(__first, __last, _M_len);
      _M_allocate_buffer();
      if (_M_len > 0)
        _M_initialize_buffer(*__first, _Trivial());
    }
    catch(...) { free(_M_buffer); _M_buffer = 0; _M_len = 0; throw; };
  }

  ~_Temporary_buffer() {
    destroy(_M_buffer, _M_buffer + _M_len);
    free(_M_buffer);
  }

private:

  _Temporary_buffer(const _Temporary_buffer&) {}
  void operator=(const _Temporary_buffer&) {}
};



template <class _ForwardIterator,
          class _Tp
                    = typename iterator_traits<_ForwardIterator>::value_type
         >
struct temporary_buffer : public _Temporary_buffer<_ForwardIterator, _Tp>
{
  temporary_buffer(_ForwardIterator __first, _ForwardIterator __last)
    : _Temporary_buffer<_ForwardIterator, _Tp>(__first, __last) {}
  ~temporary_buffer() {}
};

}
# 54 "/usr/local/include/g++-v3/bits/std_memory.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/stl_uninitialized.h" 1 3
# 63 "/usr/local/include/g++-v3/bits/stl_uninitialized.h" 3
# 1 "/usr/local/include/g++-v3/bits/std_cstring.h" 1 3
# 64 "/usr/local/include/g++-v3/bits/stl_uninitialized.h" 2 3

namespace std
{





template <class _InputIter, class _ForwardIter>
inline _ForwardIter
__uninitialized_copy_aux(_InputIter __first, _InputIter __last,
                         _ForwardIter __result,
                         __true_type)
{
  return copy(__first, __last, __result);
}

template <class _InputIter, class _ForwardIter>
_ForwardIter
__uninitialized_copy_aux(_InputIter __first, _InputIter __last,
                         _ForwardIter __result,
                         __false_type)
{
  _ForwardIter __cur = __result;
  try {
    for ( ; __first != __last; ++__first, ++__cur)
      _Construct(&*__cur, *__first);
    return __cur;
  }
  catch(...) { _Destroy(__result, __cur); throw; };
}


template <class _InputIter, class _ForwardIter, class _Tp>
inline _ForwardIter
__uninitialized_copy(_InputIter __first, _InputIter __last,
                     _ForwardIter __result, _Tp*)
{
  typedef typename __type_traits<_Tp>::is_POD_type _Is_POD;
  return __uninitialized_copy_aux(__first, __last, __result, _Is_POD());
}

template <class _InputIter, class _ForwardIter>
inline _ForwardIter
  uninitialized_copy(_InputIter __first, _InputIter __last,
                     _ForwardIter __result)
{
  return __uninitialized_copy(__first, __last, __result,
                              __value_type(__result));
}

inline char* uninitialized_copy(const char* __first, const char* __last,
                                char* __result) {
  memmove(__result, __first, __last - __first);
  return __result + (__last - __first);
}

inline wchar_t*
uninitialized_copy(const wchar_t* __first, const wchar_t* __last,
                   wchar_t* __result)
{
  memmove(__result, __first, sizeof(wchar_t) * (__last - __first));
  return __result + (__last - __first);
}



template <class _InputIter, class _Size, class _ForwardIter>
pair<_InputIter, _ForwardIter>
__uninitialized_copy_n(_InputIter __first, _Size __count,
                       _ForwardIter __result,
                       input_iterator_tag)
{
  _ForwardIter __cur = __result;
  try {
    for ( ; __count > 0 ; --__count, ++__first, ++__cur)
      _Construct(&*__cur, *__first);
    return pair<_InputIter, _ForwardIter>(__first, __cur);
  }
  catch(...) { _Destroy(__result, __cur); throw; };
}

template <class _RandomAccessIter, class _Size, class _ForwardIter>
inline pair<_RandomAccessIter, _ForwardIter>
__uninitialized_copy_n(_RandomAccessIter __first, _Size __count,
                       _ForwardIter __result,
                       random_access_iterator_tag) {
  _RandomAccessIter __last = __first + __count;
  return pair<_RandomAccessIter, _ForwardIter>(
                 __last,
                 uninitialized_copy(__first, __last, __result));
}

template <class _InputIter, class _Size, class _ForwardIter>
inline pair<_InputIter, _ForwardIter>
__uninitialized_copy_n(_InputIter __first, _Size __count,
                     _ForwardIter __result) {
  return __uninitialized_copy_n(__first, __count, __result,
                                __iterator_category(__first));
}

template <class _InputIter, class _Size, class _ForwardIter>
inline pair<_InputIter, _ForwardIter>
uninitialized_copy_n(_InputIter __first, _Size __count,
                     _ForwardIter __result) {
  return __uninitialized_copy_n(__first, __count, __result,
                                __iterator_category(__first));
}



template <class _ForwardIter, class _Tp>
inline void
__uninitialized_fill_aux(_ForwardIter __first, _ForwardIter __last,
                         const _Tp& __x, __true_type)
{
  fill(__first, __last, __x);
}

template <class _ForwardIter, class _Tp>
void
__uninitialized_fill_aux(_ForwardIter __first, _ForwardIter __last,
                         const _Tp& __x, __false_type)
{
  _ForwardIter __cur = __first;
  try {
    for ( ; __cur != __last; ++__cur)
      _Construct(&*__cur, __x);
  }
  catch(...) { _Destroy(__first, __cur); throw; };
}

template <class _ForwardIter, class _Tp, class _Tp1>
inline void __uninitialized_fill(_ForwardIter __first,
                                 _ForwardIter __last, const _Tp& __x, _Tp1*)
{
  typedef typename __type_traits<_Tp1>::is_POD_type _Is_POD;
  __uninitialized_fill_aux(__first, __last, __x, _Is_POD());

}

template <class _ForwardIter, class _Tp>
inline void uninitialized_fill(_ForwardIter __first,
                               _ForwardIter __last,
                               const _Tp& __x)
{
  __uninitialized_fill(__first, __last, __x, __value_type(__first));
}



template <class _ForwardIter, class _Size, class _Tp>
inline _ForwardIter
__uninitialized_fill_n_aux(_ForwardIter __first, _Size __n,
                           const _Tp& __x, __true_type)
{
  return fill_n(__first, __n, __x);
}

template <class _ForwardIter, class _Size, class _Tp>
_ForwardIter
__uninitialized_fill_n_aux(_ForwardIter __first, _Size __n,
                           const _Tp& __x, __false_type)
{
  _ForwardIter __cur = __first;
  try {
    for ( ; __n > 0; --__n, ++__cur)
      _Construct(&*__cur, __x);
    return __cur;
  }
  catch(...) { _Destroy(__first, __cur); throw; };
}

template <class _ForwardIter, class _Size, class _Tp, class _Tp1>
inline _ForwardIter
__uninitialized_fill_n(_ForwardIter __first, _Size __n, const _Tp& __x, _Tp1*)
{
  typedef typename __type_traits<_Tp1>::is_POD_type _Is_POD;
  return __uninitialized_fill_n_aux(__first, __n, __x, _Is_POD());
}

template <class _ForwardIter, class _Size, class _Tp>
inline _ForwardIter
uninitialized_fill_n(_ForwardIter __first, _Size __n, const _Tp& __x)
{
  return __uninitialized_fill_n(__first, __n, __x, __value_type(__first));
}
# 260 "/usr/local/include/g++-v3/bits/stl_uninitialized.h" 3
template <class _InputIter1, class _InputIter2, class _ForwardIter>
inline _ForwardIter
__uninitialized_copy_copy(_InputIter1 __first1, _InputIter1 __last1,
                          _InputIter2 __first2, _InputIter2 __last2,
                          _ForwardIter __result)
{
  _ForwardIter __mid = uninitialized_copy(__first1, __last1, __result);
  try {
    return uninitialized_copy(__first2, __last2, __mid);
  }
  catch(...) { _Destroy(__result, __mid); throw; };
}




template <class _ForwardIter, class _Tp, class _InputIter>
inline _ForwardIter
__uninitialized_fill_copy(_ForwardIter __result, _ForwardIter __mid,
                          const _Tp& __x,
                          _InputIter __first, _InputIter __last)
{
  uninitialized_fill(__result, __mid, __x);
  try {
    return uninitialized_copy(__first, __last, __mid);
  }
  catch(...) { _Destroy(__result, __mid); throw; };
}




template <class _InputIter, class _ForwardIter, class _Tp>
inline void
__uninitialized_copy_fill(_InputIter __first1, _InputIter __last1,
                          _ForwardIter __first2, _ForwardIter __last2,
                          const _Tp& __x)
{
  _ForwardIter __mid2 = uninitialized_copy(__first1, __last1, __first2);
  try {
    uninitialized_fill(__mid2, __last2, __x);
  }
  catch(...) { _Destroy(__first2, __mid2); throw; };
}

}
# 55 "/usr/local/include/g++-v3/bits/std_memory.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/stl_raw_storage_iter.h" 1 3
# 63 "/usr/local/include/g++-v3/bits/stl_raw_storage_iter.h" 3
namespace std
{

template <class _ForwardIterator, class _Tp>
class raw_storage_iterator {
protected:
  _ForwardIterator _M_iter;
public:
  typedef output_iterator_tag iterator_category;
  typedef void value_type;
  typedef void difference_type;
  typedef void pointer;
  typedef void reference;

  explicit raw_storage_iterator(_ForwardIterator __x) : _M_iter(__x) {}
  raw_storage_iterator& operator*() { return *this; }
  raw_storage_iterator& operator=(const _Tp& __element) {
    construct(&*_M_iter, __element);
    return *this;
  }
  raw_storage_iterator<_ForwardIterator, _Tp>& operator++() {
    ++_M_iter;
    return *this;
  }
  raw_storage_iterator<_ForwardIterator, _Tp> operator++(int) {
    raw_storage_iterator<_ForwardIterator, _Tp> __tmp = *this;
    ++_M_iter;
    return __tmp;
  }
};


}
# 56 "/usr/local/include/g++-v3/bits/std_memory.h" 2 3

namespace std
{

 template<class _Tp1> struct auto_ptr_ref {
   _Tp1* _M_ptr;
   auto_ptr_ref(_Tp1* __p) : _M_ptr(__p) {}
};

template <class _Tp> class auto_ptr {
private:
  _Tp* _M_ptr;

public:
  typedef _Tp element_type;

  explicit auto_ptr(_Tp* __p = 0) throw() : _M_ptr(__p) {}
  auto_ptr(auto_ptr& __a) throw() : _M_ptr(__a.release()) {}

  template <class _Tp1> auto_ptr(auto_ptr<_Tp1>& __a) throw()
    : _M_ptr(__a.release()) {}

  auto_ptr& operator=(auto_ptr& __a) throw() {
    reset(__a.release());
    return *this;
  }

  template <class _Tp1>
  auto_ptr& operator=(auto_ptr<_Tp1>& __a) throw() {
    reset(__a.release());
    return *this;
  }





  ~auto_ptr() { delete _M_ptr; }

  _Tp& operator*() const throw() {
    return *_M_ptr;
  }
  _Tp* operator->() const throw() {
    return _M_ptr;
  }
  _Tp* get() const throw() {
    return _M_ptr;
  }
  _Tp* release() throw() {
    _Tp* __tmp = _M_ptr;
    _M_ptr = 0;
    return __tmp;
  }
  void reset(_Tp* __p = 0) throw() {
    if (__p != _M_ptr) {
      delete _M_ptr;
      _M_ptr = __p;
    }
  }





public:
  auto_ptr(auto_ptr_ref<_Tp> __ref) throw()
    : _M_ptr(__ref._M_ptr) {}

  auto_ptr& operator=(auto_ptr_ref<_Tp> __ref) throw() {
    if (__ref._M_ptr != this->get()) {
      delete _M_ptr;
      _M_ptr = __ref._M_ptr;
    }
    return *this;
  }

  template <class _Tp1> operator auto_ptr_ref<_Tp1>() throw()
    { return auto_ptr_ref<_Tp>(this->release()); }
  template <class _Tp1> operator auto_ptr<_Tp1>() throw()
    { return auto_ptr<_Tp1>(this->release()); }
};

}
# 44 "/usr/local/include/g++-v3/bits/std_string.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/type_traits.h" 1 3
# 45 "/usr/local/include/g++-v3/bits/std_string.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_iosfwd.h" 1 3
# 46 "/usr/local/include/g++-v3/bits/std_string.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/basic_string.h" 1 3
# 38 "/usr/local/include/g++-v3/bits/basic_string.h" 3

# 1 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/atomicity.h" 1 3
# 33 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/atomicity.h" 3
typedef int _Atomic_word;

static inline _Atomic_word
__attribute__ ((__unused__))
__exchange_and_add (volatile _Atomic_word *__mem, int __val)
{
  register _Atomic_word __result;
  __asm__ __volatile__ ("lock; xaddl %0,%2"
                        : "=r" (__result)
                        : "0" (__val), "m" (*__mem)
                        : "memory");
  return __result;
}

static inline void
__attribute__ ((__unused__))
__atomic_add (volatile _Atomic_word* __mem, int __val)
{
  __asm__ __volatile__ ("lock; addl %0,%1"
                        : : "ir" (__val), "m" (*__mem) : "memory");
}

static inline char
__attribute__ ((__unused__))
__compare_and_swap (volatile long* __p, long __oldval, long __newval)
{
  char __ret;
  long __readval;

  __asm__ __volatile__ ("lock; cmpxchgl %3, %1; sete %0"
                        : "=q" (__ret), "=m" (*__p), "=a" (__readval)
                        : "r" (__newval), "m" (*__p), "a" (__oldval));
  return __ret;
}
# 40 "/usr/local/include/g++-v3/bits/basic_string.h" 2 3

namespace std
{
# 83 "/usr/local/include/g++-v3/bits/basic_string.h" 3
  template<typename _CharT, typename _Traits, typename _Alloc>
    class basic_string
    {

    public:
      typedef _Traits traits_type;
      typedef typename _Traits::char_type value_type;
      typedef _Alloc allocator_type;
      typedef typename _Alloc::size_type size_type;
      typedef typename _Alloc::difference_type difference_type;
      typedef typename _Alloc::reference reference;
      typedef typename _Alloc::const_reference const_reference;
      typedef typename _Alloc::pointer pointer;
      typedef typename _Alloc::const_pointer const_pointer;
      typedef __normal_iterator<pointer, basic_string> iterator;
      typedef __normal_iterator<const_pointer, basic_string> const_iterator;
      typedef reverse_iterator<const_iterator> const_reverse_iterator;
      typedef reverse_iterator<iterator> reverse_iterator;

    private:
# 118 "/usr/local/include/g++-v3/bits/basic_string.h" 3
      struct _Rep
      {

        typedef typename _Alloc::template rebind<char>::other _Raw_bytes_alloc;
# 136 "/usr/local/include/g++-v3/bits/basic_string.h" 3
        static const size_type _S_max_size;
        static const _CharT _S_terminal;

        size_type _M_length;
        size_type _M_capacity;
        _Atomic_word _M_references;

        bool
        _M_is_leaked() const
        { return _M_references < 0; }

        bool
        _M_is_shared() const
        { return _M_references > 0; }

        void
        _M_set_leaked()
        { _M_references = -1; }

        void
        _M_set_sharable()
        { _M_references = 0; }

        _CharT*
        _M_refdata() throw()
        { return reinterpret_cast<_CharT*> (this + 1); }

        _CharT&
        operator[](size_t __s) throw()
        { return _M_refdata() [__s]; }

        _CharT*
        _M_grab(const _Alloc& __alloc1, const _Alloc& __alloc2)
        { return (!_M_is_leaked() && __alloc1 == __alloc2) ?
            _M_refcopy() : _M_clone(__alloc1); }


        static _Rep*
        _S_create(size_t, const _Alloc&);

        void
        _M_dispose(const _Alloc& __a)
        {
          if (__exchange_and_add(&_M_references, -1) <= 0)
            _M_destroy(__a);
        }

        void
        _M_destroy(const _Alloc&) throw();

        _CharT*
        _M_refcopy() throw()
        {
          __atomic_add(&_M_references, 1);
          return _M_refdata();
        }

        _CharT*
        _M_clone(const _Alloc&, size_type __res = 0);
# 208 "/usr/local/include/g++-v3/bits/basic_string.h" 3
        inline static bool
        _S_excess_slop(size_t, size_t);

      };


      struct _Alloc_hider : _Alloc
      {
        _Alloc_hider(_CharT* __dat, const _Alloc& __a)
        : _Alloc(__a), _M_p(__dat) { }

        _CharT* _M_p;
      };

    public:



      static const size_type npos = static_cast<size_type>(-1);

    private:

      mutable _Alloc_hider _M_dataplus;



      static size_type _S_empty_rep_storage[(sizeof(_Rep) + sizeof(_CharT) + sizeof(size_type) - 1)/sizeof(size_type)];

      _CharT*
      _M_data() const
      { return _M_dataplus._M_p; }

      _CharT*
      _M_data(_CharT* __p)
      { return (_M_dataplus._M_p = __p); }

      _Rep*
      _M_rep() const
      { return &((reinterpret_cast<_Rep*> (_M_data()))[-1]); }



      iterator
      _M_ibegin() const { return iterator(_M_data()); }

      iterator
      _M_iend() const { return iterator(_M_data() + this->size()); }

      void
      _M_leak()
      {
        if (!_M_rep()->_M_is_leaked())
          _M_leak_hard();
      }

      iterator
      _M_check(size_type __pos) const
      {
        if (__pos > this->size())
          __throw_out_of_range("basic_string::_M_check");
        return _M_ibegin() + __pos;
      }


      iterator
      _M_fold(size_type __pos, size_type __off) const
      {
        bool __testoff = __off < this->size() - __pos;
        size_type __newoff = __testoff ? __off : this->size() - __pos;
        return (_M_ibegin() + __pos + __newoff);
      }



      template<class _Iterator>
        static void
        _S_copy_chars(_CharT* __p, _Iterator __k1, _Iterator __k2)
        {
          for (; __k1 != __k2; ++__k1, ++__p)
            traits_type::assign(*__p, *__k1);
        }

      static void
      _S_copy_chars(_CharT* __p, iterator __k1, iterator __k2)
      { _S_copy_chars(__p, __k1.base(), __k2.base()); }

      static void
      _S_copy_chars(_CharT* __p, const_iterator __k1, const_iterator __k2)
      { _S_copy_chars(__p, __k1.base(), __k2.base()); }

      static void
      _S_copy_chars(_CharT* __p, _CharT* __k1, _CharT* __k2)
      { traits_type::copy(__p, __k1, __k2 - __k1); }

      static void
      _S_copy_chars(_CharT* __p, const _CharT* __k1, const _CharT* __k2)
      { traits_type::copy(__p, __k1, __k2 - __k1); }

      void
      _M_mutate(size_type __pos, size_type __len1, size_type __len2);

      void
      _M_leak_hard();

      static _Rep&
      _S_empty_rep()
      { return *reinterpret_cast<_Rep*>(&_S_empty_rep_storage); }

    public:




      inline
      basic_string();

      explicit
      basic_string(const _Alloc& __a);


      basic_string(const basic_string& __str);
      basic_string(const basic_string& __str, size_type __pos,
                   size_type __n = npos);
      basic_string(const basic_string& __str, size_type __pos,
                   size_type __n, const _Alloc& __a);

      basic_string(const _CharT* __s, size_type __n,
                   const _Alloc& __a = _Alloc());
      basic_string(const _CharT* __s, const _Alloc& __a = _Alloc());
      basic_string(size_type __n, _CharT __c, const _Alloc& __a = _Alloc());

      template<class _InputIterator>
        basic_string(_InputIterator __begin, _InputIterator __end,
                     const _Alloc& __a = _Alloc());

      ~basic_string()
      { _M_rep()->_M_dispose(this->get_allocator()); }

      basic_string&
      operator=(const basic_string& __str) { return this->assign(__str); }

      basic_string&
      operator=(const _CharT* __s) { return this->assign(__s); }

      basic_string&
      operator=(_CharT __c) { return this->assign(1, __c); }


      iterator
      begin()
      {
        _M_leak();
        return iterator(_M_data());
      }

      const_iterator
      begin() const
      { return const_iterator(_M_data()); }

      iterator
      end()
      {
         _M_leak();
         return iterator(_M_data() + this->size());
      }

      const_iterator
      end() const
      { return const_iterator(_M_data() + this->size()); }

      reverse_iterator
      rbegin()
      { return reverse_iterator(this->end()); }

      const_reverse_iterator
      rbegin() const
      { return const_reverse_iterator(this->end()); }

      reverse_iterator
      rend()
      { return reverse_iterator(this->begin()); }

      const_reverse_iterator
      rend() const
      { return const_reverse_iterator(this->begin()); }

    public:

      size_type
      size() const { return _M_rep()->_M_length; }

      size_type
      length() const { return _M_rep()->_M_length; }

      size_type
      max_size() const { return _Rep::_S_max_size; }

      void
      resize(size_type __n, _CharT __c);

      void
      resize(size_type __n) { this->resize(__n, _CharT()); }

      size_type
      capacity() const { return _M_rep()->_M_capacity; }

      void
      reserve(size_type __res_arg = 0);

      void
      clear() { _M_mutate(0, this->size(), 0); }

      bool
      empty() const { return this->size() == 0; }


      const_reference
      operator[] (size_type __pos) const
      { return _M_data()[__pos]; }

      reference
      operator[](size_type __pos)
      {
        _M_leak();
        return _M_data()[__pos];
      }

      const_reference
      at(size_type __n) const
      {
        if (__n >= this->size())
          __throw_out_of_range("basic_string::at");
        return _M_data()[__n];
      }

      reference
      at(size_type __n)
      {
        if (__n >= size())
          __throw_out_of_range("basic_string::at");
        _M_leak();
        return _M_data()[__n];
      }


      basic_string&
      operator+=(const basic_string& __str) { return this->append(__str); }

      basic_string&
      operator+=(const _CharT* __s) { return this->append(__s); }

      basic_string&
      operator+=(_CharT __c) { return this->append(size_type(1), __c); }

      basic_string&
      append(const basic_string& __str);

      basic_string&
      append(const basic_string& __str, size_type __pos, size_type __n);

      basic_string&
      append(const _CharT* __s, size_type __n);

      basic_string&
      append(const _CharT* __s)
      { return this->append(__s, traits_type::length(__s)); }

      basic_string&
      append(size_type __n, _CharT __c);

      template<class _InputIterator>
        basic_string&
        append(_InputIterator __first, _InputIterator __last)
        { return this->replace(_M_iend(), _M_iend(), __first, __last); }

      void
      push_back(_CharT __c)
      { this->replace(_M_iend(), _M_iend(), 1, __c); }

      basic_string&
      assign(const basic_string& __str);

      basic_string&
      assign(const basic_string& __str, size_type __pos, size_type __n)
      {
        return this->assign(__str._M_check(__pos), __str._M_fold(__pos, __n));
      }

      basic_string&
      assign(const _CharT* __s, size_type __n)
      { return this->assign(__s, __s + __n); }

      basic_string&
      assign(const _CharT* __s)
      { return this->assign(__s, __s + traits_type::length(__s)); }

      basic_string&
      assign(size_type __n, _CharT __c)
      { return this->replace(_M_ibegin(), _M_iend(), __n, __c); }

      template<class _InputIterator>
        basic_string&
        assign(_InputIterator __first, _InputIterator __last)
        { return this->replace(_M_ibegin(), _M_iend(), __first, __last); }

      void
      insert(iterator __p, size_type __n, _CharT __c)
      { this->replace(__p, __p, __n, __c); }

      template<class _InputIterator>
        void insert(iterator __p, _InputIterator __beg, _InputIterator __end)
        { this->replace(__p, __p, __beg, __end); }

      basic_string&
      insert(size_type __pos1, const basic_string& __str)
      {
        iterator __p = _M_check(__pos1);
        this->replace(__p, __p, __str._M_ibegin(), __str._M_iend());
        return *this;
      }

      basic_string&
      insert(size_type __pos1, const basic_string& __str,
             size_type __pos2, size_type __n)
      {
        iterator __p = _M_check(__pos1);
        this->replace(__p, __p, __str._M_check(__pos2),
                      __str._M_fold(__pos2, __n));
        return *this;
      }

      basic_string&
      insert(size_type __pos, const _CharT* __s, size_type __n)
      {
        iterator __p = _M_check(__pos);
        this->replace(__p, __p, __s, __s + __n);
        return *this;
      }

      basic_string&
      insert(size_type __pos, const _CharT* __s)
      { return this->insert(__pos, __s, traits_type::length(__s)); }

      basic_string&
      insert(size_type __pos, size_type __n, _CharT __c)
      {
        this->insert(_M_check(__pos), __n, __c);
        return *this;
      }

      iterator
      insert(iterator __p, _CharT __c = _CharT())
      {
        size_type __pos = __p - _M_ibegin();
        this->insert(_M_check(__pos), size_type(1), __c);
        _M_rep()->_M_set_leaked();
        return this->_M_ibegin() + __pos;
      }

      basic_string&
      erase(size_type __pos = 0, size_type __n = npos)
      {
        return this->replace(_M_check(__pos), _M_fold(__pos, __n),
                             _M_data(), _M_data());
      }

      iterator
      erase(iterator __position)
      {
        size_type __i = __position - _M_ibegin();
        this->replace(__position, __position + 1, _M_data(), _M_data());
        _M_rep()->_M_set_leaked();
        return _M_ibegin() + __i;
      }

      iterator
      erase(iterator __first, iterator __last)
      {
        size_type __i = __first - _M_ibegin();
        this->replace(__first, __last, _M_data(), _M_data());
        _M_rep()->_M_set_leaked();
       return _M_ibegin() + __i;
      }

      basic_string&
      replace(size_type __pos, size_type __n, const basic_string& __str)
      {
        return this->replace(_M_check(__pos), _M_fold(__pos, __n),
                              __str.begin(), __str.end());
      }

      basic_string&
      replace(size_type __pos1, size_type __n1, const basic_string& __str,
              size_type __pos2, size_type __n2);

      basic_string&
      replace(size_type __pos, size_type __n1, const _CharT* __s,
              size_type __n2)
      {
        return this->replace(_M_check(__pos), _M_fold(__pos, __n1),
                             __s, __s + __n2);
      }

      basic_string&
      replace(size_type __pos, size_type __n1, const _CharT* __s)
      {
        return this->replace(_M_check(__pos), _M_fold(__pos, __n1),
                             __s, __s + traits_type::length(__s));
      }

      basic_string&
      replace(size_type __pos, size_type __n1, size_type __n2, _CharT __c)
      {
        return this->replace(_M_check(__pos), _M_fold(__pos, __n1), __n2, __c);
      }

      basic_string&
      replace(iterator __i1, iterator __i2, const basic_string& __str)
      { return this->replace(__i1, __i2, __str.begin(), __str.end()); }

      basic_string&
      replace(iterator __i1, iterator __i2,
                           const _CharT* __s, size_type __n)
      { return this->replace(__i1, __i2, __s, __s + __n); }

      basic_string&
      replace(iterator __i1, iterator __i2, const _CharT* __s)
      { return this->replace(__i1, __i2, __s,
                             __s + traits_type::length(__s)); }

      basic_string&
      replace(iterator __i1, iterator __i2, size_type __n, _CharT __c);

      template<class _InputIterator>
        basic_string&
        replace(iterator __i1, iterator __i2,
                _InputIterator __k1, _InputIterator __k2)
        { return _M_replace(__i1, __i2, __k1, __k2,
             typename iterator_traits<_InputIterator>::iterator_category()); }

    private:
      template<class _InputIterator>
        basic_string&
        _M_replace(iterator __i1, iterator __i2, _InputIterator __k1,
                   _InputIterator __k2, input_iterator_tag);

      template<class _FwdIterator>
        basic_string&
        _M_replace(iterator __i1, iterator __i2, _FwdIterator __k1,
                   _FwdIterator __k2, forward_iterator_tag);



      template<class _InIter>
        static _CharT*
        _S_construct_aux(_InIter __beg, _InIter __end, const _Alloc& __a,
                         __false_type)
        {
          typedef typename iterator_traits<_InIter>::iterator_category _Tag;
          return _S_construct(__beg, __end, __a, _Tag());
        }

      template<class _InIter>
        static _CharT*
        _S_construct_aux(_InIter __beg, _InIter __end, const _Alloc& __a,
                         __true_type)
        {
          return _S_construct(static_cast<size_type>(__beg),
                              static_cast<value_type>(__end), __a);
        }

      template<class _InIter>
        static _CharT*
        _S_construct(_InIter __beg, _InIter __end, const _Alloc& __a)
        {
          typedef typename _Is_integer<_InIter>::_Integral _Integral;
          return _S_construct_aux(__beg, __end, __a, _Integral());
        }


      template<class _InIter>
        static _CharT*
         _S_construct(_InIter __beg, _InIter __end, const _Alloc& __a,
                      input_iterator_tag);



      template<class _FwdIter>
        static _CharT*
        _S_construct(_FwdIter __end, _FwdIter __beg, const _Alloc& __a,
                     forward_iterator_tag);

      static _CharT*
      _S_construct(size_type __req, _CharT __c, const _Alloc& __a);

    public:

      size_type
      copy(_CharT* __s, size_type __n, size_type __pos = 0) const;

      void
      swap(basic_string<_CharT, _Traits, _Alloc>& __s);


      const _CharT*
      c_str() const
      {

        size_type __n = this->size();
        traits_type::assign(_M_data()[__n], _Rep::_S_terminal);
        return _M_data();
      }

      const _CharT*
      data() const { return _M_data(); }

      allocator_type
      get_allocator() const { return _M_dataplus; }

      size_type
      find(const _CharT* __s, size_type __pos, size_type __n) const;

      size_type
      find(const basic_string& __str, size_type __pos = 0) const
      { return this->find(__str.data(), __pos, __str.size()); }

      size_type
      find(const _CharT* __s, size_type __pos = 0) const
      { return this->find(__s, __pos, traits_type::length(__s)); }

      size_type
      find(_CharT __c, size_type __pos = 0) const;

      size_type
      rfind(const basic_string& __str, size_type __pos = npos) const
      { return this->rfind(__str.data(), __pos, __str.size()); }

      size_type
      rfind(const _CharT* __s, size_type __pos, size_type __n) const;

      size_type
      rfind(const _CharT* __s, size_type __pos = npos) const
      { return this->rfind(__s, __pos, traits_type::length(__s)); }

      size_type
      rfind(_CharT __c, size_type __pos = npos) const;

      size_type
      find_first_of(const basic_string& __str, size_type __pos = 0) const
      { return this->find_first_of(__str.data(), __pos, __str.size()); }

      size_type
      find_first_of(const _CharT* __s, size_type __pos, size_type __n) const;

      size_type
      find_first_of(const _CharT* __s, size_type __pos = 0) const
      { return this->find_first_of(__s, __pos, traits_type::length(__s)); }

      size_type
      find_first_of(_CharT __c, size_type __pos = 0) const
      { return this->find(__c, __pos); }

      size_type
      find_last_of(const basic_string& __str, size_type __pos = npos) const
      { return this->find_last_of(__str.data(), __pos, __str.size()); }

      size_type
      find_last_of(const _CharT* __s, size_type __pos, size_type __n) const;

      size_type
      find_last_of(const _CharT* __s, size_type __pos = npos) const
      { return this->find_last_of(__s, __pos, traits_type::length(__s)); }

      size_type
      find_last_of(_CharT __c, size_type __pos = npos) const
      { return this->rfind(__c, __pos); }

      size_type
      find_first_not_of(const basic_string& __str, size_type __pos = 0) const
      { return this->find_first_not_of(__str.data(), __pos, __str.size()); }

      size_type
      find_first_not_of(const _CharT* __s, size_type __pos,
                        size_type __n) const;

      size_type
      find_first_not_of(const _CharT* __s, size_type __pos = 0) const
      { return this->find_first_not_of(__s, __pos, traits_type::length(__s)); }

      size_type
      find_first_not_of(_CharT __c, size_type __pos = 0) const;

      size_type
      find_last_not_of(const basic_string& __str, size_type __pos = npos) const
      { return this->find_last_not_of(__str.data(), __pos, __str.size()); }

      size_type
      find_last_not_of(const _CharT* __s, size_type __pos,
                       size_type __n) const;
      size_type
      find_last_not_of(const _CharT* __s, size_type __pos = npos) const
      { return this->find_last_not_of(__s, __pos, traits_type::length(__s)); }

      size_type
      find_last_not_of(_CharT __c, size_type __pos = npos) const;

      basic_string
      substr(size_type __pos = 0, size_type __n = npos) const
      {
        if (__pos > this->size())
          __throw_out_of_range("basic_string::substr");
        return basic_string(*this, __pos, __n);
      }

      int
      compare(const basic_string& __str) const
      {
        size_type __size = this->size();
        size_type __osize = __str.size();
        size_type __len = min(__size, __osize);

        int __r = traits_type::compare(_M_data(), __str.data(), __len);
        if (!__r)
          __r = __size - __osize;
        return __r;
      }

      int
      compare(size_type __pos, size_type __n, const basic_string& __str) const;

      int
      compare(size_type __pos1, size_type __n1, const basic_string& __str,
              size_type __pos2, size_type __n2) const;

      int
      compare(const _CharT* __s) const;



      int
      compare(size_type __pos, size_type __n1, const _CharT* __s) const;

      int
      compare(size_type __pos, size_type __n1, const _CharT* __s,
              size_type __n2) const;

  };


  template<typename _CharT, typename _Traits, typename _Alloc>
    inline basic_string<_CharT, _Traits, _Alloc>::
    basic_string()
    : _M_dataplus(_S_empty_rep()._M_refcopy(), _Alloc()) { }


  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT, _Traits, _Alloc>
    operator+(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
              const basic_string<_CharT, _Traits, _Alloc>& __rhs)
    {
      basic_string<_CharT, _Traits, _Alloc> __str(__lhs);
      __str.append(__rhs);
      return __str;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT,_Traits,_Alloc>
    operator+(const _CharT* __lhs,
              const basic_string<_CharT,_Traits,_Alloc>& __rhs);

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT,_Traits,_Alloc>
    operator+(_CharT __lhs, const basic_string<_CharT,_Traits,_Alloc>& __rhs);

  template<typename _CharT, typename _Traits, typename _Alloc>
    inline basic_string<_CharT, _Traits, _Alloc>
    operator+(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
             const _CharT* __rhs)
    {
      basic_string<_CharT, _Traits, _Alloc> __str(__lhs);
      __str.append(__rhs);
      return __str;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    inline basic_string<_CharT, _Traits, _Alloc>
    operator+(const basic_string<_CharT, _Traits, _Alloc>& __lhs, _CharT __rhs)
    {
      typedef basic_string<_CharT, _Traits, _Alloc> __string_type;
      typedef typename __string_type::size_type __size_type;
      __string_type __str(__lhs);
      __str.append(__size_type(1), __rhs);
      return __str;
    }


  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator==(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
               const basic_string<_CharT, _Traits, _Alloc>& __rhs)
    { return __lhs.compare(__rhs) == 0; }

  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator==(const _CharT* __lhs,
               const basic_string<_CharT, _Traits, _Alloc>& __rhs)
    { return __rhs.compare(__lhs) == 0; }

  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator==(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
               const _CharT* __rhs)
    { return __lhs.compare(__rhs) == 0; }


  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator!=(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
               const basic_string<_CharT, _Traits, _Alloc>& __rhs)
    { return __rhs.compare(__lhs) != 0; }

  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator!=(const _CharT* __lhs,
               const basic_string<_CharT, _Traits, _Alloc>& __rhs)
    { return __rhs.compare(__lhs) != 0; }

  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator!=(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
               const _CharT* __rhs)
    { return __lhs.compare(__rhs) != 0; }


  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator<(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
              const basic_string<_CharT, _Traits, _Alloc>& __rhs)
    { return __lhs.compare(__rhs) < 0; }

  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator<(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
              const _CharT* __rhs)
    { return __lhs.compare(__rhs) < 0; }

  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator<(const _CharT* __lhs,
              const basic_string<_CharT, _Traits, _Alloc>& __rhs)
    { return __rhs.compare(__lhs) > 0; }


  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator>(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
              const basic_string<_CharT, _Traits, _Alloc>& __rhs)
    { return __lhs.compare(__rhs) > 0; }

  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator>(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
              const _CharT* __rhs)
    { return __lhs.compare(__rhs) > 0; }

  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator>(const _CharT* __lhs,
              const basic_string<_CharT, _Traits, _Alloc>& __rhs)
    { return __rhs.compare(__lhs) < 0; }


  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator<=(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
               const basic_string<_CharT, _Traits, _Alloc>& __rhs)
    { return __lhs.compare(__rhs) <= 0; }

  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator<=(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
               const _CharT* __rhs)
    { return __lhs.compare(__rhs) <= 0; }

  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator<=(const _CharT* __lhs,
               const basic_string<_CharT, _Traits, _Alloc>& __rhs)
  { return __rhs.compare(__lhs) >= 0; }


  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator>=(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
               const basic_string<_CharT, _Traits, _Alloc>& __rhs)
    { return __lhs.compare(__rhs) >= 0; }

  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator>=(const basic_string<_CharT, _Traits, _Alloc>& __lhs,
               const _CharT* __rhs)
    { return __lhs.compare(__rhs) >= 0; }

  template<typename _CharT, typename _Traits, typename _Alloc>
    inline bool
    operator>=(const _CharT* __lhs,
             const basic_string<_CharT, _Traits, _Alloc>& __rhs)
    { return __rhs.compare(__lhs) <= 0; }


  template<typename _CharT, typename _Traits, typename _Alloc>
    inline void
    swap(basic_string<_CharT, _Traits, _Alloc>& __lhs,
         basic_string<_CharT, _Traits, _Alloc>& __rhs)
    { __lhs.swap(__rhs); }

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_istream<_CharT, _Traits>&
    operator>>(basic_istream<_CharT, _Traits>& __is,
               basic_string<_CharT, _Traits, _Alloc>& __str);

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __os,
               const basic_string<_CharT, _Traits, _Alloc>& __str);

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_istream<_CharT,_Traits>&
    getline(basic_istream<_CharT, _Traits>& __is,
            basic_string<_CharT, _Traits, _Alloc>& __str, _CharT __delim);

  template<typename _CharT, typename _Traits, typename _Alloc>
    inline basic_istream<_CharT,_Traits>&
    getline(basic_istream<_CharT, _Traits>& __is,
            basic_string<_CharT, _Traits, _Alloc>& __str);
}
# 47 "/usr/local/include/g++-v3/bits/std_string.h" 2 3


# 1 "/usr/local/include/g++-v3/bits/std_algorithm.h" 1 3
# 60 "/usr/local/include/g++-v3/bits/std_algorithm.h" 3

# 1 "/usr/local/include/g++-v3/bits/stl_algobase.h" 1 3
# 62 "/usr/local/include/g++-v3/bits/std_algorithm.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/stl_construct.h" 1 3
# 63 "/usr/local/include/g++-v3/bits/std_algorithm.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/stl_uninitialized.h" 1 3
# 64 "/usr/local/include/g++-v3/bits/std_algorithm.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/stl_tempbuf.h" 1 3
# 65 "/usr/local/include/g++-v3/bits/std_algorithm.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/stl_algo.h" 1 3
# 63 "/usr/local/include/g++-v3/bits/stl_algo.h" 3
# 1 "/usr/local/include/g++-v3/bits/stl_heap.h" 1 3
# 62 "/usr/local/include/g++-v3/bits/stl_heap.h" 3
namespace std
{



template <class _RandomAccessIterator, class _Distance, class _Tp>
void
__push_heap(_RandomAccessIterator __first,
            _Distance __holeIndex, _Distance __topIndex, _Tp __value)
{
  _Distance __parent = (__holeIndex - 1) / 2;
  while (__holeIndex > __topIndex && *(__first + __parent) < __value) {
    *(__first + __holeIndex) = *(__first + __parent);
    __holeIndex = __parent;
    __parent = (__holeIndex - 1) / 2;
  }
  *(__first + __holeIndex) = __value;
}

template <class _RandomAccessIterator, class _Distance, class _Tp>
inline void
__push_heap_aux(_RandomAccessIterator __first,
                _RandomAccessIterator __last, _Distance*, _Tp*)
{
  __push_heap(__first, _Distance((__last - __first) - 1), _Distance(0),
              _Tp(*(__last - 1)));
}

template <class _RandomAccessIterator>
inline void
push_heap(_RandomAccessIterator __first, _RandomAccessIterator __last)
{

                               ;

                                                                     ;


  __push_heap_aux(__first, __last,
                  __distance_type(__first), __value_type(__first));
}

template <class _RandomAccessIterator, class _Distance, class _Tp,
          class _Compare>
void
__push_heap(_RandomAccessIterator __first, _Distance __holeIndex,
            _Distance __topIndex, _Tp __value, _Compare __comp)
{
  _Distance __parent = (__holeIndex - 1) / 2;
  while (__holeIndex > __topIndex && __comp(*(__first + __parent), __value)) {
    *(__first + __holeIndex) = *(__first + __parent);
    __holeIndex = __parent;
    __parent = (__holeIndex - 1) / 2;
  }
  *(__first + __holeIndex) = __value;
}

template <class _RandomAccessIterator, class _Compare,
          class _Distance, class _Tp>
inline void
__push_heap_aux(_RandomAccessIterator __first,
                _RandomAccessIterator __last, _Compare __comp,
                _Distance*, _Tp*)
{
  __push_heap(__first, _Distance((__last - __first) - 1), _Distance(0),
              _Tp(*(__last - 1)), __comp);
}

template <class _RandomAccessIterator, class _Compare>
inline void
push_heap(_RandomAccessIterator __first, _RandomAccessIterator __last,
          _Compare __comp)
{

                               ;


  __push_heap_aux(__first, __last, __comp,
                  __distance_type(__first), __value_type(__first));
}

template <class _RandomAccessIterator, class _Distance, class _Tp>
void
__adjust_heap(_RandomAccessIterator __first, _Distance __holeIndex,
              _Distance __len, _Tp __value)
{
  _Distance __topIndex = __holeIndex;
  _Distance __secondChild = 2 * __holeIndex + 2;
  while (__secondChild < __len) {
    if (*(__first + __secondChild) < *(__first + (__secondChild - 1)))
      __secondChild--;
    *(__first + __holeIndex) = *(__first + __secondChild);
    __holeIndex = __secondChild;
    __secondChild = 2 * (__secondChild + 1);
  }
  if (__secondChild == __len) {
    *(__first + __holeIndex) = *(__first + (__secondChild - 1));
    __holeIndex = __secondChild - 1;
  }
  __push_heap(__first, __holeIndex, __topIndex, __value);
}

template <class _RandomAccessIterator, class _Tp, class _Distance>
inline void
__pop_heap(_RandomAccessIterator __first, _RandomAccessIterator __last,
           _RandomAccessIterator __result, _Tp __value, _Distance*)
{
  *__result = *__first;
  __adjust_heap(__first, _Distance(0), _Distance(__last - __first), __value);
}

template <class _RandomAccessIterator, class _Tp>
inline void
__pop_heap_aux(_RandomAccessIterator __first, _RandomAccessIterator __last,
               _Tp*)
{
  __pop_heap(__first, __last - 1, __last - 1,
             _Tp(*(__last - 1)), __distance_type(__first));
}

template <class _RandomAccessIterator>
inline void pop_heap(_RandomAccessIterator __first,
                     _RandomAccessIterator __last)
{

                               ;

                                                                     ;


  __pop_heap_aux(__first, __last, __value_type(__first));
}

template <class _RandomAccessIterator, class _Distance,
          class _Tp, class _Compare>
void
__adjust_heap(_RandomAccessIterator __first, _Distance __holeIndex,
              _Distance __len, _Tp __value, _Compare __comp)
{
  _Distance __topIndex = __holeIndex;
  _Distance __secondChild = 2 * __holeIndex + 2;
  while (__secondChild < __len) {
    if (__comp(*(__first + __secondChild), *(__first + (__secondChild - 1))))
      __secondChild--;
    *(__first + __holeIndex) = *(__first + __secondChild);
    __holeIndex = __secondChild;
    __secondChild = 2 * (__secondChild + 1);
  }
  if (__secondChild == __len) {
    *(__first + __holeIndex) = *(__first + (__secondChild - 1));
    __holeIndex = __secondChild - 1;
  }
  __push_heap(__first, __holeIndex, __topIndex, __value, __comp);
}

template <class _RandomAccessIterator, class _Tp, class _Compare,
          class _Distance>
inline void
__pop_heap(_RandomAccessIterator __first, _RandomAccessIterator __last,
           _RandomAccessIterator __result, _Tp __value, _Compare __comp,
           _Distance*)
{
  *__result = *__first;
  __adjust_heap(__first, _Distance(0), _Distance(__last - __first),
                __value, __comp);
}

template <class _RandomAccessIterator, class _Tp, class _Compare>
inline void
__pop_heap_aux(_RandomAccessIterator __first,
               _RandomAccessIterator __last, _Tp*, _Compare __comp)
{
  __pop_heap(__first, __last - 1, __last - 1, _Tp(*(__last - 1)), __comp,
             __distance_type(__first));
}

template <class _RandomAccessIterator, class _Compare>
inline void
pop_heap(_RandomAccessIterator __first,
         _RandomAccessIterator __last, _Compare __comp)
{

                               ;


  __pop_heap_aux(__first, __last, __value_type(__first), __comp);
}

template <class _RandomAccessIterator, class _Tp, class _Distance>
void
__make_heap(_RandomAccessIterator __first,
            _RandomAccessIterator __last, _Tp*, _Distance*)
{
  if (__last - __first < 2) return;
  _Distance __len = __last - __first;
  _Distance __parent = (__len - 2)/2;

  while (true) {
    __adjust_heap(__first, __parent, __len, _Tp(*(__first + __parent)));
    if (__parent == 0) return;
    __parent--;
  }
}

template <class _RandomAccessIterator>
inline void
make_heap(_RandomAccessIterator __first, _RandomAccessIterator __last)
{

                               ;

                                                                     ;


  __make_heap(__first, __last,
              __value_type(__first), __distance_type(__first));
}

template <class _RandomAccessIterator, class _Compare,
          class _Tp, class _Distance>
void
__make_heap(_RandomAccessIterator __first, _RandomAccessIterator __last,
            _Compare __comp, _Tp*, _Distance*)
{
  if (__last - __first < 2) return;
  _Distance __len = __last - __first;
  _Distance __parent = (__len - 2)/2;

  while (true) {
    __adjust_heap(__first, __parent, __len, _Tp(*(__first + __parent)),
                  __comp);
    if (__parent == 0) return;
    __parent--;
  }
}

template <class _RandomAccessIterator, class _Compare>
inline void
make_heap(_RandomAccessIterator __first,
          _RandomAccessIterator __last, _Compare __comp)
{

                               ;


  __make_heap(__first, __last, __comp,
              __value_type(__first), __distance_type(__first));
}

template <class _RandomAccessIterator>
void sort_heap(_RandomAccessIterator __first, _RandomAccessIterator __last)
{

                               ;

                                                                     ;


  while (__last - __first > 1)
    pop_heap(__first, __last--);
}

template <class _RandomAccessIterator, class _Compare>
void
sort_heap(_RandomAccessIterator __first,
          _RandomAccessIterator __last, _Compare __comp)
{

                               ;


  while (__last - __first > 1)
    pop_heap(__first, __last--, __comp);
}

}
# 64 "/usr/local/include/g++-v3/bits/stl_algo.h" 2 3



namespace std
{



template <class _Tp>
inline const _Tp& __median(const _Tp& __a, const _Tp& __b, const _Tp& __c)
{

                                                              ;
  if (__a < __b)
    if (__b < __c)
      return __b;
    else if (__a < __c)
      return __c;
    else
      return __a;
  else if (__a < __c)
    return __a;
  else if (__b < __c)
    return __c;
  else
    return __b;
}

template <class _Tp, class _Compare>
inline const _Tp&
__median(const _Tp& __a, const _Tp& __b, const _Tp& __c, _Compare __comp)
{

                                                                               ;
  if (__comp(__a, __b))
    if (__comp(__b, __c))
      return __b;
    else if (__comp(__a, __c))
      return __c;
    else
      return __a;
  else if (__comp(__a, __c))
    return __a;
  else if (__comp(__b, __c))
    return __c;
  else
    return __b;
}


template <class _InputIter, class _Function>
_Function for_each(_InputIter __first, _InputIter __last, _Function __f)
{

                                                                ;
  for ( ; __first != __last; ++__first)
    __f(*__first);
  return __f;
}



template <class _InputIter, class _Tp>
inline _InputIter find(_InputIter __first, _InputIter __last,
                       const _Tp& __val,
                       input_iterator_tag)
{
  while (__first != __last && !(*__first == __val))
    ++__first;
  return __first;
}

template <class _InputIter, class _Predicate>
inline _InputIter find_if(_InputIter __first, _InputIter __last,
                          _Predicate __pred,
                          input_iterator_tag)
{
  while (__first != __last && !__pred(*__first))
    ++__first;
  return __first;
}

template <class _RandomAccessIter, class _Tp>
_RandomAccessIter find(_RandomAccessIter __first, _RandomAccessIter __last,
                       const _Tp& __val,
                       random_access_iterator_tag)
{
  typename iterator_traits<_RandomAccessIter>::difference_type __trip_count
    = (__last - __first) >> 2;

  for ( ; __trip_count > 0 ; --__trip_count) {
    if (*__first == __val) return __first;
    ++__first;

    if (*__first == __val) return __first;
    ++__first;

    if (*__first == __val) return __first;
    ++__first;

    if (*__first == __val) return __first;
    ++__first;
  }

  switch(__last - __first) {
  case 3:
    if (*__first == __val) return __first;
    ++__first;
  case 2:
    if (*__first == __val) return __first;
    ++__first;
  case 1:
    if (*__first == __val) return __first;
    ++__first;
  case 0:
  default:
    return __last;
  }
}

template <class _RandomAccessIter, class _Predicate>
_RandomAccessIter find_if(_RandomAccessIter __first, _RandomAccessIter __last,
                          _Predicate __pred,
                          random_access_iterator_tag)
{
  typename iterator_traits<_RandomAccessIter>::difference_type __trip_count
    = (__last - __first) >> 2;

  for ( ; __trip_count > 0 ; --__trip_count) {
    if (__pred(*__first)) return __first;
    ++__first;

    if (__pred(*__first)) return __first;
    ++__first;

    if (__pred(*__first)) return __first;
    ++__first;

    if (__pred(*__first)) return __first;
    ++__first;
  }

  switch(__last - __first) {
  case 3:
    if (__pred(*__first)) return __first;
    ++__first;
  case 2:
    if (__pred(*__first)) return __first;
    ++__first;
  case 1:
    if (__pred(*__first)) return __first;
    ++__first;
  case 0:
  default:
    return __last;
  }
}

template <class _InputIter, class _Tp>
inline _InputIter find(_InputIter __first, _InputIter __last,
                       const _Tp& __val)
{

                                                                ;
                                                                   ;

  return find(__first, __last, __val, __iterator_category(__first));
}

template <class _InputIter, class _Predicate>
inline _InputIter find_if(_InputIter __first, _InputIter __last,
                          _Predicate __pred)
{

                                                                ;
                                                            ;

  return find_if(__first, __last, __pred, __iterator_category(__first));
}



template <class _ForwardIter>
_ForwardIter adjacent_find(_ForwardIter __first, _ForwardIter __last)
{

                                                                    ;
                                                            ;

  if (__first == __last)
    return __last;
  _ForwardIter __next = __first;
  while(++__next != __last) {
    if (*__first == *__next)
      return __first;
    __first = __next;
  }
  return __last;
}

template <class _ForwardIter, class _BinaryPredicate>
_ForwardIter adjacent_find(_ForwardIter __first, _ForwardIter __last,
                           _BinaryPredicate __binary_pred)
{

                                                                    ;
                                                            ;


  if (__first == __last)
    return __last;
  _ForwardIter __next = __first;
  while(++__next != __last) {
    if (__binary_pred(*__first, *__next))
      return __first;
    __first = __next;
  }
  return __last;
}







template <class _InputIter, class _Tp, class _Size>
void count(_InputIter __first, _InputIter __last, const _Tp& __value,
           _Size& __n)
{

                                                                ;
                                                           ;

                                                              ;
  for ( ; __first != __last; ++__first)
    if (*__first == __value)
      ++__n;
}

template <class _InputIter, class _Predicate, class _Size>
void count_if(_InputIter __first, _InputIter __last, _Predicate __pred,
              _Size& __n)
{

                                                                ;
                                                          ;

  for ( ; __first != __last; ++__first)
    if (__pred(*__first))
      ++__n;
}

template <class _InputIter, class _Tp>
typename iterator_traits<_InputIter>::difference_type
count(_InputIter __first, _InputIter __last, const _Tp& __value)
{

                                                                ;
                                                           ;

                                                              ;
  typename iterator_traits<_InputIter>::difference_type __n = 0;
  for ( ; __first != __last; ++__first)
    if (*__first == __value)
      ++__n;
  return __n;
}

template <class _InputIter, class _Predicate>
typename iterator_traits<_InputIter>::difference_type
count_if(_InputIter __first, _InputIter __last, _Predicate __pred)
{

                                                                ;
                                                          ;

  typename iterator_traits<_InputIter>::difference_type __n = 0;
  for ( ; __first != __last; ++__first)
    if (__pred(*__first))
      ++__n;
  return __n;
}




template <class _ForwardIter1, class _ForwardIter2>
_ForwardIter1 search(_ForwardIter1 __first1, _ForwardIter1 __last1,
                     _ForwardIter2 __first2, _ForwardIter2 __last2)
{

                                                                     ;
                                                                     ;
                                                             ;




  if (__first1 == __last1 || __first2 == __last2)
    return __first1;


  _ForwardIter2 __tmp(__first2);
  ++__tmp;
  if (__tmp == __last2)
    return find(__first1, __last1, *__first2);



  _ForwardIter2 __p1, __p;

  __p1 = __first2; ++__p1;

  _ForwardIter1 __current = __first1;

  while (__first1 != __last1) {
    __first1 = find(__first1, __last1, *__first2);
    if (__first1 == __last1)
      return __last1;

    __p = __p1;
    __current = __first1;
    if (++__current == __last1)
      return __last1;

    while (*__current == *__p) {
      if (++__p == __last2)
        return __first1;
      if (++__current == __last1)
        return __last1;
    }

    ++__first1;
  }
  return __first1;
}

template <class _ForwardIter1, class _ForwardIter2, class _BinaryPred>
_ForwardIter1 search(_ForwardIter1 __first1, _ForwardIter1 __last1,
                     _ForwardIter2 __first2, _ForwardIter2 __last2,
                     _BinaryPred __predicate)
{

                                                                     ;
                                                                     ;
                                                             ;




  if (__first1 == __last1 || __first2 == __last2)
    return __first1;


  _ForwardIter2 __tmp(__first2);
  ++__tmp;
  if (__tmp == __last2) {
    while (__first1 != __last1 && !__predicate(*__first1, *__first2))
      ++__first1;
    return __first1;
  }



  _ForwardIter2 __p1, __p;

  __p1 = __first2; ++__p1;

  _ForwardIter1 __current = __first1;

  while (__first1 != __last1) {
    while (__first1 != __last1) {
      if (__predicate(*__first1, *__first2))
        break;
      ++__first1;
    }
    while (__first1 != __last1 && !__predicate(*__first1, *__first2))
      ++__first1;
    if (__first1 == __last1)
      return __last1;

    __p = __p1;
    __current = __first1;
    if (++__current == __last1) return __last1;

    while (__predicate(*__current, *__p)) {
      if (++__p == __last2)
        return __first1;
      if (++__current == __last1)
        return __last1;
    }

    ++__first1;
  }
  return __first1;
}



template <class _ForwardIter, class _Integer, class _Tp>
_ForwardIter search_n(_ForwardIter __first, _ForwardIter __last,
                      _Integer __count, const _Tp& __val)
{

                                                                    ;
                                                            ;

                                                              ;

  if (__count <= 0)
    return __first;
  else {
    __first = find(__first, __last, __val);
    while (__first != __last) {
      _Integer __n = __count - 1;
      _ForwardIter __i = __first;
      ++__i;
      while (__i != __last && __n != 0 && *__i == __val) {
        ++__i;
        --__n;
      }
      if (__n == 0)
        return __first;
      else
        __first = find(__i, __last, __val);
    }
    return __last;
  }
}

template <class _ForwardIter, class _Integer, class _Tp, class _BinaryPred>
_ForwardIter search_n(_ForwardIter __first, _ForwardIter __last,
                      _Integer __count, const _Tp& __val,
                      _BinaryPred __binary_pred)
{

                                                                    ;
                                                                 ;


  if (__count <= 0)
    return __first;
  else {
    while (__first != __last) {
      if (__binary_pred(*__first, __val))
        break;
      ++__first;
    }
    while (__first != __last) {
      _Integer __n = __count - 1;
      _ForwardIter __i = __first;
      ++__i;
      while (__i != __last && __n != 0 && __binary_pred(*__i, __val)) {
        ++__i;
        --__n;
      }
      if (__n == 0)
        return __first;
      else {
        while (__i != __last) {
          if (__binary_pred(*__i, __val))
            break;
          ++__i;
        }
        __first = __i;
      }
    }
    return __last;
  }
}



template <class _ForwardIter1, class _ForwardIter2>
_ForwardIter2 swap_ranges(_ForwardIter1 __first1, _ForwardIter1 __last1,
                          _ForwardIter2 __first2)
{

                                                                             ;
                                                                             ;
                                                             ;


                                                             ;



  for ( ; __first1 != __last1; ++__first1, ++__first2)
    iter_swap(__first1, __first2);
  return __first2;
}



template <class _InputIter, class _OutputIter, class _UnaryOperation>
_OutputIter transform(_InputIter __first, _InputIter __last,
                      _OutputIter __result, _UnaryOperation __unary_op)
{

                                                                ;






  for ( ; __first != __last; ++__first, ++__result)
    *__result = __unary_op(*__first);
  return __result;
}

template <class _InputIter1, class _InputIter2, class _OutputIter,
          class _BinaryOperation>
_OutputIter transform(_InputIter1 __first1, _InputIter1 __last1,
                      _InputIter2 __first2, _OutputIter __result,
                      _BinaryOperation __binary_op)
{

                                                                 ;
                                                                 ;






  for ( ; __first1 != __last1; ++__first1, ++__first2, ++__result)
    *__result = __binary_op(*__first1, *__first2);
  return __result;
}



template <class _ForwardIter, class _Tp>
void replace(_ForwardIter __first, _ForwardIter __last,
             const _Tp& __old_value, const _Tp& __new_value)
{

                                                                            ;
                                                                 ;

                                                            ;


  for ( ; __first != __last; ++__first)
    if (*__first == __old_value)
      *__first = __new_value;
}

template <class _ForwardIter, class _Predicate, class _Tp>
void replace_if(_ForwardIter __first, _ForwardIter __last,
                _Predicate __pred, const _Tp& __new_value)
{

                                                                            ;
                                                            ;

                                                            ;


  for ( ; __first != __last; ++__first)
    if (__pred(*__first))
      *__first = __new_value;
}

template <class _InputIter, class _OutputIter, class _Tp>
_OutputIter replace_copy(_InputIter __first, _InputIter __last,
                         _OutputIter __result,
                         const _Tp& __old_value, const _Tp& __new_value)
{

                                                                ;
                                                          ;

                                                               ;


  for ( ; __first != __last; ++__first, ++__result)
    *__result = *__first == __old_value ? __new_value : *__first;
  return __result;
}

template <class _InputIter, class _OutputIter, class _Predicate, class _Tp>
_OutputIter replace_copy_if(_InputIter __first, _InputIter __last,
                            _OutputIter __result,
                            _Predicate __pred, const _Tp& __new_value)
{

                                                                ;
                                                          ;

                                                          ;


  for ( ; __first != __last; ++__first, ++__result)
    *__result = __pred(*__first) ? __new_value : *__first;
  return __result;
}



template <class _ForwardIter, class _Generator>
void generate(_ForwardIter __first, _ForwardIter __last, _Generator __gen)
{

                                                                    ;
                                                            ;


  for ( ; __first != __last; ++__first)
    *__first = __gen();
}

template <class _OutputIter, class _Size, class _Generator>
_OutputIter generate_n(_OutputIter __first, _Size __n, _Generator __gen)
{






  for ( ; __n > 0; --__n, ++__first)
    *__first = __gen();
  return __first;
}



template <class _InputIter, class _OutputIter, class _Tp>
_OutputIter remove_copy(_InputIter __first, _InputIter __last,
                        _OutputIter __result, const _Tp& __value)
{

                                                                ;
                                                          ;

                                                               ;


  for ( ; __first != __last; ++__first)
    if (!(*__first == __value)) {
      *__result = *__first;
      ++__result;
    }
  return __result;
}

template <class _InputIter, class _OutputIter, class _Predicate>
_OutputIter remove_copy_if(_InputIter __first, _InputIter __last,
                           _OutputIter __result, _Predicate __pred)
{

                                                                ;
                                                          ;

                                                          ;


  for ( ; __first != __last; ++__first)
    if (!__pred(*__first)) {
      *__result = *__first;
      ++__result;
    }
  return __result;
}

template <class _ForwardIter, class _Tp>
_ForwardIter remove(_ForwardIter __first, _ForwardIter __last,
                    const _Tp& __value)
{

                                                                            ;
                                                            ;

                                                                 ;


  __first = find(__first, __last, __value);
  _ForwardIter __i = __first;
  return __first == __last ? __first
                           : remove_copy(++__i, __last, __first, __value);
}

template <class _ForwardIter, class _Predicate>
_ForwardIter remove_if(_ForwardIter __first, _ForwardIter __last,
                       _Predicate __pred)
{

                                                                            ;
                                                            ;


  __first = find_if(__first, __last, __pred);
  _ForwardIter __i = __first;
  return __first == __last ? __first
                           : remove_copy_if(++__i, __last, __first, __pred);
}



template <class _InputIter, class _OutputIter, class _Tp>
_OutputIter __unique_copy(_InputIter __first, _InputIter __last,
                          _OutputIter __result, _Tp*)
{

  _Tp __value = *__first;
  *__result = __value;
  while (++__first != __last)
    if (!(__value == *__first)) {
      __value = *__first;
      *++__result = __value;
    }
  return ++__result;
}

template <class _InputIter, class _OutputIter>
inline _OutputIter __unique_copy(_InputIter __first, _InputIter __last,
                                 _OutputIter __result,
                                 output_iterator_tag)
{

  return __unique_copy(__first, __last, __result, __value_type(__first));
}

template <class _InputIter, class _ForwardIter>
_ForwardIter __unique_copy(_InputIter __first, _InputIter __last,
                           _ForwardIter __result, forward_iterator_tag)
{

  *__result = *__first;
  while (++__first != __last)
    if (!(*__result == *__first))
      *++__result = *__first;
  return ++__result;
}

template <class _InputIter, class _OutputIter>
inline _OutputIter unique_copy(_InputIter __first, _InputIter __last,
                               _OutputIter __result)
{

                                                                ;
                                                          ;

                                                          ;


  if (__first == __last) return __result;
  return __unique_copy(__first, __last, __result,
                       __iterator_category(__result));
}

template <class _InputIter, class _OutputIter, class _BinaryPredicate,
          class _Tp>
_OutputIter __unique_copy(_InputIter __first, _InputIter __last,
                          _OutputIter __result,
                          _BinaryPredicate __binary_pred, _Tp*)
{

                                                                                  ;

  _Tp __value = *__first;
  *__result = __value;
  while (++__first != __last)
    if (!__binary_pred(__value, *__first)) {
      __value = *__first;
      *++__result = __value;
    }
  return ++__result;
}

template <class _InputIter, class _OutputIter, class _BinaryPredicate>
inline _OutputIter __unique_copy(_InputIter __first, _InputIter __last,
                                 _OutputIter __result,
                                 _BinaryPredicate __binary_pred,
                                 output_iterator_tag)
{

  return __unique_copy(__first, __last, __result, __binary_pred,
                       __value_type(__first));
}

template <class _InputIter, class _ForwardIter, class _BinaryPredicate>
_ForwardIter __unique_copy(_InputIter __first, _InputIter __last,
                           _ForwardIter __result,
                           _BinaryPredicate __binary_pred,
                           forward_iterator_tag)
{

                                                          ;



  *__result = *__first;
  while (++__first != __last)
    if (!__binary_pred(*__result, *__first)) *++__result = *__first;
  return ++__result;
}

template <class _InputIter, class _OutputIter, class _BinaryPredicate>
inline _OutputIter unique_copy(_InputIter __first, _InputIter __last,
                               _OutputIter __result,
                               _BinaryPredicate __binary_pred)
{

                                                                ;
                                                          ;


  if (__first == __last) return __result;
  return __unique_copy(__first, __last, __result, __binary_pred,
                       __iterator_category(__result));
}

template <class _ForwardIter>
_ForwardIter unique(_ForwardIter __first, _ForwardIter __last)
{

                                                                            ;
                                                            ;


  __first = adjacent_find(__first, __last);
  return unique_copy(__first, __last, __first);
}

template <class _ForwardIter, class _BinaryPredicate>
_ForwardIter unique(_ForwardIter __first, _ForwardIter __last,
                    _BinaryPredicate __binary_pred)
{

                                                                            ;
                                                            ;



  __first = adjacent_find(__first, __last, __binary_pred);
  return unique_copy(__first, __last, __first, __binary_pred);
}



template <class _BidirectionalIter>
void __reverse(_BidirectionalIter __first, _BidirectionalIter __last,
               bidirectional_iterator_tag) {
  while (true)
    if (__first == __last || __first == --__last)
      return;
    else
      iter_swap(__first++, __last);
}

template <class _RandomAccessIter>
void __reverse(_RandomAccessIter __first, _RandomAccessIter __last,
               random_access_iterator_tag) {
  while (__first < __last)
    iter_swap(__first++, --__last);
}

template <class _BidirectionalIter>
inline void reverse(_BidirectionalIter __first, _BidirectionalIter __last)
{

                            ;

  __reverse(__first, __last, __iterator_category(__first));
}

template <class _BidirectionalIter, class _OutputIter>
_OutputIter reverse_copy(_BidirectionalIter __first,
                         _BidirectionalIter __last,
                         _OutputIter __result)
{

                                                                                ;
                                                                  ;


  while (__first != __last) {
    --__last;
    *__result = *__last;
    ++__result;
  }
  return __result;
}



template <class _EuclideanRingElement>
_EuclideanRingElement __gcd(_EuclideanRingElement __m,
                            _EuclideanRingElement __n)
{
  while (__n != 0) {
    _EuclideanRingElement __t = __m % __n;
    __m = __n;
    __n = __t;
  }
  return __m;
}

template <class _ForwardIter, class _Distance>
_ForwardIter __rotate(_ForwardIter __first,
                      _ForwardIter __middle,
                      _ForwardIter __last,
                      _Distance*,
                      forward_iterator_tag)
{
  if (__first == __middle)
    return __last;
  if (__last == __middle)
    return __first;

  _ForwardIter __first2 = __middle;
  do {
    swap(*__first++, *__first2++);
    if (__first == __middle)
      __middle = __first2;
  } while (__first2 != __last);

  _ForwardIter __new_middle = __first;

  __first2 = __middle;

  while (__first2 != __last) {
    swap (*__first++, *__first2++);
    if (__first == __middle)
      __middle = __first2;
    else if (__first2 == __last)
      __first2 = __middle;
  }

  return __new_middle;
}


template <class _BidirectionalIter, class _Distance>
_BidirectionalIter __rotate(_BidirectionalIter __first,
                            _BidirectionalIter __middle,
                            _BidirectionalIter __last,
                            _Distance*,
                            bidirectional_iterator_tag)
{

                            ;


  if (__first == __middle)
    return __last;
  if (__last == __middle)
    return __first;

  __reverse(__first, __middle, bidirectional_iterator_tag());
  __reverse(__middle, __last, bidirectional_iterator_tag());

  while (__first != __middle && __middle != __last)
    swap (*__first++, *--__last);

  if (__first == __middle) {
    __reverse(__middle, __last, bidirectional_iterator_tag());
    return __last;
  }
  else {
    __reverse(__first, __middle, bidirectional_iterator_tag());
    return __first;
  }
}

template <class _RandomAccessIter, class _Distance, class _Tp>
_RandomAccessIter __rotate(_RandomAccessIter __first,
                           _RandomAccessIter __middle,
                           _RandomAccessIter __last,
                           _Distance *, _Tp *)
{

                           ;


  _Distance __n = __last - __first;
  _Distance __k = __middle - __first;
  _Distance __l = __n - __k;
  _RandomAccessIter __result = __first + (__last - __middle);

  if (__k == 0)
    return __last;

  else if (__k == __l) {
    swap_ranges(__first, __middle, __middle);
    return __result;
  }

  _Distance __d = __gcd(__n, __k);

  for (_Distance __i = 0; __i < __d; __i++) {
    _Tp __tmp = *__first;
    _RandomAccessIter __p = __first;

    if (__k < __l) {
      for (_Distance __j = 0; __j < __l/__d; __j++) {
        if (__p > __first + __l) {
          *__p = *(__p - __l);
          __p -= __l;
        }

        *__p = *(__p + __k);
        __p += __k;
      }
    }

    else {
      for (_Distance __j = 0; __j < __k/__d - 1; __j ++) {
        if (__p < __last - __k) {
          *__p = *(__p + __k);
          __p += __k;
        }

        *__p = * (__p - __l);
        __p -= __l;
      }
    }

    *__p = __tmp;
    ++__first;
  }

  return __result;
}

template <class _ForwardIter>
inline _ForwardIter rotate(_ForwardIter __first, _ForwardIter __middle,
                           _ForwardIter __last)
{

                                                                            ;

  return __rotate(__first, __middle, __last,
                  __distance_type(__first),
                  __iterator_category(__first));
}

template <class _ForwardIter, class _OutputIter>
_OutputIter rotate_copy(_ForwardIter __first, _ForwardIter __middle,
                        _ForwardIter __last, _OutputIter __result)
{

                                                                    ;
                                                            ;


  return copy(__first, __middle, copy(__middle, __last, __result));
}




template <class _Distance>
inline _Distance __random_number(_Distance __n) {

  return lrand48() % __n;



}



template <class _RandomAccessIter>
inline void random_shuffle(_RandomAccessIter __first,
                           _RandomAccessIter __last)
{

                           ;


  if (__first == __last) return;
  for (_RandomAccessIter __i = __first + 1; __i != __last; ++__i)
    iter_swap(__i, __first + __random_number((__i - __first) + 1));
}

template <class _RandomAccessIter, class _RandomNumberGenerator>
void random_shuffle(_RandomAccessIter __first, _RandomAccessIter __last,
                    _RandomNumberGenerator& __rand)
{

                           ;


  if (__first == __last) return;
  for (_RandomAccessIter __i = __first + 1; __i != __last; ++__i)
    iter_swap(__i, __first + __rand((__i - __first) + 1));
}



template <class _ForwardIter, class _OutputIter, class _Distance>
_OutputIter random_sample_n(_ForwardIter __first, _ForwardIter __last,
                            _OutputIter __out, const _Distance __n)
{

                                                                    ;
                                                            ;


  _Distance __remaining = 0;
  distance(__first, __last, __remaining);
  _Distance __m = min(__n, __remaining);

  while (__m > 0) {
    if (__random_number(__remaining) < __m) {
      *__out = *__first;
      ++__out;
      --__m;
    }

    --__remaining;
    ++__first;
  }
  return __out;
}

template <class _ForwardIter, class _OutputIter, class _Distance,
          class _RandomNumberGenerator>
_OutputIter random_sample_n(_ForwardIter __first, _ForwardIter __last,
                            _OutputIter __out, const _Distance __n,
                            _RandomNumberGenerator& __rand)
{

                                                                    ;
                                                            ;

                                                      ;


  _Distance __remaining = 0;
  distance(__first, __last, __remaining);
  _Distance __m = min(__n, __remaining);

  while (__m > 0) {
    if (__rand(__remaining) < __m) {
      *__out = *__first;
      ++__out;
      --__m;
    }

    --__remaining;
    ++__first;
  }
  return __out;
}

template <class _InputIter, class _RandomAccessIter, class _Distance>
_RandomAccessIter __random_sample(_InputIter __first, _InputIter __last,
                                  _RandomAccessIter __out,
                                  const _Distance __n)
{
  _Distance __m = 0;
  _Distance __t = __n;
  for ( ; __first != __last && __m < __n; ++__m, ++__first)
    __out[__m] = *__first;

  while (__first != __last) {
    ++__t;
    _Distance __M = __random_number(__t);
    if (__M < __n)
      __out[__M] = *__first;
    ++__first;
  }

  return __out + __m;
}

template <class _InputIter, class _RandomAccessIter,
          class _RandomNumberGenerator, class _Distance>
_RandomAccessIter __random_sample(_InputIter __first, _InputIter __last,
                                  _RandomAccessIter __out,
                                  _RandomNumberGenerator& __rand,
                                  const _Distance __n)
{

                                                      ;


  _Distance __m = 0;
  _Distance __t = __n;
  for ( ; __first != __last && __m < __n; ++__m, ++__first)
    __out[__m] = *__first;

  while (__first != __last) {
    ++__t;
    _Distance __M = __rand(__t);
    if (__M < __n)
      __out[__M] = *__first;
    ++__first;
  }

  return __out + __m;
}

template <class _InputIter, class _RandomAccessIter>
inline _RandomAccessIter
random_sample(_InputIter __first, _InputIter __last,
              _RandomAccessIter __out_first, _RandomAccessIter __out_last)
{

                                                                ;
                           ;


  return __random_sample(__first, __last,
                         __out_first, __out_last - __out_first);
}


template <class _InputIter, class _RandomAccessIter,
          class _RandomNumberGenerator>
inline _RandomAccessIter
random_sample(_InputIter __first, _InputIter __last,
              _RandomAccessIter __out_first, _RandomAccessIter __out_last,
              _RandomNumberGenerator& __rand)
{

                                                                ;
                           ;


  return __random_sample(__first, __last,
                         __out_first, __rand,
                         __out_last - __out_first);
}



template <class _ForwardIter, class _Predicate>
_ForwardIter __partition(_ForwardIter __first,
                         _ForwardIter __last,
                         _Predicate __pred,
                         forward_iterator_tag)
{
  if (__first == __last) return __first;

  while (__pred(*__first))
    if (++__first == __last) return __first;

  _ForwardIter __next = __first;

  while (++__next != __last)
    if (__pred(*__next)) {
      swap(*__first, *__next);
      ++__first;
    }

  return __first;
}

template <class _BidirectionalIter, class _Predicate>
_BidirectionalIter __partition(_BidirectionalIter __first,
                               _BidirectionalIter __last,
                               _Predicate __pred,
                               bidirectional_iterator_tag)
{
  while (true) {
    while (true)
      if (__first == __last)
        return __first;
      else if (__pred(*__first))
        ++__first;
      else
        break;
    --__last;
    while (true)
      if (__first == __last)
        return __first;
      else if (!__pred(*__last))
        --__last;
      else
        break;
    iter_swap(__first, __last);
    ++__first;
  }
}

template <class _ForwardIter, class _Predicate>
inline _ForwardIter partition(_ForwardIter __first,
                              _ForwardIter __last,
                              _Predicate __pred)
{

                                                                            ;
                                                            ;


  return __partition(__first, __last, __pred, __iterator_category(__first));
}


template <class _ForwardIter, class _Predicate, class _Distance>
_ForwardIter __inplace_stable_partition(_ForwardIter __first,
                                        _ForwardIter __last,
                                        _Predicate __pred, _Distance __len)
{
  if (__len == 1)
    return __pred(*__first) ? __last : __first;
  _ForwardIter __middle = __first;
  advance(__middle, __len / 2);
  return rotate(__inplace_stable_partition(__first, __middle, __pred,
                                           __len / 2),
                __middle,
                __inplace_stable_partition(__middle, __last, __pred,
                                           __len - __len / 2));
}

template <class _ForwardIter, class _Pointer, class _Predicate,
          class _Distance>
_ForwardIter __stable_partition_adaptive(_ForwardIter __first,
                                         _ForwardIter __last,
                                         _Predicate __pred, _Distance __len,
                                         _Pointer __buffer,
                                         _Distance __buffer_size)
{
  if (__len <= __buffer_size) {
    _ForwardIter __result1 = __first;
    _Pointer __result2 = __buffer;
    for ( ; __first != __last ; ++__first)
      if (__pred(*__first)) {
        *__result1 = *__first;
        ++__result1;
      }
      else {
        *__result2 = *__first;
        ++__result2;
      }
    copy(__buffer, __result2, __result1);
    return __result1;
  }
  else {
    _ForwardIter __middle = __first;
    advance(__middle, __len / 2);
    return rotate(__stable_partition_adaptive(
                          __first, __middle, __pred,
                          __len / 2, __buffer, __buffer_size),
                    __middle,
                    __stable_partition_adaptive(
                          __middle, __last, __pred,
                          __len - __len / 2, __buffer, __buffer_size));
  }
}

template <class _ForwardIter, class _Predicate, class _Tp, class _Distance>
inline _ForwardIter
__stable_partition_aux(_ForwardIter __first, _ForwardIter __last,
                       _Predicate __pred, _Tp*, _Distance*)
{
  _Temporary_buffer<_ForwardIter, _Tp> __buf(__first, __last);
  if (__buf.size() > 0)
    return __stable_partition_adaptive(__first, __last, __pred,
                                       _Distance(__buf.requested_size()),
                                       __buf.begin(), __buf.size());
  else
    return __inplace_stable_partition(__first, __last, __pred,
                                      _Distance(__buf.requested_size()));
}

template <class _ForwardIter, class _Predicate>
inline _ForwardIter stable_partition(_ForwardIter __first,
                                     _ForwardIter __last,
                                     _Predicate __pred)
{

                                                                            ;
                                                            ;


  if (__first == __last)
    return __first;
  else
    return __stable_partition_aux(__first, __last, __pred,
                                  __value_type(__first),
                                  __distance_type(__first));
}

template <class _RandomAccessIter, class _Tp>
_RandomAccessIter __unguarded_partition(_RandomAccessIter __first,
                                        _RandomAccessIter __last,
                                        _Tp __pivot)
{
  while (true) {
    while (*__first < __pivot)
      ++__first;
    --__last;
    while (__pivot < *__last)
      --__last;
    if (!(__first < __last))
      return __first;
    iter_swap(__first, __last);
    ++__first;
  }
}

template <class _RandomAccessIter, class _Tp, class _Compare>
_RandomAccessIter __unguarded_partition(_RandomAccessIter __first,
                                        _RandomAccessIter __last,
                                        _Tp __pivot, _Compare __comp)
{
  while (true) {
    while (__comp(*__first, __pivot))
      ++__first;
    --__last;
    while (__comp(__pivot, *__last))
      --__last;
    if (!(__first < __last))
      return __first;
    iter_swap(__first, __last);
    ++__first;
  }
}

const int __stl_threshold = 16;



template <class _RandomAccessIter, class _Tp>
void __unguarded_linear_insert(_RandomAccessIter __last, _Tp __val)
{
  _RandomAccessIter __next = __last;
  --__next;
  while (__val < *__next) {
    *__last = *__next;
    __last = __next;
    --__next;
  }
  *__last = __val;
}

template <class _RandomAccessIter, class _Tp, class _Compare>
void __unguarded_linear_insert(_RandomAccessIter __last, _Tp __val,
                               _Compare __comp)
{
  _RandomAccessIter __next = __last;
  --__next;
  while (__comp(__val, *__next)) {
    *__last = *__next;
    __last = __next;
    --__next;
  }
  *__last = __val;
}

template <class _RandomAccessIter, class _Tp>
inline void __linear_insert(_RandomAccessIter __first,
                            _RandomAccessIter __last, _Tp*)
{
  _Tp __val = *__last;
  if (__val < *__first) {
    copy_backward(__first, __last, __last + 1);
    *__first = __val;
  }
  else
    __unguarded_linear_insert(__last, __val);
}

template <class _RandomAccessIter, class _Tp, class _Compare>
inline void __linear_insert(_RandomAccessIter __first,
                            _RandomAccessIter __last, _Tp*, _Compare __comp)
{
  _Tp __val = *__last;
  if (__comp(__val, *__first)) {
    copy_backward(__first, __last, __last + 1);
    *__first = __val;
  }
  else
    __unguarded_linear_insert(__last, __val, __comp);
}

template <class _RandomAccessIter>
void __insertion_sort(_RandomAccessIter __first, _RandomAccessIter __last)
{
  if (__first == __last) return;
  for (_RandomAccessIter __i = __first + 1; __i != __last; ++__i)
    __linear_insert(__first, __i, __value_type(__first));
}

template <class _RandomAccessIter, class _Compare>
void __insertion_sort(_RandomAccessIter __first,
                      _RandomAccessIter __last, _Compare __comp)
{
  if (__first == __last) return;
  for (_RandomAccessIter __i = __first + 1; __i != __last; ++__i)
    __linear_insert(__first, __i, __value_type(__first), __comp);
}

template <class _RandomAccessIter, class _Tp>
void __unguarded_insertion_sort_aux(_RandomAccessIter __first,
                                    _RandomAccessIter __last, _Tp*)
{
  for (_RandomAccessIter __i = __first; __i != __last; ++__i)
    __unguarded_linear_insert(__i, _Tp(*__i));
}

template <class _RandomAccessIter>
inline void __unguarded_insertion_sort(_RandomAccessIter __first,
                                _RandomAccessIter __last) {
  __unguarded_insertion_sort_aux(__first, __last, __value_type(__first));
}

template <class _RandomAccessIter, class _Tp, class _Compare>
void __unguarded_insertion_sort_aux(_RandomAccessIter __first,
                                    _RandomAccessIter __last,
                                    _Tp*, _Compare __comp)
{
  for (_RandomAccessIter __i = __first; __i != __last; ++__i)
    __unguarded_linear_insert(__i, _Tp(*__i), __comp);
}

template <class _RandomAccessIter, class _Compare>
inline void __unguarded_insertion_sort(_RandomAccessIter __first,
                                       _RandomAccessIter __last,
                                       _Compare __comp)
{
  __unguarded_insertion_sort_aux(__first, __last, __value_type(__first),
                                 __comp);
}

template <class _RandomAccessIter>
void __final_insertion_sort(_RandomAccessIter __first,
                            _RandomAccessIter __last)
{
  if (__last - __first > __stl_threshold) {
    __insertion_sort(__first, __first + __stl_threshold);
    __unguarded_insertion_sort(__first + __stl_threshold, __last);
  }
  else
    __insertion_sort(__first, __last);
}

template <class _RandomAccessIter, class _Compare>
void __final_insertion_sort(_RandomAccessIter __first,
                            _RandomAccessIter __last, _Compare __comp)
{
  if (__last - __first > __stl_threshold) {
    __insertion_sort(__first, __first + __stl_threshold, __comp);
    __unguarded_insertion_sort(__first + __stl_threshold, __last, __comp);
  }
  else
    __insertion_sort(__first, __last, __comp);
}

template <class _Size>
inline _Size __lg(_Size __n)
{
  _Size __k;
  for (__k = 0; __n != 1; __n >>= 1) ++__k;
  return __k;
}

template <class _RandomAccessIter, class _Tp, class _Size>
void __introsort_loop(_RandomAccessIter __first,
                      _RandomAccessIter __last, _Tp*,
                      _Size __depth_limit)
{
  while (__last - __first > __stl_threshold) {
    if (__depth_limit == 0) {
      partial_sort(__first, __last, __last);
      return;
    }
    --__depth_limit;
    _RandomAccessIter __cut =
      __unguarded_partition(__first, __last,
                            _Tp(__median(*__first,
                                         *(__first + (__last - __first)/2),
                                         *(__last - 1))));
    __introsort_loop(__cut, __last, (_Tp*) 0, __depth_limit);
    __last = __cut;
  }
}

template <class _RandomAccessIter, class _Tp, class _Size, class _Compare>
void __introsort_loop(_RandomAccessIter __first,
                      _RandomAccessIter __last, _Tp*,
                      _Size __depth_limit, _Compare __comp)
{
  while (__last - __first > __stl_threshold) {
    if (__depth_limit == 0) {
      partial_sort(__first, __last, __last, __comp);
      return;
    }
    --__depth_limit;
    _RandomAccessIter __cut =
      __unguarded_partition(__first, __last,
                            _Tp(__median(*__first,
                                         *(__first + (__last - __first)/2),
                                         *(__last - 1), __comp)),
       __comp);
    __introsort_loop(__cut, __last, (_Tp*) 0, __depth_limit, __comp);
    __last = __cut;
  }
}

template <class _RandomAccessIter>
inline void sort(_RandomAccessIter __first, _RandomAccessIter __last)
{

                           ;

                                                                 ;


  if (__first != __last) {
    __introsort_loop(__first, __last,
                     __value_type(__first),
                     __lg(__last - __first) * 2);
    __final_insertion_sort(__first, __last);
  }
}

template <class _RandomAccessIter, class _Compare>
inline void sort(_RandomAccessIter __first, _RandomAccessIter __last,
                 _Compare __comp)
{

                           ;

                                                                 ;



  if (__first != __last) {
    __introsort_loop(__first, __last,
                     __value_type(__first),
                     __lg(__last - __first) * 2,
                     __comp);
    __final_insertion_sort(__first, __last, __comp);
  }
}



template <class _RandomAccessIter>
void __inplace_stable_sort(_RandomAccessIter __first,
                           _RandomAccessIter __last)
{
  if (__last - __first < 15) {
    __insertion_sort(__first, __last);
    return;
  }
  _RandomAccessIter __middle = __first + (__last - __first) / 2;
  __inplace_stable_sort(__first, __middle);
  __inplace_stable_sort(__middle, __last);
  __merge_without_buffer(__first, __middle, __last,
                         __middle - __first,
                         __last - __middle);
}

template <class _RandomAccessIter, class _Compare>
void __inplace_stable_sort(_RandomAccessIter __first,
                           _RandomAccessIter __last, _Compare __comp)
{
  if (__last - __first < 15) {
    __insertion_sort(__first, __last, __comp);
    return;
  }
  _RandomAccessIter __middle = __first + (__last - __first) / 2;
  __inplace_stable_sort(__first, __middle, __comp);
  __inplace_stable_sort(__middle, __last, __comp);
  __merge_without_buffer(__first, __middle, __last,
                         __middle - __first,
                         __last - __middle,
                         __comp);
}

template <class _RandomAccessIter1, class _RandomAccessIter2,
          class _Distance>
void __merge_sort_loop(_RandomAccessIter1 __first,
                       _RandomAccessIter1 __last,
                       _RandomAccessIter2 __result, _Distance __step_size)
{
  _Distance __two_step = 2 * __step_size;

  while (__last - __first >= __two_step) {
    __result = merge(__first, __first + __step_size,
                     __first + __step_size, __first + __two_step,
                     __result);
    __first += __two_step;
  }

  __step_size = min(_Distance(__last - __first), __step_size);
  merge(__first, __first + __step_size, __first + __step_size, __last,
        __result);
}

template <class _RandomAccessIter1, class _RandomAccessIter2,
          class _Distance, class _Compare>
void __merge_sort_loop(_RandomAccessIter1 __first,
                       _RandomAccessIter1 __last,
                       _RandomAccessIter2 __result, _Distance __step_size,
                       _Compare __comp)
{
  _Distance __two_step = 2 * __step_size;

  while (__last - __first >= __two_step) {
    __result = merge(__first, __first + __step_size,
                     __first + __step_size, __first + __two_step,
                     __result,
                     __comp);
    __first += __two_step;
  }
  __step_size = min(_Distance(__last - __first), __step_size);

  merge(__first, __first + __step_size,
        __first + __step_size, __last,
        __result,
        __comp);
}

const int __stl_chunk_size = 7;

template <class _RandomAccessIter, class _Distance>
void __chunk_insertion_sort(_RandomAccessIter __first,
                            _RandomAccessIter __last, _Distance __chunk_size)
{
  while (__last - __first >= __chunk_size) {
    __insertion_sort(__first, __first + __chunk_size);
    __first += __chunk_size;
  }
  __insertion_sort(__first, __last);
}

template <class _RandomAccessIter, class _Distance, class _Compare>
void __chunk_insertion_sort(_RandomAccessIter __first,
                            _RandomAccessIter __last,
                            _Distance __chunk_size, _Compare __comp)
{
  while (__last - __first >= __chunk_size) {
    __insertion_sort(__first, __first + __chunk_size, __comp);
    __first += __chunk_size;
  }
  __insertion_sort(__first, __last, __comp);
}

template <class _RandomAccessIter, class _Pointer, class _Distance>
void __merge_sort_with_buffer(_RandomAccessIter __first,
                              _RandomAccessIter __last,
                              _Pointer __buffer, _Distance*)
{
  _Distance __len = __last - __first;
  _Pointer __buffer_last = __buffer + __len;

  _Distance __step_size = __stl_chunk_size;
  __chunk_insertion_sort(__first, __last, __step_size);

  while (__step_size < __len) {
    __merge_sort_loop(__first, __last, __buffer, __step_size);
    __step_size *= 2;
    __merge_sort_loop(__buffer, __buffer_last, __first, __step_size);
    __step_size *= 2;
  }
}

template <class _RandomAccessIter, class _Pointer, class _Distance,
          class _Compare>
void __merge_sort_with_buffer(_RandomAccessIter __first,
                              _RandomAccessIter __last, _Pointer __buffer,
                              _Distance*, _Compare __comp)
{
  _Distance __len = __last - __first;
  _Pointer __buffer_last = __buffer + __len;

  _Distance __step_size = __stl_chunk_size;
  __chunk_insertion_sort(__first, __last, __step_size, __comp);

  while (__step_size < __len) {
    __merge_sort_loop(__first, __last, __buffer, __step_size, __comp);
    __step_size *= 2;
    __merge_sort_loop(__buffer, __buffer_last, __first, __step_size, __comp);
    __step_size *= 2;
  }
}

template <class _RandomAccessIter, class _Pointer, class _Distance>
void __stable_sort_adaptive(_RandomAccessIter __first,
                            _RandomAccessIter __last, _Pointer __buffer,
                            _Distance __buffer_size)
{
  _Distance __len = (__last - __first + 1) / 2;
  _RandomAccessIter __middle = __first + __len;
  if (__len > __buffer_size) {
    __stable_sort_adaptive(__first, __middle, __buffer, __buffer_size);
    __stable_sort_adaptive(__middle, __last, __buffer, __buffer_size);
  }
  else {
    __merge_sort_with_buffer(__first, __middle, __buffer, (_Distance*)0);
    __merge_sort_with_buffer(__middle, __last, __buffer, (_Distance*)0);
  }
  __merge_adaptive(__first, __middle, __last, _Distance(__middle - __first),
                   _Distance(__last - __middle), __buffer, __buffer_size);
}

template <class _RandomAccessIter, class _Pointer, class _Distance,
          class _Compare>
void __stable_sort_adaptive(_RandomAccessIter __first,
                            _RandomAccessIter __last, _Pointer __buffer,
                            _Distance __buffer_size, _Compare __comp)
{
  _Distance __len = (__last - __first + 1) / 2;
  _RandomAccessIter __middle = __first + __len;
  if (__len > __buffer_size) {
    __stable_sort_adaptive(__first, __middle, __buffer, __buffer_size,
                           __comp);
    __stable_sort_adaptive(__middle, __last, __buffer, __buffer_size,
                           __comp);
  }
  else {
    __merge_sort_with_buffer(__first, __middle, __buffer, (_Distance*)0,
                               __comp);
    __merge_sort_with_buffer(__middle, __last, __buffer, (_Distance*)0,
                               __comp);
  }
  __merge_adaptive(__first, __middle, __last, _Distance(__middle - __first),
                   _Distance(__last - __middle), __buffer, __buffer_size,
                   __comp);
}

template <class _RandomAccessIter, class _Tp, class _Distance>
inline void __stable_sort_aux(_RandomAccessIter __first,
                              _RandomAccessIter __last, _Tp*, _Distance*)
{
  _Temporary_buffer<_RandomAccessIter, _Tp> buf(__first, __last);
  if (buf.begin() == 0)
    __inplace_stable_sort(__first, __last);
  else
    __stable_sort_adaptive(__first, __last, buf.begin(),
                           _Distance(buf.size()));
}

template <class _RandomAccessIter, class _Tp, class _Distance, class _Compare>
inline void __stable_sort_aux(_RandomAccessIter __first,
                              _RandomAccessIter __last, _Tp*, _Distance*,
                              _Compare __comp)
{
  _Temporary_buffer<_RandomAccessIter, _Tp> buf(__first, __last);
  if (buf.begin() == 0)
    __inplace_stable_sort(__first, __last, __comp);
  else
    __stable_sort_adaptive(__first, __last, buf.begin(),
                           _Distance(buf.size()),
                           __comp);
}

template <class _RandomAccessIter>
inline void stable_sort(_RandomAccessIter __first,
                        _RandomAccessIter __last)
{

                           ;

                                                                 ;


  __stable_sort_aux(__first, __last,
                    __value_type(__first),
                    __distance_type(__first));
}

template <class _RandomAccessIter, class _Compare>
inline void stable_sort(_RandomAccessIter __first,
                        _RandomAccessIter __last, _Compare __comp)
{

                           ;

                                                                 ;



  __stable_sort_aux(__first, __last,
                    __value_type(__first),
                    __distance_type(__first),
                    __comp);
}



template <class _RandomAccessIter, class _Tp>
void __partial_sort(_RandomAccessIter __first, _RandomAccessIter __middle,
                    _RandomAccessIter __last, _Tp*)
{
  make_heap(__first, __middle);
  for (_RandomAccessIter __i = __middle; __i < __last; ++__i)
    if (*__i < *__first)
      __pop_heap(__first, __middle, __i, _Tp(*__i),
                 __distance_type(__first));
  sort_heap(__first, __middle);
}

template <class _RandomAccessIter>
inline void partial_sort(_RandomAccessIter __first,
                         _RandomAccessIter __middle,
                         _RandomAccessIter __last)
{

                           ;

                                                                 ;


  __partial_sort(__first, __middle, __last, __value_type(__first));
}

template <class _RandomAccessIter, class _Tp, class _Compare>
void __partial_sort(_RandomAccessIter __first, _RandomAccessIter __middle,
                    _RandomAccessIter __last, _Tp*, _Compare __comp)
{
  make_heap(__first, __middle, __comp);
  for (_RandomAccessIter __i = __middle; __i < __last; ++__i)
    if (__comp(*__i, *__first))
      __pop_heap(__first, __middle, __i, _Tp(*__i), __comp,
                 __distance_type(__first));
  sort_heap(__first, __middle, __comp);
}

template <class _RandomAccessIter, class _Compare>
inline void partial_sort(_RandomAccessIter __first,
                         _RandomAccessIter __middle,
                         _RandomAccessIter __last, _Compare __comp)
{

                           ;

                                                                 ;



  __partial_sort(__first, __middle, __last, __value_type(__first), __comp);
}

template <class _InputIter, class _RandomAccessIter, class _Distance,
          class _Tp>
_RandomAccessIter __partial_sort_copy(_InputIter __first,
                                      _InputIter __last,
                                      _RandomAccessIter __result_first,
                                      _RandomAccessIter __result_last,
                                      _Distance*, _Tp*)
{
  if (__result_first == __result_last) return __result_last;
  _RandomAccessIter __result_real_last = __result_first;
  while(__first != __last && __result_real_last != __result_last) {
    *__result_real_last = *__first;
    ++__result_real_last;
    ++__first;
  }
  make_heap(__result_first, __result_real_last);
  while (__first != __last) {
    if (*__first < *__result_first)
      __adjust_heap(__result_first, _Distance(0),
                    _Distance(__result_real_last - __result_first),
                    _Tp(*__first));
    ++__first;
  }
  sort_heap(__result_first, __result_real_last);
  return __result_real_last;
}

template <class _InputIter, class _RandomAccessIter>
inline _RandomAccessIter
partial_sort_copy(_InputIter __first, _InputIter __last,
                  _RandomAccessIter __result_first,
                  _RandomAccessIter __result_last)
{

                                                                ;
                                                                 ;


                                                                 ;

                                                          ;


  return __partial_sort_copy(__first, __last, __result_first, __result_last,
                             __distance_type(__result_first),
                             __value_type(__first));
}

template <class _InputIter, class _RandomAccessIter, class _Compare,
          class _Distance, class _Tp>
_RandomAccessIter __partial_sort_copy(_InputIter __first,
                                         _InputIter __last,
                                         _RandomAccessIter __result_first,
                                         _RandomAccessIter __result_last,
                                         _Compare __comp, _Distance*, _Tp*)
{
  if (__result_first == __result_last) return __result_last;
  _RandomAccessIter __result_real_last = __result_first;
  while(__first != __last && __result_real_last != __result_last) {
    *__result_real_last = *__first;
    ++__result_real_last;
    ++__first;
  }
  make_heap(__result_first, __result_real_last, __comp);
  while (__first != __last) {
    if (__comp(*__first, *__result_first))
      __adjust_heap(__result_first, _Distance(0),
                    _Distance(__result_real_last - __result_first),
                    _Tp(*__first),
                    __comp);
    ++__first;
  }
  sort_heap(__result_first, __result_real_last, __comp);
  return __result_real_last;
}

template <class _InputIter, class _RandomAccessIter, class _Compare>
inline _RandomAccessIter
partial_sort_copy(_InputIter __first, _InputIter __last,
                  _RandomAccessIter __result_first,
                  _RandomAccessIter __result_last, _Compare __comp)
{

                                                                ;
                           ;

                                                                 ;


                                                                 ;



  return __partial_sort_copy(__first, __last, __result_first, __result_last,
                             __comp,
                             __distance_type(__result_first),
                             __value_type(__first));
}



template <class _RandomAccessIter, class _Tp>
void __nth_element(_RandomAccessIter __first, _RandomAccessIter __nth,
                   _RandomAccessIter __last, _Tp*)
{
  while (__last - __first > 3) {
    _RandomAccessIter __cut =
      __unguarded_partition(__first, __last,
                            _Tp(__median(*__first,
                                         *(__first + (__last - __first)/2),
                                         *(__last - 1))));
    if (__cut <= __nth)
      __first = __cut;
    else
      __last = __cut;
  }
  __insertion_sort(__first, __last);
}

template <class _RandomAccessIter>
inline void nth_element(_RandomAccessIter __first, _RandomAccessIter __nth,
                        _RandomAccessIter __last)
{

                           ;

                                                                 ;


  __nth_element(__first, __nth, __last, __value_type(__first));
}

template <class _RandomAccessIter, class _Tp, class _Compare>
void __nth_element(_RandomAccessIter __first, _RandomAccessIter __nth,
                   _RandomAccessIter __last, _Tp*, _Compare __comp)
{
  while (__last - __first > 3) {
    _RandomAccessIter __cut =
      __unguarded_partition(__first, __last,
                            _Tp(__median(*__first,
                                         *(__first + (__last - __first)/2),
                                         *(__last - 1),
                                         __comp)),
                            __comp);
    if (__cut <= __nth)
      __first = __cut;
    else
      __last = __cut;
  }
  __insertion_sort(__first, __last, __comp);
}

template <class _RandomAccessIter, class _Compare>
inline void nth_element(_RandomAccessIter __first, _RandomAccessIter __nth,
                        _RandomAccessIter __last, _Compare __comp)
{

                           ;

                                                                 ;



  __nth_element(__first, __nth, __last, __value_type(__first), __comp);
}




template <class _ForwardIter, class _Tp, class _Distance>
_ForwardIter __lower_bound(_ForwardIter __first, _ForwardIter __last,
                           const _Tp& __val, _Distance*)
{
  _Distance __len = 0;
  distance(__first, __last, __len);
  _Distance __half;
  _ForwardIter __middle;

  while (__len > 0) {
    __half = __len >> 1;
    __middle = __first;
    advance(__middle, __half);
    if (*__middle < __val) {
      __first = __middle;
      ++__first;
      __len = __len - __half - 1;
    }
    else
      __len = __half;
  }
  return __first;
}

template <class _ForwardIter, class _Tp>
inline _ForwardIter lower_bound(_ForwardIter __first, _ForwardIter __last,
                                const _Tp& __val)
{

                                                                    ;
                                                            ;

                                                              ;

  return __lower_bound(__first, __last, __val,
                       __distance_type(__first));
}

template <class _ForwardIter, class _Tp, class _Compare, class _Distance>
_ForwardIter __lower_bound(_ForwardIter __first, _ForwardIter __last,
                              const _Tp& __val, _Compare __comp, _Distance*)
{
  _Distance __len = 0;
  distance(__first, __last, __len);
  _Distance __half;
  _ForwardIter __middle;

  while (__len > 0) {
    __half = __len >> 1;
    __middle = __first;
    advance(__middle, __half);
    if (__comp(*__middle, __val)) {
      __first = __middle;
      ++__first;
      __len = __len - __half - 1;
    }
    else
      __len = __half;
  }
  return __first;
}

template <class _ForwardIter, class _Tp, class _Compare>
inline _ForwardIter lower_bound(_ForwardIter __first, _ForwardIter __last,
                                const _Tp& __val, _Compare __comp)
{

                                                                    ;
                                                            ;

                                                                          ;

  return __lower_bound(__first, __last, __val, __comp,
                       __distance_type(__first));
}

template <class _ForwardIter, class _Tp, class _Distance>
_ForwardIter __upper_bound(_ForwardIter __first, _ForwardIter __last,
                           const _Tp& __val, _Distance*)
{
  _Distance __len = 0;
  distance(__first, __last, __len);
  _Distance __half;
  _ForwardIter __middle;

  while (__len > 0) {
    __half = __len >> 1;
    __middle = __first;
    advance(__middle, __half);
    if (__val < *__middle)
      __len = __half;
    else {
      __first = __middle;
      ++__first;
      __len = __len - __half - 1;
    }
  }
  return __first;
}

template <class _ForwardIter, class _Tp>
inline _ForwardIter upper_bound(_ForwardIter __first, _ForwardIter __last,
                                const _Tp& __val)
{

                                                                    ;
                                                            ;

                                                              ;

  return __upper_bound(__first, __last, __val,
                       __distance_type(__first));
}

template <class _ForwardIter, class _Tp, class _Compare, class _Distance>
_ForwardIter __upper_bound(_ForwardIter __first, _ForwardIter __last,
                           const _Tp& __val, _Compare __comp, _Distance*)
{
  _Distance __len = 0;
  distance(__first, __last, __len);
  _Distance __half;
  _ForwardIter __middle;

  while (__len > 0) {
    __half = __len >> 1;
    __middle = __first;
    advance(__middle, __half);
    if (__comp(__val, *__middle))
      __len = __half;
    else {
      __first = __middle;
      ++__first;
      __len = __len - __half - 1;
    }
  }
  return __first;
}

template <class _ForwardIter, class _Tp, class _Compare>
inline _ForwardIter upper_bound(_ForwardIter __first, _ForwardIter __last,
                                const _Tp& __val, _Compare __comp)
{

                                                                    ;
                                                            ;

                                                                          ;

  return __upper_bound(__first, __last, __val, __comp,
                       __distance_type(__first));
}

template <class _ForwardIter, class _Tp, class _Distance>
pair<_ForwardIter, _ForwardIter>
__equal_range(_ForwardIter __first, _ForwardIter __last, const _Tp& __val,
              _Distance*)
{
  _Distance __len = 0;
  distance(__first, __last, __len);
  _Distance __half;
  _ForwardIter __middle, __left, __right;

  while (__len > 0) {
    __half = __len >> 1;
    __middle = __first;
    advance(__middle, __half);
    if (*__middle < __val) {
      __first = __middle;
      ++__first;
      __len = __len - __half - 1;
    }
    else if (__val < *__middle)
      __len = __half;
    else {
      __left = lower_bound(__first, __middle, __val);
      advance(__first, __len);
      __right = upper_bound(++__middle, __first, __val);
      return pair<_ForwardIter, _ForwardIter>(__left, __right);
    }
  }
  return pair<_ForwardIter, _ForwardIter>(__first, __first);
}

template <class _ForwardIter, class _Tp>
inline pair<_ForwardIter, _ForwardIter>
equal_range(_ForwardIter __first, _ForwardIter __last, const _Tp& __val)
{

                                                                    ;
                                                            ;

                                                              ;

  return __equal_range(__first, __last, __val,
                       __distance_type(__first));
}

template <class _ForwardIter, class _Tp, class _Compare, class _Distance>
pair<_ForwardIter, _ForwardIter>
__equal_range(_ForwardIter __first, _ForwardIter __last, const _Tp& __val,
              _Compare __comp, _Distance*)
{
  _Distance __len = 0;
  distance(__first, __last, __len);
  _Distance __half;
  _ForwardIter __middle, __left, __right;

  while (__len > 0) {
    __half = __len >> 1;
    __middle = __first;
    advance(__middle, __half);
    if (__comp(*__middle, __val)) {
      __first = __middle;
      ++__first;
      __len = __len - __half - 1;
    }
    else if (__comp(__val, *__middle))
      __len = __half;
    else {
      __left = lower_bound(__first, __middle, __val, __comp);
      advance(__first, __len);
      __right = upper_bound(++__middle, __first, __val, __comp);
      return pair<_ForwardIter, _ForwardIter>(__left, __right);
    }
  }
  return pair<_ForwardIter, _ForwardIter>(__first, __first);
}

template <class _ForwardIter, class _Tp, class _Compare>
inline pair<_ForwardIter, _ForwardIter>
equal_range(_ForwardIter __first, _ForwardIter __last, const _Tp& __val,
            _Compare __comp)
{

                                                                    ;
                                                            ;

                                                                          ;

  return __equal_range(__first, __last, __val, __comp,
                       __distance_type(__first));
}

template <class _ForwardIter, class _Tp>
bool binary_search(_ForwardIter __first, _ForwardIter __last,
                   const _Tp& __val)
{

                                                                    ;
                                                            ;

                                                              ;

  _ForwardIter __i = lower_bound(__first, __last, __val);
  return __i != __last && !(__val < *__i);
}

template <class _ForwardIter, class _Tp, class _Compare>
bool binary_search(_ForwardIter __first, _ForwardIter __last,
                   const _Tp& __val,
                   _Compare __comp)
{

                                                                    ;
                                                            ;

                                                                          ;

  _ForwardIter __i = lower_bound(__first, __last, __val, __comp);
  return __i != __last && !__comp(__val, *__i);
}



template <class _InputIter1, class _InputIter2, class _OutputIter>
_OutputIter merge(_InputIter1 __first1, _InputIter1 __last1,
                  _InputIter2 __first2, _InputIter2 __last2,
                  _OutputIter __result)
{

                                                                 ;
                                                                 ;
                                                           ;

                                                           ;


                                                           ;


  while (__first1 != __last1 && __first2 != __last2) {
    if (*__first2 < *__first1) {
      *__result = *__first2;
      ++__first2;
    }
    else {
      *__result = *__first1;
      ++__first1;
    }
    ++__result;
  }
  return copy(__first2, __last2, copy(__first1, __last1, __result));
}

template <class _InputIter1, class _InputIter2, class _OutputIter,
          class _Compare>
_OutputIter merge(_InputIter1 __first1, _InputIter1 __last1,
                  _InputIter2 __first2, _InputIter2 __last2,
                  _OutputIter __result, _Compare __comp)
{

                                                                 ;
                                                                 ;
                                                           ;


                                                           ;

                                                           ;



  while (__first1 != __last1 && __first2 != __last2) {
    if (__comp(*__first2, *__first1)) {
      *__result = *__first2;
      ++__first2;
    }
    else {
      *__result = *__first1;
      ++__first1;
    }
    ++__result;
  }
  return copy(__first2, __last2, copy(__first1, __last1, __result));
}



template <class _BidirectionalIter, class _Distance>
void __merge_without_buffer(_BidirectionalIter __first,
                            _BidirectionalIter __middle,
                            _BidirectionalIter __last,
                            _Distance __len1, _Distance __len2)
{
  if (__len1 == 0 || __len2 == 0)
    return;
  if (__len1 + __len2 == 2) {
    if (*__middle < *__first)
      iter_swap(__first, __middle);
    return;
  }
  _BidirectionalIter __first_cut = __first;
  _BidirectionalIter __second_cut = __middle;
  _Distance __len11 = 0;
  _Distance __len22 = 0;
  if (__len1 > __len2) {
    __len11 = __len1 / 2;
    advance(__first_cut, __len11);
    __second_cut = lower_bound(__middle, __last, *__first_cut);
    distance(__middle, __second_cut, __len22);
  }
  else {
    __len22 = __len2 / 2;
    advance(__second_cut, __len22);
    __first_cut = upper_bound(__first, __middle, *__second_cut);
    distance(__first, __first_cut, __len11);
  }
  _BidirectionalIter __new_middle
    = rotate(__first_cut, __middle, __second_cut);
  __merge_without_buffer(__first, __first_cut, __new_middle,
                         __len11, __len22);
  __merge_without_buffer(__new_middle, __second_cut, __last, __len1 - __len11,
                         __len2 - __len22);
}

template <class _BidirectionalIter, class _Distance, class _Compare>
void __merge_without_buffer(_BidirectionalIter __first,
                            _BidirectionalIter __middle,
                            _BidirectionalIter __last,
                            _Distance __len1, _Distance __len2,
                            _Compare __comp)
{
  if (__len1 == 0 || __len2 == 0)
    return;
  if (__len1 + __len2 == 2) {
    if (__comp(*__middle, *__first))
      iter_swap(__first, __middle);
    return;
  }
  _BidirectionalIter __first_cut = __first;
  _BidirectionalIter __second_cut = __middle;
  _Distance __len11 = 0;
  _Distance __len22 = 0;
  if (__len1 > __len2) {
    __len11 = __len1 / 2;
    advance(__first_cut, __len11);
    __second_cut = lower_bound(__middle, __last, *__first_cut, __comp);
    distance(__middle, __second_cut, __len22);
  }
  else {
    __len22 = __len2 / 2;
    advance(__second_cut, __len22);
    __first_cut = upper_bound(__first, __middle, *__second_cut, __comp);
    distance(__first, __first_cut, __len11);
  }
  _BidirectionalIter __new_middle
    = rotate(__first_cut, __middle, __second_cut);
  __merge_without_buffer(__first, __first_cut, __new_middle, __len11, __len22,
                         __comp);
  __merge_without_buffer(__new_middle, __second_cut, __last, __len1 - __len11,
                         __len2 - __len22, __comp);
}

template <class _BidirectionalIter1, class _BidirectionalIter2,
          class _Distance>
_BidirectionalIter1 __rotate_adaptive(_BidirectionalIter1 __first,
                                      _BidirectionalIter1 __middle,
                                      _BidirectionalIter1 __last,
                                      _Distance __len1, _Distance __len2,
                                      _BidirectionalIter2 __buffer,
                                      _Distance __buffer_size)
{
  _BidirectionalIter2 __buffer_end;
  if (__len1 > __len2 && __len2 <= __buffer_size) {
    __buffer_end = copy(__middle, __last, __buffer);
    copy_backward(__first, __middle, __last);
    return copy(__buffer, __buffer_end, __first);
  }
  else if (__len1 <= __buffer_size) {
    __buffer_end = copy(__first, __middle, __buffer);
    copy(__middle, __last, __first);
    return copy_backward(__buffer, __buffer_end, __last);
  }
  else
    return rotate(__first, __middle, __last);
}

template <class _BidirectionalIter1, class _BidirectionalIter2,
          class _BidirectionalIter3>
_BidirectionalIter3 __merge_backward(_BidirectionalIter1 __first1,
                                     _BidirectionalIter1 __last1,
                                     _BidirectionalIter2 __first2,
                                     _BidirectionalIter2 __last2,
                                     _BidirectionalIter3 __result)
{
  if (__first1 == __last1)
    return copy_backward(__first2, __last2, __result);
  if (__first2 == __last2)
    return copy_backward(__first1, __last1, __result);
  --__last1;
  --__last2;
  while (true) {
    if (*__last2 < *__last1) {
      *--__result = *__last1;
      if (__first1 == __last1)
        return copy_backward(__first2, ++__last2, __result);
      --__last1;
    }
    else {
      *--__result = *__last2;
      if (__first2 == __last2)
        return copy_backward(__first1, ++__last1, __result);
      --__last2;
    }
  }
}

template <class _BidirectionalIter1, class _BidirectionalIter2,
          class _BidirectionalIter3, class _Compare>
_BidirectionalIter3 __merge_backward(_BidirectionalIter1 __first1,
                                     _BidirectionalIter1 __last1,
                                     _BidirectionalIter2 __first2,
                                     _BidirectionalIter2 __last2,
                                     _BidirectionalIter3 __result,
                                     _Compare __comp)
{
  if (__first1 == __last1)
    return copy_backward(__first2, __last2, __result);
  if (__first2 == __last2)
    return copy_backward(__first1, __last1, __result);
  --__last1;
  --__last2;
  while (true) {
    if (__comp(*__last2, *__last1)) {
      *--__result = *__last1;
      if (__first1 == __last1)
        return copy_backward(__first2, ++__last2, __result);
      --__last1;
    }
    else {
      *--__result = *__last2;
      if (__first2 == __last2)
        return copy_backward(__first1, ++__last1, __result);
      --__last2;
    }
  }
}

template <class _BidirectionalIter, class _Distance, class _Pointer>
void __merge_adaptive(_BidirectionalIter __first,
                      _BidirectionalIter __middle,
                      _BidirectionalIter __last,
                      _Distance __len1, _Distance __len2,
                      _Pointer __buffer, _Distance __buffer_size)
{
  if (__len1 <= __len2 && __len1 <= __buffer_size) {
    _Pointer __buffer_end = copy(__first, __middle, __buffer);
    merge(__buffer, __buffer_end, __middle, __last, __first);
  }
  else if (__len2 <= __buffer_size) {
    _Pointer __buffer_end = copy(__middle, __last, __buffer);
    __merge_backward(__first, __middle, __buffer, __buffer_end, __last);
  }
  else {
    _BidirectionalIter __first_cut = __first;
    _BidirectionalIter __second_cut = __middle;
    _Distance __len11 = 0;
    _Distance __len22 = 0;
    if (__len1 > __len2) {
      __len11 = __len1 / 2;
      advance(__first_cut, __len11);
      __second_cut = lower_bound(__middle, __last, *__first_cut);
      distance(__middle, __second_cut, __len22);
    }
    else {
      __len22 = __len2 / 2;
      advance(__second_cut, __len22);
      __first_cut = upper_bound(__first, __middle, *__second_cut);
      distance(__first, __first_cut, __len11);
    }
    _BidirectionalIter __new_middle =
      __rotate_adaptive(__first_cut, __middle, __second_cut, __len1 - __len11,
                        __len22, __buffer, __buffer_size);
    __merge_adaptive(__first, __first_cut, __new_middle, __len11,
                     __len22, __buffer, __buffer_size);
    __merge_adaptive(__new_middle, __second_cut, __last, __len1 - __len11,
                     __len2 - __len22, __buffer, __buffer_size);
  }
}

template <class _BidirectionalIter, class _Distance, class _Pointer,
          class _Compare>
void __merge_adaptive(_BidirectionalIter __first,
                      _BidirectionalIter __middle,
                      _BidirectionalIter __last,
                      _Distance __len1, _Distance __len2,
                      _Pointer __buffer, _Distance __buffer_size,
                      _Compare __comp)
{
  if (__len1 <= __len2 && __len1 <= __buffer_size) {
    _Pointer __buffer_end = copy(__first, __middle, __buffer);
    merge(__buffer, __buffer_end, __middle, __last, __first, __comp);
  }
  else if (__len2 <= __buffer_size) {
    _Pointer __buffer_end = copy(__middle, __last, __buffer);
    __merge_backward(__first, __middle, __buffer, __buffer_end, __last,
                     __comp);
  }
  else {
    _BidirectionalIter __first_cut = __first;
    _BidirectionalIter __second_cut = __middle;
    _Distance __len11 = 0;
    _Distance __len22 = 0;
    if (__len1 > __len2) {
      __len11 = __len1 / 2;
      advance(__first_cut, __len11);
      __second_cut = lower_bound(__middle, __last, *__first_cut, __comp);
      distance(__middle, __second_cut, __len22);
    }
    else {
      __len22 = __len2 / 2;
      advance(__second_cut, __len22);
      __first_cut = upper_bound(__first, __middle, *__second_cut, __comp);
      distance(__first, __first_cut, __len11);
    }
    _BidirectionalIter __new_middle =
      __rotate_adaptive(__first_cut, __middle, __second_cut, __len1 - __len11,
                        __len22, __buffer, __buffer_size);
    __merge_adaptive(__first, __first_cut, __new_middle, __len11,
                     __len22, __buffer, __buffer_size, __comp);
    __merge_adaptive(__new_middle, __second_cut, __last, __len1 - __len11,
                     __len2 - __len22, __buffer, __buffer_size, __comp);
  }
}

template <class _BidirectionalIter, class _Tp, class _Distance>
inline void __inplace_merge_aux(_BidirectionalIter __first,
                                _BidirectionalIter __middle,
                                _BidirectionalIter __last, _Tp*, _Distance*)
{
  _Distance __len1 = 0;
  distance(__first, __middle, __len1);
  _Distance __len2 = 0;
  distance(__middle, __last, __len2);

  _Temporary_buffer<_BidirectionalIter, _Tp> __buf(__first, __last);
  if (__buf.begin() == 0)
    __merge_without_buffer(__first, __middle, __last, __len1, __len2);
  else
    __merge_adaptive(__first, __middle, __last, __len1, __len2,
                     __buf.begin(), _Distance(__buf.size()));
}

template <class _BidirectionalIter, class _Tp,
          class _Distance, class _Compare>
inline void __inplace_merge_aux(_BidirectionalIter __first,
                                _BidirectionalIter __middle,
                                _BidirectionalIter __last, _Tp*, _Distance*,
                                _Compare __comp)
{
  _Distance __len1 = 0;
  distance(__first, __middle, __len1);
  _Distance __len2 = 0;
  distance(__middle, __last, __len2);

  _Temporary_buffer<_BidirectionalIter, _Tp> __buf(__first, __last);
  if (__buf.begin() == 0)
    __merge_without_buffer(__first, __middle, __last, __len1, __len2, __comp);
  else
    __merge_adaptive(__first, __middle, __last, __len1, __len2,
                     __buf.begin(), _Distance(__buf.size()),
                     __comp);
}

template <class _BidirectionalIter>
inline void inplace_merge(_BidirectionalIter __first,
                          _BidirectionalIter __middle,
                          _BidirectionalIter __last)
{

                            ;

                                                                  ;


  if (__first == __middle || __middle == __last)
    return;
  __inplace_merge_aux(__first, __middle, __last,
                      __value_type(__first), __distance_type(__first));
}

template <class _BidirectionalIter, class _Compare>
inline void inplace_merge(_BidirectionalIter __first,
                          _BidirectionalIter __middle,
                          _BidirectionalIter __last, _Compare __comp)
{

                            ;

                                                                  ;



  if (__first == __middle || __middle == __last)
    return;
  __inplace_merge_aux(__first, __middle, __last,
                      __value_type(__first), __distance_type(__first),
                      __comp);
}






template <class _InputIter1, class _InputIter2>
bool includes(_InputIter1 __first1, _InputIter1 __last1,
              _InputIter2 __first2, _InputIter2 __last2)
{

                                                                 ;
                                                                 ;
                                                           ;


                                                           ;


  while (__first1 != __last1 && __first2 != __last2)
    if (*__first2 < *__first1)
      return false;
    else if(*__first1 < *__first2)
      ++__first1;
    else
      ++__first1, ++__first2;

  return __first2 == __last2;
}

template <class _InputIter1, class _InputIter2, class _Compare>
bool includes(_InputIter1 __first1, _InputIter1 __last1,
              _InputIter2 __first2, _InputIter2 __last2, _Compare __comp)
{

                                                                 ;
                                                                 ;
                                                           ;


                                                           ;



  while (__first1 != __last1 && __first2 != __last2)
    if (__comp(*__first2, *__first1))
      return false;
    else if(__comp(*__first1, *__first2))
      ++__first1;
    else
      ++__first1, ++__first2;

  return __first2 == __last2;
}

template <class _InputIter1, class _InputIter2, class _OutputIter>
_OutputIter set_union(_InputIter1 __first1, _InputIter1 __last1,
                      _InputIter2 __first2, _InputIter2 __last2,
                      _OutputIter __result)
{

                                                                 ;
                                                                 ;
                                                           ;

                                                           ;


                                                           ;


  while (__first1 != __last1 && __first2 != __last2) {
    if (*__first1 < *__first2) {
      *__result = *__first1;
      ++__first1;
    }
    else if (*__first2 < *__first1) {
      *__result = *__first2;
      ++__first2;
    }
    else {
      *__result = *__first1;
      ++__first1;
      ++__first2;
    }
    ++__result;
  }
  return copy(__first2, __last2, copy(__first1, __last1, __result));
}

template <class _InputIter1, class _InputIter2, class _OutputIter,
          class _Compare>
_OutputIter set_union(_InputIter1 __first1, _InputIter1 __last1,
                      _InputIter2 __first2, _InputIter2 __last2,
                      _OutputIter __result, _Compare __comp)
{

                                                                 ;
                                                                 ;
                                                           ;


                                                           ;

                                                           ;



  while (__first1 != __last1 && __first2 != __last2) {
    if (__comp(*__first1, *__first2)) {
      *__result = *__first1;
      ++__first1;
    }
    else if (__comp(*__first2, *__first1)) {
      *__result = *__first2;
      ++__first2;
    }
    else {
      *__result = *__first1;
      ++__first1;
      ++__first2;
    }
    ++__result;
  }
  return copy(__first2, __last2, copy(__first1, __last1, __result));
}

template <class _InputIter1, class _InputIter2, class _OutputIter>
_OutputIter set_intersection(_InputIter1 __first1, _InputIter1 __last1,
                             _InputIter2 __first2, _InputIter2 __last2,
                             _OutputIter __result)
{

                                                                 ;
                                                                 ;
                                                           ;

                                                           ;


                                                           ;


  while (__first1 != __last1 && __first2 != __last2)
    if (*__first1 < *__first2)
      ++__first1;
    else if (*__first2 < *__first1)
      ++__first2;
    else {
      *__result = *__first1;
      ++__first1;
      ++__first2;
      ++__result;
    }
  return __result;
}

template <class _InputIter1, class _InputIter2, class _OutputIter,
          class _Compare>
_OutputIter set_intersection(_InputIter1 __first1, _InputIter1 __last1,
                             _InputIter2 __first2, _InputIter2 __last2,
                             _OutputIter __result, _Compare __comp)
{

                                                                 ;
                                                                 ;
                                                           ;


                                                           ;

                                                           ;



  while (__first1 != __last1 && __first2 != __last2)
    if (__comp(*__first1, *__first2))
      ++__first1;
    else if (__comp(*__first2, *__first1))
      ++__first2;
    else {
      *__result = *__first1;
      ++__first1;
      ++__first2;
      ++__result;
    }
  return __result;
}

template <class _InputIter1, class _InputIter2, class _OutputIter>
_OutputIter set_difference(_InputIter1 __first1, _InputIter1 __last1,
                           _InputIter2 __first2, _InputIter2 __last2,
                           _OutputIter __result)
{

                                                                 ;
                                                                 ;
                                                           ;

                                                           ;


                                                           ;


  while (__first1 != __last1 && __first2 != __last2)
    if (*__first1 < *__first2) {
      *__result = *__first1;
      ++__first1;
      ++__result;
    }
    else if (*__first2 < *__first1)
      ++__first2;
    else {
      ++__first1;
      ++__first2;
    }
  return copy(__first1, __last1, __result);
}

template <class _InputIter1, class _InputIter2, class _OutputIter,
          class _Compare>
_OutputIter set_difference(_InputIter1 __first1, _InputIter1 __last1,
                           _InputIter2 __first2, _InputIter2 __last2,
                           _OutputIter __result, _Compare __comp)
{

                                                                 ;
                                                                 ;
                                                           ;


                                                           ;

                                                           ;



  while (__first1 != __last1 && __first2 != __last2)
    if (__comp(*__first1, *__first2)) {
      *__result = *__first1;
      ++__first1;
      ++__result;
    }
    else if (__comp(*__first2, *__first1))
      ++__first2;
    else {
      ++__first1;
      ++__first2;
    }
  return copy(__first1, __last1, __result);
}

template <class _InputIter1, class _InputIter2, class _OutputIter>
_OutputIter
set_symmetric_difference(_InputIter1 __first1, _InputIter1 __last1,
                         _InputIter2 __first2, _InputIter2 __last2,
                         _OutputIter __result)
{

                                                                 ;
                                                                 ;
                                                           ;

                                                           ;


                                                           ;


  while (__first1 != __last1 && __first2 != __last2)
    if (*__first1 < *__first2) {
      *__result = *__first1;
      ++__first1;
      ++__result;
    }
    else if (*__first2 < *__first1) {
      *__result = *__first2;
      ++__first2;
      ++__result;
    }
    else {
      ++__first1;
      ++__first2;
    }
  return copy(__first2, __last2, copy(__first1, __last1, __result));
}

template <class _InputIter1, class _InputIter2, class _OutputIter,
          class _Compare>
_OutputIter
set_symmetric_difference(_InputIter1 __first1, _InputIter1 __last1,
                         _InputIter2 __first2, _InputIter2 __last2,
                         _OutputIter __result,
                         _Compare __comp)
{

                                                                 ;
                                                                 ;
                                                           ;


                                                           ;

                                                           ;



  while (__first1 != __last1 && __first2 != __last2)
    if (__comp(*__first1, *__first2)) {
      *__result = *__first1;
      ++__first1;
      ++__result;
    }
    else if (__comp(*__first2, *__first1)) {
      *__result = *__first2;
      ++__first2;
      ++__result;
    }
    else {
      ++__first1;
      ++__first2;
    }
  return copy(__first2, __last2, copy(__first1, __last1, __result));
}




template <class _ForwardIter>
_ForwardIter max_element(_ForwardIter __first, _ForwardIter __last)
{

                                                                    ;
                                                            ;


  if (__first == __last) return __first;
  _ForwardIter __result = __first;
  while (++__first != __last)
    if (*__result < *__first)
      __result = __first;
  return __result;
}

template <class _ForwardIter, class _Compare>
_ForwardIter max_element(_ForwardIter __first, _ForwardIter __last,
                         _Compare __comp)
{

                                                                    ;
                                                            ;



  if (__first == __last) return __first;
  _ForwardIter __result = __first;
  while (++__first != __last)
    if (__comp(*__result, *__first)) __result = __first;
  return __result;
}

template <class _ForwardIter>
_ForwardIter min_element(_ForwardIter __first, _ForwardIter __last)
{

                                                                    ;
                                                            ;


  if (__first == __last) return __first;
  _ForwardIter __result = __first;
  while (++__first != __last)
    if (*__first < *__result)
      __result = __first;
  return __result;
}

template <class _ForwardIter, class _Compare>
_ForwardIter min_element(_ForwardIter __first, _ForwardIter __last,
                         _Compare __comp)
{

                                                                    ;
                                                            ;



  if (__first == __last) return __first;
  _ForwardIter __result = __first;
  while (++__first != __last)
    if (__comp(*__first, *__result))
      __result = __first;
  return __result;
}




template <class _BidirectionalIter>
bool next_permutation(_BidirectionalIter __first, _BidirectionalIter __last)
{

                                                                                ;
                                                                  ;


  if (__first == __last)
    return false;
  _BidirectionalIter __i = __first;
  ++__i;
  if (__i == __last)
    return false;
  __i = __last;
  --__i;

  for(;;) {
    _BidirectionalIter __ii = __i;
    --__i;
    if (*__i < *__ii) {
      _BidirectionalIter __j = __last;
      while (!(*__i < *--__j))
        {}
      iter_swap(__i, __j);
      reverse(__ii, __last);
      return true;
    }
    if (__i == __first) {
      reverse(__first, __last);
      return false;
    }
  }
}

template <class _BidirectionalIter, class _Compare>
bool next_permutation(_BidirectionalIter __first, _BidirectionalIter __last,
                      _Compare __comp)
{

                                                                                ;
                                                                  ;



  if (__first == __last)
    return false;
  _BidirectionalIter __i = __first;
  ++__i;
  if (__i == __last)
    return false;
  __i = __last;
  --__i;

  for(;;) {
    _BidirectionalIter __ii = __i;
    --__i;
    if (__comp(*__i, *__ii)) {
      _BidirectionalIter __j = __last;
      while (!__comp(*__i, *--__j))
        {}
      iter_swap(__i, __j);
      reverse(__ii, __last);
      return true;
    }
    if (__i == __first) {
      reverse(__first, __last);
      return false;
    }
  }
}

template <class _BidirectionalIter>
bool prev_permutation(_BidirectionalIter __first, _BidirectionalIter __last)
{

                                                                                ;
                                                                  ;


  if (__first == __last)
    return false;
  _BidirectionalIter __i = __first;
  ++__i;
  if (__i == __last)
    return false;
  __i = __last;
  --__i;

  for(;;) {
    _BidirectionalIter __ii = __i;
    --__i;
    if (*__ii < *__i) {
      _BidirectionalIter __j = __last;
      while (!(*--__j < *__i))
        {}
      iter_swap(__i, __j);
      reverse(__ii, __last);
      return true;
    }
    if (__i == __first) {
      reverse(__first, __last);
      return false;
    }
  }
}

template <class _BidirectionalIter, class _Compare>
bool prev_permutation(_BidirectionalIter __first, _BidirectionalIter __last,
                      _Compare __comp)
{

                                                                                ;
                                                                  ;



  if (__first == __last)
    return false;
  _BidirectionalIter __i = __first;
  ++__i;
  if (__i == __last)
    return false;
  __i = __last;
  --__i;

  for(;;) {
    _BidirectionalIter __ii = __i;
    --__i;
    if (__comp(*__ii, *__i)) {
      _BidirectionalIter __j = __last;
      while (!__comp(*--__j, *__i))
        {}
      iter_swap(__i, __j);
      reverse(__ii, __last);
      return true;
    }
    if (__i == __first) {
      reverse(__first, __last);
      return false;
    }
  }
}



template <class _InputIter, class _ForwardIter>
_InputIter find_first_of(_InputIter __first1, _InputIter __last1,
                         _ForwardIter __first2, _ForwardIter __last2)
{

                                                                ;
                                                                    ;
                                                            ;



  for ( ; __first1 != __last1; ++__first1)
    for (_ForwardIter __iter = __first2; __iter != __last2; ++__iter)
      if (*__first1 == *__iter)
        return __first1;
  return __last1;
}

template <class _InputIter, class _ForwardIter, class _BinaryPredicate>
_InputIter find_first_of(_InputIter __first1, _InputIter __last1,
                         _ForwardIter __first2, _ForwardIter __last2,
                         _BinaryPredicate __comp)
{

                                                                ;
                                                                    ;
                                                            ;


                                                            ;



  for ( ; __first1 != __last1; ++__first1)
    for (_ForwardIter __iter = __first2; __iter != __last2; ++__iter)
      if (__comp(*__first1, *__iter))
        return __first1;
  return __last1;
}
# 3419 "/usr/local/include/g++-v3/bits/stl_algo.h" 3
template <class _ForwardIter1, class _ForwardIter2>
_ForwardIter1 __find_end(_ForwardIter1 __first1, _ForwardIter1 __last1,
                         _ForwardIter2 __first2, _ForwardIter2 __last2,
                         forward_iterator_tag, forward_iterator_tag)
{
  if (__first2 == __last2)
    return __last1;
  else {
    _ForwardIter1 __result = __last1;
    while (1) {
      _ForwardIter1 __new_result
        = search(__first1, __last1, __first2, __last2);
      if (__new_result == __last1)
        return __result;
      else {
        __result = __new_result;
        __first1 = __new_result;
        ++__first1;
      }
    }
  }
}

template <class _ForwardIter1, class _ForwardIter2,
          class _BinaryPredicate>
_ForwardIter1 __find_end(_ForwardIter1 __first1, _ForwardIter1 __last1,
                         _ForwardIter2 __first2, _ForwardIter2 __last2,
                         forward_iterator_tag, forward_iterator_tag,
                         _BinaryPredicate __comp)
{
  if (__first2 == __last2)
    return __last1;
  else {
    _ForwardIter1 __result = __last1;
    while (1) {
      _ForwardIter1 __new_result
        = search(__first1, __last1, __first2, __last2, __comp);
      if (__new_result == __last1)
        return __result;
      else {
        __result = __new_result;
        __first1 = __new_result;
        ++__first1;
      }
    }
  }
}


template <class _BidirectionalIter1, class _BidirectionalIter2>
_BidirectionalIter1
__find_end(_BidirectionalIter1 __first1, _BidirectionalIter1 __last1,
           _BidirectionalIter2 __first2, _BidirectionalIter2 __last2,
           bidirectional_iterator_tag, bidirectional_iterator_tag)
{

                                                                                 ;
                                                                                 ;

  typedef reverse_iterator<_BidirectionalIter1> _RevIter1;
  typedef reverse_iterator<_BidirectionalIter2> _RevIter2;

  _RevIter1 __rlast1(__first1);
  _RevIter2 __rlast2(__first2);
  _RevIter1 __rresult = search(_RevIter1(__last1), __rlast1,
                               _RevIter2(__last2), __rlast2);

  if (__rresult == __rlast1)
    return __last1;
  else {
    _BidirectionalIter1 __result = __rresult.base();
    advance(__result, -distance(__first2, __last2));
    return __result;
  }
}

template <class _BidirectionalIter1, class _BidirectionalIter2,
          class _BinaryPredicate>
_BidirectionalIter1
__find_end(_BidirectionalIter1 __first1, _BidirectionalIter1 __last1,
           _BidirectionalIter2 __first2, _BidirectionalIter2 __last2,
           bidirectional_iterator_tag, bidirectional_iterator_tag,
           _BinaryPredicate __comp)
{

                                                                                 ;
                                                                                 ;

  typedef reverse_iterator<_BidirectionalIter1> _RevIter1;
  typedef reverse_iterator<_BidirectionalIter2> _RevIter2;

  _RevIter1 __rlast1(__first1);
  _RevIter2 __rlast2(__first2);
  _RevIter1 __rresult = search(_RevIter1(__last1), __rlast1,
                               _RevIter2(__last2), __rlast2,
                               __comp);

  if (__rresult == __rlast1)
    return __last1;
  else {
    _BidirectionalIter1 __result = __rresult.base();
    advance(__result, -distance(__first2, __last2));
    return __result;
  }
}



template <class _ForwardIter1, class _ForwardIter2>
inline _ForwardIter1
find_end(_ForwardIter1 __first1, _ForwardIter1 __last1,
         _ForwardIter2 __first2, _ForwardIter2 __last2)
{

                                                                     ;
                                                                     ;
                                                             ;



  return __find_end(__first1, __last1, __first2, __last2,
                    __iterator_category(__first1),
                    __iterator_category(__first2));
}

template <class _ForwardIter1, class _ForwardIter2,
          class _BinaryPredicate>
inline _ForwardIter1
find_end(_ForwardIter1 __first1, _ForwardIter1 __last1,
         _ForwardIter2 __first2, _ForwardIter2 __last2,
         _BinaryPredicate __comp)
{

                                                                     ;
                                                                     ;
                                                             ;



  return __find_end(__first1, __last1, __first2, __last2,
                    __iterator_category(__first1),
                    __iterator_category(__first2),
                    __comp);
}





template <class _RandomAccessIter, class _Distance>
bool __is_heap(_RandomAccessIter __first, _Distance __n)
{
  _Distance __parent = 0;
  for (_Distance __child = 1; __child < __n; ++__child) {
    if (__first[__parent] < __first[__child])
      return false;
    if ((__child & 1) == 0)
      ++__parent;
  }
  return true;
}

template <class _RandomAccessIter, class _Distance, class _StrictWeakOrdering>
bool __is_heap(_RandomAccessIter __first, _StrictWeakOrdering __comp,
               _Distance __n)
{
  _Distance __parent = 0;
  for (_Distance __child = 1; __child < __n; ++__child) {
    if (__comp(__first[__parent], __first[__child]))
      return false;
    if ((__child & 1) == 0)
      ++__parent;
  }
  return true;
}

template <class _RandomAccessIter>
inline bool is_heap(_RandomAccessIter __first, _RandomAccessIter __last)
{

                                                                              ;
                                                                 ;


  return __is_heap(__first, __last - __first);
}


template <class _RandomAccessIter, class _StrictWeakOrdering>
inline bool is_heap(_RandomAccessIter __first, _RandomAccessIter __last,
                    _StrictWeakOrdering __comp)
{

                                                                              ;
                                                                 ;



  return __is_heap(__first, __comp, __last - __first);
}





template <class _ForwardIter>
bool is_sorted(_ForwardIter __first, _ForwardIter __last)
{

                                                                    ;
                                                            ;


  if (__first == __last)
    return true;

  _ForwardIter __next = __first;
  for (++__next; __next != __last; __first = __next, ++__next) {
    if (*__next < *__first)
      return false;
  }

  return true;
}

template <class _ForwardIter, class _StrictWeakOrdering>
bool is_sorted(_ForwardIter __first, _ForwardIter __last,
               _StrictWeakOrdering __comp)
{

                                                                    ;
                                                            ;



  if (__first == __last)
    return true;

  _ForwardIter __next = __first;
  for (++__next; __next != __last; __first = __next, ++__next) {
    if (__comp(*__next, *__first))
      return false;
  }

  return true;
}

}
# 66 "/usr/local/include/g++-v3/bits/std_algorithm.h" 2 3
# 50 "/usr/local/include/g++-v3/bits/std_string.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/basic_string.tcc" 1 3
# 43 "/usr/local/include/g++-v3/bits/basic_string.tcc" 3
namespace std
{
  template<typename _CharT, typename _Traits, typename _Alloc>
    const _CharT
    basic_string<_CharT, _Traits, _Alloc>::
    _Rep::_S_terminal = _CharT();

  template<typename _CharT, typename _Traits, typename _Alloc>
    const typename basic_string<_CharT, _Traits, _Alloc>::size_type
    basic_string<_CharT, _Traits, _Alloc>::
    _Rep::_S_max_size = (((npos - sizeof(_Rep))/sizeof(_CharT)) - 1) / 4;

  template<typename _CharT, typename _Traits, typename _Alloc>
    const typename basic_string<_CharT, _Traits, _Alloc>::size_type
    basic_string<_CharT, _Traits, _Alloc>::npos;



  template<typename _CharT, typename _Traits, typename _Alloc>
    typename basic_string<_CharT, _Traits, _Alloc>::size_type
    basic_string<_CharT, _Traits, _Alloc>::_S_empty_rep_storage[
    (sizeof(_Rep) + sizeof(_CharT) + sizeof(size_type) - 1)/sizeof(size_type)];





  template<typename _CharT, typename _Traits, typename _Alloc>
    template<typename _InIter>
      _CharT*
      basic_string<_CharT, _Traits, _Alloc>::
      _S_construct(_InIter __beg, _InIter __end, const _Alloc& __a,
                   input_iterator_tag)
      {
        if (__beg == __end && __a == _Alloc())
          return _S_empty_rep()._M_refcopy();

        _CharT __buf[100];
        size_type __i = 0;
        while (__beg != __end && __i < sizeof(__buf) / sizeof(_CharT))
          {
            __buf[__i++] = *__beg;
            ++__beg;
          }
        _Rep* __r = _Rep::_S_create(__i, __a);
        traits_type::copy(__r->_M_refdata(), __buf, __i);
        __r->_M_length = __i;
        try
          {



            for (;;)
              {
                _CharT* __p = __r->_M_refdata() + __r->_M_length;
                _CharT* __last = __r->_M_refdata() + __r->_M_capacity;
                for (;;)
                  {
                    if (__beg == __end)
                      {
                        __r->_M_length = __p - __r->_M_refdata();
                        *__p = _Rep::_S_terminal;
                        return __r->_M_refdata();
                      }
                    if (__p == __last)
                      break;
                    *__p++ = *__beg;
                    ++__beg;
                  }

                size_type __len = __p - __r->_M_refdata();
                _Rep* __another = _Rep::_S_create(__len + 1, __a);
                traits_type::copy(__another->_M_refdata(),
                                  __r->_M_refdata(), __len);
                __r->_M_destroy(__a);
                __r = __another;
                __r->_M_length = __len;
              }
          }
        catch(...)
          {
            __r->_M_destroy(__a);
            throw;
          }
        return 0;
      }

  template<typename _CharT, typename _Traits, typename _Alloc>
    template <class _InIter>
      _CharT*
      basic_string<_CharT,_Traits,_Alloc>::
      _S_construct(_InIter __beg, _InIter __end, const _Alloc& __a,
                   forward_iterator_tag)
      {
        size_type __dnew = static_cast<size_type>(distance(__beg, __end));

        if (__beg == __end && __a == _Alloc())
          return _S_empty_rep()._M_refcopy();


        _Rep* __r = _Rep::_S_create(__dnew, __a);
        try
          { _S_copy_chars(__r->_M_refdata(), __beg, __end); }
        catch(...)
          {
            __r->_M_destroy(__a);
            throw;
          }
        __r->_M_length = __dnew;

        __r->_M_refdata()[__dnew] = _Rep::_S_terminal;
        return __r->_M_refdata();
      }

  template<typename _CharT, typename _Traits, typename _Alloc>
    _CharT*
    basic_string<_CharT,_Traits, _Alloc>::
    _S_construct(size_type __n, _CharT __c, const _Alloc& __a)
    {
      if (__n == 0 && __a == _Alloc())
        return _S_empty_rep()._M_refcopy();


      _Rep* __r = _Rep::_S_create(__n, __a);
      try
        {
          if (__n)
            traits_type::assign(__r->_M_refdata(), __n, __c);
        }
      catch(...)
        {
          __r->_M_destroy(__a);
          throw;
        }
      __r->_M_length = __n;
      __r->_M_refdata()[__n] = _Rep::_S_terminal;
      return __r->_M_refdata();
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT, _Traits, _Alloc>::
    basic_string(const basic_string& __str)
    : _M_dataplus(__str._M_rep()->_M_grab(_Alloc(), __str.get_allocator()),
                 __str.get_allocator())
    { }

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT, _Traits, _Alloc>::
    basic_string(const _Alloc& __a)
    : _M_dataplus(_S_construct(size_type(), _CharT(), __a), __a)
    { }

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT, _Traits, _Alloc>::
    basic_string(const basic_string& __str, size_type __pos, size_type __n)
    : _M_dataplus(_S_construct(__str._M_check(__pos),
                               __str._M_fold(__pos, __n), _Alloc()), _Alloc())
    { }

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT, _Traits, _Alloc>::
    basic_string(const basic_string& __str, size_type __pos,
                 size_type __n, const _Alloc& __a)
    : _M_dataplus(_S_construct(__str._M_check(__pos),
                               __str._M_fold(__pos, __n), __a), __a)
    { }

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT, _Traits, _Alloc>::
    basic_string(const _CharT* __s, size_type __n, const _Alloc& __a)
    : _M_dataplus(_S_construct(__s, __s + __n, __a), __a)
    { }

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT, _Traits, _Alloc>::
    basic_string(const _CharT* __s, const _Alloc& __a)
    : _M_dataplus(_S_construct(__s, __s + traits_type::length(__s), __a), __a)
    { }

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT, _Traits, _Alloc>::
    basic_string(size_type __n, _CharT __c, const _Alloc& __a)
    : _M_dataplus(_S_construct(__n, __c, __a), __a)
    { }

  template<typename _CharT, typename _Traits, typename _Alloc>
    template<typename _InputIter>
    basic_string<_CharT, _Traits, _Alloc>::
    basic_string(_InputIter __beg, _InputIter __end, const _Alloc& __a)
    : _M_dataplus(_S_construct(__beg, __end, __a), __a)
    { }

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT, _Traits, _Alloc>&
    basic_string<_CharT, _Traits, _Alloc>::assign(const basic_string& __str)
    {
      if (_M_rep() != __str._M_rep())
        {

          allocator_type __a = this->get_allocator();
          _CharT* __tmp = __str._M_rep()->_M_grab(__a, __str.get_allocator());
          _M_rep()->_M_dispose(__a);
          _M_data(__tmp);
        }
      return *this;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    void
    basic_string<_CharT, _Traits, _Alloc>::_Rep::
    _M_destroy(const _Alloc& __a) throw ()
    {
      size_type __size = sizeof(_Rep) + (_M_capacity + 1) * sizeof(_CharT);
      _Raw_bytes_alloc(__a).deallocate(reinterpret_cast<char*>(this), __size);
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    void
    basic_string<_CharT, _Traits, _Alloc>::_M_leak_hard()
    {
      if (_M_rep()->_M_is_shared())
        _M_mutate(0, 0, 0);
      _M_rep()->_M_set_leaked();
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    void
    basic_string<_CharT, _Traits, _Alloc>::
    _M_mutate(size_type __pos, size_type __len1, size_type __len2)
    {
      size_type __old_size = this->size();
      const size_type __new_size = __old_size + __len2 - __len1;
      const _CharT* __src = _M_data() + __pos + __len1;
      const size_type __how_much = __old_size - __pos - __len1;

      if (_M_rep()->_M_is_shared() || __new_size > capacity())
        {

          allocator_type __a = get_allocator();
          _Rep* __r = _Rep::_S_create(__new_size, __a);
          try
            {
              if (__pos)
                traits_type::copy(__r->_M_refdata(), _M_data(), __pos);
              if (__how_much)
                traits_type::copy(__r->_M_refdata() + __pos + __len2,
                                  __src, __how_much);
            }
          catch(...)
            {
              __r->_M_dispose(get_allocator());
              throw;
            }
          _M_rep()->_M_dispose(__a);
          _M_data(__r->_M_refdata());
      }
      else if (__how_much && __len1 != __len2)
        {

          traits_type::move(_M_data() + __pos + __len2, __src, __how_much);
        }
      _M_rep()->_M_set_sharable();
      _M_rep()->_M_length = __new_size;
      _M_data()[__new_size] = _Rep::_S_terminal;

    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    void
    basic_string<_CharT, _Traits, _Alloc>::reserve(size_type __res)
    {
      if (__res > this->capacity() || _M_rep()->_M_is_shared())
        {
          if (__res > this->max_size())
            __throw_length_error("basic_string::reserve");
          allocator_type __a = get_allocator();
          _CharT* __tmp = _M_rep()->_M_clone(__a, __res - this->size());
          _M_rep()->_M_dispose(__a);
          _M_data(__tmp);
        }
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    void basic_string<_CharT, _Traits, _Alloc>::swap(basic_string& __s)
    {
      if (_M_rep()->_M_is_leaked())
        _M_rep()->_M_set_sharable();
      if (__s._M_rep()->_M_is_leaked())
        __s._M_rep()->_M_set_sharable();
      if (this->get_allocator() == __s.get_allocator())
        {
          _CharT* __tmp = _M_data();
          _M_data(__s._M_data());
          __s._M_data(__tmp);
        }

      else
        {
          basic_string __tmp1(_M_ibegin(), _M_iend(), __s.get_allocator());
          basic_string __tmp2(__s._M_ibegin(), __s._M_iend(),
                              this->get_allocator());
          *this = __tmp2;
          __s = __tmp1;
        }
    }
# 356 "/usr/local/include/g++-v3/bits/basic_string.tcc" 3
  template<typename _CharT, typename _Traits, typename _Alloc>
    typename basic_string<_CharT, _Traits, _Alloc>::_Rep*
    basic_string<_CharT, _Traits, _Alloc>::_Rep::
    _S_create(size_t __capacity, const _Alloc& __alloc)
    {
      typedef basic_string<_CharT, _Traits, _Alloc> __string_type;


      if (__capacity > _S_max_size)



        __throw_length_error("basic_string::_S_create");




      size_t __size = (__capacity + 1) * sizeof(_CharT) + sizeof(_Rep);


      void* __place = _Raw_bytes_alloc(__alloc).allocate(__size);
      _Rep *__p = new (__place) _Rep;
      __p->_M_capacity = __capacity;
      __p->_M_set_sharable();
      __p->_M_length = 0;
      return __p;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    _CharT*
    basic_string<_CharT, _Traits, _Alloc>::_Rep::
    _M_clone(const _Alloc& __alloc, size_type __res)
    {
      _Rep* __r = _Rep::_S_create(_M_length + __res, __alloc);
      if (_M_length)
        {
          try
            { traits_type::copy(__r->_M_refdata(), _M_refdata(), _M_length); }
          catch(...)
            {
              __r->_M_destroy(__alloc);
              throw;
            }
        }
      __r->_M_length = _M_length;
      return __r->_M_refdata();
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
  inline bool




    basic_string<_CharT, _Traits, _Alloc>::_Rep::
    _S_excess_slop(size_t __s, size_t __r)

    {
      return 2 * (__s <= 16 ? 16 : __s) < __r;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    void
    basic_string<_CharT, _Traits, _Alloc>::resize(size_type __n, _CharT __c)
    {
      if (__n > max_size())
        __throw_length_error("basic_string::resize");
      size_type __size = this->size();
      if (__size < __n)
        this->append(__n - __size, __c);
      else if (__n < __size)
        this->erase(__n);

    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    template<typename _InputIter>
      basic_string<_CharT, _Traits, _Alloc>&
      basic_string<_CharT, _Traits, _Alloc>::
      _M_replace(iterator __i1, iterator __i2, _InputIter __k1,
                 _InputIter __k2, input_iterator_tag)
      {
        basic_string __s(__k1, __k2);
        return this->replace(__i1, __i2, __s._M_ibegin(), __s._M_iend());
      }

  template<typename _CharT, typename _Traits, typename _Alloc>
    template<typename _ForwardIter>
      basic_string<_CharT, _Traits, _Alloc>&
      basic_string<_CharT, _Traits, _Alloc>::
      _M_replace(iterator __i1, iterator __i2, _ForwardIter __k1,
                 _ForwardIter __k2, forward_iterator_tag)
      {
        size_type __dold = __i2 - __i1;
        size_type __dmax = this->max_size();
        size_type __dnew = static_cast<size_type>(distance(__k1, __k2));

        if (__dmax <= __dnew)
          __throw_length_error("basic_string::_M_replace");
        size_type __off = __i1 - _M_ibegin();
        _M_mutate(__off, __dold, __dnew);

        if (__dnew)
          _S_copy_chars(_M_data() + __off, __k1, __k2);

        return *this;
      }

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT, _Traits, _Alloc>&
    basic_string<_CharT, _Traits, _Alloc>::
    replace(size_type __pos1, size_type __n1, const basic_string& __str,
            size_type __pos2, size_type __n2)
    {
      return this->replace(_M_check(__pos1), _M_fold(__pos1, __n1),
                           __str._M_check(__pos2),
                           __str._M_fold(__pos2, __n2));
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT,_Traits,_Alloc>&
    basic_string<_CharT,_Traits,_Alloc>::
    append(const basic_string& __str)
    {



      size_type __size = __str.size();
      size_type __len = __size + this->size();
      if (__len > this->capacity())
        this->reserve(__len);
      return this->replace(_M_iend(), _M_iend(), __str._M_ibegin(),
                           __str._M_iend());
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT,_Traits,_Alloc>&
    basic_string<_CharT,_Traits,_Alloc>::
    append(const basic_string& __str, size_type __pos, size_type __n)
    {



      size_type __len = min(__str.size() - __pos, __n) + this->size();
      if (__len > this->capacity())
        this->reserve(__len);
      return this->replace(_M_iend(), _M_iend(), __str._M_check(__pos),
                           __str._M_fold(__pos, __n));
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT,_Traits,_Alloc>&
    basic_string<_CharT,_Traits,_Alloc>::
    append(const _CharT* __s, size_type __n)
    {
      size_type __len = __n + this->size();
      if (__len > this->capacity())
        this->reserve(__len);
      return this->replace(_M_iend(), _M_iend(), __s, __s + __n);
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT,_Traits,_Alloc>&
    basic_string<_CharT,_Traits,_Alloc>::
    append(size_type __n, _CharT __c)
    {
      size_type __len = __n + this->size();
      if (__len > this->capacity())
        this->reserve(__len);
       return this->replace(_M_iend(), _M_iend(), __n, __c);
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT,_Traits,_Alloc>
    operator+(const _CharT* __lhs,
             const basic_string<_CharT,_Traits,_Alloc>& __rhs)
    {
      typedef basic_string<_CharT,_Traits,_Alloc> __string_type;
      typedef typename __string_type::size_type __size_type;
      __size_type __len = _Traits::length(__lhs);
      __string_type __str;
      __str.reserve(__len + __rhs.size());
      __str.append(__lhs, __lhs + __len);
      __str.append(__rhs);
      return __str;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT,_Traits,_Alloc>
    operator+(_CharT __lhs, const basic_string<_CharT,_Traits,_Alloc>& __rhs)
    {
      typedef basic_string<_CharT,_Traits,_Alloc> __string_type;
      typedef typename __string_type::size_type __size_type;
      __string_type __str;
      __size_type __len = __rhs.size();
      __str.reserve(__len + 1);
      __str.append(__size_type(1), __lhs);
      __str.append(__rhs);
      return __str;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_string<_CharT, _Traits, _Alloc>&
    basic_string<_CharT, _Traits, _Alloc>::
    replace(iterator __i1, iterator __i2, size_type __n2, _CharT __c)
    {
      size_type __n1 = __i2 - __i1;
      size_type __off1 = __i1 - _M_ibegin();
      if (max_size() - (this->size() - __n1) <= __n2)
        __throw_length_error("basic_string::replace");
      _M_mutate (__off1, __n1, __n2);

      if (__n2)
        traits_type::assign(_M_data() + __off1, __n2, __c);
      return *this;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    typename basic_string<_CharT, _Traits, _Alloc>::size_type
    basic_string<_CharT, _Traits, _Alloc>::
    copy(_CharT* __s, size_type __n, size_type __pos) const
    {
      if (__pos > this->size())
        __throw_out_of_range("basic_string::copy");

      if (__n > this->size() - __pos)
        __n = this->size() - __pos;

      traits_type::copy(__s, _M_data() + __pos, __n);

      return __n;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    typename basic_string<_CharT, _Traits, _Alloc>::size_type
    basic_string<_CharT, _Traits, _Alloc>::
    find(const _CharT* __s, size_type __pos, size_type __n) const
    {
      size_type __size = this->size();
      size_t __xpos = __pos;
      const _CharT* __data = _M_data();
      for (; __xpos + __n <= __size; ++__xpos)
        if (traits_type::compare(__data + __xpos, __s, __n) == 0)
          return __xpos;
      return npos;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    typename basic_string<_CharT, _Traits, _Alloc>::size_type
    basic_string<_CharT, _Traits, _Alloc>::
    find(_CharT __c, size_type __pos) const
    {
      size_type __size = this->size();
      size_type __ret = npos;
      if (__pos < __size)
        {
          const _CharT* __data = _M_data();
          size_type __n = __size - __pos;
          const _CharT* __p = traits_type::find(__data + __pos, __n, __c);
          if (__p)
            __ret = __p - __data;
        }
      return __ret;
    }


  template<typename _CharT, typename _Traits, typename _Alloc>
    typename basic_string<_CharT, _Traits, _Alloc>::size_type
    basic_string<_CharT, _Traits, _Alloc>::
    rfind(const _CharT* __s, size_type __pos, size_type __n) const
    {
      size_type __size = this->size();
      if (__n <= __size)
        {
          __pos = std::min(__size - __n ,__pos);
          const _CharT* __data = _M_data();
          do
            {
              if (traits_type::compare(__data + __pos, __s, __n) == 0)
                return __pos;
            }
          while (__pos-- > 0);
        }
      return npos;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    typename basic_string<_CharT, _Traits, _Alloc>::size_type
    basic_string<_CharT, _Traits, _Alloc>::
    rfind(_CharT __c, size_type __pos) const
    {
      size_type __size = this->size();
      if (__size)
        {
          size_t __xpos = __size - 1;
          if (__xpos > __pos)
            __xpos = __pos;

          for (++__xpos; __xpos-- > 0; )
            if (traits_type::eq(_M_data()[__xpos], __c))
              return __xpos;
        }
      return npos;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    typename basic_string<_CharT, _Traits, _Alloc>::size_type
    basic_string<_CharT, _Traits, _Alloc>::
    find_first_of(const _CharT* __s, size_type __pos, size_type __n) const
    {
      for (; __n && __pos < this->size(); ++__pos)
        {
          const _CharT* __p = traits_type::find(__s, __n, _M_data()[__pos]);
          if (__p)
            return __pos;
        }
      return npos;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    typename basic_string<_CharT, _Traits, _Alloc>::size_type
    basic_string<_CharT, _Traits, _Alloc>::
    find_last_of(const _CharT* __s, size_type __pos, size_type __n) const
    {
      size_type __size = this->size();
      if (__size && __n)
        {
          if (--__size > __pos)
            __size = __pos;
          do
            {
              if (traits_type::find(__s, __n, _M_data()[__size]))
                return __size;
            }
          while (__size-- != 0);
        }
      return npos;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    typename basic_string<_CharT, _Traits, _Alloc>::size_type
    basic_string<_CharT, _Traits, _Alloc>::
    find_first_not_of(const _CharT* __s, size_type __pos, size_type __n) const
    {
      size_t __xpos = __pos;
      for (; __n && __xpos < this->size(); ++__xpos)
        if (!traits_type::find(__s, __n, _M_data()[__xpos]))
          return __xpos;
      return npos;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    typename basic_string<_CharT, _Traits, _Alloc>::size_type
    basic_string<_CharT, _Traits, _Alloc>::
    find_first_not_of(_CharT __c, size_type __pos) const
    {
      size_t __xpos = __pos;
      for (; __xpos < this->size(); ++__xpos)
        if (!traits_type::eq(_M_data()[__xpos], __c))
          return __xpos;
      return npos;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    typename basic_string<_CharT, _Traits, _Alloc>::size_type
    basic_string<_CharT, _Traits, _Alloc>::
    find_last_not_of(const _CharT* __s, size_type __pos, size_type __n) const
    {
      size_type __size = this->size();
      if (__size && __n)
        {
          if (--__size > __pos)
            __size = __pos;
          do
            {
              if (!traits_type::find(__s, __n, _M_data()[__size]))
                return __size;
            }
          while (__size--);
        }
      return npos;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    typename basic_string<_CharT, _Traits, _Alloc>::size_type
    basic_string<_CharT, _Traits, _Alloc>::
    find_last_not_of(_CharT __c, size_type __pos) const
    {
      size_type __size = this->size();
      if (__size)
        {
          if (--__size > __pos)
            __size = __pos;
          do
            {
              if (!traits_type::eq(_M_data()[__size], __c))
                return __size;
            }
          while (__size--);
        }
      return npos;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    int
    basic_string<_CharT, _Traits, _Alloc>::
    compare(size_type __pos, size_type __n, const basic_string& __str) const
    {
      size_type __size = this->size();
      size_type __osize = __str.size();
      if (__pos > __size)
        __throw_out_of_range("basic_string::compare");

      size_type __rsize= min(__size - __pos, __n);
      size_type __len = min(__rsize, __osize);
      int __r = traits_type::compare(_M_data() + __pos, __str.data(), __len);
      if (!__r)
        __r = __rsize - __osize;
      return __r;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    int
    basic_string<_CharT, _Traits, _Alloc>::
    compare(size_type __pos1, size_type __n1, const basic_string& __str,
            size_type __pos2, size_type __n2) const
    {
      size_type __size = this->size();
      size_type __osize = __str.size();
      if (__pos1 > __size || __pos2 > __osize)
        __throw_out_of_range("basic_string::compare");

      size_type __rsize = min(__size - __pos1, __n1);
      size_type __rosize = min(__osize - __pos2, __n2);
      size_type __len = min(__rsize, __rosize);
      int __r = traits_type::compare(_M_data() + __pos1,
                                     __str.data() + __pos2, __len);
      if (!__r)
        __r = __rsize - __rosize;
      return __r;
    }


  template<typename _CharT, typename _Traits, typename _Alloc>
    int
    basic_string<_CharT, _Traits, _Alloc>::
    compare(const _CharT* __s) const
    {
      size_type __size = this->size();
      int __r = traits_type::compare(_M_data(), __s, __size);
      if (!__r)
        __r = __size - traits_type::length(__s);
      return __r;
    }


  template<typename _CharT, typename _Traits, typename _Alloc>
    int
    basic_string <_CharT,_Traits,_Alloc>::
    compare(size_type __pos, size_type __n1, const _CharT* __s) const
    {
      size_type __size = this->size();
      if (__pos > __size)
        __throw_out_of_range("basic_string::compare");

      size_type __osize = traits_type::length(__s);
      size_type __rsize = min(__size - __pos, __n1);
      size_type __len = min(__rsize, __osize);
      int __r = traits_type::compare(_M_data() + __pos, __s, __len);
      if (!__r)
        __r = __rsize - __osize;
      return __r;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    int
    basic_string <_CharT,_Traits,_Alloc>::
    compare(size_type __pos, size_type __n1, const _CharT* __s,
            size_type __n2) const
    {
      size_type __size = this->size();
      if (__pos > __size)
        __throw_out_of_range("basic_string::compare");

      size_type __osize = min(traits_type::length(__s), __n2);
      size_type __rsize = min(__size - __pos, __n1);
      size_type __len = min(__rsize, __osize);
      int __r = traits_type::compare(_M_data() + __pos, __s, __len);
      if (!__r)
        __r = __rsize - __osize;
      return __r;
    }

  template <class _CharT, class _Traits, class _Alloc>
    void
    _S_string_copy(const basic_string<_CharT, _Traits, _Alloc>& __str,
                   _CharT* __buf, typename _Alloc::size_type __bufsiz)
    {
      typedef typename _Alloc::size_type size_type;
      size_type __strsize = __str.size();
      size_type __bytes = min(__strsize, __bufsiz - 1);
      _Traits::copy(__buf, __str.data(), __bytes);
      __buf[__bytes] = _CharT();
    }
}
# 51 "/usr/local/include/g++-v3/bits/std_string.h" 2 3
# 43 "/usr/local/include/g++-v3/bits/localefwd.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_cctype.h" 1 3
# 38 "/usr/local/include/g++-v3/bits/std_cctype.h" 3
# 1 "/usr/include/ctype.h" 1 3
# 26 "/usr/include/ctype.h" 3
# 1 "/usr/include/features.h" 1 3
# 27 "/usr/include/ctype.h" 2 3
# 1 "/usr/include/bits/types.h" 1 3
# 28 "/usr/include/ctype.h" 2 3

extern "C" {
# 40 "/usr/include/ctype.h" 3
# 1 "/usr/include/endian.h" 1 3
# 41 "/usr/include/ctype.h" 2 3






enum
{
  _ISupper = ((0) < 8 ? ((1 << (0)) << 8) : ((1 << (0)) >> 8)),
  _ISlower = ((1) < 8 ? ((1 << (1)) << 8) : ((1 << (1)) >> 8)),
  _ISalpha = ((2) < 8 ? ((1 << (2)) << 8) : ((1 << (2)) >> 8)),
  _ISdigit = ((3) < 8 ? ((1 << (3)) << 8) : ((1 << (3)) >> 8)),
  _ISxdigit = ((4) < 8 ? ((1 << (4)) << 8) : ((1 << (4)) >> 8)),
  _ISspace = ((5) < 8 ? ((1 << (5)) << 8) : ((1 << (5)) >> 8)),
  _ISprint = ((6) < 8 ? ((1 << (6)) << 8) : ((1 << (6)) >> 8)),
  _ISgraph = ((7) < 8 ? ((1 << (7)) << 8) : ((1 << (7)) >> 8)),
  _ISblank = ((8) < 8 ? ((1 << (8)) << 8) : ((1 << (8)) >> 8)),
  _IScntrl = ((9) < 8 ? ((1 << (9)) << 8) : ((1 << (9)) >> 8)),
  _ISpunct = ((10) < 8 ? ((1 << (10)) << 8) : ((1 << (10)) >> 8)),
  _ISalnum = ((11) < 8 ? ((1 << (11)) << 8) : ((1 << (11)) >> 8))
};
# 75 "/usr/include/ctype.h" 3
extern __const unsigned short int *__ctype_b;
extern __const __int32_t *__ctype_tolower;
extern __const __int32_t *__ctype_toupper;
# 91 "/usr/include/ctype.h" 3
extern int isalnum (int) throw ();
extern int isalpha (int) throw ();
extern int iscntrl (int) throw ();
extern int isdigit (int) throw ();
extern int islower (int) throw ();
extern int isgraph (int) throw ();
extern int isprint (int) throw ();
extern int ispunct (int) throw ();
extern int isspace (int) throw ();
extern int isupper (int) throw ();
extern int isxdigit (int) throw ();


extern int isblank (int) throw ();




extern int tolower (int __c) throw ();


extern int toupper (int __c) throw ();






extern int isascii (int __c) throw ();



extern int toascii (int __c) throw ();



extern int _toupper (int) throw ();
extern int _tolower (int) throw ();
# 210 "/usr/include/ctype.h" 3
# 1 "/usr/include/xlocale.h" 1 3
# 211 "/usr/include/ctype.h" 2 3
# 223 "/usr/include/ctype.h" 3
extern int __isalnum_l (int, __locale_t) throw ();
extern int __isalpha_l (int, __locale_t) throw ();
extern int __iscntrl_l (int, __locale_t) throw ();
extern int __isdigit_l (int, __locale_t) throw ();
extern int __islower_l (int, __locale_t) throw ();
extern int __isgraph_l (int, __locale_t) throw ();
extern int __isprint_l (int, __locale_t) throw ();
extern int __ispunct_l (int, __locale_t) throw ();
extern int __isspace_l (int, __locale_t) throw ();
extern int __isupper_l (int, __locale_t) throw ();
extern int __isxdigit_l (int, __locale_t) throw ();

extern int __isblank_l (int, __locale_t) throw ();



extern int __tolower_l (int __c, __locale_t __l) throw ();


extern int __toupper_l (int __c, __locale_t __l) throw ();
# 276 "/usr/include/ctype.h" 3
}
# 39 "/usr/local/include/g++-v3/bits/std_cctype.h" 2 3
# 55 "/usr/local/include/g++-v3/bits/std_cctype.h" 3
namespace std
{
  using ::isalnum;
  using ::isalpha;
  using ::iscntrl;
  using ::isdigit;
  using ::isgraph;
  using ::islower;
  using ::isprint;
  using ::ispunct;
  using ::isspace;
  using ::isupper;
  using ::isxdigit;
  using ::tolower;
  using ::toupper;
}
# 44 "/usr/local/include/g++-v3/bits/localefwd.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/functexcept.h" 1 3
# 34 "/usr/local/include/g++-v3/bits/functexcept.h" 3
# 1 "/usr/local/include/g++-v3/exception_defines.h" 1 3
# 35 "/usr/local/include/g++-v3/bits/functexcept.h" 2 3

namespace std
{

  void
  __throw_bad_exception(void);


  void
  __throw_bad_alloc(void);


  void
  __throw_bad_cast(void);

  void
  __throw_bad_typeid(void);


  void
  __throw_logic_error(const char* __s);

  void
  __throw_domain_error(const char* __s);

  void
  __throw_invalid_argument(const char* __s);

  void
  __throw_length_error(const char* __s);

  void
  __throw_out_of_range(const char* __s);

  void
  __throw_runtime_error(const char* __s);

  void
  __throw_range_error(const char* __s);

  void
  __throw_overflow_error(const char* __s);

  void
  __throw_underflow_error(const char* __s);


  void
  __throw_ios_failure(const char* __s);
}
# 45 "/usr/local/include/g++-v3/bits/localefwd.h" 2 3

namespace std
{
# 56 "/usr/local/include/g++-v3/bits/localefwd.h" 3
  template<typename _Tp, typename _Alloc>
    class vector;
  class locale;


  template<typename _CharT>
    inline bool
    isspace(_CharT, const locale&);

  template<typename _CharT>
    inline bool
    isprint(_CharT, const locale&);

  template<typename _CharT>
    inline bool
    iscntrl(_CharT, const locale&);

  template<typename _CharT>
    inline bool
    isupper(_CharT, const locale&);

  template<typename _CharT>
    inline bool
    islower(_CharT, const locale&);

  template<typename _CharT>
    inline bool
    isalpha(_CharT, const locale&);

  template<typename _CharT>
    inline bool
    isdigit(_CharT, const locale&);

  template<typename _CharT>
    inline bool
    ispunct(_CharT, const locale&);

  template<typename _CharT>
    inline bool
    isxdigit(_CharT, const locale&);

  template<typename _CharT>
    inline bool
    isalnum(_CharT, const locale&);

  template<typename _CharT>
    inline bool
    isgraph(_CharT, const locale&);

  template<typename _CharT>
    inline _CharT
    toupper(_CharT, const locale&);

  template<typename _CharT>
    inline _CharT
    tolower(_CharT, const locale&);



  class ctype_base;
  template<typename _CharT>
    class ctype;
  template<> class ctype<char>;

  template<> class ctype<wchar_t>;

  template<typename _CharT>
    class ctype_byname;


  class codecvt_base;
  template<typename _InternT, typename _ExternT, typename _StateT>
    class codecvt;
  template<> class codecvt<char, char, mbstate_t>;

  template<> class codecvt<wchar_t, char, mbstate_t>;

  template<typename _InternT, typename _ExternT, typename _StateT>
    class codecvt_byname;


  template<typename _CharT, typename _InIter = istreambuf_iterator<_CharT> >
    class num_get;
  template<typename _CharT, typename _OutIter = ostreambuf_iterator<_CharT> >
    class num_put;
  template<typename _CharT> class numpunct;
  template<typename _CharT> class numpunct_byname;


  template<typename _CharT>
    class collate;
  template<typename _CharT> class
    collate_byname;


  class time_base;
  template<typename _CharT, typename _InIter = istreambuf_iterator<_CharT> >
    class time_get;
  template<typename _CharT, typename _InIter = istreambuf_iterator<_CharT> >
    class time_get_byname;
  template<typename _CharT, typename _OutIter = ostreambuf_iterator<_CharT> >
    class time_put;
  template<typename _CharT, typename _OutIter = ostreambuf_iterator<_CharT> >
    class time_put_byname;


  class money_base;
  template<typename _CharT, typename _InIter = istreambuf_iterator<_CharT> >
    class money_get;
  template<typename _CharT, typename _OutIter = ostreambuf_iterator<_CharT> >
    class money_put;
  template<typename _CharT, bool _Intl = false>
    class moneypunct;
  template<typename _CharT, bool _Intl = false>
    class moneypunct_byname;


  class messages_base;
  template<typename _CharT>
    class messages;
  template<typename _CharT>
    class messages_byname;


  class locale
  {
  public:

    typedef unsigned int category;


    class facet;
    class id;
    class _Impl;

    friend class facet;
    friend class _Impl;

    template<typename _Facet>
      friend const _Facet&
      use_facet(const locale&);

    template<typename _Facet>
      friend bool
      has_facet(const locale&) throw();



    static const category none = 0;
    static const category ctype = 1L << 0;
    static const category numeric = 1L << 1;
    static const category collate = 1L << 2;
    static const category time = 1L << 3;
    static const category monetary = 1L << 4;
    static const category messages = 1L << 5;
    static const category all = (collate | ctype | monetary |
                                           numeric | time | messages);


    locale() throw();

    locale(const locale& __other) throw();

    explicit
    locale(const char* __std_name);

    locale(const locale& __base, const char* __s, category __cat);

    locale(const locale& __base, const locale& __add, category __cat);

    template<typename _Facet>
      locale(const locale& __other, _Facet* __f);

    ~locale() throw();

    const locale&
    operator=(const locale& __other) throw();

    template<typename _Facet>
      locale
      combine(const locale& __other);


    string
    name() const;

    bool
    operator==(const locale& __other) const throw ();

    inline bool
    operator!=(const locale& __other) const throw ()
    { return !(this->operator==(__other)); }

    template<typename _Char, typename _Traits, typename _Alloc>
      bool
      operator()(const basic_string<_Char, _Traits, _Alloc>& __s1,
                 const basic_string<_Char, _Traits, _Alloc>& __s2) const;


    static locale
    global(const locale&);

    static const locale&
    classic();

  private:

    _Impl* _M_impl;


    static _Impl* _S_classic;


    static _Impl* _S_global;

    static const size_t _S_num_categories = 6;
    static const size_t _S_num_facets = 26;

    explicit
    locale(_Impl*) throw();

    static inline void
    _S_initialize()
    { if (!_S_classic) classic(); }

    static category
    _S_normalize_category(category);

    void
    _M_coalesce(const locale& __base, const locale& __add, category __cat);
  };



  class locale::_Impl
  {
  public:

    typedef vector<facet*, allocator<facet*> > __vec_facet;


    friend class locale;
    friend class locale::facet;

    template<typename _Facet>
      friend const _Facet&
      use_facet(const locale&);

    template<typename _Facet>
      friend bool
      has_facet(const locale&) throw();

  private:

    size_t _M_references;
    __vec_facet* _M_facets;
    string _M_names[_S_num_categories];
    __c_locale _M_c_locale;
    static const locale::id* const _S_id_ctype[];
    static const locale::id* const _S_id_numeric[];
    static const locale::id* const _S_id_collate[];
    static const locale::id* const _S_id_time[];
    static const locale::id* const _S_id_monetary[];
    static const locale::id* const _S_id_messages[];
    static const locale::id* const* const _S_facet_categories[];

    inline void
    _M_add_reference() throw()
    { ++_M_references; }

    inline void
    _M_remove_reference() throw()
    {
      if (_M_references-- == 0)
        {
          try
            { delete this; }
          catch(...)
            { }
        }
    }

    _Impl(const _Impl&, size_t);
    _Impl(string __name, size_t);
   ~_Impl() throw();

    bool
    _M_check_same_name()
    {
      bool __ret = true;
      for (size_t i = 0; i < _S_num_categories - 1; ++i)
        __ret &= _M_names[i] == _M_names[i + 1];
      return __ret;
    }
    void
    _M_replace_categories(const _Impl*, category);

    void
    _M_replace_category(const _Impl*, const locale::id* const*);

    void
    _M_replace_facet(const _Impl*, const locale::id*);

    void
    _M_install_facet(const locale::id*, facet*);

    template<typename _Facet>
      inline void
      _M_init_facet(_Facet* __facet)
      { _M_install_facet(&_Facet::id, __facet); }
  };

  template<typename _Facet>
    locale::locale(const locale& __other, _Facet* __f)
    {
      _M_impl = new _Impl(*__other._M_impl, 1);
      _M_impl->_M_install_facet(&_Facet::id, __f);
      for (size_t __i = 0; __i < _S_num_categories; ++__i)
        _M_impl->_M_names[__i] = "*";
    }


  class locale::facet
  {
    friend class locale;
    friend class locale::_Impl;

  protected:
    explicit
    facet(size_t __refs = 0) throw();

    virtual
    ~facet() { };

    static void
    _S_create_c_locale(__c_locale& __cloc, const char* __s);

    static void
    _S_destroy_c_locale(__c_locale& __cloc);

  private:
    size_t _M_references;

    void
    _M_add_reference() throw();

    void
    _M_remove_reference() throw();

    facet(const facet&);

    void
    operator=(const facet&);
  };



  class locale::id
  {
  private:
    friend class locale;
    friend class locale::_Impl;
    template<typename _Facet>
      friend const _Facet&
      use_facet(const locale&);
    template<typename _Facet>
      friend bool
      has_facet(const locale&) throw ();




    mutable size_t _M_index;


    static size_t _S_highwater;

    void
    operator=(const id&);

    id(const id&);

  public:



    id() { }
  };

  template<typename _Facet>
    const _Facet&
    use_facet(const locale& __loc);

  template<typename _Facet>
    bool
    has_facet(const locale& __loc) throw();
}
# 44 "/usr/local/include/g++-v3/bits/std_ios.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/ios_base.h" 1 3
# 38 "/usr/local/include/g++-v3/bits/ios_base.h" 3

namespace std
{




  enum _Ios_Fmtflags { _M_ios_fmtflags_end = 1L << 16 };

  inline _Ios_Fmtflags
  operator&(_Ios_Fmtflags __a, _Ios_Fmtflags __b)
  { return _Ios_Fmtflags(static_cast<int>(__a) & static_cast<int>(__b)); }

  inline _Ios_Fmtflags
  operator|(_Ios_Fmtflags __a, _Ios_Fmtflags __b)
  { return _Ios_Fmtflags(static_cast<int>(__a) | static_cast<int>(__b)); }

  inline _Ios_Fmtflags
  operator^(_Ios_Fmtflags __a, _Ios_Fmtflags __b)
  { return _Ios_Fmtflags(static_cast<int>(__a) ^ static_cast<int>(__b)); }

  inline _Ios_Fmtflags
  operator|=(_Ios_Fmtflags& __a, _Ios_Fmtflags __b)
  { return __a = __a | __b; }

  inline _Ios_Fmtflags
  operator&=(_Ios_Fmtflags& __a, _Ios_Fmtflags __b)
  { return __a = __a & __b; }

  inline _Ios_Fmtflags
  operator^=(_Ios_Fmtflags& __a, _Ios_Fmtflags __b)
  { return __a = __a ^ __b; }

  inline _Ios_Fmtflags
  operator~(_Ios_Fmtflags __a)
  { return _Ios_Fmtflags(~static_cast<int>(__a)); }


  enum _Ios_Openmode { _M_ios_openmode_end = 1L << 16 };

  inline _Ios_Openmode
  operator&(_Ios_Openmode __a, _Ios_Openmode __b)
  { return _Ios_Openmode(static_cast<int>(__a) & static_cast<int>(__b)); }

  inline _Ios_Openmode
  operator|(_Ios_Openmode __a, _Ios_Openmode __b)
  { return _Ios_Openmode(static_cast<int>(__a) | static_cast<int>(__b)); }

  inline _Ios_Openmode
  operator^(_Ios_Openmode __a, _Ios_Openmode __b)
  { return _Ios_Openmode(static_cast<int>(__a) ^ static_cast<int>(__b)); }

  inline _Ios_Openmode
  operator|=(_Ios_Openmode& __a, _Ios_Openmode __b)
  { return __a = __a | __b; }

  inline _Ios_Openmode
  operator&=(_Ios_Openmode& __a, _Ios_Openmode __b)
  { return __a = __a & __b; }

  inline _Ios_Openmode
  operator^=(_Ios_Openmode& __a, _Ios_Openmode __b)
  { return __a = __a ^ __b; }

  inline _Ios_Openmode
  operator~(_Ios_Openmode __a)
  { return _Ios_Openmode(~static_cast<int>(__a)); }


  enum _Ios_Iostate { _M_ios_iostate_end = 1L << 16 };

  inline _Ios_Iostate
  operator&(_Ios_Iostate __a, _Ios_Iostate __b)
  { return _Ios_Iostate(static_cast<int>(__a) & static_cast<int>(__b)); }

  inline _Ios_Iostate
  operator|(_Ios_Iostate __a, _Ios_Iostate __b)
  { return _Ios_Iostate(static_cast<int>(__a) | static_cast<int>(__b)); }

  inline _Ios_Iostate
  operator^(_Ios_Iostate __a, _Ios_Iostate __b)
  { return _Ios_Iostate(static_cast<int>(__a) ^ static_cast<int>(__b)); }

  inline _Ios_Iostate
  operator|=(_Ios_Iostate& __a, _Ios_Iostate __b)
  { return __a = __a | __b; }

  inline _Ios_Iostate
  operator&=(_Ios_Iostate& __a, _Ios_Iostate __b)
  { return __a = __a & __b; }

  inline _Ios_Iostate
  operator^=(_Ios_Iostate& __a, _Ios_Iostate __b)
  { return __a = __a ^ __b; }

  inline _Ios_Iostate
  operator~(_Ios_Iostate __a)
  { return _Ios_Iostate(~static_cast<int>(__a)); }

  enum _Ios_Seekdir { _M_ios_seekdir_end = 1L << 16 };


  class ios_base
  {
  public:


    class failure : public exception
    {
    public:


      explicit
      failure(const string& __str) throw();

      virtual
      ~failure() throw();

      virtual const char*
      what() const throw();

    private:
      enum { _M_bufsize = 256 };
      char _M_name[_M_bufsize];

    };


    typedef _Ios_Fmtflags fmtflags;

    static const fmtflags boolalpha = fmtflags(__ios_flags::_S_boolalpha);
    static const fmtflags dec = fmtflags(__ios_flags::_S_dec);
    static const fmtflags fixed = fmtflags(__ios_flags::_S_fixed);
    static const fmtflags hex = fmtflags(__ios_flags::_S_hex);
    static const fmtflags internal = fmtflags(__ios_flags::_S_internal);
    static const fmtflags left = fmtflags(__ios_flags::_S_left);
    static const fmtflags oct = fmtflags(__ios_flags::_S_oct);
    static const fmtflags right = fmtflags(__ios_flags::_S_right);
    static const fmtflags scientific = fmtflags(__ios_flags::_S_scientific);
    static const fmtflags showbase = fmtflags(__ios_flags::_S_showbase);
    static const fmtflags showpoint = fmtflags(__ios_flags::_S_showpoint);
    static const fmtflags showpos = fmtflags(__ios_flags::_S_showpos);
    static const fmtflags skipws = fmtflags(__ios_flags::_S_skipws);
    static const fmtflags unitbuf = fmtflags(__ios_flags::_S_unitbuf);
    static const fmtflags uppercase = fmtflags(__ios_flags::_S_uppercase);
    static const fmtflags adjustfield = fmtflags(__ios_flags::_S_adjustfield);
    static const fmtflags basefield = fmtflags(__ios_flags::_S_basefield);
    static const fmtflags floatfield = fmtflags(__ios_flags::_S_floatfield);


    typedef _Ios_Iostate iostate;
    static const iostate badbit = iostate(__ios_flags::_S_badbit);
    static const iostate eofbit = iostate(__ios_flags::_S_eofbit);
    static const iostate failbit = iostate(__ios_flags::_S_failbit);
    static const iostate goodbit = iostate(0);


    typedef _Ios_Openmode openmode;
    static const openmode app = openmode(__ios_flags::_S_app);
    static const openmode ate = openmode(__ios_flags::_S_ate);
    static const openmode binary = openmode(__ios_flags::_S_bin);
    static const openmode in = openmode(__ios_flags::_S_in);
    static const openmode out = openmode(__ios_flags::_S_out);
    static const openmode trunc = openmode(__ios_flags::_S_trunc);


    typedef _Ios_Seekdir seekdir;
    static const seekdir beg = seekdir(0);
    static const seekdir cur = seekdir(1);
    static const seekdir end = seekdir(2);
# 216 "/usr/local/include/g++-v3/bits/ios_base.h" 3
    enum event
    {
      erase_event,
      imbue_event,
      copyfmt_event
    };

    typedef void (*event_callback) (event, ios_base&, int);

    void
    register_callback(event_callback __fn, int __index);

  protected:

    streamsize _M_precision;
    streamsize _M_width;
    fmtflags _M_flags;



    struct _Callback_list
    {

      _Callback_list* _M_next;
      ios_base::event_callback _M_fn;
      int _M_index;
      int _M_refcount;

      _Callback_list(ios_base::event_callback __fn, int __index,
                     _Callback_list* __cb)
      : _M_next(__cb), _M_fn(__fn), _M_index(__index), _M_refcount(0) { }

      void
      _M_add_reference() { ++_M_refcount; }

      int
      _M_remove_reference() { return _M_refcount--; }
    };

     _Callback_list* _M_callbacks;

    void
    _M_call_callbacks(event __ev) throw();

    void
    _M_dispose_callbacks(void);


    struct _Words
    {
      void* _M_pword;
      long _M_iword;
    };

    static const int _S_local_words = 8;
    _Words _M_word_array[_S_local_words];
    _Words _M_dummy;
    _Words* _M_words;
    int _M_word_limit;

    _Words&
    _M_grow_words(int __index);


    locale _M_ios_locale;

    void
    _M_init();

  public:





    class Init
    {
      friend class ios_base;
    public:
      Init();
      ~Init();

      static void
      _S_ios_create(bool __sync);

      static void
      _S_ios_destroy();

    private:
      static int _S_ios_base_init;
      static bool _S_synced_with_stdio;
    };


    inline fmtflags
    flags() const { return _M_flags; }

    inline fmtflags
    flags(fmtflags __fmtfl)
    {
      fmtflags __old = _M_flags;
      _M_flags = __fmtfl;
      return __old;
    }

    inline fmtflags
    setf(fmtflags __fmtfl)
    {
      fmtflags __old = _M_flags;
      _M_flags |= __fmtfl;
      return __old;
    }

    inline fmtflags
    setf(fmtflags __fmtfl, fmtflags __mask)
    {
      fmtflags __old = _M_flags;
      _M_flags &= ~__mask;
      _M_flags |= (__fmtfl & __mask);
      return __old;
    }

    inline void
    unsetf(fmtflags __mask) { _M_flags &= ~__mask; }

    inline streamsize
    precision() const { return _M_precision; }

    inline streamsize
    precision(streamsize __prec)
    {
      streamsize __old = _M_precision;
      _M_precision = __prec;
      return __old;
    }

    inline streamsize
    width() const { return _M_width; }

    inline streamsize
    width(streamsize __wide)
    {
      streamsize __old = _M_width;
      _M_width = __wide;
      return __old;
    }

    static bool
    sync_with_stdio(bool __sync = true);


    locale
    imbue(const locale& __loc);

    inline locale
    getloc() const { return _M_ios_locale; }


    static int
    xalloc() throw();

    inline long&
    iword(int __ix)
    {
      _Words& __word = (__ix < _M_word_limit)
                        ? _M_words[__ix] : _M_grow_words(__ix);
      return __word._M_iword;
    }

    inline void*&
    pword(int __ix)
    {
      _Words& __word = (__ix < _M_word_limit)
                        ? _M_words[__ix] : _M_grow_words(__ix);
      return __word._M_pword;
    }


    ~ios_base();

  protected:
    ios_base();


  private:
    ios_base(const ios_base&);

    ios_base&
    operator=(const ios_base&);

  };


  inline ios_base&
  boolalpha(ios_base& __base)
  {
    __base.setf(ios_base::boolalpha);
    return __base;
  }

  inline ios_base&
  noboolalpha(ios_base& __base)
  {
    __base.unsetf(ios_base::boolalpha);
    return __base;
  }

  inline ios_base&
  showbase(ios_base& __base)
  {
    __base.setf(ios_base::showbase);
    return __base;
  }

  inline ios_base&
  noshowbase(ios_base& __base)
  {
    __base.unsetf(ios_base::showbase);
    return __base;
  }

  inline ios_base&
  showpoint(ios_base& __base)
  {
    __base.setf(ios_base::showpoint);
    return __base;
  }

  inline ios_base&
  noshowpoint(ios_base& __base)
  {
    __base.unsetf(ios_base::showpoint);
    return __base;
  }

  inline ios_base&
  showpos(ios_base& __base)
  {
    __base.setf(ios_base::showpos);
    return __base;
  }

  inline ios_base&
  noshowpos(ios_base& __base)
  {
    __base.unsetf(ios_base::showpos);
    return __base;
  }

  inline ios_base&
  skipws(ios_base& __base)
  {
    __base.setf(ios_base::skipws);
    return __base;
  }

  inline ios_base&
  noskipws(ios_base& __base)
  {
    __base.unsetf(ios_base::skipws);
    return __base;
  }

  inline ios_base&
  uppercase(ios_base& __base)
  {
    __base.setf(ios_base::uppercase);
    return __base;
  }

  inline ios_base&
  nouppercase(ios_base& __base)
  {
    __base.unsetf(ios_base::uppercase);
    return __base;
  }

  inline ios_base&
  unitbuf(ios_base& __base)
  {
     __base.setf(ios_base::unitbuf);
     return __base;
  }

  inline ios_base&
  nounitbuf(ios_base& __base)
  {
     __base.unsetf(ios_base::unitbuf);
     return __base;
  }


  inline ios_base&
  internal(ios_base& __base)
  {
     __base.setf(ios_base::internal, ios_base::adjustfield);
     return __base;
  }

  inline ios_base&
  left(ios_base& __base)
  {
    __base.setf(ios_base::left, ios_base::adjustfield);
    return __base;
  }

  inline ios_base&
  right(ios_base& __base)
  {
    __base.setf(ios_base::right, ios_base::adjustfield);
    return __base;
  }


  inline ios_base&
  dec(ios_base& __base)
  {
    __base.setf(ios_base::dec, ios_base::basefield);
    return __base;
  }

  inline ios_base&
  hex(ios_base& __base)
  {
    __base.setf(ios_base::hex, ios_base::basefield);
    return __base;
  }

  inline ios_base&
  oct(ios_base& __base)
  {
    __base.setf(ios_base::oct, ios_base::basefield);
    return __base;
  }


  inline ios_base&
  fixed(ios_base& __base)
  {
    __base.setf(ios_base::fixed, ios_base::floatfield);
    return __base;
  }

  inline ios_base&
  scientific(ios_base& __base)
  {
    __base.setf(ios_base::scientific, ios_base::floatfield);
    return __base;
  }

}
# 45 "/usr/local/include/g++-v3/bits/std_ios.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_streambuf.h" 1 3
# 38 "/usr/local/include/g++-v3/bits/std_streambuf.h" 3

# 1 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/c++config.h" 1 3
# 40 "/usr/local/include/g++-v3/bits/std_streambuf.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_iosfwd.h" 1 3
# 41 "/usr/local/include/g++-v3/bits/std_streambuf.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_cstdio.h" 1 3
# 42 "/usr/local/include/g++-v3/bits/std_streambuf.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/localefwd.h" 1 3
# 43 "/usr/local/include/g++-v3/bits/std_streambuf.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/ios_base.h" 1 3
# 44 "/usr/local/include/g++-v3/bits/std_streambuf.h" 2 3

namespace std
{
  template<typename _CharT, typename _Traits>
    streamsize
    __copy_streambufs(basic_ios<_CharT, _Traits>& _ios,
                      basic_streambuf<_CharT, _Traits>* __sbin,
                      basic_streambuf<_CharT, _Traits>* __sbout);


  template<typename _CharT, typename _Traits>
    class basic_streambuf
    {
    public:

      typedef _CharT char_type;
      typedef _Traits traits_type;
      typedef typename traits_type::int_type int_type;
      typedef typename traits_type::pos_type pos_type;
      typedef typename traits_type::off_type off_type;


      typedef ctype<char_type> __ctype_type;
      typedef basic_streambuf<char_type, traits_type> __streambuf_type;

      friend class basic_ios<char_type, traits_type>;
      friend class basic_istream<char_type, traits_type>;
      friend class basic_ostream<char_type, traits_type>;
      friend class istreambuf_iterator<char_type, traits_type>;
      friend class ostreambuf_iterator<char_type, traits_type>;

      friend streamsize
      __copy_streambufs<>(basic_ios<char_type, traits_type>& __ios,
                          __streambuf_type* __sbin,__streambuf_type* __sbout);

    protected:






      char_type* _M_buf;


      int_type _M_buf_size;


      int_type _M_buf_size_opt;



      bool _M_buf_unified;






      char_type* _M_in_beg;
      char_type* _M_in_cur;
      char_type* _M_in_end;
      char_type* _M_out_beg;
      char_type* _M_out_cur;
      char_type* _M_out_end;


      ios_base::openmode _M_mode;


      locale _M_buf_locale;


      bool _M_buf_locale_init;






      int_type _M_pback_size;
      char_type* _M_pback;
      char_type* _M_pback_cur_save;
      char_type* _M_pback_end_save;
      bool _M_pback_init;




      void
      _M_pback_create()
      {
        if (!_M_pback_init)
          {
            int_type __dist = _M_in_end - _M_in_cur;
            int_type __len = min(_M_pback_size, __dist);
            traits_type::copy(_M_pback, _M_in_cur, __len);
            _M_pback_cur_save = _M_in_cur;
            _M_pback_end_save = _M_in_end;
            this->setg(_M_pback, _M_pback, _M_pback + __len);
            _M_pback_init = true;
          }
      }




      void
      _M_pback_destroy()
      {
        if (_M_pback_init)
          {

            int_type __off_cur = _M_in_cur - _M_pback;


            int_type __off_end = 0;
            int_type __pback_len = _M_in_end - _M_pback;
            int_type __save_len = _M_pback_end_save - _M_buf;
            if (__pback_len > __save_len)
              __off_end = __pback_len - __save_len;

            this->setg(_M_buf, _M_pback_cur_save + __off_cur,
                       _M_pback_end_save + __off_end);
            _M_pback_cur_save = __null;
            _M_pback_end_save = __null;
            _M_pback_init = false;
          }
      }



      void
      _M_in_cur_move(off_type __n)
      {
        bool __testout = _M_out_cur;
        _M_in_cur += __n;
        if (__testout && _M_buf_unified)
          _M_out_cur += __n;
      }
# 193 "/usr/local/include/g++-v3/bits/std_streambuf.h" 3
      void
      _M_out_cur_move(off_type __n)
      {
        bool __testin = _M_in_cur;

        _M_out_cur += __n;
        if (__testin && _M_buf_unified)
          _M_in_cur += __n;
        if (_M_out_cur > _M_out_end)
          {
            _M_out_end = _M_out_cur;

            if (__testin)
              _M_in_end += __n;
          }
      }




      off_type
      _M_out_buf_size()
      {
        off_type __ret = 0;
        if (_M_out_cur)
          {

            if (_M_out_beg == _M_buf)
              __ret = _M_out_beg + _M_buf_size - _M_out_cur;

            else
              __ret = _M_out_end - _M_out_cur;
          }
        return __ret;
      }
# 236 "/usr/local/include/g++-v3/bits/std_streambuf.h" 3
      void
      _M_set_indeterminate(void)
      {
        if (_M_mode & ios_base::in)
          this->setg(_M_buf, _M_buf, _M_buf);
        if (_M_mode & ios_base::out)
          this->setp(_M_buf, _M_buf);
      }

      void
      _M_set_determinate(off_type __off)
      {
        bool __testin = _M_mode & ios_base::in;
        bool __testout = _M_mode & ios_base::out;
        if (__testin)
          this->setg(_M_buf, _M_buf, _M_buf + __off);
        if (__testout)
          this->setp(_M_buf, _M_buf + __off);
      }

      bool
      _M_is_indeterminate(void)
      {
        bool __ret = false;

        if (_M_buf)
          {
            if (_M_mode & ios_base::in)
              __ret = _M_in_beg == _M_in_cur && _M_in_cur == _M_in_end;
            if (_M_mode & ios_base::out)
              __ret = _M_out_beg == _M_out_cur && _M_out_cur == _M_out_end;
          }
        return __ret;
      }

  public:
      virtual
      ~basic_streambuf()
      {
        _M_buf_unified = false;
        _M_buf_size = 0;
        _M_buf_size_opt = 0;
        _M_mode = ios_base::openmode(0);
        _M_buf_locale_init = false;
      }


      locale
      pubimbue(const locale &__loc)
      {
        locale __tmp(this->getloc());
        this->imbue(__loc);
        return __tmp;
      }

      locale
      getloc() const
      {
        if (_M_buf_locale_init)
          return _M_buf_locale;
        else
          return locale();
      }


      __streambuf_type*
      pubsetbuf(char_type* __s, streamsize __n)
      { return this->setbuf(__s, __n); }

      pos_type
      pubseekoff(off_type __off, ios_base::seekdir __way,
                 ios_base::openmode __mode = ios_base::in | ios_base::out)
      { return this->seekoff(__off, __way, __mode); }

      pos_type
      pubseekpos(pos_type __sp,
                 ios_base::openmode __mode = ios_base::in | ios_base::out)
      { return this->seekpos(__sp, __mode); }

      int
      pubsync() { return this->sync(); }



      streamsize
      in_avail()
      {
        streamsize __ret;
        if (_M_in_cur && _M_in_cur < _M_in_end)
          {
            if (_M_pback_init)
              {
                int_type __save_len = _M_pback_end_save - _M_pback_cur_save;
                int_type __pback_len = _M_in_cur - _M_pback;
                __ret = __save_len - __pback_len;
              }
            else
              __ret = this->egptr() - this->gptr();
          }
        else
          __ret = this->showmanyc();
        return __ret;
      }

      int_type
      snextc()
      {
        int_type __eof = traits_type::eof();
        return (this->sbumpc() == __eof ? __eof : this->sgetc());
      }

      int_type
      sbumpc();

      int_type
      sgetc()
      {
        int_type __ret;
        if (_M_in_cur && _M_in_cur < _M_in_end)
          __ret = traits_type::to_int_type(*(this->gptr()));
        else
          __ret = this->underflow();
        return __ret;
      }

      streamsize
      sgetn(char_type* __s, streamsize __n)
      { return this->xsgetn(__s, __n); }


      int_type
      sputbackc(char_type __c);

      int_type
      sungetc();


      int_type
      sputc(char_type __c);

      streamsize
      sputn(const char_type* __s, streamsize __n)
      { return this->xsputn(__s, __n); }

    protected:
      basic_streambuf()
      : _M_buf(__null), _M_buf_size(0),
      _M_buf_size_opt(static_cast<int_type>(8192)), _M_buf_unified(false),
      _M_in_beg(0), _M_in_cur(0), _M_in_end(0), _M_out_beg(0), _M_out_cur(0),
      _M_out_end(0), _M_mode(ios_base::openmode(0)), _M_buf_locale(locale()),
      _M_buf_locale_init(false), _M_pback_size(1), _M_pback(__null),
      _M_pback_cur_save(__null), _M_pback_end_save(__null), _M_pback_init(false)
      { }


      char_type*
      eback() const { return _M_in_beg; }

      char_type*
      gptr() const { return _M_in_cur; }

      char_type*
      egptr() const { return _M_in_end; }

      void
      gbump(int __n) { _M_in_cur += __n; }

      void
      setg(char_type* __gbeg, char_type* __gnext, char_type* __gend)
      {
        _M_in_beg = __gbeg;
        _M_in_cur = __gnext;
        _M_in_end = __gend;
        if (!(_M_mode & ios_base::in) && __gbeg && __gnext && __gend)
          _M_mode = _M_mode | ios_base::in;
      }


      char_type*
      pbase() const { return _M_out_beg; }

      char_type*
      pptr() const { return _M_out_cur; }

      char_type*
      epptr() const { return _M_out_end; }

      void
      pbump(int __n) { _M_out_cur += __n; }

      void
      setp(char_type* __pbeg, char_type* __pend)
      {
        _M_out_beg = _M_out_cur = __pbeg;
        _M_out_end = __pend;
        if (!(_M_mode & ios_base::out) && __pbeg && __pend)
          _M_mode = _M_mode | ios_base::out;
      }



      virtual void
      imbue(const locale& __loc)
      {
        _M_buf_locale_init = true;
        if (_M_buf_locale != __loc)
          _M_buf_locale = __loc;
      }


      virtual basic_streambuf<char_type,_Traits>*
      setbuf(char_type*, streamsize)
      { return this; }

      virtual pos_type
      seekoff(off_type, ios_base::seekdir,
              ios_base::openmode = ios_base::in | ios_base::out)
      { return pos_type(off_type(-1)); }

      virtual pos_type
      seekpos(pos_type,
              ios_base::openmode = ios_base::in | ios_base::out)
      { return pos_type(off_type(-1)); }

      virtual int
      sync() { return 0; }


      virtual streamsize
      showmanyc() { return 0; }

      virtual streamsize
      xsgetn(char_type* __s, streamsize __n);

      virtual int_type
      underflow()
      { return traits_type::eof(); }

      virtual int_type
      uflow()
      {
        int_type __ret = traits_type::eof();
        bool __testeof = this->underflow() == __ret;
        bool __testpending = _M_in_cur && _M_in_cur < _M_in_end;
        if (!__testeof && __testpending)
          {
            __ret = traits_type::to_int_type(*_M_in_cur);
            ++_M_in_cur;
            if (_M_buf_unified && _M_mode & ios_base::out)
              ++_M_out_cur;
          }
        return __ret;
      }


      virtual int_type
      pbackfail(int_type = traits_type::eof())
      { return traits_type::eof(); }


      virtual streamsize
      xsputn(const char_type* __s, streamsize __n);

      virtual int_type
      overflow(int_type = traits_type::eof())
      { return traits_type::eof(); }
# 516 "/usr/local/include/g++-v3/bits/std_streambuf.h" 3
    private:
      basic_streambuf(const __streambuf_type&);

      __streambuf_type&
      operator=(const __streambuf_type&);

    };

}




# 1 "/usr/local/include/g++-v3/bits/streambuf.tcc" 1 3
# 37 "/usr/local/include/g++-v3/bits/streambuf.tcc" 3
namespace std {

  template<typename _CharT, typename _Traits>
    typename basic_streambuf<_CharT, _Traits>::int_type
    basic_streambuf<_CharT, _Traits>::
    sbumpc()
    {
      int_type __ret;
      if (_M_in_cur && _M_in_cur < _M_in_end)
        {
          char_type __c = *gptr();
          _M_in_cur_move(1);
          __ret = traits_type::to_int_type(__c);
        }
      else
        __ret = this->uflow();
      return __ret;
    }

  template<typename _CharT, typename _Traits>
    typename basic_streambuf<_CharT, _Traits>::int_type
    basic_streambuf<_CharT, _Traits>::
    sputbackc(char_type __c)
    {
      int_type __ret;
      bool __testpos = _M_in_cur && _M_in_beg < _M_in_cur;
      bool __testne = _M_in_cur && !traits_type::eq(__c, this->gptr()[-1]);
      if (!__testpos || __testne)
        __ret = pbackfail(traits_type::to_int_type(__c));
      else
        {
          _M_in_cur_move(-1);
          __ret = traits_type::to_int_type(*this->gptr());
        }
      return __ret;
    }

  template<typename _CharT, typename _Traits>
    typename basic_streambuf<_CharT, _Traits>::int_type
    basic_streambuf<_CharT, _Traits>::
    sungetc()
    {
      int_type __ret;
      if (_M_in_cur && _M_in_beg < _M_in_cur)
        {
          _M_in_cur_move(-1);
          __ret = traits_type::to_int_type(*_M_in_cur);
        }
      else
        __ret = this->pbackfail();
      return __ret;
    }






  template<typename _CharT, typename _Traits>
    typename basic_streambuf<_CharT, _Traits>::int_type
    basic_streambuf<_CharT, _Traits>::
    sputc(char_type __c)
    {
      int_type __ret;
      if (_M_out_buf_size())
        {
          *_M_out_cur = __c;
          _M_out_cur_move(1);
          __ret = traits_type::to_int_type(__c);
        }
      else
        __ret = this->overflow(traits_type::to_int_type(__c));
      return __ret;
    }

  template<typename _CharT, typename _Traits>
    streamsize
    basic_streambuf<_CharT, _Traits>::
    xsgetn(char_type* __s, streamsize __n)
    {
      streamsize __ret = 0;
      while (__ret < __n)
        {
          size_t __buf_len = _M_in_end - _M_in_cur;
          if (__buf_len > 0)
            {
              size_t __remaining = __n - __ret;
              size_t __len = min(__buf_len, __remaining);
              traits_type::copy(__s, _M_in_cur, __len);
              __ret += __len;
              __s += __len;
              _M_in_cur_move(__len);
            }

          if (__ret < __n)
            {
              int_type __c = this->uflow();
              if (__c != traits_type::eof())
                {
                  traits_type::assign(*__s++, traits_type::to_char_type(__c));
                  ++__ret;
                }
              else
                break;
            }
        }
      return __ret;
    }






  template<typename _CharT, typename _Traits>
    streamsize
    basic_streambuf<_CharT, _Traits>::
    xsputn(const char_type* __s, streamsize __n)
    {
      streamsize __ret = 0;
      while (__ret < __n)
        {
          off_type __buf_len = _M_out_buf_size();
          if (__buf_len > 0)
            {
              off_type __remaining = __n - __ret;
              off_type __len = min(__buf_len, __remaining);
              traits_type::copy(_M_out_cur, __s, __len);
              __ret += __len;
              __s += __len;
              _M_out_cur_move(__len);
            }

          if (__ret < __n)
            {
              int_type __c = this->overflow(traits_type::to_int_type(*__s));
              if (__c != traits_type::eof())
                {
                  ++__ret;
                  ++__s;
                }
              else
                break;
            }
        }
      return __ret;
    }





  template<typename _CharT, typename _Traits>
    streamsize
    __copy_streambufs(basic_ios<_CharT, _Traits>& __ios,
                      basic_streambuf<_CharT, _Traits>* __sbin,
                      basic_streambuf<_CharT, _Traits>* __sbout)
  {
      typedef typename _Traits::int_type int_type;

      streamsize __ret = 0;
      streamsize __bufsize = __sbin->in_avail();
      streamsize __xtrct;
      bool __testput = __sbout->_M_mode & ios_base::out;
      try {
        while (__testput && __bufsize != -1)
          {
            __xtrct = __sbout->sputn(__sbin->gptr(), __bufsize);
            __ret += __xtrct;
            __sbin->_M_in_cur_move(__xtrct);
            if (__xtrct == __bufsize)
              {
                int_type __c = __sbin->sgetc();
                if (__c == _Traits::eof())
                  {
                    __ios.setstate(ios_base::eofbit);
                    break;
                  }
                __bufsize = __sbin->in_avail();
              }
            else
              break;
          }
      }
      catch(exception& __fail) {
        if ((__ios.exceptions() & ios_base::failbit) != 0)
          throw;
      }
      return __ret;
    }
}
# 530 "/usr/local/include/g++-v3/bits/std_streambuf.h" 2 3
# 46 "/usr/local/include/g++-v3/bits/std_ios.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/basic_ios.h" 1 3
# 34 "/usr/local/include/g++-v3/bits/basic_ios.h" 3

# 1 "/usr/local/include/g++-v3/bits/sbuf_iter.h" 1 3
# 36 "/usr/local/include/g++-v3/bits/sbuf_iter.h" 3

namespace std
{
  template<typename _CharT, typename _Traits>
    class ostreambuf_iterator
    : public iterator<output_iterator_tag, void, void, void, void>
    {
    public:

      typedef _CharT char_type;
      typedef _Traits traits_type;
      typedef basic_streambuf<_CharT, _Traits> streambuf_type;
      typedef basic_ostream<_CharT, _Traits> ostream_type;

    private:
      streambuf_type* _M_sbuf;
      bool _M_failed;

    public:
      inline
      ostreambuf_iterator(ostream_type& __s) throw ()
      : _M_sbuf(__s.rdbuf()), _M_failed(!_M_sbuf) { }

      ostreambuf_iterator(streambuf_type* __s) throw ()
      : _M_sbuf(__s), _M_failed(!_M_sbuf) { }

      ostreambuf_iterator&
      operator=(_CharT __c);

      ostreambuf_iterator&
      operator*() throw()
      { return *this; }

      ostreambuf_iterator&
      operator++(int) throw()
      { return *this; }

      ostreambuf_iterator&
      operator++() throw()
      { return *this; }

      bool
      failed() const throw()
      { return _M_failed; }
    };

  template<typename _CharT, typename _Traits>
    inline ostreambuf_iterator<_CharT, _Traits>&
    ostreambuf_iterator<_CharT, _Traits>::operator=(_CharT __c)
    {
      if (!_M_failed &&
          _Traits::eq_int_type(_M_sbuf->sputc(__c),_Traits::eof()))
      _M_failed = true;
      return *this;
    }



  template<typename _CharT, typename _Traits>
    class istreambuf_iterator
    : public iterator<input_iterator_tag, _CharT, typename _Traits::off_type,
                      _CharT*, _CharT&>
    {
    public:

      typedef _CharT char_type;
      typedef _Traits traits_type;
      typedef typename _Traits::int_type int_type;
      typedef basic_streambuf<_CharT, _Traits> streambuf_type;
      typedef basic_istream<_CharT, _Traits> istream_type;

      typedef istreambuf_iterator<_CharT, _Traits> __istreambufiter_type;

    private:







      streambuf_type* _M_sbuf;
      int_type _M_c;

    public:
      istreambuf_iterator() throw()
      : _M_sbuf(__null), _M_c(-2) { }

      istreambuf_iterator(istream_type& __s) throw()
      : _M_sbuf(__s.rdbuf()), _M_c(-2) { }

      istreambuf_iterator(streambuf_type* __s) throw()
      : _M_sbuf(__s), _M_c(-2) { }




      char_type
      operator*() const
      {

        char_type __ret;
        if (_M_sbuf && _M_c != static_cast<int_type>(-2))
          __ret = _M_c;
        else if (_M_sbuf)
          __ret = traits_type::to_char_type(_M_sbuf->sgetc());
        else
          __ret = static_cast<char_type>(traits_type::eof());
        return __ret;
      }

      __istreambufiter_type&
      operator++()
      {
        if (_M_sbuf)
          _M_sbuf->sbumpc();
        _M_c = -2;
        return *this;
      }

      __istreambufiter_type
      operator++(int)
      {
        __istreambufiter_type __old = *this;
        if (_M_sbuf)
          __old._M_c = _M_sbuf->sbumpc();
        _M_c = -2;
        return __old;
      }

      bool
      equal(const __istreambufiter_type& __b)
      {
        int_type __eof = traits_type::eof();
        bool __thiseof = !_M_sbuf || _M_sbuf->sgetc() == __eof;
        bool __beof = !__b._M_sbuf
                      || __b._M_sbuf->sgetc() == __eof;
        return (__thiseof && __beof || (!__thiseof && !__beof));
      }




      bool
      equal(const __istreambufiter_type& __b) const
      {
        int_type __eof = traits_type::eof();
        bool __thiseof = !_M_sbuf || _M_sbuf->sgetc() == __eof;
        bool __beof = !__b._M_sbuf
                      || __b._M_sbuf->sgetc() == __eof;
        return (__thiseof && __beof || (!__thiseof && !__beof));
      }

    };

  template<typename _CharT, typename _Traits>
    inline bool
    operator==(const istreambuf_iterator<_CharT, _Traits>& __a,
               const istreambuf_iterator<_CharT, _Traits>& __b)
    { return __a.equal(__b); }

  template<typename _CharT, typename _Traits>
    inline bool
    operator!=(const istreambuf_iterator<_CharT, _Traits>& __a,
               const istreambuf_iterator<_CharT, _Traits>& __b)
    { return !__a.equal(__b); }
}
# 36 "/usr/local/include/g++-v3/bits/basic_ios.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/locale_facets.h" 1 3
# 40 "/usr/local/include/g++-v3/bits/locale_facets.h" 3

# 1 "/usr/local/include/g++-v3/bits/std_ctime.h" 1 3
# 42 "/usr/local/include/g++-v3/bits/locale_facets.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_ios.h" 1 3
# 43 "/usr/local/include/g++-v3/bits/locale_facets.h" 2 3

# 1 "/usr/include/langinfo.h" 1 3
# 24 "/usr/include/langinfo.h" 3
# 1 "/usr/include/nl_types.h" 1 3
# 22 "/usr/include/nl_types.h" 3
# 1 "/usr/include/features.h" 1 3
# 23 "/usr/include/nl_types.h" 2 3
# 31 "/usr/include/nl_types.h" 3
extern "C" {


typedef void *nl_catd;


typedef int nl_item;


extern nl_catd catopen (__const char *__cat_name, int __flag) throw ();



extern char *catgets (nl_catd __catalog, int __set, int __number,
                      __const char *__string) throw ();


extern int catclose (nl_catd __catalog) throw ();

}
# 25 "/usr/include/langinfo.h" 2 3

# 1 "/usr/include/bits/locale.h" 1 3
# 27 "/usr/include/bits/locale.h" 3
enum
{
  __LC_CTYPE = 0,
  __LC_NUMERIC = 1,
  __LC_TIME = 2,
  __LC_COLLATE = 3,
  __LC_MONETARY = 4,
  __LC_MESSAGES = 5,
  __LC_ALL = 6,
  __LC_PAPER = 7,
  __LC_NAME = 8,
  __LC_ADDRESS = 9,
  __LC_TELEPHONE = 10,
  __LC_MEASUREMENT = 11,
  __LC_IDENTIFICATION = 12
};
# 27 "/usr/include/langinfo.h" 2 3


extern "C" {
# 43 "/usr/include/langinfo.h" 3
enum
{



  ABDAY_1 = (((__LC_TIME) << 16) | (0)),

  ABDAY_2,

  ABDAY_3,

  ABDAY_4,

  ABDAY_5,

  ABDAY_6,

  ABDAY_7,



  DAY_1,

  DAY_2,

  DAY_3,

  DAY_4,

  DAY_5,

  DAY_6,

  DAY_7,



  ABMON_1,

  ABMON_2,

  ABMON_3,

  ABMON_4,

  ABMON_5,

  ABMON_6,

  ABMON_7,

  ABMON_8,

  ABMON_9,

  ABMON_10,

  ABMON_11,

  ABMON_12,



  MON_1,

  MON_2,

  MON_3,

  MON_4,

  MON_5,

  MON_6,

  MON_7,

  MON_8,

  MON_9,

  MON_10,

  MON_11,

  MON_12,


  AM_STR,

  PM_STR,


  D_T_FMT,

  D_FMT,

  T_FMT,

  T_FMT_AMPM,


  ERA,

  __ERA_YEAR,



  ERA_D_FMT,

  ALT_DIGITS,

  ERA_D_T_FMT,

  ERA_T_FMT,


  _NL_TIME_ERA_NUM_ENTRIES,
  _NL_TIME_ERA_ENTRIES,

  _NL_WABDAY_1,
  _NL_WABDAY_2,
  _NL_WABDAY_3,
  _NL_WABDAY_4,
  _NL_WABDAY_5,
  _NL_WABDAY_6,
  _NL_WABDAY_7,


  _NL_WDAY_1,
  _NL_WDAY_2,
  _NL_WDAY_3,
  _NL_WDAY_4,
  _NL_WDAY_5,
  _NL_WDAY_6,
  _NL_WDAY_7,


  _NL_WABMON_1,
  _NL_WABMON_2,
  _NL_WABMON_3,
  _NL_WABMON_4,
  _NL_WABMON_5,
  _NL_WABMON_6,
  _NL_WABMON_7,
  _NL_WABMON_8,
  _NL_WABMON_9,
  _NL_WABMON_10,
  _NL_WABMON_11,
  _NL_WABMON_12,


  _NL_WMON_1,
  _NL_WMON_2,
  _NL_WMON_3,
  _NL_WMON_4,
  _NL_WMON_5,
  _NL_WMON_6,
  _NL_WMON_7,
  _NL_WMON_8,
  _NL_WMON_9,
  _NL_WMON_10,
  _NL_WMON_11,
  _NL_WMON_12,

  _NL_WAM_STR,
  _NL_WPM_STR,

  _NL_WD_T_FMT,
  _NL_WD_FMT,
  _NL_WT_FMT,
  _NL_WT_FMT_AMPM,

  _NL_WERA_YEAR,
  _NL_WERA_D_FMT,
  _NL_WALT_DIGITS,
  _NL_WERA_D_T_FMT,
  _NL_WERA_T_FMT,

  _NL_TIME_WEEK_NDAYS,
  _NL_TIME_WEEK_1STDAY,
  _NL_TIME_WEEK_1STWEEK,
  _NL_TIME_FIRST_WEEKDAY,
  _NL_TIME_FIRST_WORKDAY,
  _NL_TIME_CAL_DIRECTION,
  _NL_TIME_TIMEZONE,

  _DATE_FMT,

  _NL_W_DATE_FMT,

  _NL_TIME_CODESET,

  _NL_NUM_LC_TIME,




  _NL_COLLATE_NRULES = (((__LC_COLLATE) << 16) | (0)),
  _NL_COLLATE_RULESETS,
  _NL_COLLATE_TABLEMB,
  _NL_COLLATE_WEIGHTMB,
  _NL_COLLATE_EXTRAMB,
  _NL_COLLATE_INDIRECTMB,
  _NL_COLLATE_GAP1,
  _NL_COLLATE_GAP2,
  _NL_COLLATE_GAP3,
  _NL_COLLATE_TABLEWC,
  _NL_COLLATE_WEIGHTWC,
  _NL_COLLATE_EXTRAWC,
  _NL_COLLATE_INDIRECTWC,
  _NL_COLLATE_SYMB_HASH_SIZEMB,
  _NL_COLLATE_SYMB_TABLEMB,
  _NL_COLLATE_SYMB_EXTRAMB,
  _NL_COLLATE_COLLSEQMB,
  _NL_COLLATE_COLLSEQWC,
  _NL_COLLATE_CODESET,
  _NL_NUM_LC_COLLATE,




  _NL_CTYPE_CLASS = (((__LC_CTYPE) << 16) | (0)),
  _NL_CTYPE_TOUPPER,
  _NL_CTYPE_GAP1,
  _NL_CTYPE_TOLOWER,
  _NL_CTYPE_GAP2,
  _NL_CTYPE_CLASS32,
  _NL_CTYPE_GAP3,
  _NL_CTYPE_GAP4,
  _NL_CTYPE_GAP5,
  _NL_CTYPE_GAP6,
  _NL_CTYPE_CLASS_NAMES,
  _NL_CTYPE_MAP_NAMES,
  _NL_CTYPE_WIDTH,
  _NL_CTYPE_MB_CUR_MAX,
  _NL_CTYPE_CODESET_NAME,
  CODESET = _NL_CTYPE_CODESET_NAME,

  _NL_CTYPE_TOUPPER32,
  _NL_CTYPE_TOLOWER32,
  _NL_CTYPE_CLASS_OFFSET,
  _NL_CTYPE_MAP_OFFSET,
  _NL_CTYPE_INDIGITS_MB_LEN,
  _NL_CTYPE_INDIGITS0_MB,
  _NL_CTYPE_INDIGITS1_MB,
  _NL_CTYPE_INDIGITS2_MB,
  _NL_CTYPE_INDIGITS3_MB,
  _NL_CTYPE_INDIGITS4_MB,
  _NL_CTYPE_INDIGITS5_MB,
  _NL_CTYPE_INDIGITS6_MB,
  _NL_CTYPE_INDIGITS7_MB,
  _NL_CTYPE_INDIGITS8_MB,
  _NL_CTYPE_INDIGITS9_MB,
  _NL_CTYPE_INDIGITS_WC_LEN,
  _NL_CTYPE_INDIGITS0_WC,
  _NL_CTYPE_INDIGITS1_WC,
  _NL_CTYPE_INDIGITS2_WC,
  _NL_CTYPE_INDIGITS3_WC,
  _NL_CTYPE_INDIGITS4_WC,
  _NL_CTYPE_INDIGITS5_WC,
  _NL_CTYPE_INDIGITS6_WC,
  _NL_CTYPE_INDIGITS7_WC,
  _NL_CTYPE_INDIGITS8_WC,
  _NL_CTYPE_INDIGITS9_WC,
  _NL_CTYPE_OUTDIGIT0_MB,
  _NL_CTYPE_OUTDIGIT1_MB,
  _NL_CTYPE_OUTDIGIT2_MB,
  _NL_CTYPE_OUTDIGIT3_MB,
  _NL_CTYPE_OUTDIGIT4_MB,
  _NL_CTYPE_OUTDIGIT5_MB,
  _NL_CTYPE_OUTDIGIT6_MB,
  _NL_CTYPE_OUTDIGIT7_MB,
  _NL_CTYPE_OUTDIGIT8_MB,
  _NL_CTYPE_OUTDIGIT9_MB,
  _NL_CTYPE_OUTDIGIT0_WC,
  _NL_CTYPE_OUTDIGIT1_WC,
  _NL_CTYPE_OUTDIGIT2_WC,
  _NL_CTYPE_OUTDIGIT3_WC,
  _NL_CTYPE_OUTDIGIT4_WC,
  _NL_CTYPE_OUTDIGIT5_WC,
  _NL_CTYPE_OUTDIGIT6_WC,
  _NL_CTYPE_OUTDIGIT7_WC,
  _NL_CTYPE_OUTDIGIT8_WC,
  _NL_CTYPE_OUTDIGIT9_WC,
  _NL_CTYPE_TRANSLIT_TAB_SIZE,
  _NL_CTYPE_TRANSLIT_FROM_IDX,
  _NL_CTYPE_TRANSLIT_FROM_TBL,
  _NL_CTYPE_TRANSLIT_TO_IDX,
  _NL_CTYPE_TRANSLIT_TO_TBL,
  _NL_CTYPE_TRANSLIT_DEFAULT_MISSING_LEN,
  _NL_CTYPE_TRANSLIT_DEFAULT_MISSING,
  _NL_CTYPE_TRANSLIT_IGNORE_LEN,
  _NL_CTYPE_TRANSLIT_IGNORE,
  _NL_CTYPE_EXTRA_MAP_1,
  _NL_CTYPE_EXTRA_MAP_2,
  _NL_CTYPE_EXTRA_MAP_3,
  _NL_CTYPE_EXTRA_MAP_4,
  _NL_CTYPE_EXTRA_MAP_5,
  _NL_CTYPE_EXTRA_MAP_6,
  _NL_CTYPE_EXTRA_MAP_7,
  _NL_CTYPE_EXTRA_MAP_8,
  _NL_CTYPE_EXTRA_MAP_9,
  _NL_CTYPE_EXTRA_MAP_10,
  _NL_CTYPE_EXTRA_MAP_11,
  _NL_CTYPE_EXTRA_MAP_12,
  _NL_CTYPE_EXTRA_MAP_13,
  _NL_CTYPE_EXTRA_MAP_14,
  _NL_NUM_LC_CTYPE,




  __INT_CURR_SYMBOL = (((__LC_MONETARY) << 16) | (0)),



  __CURRENCY_SYMBOL,



  __MON_DECIMAL_POINT,



  __MON_THOUSANDS_SEP,



  __MON_GROUPING,



  __POSITIVE_SIGN,



  __NEGATIVE_SIGN,



  __INT_FRAC_DIGITS,



  __FRAC_DIGITS,



  __P_CS_PRECEDES,



  __P_SEP_BY_SPACE,



  __N_CS_PRECEDES,



  __N_SEP_BY_SPACE,



  __P_SIGN_POSN,



  __N_SIGN_POSN,



  _NL_MONETARY_CRNCYSTR,

  __INT_P_CS_PRECEDES,



  __INT_P_SEP_BY_SPACE,



  __INT_N_CS_PRECEDES,



  __INT_N_SEP_BY_SPACE,



  __INT_P_SIGN_POSN,



  __INT_N_SIGN_POSN,



  _NL_MONETARY_DUO_INT_CURR_SYMBOL,
  _NL_MONETARY_DUO_CURRENCY_SYMBOL,
  _NL_MONETARY_DUO_INT_FRAC_DIGITS,
  _NL_MONETARY_DUO_FRAC_DIGITS,
  _NL_MONETARY_DUO_P_CS_PRECEDES,
  _NL_MONETARY_DUO_P_SEP_BY_SPACE,
  _NL_MONETARY_DUO_N_CS_PRECEDES,
  _NL_MONETARY_DUO_N_SEP_BY_SPACE,
  _NL_MONETARY_DUO_INT_P_CS_PRECEDES,
  _NL_MONETARY_DUO_INT_P_SEP_BY_SPACE,
  _NL_MONETARY_DUO_INT_N_CS_PRECEDES,
  _NL_MONETARY_DUO_INT_N_SEP_BY_SPACE,
  _NL_MONETARY_DUO_P_SIGN_POSN,
  _NL_MONETARY_DUO_N_SIGN_POSN,
  _NL_MONETARY_DUO_INT_P_SIGN_POSN,
  _NL_MONETARY_DUO_INT_N_SIGN_POSN,
  _NL_MONETARY_UNO_VALID_FROM,
  _NL_MONETARY_UNO_VALID_TO,
  _NL_MONETARY_DUO_VALID_FROM,
  _NL_MONETARY_DUO_VALID_TO,
  _NL_MONETARY_CONVERSION_RATE,
  _NL_MONETARY_DECIMAL_POINT_WC,
  _NL_MONETARY_THOUSANDS_SEP_WC,
  _NL_MONETARY_CODESET,
  _NL_NUM_LC_MONETARY,



  __DECIMAL_POINT = (((__LC_NUMERIC) << 16) | (0)),



  RADIXCHAR = __DECIMAL_POINT,

  __THOUSANDS_SEP,



  THOUSEP = __THOUSANDS_SEP,

  __GROUPING,



  _NL_NUMERIC_DECIMAL_POINT_WC,
  _NL_NUMERIC_THOUSANDS_SEP_WC,
  _NL_NUMERIC_CODESET,
  _NL_NUM_LC_NUMERIC,

  __YESEXPR = (((__LC_MESSAGES) << 16) | (0)),

  __NOEXPR,

  __YESSTR,



  __NOSTR,



  _NL_MESSAGES_CODESET,
  _NL_NUM_LC_MESSAGES,

  _NL_PAPER_HEIGHT = (((__LC_PAPER) << 16) | (0)),
  _NL_PAPER_WIDTH,
  _NL_PAPER_CODESET,
  _NL_NUM_LC_PAPER,

  _NL_NAME_NAME_FMT = (((__LC_NAME) << 16) | (0)),
  _NL_NAME_NAME_GEN,
  _NL_NAME_NAME_MR,
  _NL_NAME_NAME_MRS,
  _NL_NAME_NAME_MISS,
  _NL_NAME_NAME_MS,
  _NL_NAME_CODESET,
  _NL_NUM_LC_NAME,

  _NL_ADDRESS_POSTAL_FMT = (((__LC_ADDRESS) << 16) | (0)),
  _NL_ADDRESS_COUNTRY_NAME,
  _NL_ADDRESS_COUNTRY_POST,
  _NL_ADDRESS_COUNTRY_AB2,
  _NL_ADDRESS_COUNTRY_AB3,
  _NL_ADDRESS_COUNTRY_CAR,
  _NL_ADDRESS_COUNTRY_NUM,
  _NL_ADDRESS_COUNTRY_ISBN,
  _NL_ADDRESS_LANG_NAME,
  _NL_ADDRESS_LANG_AB,
  _NL_ADDRESS_LANG_TERM,
  _NL_ADDRESS_LANG_LIB,
  _NL_ADDRESS_CODESET,
  _NL_NUM_LC_ADDRESS,

  _NL_TELEPHONE_TEL_INT_FMT = (((__LC_TELEPHONE) << 16) | (0)),
  _NL_TELEPHONE_TEL_DOM_FMT,
  _NL_TELEPHONE_INT_SELECT,
  _NL_TELEPHONE_INT_PREFIX,
  _NL_TELEPHONE_CODESET,
  _NL_NUM_LC_TELEPHONE,

  _NL_MEASUREMENT_MEASUREMENT = (((__LC_MEASUREMENT) << 16) | (0)),
  _NL_MEASUREMENT_CODESET,
  _NL_NUM_LC_MEASUREMENT,

  _NL_IDENTIFICATION_TITLE = (((__LC_IDENTIFICATION) << 16) | (0)),
  _NL_IDENTIFICATION_SOURCE,
  _NL_IDENTIFICATION_ADDRESS,
  _NL_IDENTIFICATION_CONTACT,
  _NL_IDENTIFICATION_EMAIL,
  _NL_IDENTIFICATION_TEL,
  _NL_IDENTIFICATION_FAX,
  _NL_IDENTIFICATION_LANGUAGE,
  _NL_IDENTIFICATION_TERRITORY,
  _NL_IDENTIFICATION_AUDIENCE,
  _NL_IDENTIFICATION_APPLICATION,
  _NL_IDENTIFICATION_ABBREVIATION,
  _NL_IDENTIFICATION_REVISION,
  _NL_IDENTIFICATION_DATE,
  _NL_IDENTIFICATION_CATEGORY,
  _NL_IDENTIFICATION_CODESET,
  _NL_NUM_LC_IDENTIFICATION,


  _NL_NUM
};
# 575 "/usr/include/langinfo.h" 3
extern char *nl_langinfo (nl_item __item) throw ();







# 1 "/usr/include/xlocale.h" 1 3
# 584 "/usr/include/langinfo.h" 2 3


extern char *__nl_langinfo_l (nl_item __item, __locale_t l);


}
# 45 "/usr/local/include/g++-v3/bits/locale_facets.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_cwctype.h" 1 3
# 38 "/usr/local/include/g++-v3/bits/std_cwctype.h" 3
# 1 "/usr/include/wctype.h" 1 3
# 26 "/usr/include/wctype.h" 3
# 1 "/usr/include/features.h" 1 3
# 27 "/usr/include/wctype.h" 2 3
# 1 "/usr/include/bits/types.h" 1 3
# 28 "/usr/include/wctype.h" 2 3







# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stddef.h" 1 3
# 36 "/usr/include/wctype.h" 2 3
# 61 "/usr/include/wctype.h" 3
typedef unsigned long int wctype_t;






# 1 "/usr/include/endian.h" 1 3
# 69 "/usr/include/wctype.h" 2 3
# 79 "/usr/include/wctype.h" 3
enum
{
  __ISwupper = 0,
  __ISwlower = 1,
  __ISwalpha = 2,
  __ISwdigit = 3,
  __ISwxdigit = 4,
  __ISwspace = 5,
  __ISwprint = 6,
  __ISwgraph = 7,
  __ISwblank = 8,
  __ISwcntrl = 9,
  __ISwpunct = 10,
  __ISwalnum = 11,

  _ISwupper = ((__ISwupper) < 8 ? (int) ((1UL << (__ISwupper)) << 24) : ((__ISwupper) < 16 ? (int) ((1UL << (__ISwupper)) << 8) : ((__ISwupper) < 24 ? (int) ((1UL << (__ISwupper)) >> 8) : (int) ((1UL << (__ISwupper)) >> 24)))),
  _ISwlower = ((__ISwlower) < 8 ? (int) ((1UL << (__ISwlower)) << 24) : ((__ISwlower) < 16 ? (int) ((1UL << (__ISwlower)) << 8) : ((__ISwlower) < 24 ? (int) ((1UL << (__ISwlower)) >> 8) : (int) ((1UL << (__ISwlower)) >> 24)))),
  _ISwalpha = ((__ISwalpha) < 8 ? (int) ((1UL << (__ISwalpha)) << 24) : ((__ISwalpha) < 16 ? (int) ((1UL << (__ISwalpha)) << 8) : ((__ISwalpha) < 24 ? (int) ((1UL << (__ISwalpha)) >> 8) : (int) ((1UL << (__ISwalpha)) >> 24)))),
  _ISwdigit = ((__ISwdigit) < 8 ? (int) ((1UL << (__ISwdigit)) << 24) : ((__ISwdigit) < 16 ? (int) ((1UL << (__ISwdigit)) << 8) : ((__ISwdigit) < 24 ? (int) ((1UL << (__ISwdigit)) >> 8) : (int) ((1UL << (__ISwdigit)) >> 24)))),
  _ISwxdigit = ((__ISwxdigit) < 8 ? (int) ((1UL << (__ISwxdigit)) << 24) : ((__ISwxdigit) < 16 ? (int) ((1UL << (__ISwxdigit)) << 8) : ((__ISwxdigit) < 24 ? (int) ((1UL << (__ISwxdigit)) >> 8) : (int) ((1UL << (__ISwxdigit)) >> 24)))),
  _ISwspace = ((__ISwspace) < 8 ? (int) ((1UL << (__ISwspace)) << 24) : ((__ISwspace) < 16 ? (int) ((1UL << (__ISwspace)) << 8) : ((__ISwspace) < 24 ? (int) ((1UL << (__ISwspace)) >> 8) : (int) ((1UL << (__ISwspace)) >> 24)))),
  _ISwprint = ((__ISwprint) < 8 ? (int) ((1UL << (__ISwprint)) << 24) : ((__ISwprint) < 16 ? (int) ((1UL << (__ISwprint)) << 8) : ((__ISwprint) < 24 ? (int) ((1UL << (__ISwprint)) >> 8) : (int) ((1UL << (__ISwprint)) >> 24)))),
  _ISwgraph = ((__ISwgraph) < 8 ? (int) ((1UL << (__ISwgraph)) << 24) : ((__ISwgraph) < 16 ? (int) ((1UL << (__ISwgraph)) << 8) : ((__ISwgraph) < 24 ? (int) ((1UL << (__ISwgraph)) >> 8) : (int) ((1UL << (__ISwgraph)) >> 24)))),
  _ISwblank = ((__ISwblank) < 8 ? (int) ((1UL << (__ISwblank)) << 24) : ((__ISwblank) < 16 ? (int) ((1UL << (__ISwblank)) << 8) : ((__ISwblank) < 24 ? (int) ((1UL << (__ISwblank)) >> 8) : (int) ((1UL << (__ISwblank)) >> 24)))),
  _ISwcntrl = ((__ISwcntrl) < 8 ? (int) ((1UL << (__ISwcntrl)) << 24) : ((__ISwcntrl) < 16 ? (int) ((1UL << (__ISwcntrl)) << 8) : ((__ISwcntrl) < 24 ? (int) ((1UL << (__ISwcntrl)) >> 8) : (int) ((1UL << (__ISwcntrl)) >> 24)))),
  _ISwpunct = ((__ISwpunct) < 8 ? (int) ((1UL << (__ISwpunct)) << 24) : ((__ISwpunct) < 16 ? (int) ((1UL << (__ISwpunct)) << 8) : ((__ISwpunct) < 24 ? (int) ((1UL << (__ISwpunct)) >> 8) : (int) ((1UL << (__ISwpunct)) >> 24)))),
  _ISwalnum = ((__ISwalnum) < 8 ? (int) ((1UL << (__ISwalnum)) << 24) : ((__ISwalnum) < 16 ? (int) ((1UL << (__ISwalnum)) << 8) : ((__ISwalnum) < 24 ? (int) ((1UL << (__ISwalnum)) >> 8) : (int) ((1UL << (__ISwalnum)) >> 24))))
};



extern "C" {







extern int iswalnum (wint_t __wc) throw ();





extern int iswalpha (wint_t __wc) throw ();


extern int iswcntrl (wint_t __wc) throw ();



extern int iswdigit (wint_t __wc) throw ();



extern int iswgraph (wint_t __wc) throw ();




extern int iswlower (wint_t __wc) throw ();


extern int iswprint (wint_t __wc) throw ();




extern int iswpunct (wint_t __wc) throw ();




extern int iswspace (wint_t __wc) throw ();




extern int iswupper (wint_t __wc) throw ();




extern int iswxdigit (wint_t __wc) throw ();





extern int iswblank (wint_t __wc) throw ();
# 178 "/usr/include/wctype.h" 3
extern wctype_t wctype (__const char *__property) throw ();



extern int iswctype (wint_t __wc, wctype_t __desc) throw ();




extern unsigned int *__ctype32_b;
# 249 "/usr/include/wctype.h" 3
typedef __const __int32_t *wctrans_t;


extern wint_t towlower (wint_t __wc) throw ();


extern wint_t towupper (wint_t __wc) throw ();




extern const wint_t *__ctype32_tolower;
extern const wint_t *__ctype32_toupper;
# 275 "/usr/include/wctype.h" 3
}
# 288 "/usr/include/wctype.h" 3
extern "C" {



extern wctrans_t wctrans (__const char *__property) throw ();


extern wint_t towctrans (wint_t __wc, wctrans_t __desc) throw ();



# 1 "/usr/include/xlocale.h" 1 3
# 300 "/usr/include/wctype.h" 2 3



extern int __iswalnum_l (wint_t __wc, __locale_t __locale) throw ();





extern int __iswalpha_l (wint_t __wc, __locale_t __locale) throw ();


extern int __iswcntrl_l (wint_t __wc, __locale_t __locale) throw ();



extern int __iswdigit_l (wint_t __wc, __locale_t __locale) throw ();



extern int __iswgraph_l (wint_t __wc, __locale_t __locale) throw ();




extern int __iswlower_l (wint_t __wc, __locale_t __locale) throw ();


extern int __iswprint_l (wint_t __wc, __locale_t __locale) throw ();




extern int __iswpunct_l (wint_t __wc, __locale_t __locale) throw ();




extern int __iswspace_l (wint_t __wc, __locale_t __locale) throw ();




extern int __iswupper_l (wint_t __wc, __locale_t __locale) throw ();




extern int __iswxdigit_l (wint_t __wc, __locale_t __locale) throw ();




extern int __iswblank_l (wint_t __wc, __locale_t __locale) throw ();



extern wctype_t __wctype_l (__const char *__property, __locale_t __locale)
     throw ();



extern int __iswctype_l (wint_t __wc, wctype_t __desc, __locale_t __locale)
     throw ();







extern wint_t __towlower_l (wint_t __wc, __locale_t __locale) throw ();


extern wint_t __towupper_l (wint_t __wc, __locale_t __locale) throw ();



extern wctrans_t __wctrans_l (__const char *__property, __locale_t __locale)
     throw ();


extern wint_t __towctrans_l (wint_t __wc, wctrans_t __desc,
                             __locale_t __locale) throw ();



}
# 39 "/usr/local/include/g++-v3/bits/std_cwctype.h" 2 3
# 61 "/usr/local/include/g++-v3/bits/std_cwctype.h" 3
namespace std
{
  using ::wint_t;

  using ::wctype_t;
  using ::wctrans_t;

  using ::iswalnum;
  using ::iswalpha;
  using ::iswblank;
  using ::iswcntrl;
  using ::iswdigit;
  using ::iswgraph;
  using ::iswlower;
  using ::iswprint;
  using ::iswprint;
  using ::iswpunct;
  using ::iswspace;
  using ::iswupper;
  using ::iswxdigit;
  using ::iswctype;
  using ::towlower;
  using ::towupper;
  using ::towctrans;
  using ::wctrans;
  using ::wctype;
}
# 46 "/usr/local/include/g++-v3/bits/locale_facets.h" 2 3
# 1 "/usr/include/iconv.h" 1 3
# 22 "/usr/include/iconv.h" 3
# 1 "/usr/include/features.h" 1 3
# 23 "/usr/include/iconv.h" 2 3

# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stddef.h" 1 3
# 25 "/usr/include/iconv.h" 2 3


extern "C" {


typedef void *iconv_t;




extern iconv_t iconv_open (__const char *__tocode, __const char *__fromcode)
     throw ();




extern size_t iconv (iconv_t __cd, char **__restrict __inbuf,
                     size_t *__restrict __inbytesleft,
                     char **__restrict __outbuf,
                     size_t *__restrict __outbytesleft);


extern int iconv_close (iconv_t __cd) throw ();

}
# 47 "/usr/local/include/g++-v3/bits/locale_facets.h" 2 3


namespace std
{


# 1 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/ctype_base.h" 1 3
# 50 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/ctype_base.h" 3
  struct ctype_base
  {

    typedef const int* __to_type;



    typedef unsigned short mask;
    static const mask upper = _ISupper;
    static const mask lower = _ISlower;
    static const mask alpha = _ISalpha;
    static const mask digit = _ISdigit;
    static const mask xdigit = _ISxdigit;
    static const mask space = _ISspace;
    static const mask print = _ISprint;
    static const mask graph = _ISgraph;
    static const mask cntrl = _IScntrl;
    static const mask punct = _ISpunct;
    static const mask alnum = _ISalnum;
  };
# 54 "/usr/local/include/g++-v3/bits/locale_facets.h" 2 3


  template<typename _CharT>
    class __ctype_abstract_base : public locale::facet, public ctype_base
    {
    public:

      typedef _CharT char_type;

      bool
      is(mask __m, char_type __c) const
      { return this->do_is(__m, __c); }

      const char_type*
      is(const char_type *__lo, const char_type *__hi, mask *__vec) const
      { return this->do_is(__lo, __hi, __vec); }

      const char_type*
      scan_is(mask __m, const char_type* __lo, const char_type* __hi) const
      { return this->do_scan_is(__m, __lo, __hi); }

      const char_type*
      scan_not(mask __m, const char_type* __lo, const char_type* __hi) const
      { return this->do_scan_not(__m, __lo, __hi); }

      char_type
      toupper(char_type __c) const
      { return this->do_toupper(__c); }

      const char_type*
      toupper(char_type *__lo, const char_type* __hi) const
      { return this->do_toupper(__lo, __hi); }

      char_type
      tolower(char_type __c) const
      { return this->do_tolower(__c); }

      const char_type*
      tolower(char_type* __lo, const char_type* __hi) const
      { return this->do_tolower(__lo, __hi); }

      char_type
      widen(char __c) const
      { return this->do_widen(__c); }

      const char*
      widen(const char* __lo, const char* __hi, char_type* __to) const
      { return this->do_widen(__lo, __hi, __to); }

      char
      narrow(char_type __c, char __dfault) const
      { return this->do_narrow(__c, __dfault); }

      const char_type*
      narrow(const char_type* __lo, const char_type* __hi,
              char __dfault, char *__to) const
      { return this->do_narrow(__lo, __hi, __dfault, __to); }

    protected:
      explicit
      __ctype_abstract_base(size_t __refs = 0): locale::facet(__refs) { }

      virtual
      ~__ctype_abstract_base() { }

      virtual bool
      do_is(mask __m, char_type __c) const = 0;

      virtual const char_type*
      do_is(const char_type* __lo, const char_type* __hi,
            mask* __vec) const = 0;

      virtual const char_type*
      do_scan_is(mask __m, const char_type* __lo,
                 const char_type* __hi) const = 0;

      virtual const char_type*
      do_scan_not(mask __m, const char_type* __lo,
                  const char_type* __hi) const = 0;

      virtual char_type
      do_toupper(char_type) const = 0;

      virtual const char_type*
      do_toupper(char_type* __lo, const char_type* __hi) const = 0;

      virtual char_type
      do_tolower(char_type) const = 0;

      virtual const char_type*
      do_tolower(char_type* __lo, const char_type* __hi) const = 0;

      virtual char_type
      do_widen(char) const = 0;

      virtual const char*
      do_widen(const char* __lo, const char* __hi,
               char_type* __dest) const = 0;

      virtual char
      do_narrow(char_type, char __dfault) const = 0;

      virtual const char_type*
      do_narrow(const char_type* __lo, const char_type* __hi,
                 char __dfault, char* __dest) const = 0;
    };


  template<typename _CharT>
    class ctype : public __ctype_abstract_base<_CharT>
    {
    public:

      typedef _CharT char_type;
      typedef typename ctype::mask mask;

      explicit
      ctype(size_t __refs = 0) : __ctype_abstract_base<_CharT>(__refs) { }

      static locale::id id;

   protected:
      virtual
      ~ctype() { }

      virtual bool
      do_is(mask __m, char_type __c) const
      { return false; }

      virtual const char_type*
      do_is(const char_type* __lo, const char_type* __hi, mask* __vec) const
      { return __hi; }

      virtual const char_type*
      do_scan_is(mask __m, const char_type* __lo, const char_type* __hi) const
      { return __hi; }

      virtual const char_type*
      do_scan_not(mask __m, const char_type* __lo,
                  const char_type* __hi) const
      { return __hi; }

      virtual char_type
      do_toupper(char_type __c) const
      { return __c; }

      virtual const char_type*
      do_toupper(char_type* __lo, const char_type* __hi) const
      { return __hi; }

      virtual char_type
      do_tolower(char_type __c) const
      { return __c; }

      virtual const char_type*
      do_tolower(char_type* __lo, const char_type* __hi) const
      { return __hi; }

      virtual char_type
      do_widen(char __c) const
      { return char_type(); }

      virtual const char*
      do_widen(const char* __lo, const char* __hi, char_type* __dest) const
      { return __hi; }

      virtual char
      do_narrow(char_type, char __dfault) const
      { return __dfault; }

      virtual const char_type*
      do_narrow(const char_type* __lo, const char_type* __hi,
                char __dfault, char* __dest) const
      { return __hi; }
    };

  template<typename _CharT>
    locale::id ctype<_CharT>::id;


  template<>
    class ctype<char> : public __ctype_abstract_base<char>
    {
    public:

      typedef char char_type;

    private:

      bool _M_del;
      __to_type const& _M_toupper;
      __to_type const& _M_tolower;
      const mask* const& _M_ctable;
      const mask* _M_table;

    public:
      static locale::id id;
      static const size_t table_size = 1 + static_cast<unsigned char>(-1);

      explicit
      ctype(const mask* __table = 0, bool __del = false, size_t __refs = 0);

      inline bool
      is(mask __m, char __c) const;

      inline const char*
      is(const char* __lo, const char* __hi, mask* __vec) const;

      inline const char*
      scan_is(mask __m, const char* __lo, const char* __hi) const;

      inline const char*
      scan_not(mask __m, const char* __lo, const char* __hi) const;

    protected:
      virtual
      ~ctype();

      const mask*
      table() const throw()
      { return _M_table; }

      const mask*
      classic_table() throw()
      { return _M_ctable; }

      virtual bool
      do_is(mask __m, char_type __c) const;

      virtual const char_type*
      do_is(const char_type* __lo, const char_type* __hi, mask* __vec) const;

      virtual const char_type*
      do_scan_is(mask __m, const char_type* __lo, const char_type* __hi) const;

      virtual const char_type*
      do_scan_not(mask __m, const char_type* __lo,
                  const char_type* __hi) const;

      virtual char_type
      do_toupper(char_type) const;

      virtual const char_type*
      do_toupper(char_type* __lo, const char_type* __hi) const;

      virtual char_type
      do_tolower(char_type) const;

      virtual const char_type*
      do_tolower(char_type* __lo, const char_type* __hi) const;

      virtual char_type
      do_widen(char) const;

      virtual const char*
      do_widen(const char* __lo, const char* __hi, char_type* __dest) const;

      virtual char
      do_narrow(char_type, char __dfault) const;

      virtual const char_type*
      do_narrow(const char_type* __lo, const char_type* __hi,
                 char __dfault, char* __dest) const;
    };

  template<>
    const ctype<char>&
    use_facet<ctype<char> >(const locale& __loc);



  template<>
    class ctype<wchar_t> : public __ctype_abstract_base<wchar_t>
    {
    public:

      typedef wchar_t char_type;
      typedef wctype_t __wmask_type;


      static locale::id id;

      explicit
      ctype(size_t __refs = 0);

    protected:
      __wmask_type
      _M_convert_to_wmask(const mask __m) const;

      virtual
      ~ctype();

      virtual bool
      do_is(mask __m, char_type __c) const;

      virtual const char_type*
      do_is(const char_type* __lo, const char_type* __hi, mask* __vec) const;

      virtual const char_type*
      do_scan_is(mask __m, const char_type* __lo, const char_type* __hi) const;

      virtual const char_type*
      do_scan_not(mask __m, const char_type* __lo,
                  const char_type* __hi) const;

      virtual char_type
      do_toupper(char_type) const;

      virtual const char_type*
      do_toupper(char_type* __lo, const char_type* __hi) const;

      virtual char_type
      do_tolower(char_type) const;

      virtual const char_type*
      do_tolower(char_type* __lo, const char_type* __hi) const;

      virtual char_type
      do_widen(char) const;

      virtual const char*
      do_widen(const char* __lo, const char* __hi, char_type* __dest) const;

      virtual char
      do_narrow(char_type, char __dfault) const;

      virtual const char_type*
      do_narrow(const char_type* __lo, const char_type* __hi,
                 char __dfault, char* __dest) const;

    };

  template<>
    const ctype<wchar_t>&
    use_facet<ctype<wchar_t> >(const locale& __loc);



# 1 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/ctype_inline.h" 1 3
# 37 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/ctype_inline.h" 3
  bool
  ctype<char>::
  is(mask __m, char __c) const
  { return _M_table[__c] & __m; }

  const char*
  ctype<char>::
  is(const char* __low, const char* __high, mask* __vec) const
  {
    while (__low < __high)
      *__vec++ = _M_table[*__low++];
    return __high;
  }

  const char*
  ctype<char>::
  scan_is(mask __m, const char* __low, const char* __high) const
  {
    while (__low < __high && !(_M_table[*__low] & __m))
      ++__low;
    return __low;
  }

  const char*
  ctype<char>::
  scan_not(mask __m, const char* __low, const char* __high) const
  {
    while (__low < __high
           && (_M_table[*__low] & __m) != 0)
      ++__low;
    return __low;
  }
# 393 "/usr/local/include/g++-v3/bits/locale_facets.h" 2 3


  template<typename _CharT>
    class ctype_byname : public ctype<_CharT>
    {
    public:
      typedef _CharT char_type;

      explicit
      ctype_byname(const char*, size_t __refs = 0);

    protected:
      virtual
      ~ctype_byname() { }
    };


  template<>
    ctype_byname<char>::ctype_byname(const char*, size_t refs);



# 1 "/usr/local/include/g++-v3/bits/codecvt.h" 1 3
# 42 "/usr/local/include/g++-v3/bits/codecvt.h" 3
# 57 "/usr/local/include/g++-v3/bits/codecvt.h" 3
  class __enc_traits
  {
  public:



    typedef iconv_t __desc_type;

  protected:


    static const int _S_max_size = 32;

    char _M_int_enc[_S_max_size];

    char _M_ext_enc[_S_max_size];


    __desc_type _M_in_desc;

    __desc_type _M_out_desc;


    int _M_ext_bom;


    int _M_int_bom;

  public:
    __enc_traits()
    : _M_in_desc(0), _M_out_desc(0), _M_ext_bom(0), _M_int_bom(0)
    {




      strcpy(_M_int_enc, "UCS4");


      strcpy(_M_ext_enc, nl_langinfo(CODESET));
    }

    __enc_traits(const char* __int, const char* __ext, int __ibom = 0,
                 int __ebom = 0)
    : _M_in_desc(0), _M_out_desc(0), _M_ext_bom(0), _M_int_bom(0)
    {
      strncpy(_M_int_enc, __int, _S_max_size);
      strncpy(_M_ext_enc, __ext, _S_max_size);
    }






    __enc_traits(const __enc_traits& __obj)
    {
      strncpy(_M_int_enc, __obj._M_int_enc, _S_max_size);
      strncpy(_M_ext_enc, __obj._M_ext_enc, _S_max_size);
      _M_ext_bom = __obj._M_ext_bom;
      _M_int_bom = __obj._M_int_bom;
    }

    ~__enc_traits()
    {
      iconv_close(_M_in_desc);
      iconv_close(_M_out_desc);
    }


    void
    _M_init()
    {
      _M_in_desc = iconv_open(_M_int_enc, _M_ext_enc);
      _M_out_desc = iconv_open(_M_ext_enc, _M_int_enc);
      if (_M_out_desc == iconv_t(-1) || _M_in_desc == iconv_t(-1))
        {

        }
    }

    bool
    _M_good()
    {
      return _M_out_desc && _M_in_desc
             && _M_out_desc != iconv_t(-1) && _M_in_desc != iconv_t(-1);
    }

    const __desc_type*
    _M_get_in_descriptor()
    { return &_M_in_desc; }

    const __desc_type*
    _M_get_out_descriptor()
    { return &_M_out_desc; }

   const char*
    _M_get_internal_enc()
    { return _M_int_enc; }

    const char*
    _M_get_external_enc()
    { return _M_ext_enc; }

    int
    _M_get_external_bom()
    { return _M_ext_bom; }

    int
    _M_get_internal_bom()
    { return _M_int_bom; }
  };




  class codecvt_base
  {
  public:
    enum result
    {
      ok,
      partial,
      error,
      noconv
    };
  };





  template<typename _InternT, typename _ExternT, typename _StateT>
    class __codecvt_abstract_base
    : public locale::facet, public codecvt_base
    {
    public:

      typedef codecvt_base::result result;
      typedef _InternT intern_type;
      typedef _ExternT extern_type;
      typedef _StateT state_type;


      result
      out(state_type& __state, const intern_type* __from,
          const intern_type* __from_end, const intern_type*& __from_next,
          extern_type* __to, extern_type* __to_end,
          extern_type*& __to_next) const
      {
        return this->do_out(__state, __from, __from_end, __from_next,
                            __to, __to_end, __to_next);
      }

      result
      unshift(state_type& __state, extern_type* __to, extern_type* __to_end,
              extern_type*& __to_next) const
      { return this->do_unshift(__state, __to,__to_end,__to_next); }

      result
      in(state_type& __state, const extern_type* __from,
         const extern_type* __from_end, const extern_type*& __from_next,
         intern_type* __to, intern_type* __to_end,
         intern_type*& __to_next) const
      {
        return this->do_in(__state, __from, __from_end, __from_next,
                           __to, __to_end, __to_next);
      }

      int
      encoding() const throw()
      { return this->do_encoding(); }

      bool
      always_noconv() const throw()
      { return this->do_always_noconv(); }

      int
      length(const state_type& __state, const extern_type* __from,
             const extern_type* __end, size_t __max) const
      { return this->do_length(__state, __from, __end, __max); }

      int
      max_length() const throw()
      { return this->do_max_length(); }

    protected:
      explicit
      __codecvt_abstract_base(size_t __refs = 0) : locale::facet(__refs) { }

      virtual
      ~__codecvt_abstract_base() { }

      virtual result
      do_out(state_type& __state, const intern_type* __from,
             const intern_type* __from_end, const intern_type*& __from_next,
             extern_type* __to, extern_type* __to_end,
             extern_type*& __to_next) const = 0;

      virtual result
      do_unshift(state_type& __state, extern_type* __to,
                 extern_type* __to_end, extern_type*& __to_next) const = 0;

      virtual result
      do_in(state_type& __state, const extern_type* __from,
            const extern_type* __from_end, const extern_type*& __from_next,
            intern_type* __to, intern_type* __to_end,
            intern_type*& __to_next) const = 0;

      virtual int
      do_encoding() const throw() = 0;

      virtual bool
      do_always_noconv() const throw() = 0;

      virtual int
      do_length(const state_type&, const extern_type* __from,
                const extern_type* __end, size_t __max) const = 0;

      virtual int
      do_max_length() const throw() = 0;
    };



  template<typename _InternT, typename _ExternT, typename _StateT>
    class codecvt
    : public __codecvt_abstract_base<_InternT, _ExternT, _StateT>
    {
    public:

      typedef codecvt_base::result result;
      typedef _InternT intern_type;
      typedef _ExternT extern_type;
      typedef _StateT state_type;


      static locale::id id;

      explicit
      codecvt(size_t __refs = 0)
      : __codecvt_abstract_base<_InternT,_ExternT,_StateT> (__refs) { }

    protected:
      virtual
      ~codecvt() { }
    };

  template<typename _InternT, typename _ExternT, typename _StateT>
    locale::id codecvt<_InternT, _ExternT, _StateT>::id;





  template<typename _InternT, typename _ExternT>
    class codecvt<_InternT, _ExternT, __enc_traits>
    : public __codecvt_abstract_base<_InternT, _ExternT, __enc_traits>
    {
    public:

      typedef codecvt_base::result result;
      typedef _InternT intern_type;
      typedef _ExternT extern_type;
      typedef __enc_traits state_type;
      typedef __enc_traits::__desc_type __desc_type;
      typedef __enc_traits __enc_type;


      static locale::id id;

      explicit
      codecvt(size_t __refs = 0)
      : __codecvt_abstract_base<intern_type, extern_type, state_type>(__refs)
      { }

      explicit
      codecvt(__enc_type* __enc, size_t __refs = 0)
      : __codecvt_abstract_base<intern_type, extern_type, state_type>(__refs)
      { }

    protected:
      virtual
      ~codecvt() { }

      virtual result
      do_out(state_type& __state, const intern_type* __from,
             const intern_type* __from_end, const intern_type*& __from_next,
             extern_type* __to, extern_type* __to_end,
             extern_type*& __to_next) const;

      virtual result
      do_unshift(state_type& __state, extern_type* __to,
                 extern_type* __to_end, extern_type*& __to_next) const;

      virtual result
      do_in(state_type& __state, const extern_type* __from,
            const extern_type* __from_end, const extern_type*& __from_next,
            intern_type* __to, intern_type* __to_end,
            intern_type*& __to_next) const;

      virtual int
      do_encoding() const throw();

      virtual bool
      do_always_noconv() const throw();

      virtual int
      do_length(const state_type&, const extern_type* __from,
                const extern_type* __end, size_t __max) const;

      virtual int
      do_max_length() const throw();
    };

  template<typename _InternT, typename _ExternT>
    locale::id
    codecvt<_InternT, _ExternT, __enc_traits>::id;





  template<typename _T>
    inline size_t
    __iconv_adaptor(size_t(*iconv_func)(iconv_t, _T, size_t*, char**, size_t*),
                    iconv_t cd, char** inbuf, size_t* inbytesleft,
                    char** outbuf, size_t* outbytesleft)
    {
      return iconv_func(cd, (_T)inbuf, inbytesleft, outbuf, outbytesleft);
    }

  template<typename _InternT, typename _ExternT>
    codecvt_base::result
    codecvt<_InternT, _ExternT, __enc_traits>::
    do_out(state_type& __state, const intern_type* __from,
           const intern_type* __from_end, const intern_type*& __from_next,
           extern_type* __to, extern_type* __to_end,
           extern_type*& __to_next) const
    {
      result __ret = error;
      if (__state._M_good())
        {
          typedef state_type::__desc_type __desc_type;
          const __desc_type* __desc = __state._M_get_out_descriptor();
          const size_t __fmultiple = sizeof(intern_type) / sizeof(char);
          size_t __flen = __fmultiple * (__from_end - __from);
          const size_t __tmultiple = sizeof(extern_type) / sizeof(char);
          size_t __tlen = __tmultiple * (__to_end - __to);



          char* __cto = reinterpret_cast<char*>(__to);
          char* __cfrom;
          size_t __conv;






          int __int_bom = __state._M_get_internal_bom();
          if (__int_bom)
            {
              size_t __size = __from_end - __from;
              intern_type* __cfixed = static_cast<intern_type*>(__builtin_alloca(sizeof(intern_type) * (__size + 1)));
              __cfixed[0] = static_cast<intern_type>(__int_bom);
              char_traits<intern_type>::copy(__cfixed + 1, __from, __size);
              __cfrom = reinterpret_cast<char*>(__cfixed);
              __conv = __iconv_adaptor(iconv, *__desc, &__cfrom,
                                        &__flen, &__cto, &__tlen);
            }
          else
            {
              intern_type* __cfixed = const_cast<intern_type*>(__from);
              __cfrom = reinterpret_cast<char*>(__cfixed);
              __conv = __iconv_adaptor(iconv, *__desc, &__cfrom,
                                       &__flen, &__cto, &__tlen);
            }

          if (__conv != size_t(-1))
            {
              __from_next = reinterpret_cast<const intern_type*>(__cfrom);
              __to_next = reinterpret_cast<extern_type*>(__cto);
              __ret = ok;
            }
          else
            {
              if (__flen < static_cast<size_t>(__from_end - __from))
                {
                  __from_next = reinterpret_cast<const intern_type*>(__cfrom);
                  __to_next = reinterpret_cast<extern_type*>(__cto);
                  __ret = partial;
                }
              else
                __ret = error;
            }
        }
      return __ret;
    }

  template<typename _InternT, typename _ExternT>
    codecvt_base::result
    codecvt<_InternT, _ExternT, __enc_traits>::
    do_unshift(state_type& __state, extern_type* __to,
               extern_type* __to_end, extern_type*& __to_next) const
    {
      result __ret = error;
      if (__state._M_good())
        {
          typedef state_type::__desc_type __desc_type;
          const __desc_type* __desc = __state._M_get_in_descriptor();
          const size_t __tmultiple = sizeof(intern_type) / sizeof(char);
          size_t __tlen = __tmultiple * (__to_end - __to);



          char* __cto = reinterpret_cast<char*>(__to);
          size_t __conv = __iconv_adaptor(iconv,*__desc, __null, __null,
                                          &__cto, &__tlen);

          if (__conv != size_t(-1))
            {
              __to_next = reinterpret_cast<extern_type*>(__cto);
              if (__tlen == __tmultiple * (__to_end - __to))
                __ret = noconv;
              else if (__tlen == 0)
                __ret = ok;
              else
                __ret = partial;
            }
          else
            __ret = error;
        }
      return __ret;
    }

  template<typename _InternT, typename _ExternT>
    codecvt_base::result
    codecvt<_InternT, _ExternT, __enc_traits>::
    do_in(state_type& __state, const extern_type* __from,
          const extern_type* __from_end, const extern_type*& __from_next,
          intern_type* __to, intern_type* __to_end,
          intern_type*& __to_next) const
    {
      result __ret = error;
      if (__state._M_good())
        {
          typedef state_type::__desc_type __desc_type;
          const __desc_type* __desc = __state._M_get_in_descriptor();
          const size_t __fmultiple = sizeof(extern_type) / sizeof(char);
          size_t __flen = __fmultiple * (__from_end - __from);
          const size_t __tmultiple = sizeof(intern_type) / sizeof(char);
          size_t __tlen = __tmultiple * (__to_end - __to);



          char* __cto = reinterpret_cast<char*>(__to);
          char* __cfrom;
          size_t __conv;






          int __ext_bom = __state._M_get_external_bom();
          if (__ext_bom)
            {
              size_t __size = __from_end - __from;
              extern_type* __cfixed = static_cast<extern_type*>(__builtin_alloca(sizeof(extern_type) * (__size + 1)));
              __cfixed[0] = static_cast<extern_type>(__ext_bom);
              char_traits<extern_type>::copy(__cfixed + 1, __from, __size);
              __cfrom = reinterpret_cast<char*>(__cfixed);
              __conv = __iconv_adaptor(iconv, *__desc, &__cfrom,
                                       &__flen, &__cto, &__tlen);
            }
          else
            {
              extern_type* __cfixed = const_cast<extern_type*>(__from);
              __cfrom = reinterpret_cast<char*>(__cfixed);
              __conv = __iconv_adaptor(iconv, *__desc, &__cfrom,
                                       &__flen, &__cto, &__tlen);
            }


          if (__conv != size_t(-1))
            {
              __from_next = reinterpret_cast<const extern_type*>(__cfrom);
              __to_next = reinterpret_cast<intern_type*>(__cto);
              __ret = ok;
            }
          else
            {
              if (__flen < static_cast<size_t>(__from_end - __from))
                {
                  __from_next = reinterpret_cast<const extern_type*>(__cfrom);
                  __to_next = reinterpret_cast<intern_type*>(__cto);
                  __ret = partial;
                }
              else
                __ret = error;
            }
        }
      return __ret;
    }

  template<typename _InternT, typename _ExternT>
    int
    codecvt<_InternT, _ExternT, __enc_traits>::
    do_encoding() const throw()
    { return 0; }

  template<typename _InternT, typename _ExternT>
    bool
    codecvt<_InternT, _ExternT, __enc_traits>::
    do_always_noconv() const throw()
    { return false; }

  template<typename _InternT, typename _ExternT>
    int
    codecvt<_InternT, _ExternT, __enc_traits>::
    do_length(const state_type&, const extern_type* __from,
              const extern_type* __end, size_t __max) const
    { return min(__max, static_cast<size_t>(__end - __from)); }



  template<typename _InternT, typename _ExternT>
    int
    codecvt<_InternT, _ExternT, __enc_traits>::
    do_max_length() const throw()
    { return 1; }




  template<>
    class codecvt<char, char, mbstate_t>
    : public __codecvt_abstract_base<char, char, mbstate_t>
    {
    public:

      typedef char intern_type;
      typedef char extern_type;
      typedef mbstate_t state_type;


      static locale::id id;

      explicit
      codecvt(size_t __refs = 0);

    protected:
      virtual
      ~codecvt();

      virtual result
      do_out(state_type& __state, const intern_type* __from,
             const intern_type* __from_end, const intern_type*& __from_next,
             extern_type* __to, extern_type* __to_end,
             extern_type*& __to_next) const;

      virtual result
      do_unshift(state_type& __state, extern_type* __to,
                 extern_type* __to_end, extern_type*& __to_next) const;

      virtual result
      do_in(state_type& __state, const extern_type* __from,
            const extern_type* __from_end, const extern_type*& __from_next,
            intern_type* __to, intern_type* __to_end,
            intern_type*& __to_next) const;

      virtual int
      do_encoding() const throw();

      virtual bool
      do_always_noconv() const throw();

      virtual int
      do_length(const state_type&, const extern_type* __from,
                const extern_type* __end, size_t __max) const;

      virtual int
      do_max_length() const throw();
  };



  template<>
    class codecvt<wchar_t, char, mbstate_t>
    : public __codecvt_abstract_base<wchar_t, char, mbstate_t>
    {
    public:

      typedef wchar_t intern_type;
      typedef char extern_type;
      typedef mbstate_t state_type;


      static locale::id id;

      explicit
      codecvt(size_t __refs = 0);

    protected:
      virtual
      ~codecvt();

      virtual result
      do_out(state_type& __state, const intern_type* __from,
             const intern_type* __from_end, const intern_type*& __from_next,
             extern_type* __to, extern_type* __to_end,
             extern_type*& __to_next) const;

      virtual result
      do_unshift(state_type& __state,
                 extern_type* __to, extern_type* __to_end,
                 extern_type*& __to_next) const;

      virtual result
      do_in(state_type& __state,
             const extern_type* __from, const extern_type* __from_end,
             const extern_type*& __from_next,
             intern_type* __to, intern_type* __to_end,
             intern_type*& __to_next) const;

      virtual
      int do_encoding() const throw();

      virtual
      bool do_always_noconv() const throw();

      virtual
      int do_length(const state_type&, const extern_type* __from,
                    const extern_type* __end, size_t __max) const;

      virtual int
      do_max_length() const throw();
    };



  template<typename _InternT, typename _ExternT, typename _StateT>
    class codecvt_byname : public codecvt<_InternT, _ExternT, _StateT>
    {
    public:
      explicit
      codecvt_byname(const char*, size_t __refs = 0)
      : codecvt<_InternT, _ExternT, _StateT>(__refs) { }
    protected:
      virtual
      ~codecvt_byname() { }
    };
# 416 "/usr/local/include/g++-v3/bits/locale_facets.h" 2 3

  template<typename _CharT, typename _InIter>
    class _Numeric_get;






  template<typename _CharT>
    class _Format_cache
    {
    public:

      typedef _CharT char_type;
      typedef char_traits<_CharT> traits_type;
      typedef basic_string<_CharT> string_type;
      typedef typename string_type::size_type size_type;


      friend class locale;
      template<typename _Char, typename _InIter>
        friend class _Numeric_get;
      friend class num_get<_CharT>;
      friend class num_put<_CharT>;
      friend class time_get<_CharT>;
      friend class money_get<_CharT>;
      friend class time_put<_CharT>;
      friend class money_put<_CharT>;




      static int _S_pword_ix;



      bool _M_valid;



      static const char _S_literals[];




      enum
      {
        _S_minus,
        _S_plus,
        _S_x,
        _S_X,
        _S_digits,
        _S_digits_end = _S_digits + 16,
        _S_udigits = _S_digits_end,
        _S_udigits_end = _S_udigits + 16,
        _S_ee = _S_digits + 14,
        _S_Ee = _S_udigits + 14
      };




      char_type _M_decimal_point;





      char_type _M_thousands_sep;



      string_type _M_truename;
      string_type _M_falsename;



      bool _M_use_grouping;



      string _M_grouping;

      _Format_cache();

      ~_Format_cache() throw() { }




      static _Format_cache<_CharT>*
      _S_get(ios_base& __ios);

      void
      _M_populate(ios_base&);

      static void
      _S_callback(ios_base::event __event, ios_base& __ios, int __ix) throw();
    };

  template<typename _CharT>
    int _Format_cache<_CharT>::_S_pword_ix;

  template<typename _CharT>
    const char _Format_cache<_CharT>::
    _S_literals[] = "-+xX0123456789abcdef0123456789ABCDEF";

   template<> _Format_cache<char>::_Format_cache();

   template<> _Format_cache<wchar_t>::_Format_cache();




  template<typename _CharT, typename _InIter>
    class _Numeric_get
    {
    public:

      typedef _CharT char_type;
      typedef _InIter iter_type;


      template<typename _Char, typename _InIterT>
      friend class num_get;
      template<typename _Char, typename _InIterT>
      friend class time_get;
      template<typename _Char, typename _InIterT>
      friend class money_get;
      template<typename _Char, typename _InIterT>
      friend class num_put;
      template<typename _Char, typename _InIterT>
      friend class time_put;
      template<typename _Char, typename _InIterT>
      friend class money_put;

    private:
      explicit
      _Numeric_get() { }

      virtual
      ~_Numeric_get() { }

      iter_type
      _M_get_digits(iter_type __in, iter_type __end) const;
    };

  template<typename _CharT, typename _InIter>
    class num_get : public locale::facet
    {
    public:

      typedef _CharT char_type;
      typedef _InIter iter_type;
      typedef char_traits<_CharT> __traits_type;

      static locale::id id;

      explicit
      num_get(size_t __refs = 0) : locale::facet(__refs) { }

      iter_type
      get(iter_type __in, iter_type __end, ios_base& __io,
          ios_base::iostate& __err, bool& __v) const
      { return do_get(__in, __end, __io, __err, __v); }


      iter_type
      get(iter_type __in, iter_type __end, ios_base& __io,
          ios_base::iostate& __err, short& __v) const
      { return do_get(__in, __end, __io, __err, __v); }

      iter_type
      get(iter_type __in, iter_type __end, ios_base& __io,
          ios_base::iostate& __err, int& __v) const
      { return do_get(__in, __end, __io, __err, __v); }


      iter_type
      get(iter_type __in, iter_type __end, ios_base& __io,
          ios_base::iostate& __err, long& __v) const
      { return do_get(__in, __end, __io, __err, __v); }


      iter_type
      get(iter_type __in, iter_type __end, ios_base& __io,
          ios_base::iostate& __err, long long& __v) const
      { return do_get(__in, __end, __io, __err, __v); }


      iter_type
      get(iter_type __in, iter_type __end, ios_base& __io,
          ios_base::iostate& __err, unsigned short& __v) const
      { return do_get(__in, __end, __io, __err, __v); }

      iter_type
      get(iter_type __in, iter_type __end, ios_base& __io,
          ios_base::iostate& __err, unsigned int& __v) const
      { return do_get(__in, __end, __io, __err, __v); }

      iter_type
      get(iter_type __in, iter_type __end, ios_base& __io,
          ios_base::iostate& __err, unsigned long& __v) const
      { return do_get(__in, __end, __io, __err, __v); }


      iter_type
      get(iter_type __in, iter_type __end, ios_base& __io,
          ios_base::iostate& __err, unsigned long long& __v) const
      { return do_get(__in, __end, __io, __err, __v); }


      iter_type
      get(iter_type __in, iter_type __end, ios_base& __io,
          ios_base::iostate& __err, float& __v) const
      { return do_get(__in, __end, __io, __err, __v); }

      iter_type
      get(iter_type __in, iter_type __end, ios_base& __io,
          ios_base::iostate& __err, double& __v) const
      { return do_get(__in, __end, __io, __err, __v); }

      iter_type
      get(iter_type __in, iter_type __end, ios_base& __io,
          ios_base::iostate& __err, long double& __v) const
      { return do_get(__in, __end, __io, __err, __v); }

      iter_type
      get(iter_type __in, iter_type __end, ios_base& __io,
          ios_base::iostate& __err, void*& __v) const
      { return do_get(__in, __end, __io, __err, __v); }

    protected:
      virtual ~num_get() { }





      void
      _M_extract(iter_type __beg, iter_type __end, ios_base& __io,
                 ios_base::iostate& __err, char* __xtrc,
                 int& __base, bool __fp = true) const;

      virtual iter_type
      do_get(iter_type, iter_type, ios_base&, ios_base::iostate&, bool&) const;


      virtual iter_type
      do_get(iter_type, iter_type, ios_base&, ios_base::iostate&, short&) const;
      virtual iter_type
      do_get(iter_type, iter_type, ios_base&, ios_base::iostate&, int&) const;

      virtual iter_type
      do_get (iter_type, iter_type, ios_base&, ios_base::iostate&, long&) const;

      virtual iter_type
      do_get(iter_type, iter_type, ios_base&, ios_base::iostate& __err,
             long long&) const;

      virtual iter_type
      do_get(iter_type, iter_type, ios_base&, ios_base::iostate& __err,
              unsigned short&) const;
      virtual iter_type
      do_get(iter_type, iter_type, ios_base&,
              ios_base::iostate& __err, unsigned int&) const;
      virtual iter_type
      do_get(iter_type, iter_type, ios_base&,
              ios_base::iostate& __err, unsigned long&) const;

      virtual iter_type
      do_get(iter_type, iter_type, ios_base&,
             ios_base::iostate& __err, unsigned long long&) const;

      virtual iter_type
      do_get(iter_type, iter_type, ios_base&, ios_base::iostate& __err,
             float&) const;

      virtual iter_type
      do_get(iter_type, iter_type, ios_base&, ios_base::iostate& __err,
             double&) const;

      virtual iter_type
      do_get(iter_type, iter_type, ios_base&,
             ios_base::iostate& __err, long double&) const;

      virtual iter_type
      do_get(iter_type, iter_type, ios_base&, ios_base::iostate& __err,
             void*&) const;
    };

  template<typename _CharT, typename _InIter>
    locale::id num_get<_CharT, _InIter>::id;


  template<>
    void
    num_get<char, istreambuf_iterator<char> >::
    _M_extract(istreambuf_iterator<char> __beg,
               istreambuf_iterator<char> __end, ios_base& __io,
               ios_base::iostate& __err, char* __xtrc,
               int& __base, bool __fp) const;



  template<typename _CharT, typename _OutIter>
    class _Numeric_put
    {
    public:
      typedef _CharT char_type;
      typedef _OutIter iter_type;
    protected:
      explicit
      _Numeric_put() { }

      virtual
      ~_Numeric_put() { }
    };

  template<typename _CharT, typename _OutIter>
    class num_put : public locale::facet
    {
    public:

      typedef _CharT char_type;
      typedef _OutIter iter_type;

      static locale::id id;

      explicit
      num_put(size_t __refs = 0) : locale::facet(__refs) { }

      iter_type
      put(iter_type __s, ios_base& __f, char_type __fill, bool __v) const
      { return do_put(__s, __f, __fill, __v); }

      iter_type
      put(iter_type __s, ios_base& __f, char_type __fill, long __v) const
      { return do_put(__s, __f, __fill, __v); }

      iter_type
      put(iter_type __s, ios_base& __f, char_type __fill,
          unsigned long __v) const
      { return do_put(__s, __f, __fill, __v); }


      iter_type
      put(iter_type __s, ios_base& __f, char_type __fill, long long __v) const
      { return do_put(__s, __f, __fill, __v); }

      iter_type
      put(iter_type __s, ios_base& __f, char_type __fill,
          unsigned long long __v) const
      { return do_put(__s, __f, __fill, __v); }


      iter_type
      put(iter_type __s, ios_base& __f, char_type __fill, double __v) const
      { return do_put(__s, __f, __fill, __v); }

      iter_type
      put(iter_type __s, ios_base& __f, char_type __fill,
          long double __v) const
      { return do_put(__s, __f, __fill, __v); }

      iter_type
      put(iter_type __s, ios_base& __f, char_type __fill,
          const void* __v) const
      { return do_put(__s, __f, __fill, __v); }

    protected:
      virtual
      ~num_put() { };

      virtual iter_type
      do_put(iter_type, ios_base&, char_type __fill, bool __v) const;

      virtual iter_type
      do_put(iter_type, ios_base&, char_type __fill, long __v) const;


      virtual iter_type
      do_put(iter_type, ios_base&, char_type __fill, long long __v) const;


      virtual iter_type
      do_put(iter_type, ios_base&, char_type __fill, unsigned long) const;


      virtual iter_type
      do_put(iter_type, ios_base&, char_type __fill, unsigned long long) const;


      virtual iter_type
      do_put(iter_type, ios_base&, char_type __fill, double __v) const;

      virtual iter_type
      do_put(iter_type, ios_base&, char_type __fill, long double __v) const;

      virtual iter_type
      do_put(iter_type, ios_base&, char_type __fill, const void* __v) const;
    };

  template <typename _CharT, typename _OutIter>
    locale::id num_put<_CharT, _OutIter>::id;

  template<typename _CharT>
    class numpunct : public locale::facet
    {
    public:

      typedef _CharT char_type;
      typedef basic_string<_CharT> string_type;

      static locale::id id;

    private:
      char_type _M_decimal_point;
      char_type _M_thousands_sep;
      string _M_grouping;
      string_type _M_truename;
      string_type _M_falsename;

    public:
      explicit
      numpunct(size_t __refs = 0) : locale::facet(__refs)
      { _M_initialize_numpunct(); }

      explicit
      numpunct(__c_locale __cloc, size_t __refs = 0) : locale::facet(__refs)
      { _M_initialize_numpunct(__cloc); }

      char_type
      decimal_point() const
      { return do_decimal_point(); }

      char_type
      thousands_sep() const
      { return do_thousands_sep(); }

      string
      grouping() const
      { return do_grouping(); }

      string_type
      truename() const
      { return do_truename(); }

      string_type
      falsename() const
      { return do_falsename(); }

    protected:
      virtual
      ~numpunct() { }

      virtual char_type
      do_decimal_point() const
      { return _M_decimal_point; }

      virtual char_type
      do_thousands_sep() const
      { return _M_thousands_sep; }

      virtual string
      do_grouping() const
      { return _M_grouping; }

      virtual string_type
      do_truename() const
      { return _M_truename; }

      virtual string_type
      do_falsename() const
      { return _M_falsename; }


      void
      _M_initialize_numpunct(__c_locale __cloc = __null);
    };

  template<typename _CharT>
    locale::id numpunct<_CharT>::id;

  template<typename _CharT>
    void
    numpunct<_CharT>::_M_initialize_numpunct(__c_locale )
    {

    }

  template<>
    void
    numpunct<char>::_M_initialize_numpunct(__c_locale __cloc);

  template<>
    void
    numpunct<wchar_t>::_M_initialize_numpunct(__c_locale __cloc);



  template<typename _CharT>
    class numpunct_byname : public numpunct<_CharT>
    {
      __c_locale _M_c_locale_numpunct;
    public:
      typedef _CharT char_type;
      typedef basic_string<_CharT> string_type;

      explicit
      numpunct_byname(const char* __s, size_t __refs = 0)
      : numpunct<_CharT>(__refs)
      {
        _S_create_c_locale(_M_c_locale_numpunct, __s);
        _M_initialize_numpunct(_M_c_locale_numpunct);
      }

    protected:
      virtual
      ~numpunct_byname()
      { _S_destroy_c_locale(_M_c_locale_numpunct); }
    };


  template<typename _CharT>
    class collate : public locale::facet
    {
    public:

      typedef _CharT char_type;
      typedef basic_string<_CharT> string_type;

      static locale::id id;

      explicit
      collate(size_t __refs = 0) : locale::facet(__refs) { }

      int
      compare(const _CharT* __lo1, const _CharT* __hi1,
              const _CharT* __lo2, const _CharT* __hi2) const
      { return this->do_compare(__lo1, __hi1, __lo2, __hi2); }

      string_type
      transform(const _CharT* __lo, const _CharT* __hi) const
      { return this->do_transform(__lo, __hi); }

      long
      hash(const _CharT* __lo, const _CharT* __hi) const
      { return this->do_hash(__lo, __hi); }

  protected:
      ~collate() { }

      virtual int
      do_compare(const _CharT* __lo1, const _CharT* __hi1,
                 const _CharT* __lo2, const _CharT* __hi2) const;

      virtual string_type
      do_transform(const _CharT* __lo, const _CharT* __hi) const;

      virtual long
      do_hash(const _CharT* __lo, const _CharT* __hi) const;
    };

  template<typename _CharT>
    locale::id collate<_CharT>::id;


  template<>
    int
    collate<char>::do_compare(const char* __lo1, const char* __hi1,
                              const char* __lo2, const char* __hi2) const;

  template<>
    string
    collate<char>::do_transform(const char* __lo, const char* __hi) const;

  template<>
    long
    collate<char>::do_hash(const char* __lo, const char* __hi) const;

  template<>
    int
    collate<wchar_t>::do_compare(const wchar_t* __lo1, const wchar_t* __hi1,
                                 const wchar_t* __lo2,
                                 const wchar_t* __hi2) const;

  template<>
    wstring
    collate<wchar_t>::do_transform(const wchar_t* __lo,
                                   const wchar_t* __hi) const;

  template<>
    long
    collate<wchar_t>::do_hash(const wchar_t* __lo, const wchar_t* __hi) const;


  template<typename _CharT>
    class collate_byname : public collate<_CharT>
    {
    public:

      typedef _CharT char_type;
      typedef basic_string<_CharT> string_type;

      explicit
      collate_byname(const char*, size_t __refs = 0);

    protected:
      virtual
      ~collate_byname() { }
    };

  template<>
    collate_byname<char>::collate_byname(const char*, size_t __refs);

  template<>
    collate_byname<wchar_t>::collate_byname(const char*, size_t __refs);


  class time_base
  {
  public:
    enum dateorder { no_order, dmy, mdy, ymd, ydm };
  };

  template<typename _CharT, typename _InIter>
    class time_get : public locale::facet, public time_base
    {
    public:

      typedef _CharT char_type;
      typedef _InIter iter_type;

      static locale::id id;

      explicit
      time_get(size_t __refs = 0)
      : locale::facet (__refs), _M_daynames(0), _M_monthnames(0) { }

      dateorder
      date_order() const
      { return do_date_order(); }

      iter_type
      get_time(iter_type __s, iter_type __end, ios_base& __f,
               ios_base::iostate& __err, tm* __t) const
      { return do_get_time(__s, __end, __f, __err, __t); }

      iter_type
      get_date(iter_type __s, iter_type __end, ios_base& __f,
               ios_base::iostate& __err, tm* __t) const
      { return do_get_date(__s, __end, __f, __err, __t); }

      iter_type
      get_weekday(iter_type __s, iter_type __end, ios_base& __f,
                  ios_base::iostate& __err, tm* __t) const
      { return do_get_weekday(__s,__end,__f,__err,__t); }

      iter_type
      get_monthname(iter_type __s, iter_type __end, ios_base& __f,
                    ios_base::iostate& __err, tm* __t) const
      { return do_get_monthname(__s,__end,__f,__err,__t); }

      iter_type
      get_year(iter_type __s, iter_type __end, ios_base& __f,
               ios_base::iostate& __err, tm* __t) const
      { return do_get_year(__s,__end,__f,__err,__t); }

    protected:
      virtual
      ~time_get()
      {
        delete [] _M_monthnames;
        delete [] _M_daynames;
      }

      virtual dateorder
      do_date_order() const
      { return time_base::ymd; }

      virtual iter_type
      do_get_time(iter_type __s, iter_type , ios_base&,
                  ios_base::iostate& , tm* ) const
      { return __s; }

      virtual iter_type
      do_get_date(iter_type __s, iter_type , ios_base&,
                  ios_base::iostate& , tm* ) const
      { return __s; }

      virtual iter_type
      do_get_weekday(iter_type __s, iter_type __end, ios_base&,
                     ios_base::iostate& __err, tm* __t) const;

      virtual iter_type
      do_get_monthname(iter_type __s, iter_type __end, ios_base&,
                       ios_base::iostate& __err, tm* __t) const;

      virtual iter_type
      do_get_year(iter_type __s, iter_type , ios_base&,
                   ios_base::iostate& , tm* ) const
      { return __s; }

      mutable basic_string<_CharT>* _M_daynames;
      mutable basic_string<_CharT>* _M_monthnames;
    };

  template<typename _CharT, typename _InIter>
    locale::id time_get<_CharT, _InIter>::id;

  template<typename _CharT, typename _InIter>
    class time_get_byname : public time_get<_CharT, _InIter>
    {
    public:
      typedef _CharT char_type;
      typedef _InIter iter_type;

      explicit
      time_get_byname(const char*, size_t __refs = 0)
      : time_get<_CharT, _InIter>(__refs) { }
    protected:
      virtual
      ~time_get_byname() { }
    };

  template<typename _CharT, typename _OutIter>
    class time_put : public locale::facet, public time_base
    {
    public:
      typedef _CharT char_type;
      typedef _OutIter iter_type;

      static locale::id id;

      explicit
      time_put(size_t __refs = 0) : locale::facet (__refs) { }


      iter_type
      put(iter_type __s, ios_base& , char_type ,
          const tm* , const _CharT* ,
          const _CharT* ) const
      { return __s; }

      iter_type
      put(iter_type __s, ios_base& __f, char_type __fill,
          const tm* __tmb, char __format, char __modifier = 0) const
      { return do_put(__s, __f, __fill, __tmb, __format, __modifier); }

    protected:
      virtual
      ~time_put() { }

      virtual iter_type
      do_put(iter_type __s, ios_base&, char_type, const tm* ,
             char , char ) const
      { return __s; }
    };

  template<typename _CharT, typename _OutIter>
    locale::id time_put<_CharT, _OutIter>::id;

  template<typename _CharT, typename _OutIter>
    class time_put_byname : public time_put<_CharT, _OutIter>
    {
    public:
      typedef _CharT char_type;
      typedef _OutIter iter_type;

      explicit
      time_put_byname(const char*, size_t __refs = 0)
      : time_put<_CharT, _OutIter> (__refs) { }

    protected:
      virtual
      ~time_put_byname() { }
    };


  template<typename _CharT, typename _InIter>
    class money_get : public locale::facet
    {
    public:
      typedef _CharT char_type;
      typedef _InIter iter_type;
      typedef basic_string<_CharT> string_type;

      static locale::id id;

      explicit
      money_get(size_t __refs = 0) : locale::facet(__refs) { }

      iter_type
      get(iter_type __s, iter_type __end, bool __intl,
          ios_base& __f, ios_base::iostate& __err, long double& __units) const
      { return do_get(__s, __end, __intl, __f, __err, __units); }

      iter_type
      get(iter_type __s, iter_type __end, bool __intl, ios_base& __f,
           ios_base::iostate& __err, string_type& __digits) const
      { return do_get(__s, __end, __intl, __f, __err, __digits); }

    protected:
      virtual
      ~money_get() { }

      virtual iter_type
      do_get(iter_type __s, iter_type , bool ,
             ios_base& , ios_base::iostate& ,
             long double& ) const
      { return __s; }

      virtual iter_type
      do_get(iter_type __s, iter_type , bool ,
             ios_base& , ios_base::iostate& ,
             string_type& ) const
      { return __s; }
    };

  template<typename _CharT, typename _InIter>
    locale::id money_get<_CharT, _InIter>::id;

  template<typename _CharT, typename _OutIter>
    class money_put : public locale::facet
    {
    public:
      typedef _CharT char_type;
      typedef _OutIter iter_type;
      typedef basic_string<_CharT> string_type;

      static locale::id id;

      explicit
      money_put(size_t __refs = 0) : locale::facet(__refs) { }

      iter_type
      put(iter_type __s, bool __intl, ios_base& __f,
          char_type __fill, long double __units) const
      { return do_put(__s, __intl, __f, __fill, __units); }

      iter_type
      put(iter_type __s, bool __intl, ios_base& __f,
          char_type __fill, const string_type& __digits) const
      { return do_put(__s, __intl, __f, __fill, __digits); }

    protected:
      virtual
      ~money_put() { }

      virtual iter_type
      do_put(iter_type __s, bool, ios_base& , char_type ,
             long double ) const
      { return __s; }

      virtual iter_type
      do_put(iter_type __s, bool, ios_base& , char_type ,
             const string_type& ) const
      { return __s; }
    };

  template<typename _CharT, typename _OutIter>
    locale::id money_put<_CharT, _OutIter>::id;

  struct money_base
  {
    enum part { none, space, symbol, sign, value };
    struct pattern { char field[4]; };

    static const pattern _S_default_pattern;



    static pattern
    _S_construct_pattern(char __preceeds, char __space, char __posn);
  };

  template<typename _CharT, bool _Intl>
    class moneypunct : public locale::facet, public money_base
    {
    public:

      typedef _CharT char_type;
      typedef basic_string<_CharT> string_type;

      static const bool intl = _Intl;
      static locale::id id;

    private:
      char_type _M_decimal_point;
      char_type _M_thousands_sep;
      string _M_grouping;
      string_type _M_curr_symbol;
      string_type _M_positive_sign;
      string_type _M_negative_sign;
      int _M_frac_digits;
      pattern _M_pos_format;
      pattern _M_neg_format;

    public:
      explicit
      moneypunct(size_t __refs = 0) : locale::facet(__refs)
      { _M_initialize_moneypunct(); }

      explicit
      moneypunct(__c_locale __cloc, size_t __refs = 0) : locale::facet(__refs)
      { _M_initialize_moneypunct(__cloc); }

      char_type
      decimal_point() const
      { return this->do_decimal_point(); }

      char_type
      thousands_sep() const
      { return this->do_thousands_sep(); }

      string
      grouping() const
      { return this->do_grouping(); }

      string_type
      curr_symbol() const
      { return this->do_curr_symbol(); }

      string_type
      positive_sign() const
      { return this->do_positive_sign(); }

      string_type
      negative_sign() const
      { return this->do_negative_sign(); }

      int
      frac_digits() const
      { return this->do_frac_digits(); }

      pattern
      pos_format() const
      { return this->do_pos_format(); }

      pattern
      neg_format() const
      { return this->do_neg_format(); }

    protected:
      virtual
      ~moneypunct() { }

      virtual char_type
      do_decimal_point() const
      { return _M_decimal_point; }

      virtual char_type
      do_thousands_sep() const
      { return _M_thousands_sep; }

      virtual string
      do_grouping() const
      { return _M_grouping; }

      virtual string_type
      do_curr_symbol() const
      { return _M_curr_symbol; }

      virtual string_type
      do_positive_sign() const
      { return _M_positive_sign; }

      virtual string_type
      do_negative_sign() const
      { return _M_negative_sign; }

      virtual int
      do_frac_digits() const
      { return _M_frac_digits; }

      virtual pattern
      do_pos_format() const
      { return _M_pos_format; }

      virtual pattern
      do_neg_format() const
      { return _M_neg_format; }


      void
      _M_initialize_moneypunct(__c_locale __cloc = __null);
    };

  template<typename _CharT, bool _Intl>
    locale::id moneypunct<_CharT, _Intl>::id;

  template<typename _CharT, bool _Intl>
    const bool moneypunct<_CharT, _Intl>::intl;

  template<typename _CharT, bool _Intl>
    void
    moneypunct<_CharT, _Intl>::_M_initialize_moneypunct(__c_locale )
    {

    }

  template<>
    void
    moneypunct<char>::_M_initialize_moneypunct(__c_locale __cloc);

  template<>
    void
    moneypunct<wchar_t>::_M_initialize_moneypunct(__c_locale __cloc);


  template<typename _CharT, bool _Intl>
    class moneypunct_byname : public moneypunct<_CharT, _Intl>
    {
      __c_locale _M_c_locale_moneypunct;
    public:
      typedef _CharT char_type;
      typedef basic_string<_CharT> string_type;

      static const bool intl = _Intl;

      explicit
      moneypunct_byname(const char* __s, size_t __refs = 0)
      : moneypunct<_CharT, _Intl>(__refs)
      {
        _S_create_c_locale(_M_c_locale_moneypunct, __s);
        _M_initialize_moneypunct(_M_c_locale_moneypunct);
      }

    protected:
      virtual
      ~moneypunct_byname()
      { _S_destroy_c_locale(_M_c_locale_moneypunct); }
    };

  template<typename _CharT, bool _Intl>
    const bool moneypunct_byname<_CharT, _Intl>::intl;


  struct messages_base
  {
    typedef int catalog;
  };

  template<typename _CharT>
    class messages : public locale::facet, public messages_base
    {
    public:
      typedef _CharT char_type;
      typedef basic_string<_CharT> string_type;

      static locale::id id;

      explicit
      messages(size_t __refs = 0) : locale::facet(__refs) { }

      catalog
      open(const basic_string<char>& __s, const locale& __loc) const
      { return do_open(__s, __loc); }

      string_type
      get(catalog __c, int __set, int __msgid, const string_type& __s) const
      { return do_get(__c,__set,__msgid,__s); }

      void
      close(catalog __c) const
      { return do_close(__c); }

    protected:
      virtual
      ~messages() { }



      virtual catalog
      do_open(const basic_string<char>&, const locale&) const
      { return 0; }

      virtual string_type
      do_get(catalog, int, int , const string_type& __dfault) const
      { return __dfault; }

      virtual void
      do_close(catalog) const { }
    };

  template<typename _CharT>
    locale::id messages<_CharT>::id;

  template<typename _CharT>
    class messages_byname : public messages<_CharT>
    {
    public:
      typedef _CharT char_type;
      typedef basic_string<_CharT> string_type;

      explicit
      messages_byname(const char*, size_t __refs = 0);

    protected:
      virtual
      ~messages_byname() { }
    };

  template<>
    messages_byname<char>::messages_byname(const char*, size_t __refs);

  template<>
    messages_byname<wchar_t>::messages_byname(const char*, size_t __refs);






  template<typename _CharT>
    inline bool
    isspace(_CharT __c, const locale& __loc)
    { return use_facet<ctype<_CharT> >(__loc).is(ctype_base::space, __c); }

  template<typename _CharT>
    inline bool
    isprint(_CharT __c, const locale& __loc)
    { return use_facet<ctype<_CharT> >(__loc).is(ctype_base::print, __c); }

  template<typename _CharT>
    inline bool
    iscntrl(_CharT __c, const locale& __loc)
    { return use_facet<ctype<_CharT> >(__loc).is(ctype_base::cntrl, __c); }

  template<typename _CharT>
    inline bool
    isupper(_CharT __c, const locale& __loc)
    { return use_facet<ctype<_CharT> >(__loc).is(ctype_base::upper, __c); }

  template<typename _CharT>
    inline bool islower(_CharT __c, const locale& __loc)
    { return use_facet<ctype<_CharT> >(__loc).is(ctype_base::lower, __c); }

  template<typename _CharT>
    inline bool
    isalpha(_CharT __c, const locale& __loc)
    { return use_facet<ctype<_CharT> >(__loc).is(ctype_base::alpha, __c); }

  template<typename _CharT>
    inline bool
    isdigit(_CharT __c, const locale& __loc)
    { return use_facet<ctype<_CharT> >(__loc).is(ctype_base::digit, __c); }

  template<typename _CharT>
    inline bool
    ispunct(_CharT __c, const locale& __loc)
    { return use_facet<ctype<_CharT> >(__loc).is(ctype_base::punct, __c); }

  template<typename _CharT>
    inline bool
    isxdigit(_CharT __c, const locale& __loc)
    { return use_facet<ctype<_CharT> >(__loc).is(ctype_base::xdigit, __c); }

  template<typename _CharT>
    inline bool
    isalnum(_CharT __c, const locale& __loc)
    { return use_facet<ctype<_CharT> >(__loc).is(ctype_base::alnum, __c); }

  template<typename _CharT>
    inline bool
    isgraph(_CharT __c, const locale& __loc)
    { return use_facet<ctype<_CharT> >(__loc).is(ctype_base::graph, __c); }

  template<typename _CharT>
    inline _CharT
    toupper(_CharT __c, const locale& __loc)
    { return use_facet<ctype<_CharT> >(__loc).toupper(__c); }

  template<typename _CharT>
    inline _CharT
    tolower(_CharT __c, const locale& __loc)
    { return use_facet<ctype<_CharT> >(__loc).tolower(__c); }
}
# 37 "/usr/local/include/g++-v3/bits/basic_ios.h" 2 3

namespace std
{

  template<typename _CharT, typename _Traits>
    class basic_ios : public ios_base
    {
    public:

      typedef _CharT char_type;
      typedef typename _Traits::int_type int_type;
      typedef typename _Traits::pos_type pos_type;
      typedef typename _Traits::off_type off_type;
      typedef _Traits traits_type;


      typedef ctype<_CharT> __ctype_type;
      typedef ostreambuf_iterator<_CharT, _Traits> __ostreambuf_iter;
      typedef num_put<_CharT, __ostreambuf_iter> __numput_type;
      typedef istreambuf_iterator<_CharT, _Traits> __istreambuf_iter;
      typedef num_get<_CharT, __istreambuf_iter> __numget_type;


    private:
      basic_ostream<_CharT, _Traits>* _M_tie;
      char_type _M_fill;
      iostate _M_exception;

    protected:
      basic_streambuf<_CharT, _Traits>* _M_streambuf;
      iostate _M_streambuf_state;


      const __ctype_type* _M_ios_fctype;

      const __numput_type* _M_fnumput;

      const __numget_type* _M_fnumget;

    public:
      inline const __ctype_type*
      _M_get_fctype_ios(void)
      { return _M_ios_fctype; }

      operator void*() const
      { return this->fail() ? 0 : const_cast<basic_ios*>(this); }

      inline bool
      operator!() const
      { return this->fail(); }

      inline iostate
      rdstate() const
      { return _M_streambuf_state; }

      inline void
      clear(iostate __state = goodbit)
      {
        if (this->rdbuf())
          _M_streambuf_state = __state;
        else
          _M_streambuf_state = __state | badbit;
        if ((this->rdstate() & this->exceptions()))
          __throw_ios_failure("basic_ios::clear(iostate) caused exception");
      }

      inline void
      setstate(iostate __state)
      { this->clear(this->rdstate() | __state); }

      inline bool
      good() const
      { return this->rdstate() == 0; }

      inline bool
      eof() const
      { return (this->rdstate() & eofbit) != 0; }

      inline bool
      fail() const
      { return (this->rdstate() & (badbit | failbit)) != 0; }

      inline bool
      bad() const
      { return (this->rdstate() & badbit) != 0; }

      inline iostate
      exceptions() const
      { return _M_exception; }

      inline void
      exceptions(iostate __except)
      {
        _M_exception = __except;
        this->clear(_M_streambuf_state);
      }


      explicit
      basic_ios(basic_streambuf<_CharT, _Traits>* __sb) : ios_base()
      { this->init(__sb); }

      virtual
      ~basic_ios() { }


      inline basic_ostream<_CharT, _Traits>*
      tie() const
      { return _M_tie; }

      inline basic_ostream<_CharT, _Traits>*
      tie(basic_ostream<_CharT, _Traits>* __tiestr)
      {
        basic_ostream<_CharT, _Traits>* __old = _M_tie;
        _M_tie = __tiestr;
        return __old;
      }

      inline basic_streambuf<_CharT, _Traits>*
      rdbuf() const
      { return _M_streambuf; }

      basic_streambuf<_CharT, _Traits>*
      rdbuf(basic_streambuf<_CharT, _Traits>* __sb);

      basic_ios&
      copyfmt(const basic_ios& __rhs);

      inline char_type
      fill() const
      { return _M_fill; }

      inline char_type
      fill(char_type __ch)
      {
        char_type __old = _M_fill;
        _M_fill = __ch;
        return __old;
      }


      locale
      imbue(const locale& __loc);

      char
      narrow(char_type __c, char __dfault) const;

      char_type
      widen(char __c) const;

    protected:

      basic_ios() : ios_base()
      { }

      void
      init(basic_streambuf<_CharT, _Traits>* __sb);

      bool
      _M_check_facet(const locale::facet* __f)
      {
        bool __ret = false;
        if (__f)
          __ret = true;
        else
          __throw_bad_cast();
        return __ret;
      }

      void
      _M_cache_facets(const locale& __loc);
    };
}



# 1 "/usr/local/include/g++-v3/bits/basic_ios.tcc" 1 3
# 33 "/usr/local/include/g++-v3/bits/basic_ios.tcc" 3
namespace std
{
  template<typename _CharT, typename _Traits>
    basic_streambuf<_CharT, _Traits>*
    basic_ios<_CharT, _Traits>::rdbuf(basic_streambuf<_CharT, _Traits>* __sb)
    {
      basic_streambuf<_CharT, _Traits>* __old = _M_streambuf;
      _M_streambuf = __sb;
      this->clear();
      return __old;
    }

  template<typename _CharT, typename _Traits>
    basic_ios<_CharT, _Traits>&
    basic_ios<_CharT, _Traits>::copyfmt(const basic_ios& __rhs)
    {




      _Words* __words = (__rhs._M_word_limit <= _S_local_words) ?
        _M_word_array : new _Words[__rhs._M_word_limit];
# 63 "/usr/local/include/g++-v3/bits/basic_ios.tcc" 3
      _Callback_list* __cb = __rhs._M_callbacks;
      if (__cb)
        __cb->_M_add_reference();
      _M_call_callbacks(erase_event);
      if (_M_words != _M_word_array)
        delete [] _M_words;
      _M_dispose_callbacks();

      _M_callbacks = __cb;
      for (int __i = 0; __i < __rhs._M_word_limit; ++__i)
        __words[__i] = __rhs._M_words[__i];
      if (_M_words != _M_word_array)
        delete [] _M_words;
      _M_words = __words;
      _M_word_limit = __rhs._M_word_limit;

      this->flags(__rhs.flags());
      this->width(__rhs.width());
      this->precision(__rhs.precision());
      this->tie(__rhs.tie());
      this->fill(__rhs.fill());

      this->exceptions(__rhs.exceptions());

      _M_call_callbacks(copyfmt_event);
      return *this;
    }

  template<typename _CharT, typename _Traits>
    char
    basic_ios<_CharT, _Traits>::narrow(char_type __c, char __dfault) const
    { return _M_ios_fctype->narrow(__c, __dfault); }

  template<typename _CharT, typename _Traits>
    _CharT
    basic_ios<_CharT, _Traits>::widen(char __c) const
    { return _M_ios_fctype->widen(__c); }


  template<typename _CharT, typename _Traits>
    locale
    basic_ios<_CharT, _Traits>::imbue(const locale& __loc)
    {
      locale __old(this->getloc());
      ios_base::imbue(__loc);
      _M_cache_facets(__loc);
      if (this->rdbuf() != 0)
        this->rdbuf()->pubimbue(__loc);
      return __old;
    }

  template<typename _CharT, typename _Traits>
    void
    basic_ios<_CharT, _Traits>::init(basic_streambuf<_CharT, _Traits>* __sb)
    {

      ios_base::_M_init();
      _M_cache_facets(_M_ios_locale);
      _M_tie = 0;
      _M_fill = this->widen(' ');
      _M_exception = goodbit;
      _M_streambuf = __sb;
      _M_streambuf_state = __sb ? goodbit : badbit;
    }

  template<typename _CharT, typename _Traits>
    void
    basic_ios<_CharT, _Traits>::_M_cache_facets(const locale& __loc)
    {
      if (has_facet<__ctype_type>(__loc))
        _M_ios_fctype = &use_facet<__ctype_type>(__loc);

      if (has_facet<__numput_type>(__loc))
        _M_fnumput = &use_facet<__numput_type>(__loc);
      if (has_facet<__numget_type>(__loc))
        _M_fnumget = &use_facet<__numget_type>(__loc);
    }
}
# 214 "/usr/local/include/g++-v3/bits/basic_ios.h" 2 3
# 47 "/usr/local/include/g++-v3/bits/std_ios.h" 2 3
# 40 "/usr/local/include/g++-v3/bits/std_ostream.h" 2 3

namespace std
{

  template<typename _CharT, typename _Traits>
    class basic_ostream : virtual public basic_ios<_CharT, _Traits>
    {
    public:


      typedef _CharT char_type;
      typedef typename _Traits::int_type int_type;
      typedef typename _Traits::pos_type pos_type;
      typedef typename _Traits::off_type off_type;
      typedef _Traits traits_type;


      typedef basic_streambuf<_CharT, _Traits> __streambuf_type;
      typedef basic_ios<_CharT, _Traits> __ios_type;
      typedef basic_ostream<_CharT, _Traits> __ostream_type;
      typedef ostreambuf_iterator<_CharT, _Traits> __ostreambuf_iter;
      typedef num_put<_CharT, __ostreambuf_iter> __numput_type;
      typedef ctype<_CharT> __ctype_type;


      explicit
      basic_ostream(__streambuf_type* __sb)
      { this->init(__sb); }

      virtual
      ~basic_ostream() { }


      class sentry;
      friend class sentry;



      __ostream_type&
      operator<<(__ostream_type& (*__pf)(__ostream_type&));

      __ostream_type&
      operator<<(__ios_type& (*__pf)(__ios_type&));

      __ostream_type&
      operator<<(ios_base& (*__pf) (ios_base&));


      __ostream_type&
      operator<<(long __n);

      __ostream_type&
      operator<<(unsigned long __n);

      __ostream_type&
      operator<<(bool __n);

      __ostream_type&
      operator<<(short __n)
      {
        ios_base::fmtflags __fmt = this->flags() & ios_base::basefield;
        if (__fmt & ios_base::oct || __fmt & ios_base::hex)
          return this->operator<<(static_cast<unsigned long>
                                  (static_cast<unsigned short>(__n)));
        else
          return this->operator<<(static_cast<long>(__n));
      }

      __ostream_type&
      operator<<(unsigned short __n)
      { return this->operator<<(static_cast<unsigned long>(__n)); }

      __ostream_type&
      operator<<(int __n)
      {
        ios_base::fmtflags __fmt = this->flags() & ios_base::basefield;
        if (__fmt & ios_base::oct || __fmt & ios_base::hex)
          return this->operator<<(static_cast<unsigned long>
                                  (static_cast<unsigned int>(__n)));
        else
          return this->operator<<(static_cast<long>(__n));
      }

      __ostream_type&
      operator<<(unsigned int __n)
      { return this->operator<<(static_cast<unsigned long>(__n)); }


      __ostream_type&
      operator<<(long long __n);

      __ostream_type&
      operator<<(unsigned long long __n);


      __ostream_type&
      operator<<(double __f);

      __ostream_type&
      operator<<(float __f)
      { return this->operator<<(static_cast<double>(__f)); }

      __ostream_type&
      operator<<(long double __f);

      __ostream_type&
      operator<<(const void* __p);

      __ostream_type&
      operator<<(__streambuf_type* __sb);


      __ostream_type&
      put(char_type __c);

      __ostream_type&
      write(const char_type* __s, streamsize __n);

      __ostream_type&
      flush();


      pos_type
      tellp();

      __ostream_type&
      seekp(pos_type);

      __ostream_type&
      seekp(off_type, ios_base::seekdir);

    private:


      __ostream_type&
      operator=(const __ostream_type&);

      basic_ostream(const __ostream_type&);

    };


  template <typename _CharT, typename _Traits>
    class basic_ostream<_CharT, _Traits>::sentry
    {

      bool _M_ok;
      basic_ostream<_CharT,_Traits>& _M_os;

    public:
      explicit
      sentry(basic_ostream<_CharT,_Traits>& __os);

      ~sentry()
      {

        if (_M_os.flags() & ios_base::unitbuf && !uncaught_exception())
          {

            if (_M_os.rdbuf() && _M_os.rdbuf()->pubsync() == -1)
              _M_os.setstate(ios_base::badbit);
          }
      }

      operator bool()
      { return _M_ok; }
    };

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __out, _CharT __c);

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __out, char __c)
    { return (__out << __out.widen(__c)); }


  template <class _Traits>
    basic_ostream<char, _Traits>&
    operator<<(basic_ostream<char, _Traits>& __out, char __c);


  template<class _Traits>
    basic_ostream<char, _Traits>&
    operator<<(basic_ostream<char, _Traits>& __out, signed char __c)
    { return (__out << static_cast<char>(__c)); }

  template<class _Traits>
    basic_ostream<char, _Traits>&
    operator<<(basic_ostream<char, _Traits>& __out, unsigned char __c)
    { return (__out << static_cast<char>(__c)); }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __out, const _CharT* __s);

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits> &
    operator<<(basic_ostream<_CharT, _Traits>& __out, const char* __s);


  template<class _Traits>
    basic_ostream<char, _Traits>&
    operator<<(basic_ostream<char, _Traits>& __out, const char* __s);


  template<class _Traits>
    basic_ostream<char, _Traits>&
    operator<<(basic_ostream<char, _Traits>& __out, const signed char* __s)
    { return (__out << reinterpret_cast<const char*>(__s)); }

  template<class _Traits>
    basic_ostream<char, _Traits> &
    operator<<(basic_ostream<char, _Traits>& __out, const unsigned char* __s)
    { return (__out << reinterpret_cast<const char*>(__s)); }


  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    endl(basic_ostream<_CharT, _Traits>& __os)
    { return flush(__os.put(__os.widen('\n'))); }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    ends(basic_ostream<_CharT, _Traits>& __os)
    { return __os.put(_CharT()); }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    flush(basic_ostream<_CharT, _Traits>& __os)
    { return __os.flush(); }

}




# 1 "/usr/local/include/g++-v3/bits/ostream.tcc" 1 3
# 32 "/usr/local/include/g++-v3/bits/ostream.tcc" 3
# 1 "/usr/local/include/g++-v3/bits/std_locale.h" 1 3
# 38 "/usr/local/include/g++-v3/bits/std_locale.h" 3

# 1 "/usr/local/include/g++-v3/bits/localefwd.h" 1 3
# 40 "/usr/local/include/g++-v3/bits/std_locale.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/locale_facets.h" 1 3
# 41 "/usr/local/include/g++-v3/bits/std_locale.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/locale_facets.tcc" 1 3
# 35 "/usr/local/include/g++-v3/bits/locale_facets.tcc" 3
# 1 "/usr/local/include/g++-v3/bits/std_cerrno.h" 1 3
# 38 "/usr/local/include/g++-v3/bits/std_cerrno.h" 3
# 1 "/usr/include/errno.h" 1 3
# 29 "/usr/include/errno.h" 3
# 1 "/usr/include/features.h" 1 3
# 30 "/usr/include/errno.h" 2 3


extern "C" {



# 1 "/usr/include/bits/errno.h" 1 3
# 25 "/usr/include/bits/errno.h" 3
# 1 "/usr/include/linux/errno.h" 1 3



# 1 "/usr/include/asm/errno.h" 1 3
# 5 "/usr/include/linux/errno.h" 2 3
# 26 "/usr/include/bits/errno.h" 2 3
# 36 "/usr/include/bits/errno.h" 3
extern int errno;


extern int *__errno_location (void) throw () __attribute__ ((__const__));
# 37 "/usr/include/errno.h" 2 3
# 55 "/usr/include/errno.h" 3
extern char *program_invocation_name, *program_invocation_short_name;



}
# 69 "/usr/include/errno.h" 3
typedef int error_t;
# 39 "/usr/local/include/g++-v3/bits/std_cerrno.h" 2 3
# 36 "/usr/local/include/g++-v3/bits/locale_facets.tcc" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_clocale.h" 1 3
# 38 "/usr/local/include/g++-v3/bits/std_clocale.h" 3
# 1 "/usr/include/locale.h" 1 3
# 26 "/usr/include/locale.h" 3
# 1 "/usr/include/features.h" 1 3
# 27 "/usr/include/locale.h" 2 3


# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stddef.h" 1 3
# 30 "/usr/include/locale.h" 2 3
# 1 "/usr/include/bits/locale.h" 1 3
# 31 "/usr/include/locale.h" 2 3

extern "C" {
# 52 "/usr/include/locale.h" 3
struct lconv
{


  char *decimal_point;
  char *thousands_sep;





  char *grouping;





  char *int_curr_symbol;
  char *currency_symbol;
  char *mon_decimal_point;
  char *mon_thousands_sep;
  char *mon_grouping;
  char *positive_sign;
  char *negative_sign;
  char int_frac_digits;
  char frac_digits;

  char p_cs_precedes;

  char p_sep_by_space;

  char n_cs_precedes;

  char n_sep_by_space;






  char p_sign_posn;
  char n_sign_posn;


  char int_p_cs_precedes;

  char int_p_sep_by_space;

  char int_n_cs_precedes;

  char int_n_sep_by_space;






  char int_p_sign_posn;
  char int_n_sign_posn;
# 119 "/usr/include/locale.h" 3
};



extern char *setlocale (int __category, __const char *__locale) throw ();


extern struct lconv *localeconv (void) throw ();
# 141 "/usr/include/locale.h" 3
# 1 "/usr/include/xlocale.h" 1 3
# 142 "/usr/include/locale.h" 2 3







extern __locale_t __newlocale (int __category_mask, __const char *__locale,
                               __locale_t __base) throw ();



extern __locale_t __duplocale (__locale_t __dataset) throw ();



extern void __freelocale (__locale_t __dataset) throw ();


}
# 39 "/usr/local/include/g++-v3/bits/std_clocale.h" 2 3





namespace std
{
  using ::lconv;
  using ::setlocale;
  using ::localeconv;
}
# 37 "/usr/local/include/g++-v3/bits/locale_facets.tcc" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_cstdlib.h" 1 3
# 38 "/usr/local/include/g++-v3/bits/locale_facets.tcc" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_limits.h" 1 3
# 42 "/usr/local/include/g++-v3/bits/std_limits.h" 3

# 1 "/usr/local/include/g++-v3/i686-pc-linux-gnu/bits/c++config.h" 1 3
# 44 "/usr/local/include/g++-v3/bits/std_limits.h" 2 3
# 871 "/usr/local/include/g++-v3/bits/std_limits.h" 3
namespace std
{
  enum float_round_style
  {
    round_indeterminate = -1,
    round_toward_zero = 0,
    round_to_nearest = 1,
    round_toward_infinity = 2,
    round_toward_neg_infinity = 3
  };

  enum float_denorm_style
  {
    denorm_indeterminate = -1,
    denorm_absent = 0,
    denorm_present = 1
  };




  template<typename _Tp>
    struct numeric_limits
    {
      static const bool is_specialized = false;

      static _Tp min() throw() { return static_cast<_Tp>(0); }
      static _Tp max() throw() { return static_cast<_Tp>(0); }

      static const int digits = 0;
      static const int digits10 = 0;
      static const bool is_signed = false;
      static const bool is_integer = false;
      static const bool is_exact = false;
      static const int radix = 0;

      static _Tp epsilon() throw() { return static_cast<_Tp>(0); }
      static _Tp round_error() throw() { return static_cast<_Tp>(0); }

      static const int min_exponent = 0;
      static const int min_exponent10 = 0;
      static const int max_exponent = 0;
      static const int max_exponent10 = 0;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm = denorm_absent;
      static const bool has_denorm_loss = false;

      static _Tp infinity() throw() { return static_cast<_Tp>(0); }
      static _Tp quiet_NaN() throw() { return static_cast<_Tp>(0); }
      static _Tp signaling_NaN() throw() { return static_cast<_Tp>(0); }
      static _Tp denorm_min() throw() { return static_cast<_Tp>(0); }

      static const bool is_iec559 = false;
      static const bool is_bounded = false;
      static const bool is_modulo = false;

      static const bool traps = false;
      static const bool tinyness_before = false;
      static const float_round_style round_style = round_toward_zero;
    };

  template<typename _Tp>
    const bool
    numeric_limits<_Tp>::is_specialized;

  template<typename _Tp>
    const int
    numeric_limits<_Tp>::digits;

  template<typename _Tp>
    const int
    numeric_limits<_Tp>::digits10;

  template<typename _Tp>
    const bool
    numeric_limits<_Tp>::is_signed;

  template<typename _Tp>
    const bool
    numeric_limits<_Tp>::is_integer;

  template<typename _Tp>
    const bool
    numeric_limits<_Tp>::is_exact;

  template<typename _Tp>
    const int
    numeric_limits<_Tp>::radix;

  template<typename _Tp>
    const int
    numeric_limits<_Tp>::min_exponent;

  template<typename _Tp>
    const int
    numeric_limits<_Tp>::min_exponent10;

  template<typename _Tp>
    const int
    numeric_limits<_Tp>::max_exponent;

  template<typename _Tp>
    const int
    numeric_limits<_Tp>::max_exponent10;

  template<typename _Tp>
    const bool
    numeric_limits<_Tp>::has_infinity;

  template<typename _Tp>
    const bool
    numeric_limits<_Tp>::has_quiet_NaN;

  template<typename _Tp>
    const bool
    numeric_limits<_Tp>::has_signaling_NaN;

  template<typename _Tp>
    const float_denorm_style
    numeric_limits<_Tp>::has_denorm;

  template<typename _Tp>
    const bool
    numeric_limits<_Tp>::has_denorm_loss;

  template<typename _Tp>
    const bool
    numeric_limits<_Tp>::is_iec559;

  template<typename _Tp>
    const bool
    numeric_limits<_Tp>::is_bounded;

  template<typename _Tp>
    const bool
    numeric_limits<_Tp>::is_modulo;

  template<typename _Tp>
    const bool
    numeric_limits<_Tp>::traps;

  template<typename _Tp>
    const bool
    numeric_limits<_Tp>::tinyness_before;

  template<typename _Tp>
    const float_round_style
    numeric_limits<_Tp>::round_style;




  template<>
    struct numeric_limits<bool>
    {
      static const bool is_specialized = true;

      static bool min() throw()
      { return false; }

      static bool max() throw()
      { return true; }

      static const int digits = 8;
      static const int digits10 = 1;
      static const bool is_signed = false;
      static const bool is_integer = true;
      static const bool is_exact = true;
      static const int radix = 2;
      static bool epsilon() throw()
      { return false; }
      static bool round_error() throw()
      { return false; }

      static const int min_exponent = 0;
      static const int min_exponent10 = 0;
      static const int max_exponent = 0;
      static const int max_exponent10 = 0;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm = denorm_absent;
      static const bool has_denorm_loss = false;

      static bool infinity() throw()
      { return false; }
      static bool quiet_NaN() throw()
      { return false; }
      static bool signaling_NaN() throw()
      { return false; }
      static bool denorm_min() throw()
      { return false; }

      static const bool is_iec559 = true;
      static const bool is_bounded = true;
      static const bool is_modulo = true;




      static const bool traps = true
               || true;
      static const bool tinyness_before = false;
      static const float_round_style round_style = round_toward_zero;
    };



  template<>
    struct numeric_limits<char>
    {
      static const bool is_specialized = true;

      static char min() throw()
      { return (char)(-127 - 1); }
      static char max() throw()
      { return (char)127; }

      static const int digits = 7;
      static const int digits10 = 7;
      static const bool is_signed = true;
      static const bool is_integer = true;
      static const bool is_exact = true;
      static const int radix = 2;
      static char epsilon() throw()
      { return char(); }
      static char round_error() throw()
      { return char(); }

      static const int min_exponent = 0;
      static const int min_exponent10 = 0;
      static const int max_exponent = 0;
      static const int max_exponent10 = 0;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm = denorm_absent;
      static const bool has_denorm_loss = false;

      static char infinity() throw()
      { return char(); }
      static char quiet_NaN() throw()
      { return char(); }
      static char signaling_NaN() throw()
      { return char(); }
      static char denorm_min() throw()
      { return static_cast<char>(0); }

      static const bool is_iec559 = false;
      static const bool is_bounded = true;
      static const bool is_modulo = false;

      static const bool traps = true;
      static const bool tinyness_before = false;
      static const float_round_style round_style = round_toward_zero;
    };
# 1141 "/usr/local/include/g++-v3/bits/std_limits.h" 3
  template<>
  struct numeric_limits<signed char>
    {
      static const bool is_specialized = true;

      static signed char min() throw()
      { return (-127 - 1); }
      static signed char max() throw()
      { return 127; }

      static const int digits = 7;
      static const int digits10 = 3;
      static const bool is_signed = true;
      static const bool is_integer = true;
      static const bool is_exact = true;
      static const int radix = 2;
      static signed char epsilon() throw()
      { return 0; }
      static signed char round_error() throw()
      { return 0; }

      static const int min_exponent = 0;
      static const int min_exponent10 = 0;
      static const int max_exponent = 0;
      static const int max_exponent10 = 0;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm = denorm_absent;
      static const bool has_denorm_loss = false;

      static signed char infinity() throw()
      { return static_cast<signed char>(0); }
      static signed char quiet_NaN() throw()
      { return static_cast<signed char>(0); }
      static signed char signaling_NaN() throw()
      { return static_cast<signed char>(0); }
      static signed char denorm_min() throw()
      { return static_cast<signed char>(0); }

      static const bool is_iec559 = false;
      static const bool is_bounded = true;
      static const bool is_modulo = false;

      static const bool traps = true;
      static const bool tinyness_before = false;
      static const float_round_style round_style = round_toward_zero;
    };







  template<>
    struct numeric_limits<unsigned char>
    {
      static const bool is_specialized = true;

      static unsigned char min() throw()
      { return 0; }
      static unsigned char max() throw()
      { return (127 * 2 + 1); }

      static const int digits = 8;
      static const int digits10 = 3;
      static const bool is_signed = false;
      static const bool is_integer = true;
      static const bool is_exact = true;
      static const int radix = 2;
      static unsigned char epsilon() throw()
      { return 0; }
      static unsigned char round_error() throw()
      { return 0; }

      static const int min_exponent = 0;
      static const int min_exponent10 = 0;
      static const int max_exponent = 0;
      static const int max_exponent10 = 0;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm = denorm_absent;
      static const bool has_denorm_loss = false;

      static unsigned char infinity() throw()
      { return static_cast<unsigned char>(0); }
      static unsigned char quiet_NaN() throw()
      { return static_cast<unsigned char>(0); }
      static unsigned char signaling_NaN() throw()
      { return static_cast<unsigned char>(0); }
      static unsigned char denorm_min() throw()
      { return static_cast<unsigned char>(0); }

      static const bool is_iec559 = false;
      static const bool is_bounded = true;
      static const bool is_modulo = true;

      static const bool traps = true;
      static const bool tinyness_before = false;
      static const float_round_style round_style = round_toward_zero;
    };






  template<>
    struct numeric_limits<wchar_t>
    {
      static const bool is_specialized = true;

      static wchar_t min() throw()
      { return (wchar_t)(-2147483647L - 1); }
      static wchar_t max() throw()
      { return (wchar_t)2147483647L; }

      static const int digits = 31;
      static const int digits10 = 10;
      static const bool is_signed = true;
      static const bool is_integer = true;
      static const bool is_exact = true;
      static const int radix = 2;
      static wchar_t epsilon() throw()
      { return 0; }
      static wchar_t round_error() throw()
      { return 0; }

      static const int min_exponent = 0;
      static const int min_exponent10 = 0;
      static const int max_exponent = 0;
      static const int max_exponent10 = 0;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm = denorm_absent;
      static const bool has_denorm_loss = false;

      static wchar_t infinity() throw()
      { return wchar_t(); }
      static wchar_t quiet_NaN() throw()
      { return wchar_t(); }
      static wchar_t signaling_NaN() throw()
      { return wchar_t(); }
      static wchar_t denorm_min() throw()
      { return wchar_t(); }

      static const bool is_iec559 = false;
      static const bool is_bounded = true;
      static const bool is_modulo = false;

      static const bool traps = true;
      static const bool tinyness_before = false;
      static const float_round_style round_style = round_toward_zero;
    };
# 1309 "/usr/local/include/g++-v3/bits/std_limits.h" 3
  template<>
    struct numeric_limits<short>
    {
      static const bool is_specialized = true;

      static short min() throw()
      { return (-32767 - 1); }
      static short max() throw()
      { return 32767; }

      static const int digits = 15;
      static const int digits10 = 5;
      static const bool is_signed = true;
      static const bool is_integer = true;
      static const bool is_exact = true;
      static const int radix = 2;
      static short epsilon() throw()
      { return 0; }
      static short round_error() throw()
      { return 0; }

      static const int min_exponent = 0;
      static const int min_exponent10 = 0;
      static const int max_exponent = 0;
      static const int max_exponent10 = 0;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm = denorm_absent;
      static const bool has_denorm_loss = false;

      static short infinity() throw()
      { return short(); }
      static short quiet_NaN() throw()
      { return short(); }
      static short signaling_NaN() throw()
      { return short(); }
      static short denorm_min() throw()
      { return short(); }

      static const bool is_iec559 = true;
      static const bool is_bounded = true;
      static const bool is_modulo = false;

      static const bool traps = true;
      static const bool tinyness_before = false;
      static const float_round_style round_style = round_toward_zero;
    };







  template<>
    struct numeric_limits<unsigned short>
    {
      static const bool is_specialized = true;

      static unsigned short min() throw()
      { return 0; }
      static unsigned short max() throw()
      { return (32767 * 2 + 1); }

      static const int digits = 16;
      static const int digits10 = 5;
      static const bool is_signed = false;
      static const bool is_integer = true;
      static const bool is_exact = true;
      static const int radix = 2;
      static unsigned short epsilon() throw()
      { return 0; }
      static unsigned short round_error() throw()
      { return 0; }

      static const int min_exponent = 0;
      static const int min_exponent10 = 0;
      static const int max_exponent = 0;
      static const int max_exponent10 = 0;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm = denorm_absent;
      static const bool has_denorm_loss = false;

      static unsigned short infinity() throw()
      { return static_cast<unsigned short>(0); }
      static unsigned short quiet_NaN() throw()
      { return static_cast<unsigned short>(0); }
      static unsigned short signaling_NaN() throw()
      { return static_cast<unsigned short>(0); }
      static unsigned short denorm_min() throw()
      { return static_cast<unsigned short>(0); }

      static const bool is_iec559 = true;
      static const bool is_bounded = true;
      static const bool is_modulo = true;

      static const bool traps = true;
      static const bool tinyness_before = false;
      static const float_round_style round_style = round_toward_zero;
    };






  template<>
    struct numeric_limits<int>
    {
      static const bool is_specialized = true;

      static int min() throw()
      { return (int)(-2147483647L - 1); }
      static int max() throw()
      { return (int)2147483647L; }

      static const int digits = 31;
      static const int digits10 = 10;
      static const bool is_signed = true;
      static const bool is_integer = true;
      static const bool is_exact = true;
      static const int radix = 2;
      static int epsilon() throw()
      { return 0; }
      static int round_error() throw()
      { return 0; }

      static const int min_exponent = 0;
      static const int min_exponent10 = 0;
      static const int max_exponent = 0;
      static const int max_exponent10 = 0;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm = denorm_absent;
      static const bool has_denorm_loss = false;

      static int infinity() throw()
      { return static_cast<int>(0); }
      static int quiet_NaN() throw()
      { return static_cast<int>(0); }
      static int signaling_NaN() throw()
      { return static_cast<int>(0); }
      static int denorm_min() throw()
      { return static_cast<int>(0); }

      static const bool is_iec559 = true;
      static const bool is_bounded = true;
      static const bool is_modulo = false;

      static const bool traps = true;
      static const bool tinyness_before = false;
      static const float_round_style round_style = round_toward_zero;
    };







  template<>
    struct numeric_limits<unsigned int>
    {
      static const bool is_specialized = true;

      static unsigned int min() throw()
      { return 0; }
          static unsigned int max() throw()
      { return (unsigned)(2147483647L * 2U + 1); }

      static const int digits = 32;
      static const int digits10 = 10;
      static const bool is_signed = false;
      static const bool is_integer = true;
      static const bool is_exact = true;
      static const int radix = 2;
      static unsigned int epsilon() throw()
      { return 0; }
      static unsigned int round_error() throw()
      { return 0; }

      static const int min_exponent = 0;
      static const int min_exponent10 = 0;
      static const int max_exponent = 0;
      static const int max_exponent10 = 0;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm = denorm_absent;
      static const bool has_denorm_loss = false;

      static unsigned int infinity() throw()
      { return static_cast<unsigned int>(0); }
      static unsigned int quiet_NaN() throw()
      { return static_cast<unsigned int>(0); }
      static unsigned int signaling_NaN() throw()
      { return static_cast<unsigned int>(0); }
      static unsigned int denorm_min() throw()
      { return static_cast<unsigned int>(0); }

      static const bool is_iec559 = true;
      static const bool is_bounded = true;
      static const bool is_modulo = true;

      static const bool traps = true;
      static const bool tinyness_before = false;
      static const float_round_style round_style = round_toward_zero;
    };






  template<>
    struct numeric_limits<long>
    {
      static const bool is_specialized = true;

      static long min() throw()
      { return (-2147483647L - 1); }
      static long max() throw()
      { return 2147483647L; }

      static const int digits = 31;
      static const int digits10 = 10;
      static const bool is_signed = true;
      static const bool is_integer = true;
      static const bool is_exact = true;
      static const int radix = 2;
      static long epsilon() throw()
      { return 0; }
      static long round_error() throw()
      { return 0; }

      static const int min_exponent = 0;
      static const int min_exponent10 = 0;
      static const int max_exponent = 0;
      static const int max_exponent10 = 0;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm = denorm_absent;
      static const bool has_denorm_loss = false;

      static long infinity() throw()
      { return static_cast<long>(0); }
      static long quiet_NaN() throw()
      { return static_cast<long>(0); }
      static long signaling_NaN() throw()
      { return static_cast<long>(0); }
      static long denorm_min() throw()
      { return static_cast<long>(0); }

      static const bool is_iec559 = true;
      static const bool is_bounded = true;
      static const bool is_modulo = false;

      static const bool traps = true;
      static const bool tinyness_before = false;
      static const float_round_style round_style = round_toward_zero;
    };







  template<>
    struct numeric_limits<unsigned long>
    {
      static const bool is_specialized = true;

      static unsigned long min() throw()
      { return 0; }
      static unsigned long max() throw()
      { return (2147483647L * 2U + 1); }

      static const int digits = 32;
      static const int digits10 = 10;
      static const bool is_signed = false;
      static const bool is_integer = true;
      static const bool is_exact = true;
      static const int radix = 2;
      static unsigned long epsilon() throw()
      { return 0; }
      static unsigned long round_error() throw()
      { return 0; }

      static const int min_exponent = 0;
      static const int min_exponent10 = 0;
      static const int max_exponent = 0;
      static const int max_exponent10 = 0;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm = denorm_absent;
      static const bool has_denorm_loss = false;

      static unsigned long infinity() throw()
      { return static_cast<unsigned long>(0); }
      static unsigned long quiet_NaN() throw()
      { return static_cast<unsigned long>(0); }
      static unsigned long signaling_NaN() throw()
      { return static_cast<unsigned long>(0); }
      static unsigned long denorm_min() throw()
      { return static_cast<unsigned long>(0); }

      static const bool is_iec559 = true;
      static const bool is_bounded = true;
      static const bool is_modulo = true;

      static const bool traps = true;
      static const bool tinyness_before = false;
      static const float_round_style round_style = round_toward_zero;
    };
# 1644 "/usr/local/include/g++-v3/bits/std_limits.h" 3
  template<>
    struct numeric_limits<long long>
    {
      static const bool is_specialized = true;

      static long long min() throw()
      { return (-9223372036854775807LL - 1); }
      static long long max() throw()
      { return 9223372036854775807LL; }

      static const int digits = 63;
      static const int digits10 = 19;
      static const bool is_signed = true;
      static const bool is_integer = true;
      static const bool is_exact = true;
      static const int radix = 2;
      static long long epsilon() throw()
      { return 0; }
      static long long round_error() throw()
      { return 0; }

      static const int min_exponent = 0;
      static const int min_exponent10 = 0;
      static const int max_exponent = 0;
      static const int max_exponent10 = 0;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm = denorm_absent;
      static const bool has_denorm_loss = false;

      static long long infinity() throw()
      { return static_cast<long long>(0); }
      static long long quiet_NaN() throw()
      { return static_cast<long long>(0); }
      static long long signaling_NaN() throw()
      { return static_cast<long long>(0); }
      static long long denorm_min() throw()
      { return static_cast<long long>(0); }

      static const bool is_iec559 = true;
      static const bool is_bounded = true;
      static const bool is_modulo = false;

      static const bool traps = true;
      static const bool tinyness_before = false;
      static const float_round_style round_style = round_toward_zero;
    };







  template<>
    struct numeric_limits<unsigned long long>
    {
      static const bool is_specialized = true;

      static unsigned long long min() throw()
      { return 0; }
      static unsigned long long max() throw()
      { return (9223372036854775807LL * 2ULL + 1); }

      static const int digits = 64;
      static const int digits10 = 19;
      static const bool is_signed = false;
      static const bool is_integer = true;
      static const bool is_exact = true;
      static const int radix = 2;
      static unsigned long long epsilon() throw()
      { return 0; }
      static unsigned long long round_error() throw()
      { return 0; }

      static const int min_exponent = 0;
      static const int min_exponent10 = 0;
      static const int max_exponent = 0;
      static const int max_exponent10 = 0;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm = denorm_absent;
      static const bool has_denorm_loss = false;

      static unsigned long long infinity() throw()
      { return static_cast<unsigned long long>(0); }
      static unsigned long long quiet_NaN() throw()
      { return static_cast<unsigned long long>(0); }
      static unsigned long long signaling_NaN() throw()
      { return static_cast<unsigned long long>(0); }
      static unsigned long long denorm_min() throw()
      { return static_cast<unsigned long long>(0); }

      static const bool is_iec559 = true;
      static const bool is_bounded = true;
      static const bool is_modulo = true;

      static const bool traps = true;
      static const bool tinyness_before = false;
      static const float_round_style round_style = round_toward_zero;
    };
# 1758 "/usr/local/include/g++-v3/bits/std_limits.h" 3
  template<>
    struct numeric_limits<float>
    {
      static const bool is_specialized = true;

      static float min() throw()
      { return 1.17549435e-38F; }
      static float max() throw()
      { return 3.40282347e+38F; }

      static const int digits = 24;
      static const int digits10 = 6;
      static const bool is_signed = true;
      static const bool is_integer = false;
      static const bool is_exact = false;
      static const int radix = 2;
      static float epsilon() throw()
      { return 1.19209290e-07F; }
      static float round_error() throw()
      { return 1.0F; }

      static const int min_exponent = -125;
      static const int min_exponent10 = -37;
      static const int max_exponent = 128;
      static const int max_exponent10 = 38;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm = denorm_absent;
      static const bool has_denorm_loss = false;

      static float infinity() throw()
      { return 0.0F; }
      static float quiet_NaN() throw()
      { return 0.0F; }
      static float signaling_NaN() throw()
      { return 0.0F; }
      static float denorm_min() throw()
      { return 0.0F; }

      static const bool is_iec559 = false;
      static const bool is_bounded = true;
      static const bool is_modulo = false;

      static const bool traps = false;
      static const bool tinyness_before = false;
      static const float_round_style round_style = round_toward_zero;
    };
# 1834 "/usr/local/include/g++-v3/bits/std_limits.h" 3
  template<>
    struct numeric_limits<double>
    {
      static const bool is_specialized = true;

      static double min() throw()
      { return 2.2250738585072014e-308; }
      static double max() throw()
      { return 1.7976931348623157e+308; }

      static const int digits = 53;
      static const int digits10 = 15;
      static const bool is_signed = true;
      static const bool is_integer = false;
      static const bool is_exact = false;
      static const int radix = 2;
      static double epsilon() throw()
      { return 2.2204460492503131e-16; }
      static double round_error() throw()
      { return 1.0; }

      static const int min_exponent = -1021;
      static const int min_exponent10 = -307;
      static const int max_exponent = 1024;
      static const int max_exponent10 = 308;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN = false;
      static const float_denorm_style has_denorm =
              denorm_absent;;
      static const bool has_denorm_loss = false;;

      static double infinity() throw()
      { return 0.0; }
      static double quiet_NaN() throw()
      { return 0.0; }
      static double signaling_NaN() throw()
      { return 0.0; }
      static double denorm_min() throw()
      { return 0.0; }

      static const bool is_iec559 = false;
      static const bool is_bounded = true;
      static const bool is_modulo = false;

      static const bool traps = false;
      static const bool tinyness_before = false;
      static const float_round_style round_style =
              round_toward_zero;
    };
# 1913 "/usr/local/include/g++-v3/bits/std_limits.h" 3
  template<>
    struct numeric_limits<long double>
    {
      static const bool is_specialized = true;

      static long double min() throw()
      { return 3.36210314311209350626e-4932L; }
      static long double max() throw()
      { return 1.18973149535723176502e+4932L; }

      static const int digits = 64;
      static const int digits10 = 18;
      static const bool is_signed = true;
      static const bool is_integer = false;
      static const bool is_exact = false;
      static const int radix = 2;
      static long double epsilon() throw()
      { return 1.08420217248550443401e-19L; }
      static long double round_error() throw()
      { return 1.0L; }

      static const int min_exponent = -16381;
      static const int min_exponent10 = -4931;
      static const int max_exponent = 16384;
      static const int max_exponent10 = 4932;

      static const bool has_infinity = false;
      static const bool has_quiet_NaN = false;
      static const bool has_signaling_NaN =
                false;
      static const float_denorm_style has_denorm =
                denorm_absent;
      static const bool has_denorm_loss =
                false;

      static long double infinity() throw()
      { return 0.0L; }
      static long double quiet_NaN() throw()
      { return 0.0L; }
      static long double signaling_NaN() throw()
      { return 0.0L; }
      static long double denorm_min() throw()
      { return 0.0L; }

      static const bool is_iec559 = false;
      static const bool is_bounded = false;
      static const bool is_modulo = false;

      static const bool traps = false;
      static const bool tinyness_before = false;
      static const float_round_style round_style =
                    round_toward_zero;
    };
# 1993 "/usr/local/include/g++-v3/bits/std_limits.h" 3
}
# 39 "/usr/local/include/g++-v3/bits/locale_facets.tcc" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_memory.h" 1 3
# 40 "/usr/local/include/g++-v3/bits/locale_facets.tcc" 2 3
# 1 "/usr/local/include/g++-v3/bits/sbuf_iter.h" 1 3
# 41 "/usr/local/include/g++-v3/bits/locale_facets.tcc" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_cctype.h" 1 3
# 42 "/usr/local/include/g++-v3/bits/locale_facets.tcc" 2 3
# 1 "/usr/local/include/g++-v3/typeinfo" 1 3
# 37 "/usr/local/include/g++-v3/typeinfo" 3
# 1 "/usr/local/include/g++-v3/exception" 1 3
# 38 "/usr/local/include/g++-v3/typeinfo" 2 3

extern "C++" {

namespace __cxxabiv1
{
  class __class_type_info;
}
# 54 "/usr/local/include/g++-v3/typeinfo" 3
namespace std
{



  class type_info
  {
  public:




    virtual ~type_info();

  private:

    type_info& operator=(const type_info&);
    type_info(const type_info&);

  protected:
    const char *__name;

  protected:
    explicit type_info(const char *__n): __name(__n) { }

  public:



    const char* name() const
    { return __name; }
# 97 "/usr/local/include/g++-v3/typeinfo" 3
    bool before(const type_info& __arg) const
    { return __name < __arg.__name; }
    bool operator==(const type_info& __arg) const
    { return __name == __arg.__name; }

    bool operator!=(const type_info& __arg) const
    { return !operator==(__arg); }


  public:

    virtual bool __is_pointer_p() const;

    virtual bool __is_function_p() const;







    virtual bool __do_catch(const type_info *__thr_type, void **__thr_obj,
                            unsigned __outer) const;


    virtual bool __do_upcast(const __cxxabiv1::__class_type_info *__target,
                             void **__obj_ptr) const;
  };



  class bad_cast : public exception
  {
  public:
    bad_cast() throw() { }
    virtual ~bad_cast() throw();
  };


  class bad_typeid : public exception
  {
  public:
    bad_typeid () throw() { }
    virtual ~bad_typeid () throw();
  };
}

}
# 43 "/usr/local/include/g++-v3/bits/locale_facets.tcc" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_vector.h" 1 3
# 60 "/usr/local/include/g++-v3/bits/std_vector.h" 3

# 1 "/usr/local/include/g++-v3/bits/functexcept.h" 1 3
# 34 "/usr/local/include/g++-v3/bits/functexcept.h" 3
# 1 "/usr/local/include/g++-v3/exception_defines.h" 1 3
# 35 "/usr/local/include/g++-v3/bits/functexcept.h" 2 3

namespace std
{

  void
  __throw_bad_exception(void);


  void
  __throw_bad_alloc(void);


  void
  __throw_bad_cast(void);

  void
  __throw_bad_typeid(void);


  void
  __throw_logic_error(const char* __s);

  void
  __throw_domain_error(const char* __s);

  void
  __throw_invalid_argument(const char* __s);

  void
  __throw_length_error(const char* __s);

  void
  __throw_out_of_range(const char* __s);

  void
  __throw_runtime_error(const char* __s);

  void
  __throw_range_error(const char* __s);

  void
  __throw_overflow_error(const char* __s);

  void
  __throw_underflow_error(const char* __s);


  void
  __throw_ios_failure(const char* __s);
}
# 62 "/usr/local/include/g++-v3/bits/std_vector.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/stl_algobase.h" 1 3
# 63 "/usr/local/include/g++-v3/bits/std_vector.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/stl_alloc.h" 1 3
# 64 "/usr/local/include/g++-v3/bits/std_vector.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/stl_construct.h" 1 3
# 65 "/usr/local/include/g++-v3/bits/std_vector.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/stl_uninitialized.h" 1 3
# 66 "/usr/local/include/g++-v3/bits/std_vector.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/stl_vector.h" 1 3
# 63 "/usr/local/include/g++-v3/bits/stl_vector.h" 3
# 1 "/usr/local/include/g++-v3/bits/stl_iterator_base_funcs.h" 1 3
# 64 "/usr/local/include/g++-v3/bits/stl_vector.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/functexcept.h" 1 3
# 34 "/usr/local/include/g++-v3/bits/functexcept.h" 3
# 1 "/usr/local/include/g++-v3/exception_defines.h" 1 3
# 35 "/usr/local/include/g++-v3/bits/functexcept.h" 2 3

namespace std
{

  void
  __throw_bad_exception(void);


  void
  __throw_bad_alloc(void);


  void
  __throw_bad_cast(void);

  void
  __throw_bad_typeid(void);


  void
  __throw_logic_error(const char* __s);

  void
  __throw_domain_error(const char* __s);

  void
  __throw_invalid_argument(const char* __s);

  void
  __throw_length_error(const char* __s);

  void
  __throw_out_of_range(const char* __s);

  void
  __throw_runtime_error(const char* __s);

  void
  __throw_range_error(const char* __s);

  void
  __throw_overflow_error(const char* __s);

  void
  __throw_underflow_error(const char* __s);


  void
  __throw_ios_failure(const char* __s);
}
# 65 "/usr/local/include/g++-v3/bits/stl_vector.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/concept_check.h" 1 3
# 66 "/usr/local/include/g++-v3/bits/stl_vector.h" 2 3

namespace std
{
# 77 "/usr/local/include/g++-v3/bits/stl_vector.h" 3
template <class _Tp, class _Allocator, bool _IsStatic>
class _Vector_alloc_base {
public:
  typedef typename _Alloc_traits<_Tp, _Allocator>::allocator_type
          allocator_type;
  allocator_type get_allocator() const { return _M_data_allocator; }

  _Vector_alloc_base(const allocator_type& __a)
    : _M_data_allocator(__a), _M_start(0), _M_finish(0), _M_end_of_storage(0)
  {}

protected:
  allocator_type _M_data_allocator;
  _Tp* _M_start;
  _Tp* _M_finish;
  _Tp* _M_end_of_storage;

  _Tp* _M_allocate(size_t __n)
    { return _M_data_allocator.allocate(__n); }
  void _M_deallocate(_Tp* __p, size_t __n)
    { if (__p) _M_data_allocator.deallocate(__p, __n); }
};



template <class _Tp, class _Allocator>
class _Vector_alloc_base<_Tp, _Allocator, true> {
public:
  typedef typename _Alloc_traits<_Tp, _Allocator>::allocator_type
          allocator_type;
  allocator_type get_allocator() const { return allocator_type(); }

  _Vector_alloc_base(const allocator_type&)
    : _M_start(0), _M_finish(0), _M_end_of_storage(0)
  {}

protected:
  _Tp* _M_start;
  _Tp* _M_finish;
  _Tp* _M_end_of_storage;

  typedef typename _Alloc_traits<_Tp, _Allocator>::_Alloc_type _Alloc_type;
  _Tp* _M_allocate(size_t __n)
    { return _Alloc_type::allocate(__n); }
  void _M_deallocate(_Tp* __p, size_t __n)
    { _Alloc_type::deallocate(__p, __n);}
};

template <class _Tp, class _Alloc>
struct _Vector_base
  : public _Vector_alloc_base<_Tp, _Alloc,
                              _Alloc_traits<_Tp, _Alloc>::_S_instanceless>
{
  typedef _Vector_alloc_base<_Tp, _Alloc,
                             _Alloc_traits<_Tp, _Alloc>::_S_instanceless>
          _Base;
  typedef typename _Base::allocator_type allocator_type;

  _Vector_base(const allocator_type& __a) : _Base(__a) {}
  _Vector_base(size_t __n, const allocator_type& __a) : _Base(__a) {
    _M_start = _M_allocate(__n);
    _M_finish = _M_start;
    _M_end_of_storage = _M_start + __n;
  }

  ~_Vector_base() { _M_deallocate(_M_start, _M_end_of_storage - _M_start); }
};


template <class _Tp, class _Alloc = allocator<_Tp> >
class vector : protected _Vector_base<_Tp, _Alloc>
{

                                                      ;

private:
  typedef _Vector_base<_Tp, _Alloc> _Base;
  typedef vector<_Tp, _Alloc> vector_type;
public:
  typedef _Tp value_type;
  typedef value_type* pointer;
  typedef const value_type* const_pointer;
  typedef __normal_iterator<pointer, vector_type> iterator;
  typedef __normal_iterator<const_pointer, vector_type> const_iterator;
  typedef value_type& reference;
  typedef const value_type& const_reference;
  typedef size_t size_type;
  typedef ptrdiff_t difference_type;

  typedef typename _Base::allocator_type allocator_type;
  allocator_type get_allocator() const { return _Base::get_allocator(); }

  typedef reverse_iterator<const_iterator> const_reverse_iterator;
  typedef reverse_iterator<iterator> reverse_iterator;

protected:
  using _Base::_M_allocate;
  using _Base::_M_deallocate;
  using _Base::_M_start;
  using _Base::_M_finish;
  using _Base::_M_end_of_storage;

protected:
  void _M_insert_aux(iterator __position, const _Tp& __x);
  void _M_insert_aux(iterator __position);

public:
  iterator begin() { return iterator (_M_start); }
  const_iterator begin() const
    { return const_iterator (_M_start); }
  iterator end() { return iterator (_M_finish); }
  const_iterator end() const { return const_iterator (_M_finish); }

  reverse_iterator rbegin()
    { return reverse_iterator(end()); }
  const_reverse_iterator rbegin() const
    { return const_reverse_iterator(end()); }
  reverse_iterator rend()
    { return reverse_iterator(begin()); }
  const_reverse_iterator rend() const
    { return const_reverse_iterator(begin()); }

  size_type size() const
    { return size_type(end() - begin()); }
  size_type max_size() const
    { return size_type(-1) / sizeof(_Tp); }
  size_type capacity() const
    { return size_type(const_iterator(_M_end_of_storage) - begin()); }
  bool empty() const
    { return begin() == end(); }

  reference operator[](size_type __n) { return *(begin() + __n); }
  const_reference operator[](size_type __n) const { return *(begin() + __n); }

  void _M_range_check(size_type __n) const {
    if (__n >= this->size())
      __throw_out_of_range("vector");
  }

  reference at(size_type __n)
    { _M_range_check(__n); return (*this)[__n]; }
  const_reference at(size_type __n) const
    { _M_range_check(__n); return (*this)[__n]; }

  explicit vector(const allocator_type& __a = allocator_type())
    : _Base(__a) {}

  vector(size_type __n, const _Tp& __value,
         const allocator_type& __a = allocator_type())
    : _Base(__n, __a)
    { _M_finish = uninitialized_fill_n(_M_start, __n, __value); }

  explicit vector(size_type __n)
    : _Base(__n, allocator_type())
    { _M_finish = uninitialized_fill_n(_M_start, __n, _Tp()); }

  vector(const vector<_Tp, _Alloc>& __x)
    : _Base(__x.size(), __x.get_allocator())
    { _M_finish = uninitialized_copy(__x.begin(), __x.end(), _M_start); }


  template <class _InputIterator>
  vector(_InputIterator __first, _InputIterator __last,
         const allocator_type& __a = allocator_type()) : _Base(__a) {
    typedef typename _Is_integer<_InputIterator>::_Integral _Integral;
    _M_initialize_aux(__first, __last, _Integral());
  }

  template <class _Integer>
  void _M_initialize_aux(_Integer __n, _Integer __value, __true_type) {
    _M_start = _M_allocate(__n);
    _M_end_of_storage = _M_start + __n;
    _M_finish = uninitialized_fill_n(_M_start, __n, __value);
  }

  template <class _InputIterator>
  void _M_initialize_aux(_InputIterator __first, _InputIterator __last,
                         __false_type) {
    _M_range_initialize(__first, __last, __iterator_category(__first));
  }

  ~vector() { destroy(_M_start, _M_finish); }

  vector<_Tp, _Alloc>& operator=(const vector<_Tp, _Alloc>& __x);
  void reserve(size_type __n) {
    if (capacity() < __n) {
      const size_type __old_size = size();
      pointer __tmp = _M_allocate_and_copy(__n, _M_start, _M_finish);
      destroy(_M_start, _M_finish);
      _M_deallocate(_M_start, _M_end_of_storage - _M_start);
      _M_start = __tmp;
      _M_finish = __tmp + __old_size;
      _M_end_of_storage = _M_start + __n;
    }
  }






  void assign(size_type __n, const _Tp& __val) { _M_fill_assign(__n, __val); }
  void _M_fill_assign(size_type __n, const _Tp& __val);

  template <class _InputIterator>
  void assign(_InputIterator __first, _InputIterator __last) {
    typedef typename _Is_integer<_InputIterator>::_Integral _Integral;
    _M_assign_dispatch(__first, __last, _Integral());
  }

  template <class _Integer>
  void _M_assign_dispatch(_Integer __n, _Integer __val, __true_type)
    { _M_fill_assign((size_type) __n, (_Tp) __val); }

  template <class _InputIter>
  void _M_assign_dispatch(_InputIter __first, _InputIter __last, __false_type)
    { _M_assign_aux(__first, __last, __iterator_category(__first)); }

  template <class _InputIterator>
  void _M_assign_aux(_InputIterator __first, _InputIterator __last,
                     input_iterator_tag);

  template <class _ForwardIterator>
  void _M_assign_aux(_ForwardIterator __first, _ForwardIterator __last,
                     forward_iterator_tag);

  reference front() { return *begin(); }
  const_reference front() const { return *begin(); }
  reference back() { return *(end() - 1); }
  const_reference back() const { return *(end() - 1); }

  void push_back(const _Tp& __x) {
    if (_M_finish != _M_end_of_storage) {
      construct(_M_finish, __x);
      ++_M_finish;
    }
    else
      _M_insert_aux(end(), __x);
  }
  void push_back() {
    if (_M_finish != _M_end_of_storage) {
      construct(_M_finish);
      ++_M_finish;
    }
    else
      _M_insert_aux(end());
  }
  void swap(vector<_Tp, _Alloc>& __x) {
    std::swap(_M_start, __x._M_start);
    std::swap(_M_finish, __x._M_finish);
    std::swap(_M_end_of_storage, __x._M_end_of_storage);
  }

  iterator insert(iterator __position, const _Tp& __x) {
    size_type __n = __position - begin();
    if (_M_finish != _M_end_of_storage && __position == end()) {
      construct(_M_finish, __x);
      ++_M_finish;
    }
    else
      _M_insert_aux(iterator(__position), __x);
    return begin() + __n;
  }
  iterator insert(iterator __position) {
    size_type __n = __position - begin();
    if (_M_finish != _M_end_of_storage && __position == end()) {
      construct(_M_finish);
      ++_M_finish;
    }
    else
      _M_insert_aux(iterator(__position));
    return begin() + __n;
  }

  template <class _InputIterator>
  void insert(iterator __pos, _InputIterator __first, _InputIterator __last) {
    typedef typename _Is_integer<_InputIterator>::_Integral _Integral;
    _M_insert_dispatch(__pos, __first, __last, _Integral());
  }

  template <class _Integer>
  void _M_insert_dispatch(iterator __pos, _Integer __n, _Integer __val,
                          __true_type)
    { _M_fill_insert(__pos, (size_type) __n, (_Tp) __val); }

  template <class _InputIterator>
  void _M_insert_dispatch(iterator __pos,
                          _InputIterator __first, _InputIterator __last,
                          __false_type) {
    _M_range_insert(__pos, __first, __last, __iterator_category(__first));
  }

  void insert (iterator __pos, size_type __n, const _Tp& __x)
    { _M_fill_insert(__pos, __n, __x); }

  void _M_fill_insert (iterator __pos, size_type __n, const _Tp& __x);

  void pop_back() {
    --_M_finish;
    destroy(_M_finish);
  }
  iterator erase(iterator __position) {
    if (__position + 1 != end())
      copy(__position + 1, end(), __position);
    --_M_finish;
    destroy(_M_finish);
    return __position;
  }
  iterator erase(iterator __first, iterator __last) {
    iterator __i(copy(__last, end(), __first));
    destroy(__i, end());
    _M_finish = _M_finish - (__last - __first);
    return __first;
  }

  void resize(size_type __new_size, const _Tp& __x) {
    if (__new_size < size())
      erase(begin() + __new_size, end());
    else
      insert(end(), __new_size - size(), __x);
  }
  void resize(size_type __new_size) { resize(__new_size, _Tp()); }
  void clear() { erase(begin(), end()); }

protected:

  template <class _ForwardIterator>
  pointer _M_allocate_and_copy(size_type __n, _ForwardIterator __first,
                                               _ForwardIterator __last)
  {
    pointer __result = _M_allocate(__n);
    try {
      uninitialized_copy(__first, __last, __result);
      return __result;
    }
    catch(...) { _M_deallocate(__result, __n); throw; };
  }

  template <class _InputIterator>
  void _M_range_initialize(_InputIterator __first,
                           _InputIterator __last, input_iterator_tag)
  {
    for ( ; __first != __last; ++__first)
      push_back(*__first);
  }


  template <class _ForwardIterator>
  void _M_range_initialize(_ForwardIterator __first,
                           _ForwardIterator __last, forward_iterator_tag)
  {
    size_type __n = 0;
    distance(__first, __last, __n);
    _M_start = _M_allocate(__n);
    _M_end_of_storage = _M_start + __n;
    _M_finish = uninitialized_copy(__first, __last, _M_start);
  }

  template <class _InputIterator>
  void _M_range_insert(iterator __pos,
                       _InputIterator __first, _InputIterator __last,
                       input_iterator_tag);

  template <class _ForwardIterator>
  void _M_range_insert(iterator __pos,
                       _ForwardIterator __first, _ForwardIterator __last,
                       forward_iterator_tag);
};

template <class _Tp, class _Alloc>
inline bool
operator==(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
{
  return __x.size() == __y.size() &&
         equal(__x.begin(), __x.end(), __y.begin());
}

template <class _Tp, class _Alloc>
inline bool
operator<(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y)
{
  return lexicographical_compare(__x.begin(), __x.end(),
                                 __y.begin(), __y.end());
}

template <class _Tp, class _Alloc>
inline void swap(vector<_Tp, _Alloc>& __x, vector<_Tp, _Alloc>& __y)
{
  __x.swap(__y);
}

template <class _Tp, class _Alloc>
inline bool
operator!=(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y) {
  return !(__x == __y);
}

template <class _Tp, class _Alloc>
inline bool
operator>(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y) {
  return __y < __x;
}

template <class _Tp, class _Alloc>
inline bool
operator<=(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y) {
  return !(__y < __x);
}

template <class _Tp, class _Alloc>
inline bool
operator>=(const vector<_Tp, _Alloc>& __x, const vector<_Tp, _Alloc>& __y) {
  return !(__x < __y);
}

template <class _Tp, class _Alloc>
vector<_Tp,_Alloc>&
vector<_Tp,_Alloc>::operator=(const vector<_Tp, _Alloc>& __x)
{
  if (&__x != this) {
    const size_type __xlen = __x.size();
    if (__xlen > capacity()) {
      pointer __tmp = _M_allocate_and_copy(__xlen, __x.begin(), __x.end());
      destroy(_M_start, _M_finish);
      _M_deallocate(_M_start, _M_end_of_storage - _M_start);
      _M_start = __tmp;
      _M_end_of_storage = _M_start + __xlen;
    }
    else if (size() >= __xlen) {
      iterator __i(copy(__x.begin(), __x.end(), begin()));
      destroy(__i, end());
    }
    else {
      copy(__x.begin(), __x.begin() + size(), _M_start);
      uninitialized_copy(__x.begin() + size(), __x.end(), _M_finish);
    }
    _M_finish = _M_start + __xlen;
  }
  return *this;
}

template <class _Tp, class _Alloc>
void vector<_Tp, _Alloc>::_M_fill_assign(size_t __n, const value_type& __val)
{
  if (__n > capacity()) {
    vector<_Tp, _Alloc> __tmp(__n, __val, get_allocator());
    __tmp.swap(*this);
  }
  else if (__n > size()) {
    fill(begin(), end(), __val);
    _M_finish = uninitialized_fill_n(_M_finish, __n - size(), __val);
  }
  else
    erase(fill_n(begin(), __n, __val), end());
}

template <class _Tp, class _Alloc> template <class _InputIter>
void vector<_Tp, _Alloc>::_M_assign_aux(_InputIter __first, _InputIter __last,
                                        input_iterator_tag) {
  iterator __cur(begin());
  for ( ; __first != __last && __cur != end(); ++__cur, ++__first)
    *__cur = *__first;
  if (__first == __last)
    erase(__cur, end());
  else
    insert(end(), __first, __last);
}

template <class _Tp, class _Alloc> template <class _ForwardIter>
void
vector<_Tp, _Alloc>::_M_assign_aux(_ForwardIter __first, _ForwardIter __last,
                                   forward_iterator_tag) {
  size_type __len = 0;
  distance(__first, __last, __len);

  if (__len > capacity()) {
    pointer __tmp(_M_allocate_and_copy(__len, __first, __last));
    destroy(_M_start, _M_finish);
    _M_deallocate(_M_start, _M_end_of_storage - _M_start);
    _M_start = __tmp;
    _M_end_of_storage = _M_finish = _M_start + __len;
  }
  else if (size() >= __len) {
    iterator __new_finish(copy(__first, __last, _M_start));
    destroy(__new_finish, end());
    _M_finish = __new_finish.base();
  }
  else {
    _ForwardIter __mid = __first;
    advance(__mid, size());
    copy(__first, __mid, _M_start);
    _M_finish = uninitialized_copy(__mid, __last, _M_finish);
  }
}

template <class _Tp, class _Alloc>
void
vector<_Tp, _Alloc>::_M_insert_aux(iterator __position, const _Tp& __x)
{
  if (_M_finish != _M_end_of_storage) {
    construct(_M_finish, *(_M_finish - 1));
    ++_M_finish;
    _Tp __x_copy = __x;
    copy_backward(__position, iterator(_M_finish - 2), iterator(_M_finish- 1));
    *__position = __x_copy;
  }
  else {
    const size_type __old_size = size();
    const size_type __len = __old_size != 0 ? 2 * __old_size : 1;
    iterator __new_start(_M_allocate(__len));
    iterator __new_finish(__new_start);
    try {
      __new_finish = uninitialized_copy(iterator(_M_start), __position,
                                        __new_start);
      construct(__new_finish.base(), __x);
      ++__new_finish;
      __new_finish = uninitialized_copy(__position, iterator(_M_finish),
                                        __new_finish);
    }
    catch(...) { (destroy(__new_start,__new_finish), _M_deallocate(__new_start.base(),__len)); throw; };

    destroy(begin(), end());
    _M_deallocate(_M_start, _M_end_of_storage - _M_start);
    _M_start = __new_start.base();
    _M_finish = __new_finish.base();
    _M_end_of_storage = __new_start.base() + __len;
  }
}

template <class _Tp, class _Alloc>
void
vector<_Tp, _Alloc>::_M_insert_aux(iterator __position)
{
  if (_M_finish != _M_end_of_storage) {
    construct(_M_finish, *(_M_finish - 1));
    ++_M_finish;
    copy_backward(__position, iterator(_M_finish - 2),
                  iterator(_M_finish - 1));
    *__position = _Tp();
  }
  else {
    const size_type __old_size = size();
    const size_type __len = __old_size != 0 ? 2 * __old_size : 1;
    pointer __new_start = _M_allocate(__len);
    pointer __new_finish = __new_start;
    try {
      __new_finish = uninitialized_copy(iterator(_M_start), __position,
                                        __new_start);
      construct(__new_finish);
      ++__new_finish;
      __new_finish = uninitialized_copy(__position, iterator(_M_finish),
                                        __new_finish);
    }
    catch(...) { (destroy(__new_start,__new_finish), _M_deallocate(__new_start,__len)); throw; };

    destroy(begin(), end());
    _M_deallocate(_M_start, _M_end_of_storage - _M_start);
    _M_start = __new_start;
    _M_finish = __new_finish;
    _M_end_of_storage = __new_start + __len;
  }
}

template <class _Tp, class _Alloc>
void vector<_Tp, _Alloc>::_M_fill_insert(iterator __position, size_type __n,
                                         const _Tp& __x)
{
  if (__n != 0) {
    if (size_type(_M_end_of_storage - _M_finish) >= __n) {
      _Tp __x_copy = __x;
      const size_type __elems_after = end() - __position;
      iterator __old_finish(_M_finish);
      if (__elems_after > __n) {
        uninitialized_copy(_M_finish - __n, _M_finish, _M_finish);
        _M_finish += __n;
        copy_backward(__position, __old_finish - __n, __old_finish);
        fill(__position, __position + __n, __x_copy);
      }
      else {
        uninitialized_fill_n(_M_finish, __n - __elems_after, __x_copy);
        _M_finish += __n - __elems_after;
        uninitialized_copy(__position, __old_finish, _M_finish);
        _M_finish += __elems_after;
        fill(__position, __old_finish, __x_copy);
      }
    }
    else {
      const size_type __old_size = size();
      const size_type __len = __old_size + max(__old_size, __n);
      iterator __new_start(_M_allocate(__len));
      iterator __new_finish(__new_start);
      try {
        __new_finish = uninitialized_copy(begin(), __position, __new_start);
        __new_finish = uninitialized_fill_n(__new_finish, __n, __x);
        __new_finish
          = uninitialized_copy(__position, end(), __new_finish);
      }
      catch(...) { (destroy(__new_start,__new_finish), _M_deallocate(__new_start.base(),__len)); throw; };

      destroy(_M_start, _M_finish);
      _M_deallocate(_M_start, _M_end_of_storage - _M_start);
      _M_start = __new_start.base();
      _M_finish = __new_finish.base();
      _M_end_of_storage = __new_start.base() + __len;
    }
  }
}

template <class _Tp, class _Alloc> template <class _InputIterator>
void
vector<_Tp, _Alloc>::_M_range_insert(iterator __pos,
                                     _InputIterator __first,
                                     _InputIterator __last,
                                     input_iterator_tag)
{
  for ( ; __first != __last; ++__first) {
    __pos = insert(__pos, *__first);
    ++__pos;
  }
}

template <class _Tp, class _Alloc> template <class _ForwardIterator>
void
vector<_Tp, _Alloc>::_M_range_insert(iterator __position,
                                     _ForwardIterator __first,
                                     _ForwardIterator __last,
                                     forward_iterator_tag)
{
  if (__first != __last) {
    size_type __n = 0;
    distance(__first, __last, __n);
    if (size_type(_M_end_of_storage - _M_finish) >= __n) {
      const size_type __elems_after = end() - __position;
      iterator __old_finish(_M_finish);
      if (__elems_after > __n) {
        uninitialized_copy(_M_finish - __n, _M_finish, _M_finish);
        _M_finish += __n;
        copy_backward(__position, __old_finish - __n, __old_finish);
        copy(__first, __last, __position);
      }
      else {
        _ForwardIterator __mid = __first;
        advance(__mid, __elems_after);
        uninitialized_copy(__mid, __last, _M_finish);
        _M_finish += __n - __elems_after;
        uninitialized_copy(__position, __old_finish, _M_finish);
        _M_finish += __elems_after;
        copy(__first, __mid, __position);
      }
    }
    else {
      const size_type __old_size = size();
      const size_type __len = __old_size + max(__old_size, __n);
      iterator __new_start(_M_allocate(__len));
      iterator __new_finish(__new_start);
      try {
        __new_finish = uninitialized_copy(iterator(_M_start),
                                          __position, __new_start);
        __new_finish = uninitialized_copy(__first, __last, __new_finish);
        __new_finish
          = uninitialized_copy(__position, iterator(_M_finish), __new_finish);
      }
      catch(...) { (destroy(__new_start,__new_finish), _M_deallocate(__new_start.base(),__len)); throw; };

      destroy(_M_start, _M_finish);
      _M_deallocate(_M_start, _M_end_of_storage - _M_start);
      _M_start = __new_start.base();
      _M_finish = __new_finish.base();
      _M_end_of_storage = __new_start.base() + __len;
    }
  }
}

}
# 67 "/usr/local/include/g++-v3/bits/std_vector.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/stl_bvector.h" 1 3
# 63 "/usr/local/include/g++-v3/bits/stl_bvector.h" 3
namespace std
{

static const int __WORD_BIT = int(8*sizeof(unsigned int));

struct _Bit_reference {
  unsigned int* _M_p;
  unsigned int _M_mask;
  _Bit_reference(unsigned int* __x, unsigned int __y)
    : _M_p(__x), _M_mask(__y) {}

public:
  _Bit_reference() : _M_p(0), _M_mask(0) {}
  operator bool() const { return !(!(*_M_p & _M_mask)); }
  _Bit_reference& operator=(bool __x)
  {
    if (__x) *_M_p |= _M_mask;
    else *_M_p &= ~_M_mask;
    return *this;
  }
  _Bit_reference& operator=(const _Bit_reference& __x)
    { return *this = bool(__x); }
  bool operator==(const _Bit_reference& __x) const
    { return bool(*this) == bool(__x); }
  bool operator<(const _Bit_reference& __x) const {
    return !bool(*this) && bool(__x);
  }
  void flip() { *_M_p ^= _M_mask; }
};

inline void swap(_Bit_reference __x, _Bit_reference __y)
{
  bool __tmp = __x;
  __x = __y;
  __y = __tmp;
}

struct _Bit_iterator_base : public random_access_iterator<bool, ptrdiff_t>
{
  unsigned int* _M_p;
  unsigned int _M_offset;

  _Bit_iterator_base(unsigned int* __x, unsigned int __y)
    : _M_p(__x), _M_offset(__y) {}

  void _M_bump_up() {
    if (_M_offset++ == __WORD_BIT - 1) {
      _M_offset = 0;
      ++_M_p;
    }
  }
  void _M_bump_down() {
    if (_M_offset-- == 0) {
      _M_offset = __WORD_BIT - 1;
      --_M_p;
    }
  }

  void _M_incr(ptrdiff_t __i) {
    difference_type __n = __i + _M_offset;
    _M_p += __n / __WORD_BIT;
    __n = __n % __WORD_BIT;
    if (__n < 0) {
      _M_offset = (unsigned int) __n + __WORD_BIT;
      --_M_p;
    } else
      _M_offset = (unsigned int) __n;
  }

  bool operator==(const _Bit_iterator_base& __i) const {
    return _M_p == __i._M_p && _M_offset == __i._M_offset;
  }
  bool operator<(const _Bit_iterator_base& __i) const {
    return _M_p < __i._M_p || (_M_p == __i._M_p && _M_offset < __i._M_offset);
  }
  bool operator!=(const _Bit_iterator_base& __i) const {
    return !(*this == __i);
  }
  bool operator>(const _Bit_iterator_base& __i) const {
    return __i < *this;
  }
  bool operator<=(const _Bit_iterator_base& __i) const {
    return !(__i < *this);
  }
  bool operator>=(const _Bit_iterator_base& __i) const {
    return !(*this < __i);
  }
};

inline ptrdiff_t
operator-(const _Bit_iterator_base& __x, const _Bit_iterator_base& __y) {
  return __WORD_BIT * (__x._M_p - __y._M_p) + __x._M_offset - __y._M_offset;
}


struct _Bit_iterator : public _Bit_iterator_base
{
  typedef _Bit_reference reference;
  typedef _Bit_reference* pointer;
  typedef _Bit_iterator iterator;

  _Bit_iterator() : _Bit_iterator_base(0, 0) {}
  _Bit_iterator(unsigned int* __x, unsigned int __y)
    : _Bit_iterator_base(__x, __y) {}

  reference operator*() const { return reference(_M_p, 1U << _M_offset); }
  iterator& operator++() {
    _M_bump_up();
    return *this;
  }
  iterator operator++(int) {
    iterator __tmp = *this;
    _M_bump_up();
    return __tmp;
  }
  iterator& operator--() {
    _M_bump_down();
    return *this;
  }
  iterator operator--(int) {
    iterator __tmp = *this;
    _M_bump_down();
    return __tmp;
  }
  iterator& operator+=(difference_type __i) {
    _M_incr(__i);
    return *this;
  }
  iterator& operator-=(difference_type __i) {
    *this += -__i;
    return *this;
  }
  iterator operator+(difference_type __i) const {
    iterator __tmp = *this;
    return __tmp += __i;
  }
  iterator operator-(difference_type __i) const {
    iterator __tmp = *this;
    return __tmp -= __i;
  }

  reference operator[](difference_type __i) { return *(*this + __i); }
};

inline _Bit_iterator
operator+(ptrdiff_t __n, const _Bit_iterator& __x) { return __x + __n; }


struct _Bit_const_iterator : public _Bit_iterator_base
{
  typedef bool reference;
  typedef bool const_reference;
  typedef const bool* pointer;
  typedef _Bit_const_iterator const_iterator;

  _Bit_const_iterator() : _Bit_iterator_base(0, 0) {}
  _Bit_const_iterator(unsigned int* __x, unsigned int __y)
    : _Bit_iterator_base(__x, __y) {}
  _Bit_const_iterator(const _Bit_iterator& __x)
    : _Bit_iterator_base(__x._M_p, __x._M_offset) {}

  const_reference operator*() const {
    return _Bit_reference(_M_p, 1U << _M_offset);
  }
  const_iterator& operator++() {
    _M_bump_up();
    return *this;
  }
  const_iterator operator++(int) {
    const_iterator __tmp = *this;
    _M_bump_up();
    return __tmp;
  }
  const_iterator& operator--() {
    _M_bump_down();
    return *this;
  }
  const_iterator operator--(int) {
    const_iterator __tmp = *this;
    _M_bump_down();
    return __tmp;
  }
  const_iterator& operator+=(difference_type __i) {
    _M_incr(__i);
    return *this;
  }
  const_iterator& operator-=(difference_type __i) {
    *this += -__i;
    return *this;
  }
  const_iterator operator+(difference_type __i) const {
    const_iterator __tmp = *this;
    return __tmp += __i;
  }
  const_iterator operator-(difference_type __i) const {
    const_iterator __tmp = *this;
    return __tmp -= __i;
  }
  const_reference operator[](difference_type __i) {
    return *(*this + __i);
  }
};

inline _Bit_const_iterator
operator+(ptrdiff_t __n, const _Bit_const_iterator& __x) { return __x + __n; }






template <class _Allocator, bool __is_static>
class _Bvector_alloc_base {
public:
  typedef typename _Alloc_traits<bool, _Allocator>::allocator_type
          allocator_type;
  allocator_type get_allocator() const { return _M_data_allocator; }

  _Bvector_alloc_base(const allocator_type& __a)
    : _M_data_allocator(__a), _M_start(), _M_finish(), _M_end_of_storage(0) {}

protected:
  unsigned int* _M_bit_alloc(size_t __n)
    { return _M_data_allocator.allocate((__n + __WORD_BIT - 1)/__WORD_BIT); }
  void _M_deallocate() {
    if (_M_start._M_p)
      _M_data_allocator.deallocate(_M_start._M_p,
                                   _M_end_of_storage - _M_start._M_p);
  }

  typename _Alloc_traits<unsigned int, _Allocator>::allocator_type
          _M_data_allocator;
  _Bit_iterator _M_start;
  _Bit_iterator _M_finish;
  unsigned int* _M_end_of_storage;
};


template <class _Allocator>
class _Bvector_alloc_base<_Allocator, true> {
public:
  typedef typename _Alloc_traits<bool, _Allocator>::allocator_type
          allocator_type;
  allocator_type get_allocator() const { return allocator_type(); }

  _Bvector_alloc_base(const allocator_type&)
    : _M_start(), _M_finish(), _M_end_of_storage(0) {}

protected:
  typedef typename _Alloc_traits<unsigned int, _Allocator>::_Alloc_type
          _Alloc_type;

  unsigned int* _M_bit_alloc(size_t __n)
    { return _Alloc_type::allocate((__n + __WORD_BIT - 1)/__WORD_BIT); }
  void _M_deallocate() {
    if (_M_start._M_p)
      _Alloc_type::deallocate(_M_start._M_p,
                              _M_end_of_storage - _M_start._M_p);
  }

  _Bit_iterator _M_start;
  _Bit_iterator _M_finish;
  unsigned int* _M_end_of_storage;
};

template <class _Alloc>
class _Bvector_base
  : public _Bvector_alloc_base<_Alloc,
                               _Alloc_traits<bool, _Alloc>::_S_instanceless>
{
  typedef _Bvector_alloc_base<_Alloc,
                              _Alloc_traits<bool, _Alloc>::_S_instanceless>
          _Base;
public:
  typedef typename _Base::allocator_type allocator_type;

  _Bvector_base(const allocator_type& __a) : _Base(__a) {}
  ~_Bvector_base() { _Base::_M_deallocate(); }
};

}


# 1 "/usr/local/include/g++-v3/bits/stl_vector.h" 1 3
# 347 "/usr/local/include/g++-v3/bits/stl_bvector.h" 2 3
namespace std
{

template <typename _Alloc>
  class vector<bool, _Alloc> : public _Bvector_base<_Alloc>
  {
  public:
    typedef bool value_type;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef _Bit_reference reference;
    typedef bool const_reference;
    typedef _Bit_reference* pointer;
    typedef const bool* const_pointer;

    typedef _Bit_iterator iterator;
    typedef _Bit_const_iterator const_iterator;

    typedef reverse_iterator<const_iterator> const_reverse_iterator;
    typedef reverse_iterator<iterator> reverse_iterator;

    typedef typename _Bvector_base<_Alloc>::allocator_type allocator_type;
    allocator_type get_allocator() const {
      return _Bvector_base<_Alloc>::get_allocator();
    }

  protected:
    using _Bvector_base<_Alloc>::_M_bit_alloc;
    using _Bvector_base<_Alloc>::_M_deallocate;
    using _Bvector_base<_Alloc>::_M_start;
    using _Bvector_base<_Alloc>::_M_finish;
    using _Bvector_base<_Alloc>::_M_end_of_storage;

  protected:
    void _M_initialize(size_type __n) {
      unsigned int* __q = _M_bit_alloc(__n);
      _M_end_of_storage = __q + (__n + __WORD_BIT - 1)/__WORD_BIT;
      _M_start = iterator(__q, 0);
      _M_finish = _M_start + difference_type(__n);
    }
    void _M_insert_aux(iterator __position, bool __x) {
      if (_M_finish._M_p != _M_end_of_storage) {
        copy_backward(__position, _M_finish, _M_finish + 1);
        *__position = __x;
        ++_M_finish;
      }
      else {
        size_type __len = size() ? 2 * size() : __WORD_BIT;
        unsigned int* __q = _M_bit_alloc(__len);
        iterator __i = copy(begin(), __position, iterator(__q, 0));
        *__i++ = __x;
        _M_finish = copy(__position, end(), __i);
        _M_deallocate();
        _M_end_of_storage = __q + (__len + __WORD_BIT - 1)/__WORD_BIT;
        _M_start = iterator(__q, 0);
      }
    }

    template <class _InputIterator>
    void _M_initialize_range(_InputIterator __first, _InputIterator __last,
                             input_iterator_tag) {
      _M_start = iterator();
      _M_finish = iterator();
      _M_end_of_storage = 0;
      for ( ; __first != __last; ++__first)
        push_back(*__first);
    }

    template <class _ForwardIterator>
    void _M_initialize_range(_ForwardIterator __first, _ForwardIterator __last,
                             forward_iterator_tag) {
      size_type __n = 0;
      distance(__first, __last, __n);
      _M_initialize(__n);
      copy(__first, __last, _M_start);
    }

    template <class _InputIterator>
    void _M_insert_range(iterator __pos,
                         _InputIterator __first, _InputIterator __last,
                         input_iterator_tag) {
      for ( ; __first != __last; ++__first) {
        __pos = insert(__pos, *__first);
        ++__pos;
      }
    }

    template <class _ForwardIterator>
    void _M_insert_range(iterator __position,
                         _ForwardIterator __first, _ForwardIterator __last,
                         forward_iterator_tag) {
      if (__first != __last) {
        size_type __n = 0;
        distance(__first, __last, __n);
        if (capacity() - size() >= __n) {
          copy_backward(__position, end(), _M_finish + difference_type(__n));
          copy(__first, __last, __position);
          _M_finish += difference_type(__n);
        }
        else {
          size_type __len = size() + max(size(), __n);
          unsigned int* __q = _M_bit_alloc(__len);
          iterator __i = copy(begin(), __position, iterator(__q, 0));
          __i = copy(__first, __last, __i);
          _M_finish = copy(__position, end(), __i);
          _M_deallocate();
          _M_end_of_storage = __q + (__len + __WORD_BIT - 1)/__WORD_BIT;
          _M_start = iterator(__q, 0);
        }
      }
    }

  public:
    iterator begin() { return _M_start; }
    const_iterator begin() const { return _M_start; }
    iterator end() { return _M_finish; }
    const_iterator end() const { return _M_finish; }

    reverse_iterator rbegin() { return reverse_iterator(end()); }
    const_reverse_iterator rbegin() const {
      return const_reverse_iterator(end());
    }
    reverse_iterator rend() { return reverse_iterator(begin()); }
    const_reverse_iterator rend() const {
      return const_reverse_iterator(begin());
    }

    size_type size() const { return size_type(end() - begin()); }
    size_type max_size() const { return size_type(-1); }
    size_type capacity() const {
      return size_type(const_iterator(_M_end_of_storage, 0) - begin());
    }
    bool empty() const { return begin() == end(); }

    reference operator[](size_type __n)
      { return *(begin() + difference_type(__n)); }
    const_reference operator[](size_type __n) const
      { return *(begin() + difference_type(__n)); }

    void _M_range_check(size_type __n) const {
      if (__n >= this->size())
        __throw_range_error("vector<bool>");
    }

    reference at(size_type __n)
      { _M_range_check(__n); return (*this)[__n]; }
    const_reference at(size_type __n) const
      { _M_range_check(__n); return (*this)[__n]; }

    explicit vector(const allocator_type& __a = allocator_type())
      : _Bvector_base<_Alloc>(__a) {}

    vector(size_type __n, bool __value,
              const allocator_type& __a = allocator_type())
      : _Bvector_base<_Alloc>(__a)
    {
      _M_initialize(__n);
      fill(_M_start._M_p, _M_end_of_storage, __value ? ~0 : 0);
    }

    explicit vector(size_type __n)
      : _Bvector_base<_Alloc>(allocator_type())
    {
      _M_initialize(__n);
      fill(_M_start._M_p, _M_end_of_storage, 0);
    }

    vector(const vector& __x) : _Bvector_base<_Alloc>(__x.get_allocator()) {
      _M_initialize(__x.size());
      copy(__x.begin(), __x.end(), _M_start);
    }



    template <class _Integer>
    void _M_initialize_dispatch(_Integer __n, _Integer __x, __true_type) {
      _M_initialize(__n);
      fill(_M_start._M_p, _M_end_of_storage, __x ? ~0 : 0);
    }

    template <class _InputIterator>
    void _M_initialize_dispatch(_InputIterator __first, _InputIterator __last,
                                __false_type) {
      _M_initialize_range(__first, __last, __iterator_category(__first));
    }

    template <class _InputIterator>
    vector(_InputIterator __first, _InputIterator __last,
             const allocator_type& __a = allocator_type())
      : _Bvector_base<_Alloc>(__a)
    {
      typedef typename _Is_integer<_InputIterator>::_Integral _Integral;
      _M_initialize_dispatch(__first, __last, _Integral());
    }

    ~vector() { }

    vector& operator=(const vector& __x) {
      if (&__x == this) return *this;
      if (__x.size() > capacity()) {
        _M_deallocate();
        _M_initialize(__x.size());
      }
      copy(__x.begin(), __x.end(), begin());
      _M_finish = begin() + difference_type(__x.size());
      return *this;
    }






    void _M_fill_assign(size_t __n, bool __x) {
      if (__n > size()) {
        fill(_M_start._M_p, _M_end_of_storage, __x ? ~0 : 0);
        insert(end(), __n - size(), __x);
      }
      else {
        erase(begin() + __n, end());
        fill(_M_start._M_p, _M_end_of_storage, __x ? ~0 : 0);
      }
    }

    void assign(size_t __n, bool __x) { _M_fill_assign(__n, __x); }

    template <class _InputIterator>
    void assign(_InputIterator __first, _InputIterator __last) {
      typedef typename _Is_integer<_InputIterator>::_Integral _Integral;
      _M_assign_dispatch(__first, __last, _Integral());
    }

    template <class _Integer>
    void _M_assign_dispatch(_Integer __n, _Integer __val, __true_type)
      { _M_fill_assign((size_t) __n, (bool) __val); }

    template <class _InputIter>
    void _M_assign_dispatch(_InputIter __first, _InputIter __last, __false_type)
      { _M_assign_aux(__first, __last, __iterator_category(__first)); }

    template <class _InputIterator>
    void _M_assign_aux(_InputIterator __first, _InputIterator __last,
                       input_iterator_tag) {
      iterator __cur = begin();
      for ( ; __first != __last && __cur != end(); ++__cur, ++__first)
        *__cur = *__first;
      if (__first == __last)
        erase(__cur, end());
      else
        insert(end(), __first, __last);
    }

    template <class _ForwardIterator>
    void _M_assign_aux(_ForwardIterator __first, _ForwardIterator __last,
                       forward_iterator_tag) {
      size_type __len = 0;
      distance(__first, __last, __len);
      if (__len < size())
        erase(copy(__first, __last, begin()), end());
      else {
        _ForwardIterator __mid = __first;
        advance(__mid, size());
        copy(__first, __mid, begin());
        insert(end(), __mid, __last);
      }
    }

    void reserve(size_type __n) {
      if (capacity() < __n) {
        unsigned int* __q = _M_bit_alloc(__n);
        _M_finish = copy(begin(), end(), iterator(__q, 0));
        _M_deallocate();
        _M_start = iterator(__q, 0);
        _M_end_of_storage = __q + (__n + __WORD_BIT - 1)/__WORD_BIT;
      }
    }

    reference front() { return *begin(); }
    const_reference front() const { return *begin(); }
    reference back() { return *(end() - 1); }
    const_reference back() const { return *(end() - 1); }
    void push_back(bool __x) {
      if (_M_finish._M_p != _M_end_of_storage)
        *_M_finish++ = __x;
      else
        _M_insert_aux(end(), __x);
    }
    void swap(vector<bool, _Alloc>& __x) {
      std::swap(_M_start, __x._M_start);
      std::swap(_M_finish, __x._M_finish);
      std::swap(_M_end_of_storage, __x._M_end_of_storage);
    }
    iterator insert(iterator __position, bool __x = bool()) {
      difference_type __n = __position - begin();
      if (_M_finish._M_p != _M_end_of_storage && __position == end())
        *_M_finish++ = __x;
      else
        _M_insert_aux(__position, __x);
      return begin() + __n;
    }



    template <class _Integer>
    void _M_insert_dispatch(iterator __pos, _Integer __n, _Integer __x,
                            __true_type) {
      _M_fill_insert(__pos, __n, __x);
    }

    template <class _InputIterator>
    void _M_insert_dispatch(iterator __pos,
                            _InputIterator __first, _InputIterator __last,
                            __false_type) {
      _M_insert_range(__pos, __first, __last, __iterator_category(__first));
    }

    template <class _InputIterator>
    void insert(iterator __position,
                _InputIterator __first, _InputIterator __last) {
      typedef typename _Is_integer<_InputIterator>::_Integral _Integral;
      _M_insert_dispatch(__position, __first, __last, _Integral());
    }

    void _M_fill_insert(iterator __position, size_type __n, bool __x) {
      if (__n == 0) return;
      if (capacity() - size() >= __n) {
        copy_backward(__position, end(), _M_finish + difference_type(__n));
        fill(__position, __position + difference_type(__n), __x);
        _M_finish += difference_type(__n);
      }
      else {
        size_type __len = size() + max(size(), __n);
        unsigned int* __q = _M_bit_alloc(__len);
        iterator __i = copy(begin(), __position, iterator(__q, 0));
        fill_n(__i, __n, __x);
        _M_finish = copy(__position, end(), __i + difference_type(__n));
        _M_deallocate();
        _M_end_of_storage = __q + (__len + __WORD_BIT - 1)/__WORD_BIT;
        _M_start = iterator(__q, 0);
      }
    }

    void insert(iterator __position, size_type __n, bool __x) {
      _M_fill_insert(__position, __n, __x);
    }

    void pop_back() { --_M_finish; }
    iterator erase(iterator __position) {
      if (__position + 1 != end())
        copy(__position + 1, end(), __position);
        --_M_finish;
      return __position;
    }
    iterator erase(iterator __first, iterator __last) {
      _M_finish = copy(__last, end(), __first);
      return __first;
    }
    void resize(size_type __new_size, bool __x = bool()) {
      if (__new_size < size())
        erase(begin() + difference_type(__new_size), end());
      else
        insert(end(), __new_size - size(), __x);
    }
    void flip() {
      for (unsigned int* __p = _M_start._M_p; __p != _M_end_of_storage; ++__p)
        *__p = ~*__p;
    }

    void clear() { erase(begin(), end()); }
  };


typedef vector<bool, alloc> bit_vector;

}
# 68 "/usr/local/include/g++-v3/bits/std_vector.h" 2 3
# 44 "/usr/local/include/g++-v3/bits/locale_facets.tcc" 2 3


namespace std
{
  template<typename _Facet>
    locale
    locale::combine(const locale& __other)
    {
      locale __copy(*this);
      __copy._M_impl->_M_replace_facet(__other._M_impl, &_Facet::id);
      return __copy;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    bool
    locale::operator()(const basic_string<_CharT, _Traits, _Alloc>& __s1,
                       const basic_string<_CharT, _Traits, _Alloc>& __s2) const
    {
      typedef std::collate<_CharT> __collate_type;
      const __collate_type* __fcoll = &use_facet<__collate_type>(*this);
      return (__fcoll->compare(__s1.data(), __s1.data() + __s1.length(),
                               __s2.data(), __s2.data() + __s2.length()) < 0);
    }

  template<typename _Facet>
    const _Facet&
    use_facet(const locale& __loc)
    {
      typedef locale::_Impl::__vec_facet __vec_facet;
      size_t __i = _Facet::id._M_index;
      __vec_facet* __facet = __loc._M_impl->_M_facets;
      const locale::facet* __fp = (*__facet)[__i];
      if (__fp == 0 || __i >= __facet->size())
        __throw_bad_cast();
      return static_cast<const _Facet&>(*__fp);
    }

  template<typename _Facet>
    bool
    has_facet(const locale& __loc) throw()
    {
      typedef locale::_Impl::__vec_facet __vec_facet;
      size_t __i = _Facet::id._M_index;
      __vec_facet* __facet = __loc._M_impl->_M_facets;
      return (__i < __facet->size() && (*__facet)[__i] != 0);
    }







  template<typename _InIter, typename _CharT>
    _InIter
    __match_parallel(_InIter __s, _InIter __end, int __ntargs,
                     const basic_string<_CharT>* __targets,
                     int* __matches, int& __remain, bool& __eof)
    {
      typedef basic_string<_CharT> __string_type;
      __eof = false;
      for (int __ti = 0; __ti < __ntargs; ++__ti)
        __matches[__ti] = __ti;
      __remain = __ntargs;
      size_t __pos = 0;
      do
        {
          int __ti = 0;
          while (__ti < __remain && __pos == __targets[__matches[__ti]].size())
            ++__ti;
          if (__ti == __remain)
            {
              if (__pos == 0) __remain = 0;
              return __s;
            }
          if (__s == __end)
            __eof = true;
          bool __matched = false;
          for (int __ti2 = 0; __ti2 < __remain; )
            {
              const __string_type& __target = __targets[__matches[__ti2]];
              if (__pos < __target.size())
                {
                  if (__eof || __target[__pos] != *__s)
                    {
                      __matches[__ti2] = __matches[--__remain];
                      continue;
                    }
                  __matched = true;
                }
              ++__ti2;
            }
          if (__matched)
            {
              ++__s;
              ++__pos;
            }
          for (int __ti3 = 0; __ti3 < __remain;)
            {
              if (__pos > __targets[__matches[__ti3]].size())
                {
                  __matches[__ti3] = __matches[--__remain];
                  continue;
                }
              ++__ti3;
            }
        }
      while (__remain);
      return __s;
    }

  template<typename _CharT>
    _Format_cache<_CharT>::_Format_cache()
    : _M_valid(true), _M_use_grouping(false)
    { }

  template<>
    _Format_cache<char>::_Format_cache();

  template<>
    _Format_cache<wchar_t>::_Format_cache();

  template<typename _CharT>
    void
    _Format_cache<_CharT>::_M_populate(ios_base& __io)
    {
      locale __loc = __io.getloc ();
      numpunct<_CharT> const& __np = use_facet<numpunct<_CharT> >(__loc);
      _M_truename = __np.truename();
      _M_falsename = __np.falsename();
      _M_thousands_sep = __np.thousands_sep();
      _M_decimal_point = __np.decimal_point();
      _M_grouping = __np.grouping();
      _M_use_grouping = _M_grouping.size() != 0 && _M_grouping.data()[0] != 0;
      _M_valid = true;
    }



  template<typename _CharT>
    void
    _Format_cache<_CharT>::
    _S_callback(ios_base::event __ev, ios_base& __ios, int __ix) throw()
    {
      void*& __p = __ios.pword(__ix);
      switch (__ev)
        {
        case ios_base::erase_event:
          delete static_cast<_Format_cache<_CharT>*>(__p);
          __p = 0;
          break;
        case ios_base::copyfmt_event:

          try
            { __p = new _Format_cache<_CharT>; }
          catch(...)
            { }
          break;
        case ios_base::imbue_event:
          static_cast<_Format_cache<_CharT>*>(__p)->_M_valid = false;
          break;
        }
    }

  template<typename _CharT>
    _Format_cache<_CharT>*
    _Format_cache<_CharT>::_S_get(ios_base& __ios)
    {
      if (!_S_pword_ix)
        _S_pword_ix = ios_base::xalloc();
      void*& __p = __ios.pword(_S_pword_ix);


      if (__p == 0)
        {
          auto_ptr<_Format_cache<_CharT> > __ap(new _Format_cache<_CharT>);
          __ios.register_callback(&_Format_cache<_CharT>::_S_callback,
                                  _S_pword_ix);
          __p = __ap.release();
        }
      _Format_cache<_CharT>* __ncp = static_cast<_Format_cache<_CharT>*>(__p);
      if (!__ncp->_M_valid)
        __ncp->_M_populate(__ios);

      return __ncp;
    }
# 250 "/usr/local/include/g++-v3/bits/locale_facets.tcc" 3
  template<typename _CharT, typename _InIter>
    void
    num_get<_CharT, _InIter>::
    _M_extract(_InIter , _InIter , ios_base& ,
               ios_base::iostate& , char* ,
               int& , bool ) const
    {

    }

  template<>
    void
    num_get<char, istreambuf_iterator<char> >::
    _M_extract(istreambuf_iterator<char> __beg,
               istreambuf_iterator<char> __end, ios_base& __io,
               ios_base::iostate& __err, char* __xtrc, int& __base,
               bool __fp) const;



  template<typename _CharT, typename _InIter>
    _InIter
    num_get<_CharT, _InIter>::
    do_get(iter_type __beg, iter_type __end, ios_base& __io,
           ios_base::iostate& __err, bool& __v) const
    {

      if (!(__io.flags() & ios_base::boolalpha))
        {






          char __xtrc[32] = {'\0'};
          int __base;
          _M_extract(__beg, __end, __io, __err, __xtrc, __base, false);


          char* __sanity;
          (*__errno_location ()) = 0;
          long __l = strtol(__xtrc, &__sanity, __base);
          if (!(__err & ios_base::failbit)
              && __l <= 1
              && __sanity != __xtrc && *__sanity == '\0' && (*__errno_location ()) == 0)
            __v = __l;
          else
            __err |= ios_base::failbit;
        }


      else
        {
          typedef _Format_cache<char_type> __fcache_type;
          __fcache_type* __fmt = __fcache_type::_S_get(__io);
          const char_type* __true = __fmt->_M_truename.c_str();
          const char_type* __false = __fmt->_M_falsename.c_str();
          const size_t __truelen = __traits_type::length(__true) - 1;
          const size_t __falselen = __traits_type::length(__false) - 1;

          for (size_t __pos = 0; __beg != __end; ++__pos)
            {
              char_type __c = *__beg++;
              bool __testf = __c == __false[__pos];
              bool __testt = __c == __true[__pos];
              if (!(__testf || __testt))
                {
                  __err |= ios_base::failbit;
                  break;
                }
              else if (__testf && __pos == __falselen)
                {
                  __v = 0;
                  break;
                }
              else if (__testt && __pos == __truelen)
                {
                  __v = 1;
                  break;
                }
            }
          if (__beg == __end)
            __err |= ios_base::eofbit;
        }

      return __beg;
    }



  template<typename _CharT, typename _InIter>
    _InIter
    num_get<_CharT, _InIter>::
    do_get(iter_type __beg, iter_type __end, ios_base& __io,
           ios_base::iostate& __err, short& __v) const
    {



      char __xtrc[32]= {'\0'};
      int __base;
      _M_extract(__beg, __end, __io, __err, __xtrc, __base, false);


      char* __sanity;
      (*__errno_location ()) = 0;
      long __l = strtol(__xtrc, &__sanity, __base);
      if (!(__err & ios_base::failbit)
          && __sanity != __xtrc && *__sanity == '\0' && (*__errno_location ()) == 0
          && __l >= (-32767-1) && __l <= 32767)
        __v = static_cast<short>(__l);
      else
        __err |= ios_base::failbit;

      return __beg;
    }

  template<typename _CharT, typename _InIter>
    _InIter
    num_get<_CharT, _InIter>::
    do_get(iter_type __beg, iter_type __end, ios_base& __io,
           ios_base::iostate& __err, int& __v) const
    {



      char __xtrc[32] = {'\0'};
      int __base;
      _M_extract(__beg, __end, __io, __err, __xtrc, __base, false);


      char* __sanity;
      (*__errno_location ()) = 0;
      long __l = strtol(__xtrc, &__sanity, __base);
      if (!(__err & ios_base::failbit)
          && __sanity != __xtrc && *__sanity == '\0' && (*__errno_location ()) == 0
          && __l >= (-2147483647 -1) && __l <= 2147483647)
        __v = static_cast<int>(__l);
      else
        __err |= ios_base::failbit;

      return __beg;
    }


  template<typename _CharT, typename _InIter>
    _InIter
    num_get<_CharT, _InIter>::
    do_get(iter_type __beg, iter_type __end, ios_base& __io,
           ios_base::iostate& __err, long& __v) const
    {



      char __xtrc[32]= {'\0'};
      int __base;
      _M_extract(__beg, __end, __io, __err, __xtrc, __base, false);


      char* __sanity;
      (*__errno_location ()) = 0;
      long __l = strtol(__xtrc, &__sanity, __base);
      if (!(__err & ios_base::failbit)
          && __sanity != __xtrc && *__sanity == '\0' && (*__errno_location ()) == 0)
        __v = __l;
      else
        __err |= ios_base::failbit;

      return __beg;
    }


  template<typename _CharT, typename _InIter>
    _InIter
    num_get<_CharT, _InIter>::
    do_get(iter_type __beg, iter_type __end, ios_base& __io,
           ios_base::iostate& __err, long long& __v) const
    {



      char __xtrc[32]= {'\0'};
      int __base;
      _M_extract(__beg, __end, __io, __err, __xtrc, __base, false);


      char* __sanity;
      (*__errno_location ()) = 0;
      long long __ll = strtoll(__xtrc, &__sanity, __base);
      if (!(__err & ios_base::failbit)
          && __sanity != __xtrc && *__sanity == '\0' && (*__errno_location ()) == 0)
        __v = __ll;
      else
        __err |= ios_base::failbit;

      return __beg;
    }


  template<typename _CharT, typename _InIter>
    _InIter
    num_get<_CharT, _InIter>::
    do_get(iter_type __beg, iter_type __end, ios_base& __io,
           ios_base::iostate& __err, unsigned short& __v) const
    {



      char __xtrc[32]= {'\0'};
      int __base;
      _M_extract(__beg, __end, __io, __err, __xtrc, __base, false);


      char* __sanity;
      (*__errno_location ()) = 0;
      unsigned long __ul = strtoul(__xtrc, &__sanity, __base);
      if (!(__err & ios_base::failbit)
          && __sanity != __xtrc && *__sanity == '\0' && (*__errno_location ()) == 0
          && __ul <= 65535)
        __v = static_cast<unsigned short>(__ul);
      else
        __err |= ios_base::failbit;

      return __beg;
    }

  template<typename _CharT, typename _InIter>
    _InIter
    num_get<_CharT, _InIter>::
    do_get(iter_type __beg, iter_type __end, ios_base& __io,
           ios_base::iostate& __err, unsigned int& __v) const
    {



      char __xtrc[32]= {'\0'};
      int __base;
      _M_extract(__beg, __end, __io, __err, __xtrc, __base, false);


      char* __sanity;
      (*__errno_location ()) = 0;
      unsigned long __ul = strtoul(__xtrc, &__sanity, __base);
      if (!(__err & ios_base::failbit)
          && __sanity != __xtrc && *__sanity == '\0' && (*__errno_location ()) == 0
          && __ul <= (2147483647 * 2U + 1))
        __v = static_cast<unsigned int>(__ul);
      else
        __err |= ios_base::failbit;

      return __beg;
    }

  template<typename _CharT, typename _InIter>
    _InIter
    num_get<_CharT, _InIter>::
    do_get(iter_type __beg, iter_type __end, ios_base& __io,
           ios_base::iostate& __err, unsigned long& __v) const
    {



      char __xtrc[32] = {'\0'};
      int __base;
      _M_extract(__beg, __end, __io, __err, __xtrc, __base, false);


      char* __sanity;
      (*__errno_location ()) = 0;
      unsigned long __ul = strtoul(__xtrc, &__sanity, __base);
      if (!(__err & ios_base::failbit)
          && __sanity != __xtrc && *__sanity == '\0' && (*__errno_location ()) == 0)
        __v = __ul;
      else
        __err |= ios_base::failbit;

      return __beg;
    }


  template<typename _CharT, typename _InIter>
    _InIter
    num_get<_CharT, _InIter>::
    do_get(iter_type __beg, iter_type __end, ios_base& __io,
           ios_base::iostate& __err, unsigned long long& __v) const
    {



      char __xtrc[32]= {'\0'};
      int __base;
      _M_extract(__beg, __end, __io, __err, __xtrc, __base, false);


      char* __sanity;
      (*__errno_location ()) = 0;
      unsigned long long __ull = strtoull(__xtrc, &__sanity, __base);
      if (!(__err & ios_base::failbit)
          && __sanity != __xtrc && *__sanity == '\0' && (*__errno_location ()) == 0)
        __v = __ull;
      else
        __err |= ios_base::failbit;

      return __beg;
    }


  template<typename _CharT, typename _InIter>
    _InIter
    num_get<_CharT, _InIter>::
    do_get(iter_type __beg, iter_type __end, ios_base& __io,
           ios_base::iostate& __err, float& __v) const
    {



      char __xtrc[32]= {'\0'};
      int __base;
      _M_extract(__beg, __end, __io, __err, __xtrc, __base, true);


      char* __sanity;
      (*__errno_location ()) = 0;

      float __f = strtof(__xtrc, &__sanity);



      if (!(__err & ios_base::failbit)
          && __sanity != __xtrc && *__sanity == '\0' && (*__errno_location ()) == 0)
        __v = __f;
      else
        __err |= ios_base::failbit;

      return __beg;
    }

  template<typename _CharT, typename _InIter>
    _InIter
    num_get<_CharT, _InIter>::
    do_get(iter_type __beg, iter_type __end, ios_base& __io,
           ios_base::iostate& __err, double& __v) const
    {



      char __xtrc[32]= {'\0'};
      int __base;
      _M_extract(__beg, __end, __io, __err, __xtrc, __base, true);


      char* __sanity;
      (*__errno_location ()) = 0;
      double __d = strtod(__xtrc, &__sanity);
      if (!(__err & ios_base::failbit)
          && __sanity != __xtrc && *__sanity == '\0' && (*__errno_location ()) == 0)
        __v = __d;
      else
        __err |= ios_base::failbit;

      return __beg;
    }


  template<typename _CharT, typename _InIter>
    _InIter
    num_get<_CharT, _InIter>::
    do_get(iter_type __beg, iter_type __end, ios_base& __io,
           ios_base::iostate& __err, long double& __v) const
    {



      char __xtrc[32]= {'\0'};
      int __base;
      _M_extract(__beg, __end, __io, __err, __xtrc, __base, true);


      char* __sanity;
      (*__errno_location ()) = 0;
      long double __ld = strtold(__xtrc, &__sanity);
      if (!(__err & ios_base::failbit)
          && __sanity != __xtrc && *__sanity == '\0' && (*__errno_location ()) == 0)
        __v = __ld;
      else
        __err |= ios_base::failbit;

      return __beg;
    }
# 678 "/usr/local/include/g++-v3/bits/locale_facets.tcc" 3
  template<typename _CharT, typename _InIter>
    _InIter
    num_get<_CharT, _InIter>::
    do_get(iter_type __beg, iter_type __end, ios_base& __io,
           ios_base::iostate& __err, void*& __v) const
    {

      typedef ios_base::fmtflags fmtflags;
      fmtflags __fmt = __io.flags();
      fmtflags __fmtmask = ~(ios_base::showpos | ios_base::basefield
                             | ios_base::uppercase | ios_base::internal);
      __io.flags(__fmt & __fmtmask | (ios_base::hex | ios_base::showbase));




      char __xtrc[32]= {'\0'};
      int __base;
      _M_extract(__beg, __end, __io, __err, __xtrc, __base, false);


      char* __sanity;
      (*__errno_location ()) = 0;
      void* __vp = reinterpret_cast<void*>(strtoul(__xtrc, &__sanity, __base));
      if (!(__err & ios_base::failbit)
          && __sanity != __xtrc && *__sanity == '\0' && (*__errno_location ()) == 0)
        __v = __vp;
      else
        __err |= ios_base::failbit;


      __io.flags(__fmt);
      return __beg;
    }


  template <typename _CharT, typename _OutIter>
    inline _OutIter
    __pad(_OutIter __s, _CharT __fill, int __padding);

  template <typename _CharT, typename _RaIter>
    _RaIter
    __pad(_RaIter __s, _CharT __fill, int __padding,
          random_access_iterator_tag)
    {
      fill_n(__s, __fill);
      return __s + __padding;
    }

  template <typename _CharT, typename _OutIter, typename _Tag>
    _OutIter
    __pad(_OutIter __s, _CharT __fill, int __padding, _Tag)
    {
      while (--__padding >= 0) { *__s = __fill; ++__s; }
      return __s;
    }

  template <typename _CharT, typename _OutIter>
    inline _OutIter
    __pad(_OutIter __s, _CharT __fill, int __padding)
    {
      return __pad(__s, __fill, __padding,
                   typename iterator_traits<_OutIter>::iterator_category());
    }

  template <typename _CharT, typename _OutIter>
    _OutIter
    __pad_numeric(_OutIter __s, ios_base::fmtflags ,
                  _CharT , int ,
                  _CharT const* , _CharT const* ,
                  _CharT const* )
  {

      return __s;
    }


  template <typename _CharT>
    ostreambuf_iterator<_CharT>
    __pad_numeric(ostreambuf_iterator<_CharT> __s, ios_base::fmtflags __flags,
                  _CharT __fill, int __width, _CharT const* __first,
                  _CharT const* __middle, _CharT const* __last)
    {
      typedef ostreambuf_iterator<_CharT> __out_iter;
      int __padding = __width - (__last - __first);
      if (__padding < 0)
        __padding = 0;
      ios_base::fmtflags __aflags = __flags & ios_base::adjustfield;
      bool __testfield = __padding == 0 || __aflags == ios_base::left
                         || __aflags == ios_base::internal;


      if (__first != __middle)
        {
          if (!__testfield)
            {
              __pad(__s, __fill, __padding);
              __padding = 0;
            }
          copy(__first, __middle, __s);
        }
      __out_iter __s2 = __s;

      if (__padding && __aflags != ios_base::left)
        {
          __pad(__s2, __fill, __padding);
          __padding = 0;
        }
      __out_iter __s3 = copy(__middle, __last, __s2);
      if (__padding)
        __pad(__s3, __fill, __padding);
      return __s3;
    }

  template <typename _CharT, typename _OutIter>
    _OutIter
    num_put<_CharT, _OutIter>::
    do_put(iter_type __s, ios_base& __io, char_type __fill, bool __v) const
    {
      const _Format_cache<_CharT>* __fmt = _Format_cache<_CharT>::_S_get(__io);
      ios_base::fmtflags __flags = __io.flags();

      if ((__flags & ios_base::boolalpha) == 0)
        {
          unsigned long __uv = __v;
          return __output_integer(__s, __io, __fill, false, __uv);
        }
      else
        {
          const char_type* __first;
          const char_type* __last;
          if (__v)
            {
              __first = __fmt->_M_truename.data();
              __last = __first + __fmt->_M_truename.size();
            }
          else
            {
              __first = __fmt->_M_falsename.data();
              __last = __first + __fmt->_M_falsename.size();
            }
          copy(__first, __last, __s);
        }
      return __s;
    }





  template <typename _CharT>
    _CharT*
    __group_digits(_CharT* __s, _CharT __grsep, char const* __grouping,
                    char const* __grend, _CharT const* __first,
                    _CharT const* __last)
    {
      if (__last - __first > *__grouping)
        {
          __s = __group_digits(__s, __grsep,
              (__grouping + 1 == __grend ? __grouping : __grouping + 1),
              __grend, __first, __last - *__grouping);
          __first = __last - *__grouping;
          *__s++ = __grsep;
        }
      do
        {
          *__s++ = *__first++;
        }
      while (__first != __last);
      return __s;
    }

  template <typename _CharT, typename _OutIter, typename _ValueT>
    _OutIter
    __output_integer(_OutIter __s, ios_base& __io, _CharT __fill, bool __neg,
              _ValueT __v)
    {

      const long _M_room = numeric_limits<_ValueT>::digits10 * 2 + 4;
      _CharT __digits[_M_room];
      _CharT* __front = __digits + _M_room;
      ios_base::fmtflags __flags = __io.flags();
      const _Format_cache<_CharT>* __fmt = _Format_cache<_CharT>::_S_get(__io);
      char const* __table = __fmt->_S_literals + __fmt->_S_digits;

      ios_base::fmtflags __basefield = (__flags & __io.basefield);
      _CharT* __sign_end = __front;
      if (__basefield == ios_base::hex)
        {
          if (__flags & ios_base::uppercase)
            __table += 16;
          do
            *--__front = __table[__v & 15];
          while ((__v >>= 4) != 0);
          __sign_end = __front;
          if (__flags & ios_base::showbase)
            {
              *--__front = __fmt->_S_literals[__fmt->_S_x +
                       ((__flags & ios_base::uppercase) ? 1 : 0)];
              *--__front = __table[0];
            }
        }
      else if (__basefield == ios_base::oct)
        {
          do
            *--__front = __table[__v & 7];
          while ((__v >>= 3) != 0);
          if (__flags & ios_base::showbase
              && static_cast<char>(*__front) != __table[0])
            *--__front = __table[0];
          __sign_end = __front;
        }
      else
        {

          do
            *--__front = __table[__v % 10];
          while ((__v /= 10) != 0);
          __sign_end = __front;

          if (__neg || (__flags & ios_base::showpos))
            *--__front = __fmt->_S_literals[__fmt->_S_plus - __neg];
        }


      if (!__fmt->_M_use_grouping && !__io.width())
        return copy(__front, __digits + _M_room, __s);

      if (!__fmt->_M_use_grouping)
        return __pad_numeric(__s, __flags, __fill, __io.width(0),
                             __front, __sign_end, __digits + _M_room);

      _CharT* __p = __digits;
      while (__front < __sign_end)
        *__p++ = *__front++;
      const char* __gr = __fmt->_M_grouping.data();
      __front = __group_digits(__p, __fmt->_M_thousands_sep, __gr,
        __gr + __fmt->_M_grouping.size(), __sign_end, __digits + _M_room);
      return __pad_numeric(__s, __flags, __fill, __io.width(0),
                           __digits, __p, __front);
    }

  template <typename _CharT, typename _OutIter>
    _OutIter
    num_put<_CharT, _OutIter>::
    do_put(iter_type __s, ios_base& __io, char_type __fill, long __v) const
    {
      unsigned long __uv = __v;
      bool __neg = false;
      if (__v < 0)
        {
          __neg = true;
          __uv = -__uv;
        }
      return __output_integer(__s, __io, __fill, __neg, __uv);
    }

  template <typename _CharT, typename _OutIter>
    _OutIter
    num_put<_CharT, _OutIter>::
    do_put(iter_type __s, ios_base& __io, char_type __fill,
           unsigned long __v) const
    { return __output_integer(__s, __io, __fill, false, __v); }


  template <typename _CharT, typename _OutIter>
    _OutIter
    num_put<_CharT, _OutIter>::
    do_put(iter_type __s, ios_base& __b, char_type __fill, long long __v) const
    {
      unsigned long long __uv = __v;
      bool __neg = false;
      if (__v < 0)
        {
          __neg = true;
          __uv = -__uv;
        }
      return __output_integer(__s, __b, __fill, __neg, __uv);
    }

  template <typename _CharT, typename _OutIter>
    _OutIter
    num_put<_CharT, _OutIter>::
    do_put(iter_type __s, ios_base& __io, char_type __fill,
           unsigned long long __v) const
    { return __output_integer(__s, __io, __fill, false, __v); }



  template<typename _CharT, typename _Traits, typename _OutIter>
    _OutIter
    __output_float(_OutIter __s, ios_base& __io, _CharT __fill,
                    const char* __sptr, size_t __slen)
    {

      return __s;
    }


  template<typename _CharT, typename _Traits>
    ostreambuf_iterator<_CharT, _Traits>
    __output_float(ostreambuf_iterator<_CharT, _Traits> __s, ios_base& __io,
                   _CharT __fill, const char* __sptr, size_t __slen)
    {
      size_t __padding = __io.width() > streamsize(__slen) ?
                         __io.width() -__slen : 0;
      locale __loc = __io.getloc();
      ctype<_CharT> const& __ct = use_facet<ctype<_CharT> >(__loc);
      ios_base::fmtflags __adjfield = __io.flags() & ios_base::adjustfield;
      const char* const __eptr = __sptr + __slen;

      if (__adjfield == ios_base::internal)
       {

         if (__sptr < __eptr && (*__sptr == '+' || *__sptr == '-'))
           {
             __s = __ct.widen(*__sptr);
             ++__s;
             ++__sptr;
           }
         __s = __pad(__s, __fill, __padding);
         __padding = 0;
       }
      else if (__adjfield != ios_base::left)
        {
          __s = __pad(__s, __fill, __padding);
          __padding = 0;
        }

      char __decimal_point = *(localeconv()->decimal_point);
      const _Format_cache<_CharT>* __fmt = _Format_cache<_CharT>::_S_get(__io);
      for (; __sptr != __eptr; ++__s, ++__sptr)
       {

         if (*__sptr == __decimal_point)
           __s = __fmt->_M_decimal_point;

         else
           __s = __ct.widen(*__sptr);
       }

      if (__padding)
        __pad(__s, __fill, __padding);
      __io.width(0);
      return __s;
    }

  bool
  __build_float_format(ios_base& __io, char* __fptr, char __modifier,
                       streamsize __prec);

  template <typename _CharT, typename _OutIter>
    _OutIter
    num_put<_CharT, _OutIter>::
    do_put(iter_type __s, ios_base& __io, char_type __fill, double __v) const
    {
      const streamsize __max_prec = numeric_limits<double>::digits10 + 3;
      streamsize __prec = __io.precision();

      if (__prec > __max_prec)
        __prec = __max_prec;

      char __sbuf[__max_prec * 2];
      size_t __slen;

      char __fbuf[16];
      if (__build_float_format(__io, __fbuf, 0, __prec))
        __slen = sprintf(__sbuf, __fbuf, __prec, __v);
      else
        __slen = sprintf(__sbuf, __fbuf, __v);

      return __output_float(__s, __io, __fill, __sbuf, __slen);
    }

  template <typename _CharT, typename _OutIter>
    _OutIter
    num_put<_CharT, _OutIter>::
    do_put(iter_type __s, ios_base& __io, char_type __fill,
           long double __v) const
    {
      const streamsize __max_prec = numeric_limits<long double>::digits10 + 3;
      streamsize __prec = __io.precision();

      if (__prec > __max_prec)
        __prec = __max_prec;

      char __sbuf[__max_prec * 2];
      size_t __slen;

      char __fbuf[16];

      if (__build_float_format(__io, __fbuf, 'L', __prec))
        __slen = sprintf(__sbuf, __fbuf, __prec, __v);
      else
        __slen = sprintf(__sbuf, __fbuf, __v);

      return __output_float(__s, __io, __fill, __sbuf, __slen);
    }

  template <typename _CharT, typename _OutIter>
    _OutIter
    num_put<_CharT, _OutIter>::
    do_put(iter_type __s, ios_base& __io, char_type __fill,
           const void* __v) const
    {
      typedef ios_base::fmtflags fmtflags;
      fmtflags __fmt = __io.flags();
      fmtflags __fmtmask = ~(ios_base::showpos | ios_base::basefield
                             | ios_base::uppercase | ios_base::internal);
      __io.flags(__fmt & __fmtmask | (ios_base::hex | ios_base::showbase));
      try {
        _OutIter __s2 = __output_integer(__s, __io, __fill, false,
                                  reinterpret_cast<unsigned long>(__v));
        __io.flags(__fmt);
        return __s2;
      }
      catch (...) {
        __io.flags(__fmt);
        throw;
      }
    }





  template<typename _CharT, typename _Dummy = int>
    struct _Weekdaynames;

  template<typename _Dummy>
    struct _Weekdaynames<char, _Dummy>
    { static const char* const _S_names[14]; };

  template<typename _Dummy>
    const char* const
    _Weekdaynames<char, _Dummy>::_S_names[14] =
    {
      "Sun", "Sunday",
      "Mon", "Monday", "Tue", "Tuesday", "Wed", "Wednesday",
      "Thu", "Thursday", "Fri", "Friday", "Sat", "Saturday"
    };


  template<typename _Dummy>
    struct _Weekdaynames<wchar_t, _Dummy>
    { static const wchar_t* const _S_names[14]; };

  template<typename _Dummy>
    const wchar_t* const
    _Weekdaynames<wchar_t, _Dummy>::_S_names[14] =
    {
      L"Sun", L"Sunday",
      L"Mon", L"Monday", L"Tue", L"Tuesday", L"Wed", L"Wednesday",
      L"Thu", L"Thursday", L"Fri", L"Friday", L"Sat", L"Saturday"
    };


  template<typename _CharT, typename _Dummy = int>
    struct _Monthnames;

  template<typename _Dummy>
    struct _Monthnames<char,_Dummy>
    { static const char* const _S_names[24]; };

  template<typename _Dummy>
    const char* const
    _Monthnames<char,_Dummy>::_S_names[24] =
    {
      "Jan", "January", "Feb", "February", "Mar", "March",
      "Apr", "April", "May", "May", "Jun", "June",
      "Jul", "July", "Aug", "August", "Sep", "September",
      "Oct", "October", "Nov", "November", "Dec", "December"
    };


  template<typename _Dummy>
    struct _Monthnames<wchar_t, _Dummy>
    { static const wchar_t* const _S_names[24]; };

  template<typename _Dummy>
    const wchar_t* const
    _Monthnames<wchar_t,_Dummy>::_S_names[24] =
    {
      L"Jan", L"January", L"Feb", L"February", L"Mar", L"March",
      L"Apr", L"April", L"May", L"May", L"Jun", L"June",
      L"Jul", L"July", L"Aug", L"August", L"Sep", L"September",
      L"Oct", L"October", L"Nov", L"November", L"Dec", L"December"
    };


  template<typename _CharT, typename _InIter>
    _InIter
    time_get<_CharT, _InIter>::
    do_get_weekday(iter_type __s, iter_type __end,
                   ios_base& __io, ios_base::iostate& __err, tm* __t) const
    {
      if (!_M_daynames)
        {
          _M_daynames = new basic_string<_CharT>[14];
          for (int __i = 0; __i < 14; ++__i)
            _M_daynames[__i] = _Weekdaynames<_CharT>::_S_names[__i];
        }
      bool __at_eof = false;
      int __remain = 0;
      int __matches[14];
      iter_type __out = __match_parallel(__s, __end, 14, _M_daynames,
                                         __matches, __remain, __at_eof);
      __err = ios_base::iostate(0);
      if (__at_eof) __err |= __io.eofbit;
      if (__remain == 1 ||
          __remain == 2 && (__matches[0]>>1) == (__matches[1]>>1))
        __t->tm_wday = (__matches[0]>>1);
      else
        __err |= __io.failbit;
      return __out;
    }

  template<typename _CharT, typename _InIter>
    _InIter
    time_get<_CharT, _InIter>::
    do_get_monthname(iter_type __s, iter_type __end,
                     ios_base& __io, ios_base::iostate& __err, tm* __t) const
    {
      if (!_M_monthnames)
        {
          _M_monthnames = new basic_string<_CharT>[24];
          for (int __i = 0; __i < 24; ++__i)
            _M_monthnames[__i] = _Monthnames<_CharT>::_S_names[__i];
        }
      bool __at_eof = false;
      int __remain = 0;
      int __matches[24];
      iter_type __out = __match_parallel( __s, __end, 24, _M_monthnames,
                                          __matches, __remain, __at_eof);
      __err = ios_base::iostate(0);
      if (__at_eof) __err |= __io.eofbit;
      if (__remain == 1 ||
          __remain == 2 && (__matches[0]>>1) == (__matches[1]>>1))
        __t->tm_mon = (__matches[0]>>1);
      else
        __err |= __io.failbit;
      return __out;
    }
}
# 42 "/usr/local/include/g++-v3/bits/std_locale.h" 2 3
# 33 "/usr/local/include/g++-v3/bits/ostream.tcc" 2 3

namespace std
{
  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>::sentry::
    sentry(basic_ostream<_CharT,_Traits>& __os)
    : _M_ok(__os.good()), _M_os(__os)
    {

      if (_M_ok && __os.tie())
        __os.tie()->flush();
    }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    basic_ostream<_CharT, _Traits>::
    operator<<(__ostream_type& (*__pf)(__ostream_type&))
    {
      sentry __cerb(*this);
      if (__cerb)
        {
          try
            { __pf(*this); }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    basic_ostream<_CharT, _Traits>::
    operator<<(__ios_type& (*__pf)(__ios_type&))
    {
      sentry __cerb(*this);
      if (__cerb)
        {
          try
            { __pf(*this); }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    basic_ostream<_CharT, _Traits>::
    operator<<(ios_base& (*__pf)(ios_base&))
    {
      sentry __cerb(*this);
      if (__cerb)
        {
          try
            { __pf(*this); }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    basic_ostream<_CharT, _Traits>::operator<<(bool __n)
    {
      sentry __cerb(*this);
      if (__cerb)
        {
          try
            {
              if (_M_check_facet(_M_fnumput))
                if (_M_fnumput->put(*this, *this, this->fill(), __n).failed())
                  this->setstate(ios_base::badbit);
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    basic_ostream<_CharT, _Traits>::operator<<(long __n)
    {
      sentry __cerb(*this);
      if (__cerb)
        {
          try
            {
              char_type __c = this->fill();
              ios_base::fmtflags __fmt = this->flags() & ios_base::basefield;
              if (_M_check_facet(_M_fnumput))
                {
                  bool __b = false;
                  if (__fmt & ios_base::oct || __fmt & ios_base::hex)
                    {
                      unsigned long __l = static_cast<unsigned long>(__n);
                      __b = _M_fnumput->put(*this, *this, __c, __l).failed();
                    }
                  else
                    __b = _M_fnumput->put(*this, *this, __c, __n).failed();
                  if (__b)
                    this->setstate(ios_base::badbit);
                }
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    basic_ostream<_CharT, _Traits>::operator<<(unsigned long __n)
    {
      sentry __cerb(*this);
      if (__cerb)
        {
          try
            {
              if (_M_check_facet(_M_fnumput))
                if (_M_fnumput->put(*this, *this, this->fill(), __n).failed())
                  this->setstate(ios_base::badbit);
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return *this;
    }


  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    basic_ostream<_CharT, _Traits>::operator<<(long long __n)
    {
      sentry __cerb(*this);
      if (__cerb)
        {
          try
            {
              char_type __c = this->fill();
              ios_base::fmtflags __fmt = this->flags() & ios_base::basefield;
              if (_M_check_facet(_M_fnumput))
                {
                  bool __b = false;
                  if (__fmt & ios_base::oct || __fmt & ios_base::hex)
                    {
                      unsigned long long __l;
                      __l = static_cast<unsigned long long>(__n);
                      __b = _M_fnumput->put(*this, *this, __c, __l).failed();
                    }
                  else
                    __b = _M_fnumput->put(*this, *this, __c, __n).failed();
                  if (__b)
                    this->setstate(ios_base::badbit);
                }
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    basic_ostream<_CharT, _Traits>::operator<<(unsigned long long __n)
    {
      sentry __cerb(*this);
      if (__cerb)
        {
          try
            {
              if (_M_check_facet(_M_fnumput))
                if (_M_fnumput->put(*this, *this, this->fill(), __n).failed())
                  this->setstate(ios_base::badbit);
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return *this;
    }


  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    basic_ostream<_CharT, _Traits>::operator<<(double __n)
    {
      sentry __cerb(*this);
      if (__cerb)
        {
          try
            {
              if (_M_check_facet(_M_fnumput))
                if (_M_fnumput->put(*this, *this, this->fill(), __n).failed())
                  this->setstate(ios_base::badbit);
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    basic_ostream<_CharT, _Traits>::operator<<(long double __n)
    {
      sentry __cerb(*this);
      if (__cerb)
        {
          try
            {
              if (_M_check_facet(_M_fnumput))
                if (_M_fnumput->put(*this, *this, this->fill(), __n).failed())
                  this->setstate(ios_base::badbit);
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    basic_ostream<_CharT, _Traits>::operator<<(const void* __n)
    {
      sentry __cerb(*this);
      if (__cerb)
        {
          try
            {
              if (_M_check_facet(_M_fnumput))
                if (_M_fnumput->put(*this, *this, this->fill(), __n).failed())
                  this->setstate(ios_base::badbit);
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    basic_ostream<_CharT, _Traits>::operator<<(__streambuf_type* __sbin)
    {
      streamsize __xtrct = 0;
      __streambuf_type* __sbout = this->rdbuf();
      sentry __cerb(*this);
      if (__sbin && __cerb)
        __xtrct = __copy_streambufs(*this, __sbin, __sbout);
      if (!__sbin || !__xtrct)
        this->setstate(ios_base::failbit);
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    basic_ostream<_CharT, _Traits>::put(char_type __c)
    {
      sentry __cerb(*this);
      if (__cerb)
        {
          int_type __put = rdbuf()->sputc(__c);
          if (__put != traits_type::to_int_type(__c))
            this->setstate(ios_base::badbit);
        }
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    basic_ostream<_CharT, _Traits>::write(const _CharT* __s, streamsize __n)
    {
      sentry __cerb(*this);
      if (__cerb)
        {
          streamsize __put = this->rdbuf()->sputn(__s, __n);
          if ( __put != __n)
            this->setstate(ios_base::badbit);
        }
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    basic_ostream<_CharT, _Traits>::flush()
    {
      sentry __cerb(*this);
      if (__cerb)
        {
          if (this->rdbuf() && this->rdbuf()->pubsync() == -1)
            this->setstate(ios_base::badbit);
        }
      return *this;
    }

  template<typename _CharT, typename _Traits>
    typename basic_ostream<_CharT, _Traits>::pos_type
    basic_ostream<_CharT, _Traits>::tellp()
    {
      pos_type __ret = pos_type(-1);
      bool __testok = this->fail() != true;

      if (__testok)
        __ret = this->rdbuf()->pubseekoff(0, ios_base::cur, ios_base::out);
      return __ret;
    }


  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    basic_ostream<_CharT, _Traits>::seekp(pos_type __pos)
    {
      bool __testok = this->fail() != true;

      if (__testok)
        {


          pos_type __err = this->rdbuf()->pubseekpos(__pos, ios_base::out);


          if (__err == pos_type(off_type(-1)))
            this->setstate(failbit);

        }
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    basic_ostream<_CharT, _Traits>::
    seekp(off_type __off, ios_base::seekdir __d)
    {
      bool __testok = this->fail() != true;

      if (__testok)
        {


          pos_type __err = this->rdbuf()->pubseekoff(__off, __d,
                                                     ios_base::out);


          if (__err == pos_type(off_type(-1)))
            this->setstate(failbit);
        }

      return *this;
    }
# 457 "/usr/local/include/g++-v3/bits/ostream.tcc" 3
  template<typename _CharT, typename _Traits>
    void
    __pad_char(basic_ios<_CharT, _Traits>& __ios,
               _CharT* __news, const _CharT* __olds,
               const streamsize __newlen, const streamsize __oldlen)
    {
      typedef _CharT char_type;
      typedef _Traits traits_type;
      typedef typename traits_type::int_type int_type;

      int_type __plen = static_cast<size_t>(__newlen - __oldlen);
      char_type* __pads = static_cast<char_type*>(__builtin_alloca(sizeof(char_type) * __plen));
      traits_type::assign(__pads, __plen, __ios.fill());

      char_type* __beg;
      char_type* __end;
      size_t __mod = 0;
      size_t __beglen;
      ios_base::fmtflags __fmt = __ios.flags() & ios_base::adjustfield;

      if (__fmt == ios_base::left)
        {

          __beg = const_cast<char_type*>(__olds);
          __beglen = __oldlen;
          __end = __pads;
        }
      else if (__fmt == ios_base::internal)
        {



          typedef _Format_cache<_CharT> __cache_type;
          __cache_type const* ___fmt = __cache_type::_S_get(__ios);
          const char_type* __minus = traits_type::find(__olds, __oldlen,
                                                       ___fmt->_S_minus);
          const char_type* __plus = traits_type::find(__olds, __oldlen,
                                                      ___fmt->_S_plus);
          bool __testsign = __minus || __plus;
          bool __testhex = __olds[0] == '0'
                           && (__olds[1] == 'x' || __olds[1] == 'X');

          if (__testhex)
            {
              __news[0] = __olds[0];
              __news[1] = __olds[1];
              __mod += 2;
              __beg = const_cast<char_type*>(__olds + __mod);
              __beglen = __oldlen - __mod;
              __end = __pads;
            }
          else if (__testsign)
            {
              __mod += __plen;
              const char_type* __sign = __minus ? __minus + 1: __plus + 1;
              __beg = const_cast<char_type*>(__olds);
              __beglen = __sign - __olds;
              __end = const_cast<char_type*>(__sign + __plen);
              traits_type::copy(__news + __beglen, __pads, __plen);
            }
          else
            {

              __beg = __pads;
              __beglen = __plen;
              __end = const_cast<char_type*>(__olds);
            }
        }
      else
        {

          __beg = __pads;
          __beglen = __plen;
          __end = const_cast<char_type*>(__olds);
        }

      traits_type::copy(__news, __beg, __beglen);
      traits_type::copy(__news + __beglen, __end, __newlen - __beglen - __mod);
    }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __out, _CharT __c)
    {
      typedef basic_ostream<_CharT, _Traits> __ostream_type;
      typename __ostream_type::sentry __cerb(__out);
      if (__cerb)
        {
          try
            {
              streamsize __w = __out.width();
              _CharT* __pads = static_cast<_CharT*>(__builtin_alloca(sizeof(_CharT) * __w));
              __pads[0] = __c;
              streamsize __len = 1;
              if (__w > __len)
                {
                  __pad_char(__out, __pads, &__c, __w, __len);
                  __len = __w;
                }
              __out.write(__pads, __len);
              __out.width(0);
            }
          catch(exception& __fail)
            {


              __out.setstate(ios_base::badbit);
              if ((__out.exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return __out;
    }


  template <class _Traits>
    basic_ostream<char, _Traits>&
    operator<<(basic_ostream<char, _Traits>& __out, char __c)
    {
      typedef basic_ostream<char, _Traits> __ostream_type;
      typename __ostream_type::sentry __cerb(__out);
      if (__cerb)
        {
          try
            {
              streamsize __w = __out.width();
              char* __pads = static_cast<char*>(__builtin_alloca(__w + 1));
              __pads[0] = __c;
              streamsize __len = 1;
              if (__w > __len)
                {
                  __pad_char(__out, __pads, &__c, __w, __len);
                  __len = __w;
                }
              __out.write(__pads, __len);
              __out.width(0);
            }
          catch(exception& __fail)
            {


              __out.setstate(ios_base::badbit);
              if ((__out.exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return __out;
     }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __out, const _CharT* __s)
    {
      typedef basic_ostream<_CharT, _Traits> __ostream_type;
      typename __ostream_type::sentry __cerb(__out);
      if (__cerb)
        {
          try
            {
              streamsize __w = __out.width();
              _CharT* __pads = static_cast<_CharT*>(__builtin_alloca(sizeof(_CharT) * __w));
              streamsize __len = static_cast<streamsize>(_Traits::length(__s));
              if (__w > __len)
                {
                  __pad_char(__out, __pads, __s, __w, __len);
                  __s = __pads;
                  __len = __w;
                }
              __out.write(__s, __len);
              __out.width(0);
            }
          catch(exception& __fail)
            {


              __out.setstate(ios_base::badbit);
              if ((__out.exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return __out;
    }

  template<typename _CharT, typename _Traits>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __out, const char* __s)
    {
      typedef basic_ostream<_CharT, _Traits> __ostream_type;


      typedef char_traits<char> __ctraits_type;

      typename __ostream_type::sentry __cerb(__out);
      if (__cerb)
        {
          size_t __clen = __ctraits_type::length(__s);
          _CharT* __ws = static_cast<_CharT*>(__builtin_alloca(sizeof(_CharT) * (__clen + 1)));
          for (size_t __i = 0; __i <= __clen; ++__i)
            __ws[__i] = __out.widen(__s[__i]);
          _CharT* __str = __ws;

          try
            {
              streamsize __len = static_cast<streamsize>(__clen);
              streamsize __w = __out.width();
              _CharT* __pads = static_cast<_CharT*>(__builtin_alloca(sizeof(_CharT) * __w));

              if (__w > __len)
                {
                  __pad_char(__out, __pads, __ws, __w, __len);
                  __str = __pads;
                  __len = __w;
                }
              __out.write(__str, __len);
              __out.width(0);
            }
          catch(exception& __fail)
            {


              __out.setstate(ios_base::badbit);
              if ((__out.exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return __out;
    }


  template<class _Traits>
    basic_ostream<char, _Traits>&
    operator<<(basic_ostream<char, _Traits>& __out, const char* __s)
    {
      typedef basic_ostream<char, _Traits> __ostream_type;
      typename __ostream_type::sentry __cerb(__out);
      if (__cerb)
        {
          try
            {
              streamsize __w = __out.width();
              char* __pads = static_cast<char*>(__builtin_alloca(__w));
              streamsize __len = static_cast<streamsize>(_Traits::length(__s));
              if (__w > __len)
                {
                  __pad_char(__out, __pads, __s, __w, __len);
                  __s = __pads;
                  __len = __w;
                }
              __out.write(__s, __len);
              __out.width(0);
            }
          catch(exception& __fail)
            {


              __out.setstate(ios_base::badbit);
              if ((__out.exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return __out;
    }


  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_ostream<_CharT, _Traits>&
    operator<<(basic_ostream<_CharT, _Traits>& __out,
               const basic_string<_CharT, _Traits, _Alloc>& __str)
    {
      typedef basic_ostream<_CharT, _Traits> __ostream_type;
      typename __ostream_type::sentry __cerb(__out);
      if (__cerb)
        {
          const _CharT* __s = __str.data();
          streamsize __w = __out.width();
          _CharT* __pads = static_cast<_CharT*>(__builtin_alloca(sizeof(_CharT) * __w));
          streamsize __len = static_cast<streamsize>(__str.size());



          if (__w > __len)
            {
              __pad_char(__out, __pads, __s, __w, __len);
              __s = __pads;
              __len = __w;
            }
          streamsize __res = __out.rdbuf()->sputn(__s, __len);
          __out.width(0);
          if (__res != __len)
            __out.setstate(ios_base::failbit);
        }
      return __out;
    }
}
# 279 "/usr/local/include/g++-v3/bits/std_ostream.h" 2 3
# 41 "/usr/local/include/g++-v3/bits/std_iostream.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_istream.h" 1 3
# 38 "/usr/local/include/g++-v3/bits/std_istream.h" 3

# 1 "/usr/local/include/g++-v3/bits/std_ios.h" 1 3
# 40 "/usr/local/include/g++-v3/bits/std_istream.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_limits.h" 1 3
# 41 "/usr/local/include/g++-v3/bits/std_istream.h" 2 3

namespace std
{

  template<typename _CharT, typename _Traits>
    class basic_istream : virtual public basic_ios<_CharT, _Traits>
    {
    public:

      typedef _CharT char_type;
      typedef typename _Traits::int_type int_type;
      typedef typename _Traits::pos_type pos_type;
      typedef typename _Traits::off_type off_type;
      typedef _Traits traits_type;


      typedef basic_streambuf<_CharT, _Traits> __streambuf_type;
      typedef basic_ios<_CharT, _Traits> __ios_type;
      typedef basic_istream<_CharT, _Traits> __istream_type;
      typedef istreambuf_iterator<_CharT, _Traits> __istreambuf_iter;
      typedef num_get<_CharT, __istreambuf_iter> __numget_type;
      typedef ctype<_CharT> __ctype_type;

    protected:

      streamsize _M_gcount;

    public:

      explicit
      basic_istream(__streambuf_type* __sb)
      {
        this->init(__sb);
        _M_gcount = streamsize(0);
      }

      virtual
      ~basic_istream()
      { _M_gcount = streamsize(0); }


      class sentry;
      friend class sentry;



      __istream_type&
      operator>>(__istream_type& (*__pf)(__istream_type&));

      __istream_type&
      operator>>(__ios_type& (*__pf)(__ios_type&));

      __istream_type&
      operator>>(ios_base& (*__pf)(ios_base&));


      __istream_type&
      operator>>(bool& __n);

      __istream_type&
      operator>>(short& __n);

      __istream_type&
      operator>>(unsigned short& __n);

      __istream_type&
      operator>>(int& __n);

      __istream_type&
      operator>>(unsigned int& __n);

      __istream_type&
      operator>>(long& __n);

      __istream_type&
      operator>>(unsigned long& __n);


      __istream_type&
      operator>>(long long& __n);

      __istream_type&
      operator>>(unsigned long long& __n);


      __istream_type&
      operator>>(float& __f);

      __istream_type&
      operator>>(double& __f);

      __istream_type&
      operator>>(long double& __f);

      __istream_type&
      operator>>(void*& __p);

      __istream_type&
      operator>>(__streambuf_type* __sb);


      inline streamsize
      gcount(void) const
      { return _M_gcount; }

      int_type
      get(void);

      __istream_type&
      get(char_type& __c);

      __istream_type&
      get(char_type* __s, streamsize __n, char_type __delim);

      inline __istream_type&
      get(char_type* __s, streamsize __n)
      { return get(__s, __n, this->widen('\n')); }

      __istream_type&
      get(__streambuf_type& __sb, char_type __delim);

      inline __istream_type&
      get(__streambuf_type& __sb)
      { return get(__sb, this->widen('\n')); }

      __istream_type&
      getline(char_type* __s, streamsize __n, char_type __delim);

      inline __istream_type&
      getline(char_type* __s, streamsize __n)
      { return getline(__s, __n, this->widen('\n')); }

      __istream_type&
      ignore(streamsize __n = 1, int_type __delim = traits_type::eof());

      int_type
      peek(void);

      __istream_type&
      read(char_type* __s, streamsize __n);

      streamsize
      readsome(char_type* __s, streamsize __n);

      __istream_type&
      putback(char_type __c);

      __istream_type&
      unget(void);

      int
      sync(void);

      pos_type
      tellg(void);

      __istream_type&
      seekg(pos_type);

      __istream_type&
      seekg(off_type, ios_base::seekdir);

    private:


      __istream_type&
      operator=(const __istream_type&);

      basic_istream(const __istream_type&);

    };

  template<typename _CharT, typename _Traits>
    class basic_istream<_CharT, _Traits>::sentry
    {
    public:
      typedef _Traits traits_type;
      typedef basic_streambuf<_CharT, _Traits> __streambuf_type;
      typedef basic_istream<_CharT, _Traits> __istream_type;
      typedef typename __istream_type::__ctype_type __ctype_type;
      typedef typename _Traits::int_type __int_type;

      explicit
      sentry(basic_istream<_CharT, _Traits>& __is, bool __noskipws = false);

      operator bool() { return _M_ok; }

    private:
      bool _M_ok;
    };


  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    operator>>(basic_istream<_CharT, _Traits>& __in, _CharT& __c);

  template<class _Traits>
    basic_istream<char, _Traits>&
    operator>>(basic_istream<char, _Traits>& __in, unsigned char& __c)
    { return (__in >> reinterpret_cast<char&>(__c)); }

  template<class _Traits>
    basic_istream<char, _Traits>&
    operator>>(basic_istream<char, _Traits>& __in, signed char& __c)
    { return (__in >> reinterpret_cast<char&>(__c)); }

  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    operator>>(basic_istream<_CharT, _Traits>& __in, _CharT* __s);

  template<class _Traits>
    basic_istream<char,_Traits>&
    operator>>(basic_istream<char,_Traits>& __in, unsigned char* __s)
    { return (__in >> reinterpret_cast<char*>(__s)); }

  template<class _Traits>
    basic_istream<char,_Traits>&
    operator>>(basic_istream<char,_Traits>& __in, signed char* __s)
    { return (__in >> reinterpret_cast<char*>(__s)); }


  template<typename _CharT, typename _Traits>
    class basic_iostream
    : public basic_istream<_CharT, _Traits>,
      public basic_ostream<_CharT, _Traits>
    {
    public:

      typedef basic_istream<_CharT, _Traits> __istream_type;
      typedef basic_ostream<_CharT, _Traits> __ostream_type;

      explicit
      basic_iostream(basic_streambuf<_CharT, _Traits>* __sb)
      : __istream_type(__sb), __ostream_type(__sb)
      { }

      virtual
      ~basic_iostream() { }
    };


  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    ws(basic_istream<_CharT, _Traits>& __is);
}




# 1 "/usr/local/include/g++-v3/bits/istream.tcc" 1 3
# 32 "/usr/local/include/g++-v3/bits/istream.tcc" 3
# 1 "/usr/local/include/g++-v3/bits/std_locale.h" 1 3
# 33 "/usr/local/include/g++-v3/bits/istream.tcc" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_ostream.h" 1 3
# 34 "/usr/local/include/g++-v3/bits/istream.tcc" 2 3

namespace std
{
  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>::sentry::
    sentry(basic_istream<_CharT, _Traits>& __in, bool __noskipws)
    {
      if (__in.good())
        {
          if (__in.tie())
            __in.tie()->flush();
          if (!__noskipws && (__in.flags() & ios_base::skipws))
            {
              const __int_type __eof = traits_type::eof();
              const __ctype_type* __ctype = __in._M_get_fctype_ios();
              __streambuf_type* __sb = __in.rdbuf();
              __int_type __c = __sb->sgetc();

              while (__c != __eof && __ctype->is(ctype_base::space, __c))
                __c = __sb->snextc();



              if (__c == __eof)
                __in.setstate(ios_base::eofbit);

            }
        }

      if (__in.good())
        _M_ok = true;
      else
        {
          _M_ok = false;
          __in.setstate(ios_base::failbit);
        }
    }

  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    basic_istream<_CharT, _Traits>::
    operator>>(__istream_type& (*__pf)(__istream_type&))
    {
      __pf(*this);
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    basic_istream<_CharT, _Traits>::
    operator>>(__ios_type& (*__pf)(__ios_type&))
    {
      __pf(*this);
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    basic_istream<_CharT, _Traits>::
    operator>>(ios_base& (*__pf)(ios_base&))
    {
      __pf(*this);
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    basic_istream<_CharT, _Traits>::
    operator>>(bool& __n)
    {
      sentry __cerb(*this, false);
      if (__cerb)
        {
          try
            {
              ios_base::iostate __err = ios_base::iostate(ios_base::goodbit);
              if (_M_check_facet(_M_fnumget))
                _M_fnumget->get(*this, 0, *this, __err, __n);
              this->setstate(__err);
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    basic_istream<_CharT, _Traits>::
    operator>>(short& __n)
    {
      sentry __cerb(*this, false);
      if (__cerb)
        {
          try
            {
              ios_base::iostate __err = ios_base::iostate(ios_base::goodbit);
              if (_M_check_facet(_M_fnumget))
                _M_fnumget->get(*this, 0, *this, __err, __n);
              this->setstate(__err);
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    basic_istream<_CharT, _Traits>::
    operator>>(unsigned short& __n)
    {
      sentry __cerb(*this, false);
      if (__cerb)
        {
          try
            {
              ios_base::iostate __err = ios_base::iostate(ios_base::goodbit);
              if (_M_check_facet(_M_fnumget))
                _M_fnumget->get(*this, 0, *this, __err, __n);
              this->setstate(__err);
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    basic_istream<_CharT, _Traits>::
    operator>>(int& __n)
    {
      sentry __cerb(*this, false);
      if (__cerb)
        {
          try
            {
              ios_base::iostate __err = ios_base::iostate(ios_base::goodbit);
              if (_M_check_facet(_M_fnumget))
                _M_fnumget->get(*this, 0, *this, __err, __n);
              this->setstate(__err);
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    basic_istream<_CharT, _Traits>::
    operator>>(unsigned int& __n)
    {
      sentry __cerb(*this, false);
      if (__cerb)
        {
          try
            {
              ios_base::iostate __err = ios_base::iostate(ios_base::goodbit);
              if (_M_check_facet(_M_fnumget))
                _M_fnumget->get(*this, 0, *this, __err, __n);
              this->setstate(__err);
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    basic_istream<_CharT, _Traits>::
    operator>>(long& __n)
    {
      sentry __cerb(*this, false);
      if (__cerb)
        {
          try
            {
              ios_base::iostate __err = ios_base::iostate(ios_base::goodbit);
              if (_M_check_facet(_M_fnumget))
                _M_fnumget->get(*this, 0, *this, __err, __n);
              this->setstate(__err);
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    basic_istream<_CharT, _Traits>::
    operator>>(unsigned long& __n)
    {
      sentry __cerb(*this, false);
      if (__cerb)
        {
          try
            {
              ios_base::iostate __err = ios_base::iostate(ios_base::goodbit);
              if (_M_check_facet(_M_fnumget))
                _M_fnumget->get(*this, 0, *this, __err, __n);
              this->setstate(__err);
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return *this;
    }


  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    basic_istream<_CharT, _Traits>::
    operator>>(long long& __n)
    {
      sentry __cerb(*this, false);
      if (__cerb)
        {
          try
            {
              ios_base::iostate __err = ios_base::iostate(ios_base::goodbit);
              if (_M_check_facet(_M_fnumget))
                _M_fnumget->get(*this, 0, *this, __err, __n);
              this->setstate(__err);
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
              throw;
            }
        }
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    basic_istream<_CharT, _Traits>::
    operator>>(unsigned long long& __n)
    {
      sentry __cerb(*this, false);
      if (__cerb)
        {
          try
            {
              ios_base::iostate __err = ios_base::iostate(ios_base::goodbit);
              if (_M_check_facet(_M_fnumget))
                _M_fnumget->get(*this, 0, *this, __err, __n);
              this->setstate(__err);
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return *this;
    }


  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    basic_istream<_CharT, _Traits>::
    operator>>(float& __n)
    {
      sentry __cerb(*this, false);
      if (__cerb)
        {
          try
            {
              ios_base::iostate __err = ios_base::iostate(ios_base::goodbit);
              if (_M_check_facet(_M_fnumget))
                _M_fnumget->get(*this, 0, *this, __err, __n);
              this->setstate(__err);
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    basic_istream<_CharT, _Traits>::
    operator>>(double& __n)
    {
      sentry __cerb(*this, false);
      if (__cerb)
        {
          try
            {
              ios_base::iostate __err = ios_base::iostate(ios_base::goodbit);
              if (_M_check_facet(_M_fnumget))
                _M_fnumget->get(*this, 0, *this, __err, __n);
              this->setstate(__err);
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    basic_istream<_CharT, _Traits>::
    operator>>(long double& __n)
    {
      sentry __cerb(*this, false);
      if (__cerb)
        {
          try
            {
              ios_base::iostate __err = ios_base::iostate(ios_base::goodbit);
              if (_M_check_facet(_M_fnumget))
                _M_fnumget->get(*this, 0, *this, __err, __n);
              this->setstate(__err);
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    basic_istream<_CharT, _Traits>::
    operator>>(void*& __n)
    {
      sentry __cerb(*this, false);
      if (__cerb)
        {
          try
            {
              ios_base::iostate __err = ios_base::iostate(ios_base::goodbit);
              if (_M_check_facet(_M_fnumget))
                _M_fnumget->get(*this, 0, *this, __err, __n);
              this->setstate(__err);
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    basic_istream<_CharT, _Traits>::
    operator>>(__streambuf_type* __sbout)
    {
      streamsize __xtrct = 0;
      __streambuf_type* __sbin = this->rdbuf();
      sentry __cerb(*this, false);
      if (__sbout && __cerb)
        __xtrct = __copy_streambufs(*this, __sbin, __sbout);
      if (!__sbout || !__xtrct)
        this->setstate(ios_base::failbit);
      return *this;
    }

  template<typename _CharT, typename _Traits>
    typename basic_istream<_CharT, _Traits>::int_type
    basic_istream<_CharT, _Traits>::
    get(void)
    {
      const int_type __eof = traits_type::eof();
      int_type __c = __eof;
      _M_gcount = 0;
      sentry __cerb(*this, true);
      if (__cerb)
        {
          try
            {
              __c = this->rdbuf()->sbumpc();

              if (__c != __eof)
                _M_gcount = 1;
              else
                this->setstate(ios_base::eofbit | ios_base::failbit);
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return __c;
    }

  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    basic_istream<_CharT, _Traits>::
    get(char_type& __c)
    {
      _M_gcount = 0;
      sentry __cerb(*this, true);
      if (__cerb)
        {
          try
            {
              const int_type __eof = traits_type::eof();
              int_type __bufval = this->rdbuf()->sbumpc();

              if (__bufval != __eof)
                {
                  _M_gcount = 1;
                  __c = traits_type::to_char_type(__bufval);
                }
              else
                this->setstate(ios_base::eofbit | ios_base::failbit);
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    basic_istream<_CharT, _Traits>::
    get(char_type* __s, streamsize __n, char_type __delim)
    {
      _M_gcount = 0;
      sentry __cerb(*this, true);
      if (__cerb && __n > 1)
        {
          try
            {
              const int_type __idelim = traits_type::to_int_type(__delim);
              const int_type __eof = traits_type::eof();
              __streambuf_type* __sb = this->rdbuf();
              int_type __c = __sb->sbumpc();
              bool __testdelim = __c == __idelim;
              bool __testeof = __c == __eof;

              while (_M_gcount < __n - 1 && !__testeof && !__testdelim)
                {
                  *__s++ = traits_type::to_char_type(__c);
                  ++_M_gcount;
                  __c = __sb->sbumpc();
                  __testeof = __c == __eof;
                  __testdelim = __c == __idelim;
                }
              if (__testdelim || _M_gcount == __n - 1)
                __sb->sputbackc(__c);
              if (__testeof)
                this->setstate(ios_base::eofbit);
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      *__s = char_type();
      if (!_M_gcount)
        this->setstate(ios_base::failbit);
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    basic_istream<_CharT, _Traits>::
    get(__streambuf_type& __sb, char_type __delim)
    {
      _M_gcount = 0;
      sentry __cerb(*this, true);
      if (__cerb)
        {
          int_type __c;
          __streambuf_type* __this_sb = this->rdbuf();
          try
            {
              const int_type __idelim = traits_type::to_int_type(__delim);
              const int_type __eof = traits_type::eof();
              __c = __this_sb->sbumpc();
              bool __testdelim = __c == __idelim;
              bool __testeof = __c == __eof;
              bool __testput = true;

              while (!__testeof && !__testdelim
                    && (__testput = __sb.sputc(traits_type::to_char_type(__c))
                         != __eof))
                {
                  ++_M_gcount;
                  __c = __this_sb->sbumpc();
                  __testeof = __c == __eof;
                  __testdelim = __c == __idelim;
                }
              if (__testdelim || !__testput)
                __this_sb->sputbackc(traits_type::to_char_type(__c));
              if (__testeof)
                this->setstate(ios_base::eofbit);
            }
          catch(exception& __fail)
            {

              __this_sb->sputbackc(traits_type::to_char_type(__c));
            }
        }
      if (!_M_gcount)
        this->setstate(ios_base::failbit);
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    basic_istream<_CharT, _Traits>::
    getline(char_type* __s, streamsize __n, char_type __delim)
    {
      _M_gcount = 0;
      sentry __cerb(*this, true);
      if (__cerb)
        {
          try
            {
              __streambuf_type* __sb = this->rdbuf();
              int_type __c = __sb->sbumpc();
              ++_M_gcount;
              const int_type __idelim = traits_type::to_int_type(__delim);
              const int_type __eof = traits_type::eof();
              bool __testdelim = __c == __idelim;
              bool __testeof = __c == __eof;

              while (_M_gcount < __n && !__testeof && !__testdelim)
                {
                  *__s++ = traits_type::to_char_type(__c);
                  __c = __sb->sbumpc();
                  ++_M_gcount;
                  __testeof = __c == __eof;
                  __testdelim = __c == __idelim;
                }

              if (__testeof)
                {
                  --_M_gcount;
                  this->setstate(ios_base::eofbit);
                }
              else if (!__testdelim)
                {
                  --_M_gcount;
                  __sb->sputbackc(traits_type::to_char_type(__c));
                  this->setstate(ios_base::failbit);
                }
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      *__s = char_type();
      if (!_M_gcount)
        this->setstate(ios_base::failbit);
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    basic_istream<_CharT, _Traits>::
    ignore(streamsize __n, int_type __delim)
    {
      _M_gcount = 0;
      sentry __cerb(*this, true);
      if (__cerb && __n > 0)
        {
          try
            {
              const int_type __idelim = traits_type::to_int_type(__delim);
              const int_type __eof = traits_type::eof();
              __streambuf_type* __sb = this->rdbuf();
              int_type __c = __sb->sbumpc();
              bool __testdelim = __c == __idelim;
              bool __testeof = __c == __eof;

              __n = min(__n, numeric_limits<streamsize>::max());
              while (_M_gcount < __n - 1 && !__testeof && !__testdelim)
                {
                  ++_M_gcount;
                  __c = __sb->sbumpc();
                  __testeof = __c == __eof;
                  __testdelim = __c == __idelim;
                }
              if ((_M_gcount == __n - 1 && !__testeof) || __testdelim)
                ++_M_gcount;
              if (__testeof)
                this->setstate(ios_base::eofbit);
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return *this;
    }

  template<typename _CharT, typename _Traits>
    typename basic_istream<_CharT, _Traits>::int_type
    basic_istream<_CharT, _Traits>::
    peek(void)
    {
      int_type __c = traits_type::eof();
      _M_gcount = 0;
      sentry __cerb(*this, true);
      if (__cerb)
        {
          try
            { __c = this->rdbuf()->sgetc(); }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return __c;
    }

  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    basic_istream<_CharT, _Traits>::
    read(char_type* __s, streamsize __n)
    {
      _M_gcount = 0;
      sentry __cerb(*this, true);
      if (__cerb)
        {
          if (__n > 0)
            {
              try
                {
                  const int_type __eof = traits_type::eof();
                  __streambuf_type* __sb = this->rdbuf();
                  int_type __c = __sb->sbumpc();
                  bool __testeof = __c == __eof;

                  while (_M_gcount < __n - 1 && !__testeof)
                    {
                      *__s++ = traits_type::to_char_type(__c);
                      ++_M_gcount;
                      __c = __sb->sbumpc();
                      __testeof = __c == __eof;
                    }
                  if (__testeof)
                    this->setstate(ios_base::eofbit | ios_base::failbit);
                  else
                    {

                      *__s++ = traits_type::to_char_type(__c);
                      ++_M_gcount;
                    }
                }
              catch(exception& __fail)
                {


                  this->setstate(ios_base::badbit);
                  if ((this->exceptions() & ios_base::badbit) != 0)
                    throw;
                }
            }
        }
      else
        this->setstate(ios_base::failbit);
      return *this;
    }

  template<typename _CharT, typename _Traits>
    streamsize
    basic_istream<_CharT, _Traits>::
    readsome(char_type* __s, streamsize __n)
    {
      const int_type __eof = traits_type::eof();
      _M_gcount = 0;
      sentry __cerb(*this, true);
      if (__cerb)
        {
          if (__n > 0)
            {
              try
                {
                  streamsize __num = this->rdbuf()->in_avail();
                  if (__num != static_cast<streamsize>(__eof))
                    {
                      __num = min(__num, __n);
                      _M_gcount = this->rdbuf()->sgetn(__s, __num);
                    }
                  else
                    this->setstate(ios_base::eofbit);
                }
              catch(exception& __fail)
                {


                  this->setstate(ios_base::badbit);
                  if ((this->exceptions() & ios_base::badbit) != 0)
                    throw;
                }
            }
        }
      else
        this->setstate(ios_base::failbit);
      return _M_gcount;
    }

  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    basic_istream<_CharT, _Traits>::
    putback(char_type __c)
    {
      sentry __cerb(*this, true);
      if (__cerb)
        {
          try
            {
              const int_type __eof = traits_type::eof();
              __streambuf_type* __sb = this->rdbuf();
              if (!__sb || __sb->sputbackc(__c) == __eof)
                this->setstate(ios_base::badbit);
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      else
        this->setstate(ios_base::failbit);
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    basic_istream<_CharT, _Traits>::
    unget(void)
    {
      _M_gcount = 0;
      sentry __cerb(*this, true);
      if (__cerb)
        {
          try
            {
              const int_type __eof = traits_type::eof();
              __streambuf_type* __sb = this->rdbuf();
              if (!__sb || __eof == __sb->sungetc())
                this->setstate(ios_base::badbit);
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      else
        this->setstate(ios_base::failbit);
      return *this;
    }

  template<typename _CharT, typename _Traits>
    int
    basic_istream<_CharT, _Traits>::
    sync(void)
    {
      int __ret = traits_type::eof();
      _M_gcount = 0;
      sentry __cerb(*this, true);
      if (__cerb)
        {
          try
            {
              __streambuf_type* __sb = this->rdbuf();
              if (!__sb || __ret == __sb->pubsync())
                this->setstate(ios_base::badbit);
              else
                __ret = 0;
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return __ret;
    }

  template<typename _CharT, typename _Traits>
    typename basic_istream<_CharT, _Traits>::pos_type
    basic_istream<_CharT, _Traits>::
    tellg(void)
    {
      pos_type __ret = pos_type(-1);
      _M_gcount = 0;
      sentry __cerb(*this, true);
      if (__cerb)
        {
          try
            {
             __ret = this->rdbuf()->pubseekoff(0, ios_base::cur, ios_base::in);
            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return __ret;
    }


  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    basic_istream<_CharT, _Traits>::
    seekg(pos_type __pos)
    {
      _M_gcount = 0;
      sentry __cerb(*this, true);
      if (__cerb)
        {
          try
            {


              pos_type __err = this->rdbuf()->pubseekpos(__pos, ios_base::in);


              if (__err == pos_type(off_type(-1)))
                this->setstate(failbit);

            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return *this;
    }

  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    basic_istream<_CharT, _Traits>::
    seekg(off_type __off, ios_base::seekdir __dir)
    {
      _M_gcount = 0;
      sentry __cerb(*this, true);
      if (__cerb)
        {
          try
            {


              pos_type __err = this->rdbuf()->pubseekoff(__off, __dir,
                                                         ios_base::in);


              if (__err == pos_type(off_type(-1)))
                this->setstate(failbit);

            }
          catch(exception& __fail)
            {


              this->setstate(ios_base::badbit);
              if ((this->exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      return *this;
    }


  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    operator>>(basic_istream<_CharT, _Traits>& __in, _CharT& __c)
    {
      typedef basic_istream<_CharT, _Traits> __istream_type;
      typename __istream_type::sentry __cerb(__in, false);
      if (__cerb)
        {
          try
            { __in.get(__c); }
          catch(exception& __fail)
            {


              __in.setstate(ios_base::badbit);
              if ((__in.exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      else
        __in.setstate(ios_base::failbit);
      return __in;
    }

  template<typename _CharT, typename _Traits>
    basic_istream<_CharT, _Traits>&
    operator>>(basic_istream<_CharT, _Traits>& __in, _CharT* __s)
    {
      typedef basic_istream<_CharT, _Traits> __istream_type;
      typedef typename __istream_type::__streambuf_type __streambuf_type;
      typedef typename _Traits::int_type int_type;
      typedef _CharT char_type;
      typedef ctype<_CharT> __ctype_type;
      streamsize __extracted = 0;

      typename __istream_type::sentry __cerb(__in, false);
      if (__cerb)
        {
          try
            {

              streamsize __num = __in.width();
              if (__num == 0)
                __num = numeric_limits<streamsize>::max();

              __streambuf_type* __sb = __in.rdbuf();
              const __ctype_type* __ctype = __in._M_get_fctype_ios();
              int_type __c = __sb->sbumpc();
              const int_type __eof = _Traits::eof();
              bool __testsp = __ctype->is(ctype_base::space, __c);
              bool __testeof = __c == __eof;

              while (__extracted < __num - 1 && !__testeof && !__testsp)
                {
                  *__s++ = __c;
                  ++__extracted;
                  __c = __sb->sbumpc();
                  __testeof = __c == __eof;
                  __testsp = __ctype->is(ctype_base::space, __c);
                }

              if (!__testeof)
                __sb->sputbackc(__c);
              else
                __in.setstate(ios_base::eofbit);



              *__s = char_type();

              __in.width(0);
            }
          catch(exception& __fail)
            {


              __in.setstate(ios_base::badbit);
              if ((__in.exceptions() & ios_base::badbit) != 0)
                throw;
            }
        }
      if (!__extracted)
        __in.setstate(ios_base::failbit);
      return __in;
    }


  template<typename _CharT, typename _Traits>
    basic_istream<_CharT,_Traits>&
    ws(basic_istream<_CharT,_Traits>& __in)
    {
      typedef basic_istream<_CharT, _Traits> __istream_type;
      typedef typename __istream_type::__streambuf_type __streambuf_type;
      typedef typename __istream_type::__ctype_type __ctype_type;
      typedef typename __istream_type::int_type __int_type;
      typedef typename __istream_type::char_type __char_type;

      __streambuf_type* __sb = __in.rdbuf();
      const __ctype_type* __ctype = __in._M_get_fctype_ios();
      const __int_type __eof = _Traits::eof();
      __int_type __c;
      bool __testeof;
      bool __testsp;

      do
        {
          __c = __sb->sbumpc();
          __testeof = __c == __eof;
          __testsp = __ctype->is(ctype_base::space, __c);
        }
      while (!__testeof && __testsp);

      if (!__testeof && !__testsp)
        __sb->sputbackc(__c);
      else
        __in.setstate(ios_base::eofbit);

      return __in;
    }


  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_istream<_CharT, _Traits>&
    operator>>(basic_istream<_CharT, _Traits>& __in,
               basic_string<_CharT, _Traits, _Alloc>& __str)
    {
      typedef basic_istream<_CharT, _Traits> __istream_type;
      typedef typename __istream_type::int_type __int_type;
      typedef typename __istream_type::__streambuf_type __streambuf_type;
      typedef typename __istream_type::__ctype_type __ctype_type;
      typedef basic_string<_CharT, _Traits, _Alloc> __string_type;
      typedef typename __string_type::size_type __size_type;
      __size_type __extracted = 0;

      typename __istream_type::sentry __cerb(__in, false);
      if (__cerb)
        {
          __str.erase();
          streamsize __w = __in.width();
          __size_type __n;
          __n = __w > 0 ? static_cast<__size_type>(__w) : __str.max_size();

          __streambuf_type* __sb = __in.rdbuf();
          const __ctype_type* __ctype = __in._M_get_fctype_ios();
          __int_type __c = __sb->sbumpc();
          const __int_type __eof = _Traits::eof();
          bool __testsp = __ctype->is(ctype_base::space, __c);
          bool __testeof = __c == __eof;

          while (__extracted < __n && !__testeof && !__testsp)
            {
              __str += _Traits::to_char_type(__c);
              ++__extracted;
              __c = __sb->sbumpc();
              __testeof = __c == __eof;
              __testsp = __ctype->is(ctype_base::space, __c);
            }
          if (!__testeof)
            __sb->sputbackc(__c);
          else
            __in.setstate(ios_base::eofbit);
          __in.width(0);
        }


      if (!__extracted)
        __in.setstate (ios_base::failbit);

      return __in;
    }

  template<typename _CharT, typename _Traits, typename _Alloc>
    basic_istream<_CharT, _Traits>&
    getline(basic_istream<_CharT, _Traits>& __in,
            basic_string<_CharT, _Traits, _Alloc>& __str, _CharT __delim)
    {
      typedef basic_istream<_CharT, _Traits> __istream_type;
      typedef typename __istream_type::int_type __int_type;
      typedef typename __istream_type::__streambuf_type __streambuf_type;
      typedef typename __istream_type::__ctype_type __ctype_type;
      typedef basic_string<_CharT, _Traits, _Alloc> __string_type;
      typedef typename __string_type::size_type __size_type;

      __size_type __extracted = 0;
      bool __testdelim = false;
      typename __istream_type::sentry __cerb(__in, true);
      if (__cerb)
        {
          __str.erase();
          __size_type __n = __str.max_size();

          __int_type __idelim = _Traits::to_int_type(__delim);
          __streambuf_type* __sb = __in.rdbuf();
          __int_type __c = __sb->sbumpc();
          const __int_type __eof = _Traits::eof();
          __testdelim = __c == __idelim;
          bool __testeof = __c == __eof;

          while (__extracted <= __n && !__testeof && !__testdelim)
            {
              __str += _Traits::to_char_type(__c);
              ++__extracted;
              __c = __sb->sbumpc();
              __testeof = __c == __eof;
              __testdelim = __c == __idelim;
            }
          if (__testeof)
            __in.setstate(ios_base::eofbit);
        }
      if (!__extracted && !__testdelim)
        __in.setstate(ios_base::failbit);
      return __in;
    }

  template<class _CharT, class _Traits, class _Alloc>
    inline basic_istream<_CharT,_Traits>&
    getline(basic_istream<_CharT, _Traits>& __in,
            basic_string<_CharT,_Traits,_Alloc>& __str)
    { return getline(__in, __str, __in.widen('\n')); }
}
# 291 "/usr/local/include/g++-v3/bits/std_istream.h" 2 3
# 42 "/usr/local/include/g++-v3/bits/std_iostream.h" 2 3

namespace std
{
  extern istream cin;
  extern ostream cout;
  extern ostream cerr;
  extern ostream clog;

  extern wistream wcin;
  extern wostream wcout;
  extern wostream wcerr;
  extern wostream wclog;



  static ios_base::Init __ioinit;
}
# 32 "/usr/local/include/g++-v3/iostream" 2 3
# 51 "../../../../src/aleph/uid.H" 2
# 1 "../../../../src/aleph/aleph.H" 1
# 52 "../../../../src/aleph/uid.H" 2

struct Two_Nibbles
{
  unsigned int n1 : 4;
  unsigned int n2 : 4;
};

class Uid
{
private:

  mutable uint32_t ipAddr;
  mutable uint32_t port_number;
  mutable uint64_t counter;
  mutable uint64_t random_number;

public:

  static const int stringSize = 2*(sizeof(uint32_t) + sizeof(uint32_t) +
                                   sizeof(uint64_t) + sizeof(uint64_t)) + 1;

private:

  char* stringficate(void *src_data, size_t src_size, char * result) const;

  void destringficate(void *result, size_t src_size, char *src_data);

public:

  Uid() { }

  Uid(unsigned int _ipAddr, unsigned int _counter, unsigned int _port_number);

  Uid(char* str);

  bool operator == (const Uid& uid) const;

  char* getStringUid(char* str, size_t) const;

  uint32_t getIpAddr() const { return ipAddr; }

  uint32_t get_port_number() const { return port_number; }

  uint64_t get_counter() const { return counter; }

  uint64_t get_random_number() const { return random_number; }

  void print()
  {
    std::cout << "Uid:" << std::endl
              << "    ipAddr        = " << ipAddr << std::endl
              << "    port_number   = " << port_number << std::endl
              << "    counter       = " << counter << std::endl
              << "    random_number = " << random_number << std::endl
              << std::endl;
  }
};
# 50 "../../../../src/aleph/port.H" 2

class Port: public Uid
{
public:

  Port(): Uid()
  {

  }

  Port(unsigned int _ipAddr, unsigned int _counter, unsigned int _port_number)
    : Uid(_ipAddr, _counter, _port_number)
  {

  }

  Port(char *_str): Uid(_str)
  {

  }

  char* getStringPort(char* _str, size_t str_size) const
  {
    return getStringUid(_str, str_size);
  }

};
# 9 "../../../../src/Binder/include/binder.H" 2
# 1 "../../../../src/Binder/include/basic_defs.H" 1



# 1 "/usr/include/stdint.h" 1 3
# 5 "../../../../src/Binder/include/basic_defs.H" 2
# 1 "../../../../src/aleph/uid.H" 1
# 6 "../../../../src/Binder/include/basic_defs.H" 2

typedef uint32_t Ip_Address;

typedef int64_t Logical_Timestamp;

typedef uint64_t Random_Number;

typedef Uid Message_Id;
# 10 "../../../../src/Binder/include/binder.H" 2
# 56 "../../../../src/Binder/include/binder.H"
class Site_Id : public Port
{

public:
  Site_Id(unsigned int _ipAddr,
          unsigned int _counter,
          unsigned int _port_number)
    : Port(_ipAddr, _counter, _port_number)
  {

  }


  Site_Id() :
    Port(0, 0, 0)
  {

  }

  Site_Id(Port _port) :
    Port(_port)
  {

  }

  Site_Id(char * _str) :
    Port(_str)
  {

  }
};

typedef Uid Container_Id;

typedef Uid Object_Id;

class Locator
{
  Object_Id object_id;
  Site_Id target_site_id;
  Logical_Timestamp logical_timestamp;

public:

  Locator (const Object_Id & obj_id, const Site_Id & sit_id,
           Logical_Timestamp _timestamp = 0) :
    object_id(obj_id),
    target_site_id(sit_id),
    logical_timestamp(_timestamp)
  {

  }

  Locator() :
    object_id(0, 0, 0),
    target_site_id(0, 0, 0),
    logical_timestamp(-1)
  {

  }

  const Object_Id & get_object_id() const
    {
      return object_id;
    }

  const Site_Id & get_target_site_id() const
    {
      return target_site_id;
    }

  Logical_Timestamp get_logical_timestamp() const
    {
      return logical_timestamp;
    }

  void set_logical_timestamp(Logical_Timestamp _new_timestamp)
  {
    logical_timestamp = _new_timestamp;
  }


  void increase_logical_timestamp()
    {
      logical_timestamp++;
    }
# 152 "../../../../src/Binder/include/binder.H"
  void update_locator(const Locator & newer_locator)
  {
                                                               ;
    target_site_id = newer_locator.target_site_id;
    logical_timestamp = newer_locator.logical_timestamp;
  }

  bool operator == (const Locator & locator) const
    {
      return ((object_id == locator.object_id) &&
              (target_site_id == locator.target_site_id));


    }

  Locator & operator = (const Locator & _loc)
  {


    object_id = _loc.object_id;
    target_site_id = _loc.target_site_id;
    logical_timestamp = _loc.logical_timestamp;
    return *this;
  }

  bool operator > (const Locator & _loc) const
  {
                                        ;






    return (logical_timestamp > _loc.logical_timestamp);
  }
};


class Binding : public Locator
{
  Container_Id source_container_id;
  Site_Id source_site_id;

public:

  Binding(const Locator & locator,
          const Container_Id & src_cnt_id,
          const Site_Id & src_site_id)
    : Locator(locator),
      source_container_id(src_cnt_id),
      source_site_id(src_site_id)
    {

    }

  Binding() :
    source_container_id(0, 0, 0),
    source_site_id(0, 0, 0)
  {

  }

  const Container_Id & get_source_container_id() const
    {
      return source_container_id;
    }

  const Site_Id & get_source_site_id() const
    {
      return source_site_id;
    }

  Locator & get_locator() const
  {
    return *const_cast<Locator *>(static_cast<const Locator *>(this));
  }

  Binding & operator=(const Binding & _bind)
  {
    source_container_id = _bind.source_container_id;

    source_site_id = _bind.source_site_id;

    *static_cast<Locator *>(this) = _bind.get_locator();

    return *this;
  }

};



const Logical_Timestamp INVALID_LOGICAL_TIMESTAMP = -1;

const Object_Id INVALID_OBJECT_ID(0,0,
                                  INVALID_LOGICAL_TIMESTAMP);

const Container_Id INVALID_CONTAINER_ID(0,0,0);

const Site_Id INVALID_SITE_ID(0,0,0);

const Message_Id INVALID_MESSAGE_ID(0, 0, 0);

const Locator INVALID_LOCATOR;

const Binding INVALID_BINDING;
# 6 "../../../../src/Binder/include/locator_exceptions.H" 2
# 14 "../../../../src/Binder/include/locator_exceptions.H"
class ObjectDead : public AlephExc
{
public:

  ObjectDead() : AlephExc("Object dead", OTHER)
  { }

  ObjectDead(const char* _file, int _line)
    : AlephExc("Object dead", _file, _line, OTHER)
  { }
};







class RecentBinding : public AlephExc
{
  Binding binding;

public:

  RecentBinding(const Binding & _binding) :
    AlephExc("Recent binding", OTHER),
    binding(_binding)
  {

  }

  RecentBinding(const Binding & _binding, const char* _file, int _line) :
    AlephExc("Recent binding", _file, _line, OTHER),
    binding(_binding)
  {

  }

  const Binding & get_binding() const
  {
    return binding;
  }
};







class ObjectBusy : public AlephExc
{
public:

  ObjectBusy() : AlephExc("Object busy", OTHER)
  { }

  ObjectBusy(const char* _file, int _line)
    : AlephExc("Object busy", _file, _line, OTHER)
  { }
};
# 6 "../../../../src/Binder/include/locator_calls.H" 2
# 1 "../../../../src/Binder/include/local_access_point.H" 1







# 1 "../../../../src/Binder/include/access_point.H" 1







# 1 "../../../../src/Binder/include/base_message_header.H" 1



# 1 "/usr/include/unistd.h" 1 3
# 5 "../../../../src/Binder/include/base_message_header.H" 2
# 1 "/usr/include/pthread.h" 1 3
# 6 "../../../../src/Binder/include/base_message_header.H" 2
# 1 "/usr/include/string.h" 1 3
# 7 "../../../../src/Binder/include/base_message_header.H" 2
# 1 "../../../../src/aleph/aleph.H" 1
# 8 "../../../../src/Binder/include/base_message_header.H" 2






enum Response_Code
{
  DEMRESP_REGISTRATION_OK,
  DEMRESP_INTENDED_DOUBLE_REGISTRATION,
  DEMRESP_SERVICE_NOT_FOUND,
  DEMRESP_RESPONSE_TO_SERVICE,
  DEMRESP_SHUTDOWN_GOTTEN,

  DEMRESP_INVALID,

  DEMRESP_LAST
};




enum Service_Code
{

  DEMSERV_ADD,

  DEMSERV_SEND,


  DEMSERV_SHUTDOWN,

  DEMSERV_INVALID,

  DEMSERV_LAST
};
# 53 "../../../../src/Binder/include/base_message_header.H"
class Response_Header
{
  Response_Code deamon_response_code;
  size_t response_size;
  size_t invocation_size;

protected:

  Response_Header(Response_Code _deamon_response_code) :
    deamon_response_code(_deamon_response_code),
    response_size(0),
    invocation_size(0)
  {

  }

  Response_Header() :
    deamon_response_code(DEMRESP_INVALID),
    response_size(0),
    invocation_size(0)
  {

  }

public:
  Response_Code get_deamon_response_code() const
  {
    return deamon_response_code;
  }

  void set_response_size(const size_t size)
  {
    response_size = size;
  }

  size_t get_response_size() const
  {
    return response_size;
  }

  void set_invocation_size(const size_t size)
  {
    invocation_size = size;
  }

  size_t get_invocation_size() const
  {
    return invocation_size;
  }
};







class Service_Header
{
  Service_Code deamon_service_code;

protected:

  Service_Header(Service_Code _service_code) :
    deamon_service_code(_service_code)
  {

  }

  Service_Header() :
    deamon_service_code(DEMSERV_INVALID)
  {

  }

public:
  Service_Code get_deamon_service_code() const
  {
    return deamon_service_code;
  }

};
# 163 "../../../../src/Binder/include/base_message_header.H"
class Msg_Entry_Header : public Service_Header
{

  friend class Register_Message;
  friend class Shutdown_Message;

  long client_service_code;
  size_t parameters_size;
  size_t invocation_size;

private:

  Msg_Entry_Header() :
    client_service_code(0),
    parameters_size(0),
    invocation_size(0)
  {

  }

  Msg_Entry_Header(const Service_Code system_serv_code,
                   const long _client_service_code,
                   const size_t msg_size = 0) :
    Service_Header(system_serv_code),
    client_service_code(_client_service_code),
    parameters_size(msg_size),
    invocation_size(0)
  {

  }

protected:

  Msg_Entry_Header(const long srvc_code,
                   const size_t msg_size = 0) :
    Service_Header(DEMSERV_SEND),
    client_service_code(srvc_code),
    parameters_size(msg_size - sizeof(Msg_Entry_Header)),
    invocation_size(0)
  {
                                ;
                                    ;
  }

public:

  long get_client_service_code() const
  {
    return client_service_code;
  }

  void set_parameters_size(const size_t size)
  {
    parameters_size = size;
  }

  size_t get_parameters_size() const
  {
    return parameters_size;
  }

  void set_invocation_size(const size_t size)
  {
    invocation_size = size;
  }

  size_t get_invocation_size() const
  {
    return invocation_size;
  }
};
# 274 "../../../../src/Binder/include/base_message_header.H"
class Msg_Exit_Header : public Response_Header
{
  friend class Response_For_Registration;
  friend class Shutdown_Response;

  long response_code;

private:

  Msg_Exit_Header(const Response_Code resp_type,
                  const long resp_code) :
    Response_Header(resp_type),
    response_code(resp_code)
  {

  }

  Msg_Exit_Header() :
    response_code(DEMRESP_INVALID)
  {

  }

protected:

  Msg_Exit_Header(const long resp_code) :
    Response_Header(DEMRESP_RESPONSE_TO_SERVICE),
    response_code(resp_code)
  {

  }

public:

  void set_response_code(const long resp_code)
  {
    response_code = resp_code;
  }

  long get_response_code() const
  {
    return response_code;
  }
};


class Register_Message : public Msg_Entry_Header
{
  char service_name[80];

public:
  Register_Message(const long srvc_code,
                   const char * src_serv_name) :
    Msg_Entry_Header(DEMSERV_ADD, srvc_code,
                     sizeof(*this) - sizeof(Msg_Entry_Header))
  {
    strcpy(service_name, src_serv_name);
  }

  Register_Message()
  {

  }

  char * get_service_name () const
  {
    return const_cast<char *>(service_name);
  }
};





class Response_For_Registration : public Msg_Exit_Header
{

public:
# 366 "../../../../src/Binder/include/base_message_header.H"
  Response_For_Registration(const Response_Code deam_resp_code,
                            const long resp_type = 0) :
    Msg_Exit_Header(deam_resp_code, resp_type)
  {

  }

  Response_For_Registration() :
    Msg_Exit_Header()
  {

  }

};

class Shutdown_Message : public Msg_Entry_Header
{
public:
  Shutdown_Message() :
    Msg_Entry_Header(DEMSERV_SHUTDOWN, DEMSERV_INVALID, 0)
  {

  }
};


class Shutdown_Response : public Msg_Exit_Header
{
public:
  Shutdown_Response() :
    Msg_Exit_Header(DEMRESP_SHUTDOWN_GOTTEN, 0)
    {

    }
};
# 410 "../../../../src/Binder/include/base_message_header.H"
class Deamon_Locator
{
protected:
  Deamon_Locator()
  {

  }

public:

  virtual const char * stringficate() const = 0;
};
# 9 "../../../../src/Binder/include/access_point.H" 2
# 1 "../../../../src/Binder/include/locator_exceptions.H" 1
# 10 "../../../../src/Binder/include/access_point.H" 2
# 1 "../../../../src/aleph/aleph.H" 1
# 11 "../../../../src/Binder/include/access_point.H" 2
# 1 "/usr/include/pthread.h" 1 3
# 12 "../../../../src/Binder/include/access_point.H" 2
# 46 "../../../../src/Binder/include/access_point.H"
class Access_Point
{
protected:

  Deamon_Locator * link_to_deamon;

  typedef ssize_t (*Read_Fct)(Deamon_Locator *, void *, size_t);

  typedef ssize_t (*Write_Fct)(Deamon_Locator *, const void *, size_t);

  Read_Fct readn;

  Write_Fct writen;

  unsigned int number_of_services;

  bool is_shutdown;

  GenAlloc& alloc;






  pthread_mutex_t * lock_send;


  class Register_Table_Entry
  {
    char service_name[80];

  public:
    Register_Table_Entry(const char * src_serv_name)
    {
      strcpy(service_name, src_serv_name);
    }

    char * get_service_name ()
    {
      return service_name;
    }
  };


  Register_Table_Entry ** table;
# 100 "../../../../src/Binder/include/access_point.H"
  Access_Point(unsigned int _no_of_services,
               Read_Fct _read_fct,
               Write_Fct _write_fct,
               GenAlloc & _alloc = *objectAlloc) :
    readn(_read_fct),
    writen(_write_fct),
    number_of_services(_no_of_services),
    is_shutdown(false),
    alloc(_alloc)
  {
    lock_send = static_cast<pthread_mutex_t *>
      ((Aleph::objectAlloc->alloc(sizeof(pthread_mutex_t))));

    pthread_mutex_init(lock_send, __null);

    table = construct< Register_Table_Entry * >(alloc) [_no_of_services];
    for (size_t i = 0; i < _no_of_services; i++)
      table[i] = __null;
  }

public:






  void send(const Msg_Entry_Header *request) const
    throw (std::exception, NotFound);
# 139 "../../../../src/Binder/include/access_point.H"
  void send(Msg_Entry_Header * request,
            const void * buffer, const size_t buffer_size)
    throw (std::exception, NotFound);
# 154 "../../../../src/Binder/include/access_point.H"
  void receive(Msg_Exit_Header *reply, const size_t reply_size)
    throw (std::exception, SizeFault, NotFound);






  void receive(Msg_Exit_Header * message,
               const size_t message_size,
               void * buffer,
               size_t & buffer_size)
  throw (std::exception, SizeFault, NotFound);
# 175 "../../../../src/Binder/include/access_point.H"
  void add_service(const long service_code, char * name)
    throw (std::exception, Duplicated);







  void delete_service(const long)
    throw (std::exception, NotFound);




  virtual void shutdown() = 0;




  virtual ~Access_Point()
    {
                                        ;
      pthread_mutex_destroy(lock_send);

      (Aleph::objectAlloc->dealloc(lock_send));

      for (size_t i=0; i < number_of_services; i++)
        if (table[i] != __null)
          destruct(alloc, table[i]);
      destructArray(alloc, table);
    }

};
# 9 "../../../../src/Binder/include/local_access_point.H" 2
# 1 "../../../../src/Binder/include/local_locator.H" 1



# 1 "../../../../src/Binder/include/base_message_header.H" 1
# 5 "../../../../src/Binder/include/local_locator.H" 2

class Local_Locator : public Deamon_Locator
{
  char deamon_location[255];
  int deamon_socket;

public:
  Local_Locator(const char * dem_loc)
  {
    strcpy(deamon_location, dem_loc);
  }

  const char * stringficate() const
  {
    return deamon_location;
  }

  void set_deamon_socket(int sock_id)
  {
    deamon_socket = sock_id;
  }

  int get_deamon_socket() const
  {
    return deamon_socket;
  }
};
# 10 "../../../../src/Binder/include/local_access_point.H" 2
# 1 "../../../../src/Binder/include/base_message_header.H" 1
# 11 "../../../../src/Binder/include/local_access_point.H" 2
# 1 "../../../../src/Binder/include/locator_exceptions.H" 1
# 12 "../../../../src/Binder/include/local_access_point.H" 2
# 1 "../../../../src/aleph/aleph.H" 1
# 13 "../../../../src/Binder/include/local_access_point.H" 2
# 1 "/usr/include/pthread.h" 1 3
# 14 "../../../../src/Binder/include/local_access_point.H" 2
# 23 "../../../../src/Binder/include/local_access_point.H"
# 1 "/usr/include/sys/types.h" 1 3
# 24 "../../../../src/Binder/include/local_access_point.H" 2
# 1 "/usr/include/sys/socket.h" 1 3
# 25 "../../../../src/Binder/include/local_access_point.H" 2
# 1 "/usr/include/errno.h" 1 3
# 26 "../../../../src/Binder/include/local_access_point.H" 2
# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdio.h" 1 3
# 27 "../../../../src/Binder/include/local_access_point.H" 2
# 1 "/usr/include/stdlib.h" 1 3
# 28 "../../../../src/Binder/include/local_access_point.H" 2
# 1 "/usr/include/sys/un.h" 1 3
# 22 "/usr/include/sys/un.h" 3
# 1 "/usr/include/sys/cdefs.h" 1 3
# 23 "/usr/include/sys/un.h" 2 3


# 1 "/usr/include/bits/sockaddr.h" 1 3
# 26 "/usr/include/sys/un.h" 2 3

extern "C" {


struct sockaddr_un
  {
    sa_family_t sun_family;
    char sun_path[108];
  };



# 1 "/usr/include/string.h" 1 3
# 39 "/usr/include/sys/un.h" 2 3






}
# 29 "../../../../src/Binder/include/local_access_point.H" 2
# 1 "/usr/include/sys/select.h" 1 3
# 30 "../../../../src/Binder/include/local_access_point.H" 2
# 1 "/usr/local/include/g++-v3/backward/ostream.h" 1 3
# 31 "/usr/local/include/g++-v3/backward/ostream.h" 3
# 1 "/usr/local/include/g++-v3/backward/backward_warning.h" 1 3
# 32 "/usr/local/include/g++-v3/backward/ostream.h" 2 3
# 1 "/usr/local/include/g++-v3/backward/iostream.h" 1 3
# 31 "/usr/local/include/g++-v3/backward/iostream.h" 3
# 1 "/usr/local/include/g++-v3/backward/backward_warning.h" 1 3
# 32 "/usr/local/include/g++-v3/backward/iostream.h" 2 3
# 1 "/usr/local/include/g++-v3/bits/std_iostream.h" 1 3
# 33 "/usr/local/include/g++-v3/backward/iostream.h" 2 3

using std::iostream;
using std::ostream;
using std::istream;
using std::ios;
using std::streambuf;

using std::cout;
using std::cin;
using std::cerr;
using std::clog;

using std::wcout;
using std::wcin;
using std::wcerr;
using std::wclog;


using std::ws;
using std::endl;
using std::ends;
using std::flush;
# 33 "/usr/local/include/g++-v3/backward/ostream.h" 2 3
# 31 "../../../../src/Binder/include/local_access_point.H" 2
# 1 "/usr/include/unistd.h" 1 3
# 32 "../../../../src/Binder/include/local_access_point.H" 2







class Local_Access_Point : public Access_Point
{
public:
# 50 "../../../../src/Binder/include/local_access_point.H"
  Local_Access_Point(const Local_Locator _deamon_locator,
                     unsigned int _no_of_services,
                     GenAlloc & _alloc = *objectAlloc)
    throw (std::exception, NotFound);




  void shutdown();




  ~Local_Access_Point();
};
# 7 "../../../../src/Binder/include/locator_calls.H" 2
# 1 "../../../../src/Binder/include/binder.H" 1
# 8 "../../../../src/Binder/include/locator_calls.H" 2
# 1 "../../../../src/Binder/include/basic_defs.H" 1
# 9 "../../../../src/Binder/include/locator_calls.H" 2
# 1 "../../../../src/Binder/include/local_message_header.H" 1



# 1 "/usr/include/stdint.h" 1 3
# 5 "../../../../src/Binder/include/local_message_header.H" 2
# 1 "../../../../src/Binder/include/binder.H" 1
# 6 "../../../../src/Binder/include/local_message_header.H" 2
# 1 "../../../../src/Binder/include/base_message_header.H" 1
# 7 "../../../../src/Binder/include/local_message_header.H" 2
# 1 "../../../../src/Binder/include/basic_defs.H" 1
# 8 "../../../../src/Binder/include/local_message_header.H" 2
# 1 "../../../../src/Binder/include/remote_access_point.H" 1






# 1 "../../../../src/Binder/include/access_point.H" 1
# 8 "../../../../src/Binder/include/remote_access_point.H" 2
# 1 "../../../../src/aleph/ipcClient.H" 1
# 49 "../../../../src/aleph/ipcClient.H"
# 1 "/usr/include/sys/types.h" 1 3
# 50 "../../../../src/aleph/ipcClient.H" 2
# 1 "/usr/include/sys/socket.h" 1 3
# 51 "../../../../src/aleph/ipcClient.H" 2
# 1 "/usr/include/sys/un.h" 1 3
# 52 "../../../../src/aleph/ipcClient.H" 2
# 1 "/usr/include/sys/time.h" 1 3
# 22 "/usr/include/sys/time.h" 3
# 1 "/usr/include/features.h" 1 3
# 23 "/usr/include/sys/time.h" 2 3

# 1 "/usr/include/bits/types.h" 1 3
# 25 "/usr/include/sys/time.h" 2 3

# 1 "/usr/include/time.h" 1 3
# 27 "/usr/include/sys/time.h" 2 3

# 1 "/usr/include/bits/time.h" 1 3
# 29 "/usr/include/sys/time.h" 2 3

# 1 "/usr/include/sys/select.h" 1 3
# 31 "/usr/include/sys/time.h" 2 3







extern "C" {
# 56 "/usr/include/sys/time.h" 3
struct timezone
  {
    int tz_minuteswest;
    int tz_dsttime;
  };

typedef struct timezone *__restrict __timezone_ptr_t;
# 72 "/usr/include/sys/time.h" 3
extern int gettimeofday (struct timeval *__restrict __tv,
                         __timezone_ptr_t __tz) throw ();




extern int settimeofday (__const struct timeval *__tv,
                         __const struct timezone *__tz) throw ();





extern int adjtime (__const struct timeval *__delta,
                    struct timeval *__olddelta) throw ();




enum __itimer_which
  {

    ITIMER_REAL = 0,


    ITIMER_VIRTUAL = 1,



    ITIMER_PROF = 2

  };



struct itimerval
  {

    struct timeval it_interval;

    struct timeval it_value;
  };






typedef int __itimer_which_t;




extern int getitimer (__itimer_which_t __which,
                      struct itimerval *__value) throw ();




extern int setitimer (__itimer_which_t __which,
                      __const struct itimerval *__restrict __new,
                      struct itimerval *__restrict __old) throw ();



extern int utimes (__const char *__file, __const struct timeval __tvp[2])
     throw ();
# 171 "/usr/include/sys/time.h" 3
}
# 53 "../../../../src/aleph/ipcClient.H" 2
# 1 "/usr/include/unistd.h" 1 3
# 54 "../../../../src/aleph/ipcClient.H" 2
# 1 "/usr/include/netinet/in.h" 1 3
# 55 "../../../../src/aleph/ipcClient.H" 2
# 1 "/usr/include/arpa/inet.h" 1 3
# 56 "../../../../src/aleph/ipcClient.H" 2
# 1 "/usr/include/errno.h" 1 3
# 57 "../../../../src/aleph/ipcClient.H" 2
# 1 "/usr/include/string.h" 1 3
# 58 "../../../../src/aleph/ipcClient.H" 2
# 1 "/usr/include/fcntl.h" 1 3
# 26 "/usr/include/fcntl.h" 3
# 1 "/usr/include/features.h" 1 3
# 27 "/usr/include/fcntl.h" 2 3


extern "C" {



# 1 "/usr/include/bits/fcntl.h" 1 3
# 25 "/usr/include/bits/fcntl.h" 3
# 1 "/usr/include/sys/types.h" 1 3
# 26 "/usr/include/bits/fcntl.h" 2 3
# 136 "/usr/include/bits/fcntl.h" 3
struct flock
  {
    short int l_type;
    short int l_whence;

    __off_t l_start;
    __off_t l_len;




    __pid_t l_pid;
  };


struct flock64
  {
    short int l_type;
    short int l_whence;
    __off64_t l_start;
    __off64_t l_len;
    __pid_t l_pid;
  };
# 34 "/usr/include/fcntl.h" 2 3



# 1 "/usr/include/sys/stat.h" 1 3
# 26 "/usr/include/sys/stat.h" 3
# 1 "/usr/include/features.h" 1 3
# 27 "/usr/include/sys/stat.h" 2 3

# 1 "/usr/include/bits/types.h" 1 3
# 29 "/usr/include/sys/stat.h" 2 3



# 1 "/usr/include/time.h" 1 3
# 33 "/usr/include/sys/stat.h" 2 3
# 96 "/usr/include/sys/stat.h" 3
extern "C" {

# 1 "/usr/include/bits/stat.h" 1 3
# 36 "/usr/include/bits/stat.h" 3
struct stat
  {
    __dev_t st_dev;
    unsigned short int __pad1;

    __ino_t st_ino;



    __mode_t st_mode;
    __nlink_t st_nlink;
    __uid_t st_uid;
    __gid_t st_gid;
    __dev_t st_rdev;
    unsigned short int __pad2;

    __off_t st_size;



    __blksize_t st_blksize;


    __blkcnt_t st_blocks;



    __time_t st_atime;
    unsigned long int __unused1;
    __time_t st_mtime;
    unsigned long int __unused2;
    __time_t st_ctime;
    unsigned long int __unused3;

    unsigned long int __unused4;
    unsigned long int __unused5;



  };


struct stat64
  {
    __dev_t st_dev;
    unsigned int __pad1;

    __ino_t __st_ino;
    __mode_t st_mode;
    __nlink_t st_nlink;
    __uid_t st_uid;
    __gid_t st_gid;
    __dev_t st_rdev;
    unsigned int __pad2;
    __off64_t st_size;
    __blksize_t st_blksize;

    __blkcnt64_t st_blocks;
    __time_t st_atime;
    unsigned long int __unused1;
    __time_t st_mtime;
    unsigned long int __unused2;
    __time_t st_ctime;
    unsigned long int __unused3;
    __ino64_t st_ino;
  };
# 99 "/usr/include/sys/stat.h" 2 3
# 200 "/usr/include/sys/stat.h" 3
extern int stat (__const char *__restrict __file,
                 struct stat *__restrict __buf) throw ();



extern int fstat (int __fd, struct stat *__buf) throw ();
# 219 "/usr/include/sys/stat.h" 3
extern int stat64 (__const char *__restrict __file,
                   struct stat64 *__restrict __buf) throw ();
extern int fstat64 (int __fd, struct stat64 *__buf) throw ();






extern int lstat (__const char *__restrict __file,
                  struct stat *__restrict __buf) throw ();
# 241 "/usr/include/sys/stat.h" 3
extern int lstat64 (__const char *__restrict __file,
                    struct stat64 *__restrict __buf) throw ();






extern int chmod (__const char *__file, __mode_t __mode) throw ();



extern int fchmod (int __fd, __mode_t __mode) throw ();





extern __mode_t umask (__mode_t __mask) throw ();




extern __mode_t getumask (void) throw ();



extern int mkdir (__const char *__path, __mode_t __mode) throw ();





extern int mknod (__const char *__path, __mode_t __mode, __dev_t __dev)
     throw ();




extern int mkfifo (__const char *__path, __mode_t __mode) throw ();
# 306 "/usr/include/sys/stat.h" 3
extern int __fxstat (int __ver, int __fildes, struct stat *__stat_buf) throw ();
extern int __xstat (int __ver, __const char *__filename,
                    struct stat *__stat_buf) throw ();
extern int __lxstat (int __ver, __const char *__filename,
                     struct stat *__stat_buf) throw ();
# 330 "/usr/include/sys/stat.h" 3
extern int __fxstat64 (int __ver, int __fildes, struct stat64 *__stat_buf)
     throw ();
extern int __xstat64 (int __ver, __const char *__filename,
                      struct stat64 *__stat_buf) throw ();
extern int __lxstat64 (int __ver, __const char *__filename,
                       struct stat64 *__stat_buf) throw ();

extern int __xmknod (int __ver, __const char *__path, __mode_t __mode,
                     __dev_t *__dev) throw ();




extern __inline__ int stat (__const char *__path,
                            struct stat *__statbuf) throw ()
{
  return __xstat (3, __path, __statbuf);
}


extern __inline__ int lstat (__const char *__path,
                             struct stat *__statbuf) throw ()
{
  return __lxstat (3, __path, __statbuf);
}


extern __inline__ int fstat (int __fd, struct stat *__statbuf) throw ()
{
  return __fxstat (3, __fd, __statbuf);
}


extern __inline__ int mknod (__const char *__path, __mode_t __mode,
                             __dev_t __dev) throw ()
{
  return __xmknod (1, __path, __mode, &__dev);
}





extern __inline__ int stat64 (__const char *__path,
                              struct stat64 *__statbuf) throw ()
{
  return __xstat64 (3, __path, __statbuf);
}


extern __inline__ int lstat64 (__const char *__path,
                               struct stat64 *__statbuf) throw ()
{
  return __lxstat64 (3, __path, __statbuf);
}


extern __inline__ int fstat64 (int __fd, struct stat64 *__statbuf) throw ()
{
  return __fxstat64 (3, __fd, __statbuf);
}




}
# 38 "/usr/include/fcntl.h" 2 3
# 60 "/usr/include/fcntl.h" 3
extern int fcntl (int __fd, int __cmd, ...) throw ();





extern int open (__const char *__file, int __oflag, ...) throw ();
# 76 "/usr/include/fcntl.h" 3
extern int open64 (__const char *__file, int __oflag, ...) throw ();






extern int creat (__const char *__file, __mode_t __mode) throw ();
# 93 "/usr/include/fcntl.h" 3
extern int creat64 (__const char *__file, __mode_t __mode) throw ();
# 130 "/usr/include/fcntl.h" 3
extern int posix_fadvise (int __fd, __off_t __offset, size_t __len,
                          int __advise) throw ();
# 142 "/usr/include/fcntl.h" 3
extern int posix_fadvise64 (int __fd, __off64_t __offset, size_t __len,
                            int __advise) throw ();





extern int posix_fallocate (int __fd, __off_t __offset, size_t __len) throw ();
# 160 "/usr/include/fcntl.h" 3
extern int posix_fallocate64 (int __fd, __off64_t __offset, size_t __len)
     throw ();



}
# 59 "../../../../src/aleph/ipcClient.H" 2
# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdio.h" 1 3
# 60 "../../../../src/aleph/ipcClient.H" 2
# 1 "../../../../src/aleph/ahDefs.H" 1
# 61 "../../../../src/aleph/ipcClient.H" 2
# 1 "../../../../src/aleph/ahNew.H" 1
# 62 "../../../../src/aleph/ipcClient.H" 2
# 1 "../../../../src/aleph/localMessages.H" 1
# 50 "../../../../src/aleph/localMessages.H"
# 1 "/usr/include/string.h" 1 3
# 51 "../../../../src/aleph/localMessages.H" 2
# 1 "../../../../src/aleph/ahDefs.H" 1
# 52 "../../../../src/aleph/localMessages.H" 2
# 1 "../../../../src/aleph/msgId.H" 1
# 60 "../../../../src/aleph/msgId.H"
class MsgId
{
private:


  unsigned int addr;


  unsigned long long msgSeq;


  long timeSec;


  long timeNsec;

public:

  char * msgid_to_char(char * _str) const
  {
    sprintf(_str, "%X-%llu-%li-%li", addr, msgSeq, timeSec, timeNsec);

    return _str;
  }

  MsgId(unsigned int _addr,
        unsigned long long _msgseq,
        long _timesec = -1,
        long _timensec = -1) :
    addr(_addr), msgSeq(_msgseq), timeSec(_timesec), timeNsec(_timensec)
  {

  }

  MsgId() : addr (0), msgSeq (0), timeSec (-1), timeNsec (-1)
  {

  }

  bool operator == (const MsgId& id) const
  {
    if (not (msgSeq == id.msgSeq and addr == id.addr))
      return false;

    if (timeSec == -1 or id.timeSec == -1)
      {
                                                   ;
        return true;
      }

                                                        ;

    return timeNsec == id.timeNsec and timeSec == id.timeSec;
  }

  bool operator != (const MsgId& id) const
  {
    return not (*this == id);
  }

  unsigned int get_creation_site_ip() const
  {
    return addr;
  }

  unsigned long long getMsgSeq() const
  {
    return msgSeq;
  }

  long getTimeSec() const
  {
    return timeSec;
  }

  long getTimeNsec() const
  {
    return timeNsec;
  }


  void setAddress(unsigned int _addr)
  {
    addr = _addr;
  }


  void setMsgSeq(unsigned long long _seq)
  {
    msgSeq = _seq;
  }

  void setTimeSec(long _timesec)
  {
    timeSec = _timesec;
  }

  void setTimeNsec(long _timensec)
  {
    timeNsec = _timensec;
  }
};

extern const MsgId Null_MsgId;
# 53 "../../../../src/aleph/localMessages.H" 2
# 1 "../../../../src/aleph/port.H" 1
# 54 "../../../../src/aleph/localMessages.H" 2

enum IpcD_Header_Code
{
  CLIENT_SEND_REQUEST,
  CLIENT_RECEIVE_REPLY,
  SERVER_RECEIVE_REQUEST,
  SERVER_SEND_REPLY,
  CLIENT_RECEIVE_REPLY_UPCALL,
  SERVER_RECEIVE_REQUEST_UPCALL,
  ASYN_RECEIVE,
  ASYN_RECEIVE_UPCALL,
  ASYN_SEND,
  BINDING,
  UNBINDING,
  UID,
  TIMEOUT,
  TEST_UPCALL,


  INVALID
};


class IpcD_Entry_Header
{
private:

  IpcD_Header_Code code;
  size_t total_message_size;
  char end_header[0];

public:


  IpcD_Entry_Header(IpcD_Header_Code _code,
                     size_t total_msg_sz = sizeof(IpcD_Entry_Header))
    : code(_code), total_message_size(total_msg_sz)
  {

  }

  IpcD_Entry_Header() : code(INVALID)
  {

  }

  ~IpcD_Entry_Header()
  {

  }

  IpcD_Header_Code getCode()
  {
    return code;
  }

  size_t get_total_message_size() const { return total_message_size; }

  void * get_end_header() { return &end_header[0]; }
};


class IpcD_Exit_Header : public IpcD_Entry_Header
{
public:



  static const char OK = 0;
  static const char Incomplete_Data = -1;
  static const char Bad_Code = -2;
  static const char Timeout_Expired = -3;
  static const char Out_Memory = -4;
  static const char Posix_Error = -5;
  static const char Heavily_Loaded = -6;
  static const char Not_Found = -7;
  static const char Duplicated = -8;
  static const char Refused = -9;
  static const char Bad_Epoch = -10;
  static const char Upcall_Connect = -11;
  static const char No_Request = -12;
  static const char Incoherence = -13;
  static const char Server_Crash = -14;
  static const char Path_Name_Too_Long = -15;
  static const char Ipc_Shutdown = -16;

  static const char Unknown = -126;
  static const char Undefined = -127;

private:


  char operation_status;



  int posix_error;

  char end_header[0];

public:

  IpcD_Exit_Header() :
    operation_status (Undefined),
    posix_error (0)
  { }

  IpcD_Exit_Header
  (IpcD_Header_Code _code,
   char status = OK,
   size_t msg_size = sizeof(IpcD_Exit_Header))
    : IpcD_Entry_Header (_code, msg_size),
      operation_status (status),
      posix_error (0)

  {

  }
  void set_operation_status(char status)
  {
    operation_status = status;
  }

  char get_operation_status() const { return operation_status; }

  int get_posix_error() const { return posix_error; }

  void set_posix_error(int error) { posix_error = error; }


  void * get_end_header() { return &end_header[0]; }
};

class Test_Upcall : public IpcD_Exit_Header
{
public:

  Test_Upcall() :
    IpcD_Exit_Header(TEST_UPCALL, IpcD_Exit_Header::OK, sizeof(*this))
  {

  }
};

class Client_Request_Entry : public IpcD_Entry_Header
{
private:

  Port local_port;


  Port targetPort;


  size_t clientTimeout;


  char data[0];

public:

  Client_Request_Entry(const Port& _local_port,
                       const Port& _targetPort,
                       size_t _timeout,
                       size_t _datasize)
    : IpcD_Entry_Header(CLIENT_SEND_REQUEST, sizeof(*this) + _datasize),
      local_port(_local_port),
      targetPort(_targetPort),
      clientTimeout(_timeout)
  {
  }


  ~Client_Request_Entry()
  {

  }


  char* getData()
  {
    return data;
  }


  size_t getDataSize()
  {
    return get_total_message_size() - sizeof(*this);
  }


  const Port& get_local_port() const { return local_port; }

  const Port& getTargetPort() const
  {
    return targetPort;
  }


  size_t getTimeout()
  {
    return clientTimeout;
  }


  void setClientTimeout(size_t _timeout)
  {
    clientTimeout = _timeout;
  }
};

class Client_Request_Exit : public IpcD_Exit_Header
{
  MsgId msg_id;

public:

  Client_Request_Exit(const MsgId& _msg_id) :
    IpcD_Exit_Header(CLIENT_SEND_REQUEST, IpcD_Exit_Header::OK, sizeof(*this)),
    msg_id(_msg_id)
  { }

  Client_Request_Exit(char status = IpcD_Exit_Header::OK) :
    IpcD_Exit_Header(CLIENT_SEND_REQUEST, status, sizeof(*this))
  { }

  ~Client_Request_Exit() { }

  const MsgId & get_msg_id() const { return msg_id; }
};

class Client_Reply_Entry : public IpcD_Entry_Header
{
  Port local_port;
  MsgId msg_id;

public:

  Client_Reply_Entry() :
    IpcD_Entry_Header(CLIENT_RECEIVE_REPLY, sizeof(*this))
  {

  }

  Client_Reply_Entry(const Port & port, const MsgId & _msg_id) :
    IpcD_Entry_Header(CLIENT_RECEIVE_REPLY, sizeof(*this)),
    local_port (port), msg_id(_msg_id)
  {

  }

  const Port& get_port() const { return local_port; }

  const MsgId & get_msg_id() const { return msg_id; }
};


class Client_Reply_Exit : public IpcD_Exit_Header
{
public:

  Client_Reply_Exit(char status = IpcD_Exit_Header::OK) :
    IpcD_Exit_Header(CLIENT_RECEIVE_REPLY, status, sizeof(*this))
  {

  }

  Client_Reply_Exit(const MsgId& _msg_id) :
    IpcD_Exit_Header(CLIENT_RECEIVE_REPLY, IpcD_Exit_Header::OK,
                     sizeof(*this))
  {

  }


  ~Client_Reply_Exit()
  {

  }
};


class Client_Reply_Upcall : public IpcD_Exit_Header
{
private:

  MsgId msg_id;


  char data[0];

public:

  Client_Reply_Upcall(const MsgId& _msg_id, size_t _datasize) :
    IpcD_Exit_Header(CLIENT_RECEIVE_REPLY_UPCALL, IpcD_Exit_Header::OK,
                     sizeof(*this) + _datasize),
    msg_id(_msg_id)
  {

  }

  Client_Reply_Upcall(char status = IpcD_Exit_Header::OK) :
    IpcD_Exit_Header(CLIENT_RECEIVE_REPLY_UPCALL, status, sizeof(*this))
  {

  }


  ~Client_Reply_Upcall()
  {

  }


  char* getData()
  {
    return data;
  }


  size_t getDataSize()
  {
    return get_total_message_size() - sizeof(*this);
  }

  const MsgId & get_msg_id() const { return msg_id; }
};


class Server_Request_Entry : public IpcD_Entry_Header
{
  Port port;

public:

  Server_Request_Entry(const Port& _port) :
    IpcD_Entry_Header(SERVER_RECEIVE_REQUEST, sizeof(*this)),
    port(_port)
  {

  }

  Server_Request_Entry() :
    IpcD_Entry_Header(SERVER_RECEIVE_REQUEST, sizeof(*this))
  {

  }

  const Port& get_port() const { return port; }
};


class Server_Request_Exit : public IpcD_Exit_Header
{
public:

  Server_Request_Exit(char status = IpcD_Exit_Header::OK) :
    IpcD_Exit_Header(SERVER_RECEIVE_REQUEST, status, sizeof(*this))
  {

  }

  ~Server_Request_Exit()
  {

  }
};


class Server_Request_Upcall : public IpcD_Exit_Header
{
  MsgId msgId;
  char data[0];

public:

  Server_Request_Upcall(const MsgId& _msgid,
                      size_t _datasize) :
    IpcD_Exit_Header(SERVER_RECEIVE_REQUEST_UPCALL, IpcD_Exit_Header::OK,
                     sizeof(*this) + _datasize),
    msgId(_msgid)
  {

  }


  Server_Request_Upcall() :
    IpcD_Exit_Header(SERVER_RECEIVE_REQUEST_UPCALL, IpcD_Exit_Header::OK,
                     sizeof(*this))
  {

  }

  Server_Request_Upcall(char status) :
    IpcD_Exit_Header(SERVER_RECEIVE_REQUEST_UPCALL, status, sizeof(*this))
  {

  }

  ~Server_Request_Upcall()
  {

  }


  MsgId& getMsgId()
  {
    return msgId;
  }


  char* getData()
  {
    return &data[0];
  }
};


class Server_Reply_Entry : public IpcD_Entry_Header
{
  Port port;
  MsgId msgId;
  char data[0];

public:

  Server_Reply_Entry(const MsgId& _msgid,
                     const Port& _port,
                     size_t _datasize) :
    IpcD_Entry_Header (SERVER_SEND_REPLY, sizeof(*this) + _datasize),
    port (_port),
    msgId (_msgid)
  {

  }

  Server_Reply_Entry() :
    IpcD_Entry_Header(SERVER_SEND_REPLY, sizeof(*this))
  {

  }


  ~Server_Reply_Entry()
  {

  }


  MsgId& getMsgId()
  {
    return msgId;
  }

  const Port& get_port() const { return port; }


  char* getData()
  {
    return &data[0];
  }

  size_t getDataSize() const
  {
    return get_total_message_size() - sizeof(*this);
  }
};


class Server_Reply_Exit : public IpcD_Exit_Header
{

public:

  Server_Reply_Exit(char status = IpcD_Exit_Header::OK)
    : IpcD_Exit_Header (SERVER_SEND_REPLY, status, sizeof(*this))
  {

  }
};


class Binding_Entry : public IpcD_Entry_Header
{
  unsigned long long client_connection_number;
  char path_name[0];

public:

  Binding_Entry(): IpcD_Entry_Header(BINDING, sizeof(*this))
  {

  }

  Binding_Entry(unsigned long long con_num,
                char * _path_name) :
    IpcD_Entry_Header(BINDING, sizeof(*this) + strlen(_path_name) + 1),
    client_connection_number(con_num)
  {

  }

  ~Binding_Entry()
  {

  }

  unsigned long long get_client_connection_number() const
  {
    return client_connection_number;
  }

  char * get_path_name() { return path_name; }
};

class Binding_Exit : public IpcD_Exit_Header
{

  Port port;

public:

  Binding_Exit(char status = IpcD_Exit_Header::OK) :
    IpcD_Exit_Header(BINDING, status, sizeof(*this))
  {

  }

  Binding_Exit(const Port& _port,
               char status = IpcD_Exit_Header::OK) :
    IpcD_Exit_Header(BINDING, status, sizeof(*this)),
    port(_port)
  {

  }

  ~Binding_Exit()
  {

  }

  const Port& get_port() const { return port; }
};


class Unbinding_Entry : public IpcD_Entry_Header
{
  Port port;

public:

  Unbinding_Entry() :
    IpcD_Entry_Header(UNBINDING, sizeof(*this))
  {

  }

  Unbinding_Entry(const Port& _port) :
    IpcD_Entry_Header(UNBINDING, sizeof(*this)),
    port(_port)
  {

  }

  ~Unbinding_Entry() { }

  const Port& get_port() const { return port; }
};

class Unbinding_Exit : public IpcD_Exit_Header
{

public:

  Unbinding_Exit(char status = IpcD_Exit_Header::OK) :
    IpcD_Exit_Header(UNBINDING, status, sizeof(*this))
  {

  }
};

class Uid_Entry : public IpcD_Entry_Header
{

public:

  Uid_Entry() : IpcD_Entry_Header(UID, sizeof(*this)) { }
};


class Uid_Exit : public IpcD_Exit_Header
{
  Uid uid;

public:

  Uid_Exit(): IpcD_Exit_Header(UID, sizeof(*this))
  {

  }

  Uid_Exit(const Uid &u) :
    IpcD_Exit_Header(UID, OK, sizeof(*this)),
    uid(u)
  {

  }

  ~Uid_Exit()
  {

  }

  Uid& get_uid() { return uid; }
};

class ClientTimeout : public IpcD_Entry_Header
{
public:

  ClientTimeout(): IpcD_Entry_Header(TIMEOUT, sizeof(*this))
  {

  }

  ~ClientTimeout()
  {

  }
};


class Async_Send_Entry : public IpcD_Entry_Header
{
private:

  Port local_port;
  Port remote_port;

  char data[0];

public:

  Async_Send_Entry(const Port& _local_port,
                   const Port& _remote_port,
                   size_t data_size) :
    IpcD_Entry_Header(ASYN_SEND, sizeof(*this) + data_size),
    local_port(_local_port), remote_port(_remote_port)
  {

  }

  Async_Send_Entry() :
    IpcD_Entry_Header(ASYN_SEND, sizeof(*this))
  {

  }

  ~Async_Send_Entry() { }

  size_t getDataSize() const
  {
    return get_total_message_size() - sizeof(*this);
  }

  char * getData() { return &data[0]; }

  const Port& get_remote_port() const { return remote_port; }

  const Port& get_local_port() const { return local_port; }
};


class Async_Send_Exit : public IpcD_Exit_Header
{
private:

  MsgId msg_id;

public:

  Async_Send_Exit(char status = IpcD_Exit_Header::OK) :
    IpcD_Exit_Header(ASYN_SEND, status, sizeof(*this))
  {

  }

  Async_Send_Exit(const MsgId _msg_id) :
    IpcD_Exit_Header(ASYN_SEND, IpcD_Exit_Header::OK, sizeof(*this)),
    msg_id(_msg_id)
  {

  }

  ~Async_Send_Exit() { }

  const MsgId& get_msg_id() const { return msg_id; }
};

class Async_Receive_Entry : public IpcD_Entry_Header
{
  Port local_port;

public:

  Async_Receive_Entry(const Port& _local_port) :
    IpcD_Entry_Header(ASYN_RECEIVE, sizeof(*this)),
    local_port(_local_port)
  {

  }

  Async_Receive_Entry() :
    IpcD_Entry_Header(ASYN_RECEIVE, sizeof(*this))
  {

  }

  const Port& get_local_port() const { return local_port; }
};


class Async_Receive_Exit : public IpcD_Exit_Header
{
 public:

  Async_Receive_Exit(char status = IpcD_Exit_Header::OK) :
    IpcD_Exit_Header(ASYN_RECEIVE, status, sizeof(*this))
  {

  }

  ~Async_Receive_Exit()
  {

  }
};

class Async_Receive_Upcall : public IpcD_Exit_Header
{
  MsgId msgId;
  char data[0];

public:

  Async_Receive_Upcall(const MsgId& _msgid,
                      size_t _datasize) :
    IpcD_Exit_Header(ASYN_RECEIVE_UPCALL, IpcD_Exit_Header::OK,
                     sizeof(*this) + _datasize),
    msgId(_msgid)
  {

  }

  Async_Receive_Upcall() :
    IpcD_Exit_Header(ASYN_RECEIVE_UPCALL, IpcD_Exit_Header::OK,
                     sizeof(*this))
  {

  }

  Async_Receive_Upcall(char status) :
    IpcD_Exit_Header(ASYN_RECEIVE_UPCALL, status, sizeof(*this))
  {

  }

  ~Async_Receive_Upcall()
  {

  }


  MsgId& getMsgId()
  {
    return msgId;
  }


  char* getData()
  {
    return &data[0];
  }
};
# 63 "../../../../src/aleph/ipcClient.H" 2
# 1 "../../../../src/aleph/msgId.H" 1
# 64 "../../../../src/aleph/ipcClient.H" 2
# 1 "../../../../src/aleph/clientMsgFormat.H" 1
# 51 "../../../../src/aleph/clientMsgFormat.H"
class RawMsg
{
protected:

  void* bodyAddr;

  size_t bodySize;

  short int flags;

  int timeout;

public:


  static const short int DEFAULT_FLAG = 0;


  static const short int RPC_REQUEST = 2;
  static const short int RPC_REPLY = 4;
  static const short int SINGLE_MESSAGE = 8;
  static const short int UNRELIABLE = 16;
  static const short int WEAK_BROADCAST = 32;
  static const short int STRONG_BROADCAST = 64;


  static const short int PIGGYBACK = 128;

  RawMsg()
    : bodyAddr(__null), bodySize(0), flags(DEFAULT_FLAG), timeout(-1)
  {

  }

  RawMsg(void* bodyaddr,
         size_t bodysize,
         short int _flags = DEFAULT_FLAG,
         int _timeout = -1)
    : bodyAddr(bodyaddr),
      bodySize(bodysize),
      flags(_flags),
      timeout(_timeout)
  {

  }

  RawMsg(const RawMsg& _msg)
    : bodyAddr(_msg.bodyAddr),
      bodySize(_msg.bodySize),
      flags(_msg.flags),
      timeout(_msg.timeout)
  {

  }

  ~RawMsg() { }

  void setBodyAddr(void* bodyaddr) { bodyAddr = bodyaddr; }

  void setBodySize(size_t bodysize) { bodySize = bodysize; }

  void setFlags(short int _flag)
  {
    flags |= _flag;
  }

  void unsetFlags(short int flag)
  {
    short int complement = ~flag;
    flags &= complement;
  }

  void cleanFlags() { flags = 0; }

  void setTimeout(int _timeout) { timeout = _timeout; }

  void* getBodyAddr() const { return bodyAddr; }

  size_t getBodySize() const { return bodySize; }

  short int getFlags() const { return flags; }

  int getTimeout() const { return timeout; }
};


    template <class T>
class TypedMsg : public RawMsg
{
public:

  TypedMsg() : RawMsg() { }

  TypedMsg(void* ptr,
           size_t size = sizeof(T),
           short int _flags = DEFAULT_FLAG,
           int _timeout = 0)
    : RawMsg(ptr, size, _flags, _timeout)
  {

  }

  TypedMsg(const T& t,
           size_t size = sizeof(t),
           short int _flags = DEFAULT_FLAG,
           int _timeout = -1)
    : RawMsg(&const_cast<T&>(t), size, flags, timeout)
  {

  }

  TypedMsg(const TypedMsg& _msg)
    : RawMsg(_msg.bodyAddr, _msg.bodySize, _msg.flags, body.timeout)
  {

  }

  ~TypedMsg() { }

  operator T* ()
  {
    return reinterpret_cast<T*>(bodyAddr);
  }

  T* operator -> ()
  {
    T* return_address = reinterpret_cast<T*>(bodyAddr);

    if (return_address == __null)
      throwException<NullPointer>("../../../../src/aleph/clientMsgFormat.H", 180, "NullPointer") ();

    return return_address;
  }

  T& operator * ()
  {
    T* return_address = reinterpret_cast<T*>(bodyAddr);

    if (return_address == __null)
      throwException<NullPointer>("../../../../src/aleph/clientMsgFormat.H", 190, "NullPointer") ();

    return *return_address;
  }
};
# 65 "../../../../src/aleph/ipcClient.H" 2
# 1 "../../../../src/aleph/ipcPars.H" 1
# 49 "../../../../src/aleph/ipcPars.H"
# 1 "../../../../src/aleph/aleph.H" 1
# 50 "../../../../src/aleph/ipcPars.H" 2
# 1 "../../../../src/aleph/log.H" 1
# 50 "../../../../src/aleph/log.H"
# 1 "/usr/include/sys/utsname.h" 1 3
# 26 "/usr/include/sys/utsname.h" 3
# 1 "/usr/include/features.h" 1 3
# 27 "/usr/include/sys/utsname.h" 2 3

extern "C" {

# 1 "/usr/include/bits/utsname.h" 1 3
# 31 "/usr/include/sys/utsname.h" 2 3






struct utsname
  {

    char sysname[65];


    char nodename[65];


    char release[65];

    char version[65];


    char machine[65];




    char domainname[65];




  };







extern int uname (struct utsname *__name) throw ();


}
# 51 "../../../../src/aleph/log.H" 2
# 1 "/usr/include/errno.h" 1 3
# 52 "../../../../src/aleph/log.H" 2
# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdio.h" 1 3
# 53 "../../../../src/aleph/log.H" 2
# 1 "/usr/local/lib/gcc-lib/i686-pc-linux-gnu/3.0.2/include/stdarg.h" 1 3
# 54 "../../../../src/aleph/log.H" 2
# 1 "/usr/include/string.h" 1 3
# 55 "../../../../src/aleph/log.H" 2
# 1 "../../../../src/aleph/ahExceptions.H" 1
# 56 "../../../../src/aleph/log.H" 2
# 1 "../../../../src/aleph/useMutex.H" 1
# 49 "../../../../src/aleph/useMutex.H"
# 1 "/usr/include/pthread.h" 1 3
# 50 "../../../../src/aleph/useMutex.H" 2
# 1 "/usr/include/errno.h" 1 3
# 51 "../../../../src/aleph/useMutex.H" 2
# 1 "../../../../src/aleph/ahExceptions.H" 1
# 52 "../../../../src/aleph/useMutex.H" 2


extern void init_mutex(pthread_mutex_t *);

extern void init_mutex(pthread_mutex_t &);

extern void destroy_mutex(pthread_mutex_t *);

extern void destroy_mutex(pthread_mutex_t &);


class UseMutex
{
private:

  pthread_mutex_t *mutex;
  bool unlock_when_destroy;






public:

  UseMutex(pthread_mutex_t *m



           ) :
    mutex (m), unlock_when_destroy(true)



    {
      lock();
    }

  UseMutex(pthread_mutex_t & m



           ) :
    mutex (&m), unlock_when_destroy(true)



    {
      lock();
    }

  void unLock()
    {
# 129 "../../../../src/aleph/useMutex.H"
      pthread_mutex_unlock(mutex);

    }

  void lock()
    {
# 159 "../../../../src/aleph/useMutex.H"
      pthread_mutex_lock(mutex);

    }

  void enter() { lock(); }

  void leave() { unLock(); }

  ~UseMutex()
    {
      if (unlock_when_destroy)
        unLock();
    }

  void disallow_unlock() { unlock_when_destroy = false; }

  void allow_unlock() { unlock_when_destroy = true; }
};
# 57 "../../../../src/aleph/log.H" 2

class Log_Manager
{
  static const short int Max_Log_Line_Length = 512;
  static const short int Max_Time_Line_Length = 61;

  FILE * file_descriptor;

  pthread_mutex_t mutex;

  char print_buffer[Max_Log_Line_Length];

  char time_buffer[Max_Time_Line_Length];

  size_t num_lines;

  size_t max_num_lines;

  void get_time()
  {

    time_t unix_time;
    time(&unix_time);


    struct tm broken_time;

    localtime_r(&unix_time, &broken_time);

    strftime(time_buffer, Max_Time_Line_Length, "%a %b %d %G %r",
             &broken_time);
  }

public:

  Log_Manager(FILE * _file_descriptor)
    : file_descriptor(_file_descriptor)
  {
    init_mutex(mutex);
    struct utsname site_info;
    uname(&site_info);
  }

  ~Log_Manager()
  {
    destroy_mutex(mutex);
  }

  void init_line(




                  const char *format, ...)
  {
    va_list ap;

    __builtin_stdarg_start((ap),format);
    {
      UseMutex critical_section(mutex);

      get_time();





      fprintf(file_descriptor, "%s (%ld:%d): ",
              time_buffer, pthread_self(), getpid());

      vfprintf(file_descriptor, format, ap);
    }
    __builtin_va_end(ap);
  }

  void write_line(




                  const char *format, ...)
  {
    va_list ap;

    __builtin_stdarg_start((ap),format);
    {
      UseMutex critical_section(mutex);

      get_time();





      fprintf(file_descriptor, "%s (%ld:%d): ",
              time_buffer, pthread_self(), getpid());

      vfprintf(file_descriptor, format, ap);
      fprintf(file_descriptor, "\n");
    }
    __builtin_va_end(ap);
  }


};
# 51 "../../../../src/aleph/ipcPars.H" 2

extern unsigned long IpcServerPort;

extern const size_t DefaultMaxMessageSize;


extern const int DefaultRetriesNumber;

extern const int DefaultProcessTime;

extern const int DefaultNetLatency;

extern const int DefaultOverhead;

extern const int DefaultMessagesNumber;

extern const int DefaultSitesNumber;

extern const int DefaultTableSizeFactor;

extern const int Default_Wave_Time;

extern const int DefaultNumberPiggyback;

extern size_t reception_buffer_size;

extern int retriesNumber;

extern int netLatency;

extern int overhead;

extern int processTime;

extern int messagesNumber;

extern int max_num_piggyback;

extern int sitesNumber;

extern int tableSizeFactor;

extern int wave_time;

extern const char * const ipcPathIdentifier;

extern const int upcall_num_file_max_len;

extern const char * const upcall_path_identifier;

extern const int sun_path_size;

extern float overhead_factor;

extern int expected_response_time;



inline void set_expected_response_time()
{
  expected_response_time =
    static_cast<unsigned int>((2.0*netLatency + processTime)*overhead_factor);
}
# 66 "../../../../src/aleph/ipcClient.H" 2
# 1 "../../../../src/aleph/port.H" 1
# 67 "../../../../src/aleph/ipcClient.H" 2
# 1 "../../../../src/aleph/boot.H" 1
# 50 "../../../../src/aleph/boot.H"
# 1 "/usr/include/stdlib.h" 1 3
# 51 "../../../../src/aleph/boot.H" 2
# 1 "/usr/include/pthread.h" 1 3
# 52 "../../../../src/aleph/boot.H" 2
# 1 "../../../../src/aleph/log.H" 1
# 53 "../../../../src/aleph/boot.H" 2
# 1 "../../../../src/aleph/timeoutQueue.H" 1
# 50 "../../../../src/aleph/timeoutQueue.H"
# 1 "/usr/include/sys/time.h" 1 3
# 51 "../../../../src/aleph/timeoutQueue.H" 2
# 1 "/usr/include/unistd.h" 1 3
# 52 "../../../../src/aleph/timeoutQueue.H" 2
# 1 "/usr/include/pthread.h" 1 3
# 53 "../../../../src/aleph/timeoutQueue.H" 2
# 1 "../../../../src/aleph/tpl_binHeap.H" 1
# 55 "../../../../src/aleph/tpl_binHeap.H"
# 1 "../../../../src/aleph/ahUtils.H" 1
# 50 "../../../../src/aleph/ahUtils.H"
# 1 "../../../../src/aleph/ahExceptions.H" 1
# 51 "../../../../src/aleph/ahUtils.H" 2

namespace Aleph {

    template <class T>
void swap(T& t1, T& t2)
{
  T tmp = t1;
  t1 = t2;
  t2 = tmp;
}

}
# 56 "../../../../src/aleph/tpl_binHeap.H" 2
# 1 "../../../../src/aleph/tpl_binNode.H" 1
# 56 "tpl_binNode.nw"



# 1 "../../../../src/aleph/ahDefs.H" 1
# 60 "tpl_binNode.nw" 2
# 1 "../../../../src/aleph/ahAssert.H" 1
# 61 "tpl_binNode.nw" 2
# 1 "../../../../src/aleph/ahNew.H" 1
# 62 "tpl_binNode.nw" 2
# 162 "tpl_binNode.nw"
struct Empty_Node
{
  Empty_Node() { }

  Empty_Node(SentinelCtor) { }

  void reset() { }
};
# 178 "tpl_binNode.nw"
# 83 "tpl_binNode.nw"
# 119 "tpl_binNode.nw"
# 67 "tpl_binNode.nw"
# 151 "tpl_binNode.nw"
template <class Key> class BinNode : public Empty_Node { public: static const size_t MaxHeight = 255; static BinNode * const NullPtr; private: Key key; BinNode * lLink; BinNode * rLink; public: Key& getKey() { return key; } BinNode*& getL() { return lLink; } BinNode*& getR() { return rLink; } BinNode(const Key& k) : key(k), lLink(NullPtr), rLink(NullPtr) { } BinNode(const Empty_Node & control_data, const Key& k) : Empty_Node(control_data), key(k), lLink(NullPtr), rLink(NullPtr) { } BinNode(const BinNode & node) : Empty_Node(node), key(node.key), lLink(NullPtr), rLink(NullPtr) { } BinNode(const Empty_Node & control_data) : Empty_Node(control_data), lLink(NullPtr), rLink(NullPtr) { } BinNode() : lLink(NullPtr), rLink(NullPtr) { } void reset() { Empty_Node::reset(); rLink = lLink = NullPtr; } }; template <class Key> BinNode<Key> * const BinNode<Key>::NullPtr = __null; template <class Key> class BinNodeVtl : public Empty_Node { public: static const size_t MaxHeight = 255; static BinNodeVtl * const NullPtr; private: Key key; BinNodeVtl * lLink; BinNodeVtl * rLink; public: Key& getKey() { return key; } BinNodeVtl*& getL() { return lLink; } BinNodeVtl*& getR() { return rLink; } BinNodeVtl(const Key& k) : key(k), lLink(NullPtr), rLink(NullPtr) { } BinNodeVtl(const Empty_Node & control_data, const Key& k) : Empty_Node(control_data), key(k), lLink(NullPtr), rLink(NullPtr) { } BinNodeVtl(const BinNodeVtl & node) : Empty_Node(node), key(node.key), lLink(NullPtr), rLink(NullPtr) { } BinNodeVtl(const Empty_Node & control_data) : Empty_Node(control_data), lLink(NullPtr), rLink(NullPtr) { } BinNodeVtl() : lLink(NullPtr), rLink(NullPtr) { } void reset() { Empty_Node::reset(); rLink = lLink = NullPtr; } virtual ~BinNodeVtl() { } }; template <class Key> BinNodeVtl<Key> * const BinNodeVtl<Key>::NullPtr = __null;
# 70 "tpl_binNode.nw"
# 57 "../../../../src/aleph/tpl_binHeap.H" 2







class BinHeapNode_Data
{
private:

  struct Control_Fields
  {
    int is_leaf : 4;
    int is_left : 4;
  };

  BinHeapNode_Data * pLink;

  Control_Fields control_fields;

public:

  BinHeapNode_Data() : pLink(__null)
  {
    control_fields.is_leaf = 1;
    control_fields.is_left = 1;
  }

  BinHeapNode_Data *& getU() { return pLink; }

  Control_Fields& get_control_fields() { return control_fields; }

  void reset()
  {
    control_fields.is_leaf = 1;
    control_fields.is_left = 1;
  }
};


template <class Key> class BinHeapNode : public BinHeapNode_Data { public: static const size_t MaxHeight = 64; static BinHeapNode * const NullPtr; private: Key key; BinHeapNode * lLink; BinHeapNode * rLink; public: Key& getKey() { return key; } BinHeapNode*& getL() { return lLink; } BinHeapNode*& getR() { return rLink; } BinHeapNode(const Key& k) : key(k), lLink(NullPtr), rLink(NullPtr) { } BinHeapNode(const BinHeapNode_Data & control_data, const Key& k) : BinHeapNode_Data(control_data), key(k), lLink(NullPtr), rLink(NullPtr) { } BinHeapNode(const BinHeapNode & node) : BinHeapNode_Data(node), key(node.key), lLink(NullPtr), rLink(NullPtr) { } BinHeapNode(const BinHeapNode_Data & control_data) : BinHeapNode_Data(control_data), lLink(NullPtr), rLink(NullPtr) { } BinHeapNode() : lLink(NullPtr), rLink(NullPtr) { } void reset() { BinHeapNode_Data::reset(); rLink = lLink = NullPtr; } }; template <class Key> BinHeapNode<Key> * const BinHeapNode<Key>::NullPtr = __null; template <class Key> class BinHeapNodeVtl : public BinHeapNode_Data { public: static const size_t MaxHeight = 64; static BinHeapNodeVtl * const NullPtr; private: Key key; BinHeapNodeVtl * lLink; BinHeapNodeVtl * rLink; public: Key& getKey() { return key; } BinHeapNodeVtl*& getL() { return lLink; } BinHeapNodeVtl*& getR() { return rLink; } BinHeapNodeVtl(const Key& k) : key(k), lLink(NullPtr), rLink(NullPtr) { } BinHeapNodeVtl(const BinHeapNode_Data & control_data, const Key& k) : BinHeapNode_Data(control_data), key(k), lLink(NullPtr), rLink(NullPtr) { } BinHeapNodeVtl(const BinHeapNodeVtl & node) : BinHeapNode_Data(node), key(node.key), lLink(NullPtr), rLink(NullPtr) { } BinHeapNodeVtl(const BinHeapNode_Data & control_data) : BinHeapNode_Data(control_data), lLink(NullPtr), rLink(NullPtr) { } BinHeapNodeVtl() : lLink(NullPtr), rLink(NullPtr) { } void reset() { BinHeapNode_Data::reset(); rLink = lLink = NullPtr; } virtual ~BinHeapNodeVtl() { } }; template <class Key> BinHeapNodeVtl<Key> * const BinHeapNodeVtl<Key>::NullPtr = __null;
# 112 "../../../../src/aleph/tpl_binHeap.H"
    template <template <class> class NodeType, class Key>
class GenBinHeap
{

  typedef NodeType<Key> Node;

protected:

  Node head_node;
  Node * head;
  Node *& root;
  Node * last;
  int num_nodes;

  static bool is_in_list(Node * p)
  {
    if (((p)->get_control_fields().is_leaf))
      return true;

    return reinterpret_cast<Node*&>(((p->getL()))->getU()) == ((p->getL())->getR());
  }

  static bool has_sibling(Node * p)
  {
    return reinterpret_cast<Node*&>((p)->getU()) not_eq (p->getR());
  }

  void swap_with_parent(Node* p)
  {
                          ;

    Node *fp = reinterpret_cast<Node*&>((p)->getU());

                                            ;



    bool p_has_sibling = has_sibling(p);
    bool p_is_in_list = is_in_list(p);
    bool fp_is_in_list = is_in_list(fp);
    bool p_has_child = not ((p)->get_control_fields().is_leaf);

    Aleph::swap(((fp)->get_control_fields()), ((p)->get_control_fields()));

    Node *ffp = reinterpret_cast<Node*&>((fp)->getU());

                                                ;


    reinterpret_cast<Node*&>((fp)->getU()) = p;
    reinterpret_cast<Node*&>((p)->getU()) = ffp;

    if ((ffp->getL()) == fp)
      (ffp->getL()) = p;
    else
      (ffp->getR()) = p;

    Node *sp = __null;
    if (p_has_sibling)
      {
        sp = (p == (fp->getL())) ? (fp->getR()) : (fp->getL());
                               ;
        reinterpret_cast<Node*&>((sp)->getU()) = p;
      }

    if (p == last)
      last = fp;

    if (num_nodes == 2)
      return;

    Node *lcp = (p->getL());
    Node *rcp = (p->getR());

    if (num_nodes == 3)
      {
        if ((fp->getR()) == p)
          {
            (lcp->getL()) = (lcp->getR()) = fp;
            (fp->getR()) = lcp;
            (p->getR()) = fp;
          }
        else
          {
            (rcp->getL()) = (rcp->getR()) = fp;
            (fp->getL()) = rcp;
            (p->getL()) = fp;
          }
        return;
      }

    if (not p_is_in_list)
      {
                                                ;

        reinterpret_cast<Node*&>((lcp)->getU()) = reinterpret_cast<Node*&>((rcp)->getU()) = fp;

        if ((fp->getL()) == p)
          {
                                   ;
            (p->getL()) = fp;
            (p->getR()) = (fp->getR());
          }
        else
          {
                                   ;
            (p->getR()) = fp;
            (p->getL()) = (fp->getL());
          }
        (fp->getL()) = lcp;
        (fp->getR()) = rcp;
        return;
      }

    if (not fp_is_in_list)
      {
                                                ;

        if (p_has_child)
          reinterpret_cast<Node*&>(((p->getL()))->getU()) = fp;

        (lcp->getR()) = (rcp->getL()) = fp;

        if ((fp->getL()) == p)
          {
                                   ;
            (p->getL()) = fp;
            (p->getR()) = (fp->getR());
          }
        else
          {
                                   ;
            (p->getR()) = fp;
            (p->getL()) = (fp->getL());
          }
        (fp->getL()) = lcp;
        (fp->getR()) = rcp;
        return;
      }

                                            ;

    (lcp->getR()) = fp;
    ((fp->getR())->getL()) = p;
    (fp->getL()) = lcp;
    (p->getR()) = (fp->getR());
    (fp->getR()) = p;
    (p->getL()) = fp;
  }

  void swap_root_with_last()
  {
                         ;
                               ;
                             ;
                         ;

    if (num_nodes > 3)
      {
        Node *lRoot = (root->getL());
        Node *rRoot = (root->getR());
        Node *f_last = reinterpret_cast<Node*&>((last)->getU());
        Node *prev_last = (last->getL());
        Node *next_last = (last->getR());

        if ((f_last->getL()) == last)
          (f_last->getL()) = root;
        else
          (f_last->getR()) = root;

        if ((root->getR()) not_eq last)
          Aleph::swap(reinterpret_cast<Node*&>((root)->getU()), reinterpret_cast<Node*&>((last)->getU()));
        else
          {
            reinterpret_cast<Node*&>((root)->getU()) = last;
            reinterpret_cast<Node*&>((root)->getU()) = head;
          }
        Aleph::swap((root->getL()), (last->getL()));
        Aleph::swap((root->getR()), (last->getR()));

        reinterpret_cast<Node*&>((lRoot)->getU()) = reinterpret_cast<Node*&>((rRoot)->getU()) = last;

        (last->getL()) = lRoot;
        (last->getR()) = rRoot;

        (root->getL()) = prev_last;
        (root->getR()) = next_last;

        (prev_last->getR()) = (next_last->getL()) = root;
      }
    else if (num_nodes == 3)
      {
                                   ;
                                                                         ;

        reinterpret_cast<Node*&>((last)->getU()) = reinterpret_cast<Node*&>((root)->getU());
        reinterpret_cast<Node*&>((root)->getU()) = last;

        Node *s_last = (last->getL());
        reinterpret_cast<Node*&>((s_last)->getU()) = last;

        (last->getL()) = s_last;
        (last->getR()) = root;

        (root->getL()) = (root->getR()) = s_last;
        (s_last->getR()) = (s_last->getL()) = root;
      }
    else
      {
                                   ;

        reinterpret_cast<Node*&>((last)->getU()) = reinterpret_cast<Node*&>((root)->getU());
        reinterpret_cast<Node*&>((root)->getU()) = last;
        (last->getR()) = (last->getL()) = root;
        (root->getR()) = (root->getL()) = last;
      }

    Aleph::swap(((root)->get_control_fields()), ((last)->get_control_fields()));
    Aleph::swap(root, last);
  }

  virtual void sift_up(Node *p)
  {
    while (p not_eq root and ((p)->getKey()) < ((reinterpret_cast<Node*&>((p)->getU()))->getKey()))
      swap_with_parent(p);
  }

  virtual void sift_down(Node * p)
  {
    Node *cp;

    while (not ((p)->get_control_fields().is_leaf))
      {
        cp = (p->getL());

        if (has_sibling(cp))
          {
            if ((((p->getR()))->getKey()) < (((p->getL()))->getKey()))
              cp = (p->getR());
          }

        if (((p)->getKey()) <= ((cp)->getKey()))
          return;

        swap_with_parent(cp);
      }
  }

  Node * remove_last()
  {
                                              ;
                         ;

    Node * ret_val = last;
    Node * fp = reinterpret_cast<Node*&>((last)->getU());
    Node * new_last = (last->getL());

    if (((last)->get_control_fields().is_left))
      {
        ((fp)->get_control_fields().is_leaf) = 1;
        (fp->getL()) = new_last;
      }
    else
      {
        (fp->getR()) = (last->getR());
        ((last->getR())->getL()) = fp;
      }

    ((last->getL())->getR()) = fp;
    last = new_last;

    num_nodes--;

    ret_val->reset();

    return ret_val;
  }

  void replace_node(Node * node, Node * new_node)
  {
                                ;
                            ;


    Node * parent = reinterpret_cast<Node*&>((node)->getU());
    Node * left_child = (node->getL());
    Node * right_child = (node->getR());


    reinterpret_cast<Node*&>((new_node)->getU()) = parent;
    (new_node->getL()) = left_child;
    (new_node->getR()) = right_child;


    if (((node)->get_control_fields().is_left))
      {
                                     ;
        (parent->getL()) = new_node;
      }
    else
      {
                                     ;
        (parent->getR()) = new_node;
      }

    if (((node)->get_control_fields().is_leaf))
      {
        (left_child->getR()) = new_node;
        (right_child->getL()) = new_node;
      }
    else
      {
        reinterpret_cast<Node*&>((left_child)->getU()) = new_node;
        if (reinterpret_cast<Node*&>((right_child)->getU()) == node)
          reinterpret_cast<Node*&>((right_child)->getU()) = new_node;
        else
          {
                                      ;
            (left_child->getR()) = new_node;
            (right_child->getL()) = new_node;
          }
      }

    ((new_node)->get_control_fields()) = ((node)->get_control_fields());
  }

protected:

  GenBinHeap() :
    head_node(),
    head(&head_node),
    root((head->getR())),
    last(&head_node),
    num_nodes(0)
  {
                        ;
  }

public:

  virtual ~GenBinHeap() { }

  Node *insert(Node *p)
  {
                      ;

    if (root == __null)
      {
                              ;
        root = p;
        (p->getL()) = (p->getR()) = p;
        reinterpret_cast<Node*&>((p)->getU()) = head;
        ((p)->get_control_fields().is_leaf) = 1;
        ((p)->get_control_fields().is_left) = 0;
        last = root;
        num_nodes = 1;
        return p;
      }

    Node *fp = (last->getR());

    (p->getL()) = last;
    reinterpret_cast<Node*&>((p)->getU()) = fp;

    if (((last)->get_control_fields().is_left))
      {
        ((p)->get_control_fields().is_left) = 0;
        (p->getR()) = (fp->getR());
        ((fp->getR())->getL()) = p;
        (fp->getR()) = p;
      }
    else
      {
        ((p)->get_control_fields().is_left) = 1;
        (p->getR()) = fp;
        ((fp)->get_control_fields().is_leaf) = 0;
        (fp->getL()) = p;
      }

                           ;

    (last->getR()) = p;
    last = p;

    num_nodes++;

    sift_up(last);

    return p;
  }

  Node* getMin() throw(std::exception, AlephExc, Underflow)
  {
    if (root == __null)
      {
                              ;
        throwException<Underflow>("../../../../src/aleph/tpl_binHeap.H", 508, "Underflow") (1);
      }

    Node *retVal = root;

    if (num_nodes == 1)
      {
        root = __null;
        retVal->reset();
        num_nodes = 0;
        return retVal;
      }

    swap_root_with_last();

                                               ;

    remove_last();

    sift_down(root);

    retVal->reset();

    return retVal;
  }

  Node* top() const throw(std::exception, AlephExc, Underflow)
  {
    if (root == __null)
      {
                              ;
        throwException<Underflow>("../../../../src/aleph/tpl_binHeap.H", 539, "Underflow") (1);
      }

    return root;
  }

  Node * remove(Node * node) throw(std::exception, AlephExc, Underflow)
  {
    if (root == __null)
      {
                              ;
        throwException<Underflow>("../../../../src/aleph/tpl_binHeap.H", 550, "Underflow") (1);
      }

    if (node == root)
      return getMin();

    if (node == last)
      return remove_last();

    Node * p = remove_last();

    if (node == last)
      {
        remove_last();
        insert(p);
        return node;
      }

    replace_node(node, p);

    sift_down(p);
    sift_up(p);

    node->reset();

    return node;
  }

  size_t size() const { return num_nodes; }

protected:

  Node * advance_left(Node* p)
  {
    if (((p)->get_control_fields().is_leaf))
      return __null;

    return (p->getL());
  }

  Node * advance_right(Node* p)
  {
                          ;

    if (not has_sibling((p->getL())))
      return __null;

    return (p->getR());
  }

  virtual bool verify_heap(Node *p)
  {
    Node * left_link = advance_left(p);

    if (left_link == __null)
      {
                          ;
        return true;
      }

    if (((left_link)->getKey()) < ((p)->getKey()))
      return false;

    Node * right_link = advance_right(p);

    if (right_link == __null)
      return verify_heap(left_link);

    if (((right_link)->getKey()) < ((p)->getKey()))
      return false;

    return verify_heap(right_link);
  }

public:

  bool verify_heap()
  {
    if (root == __null)
      return true;

    return verify_heap(root);
  }
};


    template <template <class> class NodeType, class Key>
class GenBinHeapPtr : public GenBinHeap<NodeType, Key>
{

protected:

  virtual void sift_up(Node * p)
  {
    while (p not_eq root and *((p)->getKey()) < *((reinterpret_cast<Node*&>((p)->getU()))->getKey()))
      {
        Aleph::swap(((p)->getKey()), ((reinterpret_cast<Node*&>((p)->getU()))->getKey()));
        p = reinterpret_cast<Node*&>((p)->getU());
      }
  }

  virtual void sift_down(Node * p)
  {
    Node *cp;

    while (not ((p)->get_control_fields().is_leaf))
      {
        cp = (p->getL());

        if (has_sibling(cp))
          {
            if (*(((p->getR()))->getKey()) < *(((p->getL()))->getKey()))
              cp = (p->getR());
          }

        if (*((p)->getKey()) <= *((cp)->getKey()))
          return;

        swap_with_parent(cp);
      }
  }

  virtual bool verify_heap(Node *p)
  {
    Node * left_link = advance_left(p);

    if (left_link == __null)
      {
                          ;
        return true;
      }

    if (*((left_link)->getKey()) < *((p)->getKey()))
      return false;

    Node * right_link = advance_right(p);

    if (right_link == __null)
      return verify_heap(left_link);

    if (*((right_link)->getKey()) < *((p)->getKey()))
      return false;

    return verify_heap(right_link);
  }


  virtual bool verify_heap(Node *p, int ordinal)
  {
                         ;

    Node * left_link = advance_left(p, ordinal);

    if (left_link == __null)
      return true;

    if (*((left_link)->getKey()) < *((p)->getKey()))
      return false;

    Node * right_link = advance_right(p, ordinal);

    if (right_link == __null)
      return verify_heap(left_link, multiply_by_2(ordinal));

    if (*((right_link)->getKey()) < *((p)->getKey()))
      return false;

    return verify_heap(right_link, multiply_by_2(ordinal) + 1);
  }
};


    template <class Key>
class BinHeap : public GenBinHeap<BinHeapNode, Key>
{
public:

  typedef BinHeapNode<Key> Node;

  BinHeap() : GenBinHeap<BinHeapNode, Key>()
  {

  }
};


    template <class Type>
class BinHeap<Type*> : public GenBinHeapPtr<BinHeapNode, Type*>
{
public:

  typedef BinHeapNode<Type*> Node;

  BinHeap() : GenBinHeapPtr<BinHeapNode, Type*>()
  {

  }
};


    template <class Key>
class BinHeapVtl : public GenBinHeap<BinHeapNodeVtl, Key>
{
public:

  typedef BinHeapNodeVtl<Key> Node;

  BinHeapVtl() : GenBinHeap<BinHeapNodeVtl, Key>() { }
};
# 54 "../../../../src/aleph/timeoutQueue.H" 2
# 1 "../../../../src/aleph/useMutex.H" 1
# 55 "../../../../src/aleph/timeoutQueue.H" 2
# 1 "../../../../src/aleph/ipcPars.H" 1
# 56 "../../../../src/aleph/timeoutQueue.H" 2
# 67 "../../../../src/aleph/timeoutQueue.H"
class TimeoutQueue
{
public:

  friend class Event : private BinHeapVtl<struct timespec>::Node
  {
    friend class TimeoutQueue;
  private:

    friend bool operator < (const struct timespec&, const struct timespec&);
    friend bool operator <= (const struct timespec&, const struct timespec&);
    friend bool operator > (const struct timespec&, const struct timespec&);
    friend bool operator >= (const struct timespec&, const struct timespec&);

  public:
    enum Execution_Status
    {
      Out_Queue,
      In_Queue,
      Canceled,
      Executing,
      Executed
    };

  private:

    Execution_Status execution_status;

    void setAbsoluteTime(struct timespec _t)
    {
                                                   ;
      ((this)->getKey()) = _t;
    }

    void set_execution_status(Execution_Status status)
    {
      execution_status = status;
    }

  protected:

    Event(const struct timespec& t) :
      BinHeapVtl<struct timespec>::Node(t),
      execution_status(Out_Queue)
    {
                                                               ;
    }

    Event(long sec, long nsec) :
      execution_status(Out_Queue)
    {
                                       ;

      (((this)->getKey()).tv_sec) = sec;
      (((this)->getKey()).tv_nsec) = nsec;
    }

  public:

    virtual ~Event()
    {
      if (execution_status == In_Queue)
        Aleph::error("../../../../src/aleph/timeoutQueue.H", 129, "Attempting to delete an event in queue (0x%x)" , this);
    }

    Execution_Status get_execution_status() const { return execution_status; }

    struct timespec getAbsoluteTime() { return ((this)->getKey()); }

    virtual void EventFct() = 0;
  };

private:

  BinHeapVtl<struct timespec> prioQueue;
  pthread_mutex_t mutex;
  pthread_cond_t cond;
  pthread_t threadId;
  bool isShutdown;

  static int instanceCounter;

  void *triggerEvent();

  static void* triggerEventThread(void*);

public:

  TimeoutQueue();

  ~TimeoutQueue();

  void insertEvent(const struct timespec &, Event*)
    throw(std::exception, AlephExc, Overflow);

  void insertEvent(Event*) throw(std::exception, AlephExc, Overflow);

  bool cancelEvent(Event*);

  void cancel_delete_event(Event *& event)
  {
    if (event == __null)
      return;

    cancelEvent(event);
    destruct(*Aleph::objectAlloc, event);
    event = __null;
  }

  void shutdown();

  pthread_t getThreadId() const { return threadId; }
};


inline long msec_to_nsec(long msec)
{
                                   ;

  return msec*1000000;
}


inline long usec_to_nsec(long usec)
{
                                   ;

  return usec*1000;
}


inline char * timespec_to_char(const struct timespec & t, char * str)
{
  sprintf(str, "(%ld sec, %ld nsec)", t.tv_sec, t.tv_nsec);

  return str;
}


    inline
struct timespec timeval_to_timespec(const struct timeval& current_time)
{
                                                                   ;

  struct timespec ret_val;
  ret_val.tv_sec = current_time.tv_sec;
  ret_val.tv_nsec = usec_to_nsec(current_time.tv_usec);

                                                         ;

  return ret_val;
}


inline struct timespec read_current_time()
{
  struct timeval current_time;
  gettimeofday(&current_time, __null);

  return timeval_to_timespec(current_time);
}

    inline
struct timespec timespec_plus_msec(const struct timespec& current_time,
                                   int msec)
{
                                                                   ;
  long sec = msec/1000;
  msec %= 1000;
  long total_nsec = current_time.tv_nsec + msec_to_nsec(msec);
  struct timespec _t;
  _t.tv_sec = current_time.tv_sec + sec + total_nsec/1000000000;
  _t.tv_nsec = total_nsec%1000000000;
                                               ;
  return _t;
}


    inline
bool operator < (const struct timespec& l, const struct timespec& r)
{
                                             ;
                                             ;

  if (l.tv_sec not_eq r.tv_sec)
    return l.tv_sec < r.tv_sec;

  return l.tv_nsec < r.tv_nsec;
}


    inline
bool operator <= (const struct timespec& l, const struct timespec& r)
{
                                             ;
                                             ;

  if (l.tv_sec not_eq r.tv_sec)
    return l.tv_sec < r.tv_sec;

  return l.tv_nsec <= r.tv_nsec;
}


    inline
bool operator > (const struct timespec& l, const struct timespec& r)
{
  return not (l <= r);
}


    inline
bool operator >= (const struct timespec& l, const struct timespec& r)
{
  return not (l < r);
}
# 54 "../../../../src/aleph/boot.H" 2
# 1 "../../../../src/aleph/sendQueue.H" 1
# 50 "../../../../src/aleph/sendQueue.H"
# 1 "/usr/include/sys/socket.h" 1 3
# 51 "../../../../src/aleph/sendQueue.H" 2
# 1 "/usr/include/netinet/in.h" 1 3
# 52 "../../../../src/aleph/sendQueue.H" 2
# 1 "/usr/include/string.h" 1 3
# 53 "../../../../src/aleph/sendQueue.H" 2
# 1 "/usr/include/pthread.h" 1 3
# 54 "../../../../src/aleph/sendQueue.H" 2
# 1 "/usr/include/errno.h" 1 3
# 55 "../../../../src/aleph/sendQueue.H" 2
# 1 "../../../../src/aleph/aleph.H" 1
# 56 "../../../../src/aleph/sendQueue.H" 2
# 1 "../../../../src/aleph/useMutex.H" 1
# 57 "../../../../src/aleph/sendQueue.H" 2
# 1 "../../../../src/aleph/useCondVar.H" 1
# 92 "../../../../src/aleph/useCondVar.H"
# 1 "/usr/include/pthread.h" 1 3
# 93 "../../../../src/aleph/useCondVar.H" 2

class UseCondVar
{
private:

  pthread_cond_t *cond;
  pthread_mutex_t *mutex;

public:

  UseCondVar(pthread_cond_t *c, pthread_mutex_t *m)
  {
    mutex = m;
    cond = c;
  }

  int wait()
  {
    int retVal = pthread_cond_wait(cond, mutex);
    return retVal;
  }

  int signal()
  {
    int retVal = pthread_cond_signal(cond);
    return retVal;
  }

  int broadcast()
  {
    int retVal = pthread_cond_broadcast(cond);
    return retVal;
  }

  ~UseCondVar()
  {

  }
};
# 58 "../../../../src/aleph/sendQueue.H" 2
# 1 "../../../../src/aleph/tpl_dynListQueue.H" 1
# 13 "tpl_dynListQueue.nw"



# 1 "../../../../src/aleph/tpl_listQueue.H" 1
# 6 "tpl_listQueue.nw"



# 1 "../../../../src/aleph/ahExceptions.H" 1
# 10 "tpl_listQueue.nw" 2
# 1 "../../../../src/aleph/tpl_snode.H" 1
# 6 "tpl_snode.nw"



# 1 "../../../../src/aleph/slink.H" 1
# 7 "slink.nw"



# 1 "../../../../src/aleph/ahAssert.H" 1
# 11 "slink.nw" 2
# 1 "../../../../src/aleph/ahExceptions.H" 1
# 12 "slink.nw" 2

class Slink
{
# 79 "slink.nw"
 protected:

  Slink* next;
# 17 "slink.nw"
public:
# 88 "slink.nw"
Slink() : next(this) { }

Slink(const Slink& l)
{
# 135 "slink.nw"
if (not l.isEmpty())
  throwException<Invalid>("slink.nw", 136, "Invalid") ();

next = this;
# 93 "slink.nw"
}

Slink& operator = (const Slink& l)
{
  if (not isEmpty())
    throwException<Invalid>("slink.nw", 98, "Invalid") ();
# 135 "slink.nw"
if (not l.isEmpty())
  throwException<Invalid>("slink.nw", 136, "Invalid") ();

next = this;
# 100 "slink.nw"
}

void reset()
{
                          ;
  next = this;
}

bool isEmpty() const
{
                          ;
  return next == this;
}

Slink* getNext() const
{
                          ;
  return next;
}
# 143 "slink.nw"
void insertNext(Slink* p)
{
                          ;
                       ;
                      ;

  p->next = next;
  next = p;
}
# 157 "slink.nw"
Slink * removeNext()
{
                          ;

  Slink * ret_val = next;
  next = ret_val->next;
  ret_val->reset();

  return ret_val;
}
# 19 "slink.nw"
};
# 225 "slink.nw"
# 23 "slink.nw"
# 10 "tpl_snode.nw" 2

    template <class T>
class Snode : public Slink
{
private:
# 40 "tpl_snode.nw"
T data;
# 18 "tpl_snode.nw"
public:
# 44 "tpl_snode.nw"
T& getData() { return data; }
# 49 "tpl_snode.nw"
Snode() { }

Snode(const T& _data) : data(_data) { }
# 64 "tpl_snode.nw"
Snode * removeNext() { return static_cast<Snode*>(Slink::removeNext()); }
# 74 "tpl_snode.nw"
Snode * getNext() const { return static_cast<Snode*>(Slink::getNext()); }
# 21 "tpl_snode.nw"
};
# 11 "tpl_listQueue.nw" 2

    template <class T>
class ListQueue
{
# 30 "tpl_listQueue.nw"
public:
typedef Snode<T> Node;
private:
# 17 "tpl_listQueue.nw"
# 98 "tpl_listQueue.nw"
Node * rear_ptr;
# 103 "tpl_listQueue.nw"
size_t num_nodes;
# 19 "tpl_listQueue.nw"
public:
# 108 "tpl_listQueue.nw"
ListQueue() : rear_ptr(__null), num_nodes(0) { }
# 116 "tpl_listQueue.nw"
void put(Node * node)
{
                         ;

  if (num_nodes > 0)
    rear_ptr->insertNext(node);

  num_nodes++;
  rear_ptr = node;
}
# 135 "tpl_listQueue.nw"
Node * get() throw(std::exception, AlephExc, Underflow)
{
# 150 "tpl_listQueue.nw"
if (num_nodes == 0)
  throwException<Underflow>("tpl_listQueue.nw", 151, "Underflow") (1);
# 139 "tpl_listQueue.nw"
 Node * ret_val = rear_ptr->removeNext();
  num_nodes--;

  if (num_nodes == 0)
    rear_ptr = __null;

  return ret_val;
}
# 156 "tpl_listQueue.nw"
Node * front() const throw(std::exception, AlephExc, Underflow)
{
# 150 "tpl_listQueue.nw"
if (num_nodes == 0)
  throwException<Underflow>("tpl_listQueue.nw", 151, "Underflow") (1);
# 160 "tpl_listQueue.nw"
 return rear_ptr->getNext();
}

Node * rear() const throw(std::exception, AlephExc, Underflow)
{
# 150 "tpl_listQueue.nw"
if (num_nodes == 0)
  throwException<Underflow>("tpl_listQueue.nw", 151, "Underflow") (1);
# 167 "tpl_listQueue.nw"
 return rear_ptr;
}
# 173 "tpl_listQueue.nw"
size_t size() const { return num_nodes; }

bool isEmpty() const { return num_nodes == 0; }
# 22 "tpl_listQueue.nw"
};
# 17 "tpl_dynListQueue.nw" 2
# 1 "../../../../src/aleph/ahNew.H" 1
# 18 "tpl_dynListQueue.nw" 2

    template <class T>
class DynListQueue : public ListQueue<T>
{
public:

  T& put(const T& data) throw(std::exception, AlephExc, Nomem)
  {
    Node * ptr = construct< Node >(*Aleph::objectAlloc) (data);

    ListQueue<T>::put(ptr);

    return ptr->getData();
  }

  T get() throw(std::exception, AlephExc, Underflow)
  {
    Node * ptr = ListQueue<T>::get();

    T ret_val = ptr->getData();
    destruct(*Aleph::objectAlloc, ptr);

    return ret_val;
  }

  T& front() const throw(std::exception, AlephExc, Underflow)
  {
    return ListQueue<T>::front()->getData();
  }

  T& rear() const throw(std::exception, AlephExc, Underflow)
  {
    return ListQueue<T>::rear()->getData();
  }

  virtual ~DynListQueue()
  {
    while (not isEmpty())
      get();
  }
};
# 59 "../../../../src/aleph/sendQueue.H" 2
# 1 "../../../../src/aleph/messages.H" 1
# 50 "../../../../src/aleph/messages.H"
# 1 "../../../../src/aleph/ahDefs.H" 1
# 51 "../../../../src/aleph/messages.H" 2
# 1 "../../../../src/aleph/dlink.H" 1
# 8 "dlink.nw"



# 1 "../../../../src/aleph/ahAssert.H" 1
# 12 "dlink.nw" 2
# 1 "../../../../src/aleph/ahExceptions.H" 1
# 13 "dlink.nw" 2

class Dlink
{
# 30 "dlink.nw"
protected:
Dlink* prev;
Dlink* next;
# 18 "dlink.nw"
public:
# 38 "dlink.nw"
Dlink() : prev(this), next(this) { }
# 44 "dlink.nw"
Dlink(const Dlink & l)
{
# 60 "dlink.nw"
if (not l.isEmpty())
  throwException<Invalid>("dlink.nw", 61, "Invalid") ();

next = prev = this;
# 47 "dlink.nw"
}

Dlink& operator = (const Dlink & l)
{
  if (not isEmpty())
    throwException<Invalid>("dlink.nw", 52, "Invalid") ();
# 60 "dlink.nw"
if (not l.isEmpty())
  throwException<Invalid>("dlink.nw", 61, "Invalid") ();

next = prev = this;
# 55 "dlink.nw"
 return *this;
}
# 72 "dlink.nw"
void reset()
{
                          ;
  next = prev = this;
}
# 82 "dlink.nw"
bool isEmpty() const
{
                          ;
  return (this == next) and (this == prev);
}
# 92 "dlink.nw"
void insert(Dlink* node)
{
                                                                          ;
                          ;
                         ;
  node->prev = this;
  node->next = next;
  next->prev = node;
  next = node;
}
# 114 "dlink.nw"
void append(Dlink* node)
{
                                                                          ;
                          ;
                         ;
  node->next = this;
  node->prev = prev;
  prev->next = node;
  prev = node;
}
# 133 "dlink.nw"
Dlink*& getNext()
{
                                                                          ;
  return next;
}

Dlink*& getPrev()
{
                                                                          ;
  return prev;
}
# 150 "dlink.nw"
void del()
{
                                                                          ;
                          ;
                          ;
  prev->next = next;
  next->prev = prev;
  reset();
}
# 179 "dlink.nw"
Dlink* removePrev()
{
                                                                          ;
                          ;
                          ;
  Dlink* retValue = prev;
  retValue->del();
  return retValue;
}

Dlink* removeNext()
{
                                                                          ;
                          ;
                          ;
  Dlink* retValue = next;
  retValue->del();
  return retValue;
}
# 21 "dlink.nw"
};
# 210 "dlink.nw"
# 25 "dlink.nw"
# 52 "../../../../src/aleph/messages.H" 2
# 1 "../../../../src/aleph/msgId.H" 1
# 53 "../../../../src/aleph/messages.H" 2
# 1 "../../../../src/aleph/port.H" 1
# 54 "../../../../src/aleph/messages.H" 2
# 1 "../../../../src/aleph/piggyback.H" 1
# 50 "../../../../src/aleph/piggyback.H"
# 1 "/usr/include/unistd.h" 1 3
# 51 "../../../../src/aleph/piggyback.H" 2
# 1 "/usr/include/sys/time.h" 1 3
# 52 "../../../../src/aleph/piggyback.H" 2
# 1 "../../../../src/aleph/dlink.H" 1
# 8 "dlink.nw"
# 53 "../../../../src/aleph/piggyback.H" 2
# 1 "../../../../src/aleph/tpl_lhash.H" 1
# 16 "tpl_lhash.nw"
# 257 "tpl_lhash.nw"
# 1 "../../../../src/aleph/ahNew.H" 1
# 258 "tpl_lhash.nw" 2
# 1 "../../../../src/aleph/primes.H" 1
# 11 "primes.nw"



# 1 "../../../../src/aleph/ahExceptions.H" 1
# 15 "primes.nw" 2

namespace Primes
{

extern const unsigned long DefaultPrime;

extern unsigned long next_prime(unsigned long n)
  throw(std::exception, AlephExc, SizeFault);

};
# 259 "tpl_lhash.nw" 2
# 1 "../../../../src/aleph/tpl_dlist.H" 1
# 7 "tpl_dlist.nw"



# 1 "../../../../src/aleph/tpl_dnode.H" 1
# 6 "tpl_dnode.nw"



# 1 "../../../../src/aleph/dlink.H" 1
# 8 "dlink.nw"
# 10 "tpl_dnode.nw" 2

    template <class T>
class Dnode : public Dlink
{
private:
# 29 "tpl_dnode.nw"
T data;
# 18 "tpl_dnode.nw"
public:
# 38 "tpl_dnode.nw"
Dnode<T>*& getNext() { return reinterpret_cast<Dnode<T>*&>(next); }

Dnode<T>*& getPrev() { return reinterpret_cast<Dnode<T>*&> (prev); }

Dnode<T>* removePrev()
{
  return static_cast<Dnode<T>*>(Dlink::removePrev());
}

Dnode<T>* removeNext()
{
  return static_cast<Dnode<T>*>(Dlink::removeNext());
}
# 59 "tpl_dnode.nw"
Dnode() { }

Dnode(const T& _data) : data(_data) { }
# 66 "tpl_dnode.nw"
Dnode& operator = (const T& _data)
{
  data = _data;
  return *this;
}
# 75 "tpl_dnode.nw"
T& getData() { return data; }
# 21 "tpl_dnode.nw"
};
# 11 "tpl_dlist.nw" 2
# 1 "../../../../src/aleph/ahNew.H" 1
# 12 "tpl_dlist.nw" 2
# 69 "tpl_dlist.nw"
 template <class T>
class Dlist_Node : public Dnode<T>
{
public:

  Dlist_Node() { }

  Dlist_Node(const T& _data) : Dnode<T>(_data) { }
};

    template <class T>
class Dlist_Node_Vtl : public Dlist_Node<T>
{
public:

  Dlist_Node_Vtl() { }

  virtual ~Dlist_Node_Vtl() { }

  Dlist_Node_Vtl(const T& _data) : Dlist_Node<T>(_data) { }
};
# 159 "tpl_dlist.nw"
 template <class T, class Node>
class MetaDlistNode : public Node
{
public:

  MetaDlistNode() { }

  MetaDlistNode(const T& _data) : Node(_data) { }

  MetaDlistNode*& getNext()
  {
    return reinterpret_cast<MetaDlistNode*&>(Node::getNext());
  }

  MetaDlistNode*& getPrev()
  {
    return reinterpret_cast<MetaDlistNode*&>(Node::getPrev());
  }
};
# 102 "tpl_dlist.nw"
 template <class T, class Node_Type>
class GenDlist : public Dnode<T>
{
public:
# 191 "tpl_dlist.nw"
typedef MetaDlistNode<T, Node_Type> Node;
typedef Node Item;
# 211 "tpl_dlist.nw"
Node* getFirst() throw(std::exception, AlephExc, Underflow)
{
# 225 "tpl_dlist.nw"
if (isEmpty())
  throwException<Underflow>("tpl_dlist.nw", 226, "Underflow") ();
# 214 "tpl_dlist.nw"
 return static_cast<Node*>(getNext());
}

Node* getLast() throw(std::exception, AlephExc, Underflow)
{
# 225 "tpl_dlist.nw"
if (isEmpty())
  throwException<Underflow>("tpl_dlist.nw", 226, "Underflow") ();
# 220 "tpl_dlist.nw"
 return static_cast<Node*>(getPrev());
}
# 233 "tpl_dlist.nw"
Node* removeFirst() throw(std::exception, AlephExc, Underflow)
{
# 225 "tpl_dlist.nw"
if (isEmpty())
  throwException<Underflow>("tpl_dlist.nw", 226, "Underflow") ();
# 236 "tpl_dlist.nw"
 Dnode<T>* retValue = getNext();
  retValue->del();

  return static_cast<Node*>(retValue);
}

Node* removeLast() throw(std::exception, AlephExc, Underflow)
{
# 225 "tpl_dlist.nw"
if (isEmpty())
  throwException<Underflow>("tpl_dlist.nw", 226, "Underflow") ();
# 245 "tpl_dlist.nw"
 Dnode<T>* retValue = getPrev();
  retValue->del();

  return static_cast<Node*>(retValue);
}
# 259 "tpl_dlist.nw"
friend class Iterator
{
private:
# 274 "tpl_dlist.nw"
Dnode<T> * head;
Dnode<T> * curr;
# 265 "tpl_dlist.nw"
public:
# 281 "tpl_dlist.nw"
Iterator() : head (__null), curr(__null) { }

Iterator(GenDlist<T, Node_Type>& list) : head (&list), curr(head->getNext())
{

}
# 295 "tpl_dlist.nw"
Iterator& operator = (GenDlist<T, Node>& list)
{
  head = &list;
  curr = head->getNext();
  return *this;
}
# 306 "tpl_dlist.nw"
void resetFirst()
{
                                               ;
  curr = head->getNext();
}

void resetLast()
{
                                               ;
  curr = head->getPrev();
}
# 323 "tpl_dlist.nw"
Node* getCurr() const throw(std::exception, AlephExc, Overflow)
{
# 331 "tpl_dlist.nw"
;
if (curr == head)
  throwException<Overflow>("tpl_dlist.nw", 333, "Overflow") ();
# 326 "tpl_dlist.nw"
 return static_cast<Node*>(curr);
}
# 338 "tpl_dlist.nw"
bool hasCurr() const
{
                                               ;
  return curr not_eq head;
}
# 348 "tpl_dlist.nw"
void prev() throw(std::exception, AlephExc, Overflow)
{
# 331 "tpl_dlist.nw"
;
if (curr == head)
  throwException<Overflow>("tpl_dlist.nw", 333, "Overflow") ();
# 351 "tpl_dlist.nw"
 curr = curr->getPrev();
}

void next() throw(std::exception, AlephExc, Overflow)
{
# 331 "tpl_dlist.nw"
;
if (curr == head)
  throwException<Overflow>("tpl_dlist.nw", 333, "Overflow") ();
# 357 "tpl_dlist.nw"
 curr = curr->getNext();
}
# 269 "tpl_dlist.nw"
};
# 372 "tpl_dlist.nw"
void removeAllAndDelete()
{
  Node* node;
  Iterator itor(*this);

  while (itor.hasCurr())
    {
      node = itor.getCurr();
      itor.next();
      node->del();
      destruct(*Aleph::objectAlloc, node);
    }
}
# 389 "tpl_dlist.nw"
bool check()
{
  Iterator itor(*this);
  Node* node;

  for ( ; itor.hasCurr(); itor.next())
    {
      node = itor.getCurr();
      if (not (node->getNext()->getPrev() == node))
        return false;
      if (not (node->getPrev()->getNext() == node))
        return false;
    }

  for (itor.resetLast(); itor.hasCurr(); itor.prev())
    {
      node = itor.getCurr();
      if (not (node->getNext()->getPrev() == node))
        return false;
      if (not (node->getPrev()->getNext() == node))
        return false;
    }

  return true;
}
# 108 "tpl_dlist.nw"
};
# 116 "tpl_dlist.nw"
 template <class T>
class Dlist : public GenDlist<T, Dlist_Node<T> > { };

template <class T>
class DlistVtl : public GenDlist<T, Dlist_Node_Vtl<T> > { };
# 21 "tpl_dlist.nw"
# 260 "tpl_lhash.nw" 2
# 20 "tpl_lhash.nw"
# 1 "../../../../src/aleph/primes.H" 1
# 11 "primes.nw"
# 21 "tpl_lhash.nw" 2
# 1 "../../../../src/aleph/tpl_dlist.H" 1
# 7 "tpl_dlist.nw"
# 22 "tpl_lhash.nw" 2
# 1 "../../../../src/aleph/ahNew.H" 1
# 23 "tpl_lhash.nw" 2

using namespace Primes;
# 327 "tpl_lhash.nw"
 template <class Key, class BucketType>
class GenLhashTable
{
public:

  typedef BucketType Bucket;

private:
# 135 "tpl_lhash.nw"
 typedef unsigned long (*HashFctType)(const Key&);
# 338 "tpl_lhash.nw"
# 384 "tpl_lhash.nw"
protected:

  typedef Dlist<Key> BucketList;

  typedef Dlist<Key>::Iterator BucketItor;
# 396 "tpl_lhash.nw"
private:

  BucketList* bucket_table;
# 405 "tpl_lhash.nw"
int table_size;

int busy_slots_counter;

int num_items;

HashFctType hashFct;

bool remove_all_buckets;
# 340 "tpl_lhash.nw"
protected:
# 424 "tpl_lhash.nw"
protected:

GenLhashTable(HashFctType _hashFct,
              int _table_size,
              bool _remove_all_buckets = true)
  throw(std::exception, AlephExc, SizeFault, Nomem) :
    table_size (_table_size),
    busy_slots_counter (0),
    num_items (0),
    hashFct (_hashFct),
    remove_all_buckets (_remove_all_buckets)
{
  table_size = next_prime(table_size);

  bucket_table = construct< BucketList >(*Aleph::objectAlloc) [table_size];
}

public:
# 344 "tpl_lhash.nw"
public:
# 447 "tpl_lhash.nw"
void removeAllAndDelete()
{
  int i;
  Bucket *node;

  for (i = 0; i < table_size; i++)
    {
      BucketList::Iterator itor(bucket_table[i]);
      while (itor.hasCurr())
        {
          node = static_cast<Bucket*>(itor.getCurr());
                               ;
          itor.next();
          node->del();
          destruct(*Aleph::objectAlloc, node);
        }
    }

  busy_slots_counter = 0;
  num_items = 0;
}
# 472 "tpl_lhash.nw"
virtual ~GenLhashTable()
{
  if (remove_all_buckets)
    removeAllAndDelete();

  destructArray(*Aleph::objectAlloc, bucket_table);
}
# 484 "tpl_lhash.nw"
Bucket* insert(Bucket* bucket)
{
  int bucket_index = (*hashFct)(bucket->getKey()) % table_size;

  if (bucket_table[bucket_index].isEmpty())
    busy_slots_counter++;

  bucket_table[bucket_index].append(bucket);

  ++num_items;

  return bucket;
}
# 501 "tpl_lhash.nw"
Bucket* search(const Key& key) const
{
  int bucket_index = (*hashFct)(key) % table_size;

  if (bucket_table[bucket_index].isEmpty())
    return __null;

  for (BucketList::Iterator itor(bucket_table[bucket_index]);
       itor.hasCurr();
       itor.next()
       )
    {
      Bucket* node = static_cast<Bucket*>(itor.getCurr());

      if (key == node->getKey())
        return node;
    }

  return __null;
}

Bucket* searchNext(Bucket* bucket) const
{
                            ;

  Dlist<Key>::Node * node = static_cast<Dlist<Key>::Node*>(bucket);

  for (node = static_cast<Dlist<Key>::Item *>(bucket)->getNext();
       node not_eq static_cast<Dlist<Key>::Item *>(bucket);
       node = node->getNext())
    {
      if (bucket->getKey() == static_cast<Bucket*>(node)->getKey())
        return static_cast<Bucket*>(node);
    }

  return bucket;
}

Bucket* searchPrev(Bucket* bucket) const
{
                            ;

  Dlist<Key>::Item * node = static_cast<Dlist<Key>::Item *>(bucket);

  for (node = static_cast<Dlist<Key>::Item *>(bucket)->getPrev();
       node not_eq static_cast<Dlist<Key>::Item *>(bucket);
       node = node->getPrev())
    {
      if (bucket->getKey() == static_cast<Bucket*>(node)->getKey())
        return static_cast<Bucket*>(node);
    }

  return bucket;
}
# 559 "tpl_lhash.nw"
Bucket* remove(Bucket* bucket)
{
                                            ;

  Bucket* next = static_cast<Bucket*>(bucket->getNext());

  bucket->del();

  if (next->isEmpty())
    busy_slots_counter--;

  --num_items;

  return bucket;
}
# 582 "tpl_lhash.nw"
int resize(int new_size) throw(std::exception, AlephExc, SizeFault, Nomem)
{
  new_size = next_prime(new_size);

  if (new_size == table_size)
    return table_size;

  BucketList* new_table = construct< BucketList >(*Aleph::objectAlloc) [new_size];


  BucketList* old_table = bucket_table;
  int old_size = table_size;

                                   ;
                                ;


  bucket_table = new_table;
  table_size = new_size;
  busy_slots_counter = 0;
  num_items = 0;

  for (int i = 0; i < old_size; i++)
    {

      for (BucketList::Iterator itor(old_table[i]);
           itor.hasCurr(); )
        {
          Bucket* node = static_cast<Bucket*>(itor.getCurr());
          itor.next();
          node->del();
          insert(node);

                                  ;
        }
    }
  destructArray(*Aleph::objectAlloc, old_table);

                                             ;
                                         ;

  return table_size;
}
# 638 "tpl_lhash.nw"
int resize_next() throw(std::exception, AlephExc, SizeFault, Nomem)
{
  return resize(table_size + 1);
}

int resize_prev() throw(std::exception, AlephExc, SizeFault, Nomem)
{
  return resize(table_size - 1);
}

int get_table_size() const
{
  return table_size;
}

int get_num_items() const
{
  return num_items;
}

int get_num_busy_slots() const
{
  return busy_slots_counter;
}
# 713 "tpl_lhash.nw"
friend class Iterator
{
private:
# 727 "tpl_lhash.nw"
int current_index;
BucketList::Iterator current_itor;
GenLhashTable* hash_table;
# 774 "tpl_lhash.nw"
void locate_next_available_entry()
{
                                ;

  while (1)
    {
      if (current_index == hash_table->table_size)
        throwException<Overflow>("tpl_lhash.nw", 781, "Overflow") ();

      if (current_index == hash_table->table_size - 1)
        {
          current_index = hash_table->table_size;
          return;
        }

      current_index++;

      if (not hash_table->bucket_table[current_index].isEmpty())
        {
          BucketList::Iterator itor(hash_table->bucket_table[current_index]);
          current_itor = itor;
# 745 "tpl_lhash.nw"
;
                              ;
# 796 "tpl_lhash.nw"
 return;
        }
    }
}
# 807 "tpl_lhash.nw"
void locate_next_available_bucket()
{
                                ;

  current_itor.next();

  if (not current_itor.hasCurr())
    locate_next_available_entry();
}
# 819 "tpl_lhash.nw"
void locate_prev_available_entry()
{
                                ;

  while (1)
    {
      if (current_index == -1)
        throwException<Underflow>("tpl_lhash.nw", 826, "Underflow") ();

      if (current_index == 0)
        {
          current_index = -1;
          return;
        }

      current_index--;

      if (not hash_table->bucket_table[current_index].isEmpty())
        {
          BucketList::Iterator itor(hash_table->bucket_table[current_index]);
          current_itor = itor;
          current_itor.resetLast();
# 745 "tpl_lhash.nw"
;
                              ;
# 842 "tpl_lhash.nw"
 return;
        }
    }
}
# 855 "tpl_lhash.nw"
void locate_prev_available_bucket()
{
                                ;

  current_itor.prev();

  if (not current_itor.hasCurr())
    locate_prev_available_entry();
}
# 719 "tpl_lhash.nw"
public:
# 867 "tpl_lhash.nw"
Iterator(GenLhashTable & table) : current_index(-1), hash_table(&table)
{
  try
    {
      locate_next_available_entry();
    }
  catch (Overflow)
    { }
}
# 879 "tpl_lhash.nw"
Iterator() : current_index(-1), hash_table(__null)
{

}
# 892 "tpl_lhash.nw"
void reset_first()
{
  current_index = -1;

  locate_next_available_entry();
}

void reset_last()
{
  current_index = hash_table->table_size;

  locate_prev_available_entry();
}
# 909 "tpl_lhash.nw"
bool has_current() const
{
  return current_index >= 0 and current_index < hash_table->table_size;
}
# 915 "tpl_lhash.nw"
Bucket * get_current()
{
  if (current_index == -1)
    throwException<Underflow>("tpl_lhash.nw", 918, "Underflow") ();

  if (current_index == hash_table->table_size)
    throwException<Overflow>("tpl_lhash.nw", 921, "Overflow") ();

  return static_cast<Bucket*>(current_itor.getCurr());
}
# 928 "tpl_lhash.nw"
void next()
{
  if (current_index == hash_table->table_size)
    throwException<Overflow>("tpl_lhash.nw", 931, "Overflow") ();
# 745 "tpl_lhash.nw"
;
                              ;
# 935 "tpl_lhash.nw"
 locate_next_available_bucket();
}

void prev()
{
  if (current_index == -1)
    throwException<Underflow>("tpl_lhash.nw", 941, "Underflow") ();
# 745 "tpl_lhash.nw"
;
                              ;
# 945 "tpl_lhash.nw"
 locate_prev_available_bucket();
}
# 722 "tpl_lhash.nw"
};
# 347 "tpl_lhash.nw"
};
# 262 "tpl_lhash.nw"
 template <class Key>
class LhashBucket : public Dlist<Key>::Node
{
private:

  LhashBucket(const LhashBucket&);
  LhashBucket& operator = (const LhashBucket&);

public:

  LhashBucket() { }

  LhashBucket(const Key& key) : Dlist<Key>::Node(key) { }

  Key& getKey() { return getData(); }
};
# 299 "tpl_lhash.nw"
 template <class Key>
class LhashBucketVtl : public LhashBucket<Key>
{
private:

  LhashBucketVtl(const LhashBucketVtl&);
  LhashBucketVtl& operator = (const LhashBucketVtl&);

public:

  LhashBucketVtl() { }

  virtual ~LhashBucketVtl() { }

  LhashBucketVtl(const Key& key) : LhashBucket<Key>(key) { }
};
# 32 "tpl_lhash.nw"
 template <class Key>
class LhashTable :
# 357 "tpl_lhash.nw"
 public GenLhashTable<Key, LhashBucket<Key> >
# 34 "tpl_lhash.nw"
{
public:
# 666 "tpl_lhash.nw"
 LhashTable(HashFctType _hashFct,
             const int _table_size = DefaultPrime,
             bool _remove_all_buckets = true)
    throw(std::exception, AlephExc, SizeFault, Nomem) :
      GenLhashTable<Key, LhashBucket<Key> >(_hashFct,
                                            _table_size,
                                            _remove_all_buckets)
  {

  }
# 38 "tpl_lhash.nw"
};

template <class Key>
class LhashTableVtl :
# 360 "tpl_lhash.nw"
 public GenLhashTable<Key, LhashBucketVtl<Key> >
# 42 "tpl_lhash.nw"
{
public:
# 677 "tpl_lhash.nw"
 LhashTableVtl(HashFctType _hashFct,
                const int _table_size = DefaultPrime,
                bool _remove_all_buckets = true)
    throw(std::exception, AlephExc, SizeFault, Nomem) :
      GenLhashTable<Key, LhashBucketVtl<Key> >(_hashFct,
                                               _table_size,
                                               _remove_all_buckets)
  {

  }
# 46 "tpl_lhash.nw"
};
# 54 "../../../../src/aleph/piggyback.H" 2
# 1 "../../../../src/aleph/messages.H" 1
# 55 "../../../../src/aleph/piggyback.H" 2
# 1 "../../../../src/aleph/timeoutQueue.H" 1
# 56 "../../../../src/aleph/piggyback.H" 2


class Piggyback_Message
{
public:

  enum Code
  {
    Reply_Ack,
    Single_Msg_Ack,
    Message_Lost,
    Empty
  };

private:

  MsgId msgid;

  Code code;

public:

  Piggyback_Message() : code(Empty) { }

  Piggyback_Message(const MsgId& _msgid, Code _code) :
    msgid(_msgid), code(_code)
  {

  }

  const MsgId& get_msgid() const { return msgid; }

  Code get_code() const { return code; }

  void set_code(Code _code) { code = _code; }

  void set_msgid(const MsgId& _msgid) { msgid = _msgid; }
};


class Piggyback_Array
{
  unsigned char num_messages;
  Piggyback_Message piggyback_array[0];

public:

  Piggyback_Array(int n = 0) : num_messages(n) { }

  Piggyback_Message * get_piggyback_message(int i)
  {
                             ;
    return &piggyback_array[i];
  }

  Piggyback_Message * get_piggyback_message()
  {
    return &piggyback_array[0];
  }

  int get_num_messages() const { return static_cast<int>(num_messages); }

  void set_num_messages(size_t n)
  {
    num_messages = static_cast<unsigned char>(n);
  }
};


extern unsigned long hash_fct_sites(const int &);
extern unsigned long hash_fct_messages(const MsgId &);


class Garbage_Collect_Piggybacks_Event : public TimeoutQueue::Event
{
public:

  Garbage_Collect_Piggybacks_Event(const struct timespec & _time) :
    TimeoutQueue::Event(_time)
  {

  }

  virtual ~Garbage_Collect_Piggybacks_Event()
  {
                                                  ;
  }

  virtual void EventFct();
};


class Piggyback_Table
{
  struct Piggyback_Descriptor;

  struct Site_Descriptor : public LhashTable<int>::Bucket
  {

    int get_target_ip() { return getKey(); }


    Dlink queue;

    int num_messages;

    inline void put_in_queue(Piggyback_Descriptor * pg);

    inline Piggyback_Descriptor * get_from_queue();

    Site_Descriptor(int tgt_ip) :
      LhashTable<int>::Bucket(tgt_ip), num_messages(0)
    {

    }
  };

  struct Piggyback_Descriptor : public LhashTable<MsgId>::Bucket
  {
    Site_Descriptor * site_descriptor;
    Piggyback_Message piggyback_message;
    struct timespec creation_time;
    Dlink dlink;

    static Piggyback_Descriptor * dlink_to_type(Dlink * l) { Piggyback_Descriptor * ptr_zero = 0; size_t offset_link = reinterpret_cast<size_t>(&(ptr_zero->dlink)); char * address_type = reinterpret_cast<char*>(l) - offset_link; return reinterpret_cast<Piggyback_Descriptor *>(address_type); };

    void remove_from_queue()
    {
      dlink.del();
      site_descriptor->num_messages--;
    }

    Piggyback_Descriptor(Site_Descriptor * _site_descriptor,
                         const MsgId& msgid,
                         Piggyback_Message::Code code) :
      LhashTable<MsgId>::Bucket(msgid),
      site_descriptor (_site_descriptor),
      piggyback_message (msgid, code),
      creation_time (read_current_time())
    {

    }

  struct timespec * get_creation_time() { return &creation_time; }
  };

  LhashTable<int> sites_table;

  LhashTable<MsgId> messages_table;

  pthread_mutex_t mutex;

  TimeoutQueue::Event * garbage_collect_piggyback_event;

  Site_Descriptor * current_site_descriptor;

  void cancel(Piggyback_Descriptor * piggyback_descriptor);

  void program_garbage_collect_piggyback_event();

  void cancel_garbage_collect_piggyback_event();

  Piggyback_Message get();

public:

  Piggyback_Table(size_t len_sites_table, size_t len_messages_table) :
    sites_table(hash_fct_sites, len_sites_table),
    messages_table(hash_fct_messages, len_messages_table),
    garbage_collect_piggyback_event (__null),
    current_site_descriptor (__null)
  {
    init_mutex(mutex);
  }

  virtual ~Piggyback_Table()
  {
    {
      UseMutex critical_section(mutex);
      sites_table.removeAllAndDelete();
      messages_table.removeAllAndDelete();
    }
    destroy_mutex(mutex);
  }

  void put(const MsgId& msgid, int tgt_ip, Piggyback_Message::Code code);

  int lock_table(int tgt_ip);

  void unlock_table();

  void get(Piggyback_Message piggyback_array[], int n);

  int get_current_target_ip()
  {
    return current_site_descriptor->get_target_ip();
  }

  void cancel(const MsgId& msgid);

  int get_num_piggyback_messages() const
  {
    if (current_site_descriptor == __null)
      throwException<NotInitialized>("../../../../src/aleph/piggyback.H", 259, "NotInitialized") ();

    return current_site_descriptor->num_messages;
  }


  void delete_messages(const struct timespec & time);

  void delete_all();
};


extern Piggyback_Table * piggyback_table_ptr;

extern void process_piggyback(Piggyback_Array&);

    inline
void Piggyback_Table::Site_Descriptor::put_in_queue
(Piggyback_Table::Piggyback_Descriptor * pg)
{
                                     ;
  queue.append(&pg->dlink);
  num_messages++;
}


    inline
Piggyback_Table::Piggyback_Descriptor *
Piggyback_Table::Site_Descriptor::get_from_queue()
{
  num_messages--;
  return Piggyback_Table::Piggyback_Descriptor::
    dlink_to_type(queue.removeNext());
}
# 55 "../../../../src/aleph/messages.H" 2

enum MessageCode {
  REQUEST,
  REPLY,
  LONGSERVICE,
  AREYOUALIVE,
  BADEPOCH,
  UNKNOWN_PORT,
  SINGLE_MESSAGE,
  ACKNOWLEDGE,
  LOST_MESSAGE,
  WEAK_MESSAGE,
  SERVER_CRASH
};


class MessageHeader
{
private:


  MessageCode code;


  MsgId msgId;


  unsigned int epoch;


  int addr;

public:

  MessageHeader(MessageCode _code, const MsgId& _msgid,
                unsigned int _epoch, unsigned int _addr)
    : code(_code), msgId(_msgid),
      epoch(_epoch), addr(_addr)
  {

  }

  MessageHeader(const MessageHeader& _message) :
    code (_message.code),
    msgId (_message.msgId),
    epoch (_message.epoch),
    addr (_message.addr)
  {

  }

  MessageHeader() { }

  ~MessageHeader() { }

  MessageCode getCode() const { return code; }

  const MsgId& getMsgId() const { return msgId; }

  unsigned int getEpoch() const { return epoch; }

  void setEpoch(unsigned int _epoch) { epoch = _epoch; }

  int get_target_ip() const { return addr; }

  size_t getDataSize() const { return 0; }
};


class RequestMsg : public MessageHeader
{
private:

  unsigned int clientEpoch;

  Port Targetport;


  unsigned int relayTime;

  size_t dataSize;

  char data[0];

public:

  RequestMsg(const MsgId& _msgid,
             unsigned int _epoch,
             unsigned int _addr,
             unsigned int _clientepoch,
             const Port& _port,
             unsigned int _relayTime,
             unsigned int _datasize,
             char* _data ) :
    MessageHeader(REQUEST, _msgid, _epoch, _addr),
    clientEpoch(_clientepoch),
    Targetport(_port), relayTime(_relayTime),
    dataSize(_datasize)
  {
    memcpy(data, _data, _datasize);
  }

  ~RequestMsg()
  {

  }

  char* getData()
  {
    return data;
  }

  size_t getDataSize() const
  {
    return dataSize;
  }

  unsigned int getClientEpoch() const
  {
    return clientEpoch;
  }

  const Port& getTargetPort() const
  {
    return Targetport;
  }

  unsigned int getRelayTime() const
  {
    return relayTime;
  }

  void setRelayTime(unsigned int _relaytime)
  {
    relayTime = _relaytime;
  }
};


class ReplyMsg : public MessageHeader
{
private:

  size_t dataSize;

  MsgId request_msgid;

  char data[0];

public:

  ReplyMsg(const MsgId& _msgid,
           const MsgId& _request_msgid,
           unsigned int _epoch,
           unsigned int _addr) :
    MessageHeader(REPLY, _msgid, _epoch, _addr),
    dataSize(0), request_msgid(_request_msgid)
  {

  }

  ReplyMsg(const MsgId& _msgid,
           const MsgId& _request_msgid,
           unsigned int _epoch,
           unsigned int _addr,
           unsigned int _dataSize,
           char* _data) :
    MessageHeader(REPLY, _msgid, _epoch, _addr),
    dataSize(_dataSize), request_msgid(_request_msgid)
  {
    memcpy(data, _data, _dataSize);
  }

  ~ReplyMsg()
  {

  }

  char* getData()
  {
    return data;
  }

  const MsgId& get_request_msgid() const { return request_msgid; }

  size_t getDataSize() const
  {
    return dataSize;
  }
};


struct LongServiceMsg : public MessageHeader
{
  LongServiceMsg(const MsgId& _msgid,
                 unsigned int _epoch,
                 unsigned int _addr) :
    MessageHeader(LONGSERVICE, _msgid, _epoch, _addr)
  {

  }
};


struct AreYouAliveMsg : public MessageHeader
{
  AreYouAliveMsg(const MsgId& _msgid,
                 unsigned int _epoch,
                 unsigned int _dirip ) :
    MessageHeader(AREYOUALIVE, _msgid, _epoch, _dirip)
  {

  }
};


class BadEpochMsg : public MessageHeader
{
public:

  BadEpochMsg(const MsgId& _msgid,
              unsigned int _epoch,
              unsigned int _dirip ) :
    MessageHeader(BADEPOCH, _msgid, _epoch, _dirip)
  {

  }
};


class UnknownMsg : public MessageHeader
{
public:

  enum Message_Type { Request, Single_Message};

private:

  Message_Type message_type;

public:

  UnknownMsg(Message_Type _message_type,
             const MsgId& _msgid,
             unsigned int _epoch,
             unsigned int _dirip ) :
    MessageHeader(UNKNOWN_PORT, _msgid, _epoch, _dirip),
    message_type (_message_type)
  {

  }

  Message_Type get_message_type() const { return message_type; }
};


class Single_Message : public MessageHeader
{
private:

  Port target_port;

  unsigned int relayTime;

  size_t dataSize;

  char data[0];

public:

  Single_Message(const MsgId& _msgid,
                 unsigned int _epoch,
                 unsigned int _addr,
                 const Port& _target_port,
                 unsigned int _relayTime,
                 unsigned int _datasize,
                 char* _data) :
    MessageHeader(SINGLE_MESSAGE, _msgid, _epoch, _addr),
    target_port(_target_port),
    relayTime(_relayTime),
    dataSize(_datasize)
  {
    memcpy(data, _data, _datasize);
  }

  ~Single_Message()
  {

  }

  char* getData()
  {
    return &data[0];
  }

  size_t getDataSize() const
  {
    return dataSize;
  }

  const Port& get_target_port() const
  {
    return target_port;
  }

  unsigned int getRelayTime() const
  {
    return relayTime;
  }

  void setRelayTime(unsigned int _relaytime)
  {
    relayTime = _relaytime;
  }
};


class Ack_Msg : public MessageHeader
{
public:

  Ack_Msg(const MsgId& _msgid,
          unsigned int _epoch,
          unsigned int _dirip) :
    MessageHeader(ACKNOWLEDGE, _msgid, _epoch, _dirip)
  {

  }
};


class Lost_Msg : public MessageHeader
{
public:

  Lost_Msg(const MsgId& _msgid,
          unsigned int _epoch,
          unsigned int _dirip) :
    MessageHeader(LOST_MESSAGE, _msgid, _epoch, _dirip)
  {

  }
};


class Weak_Message : public MessageHeader
{
private:

  size_t dataSize;

  char data[0];

public:

  Weak_Message(unsigned int _epoch,
               unsigned int _addr,
               unsigned int _sender_epoch,
               unsigned int _datasize,
               char* _data) :
    MessageHeader(WEAK_MESSAGE, Null_MsgId, _epoch, _addr),
    dataSize(_datasize)
  {
    memcpy(data, _data, _datasize);
  }

  ~Weak_Message()
  {

  }

  char* getData()
  {
    return &data[0];
  }

  size_t getDataSize() const
  {
    return dataSize;
  }
};



    template <class Msg_Type>
class Piggybacked_Message
{
  Msg_Type * msg;
  size_t size;
  Piggyback_Array * piggyback_array;

public:

  Piggybacked_Message() { }

  Piggybacked_Message(Msg_Type * _msg) : msg(static_cast<Msg_Type*>(_msg))
  {
    char * base_addr = reinterpret_cast<char*> (msg);

    char * start_pb_addr = base_addr + sizeof(*msg) + msg->getDataSize();

    piggyback_array = reinterpret_cast<Piggyback_Array *>(start_pb_addr);

    char * end_addr = (start_pb_addr + sizeof(*piggyback_array) +
                       piggyback_array->get_num_messages()*
                       sizeof(Piggyback_Message));

    size = end_addr - base_addr;
  }

  size_t get_message_size() const { return size; }

  Piggyback_Message * get_piggyback_message(int i)
  {
                                                   ;

    return &(piggyback_array->get_piggyback_message()[i]);
  }

  int get_num_piggyback_messages() const
  {
    return piggyback_array->get_num_messages();
  }

  Piggyback_Array * get_piggyback_array() { return piggyback_array; }
};


    template <class Msg_Type> void
build_piggybacked_message(Msg_Type * msg,
                          Piggybacked_Message<Msg_Type> & piggybacked_message)
{
  new (&piggybacked_message) Piggybacked_Message<Msg_Type>(msg);
}


    template <typename T>
Constructor<T> alloc_message(int tgt_ip,
                             size_t data_size,
                             int &num_piggyback





                             )
{
  try
    {
      num_piggyback = 0;
      piggyback_table_ptr->lock_table(tgt_ip);
      num_piggyback = piggyback_table_ptr->get_num_piggyback_messages();
    }
  catch (NotFound)
    { }
  catch (NotInitialized)
    { Aleph::error("../../../../src/aleph/messages.H", 511, "Bug: Inconsistency in piggyback_table"); }

  if (num_piggyback > max_num_piggyback)
    num_piggyback = max_num_piggyback;

  size_t msg_size = (sizeof(T) + data_size +
                     sizeof(Piggyback_Array) +
                     num_piggyback*sizeof(Piggyback_Message));

  return construct<T>(*Aleph::objectAlloc,



                      msg_size);
}


    template <class Msg_Type>
void load_piggyback_messages(Msg_Type* msg, int num_piggyback)
{
  Piggybacked_Message<Msg_Type> pgm(msg);

  Piggyback_Array * piggyback_array = pgm.get_piggyback_array();

  piggyback_array->set_num_messages(num_piggyback);

  if (num_piggyback == 0)
    return;

                                                                              ;

  piggyback_table_ptr->get(piggyback_array->get_piggyback_message(),
                           num_piggyback);
}


    template <typename Msg_Type> inline
Piggyback_Array * get_piggyback_array(MessageHeader * msg)
{
  Piggybacked_Message<Msg_Type> pbm(static_cast<Msg_Type*>(msg));

  return pbm.get_piggyback_array();
}
# 60 "../../../../src/aleph/sendQueue.H" 2
# 1 "../../../../src/aleph/ipcPars.H" 1
# 61 "../../../../src/aleph/sendQueue.H" 2



class SendQueue
{
  pthread_t threadId;
  bool isShutdown;
  pthread_mutex_t mutex;
  pthread_cond_t COND;
  UseCondVar cond;
  int sockfd;
  struct sockaddr_in serverAddr;
  DynListQueue<MessageHeader*> queue;
  static int instanceCounter;

  void *sendMessage();

  static void* sendMessageThread(void*);

  MessageHeader* get();

  void delete_message(MessageHeader*);

public:

  SendQueue();

  ~SendQueue();

  MessageHeader* put(MessageHeader* const item);

  void shutdown();

  pthread_t getThreadId() const { return threadId; }

};
# 55 "../../../../src/aleph/boot.H" 2
# 1 "../../../../src/aleph/receiveThread.H" 1
# 50 "../../../../src/aleph/receiveThread.H"
# 1 "/usr/include/sys/socket.h" 1 3
# 51 "../../../../src/aleph/receiveThread.H" 2
# 1 "/usr/include/netinet/in.h" 1 3
# 52 "../../../../src/aleph/receiveThread.H" 2
# 1 "/usr/include/string.h" 1 3
# 53 "../../../../src/aleph/receiveThread.H" 2
# 1 "/usr/include/pthread.h" 1 3
# 54 "../../../../src/aleph/receiveThread.H" 2
# 1 "../../../../src/aleph/aleph.H" 1
# 55 "../../../../src/aleph/receiveThread.H" 2
# 1 "../../../../src/aleph/sendQueue.H" 1
# 56 "../../../../src/aleph/receiveThread.H" 2
# 1 "../../../../src/aleph/messages.H" 1
# 57 "../../../../src/aleph/receiveThread.H" 2
# 1 "../../../../src/aleph/signal.H" 1
# 49 "../../../../src/aleph/signal.H"
# 1 "/usr/include/signal.h" 1 3
# 29 "/usr/include/signal.h" 3
# 1 "/usr/include/features.h" 1 3
# 30 "/usr/include/signal.h" 2 3

extern "C" {

# 1 "/usr/include/bits/sigset.h" 1 3
# 103 "/usr/include/bits/sigset.h" 3
extern int __sigismember (__const __sigset_t *, int);
extern int __sigaddset (__sigset_t *, int);
extern int __sigdelset (__sigset_t *, int);
# 117 "/usr/include/bits/sigset.h" 3
extern __inline int __sigismember (__const __sigset_t *__set, int __sig) { unsigned long int __mask = (((unsigned long int) 1) << (((__sig) - 1) % (8 * sizeof (unsigned long int)))); unsigned long int __word = (((__sig) - 1) / (8 * sizeof (unsigned long int))); return (__set->__val[__word] & __mask) ? 1 : 0; }
extern __inline int __sigaddset ( __sigset_t *__set, int __sig) { unsigned long int __mask = (((unsigned long int) 1) << (((__sig) - 1) % (8 * sizeof (unsigned long int)))); unsigned long int __word = (((__sig) - 1) / (8 * sizeof (unsigned long int))); return ((__set->__val[__word] |= __mask), 0); }
extern __inline int __sigdelset ( __sigset_t *__set, int __sig) { unsigned long int __mask = (((unsigned long int) 1) << (((__sig) - 1) % (8 * sizeof (unsigned long int)))); unsigned long int __word = (((__sig) - 1) / (8 * sizeof (unsigned long int))); return ((__set->__val[__word] &= ~__mask), 0); }
# 34 "/usr/include/signal.h" 2 3






typedef __sig_atomic_t sig_atomic_t;
# 55 "/usr/include/signal.h" 3
# 1 "/usr/include/bits/types.h" 1 3
# 56 "/usr/include/signal.h" 2 3
# 1 "/usr/include/bits/signum.h" 1 3
# 57 "/usr/include/signal.h" 2 3
# 71 "/usr/include/signal.h" 3
typedef void (*__sighandler_t) (int);




extern __sighandler_t __sysv_signal (int __sig, __sighandler_t __handler)
     throw ();

extern __sighandler_t sysv_signal (int __sig, __sighandler_t __handler)
     throw ();






extern __sighandler_t signal (int __sig, __sighandler_t __handler) throw ();
# 103 "/usr/include/signal.h" 3
extern __sighandler_t bsd_signal (int __sig, __sighandler_t __handler) throw ();






extern int kill (__pid_t __pid, int __sig) throw ();






extern int killpg (__pid_t __pgrp, int __sig) throw ();



extern int raise (int __sig) throw ();



extern __sighandler_t ssignal (int __sig, __sighandler_t __handler) throw ();
extern int gsignal (int __sig) throw ();




extern void psignal (int __sig, __const char *__s) throw ();
# 140 "/usr/include/signal.h" 3
extern int __sigpause (int __sig_or_mask, int __is_sig) throw ();




extern int sigpause (int __mask) throw ();
# 168 "/usr/include/signal.h" 3
extern int sigblock (int __mask) throw ();


extern int sigsetmask (int __mask) throw ();


extern int siggetmask (void) throw ();
# 183 "/usr/include/signal.h" 3
typedef __sighandler_t sighandler_t;




typedef __sighandler_t sig_t;







# 1 "/usr/include/time.h" 1 3
# 197 "/usr/include/signal.h" 2 3


# 1 "/usr/include/bits/siginfo.h" 1 3
# 25 "/usr/include/bits/siginfo.h" 3
# 1 "/usr/include/bits/wordsize.h" 1 3
# 26 "/usr/include/bits/siginfo.h" 2 3







typedef union sigval
  {
    int sival_int;
    void *sival_ptr;
  } sigval_t;
# 51 "/usr/include/bits/siginfo.h" 3
typedef struct siginfo
  {
    int si_signo;
    int si_errno;

    int si_code;

    union
      {
        int _pad[((128 / sizeof (int)) - 3)];


        struct
          {
            __pid_t si_pid;
            __uid_t si_uid;
          } _kill;


        struct
          {
            unsigned int _timer1;
            unsigned int _timer2;
          } _timer;


        struct
          {
            __pid_t si_pid;
            __uid_t si_uid;
            sigval_t si_sigval;
          } _rt;


        struct
          {
            __pid_t si_pid;
            __uid_t si_uid;
            int si_status;
            __clock_t si_utime;
            __clock_t si_stime;
          } _sigchld;


        struct
          {
            void *si_addr;
          } _sigfault;


        struct
          {
            long int si_band;
            int si_fd;
          } _sigpoll;
      } _sifields;
  } siginfo_t;
# 128 "/usr/include/bits/siginfo.h" 3
enum
{
  SI_ASYNCNL = -6,

  SI_SIGIO,

  SI_ASYNCIO,

  SI_MESGQ,

  SI_TIMER,

  SI_QUEUE,

  SI_USER,

  SI_KERNEL = 0x80

};



enum
{
  ILL_ILLOPC = 1,

  ILL_ILLOPN,

  ILL_ILLADR,

  ILL_ILLTRP,

  ILL_PRVOPC,

  ILL_PRVREG,

  ILL_COPROC,

  ILL_BADSTK

};


enum
{
  FPE_INTDIV = 1,

  FPE_INTOVF,

  FPE_FLTDIV,

  FPE_FLTOVF,

  FPE_FLTUND,

  FPE_FLTRES,

  FPE_FLTINV,

  FPE_FLTSUB

};


enum
{
  SEGV_MAPERR = 1,

  SEGV_ACCERR

};


enum
{
  BUS_ADRALN = 1,

  BUS_ADRERR,

  BUS_OBJERR

};


enum
{
  TRAP_BRKPT = 1,

  TRAP_TRACE

};


enum
{
  CLD_EXITED = 1,

  CLD_KILLED,

  CLD_DUMPED,

  CLD_TRAPPED,

  CLD_STOPPED,

  CLD_CONTINUED

};


enum
{
  POLL_IN = 1,

  POLL_OUT,

  POLL_MSG,

  POLL_ERR,

  POLL_PRI,

  POLL_HUP

};
# 271 "/usr/include/bits/siginfo.h" 3
struct __pthread_attr_s;

typedef struct sigevent
  {
    sigval_t sigev_value;
    int sigev_signo;
    int sigev_notify;

    union
      {
        int _pad[((64 / sizeof (int)) - 3)];

        struct
          {
            void (*_function) (sigval_t);
            struct __pthread_attr_s *_attribute;
          } _sigev_thread;
      } _sigev_un;
  } sigevent_t;






enum
{
  SIGEV_SIGNAL = 0,

  SIGEV_NONE,

  SIGEV_THREAD

};
# 200 "/usr/include/signal.h" 2 3



extern int sigemptyset (sigset_t *__set) throw ();


extern int sigfillset (sigset_t *__set) throw ();


extern int sigaddset (sigset_t *__set, int __signo) throw ();


extern int sigdelset (sigset_t *__set, int __signo) throw ();


extern int sigismember (__const sigset_t *__set, int __signo) throw ();



extern int sigisemptyset (__const sigset_t *__set) throw ();


extern int sigandset (sigset_t *__set, __const sigset_t *__left,
                      __const sigset_t *__right) throw ();


extern int sigorset (sigset_t *__set, __const sigset_t *__left,
                     __const sigset_t *__right) throw ();




# 1 "/usr/include/bits/sigaction.h" 1 3
# 25 "/usr/include/bits/sigaction.h" 3
struct sigaction
  {


    union
      {

        __sighandler_t sa_handler;

        void (*sa_sigaction) (int, siginfo_t *, void *);
      }
    __sigaction_handler;







    __sigset_t sa_mask;


    int sa_flags;


    void (*sa_restorer) (void);
  };
# 233 "/usr/include/signal.h" 2 3


extern int sigprocmask (int __how, __const sigset_t *__restrict __set,
                        sigset_t *__restrict __oset) throw ();



extern int sigsuspend (__const sigset_t *__set) throw ();


extern int sigaction (int __sig, __const struct sigaction *__restrict __act,
                      struct sigaction *__restrict __oact) throw ();


extern int sigpending (sigset_t *__set) throw ();



extern int sigwait (__const sigset_t *__restrict __set, int *__restrict __sig)
     throw ();



extern int sigwaitinfo (__const sigset_t *__restrict __set,
                        siginfo_t *__restrict __info) throw ();



extern int sigtimedwait (__const sigset_t *__restrict __set,
                         siginfo_t *__restrict __info,
                         __const struct timespec *__restrict __timeout)
     throw ();



extern int sigqueue (__pid_t __pid, int __sig, __const union sigval __val)
     throw ();
# 278 "/usr/include/signal.h" 3
extern __const char *__const _sys_siglist[64];
extern __const char *__const sys_siglist[64];


struct sigvec
  {
    __sighandler_t sv_handler;
    int sv_mask;

    int sv_flags;

  };
# 302 "/usr/include/signal.h" 3
extern int sigvec (int __sig, __const struct sigvec *__vec,
                   struct sigvec *__ovec) throw ();



# 1 "/usr/include/bits/sigcontext.h" 1 3
# 28 "/usr/include/bits/sigcontext.h" 3
# 1 "/usr/include/asm/sigcontext.h" 1 3
# 18 "/usr/include/asm/sigcontext.h" 3
struct _fpreg {
        unsigned short significand[4];
        unsigned short exponent;
};

struct _fpxreg {
        unsigned short significand[4];
        unsigned short exponent;
        unsigned short padding[3];
};

struct _xmmreg {
        unsigned long element[4];
};

struct _fpstate {

        unsigned long cw;
        unsigned long sw;
        unsigned long tag;
        unsigned long ipoff;
        unsigned long cssel;
        unsigned long dataoff;
        unsigned long datasel;
        struct _fpreg _st[8];
        unsigned short status;
        unsigned short magic;


        unsigned long _fxsr_env[6];
        unsigned long mxcsr;
        unsigned long reserved;
        struct _fpxreg _fxsr_st[8];
        struct _xmmreg _xmm[8];
        unsigned long padding[56];
};



struct sigcontext {
        unsigned short gs, __gsh;
        unsigned short fs, __fsh;
        unsigned short es, __esh;
        unsigned short ds, __dsh;
        unsigned long edi;
        unsigned long esi;
        unsigned long ebp;
        unsigned long esp;
        unsigned long ebx;
        unsigned long edx;
        unsigned long ecx;
        unsigned long eax;
        unsigned long trapno;
        unsigned long err;
        unsigned long eip;
        unsigned short cs, __csh;
        unsigned long eflags;
        unsigned long esp_at_signal;
        unsigned short ss, __ssh;
        struct _fpstate * fpstate;
        unsigned long oldmask;
        unsigned long cr2;
};
# 29 "/usr/include/bits/sigcontext.h" 2 3
# 308 "/usr/include/signal.h" 2 3


extern int sigreturn (struct sigcontext *__scp) throw ();
# 320 "/usr/include/signal.h" 3
extern int siginterrupt (int __sig, int __interrupt) throw ();

# 1 "/usr/include/bits/sigstack.h" 1 3
# 26 "/usr/include/bits/sigstack.h" 3
struct sigstack
  {
    void *ss_sp;
    int ss_onstack;
  };



enum
{
  SS_ONSTACK = 1,

  SS_DISABLE

};
# 50 "/usr/include/bits/sigstack.h" 3
typedef struct sigaltstack
  {
    void *ss_sp;
    int ss_flags;
    size_t ss_size;
  } stack_t;
# 323 "/usr/include/signal.h" 2 3

# 1 "/usr/include/ucontext.h" 1 3
# 24 "/usr/include/ucontext.h" 3
# 1 "/usr/include/features.h" 1 3
# 25 "/usr/include/ucontext.h" 2 3


# 1 "/usr/include/sys/ucontext.h" 1 3
# 22 "/usr/include/sys/ucontext.h" 3
# 1 "/usr/include/features.h" 1 3
# 23 "/usr/include/sys/ucontext.h" 2 3
# 1 "/usr/include/signal.h" 1 3
# 24 "/usr/include/sys/ucontext.h" 2 3



# 1 "/usr/include/bits/sigcontext.h" 1 3
# 28 "/usr/include/sys/ucontext.h" 2 3



typedef int greg_t;





typedef greg_t gregset_t[19];



enum
{
  REG_GS = 0,

  REG_FS,

  REG_ES,

  REG_DS,

  REG_EDI,

  REG_ESI,

  REG_EBP,

  REG_ESP,

  REG_EBX,

  REG_EDX,

  REG_ECX,

  REG_EAX,

  REG_TRAPNO,

  REG_ERR,

  REG_EIP,

  REG_CS,

  REG_EFL,

  REG_UESP,

  REG_SS

};



struct _libc_fpreg
{
  unsigned short int significand[4];
  unsigned short int exponent;
};

struct _libc_fpstate
{
  unsigned long int cw;
  unsigned long int sw;
  unsigned long int tag;
  unsigned long int ipoff;
  unsigned long int cssel;
  unsigned long int dataoff;
  unsigned long int datasel;
  struct _libc_fpreg _st[8];
  unsigned long int status;
};


typedef struct _libc_fpstate *fpregset_t;


typedef struct
  {
    gregset_t gregs;


    fpregset_t fpregs;
    unsigned long int oldmask;
    unsigned long int cr2;
  } mcontext_t;


typedef struct ucontext
  {
    unsigned long int uc_flags;
    struct ucontext *uc_link;
    stack_t uc_stack;
    mcontext_t uc_mcontext;
    __sigset_t uc_sigmask;
    struct _libc_fpstate __fpregs_mem;
  } ucontext_t;
# 28 "/usr/include/ucontext.h" 2 3

extern "C" {


extern int getcontext (ucontext_t *__ucp) throw ();


extern int setcontext (__const ucontext_t *__ucp) throw ();



extern int swapcontext (ucontext_t *__restrict __oucp,
                        __const ucontext_t *__restrict __ucp) throw ();







extern void makecontext (ucontext_t *__ucp, void (*__func) (void),
                         int __argc, ...) throw ();

}
# 325 "/usr/include/signal.h" 2 3





extern int sigstack (struct sigstack *__ss, struct sigstack *__oss) throw ();



extern int sigaltstack (__const struct sigaltstack *__restrict __ss,
                        struct sigaltstack *__restrict __oss) throw ();







extern int sighold (int __sig) throw ();


extern int sigrelse (int __sig) throw ();


extern int sigignore (int __sig) throw ();


extern __sighandler_t sigset (int __sig, __sighandler_t __disp) throw ();





# 1 "/usr/include/bits/sigthread.h" 1 3
# 359 "/usr/include/signal.h" 2 3






extern int __libc_current_sigrtmin (void) throw ();

extern int __libc_current_sigrtmax (void) throw ();



}
# 50 "../../../../src/aleph/signal.H" 2
# 1 "../../../../src/aleph/aleph.H" 1
# 51 "../../../../src/aleph/signal.H" 2

class Signal
{

  typedef void Sigfunc(int);

  struct sigaction oldSigaction;
  int signalNumber;
  bool restartCalls;


public:

  Signal(int signo, Sigfunc *func, bool _restartcalls = true)
    : restartCalls(_restartcalls)
    {
      struct sigaction act, oact;

      signalNumber = signo;
      act.__sigaction_handler.sa_handler = func;
      sigemptyset(&act.sa_mask);
      act.sa_flags = 0;

      if (signo == 14) {

        act.sa_flags |= 0x20000000;

      } else {
        if (restartCalls)
          {

            act.sa_flags |= 0x10000000;

          }
      }

      if (sigaction(signo, &act, &oact) < 0)
        Aleph::error("../../../../src/aleph/signal.H", 88, "Cannot modify the action associated with the %d signal " , signo);


      oldSigaction = oact;
                       ;


    }

  ~Signal()
    {
      if (sigaction(signalNumber, &oldSigaction, __null) < 0)
        Aleph::error("../../../../src/aleph/signal.H", 100, "Cannot modify the action associated with the %d signal " , signalNumber);


                              ;


    }

};
# 58 "../../../../src/aleph/receiveThread.H" 2
# 1 "../../../../src/aleph/timeoutEvent.H" 1
# 49 "../../../../src/aleph/timeoutEvent.H"
# 1 "/usr/include/time.h" 1 3
# 50 "../../../../src/aleph/timeoutEvent.H" 2
# 1 "../../../../src/aleph/aleph.H" 1
# 51 "../../../../src/aleph/timeoutEvent.H" 2
# 1 "../../../../src/aleph/dlink.H" 1
# 8 "dlink.nw"
# 52 "../../../../src/aleph/timeoutEvent.H" 2
# 1 "../../../../src/aleph/timeoutQueue.H" 1
# 53 "../../../../src/aleph/timeoutEvent.H" 2
# 1 "../../../../src/aleph/msgId.H" 1
# 54 "../../../../src/aleph/timeoutEvent.H" 2
# 1 "../../../../src/aleph/messages.H" 1
# 55 "../../../../src/aleph/timeoutEvent.H" 2
# 1 "../../../../src/aleph/connectionTable.H" 1
# 50 "../../../../src/aleph/connectionTable.H"
# 1 "/usr/include/sys/un.h" 1 3
# 51 "../../../../src/aleph/connectionTable.H" 2
# 1 "/usr/include/stdint.h" 1 3
# 52 "../../../../src/aleph/connectionTable.H" 2
# 1 "/usr/include/errno.h" 1 3
# 53 "../../../../src/aleph/connectionTable.H" 2
# 1 "/usr/local/include/g++-v3/iostream" 1 3
# 54 "../../../../src/aleph/connectionTable.H" 2
# 1 "../../../../src/aleph/socket_wrappers.H" 1
# 50 "../../../../src/aleph/socket_wrappers.H"
extern "C" {

# 1 "/usr/include/sys/types.h" 1 3
# 53 "../../../../src/aleph/socket_wrappers.H" 2


ssize_t readn(int, void *, size_t);
ssize_t writen(int, const void *, size_t);

ssize_t flushn(int, size_t);

}
# 55 "../../../../src/aleph/connectionTable.H" 2
# 1 "../../../../src/aleph/dlink.H" 1
# 8 "dlink.nw"
# 56 "../../../../src/aleph/connectionTable.H" 2
# 1 "../../../../src/aleph/protected_odhash.H" 1
# 50 "../../../../src/aleph/protected_odhash.H"
# 1 "../../../../src/aleph/tpl_odhash.H" 1
# 34 "tpl_odhash.nw"



# 1 "../../../../src/aleph/primes.H" 1
# 11 "primes.nw"
# 38 "tpl_odhash.nw" 2
# 1 "../../../../src/aleph/ahNew.H" 1
# 39 "tpl_odhash.nw" 2

using namespace Primes;
# 326 "tpl_odhash.nw"
# 354 "tpl_odhash.nw"
# 44 "tpl_odhash.nw"
 template <class Key, class Record>
class ODhashTable
{
private:
# 98 "tpl_odhash.nw"
 typedef long (*HashFctType)(const Key&);
# 50 "tpl_odhash.nw"
# 297 "tpl_odhash.nw"
 struct Bucket
  {
# 314 "tpl_odhash.nw"
 Key key;
    Record record;
    unsigned char state;
    unsigned char probe_type;
    unsigned short collision_counter;
# 300 "tpl_odhash.nw"
# 407 "tpl_odhash.nw"
Bucket() :
  state (0),
  probe_type (0),
  collision_counter (0)
{

}
# 301 "tpl_odhash.nw"
# 416 "tpl_odhash.nw"
 void increase_collision_counter() { collision_counter++; }

  void decrease_collision_counter() { collision_counter--; }
# 302 "tpl_odhash.nw"
 };
# 51 "tpl_odhash.nw"
# 1074 "tpl_odhash.nw"
 friend class ODProxy
  {
  private:
# 1093 "tpl_odhash.nw"
 ODhashTable & table;
# 1098 "tpl_odhash.nw"
 const Key & key;
# 1105 "tpl_odhash.nw"
 Bucket * bucket;
# 1080 "tpl_odhash.nw"
 public:
# 1162 "tpl_odhash.nw"
 ODProxy(ODhashTable & _table, const Key& _key) :
    table (_table),
    key (_key)
  {
    Record * record = table.search(key);

    if (record == __null)
      {
        bucket = __null;
        return;
      }

    bucket = table.record_to_bucket(record);
  }
# 1196 "tpl_odhash.nw"
 operator const Record& () const throw(std::exception, AlephExc, NotFound)
  {
    if (bucket == __null)
      throwException<NotFound>("tpl_odhash.nw", 1199, "NotFound") ();

    return bucket->record;
  }
# 1230 "tpl_odhash.nw"
ODProxy& operator = (const Record& record) throw(std::exception, AlephExc, Overflow)
  {
    if (bucket == __null)
      table.insert(key, record);
    else
      bucket->record = record;
    return *this;
  }
# 1249 "tpl_odhash.nw"
 ODProxy& operator = (const ODProxy& proxy)
    throw(std::exception, AlephExc, Overflow, NotFound)
  {
    if (proxy.bucket == __null)
      throwException<NotFound>("tpl_odhash.nw", 1253, "NotFound") ();

    if (bucket == __null)
      table.insert(proxy.key, proxy.bucket->record);
    else
      bucket->record = proxy.bucket->record;
    return *this;
  }
# 1083 "tpl_odhash.nw"
 };
# 52 "tpl_odhash.nw"
# 307 "tpl_odhash.nw"
 Bucket * bucket_table;
# 430 "tpl_odhash.nw"
 HashFctType first_hash_fct;
  HashFctType second_hash_fct;
  int table_size;
  int busy_entries_counter;
  int deleted_entries_counter;
  int empty_entries_counter;
# 53 "tpl_odhash.nw"
# 480 "tpl_odhash.nw"
 Record* allocate_bucket(Bucket& bucket,
                          unsigned char probe_type,
                          const Key& key,
                          const Record& record)
  {
                                           ;
                                                                             ;


    busy_entries_counter++;
    if (bucket.state == 0)
      empty_entries_counter--;
    else
      deleted_entries_counter--;

    bucket.key = key;
    bucket.record = record;
    bucket.state = 1;
    bucket.probe_type = probe_type;
    bucket.increase_collision_counter();

    return &bucket.record;
  }
# 518 "tpl_odhash.nw"
 void advance_index(int &i)
  {
                          ;

    i++;
    if (i == table_size)
      i = 0;
  }
# 675 "tpl_odhash.nw"
 static Bucket * record_to_bucket(Record * rec)
  {
    Bucket * ret_val = 0;
    int offset = reinterpret_cast<int>(&ret_val->record);
    return reinterpret_cast<Bucket*>(reinterpret_cast<int>(rec) - offset);
  }
# 696 "tpl_odhash.nw"
 bool is_valid_bucket(Bucket * bucket)
  {
    if (bucket < &bucket_table[0] or bucket >= &bucket_table[table_size])
      return false;

    int offset_with_base = (reinterpret_cast<char*>(bucket) -
                               reinterpret_cast<char*>(&bucket_table[0]));

    return offset_with_base % sizeof(*bucket) == 0;
  }
# 727 "tpl_odhash.nw"
 int bucket_to_index(Bucket * bucket)
  {
                                   ;

    return bucket - &bucket_table[0];
  }
# 799 "tpl_odhash.nw"
 void deallocate_bucket(Bucket * bucket)
  {
                                        ;
                                         ;

    bucket->decrease_collision_counter();

    if (bucket->collision_counter == 0)
      {
        bucket->state = 0;
        bucket->probe_type = 0;
        empty_entries_counter++;
      }
    else
      {
        bucket->state = 2;
        deleted_entries_counter++;
      }
    busy_entries_counter--;
  }
# 833 "tpl_odhash.nw"
 void decrease_bucket(Bucket * bucket)
  {
                                                                           ;
                                         ;

    bucket->decrease_collision_counter();

    if (bucket->collision_counter == 0)
      {
                                               ;
        bucket->state = 0;
        deleted_entries_counter--;
        empty_entries_counter++;
      }
  }
# 55 "tpl_odhash.nw"
public:
# 89 "tpl_odhash.nw"
inline ODhashTable(HashFctType _first_hash_fct,
                   HashFctType _second_hash_fct,
                   int len)
  throw(std::exception, AlephExc, SizeFault, Nomem);
# 121 "tpl_odhash.nw"
inline ~ODhashTable();
# 133 "tpl_odhash.nw"
 inline Record* insert(const Key & key, const Record& record)
    throw(std::exception, AlephExc, Overflow);
# 156 "tpl_odhash.nw"
 inline Record* search(const Key& key);
# 161 "tpl_odhash.nw"
 inline void remove(Record * record)
    throw(std::exception, AlephExc, AddrFault, NotFound);
# 189 "tpl_odhash.nw"
 inline int resize(int new_size)
    throw(std::exception, AlephExc, Nomem, Overflow, SizeFault);
# 217 "tpl_odhash.nw"
 inline int resize_next()
    throw(std::exception, AlephExc, Nomem, Overflow, SizeFault);

  inline int resize_prev()
    throw(std::exception, AlephExc, Nomem, Overflow, SizeFault);
# 231 "tpl_odhash.nw"
void remove_all_and_delete();
# 242 "tpl_odhash.nw"
 inline const ODProxy operator [] (const Key& key) const;

  inline ODProxy operator [] (const Key& key);
# 266 "tpl_odhash.nw"
 inline int count_deleted_entries() const;

  inline int count_busy_entries() const;

  inline int count_empty_entries() const;
# 286 "tpl_odhash.nw"
const Key & get_key(const Record* record);
# 109 "tpl_odhash.nw"
 inline int get_table_size() const;
# 154 "tpl_odhash.nw"
 inline int get_num_items() const;
# 279 "tpl_odhash.nw"
 inline int get_num_deleted_entries() const;

  inline int get_num_empty_entries() const;
# 1353 "tpl_odhash.nw"
friend class Iterator
{
private:
# 1366 "tpl_odhash.nw"
int current_index;
ODhashTable* hash_table;
# 1379 "tpl_odhash.nw"
void locate_first_available_bucket()
{
                             ;

  if (hash_table->get_num_items() == 0)
    throwException<Overflow>("tpl_odhash.nw", 1384, "Overflow") ();

  current_index = 0;
  while (hash_table->bucket_table[current_index].state not_eq 1)
    current_index++;

                                                ;
}
# 1395 "tpl_odhash.nw"
void locate_last_available_bucket()
{
                                                 ;

  if (hash_table->get_num_items() == 0)
    throwException<Underflow>("tpl_odhash.nw", 1400, "Underflow") ();

  current_index = hash_table->table_size;
  while (hash_table->bucket_table[current_index].state not_eq 1)
    current_index--;

                           ;
}
# 1452 "tpl_odhash.nw"
void locate_next_available_bucket()
{
  if (current_index == -1)
    locate_first_available_bucket();

  if (current_index == hash_table->table_size)
    throwException<Overflow>("tpl_odhash.nw", 1458, "Overflow") ();

  do
    current_index++;
  while (current_index < hash_table->table_size and
         hash_table->bucket_table[current_index].state not_eq 1);
}

void locate_prev_available_bucket()
{
  if (current_index == hash_table->table_size)
    locate_last_available_bucket();

  if (current_index == -1)
    throwException<Underflow>("tpl_odhash.nw", 1472, "Underflow") ();

  do
    current_index--;
  while (current_index >= 0 and
         hash_table->bucket_table[current_index].state not_eq 1);
}
# 1359 "tpl_odhash.nw"
public:
# 1410 "tpl_odhash.nw"
Iterator(ODhashTable<Key, Record> & _hash_table) :
  current_index (-1),
  hash_table (&_hash_table)
{
  try
    {
      locate_first_available_bucket();
    }
  catch (Overflow) { }
}

Iterator(const Iterator& itor) :
  current_index (itor.current_index),
  hash_table (itor.hash_table)
{

}
# 1429 "tpl_odhash.nw"
Record * get_current()
{
  if (current_index == -1)
    throwException<Underflow>("tpl_odhash.nw", 1432, "Underflow") ();

  if (current_index == hash_table->table_size)
    throwException<Overflow>("tpl_odhash.nw", 1435, "Overflow") ();

                                                                      ;

  return &(hash_table->bucket_table[current_index].record);
}
# 1444 "tpl_odhash.nw"
bool has_current() const
{
  return current_index > -1 and current_index < hash_table->table_size;
}
# 1481 "tpl_odhash.nw"
void next()
{
  if (current_index == hash_table->table_size)
    throwException<Overflow>("tpl_odhash.nw", 1484, "Overflow") ();

  locate_next_available_bucket();
}

void prev()
{
  if (current_index == -1)
    throwException<Underflow>("tpl_odhash.nw", 1492, "Underflow") ();

  locate_prev_available_bucket();
}
# 1498 "tpl_odhash.nw"
void reset_first()
{
  current_index = -1;

  try
    {
      locate_first_available_bucket();
    }
  catch (Overflow) { }
}

void reset_last()
{
  current_index = hash_table->table_size;

   try
    {
      locate_last_available_bucket();
    }
  catch (Underflow) { }
}
# 1362 "tpl_odhash.nw"
};
# 1347 "tpl_odhash.nw"
# 58 "tpl_odhash.nw"
};
# 449 "tpl_odhash.nw"
 template <class Key, class Record> inline
ODhashTable<Key, Record>::ODhashTable(HashFctType _first_hash_fct,
                                      HashFctType _second_hash_fct,
                                      int len)
  throw(std::exception, AlephExc, SizeFault, Nomem) :
    first_hash_fct (_first_hash_fct),
    second_hash_fct (_second_hash_fct),
    busy_entries_counter (0),
    deleted_entries_counter (0)
{
  table_size = next_prime(len);
  bucket_table = construct< Bucket >(*Aleph::objectAlloc) [table_size];
  empty_entries_counter = table_size;
}

    template <class Key, class Record> inline
ODhashTable<Key, Record>::~ODhashTable()
{
  destructArray(*Aleph::objectAlloc, bucket_table);
}
# 536 "tpl_odhash.nw"
 template <class Key, class Record> inline
Record* ODhashTable<Key, Record>::insert(const Key & key,
                                         const Record & record)
  throw(std::exception, AlephExc, Overflow)
{
  if (busy_entries_counter >= table_size - 1)
    throwException<Overflow>("tpl_odhash.nw", 542, "Overflow") (table_size);


  int bucket_index = (*first_hash_fct)(key) % table_size;

  if (bucket_table[bucket_index].state not_eq 1)
    return allocate_bucket(bucket_table[bucket_index],
                           1,
                           key, record);

  bucket_table[bucket_index].increase_collision_counter();


  bucket_index = (*second_hash_fct)(key) % table_size;

  if (bucket_table[bucket_index].state not_eq 1)
    return allocate_bucket(bucket_table[bucket_index],
                           2,
                           key, record);
# 592 "tpl_odhash.nw"

  do
    {
      bucket_table[bucket_index].increase_collision_counter();

      advance_index(bucket_index);
    } while (bucket_table[bucket_index].state == 1);
# 563 "tpl_odhash.nw"

  return allocate_bucket(bucket_table[bucket_index],
                         3,
                         key, record);
}
# 622 "tpl_odhash.nw"
 template <class Key, class Record> inline
Record* ODhashTable<Key, Record>::search(const Key& key)
{

  int bucket_index = (*first_hash_fct)(key) % table_size;

  if (bucket_table[bucket_index].state == 1 and
      bucket_table[bucket_index].key == key)
    return &bucket_table[bucket_index].record;

  if (bucket_table[bucket_index].state == 0)
    return __null;


  bucket_index = (*second_hash_fct)(key) % table_size;

  if (bucket_table[bucket_index].state == 1 and
      bucket_table[bucket_index].key == key)
    return &bucket_table[bucket_index].record;


  while (bucket_table[bucket_index].state not_eq 0)
    {
      advance_index(bucket_index);

      if (bucket_table[bucket_index].state == 1 and
          bucket_table[bucket_index].key == key)
        return &bucket_table[bucket_index].record;
    }

  return __null;
}
# 736 "tpl_odhash.nw"
 template <class Key, class Record> inline
void ODhashTable<Key, Record>::remove(Record * record)
  throw(std::exception, AlephExc, AddrFault, NotFound)
{
  Bucket * bucket = record_to_bucket(record);

  if (not is_valid_bucket(bucket))
    throwException<AddrFault>("tpl_odhash.nw", 743, "AddrFault") (bucket);

  if (bucket->state not_eq 1)
    throwException<NotFound>("tpl_odhash.nw", 746, "NotFound") ();

  switch (bucket->probe_type)
    {
    case 1:
      {
# 862 "tpl_odhash.nw"
 ;
# 754 "tpl_odhash.nw"
 break;
      }
    case 2:
      {
# 871 "tpl_odhash.nw"
 ;


        int index_first_probe = ((*first_hash_fct)(bucket->key) %
                                 table_size);

        decrease_bucket(&bucket_table[index_first_probe]);
# 760 "tpl_odhash.nw"
 break;
      }
    case 3:
      {
# 883 "tpl_odhash.nw"

        int index_first_probe = ((*first_hash_fct)(bucket->key) %
                                 table_size);

        decrease_bucket(&bucket_table[index_first_probe]);


        int index_second_probe = ((*second_hash_fct)(bucket->key) %
                                  table_size);

        decrease_bucket(&bucket_table[index_second_probe]);


        int current_bucket_index = index_second_probe;
        int index_bucket_to_remove = bucket_to_index(bucket);

        for (advance_index(current_bucket_index);
             current_bucket_index not_eq index_bucket_to_remove;
             advance_index(current_bucket_index))
          {
                                ;


            decrease_bucket(&bucket_table[current_bucket_index]);
          }
# 766 "tpl_odhash.nw"
 break;
      }
    default:
# 946 "tpl_odhash.nw"
Aleph::error("tpl_odhash.nw", 946, "Inconsistency in bucket state\n" "Please send a bug report to software@cemisid.ing.ula.ve\n" "describing the error's circumstances with along this report\n" "table size              = %u\n" "deleted entries         = %u\n" "busy entries            = %u\n" "empty entries           = %u\n" "counted deleted entries = %u\n" "counted busy entries    = %u\n" "counted empty entries   = %u\n" "bucket info:\n" "\tkey               = %ul\n" "\tstate             = %uhh\n" "\tcollision_counter = %uh\n" "\tprobe_type        = %uhh\n" "\tfirst hashing     = %ul\n" "\tsecond hashing    = %ul\n" , table_size, deleted_entries_counter, busy_entries_counter, empty_entries_counter, count_deleted_entries(), count_busy_entries(), count_empty_entries(), bucket->key, bucket->state, bucket->collision_counter, bucket->probe_type, (*first_hash_fct)(bucket->key), (*second_hash_fct)(bucket->key));
# 770 "tpl_odhash.nw"
 }
# 796 "tpl_odhash.nw"
deallocate_bucket(bucket);
# 773 "tpl_odhash.nw"
}
# 976 "tpl_odhash.nw"
 template <class Key, class Record> inline
int ODhashTable<Key, Record>::resize(int new_size)
  throw(std::exception, AlephExc, Nomem, Overflow, SizeFault)
{
  new_size = next_prime(new_size);

  if (new_size == table_size)
    return table_size;

  if (busy_entries_counter >= new_size - 1)
    throwException<Overflow>("tpl_odhash.nw", 986, "Overflow") (busy_entries_counter - new_size);

  Bucket * new_table = construct< Bucket >(*Aleph::objectAlloc) [new_size];

  Bucket * old_table = bucket_table;
  int old_size = table_size;

                                                         ;

  bucket_table = new_table;
  table_size = new_size;
  empty_entries_counter = table_size;
  deleted_entries_counter = 0;
  busy_entries_counter = 0;

  for (int i = 0; i < old_size; i++)
    if (old_table[i].state == 1)
      insert(old_table[i].key, old_table[i].record);

                                                          ;

  destructArray(*Aleph::objectAlloc, old_table);

  return table_size;
}
# 1038 "tpl_odhash.nw"
 template <class Key, class Record> inline
int ODhashTable<Key, Record>::resize_next()
  throw(std::exception, AlephExc, Nomem, Overflow, SizeFault)
{
  return resize(table_size + 1);
}

    template <class Key, class Record> inline
int ODhashTable<Key, Record>::resize_prev()
  throw(std::exception, AlephExc, Nomem, Overflow, SizeFault)
{
  return resize(table_size - 1);
}
# 1054 "tpl_odhash.nw"
 template <class Key, class Record> inline
void ODhashTable<Key, Record>::remove_all_and_delete()
{
  busy_entries_counter = 0;
  deleted_entries_counter = 0;
  empty_entries_counter = table_size;

  for (int i = 0; i < table_size; i++)
    {
      bucket_table[i].state = 0;
      bucket_table[i].probe_type = 0;
    }
}
# 1139 "tpl_odhash.nw"
 template <class Key, class Record> inline
const ODhashTable<Key, Record>::ODProxy ODhashTable<Key, Record>::operator []
(const Key& key) const
{
  return ODProxy(static_cast<ODhashTable<Key, Record>&>(*this), key);
}

    template <class Key, class Record> inline
ODhashTable<Key, Record>::ODProxy ODhashTable<Key, Record>::operator []
(const Key& key)
{
  return ODProxy(*this, key);
}
# 1268 "tpl_odhash.nw"
 template <class Key, class Record> inline
int ODhashTable<Key, Record>::get_table_size() const
{
  return table_size;
}

    template <class Key, class Record> inline
int ODhashTable<Key, Record>::get_num_items() const
{
  return busy_entries_counter;
}

    template <class Key, class Record> inline
int ODhashTable<Key, Record>::get_num_deleted_entries() const
{
  return deleted_entries_counter;
}

    template <class Key, class Record> inline
int ODhashTable<Key, Record>::get_num_empty_entries() const
{
  return empty_entries_counter;
}

    template <class Key, class Record> inline
int ODhashTable<Key, Record>::count_deleted_entries() const
{
  int counter = 0;

  for (int i = 0; i < table_size; i++)
    if (bucket_table[i].state == 2)
      counter++;

  return counter;
}

    template <class Key, class Record> inline
int ODhashTable<Key, Record>::count_busy_entries() const
{
  int counter = 0;

  for (int i = 0; i < table_size; i++)
    if (bucket_table[i].state == 1)
      counter++;

  return counter;
}

    template <class Key, class Record> inline
int ODhashTable<Key, Record>::count_empty_entries() const
{
  int counter = 0;

  for (int i = 0; i < table_size; i++)
    if (bucket_table[i].state == 0)
      counter++;

  return counter;
}
# 1331 "tpl_odhash.nw"
 template <class Key, class Record> inline
const Key & ODhashTable<Key, Record>::get_key(const Record* record)
{
  Bucket * bucket = record_to_bucket(const_cast<Record*>(record));

  if (not is_valid_bucket(bucket))
    throwException<AddrFault>("tpl_odhash.nw", 1337, "AddrFault") (bucket);

  return bucket->key;
}
# 379 "tpl_odhash.nw"
# 64 "tpl_odhash.nw"
# 51 "../../../../src/aleph/protected_odhash.H" 2
# 1 "../../../../src/aleph/useMutex.H" 1
# 52 "../../../../src/aleph/protected_odhash.H" 2

    template <class Key, class Record>
class Protected_OdHashTable
{
  struct Bucket
  {
    Record record;
    bool locked;

    Bucket() : locked(false) { }

    Bucket(const Record& _record) :
      record(_record),
      locked(false)
    { }
  };

  static Bucket * record_to_bucket(Record * record)
  {
    Bucket * ret_val = 0;
    size_t offset = reinterpret_cast<size_t>(&ret_val->record);

    return
      reinterpret_cast<Bucket*>(reinterpret_cast<size_t>(record) - offset);
    }

  ODhashTable<Key, Bucket> hash_table;

  pthread_mutex_t mutex;

public:

  typedef long (*HashFctType)(const Key&);

  bool is_locked(Record * record)
  {
    Bucket * bucket = record_to_bucket(record);

    return bucket->locked;
  }

  void lock(Record * record)
  {
    Bucket * bucket = record_to_bucket(record);
    bucket->locked = true;
  }

  void unlock(Record * record)
  {
    Bucket * bucket = record_to_bucket(record);
    bucket->locked = false;
  }

  size_t get_table_size()
  {
    UseMutex critical_section(mutex);

    return hash_table.get_table_size();
  }

  size_t get_num_items()
  {
    UseMutex critical_section(&mutex);

    return hash_table.get_num_items();
  }

  Protected_OdHashTable (HashFctType _first_hash_fct,
                         HashFctType _second_hash_fct,
                         size_t len) :
    hash_table (_first_hash_fct, _second_hash_fct, len)
  {
    init_mutex(mutex);
  }

  ~Protected_OdHashTable()
  {
    destroy_mutex(mutex);
  }

  Record* insert(const Key & key, const Record & record)
  {
    Bucket bucket(record);

    UseMutex critical_section(mutex);

    Bucket * ret_val = hash_table.insert(key, bucket);

    return &ret_val->record;
  }

  Record* search(const Key& key)
  {
    UseMutex critical_section(mutex);

    Bucket * bucket = hash_table.search(key);

    if (bucket == __null)
      return __null;

    if (bucket->locked)
      throwException<Lock>("../../../../src/aleph/protected_odhash.H", 153, "Lock") ();

    return &bucket->record;
  }

  void remove(Record * record)
  {
    Bucket * bucket = record_to_bucket(record);

    if (bucket->locked)
      throwException<Lock>("../../../../src/aleph/protected_odhash.H", 163, "Lock") ();

    UseMutex critical_section(mutex);

    hash_table.remove(bucket);
  }

  void remove_all_and_delete()
  {
    UseMutex critical_section(mutex);

    hash_table.remove_all_and_delete();
  }

  int get_table_size() const
  {
    UseMutex critical_section(mutex);
    return hash_table.get_table_size();
  }

  friend class Iterator
  {
    ODhashTable<Key, Bucket>::Iterator itor;
    UseMutex critical_section;

  public:

    Iterator(Protected_OdHashTable & table) :
      itor(table.hash_table), critical_section(table.mutex)
    {

    }

    bool has_current() const { return itor.has_current(); }

    Record * get_current() { return &(itor.get_current()->record); }

    void next() { itor.next(); }

    void prev() { itor.prev(); }
  };


};
# 57 "../../../../src/aleph/connectionTable.H" 2
# 1 "../../../../src/aleph/messages.H" 1
# 58 "../../../../src/aleph/connectionTable.H" 2
# 1 "../../../../src/aleph/localMessages.H" 1
# 59 "../../../../src/aleph/connectionTable.H" 2
# 1 "../../../../src/aleph/ipcPars.H" 1
# 60 "../../../../src/aleph/connectionTable.H" 2
# 1 "../../../../src/aleph/bindTable.H" 1
# 50 "../../../../src/aleph/bindTable.H"
# 1 "../../../../src/aleph/protected_lhash.H" 1
# 51 "../../../../src/aleph/protected_lhash.H"
# 1 "../../../../src/aleph/tpl_lhash.H" 1
# 16 "tpl_lhash.nw"
# 52 "../../../../src/aleph/protected_lhash.H" 2
# 1 "../../../../src/aleph/useMutex.H" 1
# 53 "../../../../src/aleph/protected_lhash.H" 2





    template <class Key>
class ProtectedLhashTable : private LhashTableVtl<Key>
{
private:

  pthread_mutex_t mutex;

public:




  class Bucket : public LhashTableVtl<Key>::Bucket
  {

    bool isBusy;

  public:


    Bucket() : isBusy(false) { }

    Bucket(const Key& key) : LhashTableVtl<Key>::Bucket(key), isBusy(false)
    {

    }


    void lock() { isBusy = true; }


    void unLock() { isBusy = false; }


    bool isLock() const { return isBusy; }
  };

  ProtectedLhashTable(HashFctType _hashFct,
                      const unsigned long _len) :
    LhashTableVtl<Key>::LhashTableVtl(_hashFct, _len)
  {
    init_mutex(mutex);
  }

  void removeAllAndDelete()
  {
    UseMutex critical_section(&mutex);

    LhashTableVtl<Key>::removeAllAndDelete();
  }

  ~ProtectedLhashTable()
  {
    destroy_mutex(mutex);
  }

  Bucket* insert(Bucket* bucket)
  {
    UseMutex critical_section(mutex);

    return static_cast<Bucket*>(LhashTableVtl<Key>::insert(bucket));
  }

  Bucket* search(const Key& key) throw (Lock)
  {
    UseMutex critical_section(mutex);

    Bucket *retVal = static_cast<Bucket*>(LhashTableVtl<Key>::search(key));

    if (retVal not_eq __null)
      {
        if (retVal->isLock())
          throwException<Lock>("../../../../src/aleph/protected_lhash.H", 130, "Lock")();

        retVal->lock();
      }

    return retVal;
  }

  Bucket* remove(Bucket* bucket)
  {
    UseMutex critical_section(mutex);

    if (bucket->isLock())
      throwException<Lock>("../../../../src/aleph/protected_lhash.H", 143, "Lock")();

    return static_cast<Bucket*>(LhashTableVtl<Key>::remove(bucket));
  }

  void reset()
  {
    UseMutex critical_section(mutex);
    removeAllAndDelete();
  }

  int resize(unsigned long _len)
  {
    UseMutex critical_section(mutex);

    return LhashTableVtl<Key>::resize(_len);
  }

  int get_table_size() const
  {
    UseMutex critical_section(mutex);

    return table_size;
  }

  int get_num_items() const
  {
    UseMutex critical_section(mutex);

    return LhashTableVtl<Key>::getNumItems();
  }

  int get_num_busy_slots() const
  {
    UseMutex critical_section(mutex);

    return busy_slots_counter;
  }

};
# 51 "../../../../src/aleph/bindTable.H" 2
# 1 "/usr/include/sys/un.h" 1 3
# 52 "../../../../src/aleph/bindTable.H" 2
# 1 "/usr/include/stdint.h" 1 3
# 53 "../../../../src/aleph/bindTable.H" 2
# 1 "/usr/include/errno.h" 1 3
# 54 "../../../../src/aleph/bindTable.H" 2
# 1 "/usr/include/pthread.h" 1 3
# 55 "../../../../src/aleph/bindTable.H" 2
# 1 "../../../../src/aleph/socket_wrappers.H" 1
# 56 "../../../../src/aleph/bindTable.H" 2
# 1 "../../../../src/aleph/ipcPars.H" 1
# 57 "../../../../src/aleph/bindTable.H" 2
# 1 "../../../../src/aleph/port.H" 1
# 58 "../../../../src/aleph/bindTable.H" 2
# 1 "../../../../src/aleph/localMessages.H" 1
# 59 "../../../../src/aleph/bindTable.H" 2

class Client_Descriptor;

class BindDataEntry : public ProtectedLhashTable<Port>::Bucket
{
private:

  Client_Descriptor * client_descriptor;

public:

  BindDataEntry(Port& _port, Client_Descriptor * _client_descriptor) :
    ProtectedLhashTable<Port>::Bucket (_port),
    client_descriptor(_client_descriptor)
  {

  }

  ~BindDataEntry() { }

  Client_Descriptor * get_client_descriptor() { return client_descriptor; }
};


unsigned long hashFctBind(const Port& key);



class BindTable : public ProtectedLhashTable<Port>
{
public:

  BindTable(const unsigned long _len = 1024) :
    ProtectedLhashTable<Port>::ProtectedLhashTable(hashFctBind, _len)
  {

  }

  ~BindTable()
  {
    ProtectedLhashTable<Port>::removeAllAndDelete();
  }

  BindDataEntry* search(const Port&);
};
# 61 "../../../../src/aleph/connectionTable.H" 2


using namespace std;


class RequestTable;

extern RequestTable * requestTablePtr;

class RequestDataEntry;





class Client_Descriptor
{
private:

  BindDataEntry * bind_entry;


  int downcall_sockfd;



  int upcall_connfd;
  struct sockaddr_un client_addr;




  short upcall_waiting;




  Dlink pending_upcalls_list;

  Dlink requests_list;

  Dlink reply_list;

  Dlink messages_list;

  Dlink events_list;



  pthread_mutex_t mutex;



  long long connection_number;


  char * path_name;





  bool client_panic;

  int status_panic_mode;

public:

  void print()
  {
    cout << "Client_Descriptor = " << this << endl
         << "    downcall_sockfd = " << downcall_sockfd << endl
         << "    upcall_connfd   = " << upcall_connfd << endl
         << "    client_addr     = " << client_addr.sun_path << endl
         << "    upcall_waiting  = " << upcall_waiting << endl;
  }

private:

  friend struct Upcall_Operation
  {
    enum Upcall_Code { Timeout_Expired, Client_Receive_Reply,
                       Server_Receive_Request, Bad_Epoch, Port_Unknown,
                       Server_Crash, Ipc_Shutdown };

    Client_Descriptor * client_descriptor;

    Upcall_Code upcall_code;

    Dlink dlink;

    virtual int perform() = 0;

    Upcall_Operation(Client_Descriptor * _client_descriptor,
                     Upcall_Code code) :
      client_descriptor(_client_descriptor),
      upcall_code(code)
    {
                             ;
    }

    virtual ~Upcall_Operation()
    {
                             ;
    }
  };

  static Upcall_Operation * dlink_to_type(Dlink * l) { Upcall_Operation * ptr_zero = 0; size_t offset_link = reinterpret_cast<size_t>(&(ptr_zero->dlink)); char * address_type = reinterpret_cast<char*>(l) - offset_link; return reinterpret_cast<Upcall_Operation *>(address_type); };

public:

  struct Server_Receive_Request_Upcall : public Upcall_Operation
  {
    MessageHeader * net_message;

    Server_Receive_Request_Upcall(Client_Descriptor * _client_descriptor,
                                  MessageHeader* request) :
      Upcall_Operation(_client_descriptor, Server_Receive_Request),
      net_message(request)
    {

    }

    ~Server_Receive_Request_Upcall()
    {


      (Aleph::objectAlloc->dealloc(net_message));
    }

    virtual int perform()
    {
      RequestMsg * request_msg = static_cast<RequestMsg*>(net_message);
      Server_Request_Upcall
        request_upcall(request_msg->getMsgId(), request_msg->getDataSize());

      return client_descriptor->perform_upcall(request_upcall,
                                               sizeof(request_upcall),
                                               request_msg->getData(),
                                               request_msg->getDataSize());
    }
  };

  struct Async_Message_Upcall : public Upcall_Operation
  {
    MessageHeader * net_message;

    Async_Message_Upcall(Client_Descriptor * _client_descriptor,
                         MessageHeader* async_message) :
      Upcall_Operation(_client_descriptor, Server_Receive_Request),
      net_message(async_message)
    {

    }

    ~Async_Message_Upcall()
    {


      (Aleph::objectAlloc->dealloc(net_message));
    }

    virtual int perform()
    {
      Single_Message * msg = static_cast<Single_Message*>(net_message);
      Async_Receive_Upcall upcall(msg->getMsgId(), msg->getDataSize());

      return client_descriptor->perform_upcall(upcall, sizeof(upcall),
                                               msg->getData(),
                                               msg->getDataSize());
    }
  };

  struct Client_Receive_Reply_Upcall : public Upcall_Operation
  {
    MessageHeader * net_message;
    RequestDataEntry * request_data_entry;

    Client_Receive_Reply_Upcall(Client_Descriptor * _client_descriptor,
                                MessageHeader * _net_message,
                                RequestDataEntry * _request_data_entry) :
      Upcall_Operation(_client_descriptor, Client_Receive_Reply),
      net_message(_net_message),
      request_data_entry(_request_data_entry)
    {

    }

    ~Client_Receive_Reply_Upcall();

    virtual int perform()
    {
      ReplyMsg * replyMsg = static_cast<ReplyMsg *>(net_message);

      Client_Reply_Upcall reply_upcall(replyMsg->get_request_msgid(),
                                       replyMsg->getDataSize());

      return client_descriptor->perform_upcall(reply_upcall,
                                               sizeof(reply_upcall),
                                               replyMsg->getData(),
                                               replyMsg->getDataSize());
    }
  };

  struct Bad_Epoch_Upcall : public Upcall_Operation
  {
    Bad_Epoch_Upcall(Client_Descriptor * _client_descriptor)
      : Upcall_Operation(_client_descriptor, Bad_Epoch)
    {

    }

    virtual int perform()
    {
      Client_Reply_Upcall reply_upcall(IpcD_Exit_Header::Bad_Epoch);

      return client_descriptor->perform_upcall(reply_upcall,
                                               sizeof(reply_upcall));
    }
  };

  struct Port_Unknown_Upcall : public Upcall_Operation
  {
    Port_Unknown_Upcall(Client_Descriptor * _client_descriptor) :
      Upcall_Operation(_client_descriptor, Port_Unknown)
    {

    }

    virtual int perform()
    {
      Client_Reply_Upcall reply_upcall(IpcD_Exit_Header::Not_Found);

      return client_descriptor->perform_upcall(reply_upcall,
                                               sizeof(reply_upcall));
    }
  };

  struct Timeout_Expired_Upcall : public Upcall_Operation
  {
    Timeout_Expired_Upcall(Client_Descriptor * _client_descriptor) :
      Upcall_Operation(_client_descriptor, Timeout_Expired)
    {

    }

    virtual int perform()
    {
      Client_Reply_Upcall reply_upcall(IpcD_Exit_Header::Timeout_Expired);

      return client_descriptor->perform_upcall(reply_upcall,
                                               sizeof(reply_upcall));
    }
  };

  struct Server_Crash_Upcall : public Upcall_Operation
  {
    Server_Crash_Upcall(Client_Descriptor * _client_descriptor) :
      Upcall_Operation(_client_descriptor, Server_Crash)
    {

    }

    virtual int perform()
    {
      Client_Reply_Upcall reply_upcall(IpcD_Exit_Header::Server_Crash);

      return client_descriptor->perform_upcall(reply_upcall,
                                               sizeof(reply_upcall));
    }
  };

public:

  Client_Descriptor(int _downcall_sockfd,
                    int _connection_number,
                    char * _path_name) :
    downcall_sockfd (_downcall_sockfd),
    upcall_waiting (0),
    connection_number (_connection_number),
    path_name (_path_name),
    client_panic(false)
  {
                                          ;
  }

  Client_Descriptor() { }

  void init();




  void shutdown();

  ~Client_Descriptor() { }


  int perform_upcall
      (IpcD_Exit_Header & exit_header,
       size_t header_size = sizeof(IpcD_Exit_Header),
       void * buffer = __null,
       size_t buffer_size = 0);

  void set_bind_entry(BindDataEntry * _bind_entry)
  {
    bind_entry = _bind_entry;
  }

  BindDataEntry * get_bind_entry() { return bind_entry; }

  int get_downcall_sockfd() const { return downcall_sockfd; }

  int get_upcall_connfd() const { return upcall_connfd; }

  bool is_upcall_waiting()
  {
    return upcall_waiting > 0;
  }

  void set_upcall_waiting()
  {
    upcall_waiting++;
  }

  pthread_mutex_t * get_mutex() { return &mutex; }

  void insert_pending_upcall(Upcall_Operation * upcall)
  {
                                   ;

    pending_upcalls_list.append(&upcall->dlink);
  }

  Upcall_Operation * remove_first_pending_upcall()
  {
    if (pending_upcalls_list.isEmpty())
      return __null;

    Dlink * link_to_upcall = pending_upcalls_list.removeNext();

    return dlink_to_type(link_to_upcall);
  }

  bool is_there_pending_upcalls() const
  {
    return !pending_upcalls_list.isEmpty();
  }

  int try_to_perform_first_upcall()
  {
    if (!is_upcall_waiting())
      return IpcD_Exit_Header::OK;


    Upcall_Operation * upcall = remove_first_pending_upcall();

    if (upcall == __null)
      return IpcD_Exit_Header::OK;

                                             ;

    int ret_val = upcall->perform();
    destruct(*Aleph::objectAlloc, upcall);

    return ret_val;
  }

  bool is_client_in_panic() const { return client_panic; }

  void set_panic_mode(int status)
  {
    client_panic = true;
    status_panic_mode = status;
  }

  char get_status_panic_mode() { return status_panic_mode; }

  Dlink * get_requests_list() { return &requests_list; }

  Dlink * get_reply_list() { return &reply_list; }

  Dlink * get_messages_list() { return &messages_list; }

  Dlink * get_events_list() { return &events_list; }
};

inline long first_hashing(const int & key)
{
  return key;
}

extern size_t client_table_size;


inline long second_hashing(const int & key)
{
  return 1 + (key % (client_table_size - 2));
}


class Client_Table : public Protected_OdHashTable<int, Client_Descriptor>
{

public:

  Client_Table() :
    Protected_OdHashTable<int, Client_Descriptor>::Protected_OdHashTable
      (&first_hashing, &second_hashing, 1024)
  {
    client_table_size = get_table_size();
  }

  ~Client_Table()
  {

  }

  Client_Descriptor * search(const int & downcall_sockfd)
  {
    Client_Descriptor* retVal;

  start:

    try
      {
        retVal = Protected_OdHashTable<int, Client_Descriptor>::search
          (downcall_sockfd);
      }
    catch (Lock)
      {
        goto start;
      }
    return retVal;
  }

  void reset();
};
# 56 "../../../../src/aleph/timeoutEvent.H" 2

enum eventCode {
  REPEATREQUEST,
  SENDLONGSERVICE,
  SENDAREYOUALIVE,
  CLIENTEXPIRED,
  REPLYEXPIRED,
  REPEAT_MESSAGE,
  MESSAGE_EXPIRED,
  ACK_EXPIRED,
  SEND_ACK
};

class TimeoutEvent : public TimeoutQueue::Event
{
protected:

  eventCode code;
  MsgId msgId;

  Client_Descriptor * client_descriptor;

  Dlink dlink;

public:

  TimeoutEvent(Client_Descriptor * _client_descriptor,
               eventCode _code,
               const MsgId & _msgid,
               const struct timespec & t);

  virtual ~TimeoutEvent() ;

  eventCode getEventCode()
  {
    return code;
  }

  MsgId& getMsgId()
  {
    return msgId;
  }

  Client_Descriptor * get_client_descriptor() { return client_descriptor; }

  Dlink * get_dlink() { return & dlink; }

  static TimeoutEvent * dlink_to_type(Dlink * l) { TimeoutEvent * ptr_zero = 0; size_t offset_link = reinterpret_cast<size_t>(&(ptr_zero->dlink)); char * address_type = reinterpret_cast<char*>(l) - offset_link; return reinterpret_cast<TimeoutEvent *>(address_type); };

  void insert_in_list(Dlink * list)
  {
                           ;
    list->append(&dlink);
  }

  void remove_from_list()
  {
                            ;
    dlink.del();
  }
};


class RepeatRequest : public TimeoutEvent
{
public:

  RepeatRequest(Client_Descriptor * _client_descriptor,
                MsgId _msgid, struct timespec t)
    : TimeoutEvent(_client_descriptor, REPEATREQUEST, _msgid, t)
  {

  }

  ~RepeatRequest()
  {

  }

  virtual void EventFct();
};

class SendLongService : public TimeoutEvent
{
public:

  SendLongService(Client_Descriptor * _client_descriptor,
                  MsgId _msgid, struct timespec t)
    : TimeoutEvent(_client_descriptor, SENDLONGSERVICE, _msgid, t)
  {

  }

  ~SendLongService()
  {

  }

  virtual void EventFct();
};


class SendAreYouAlive : public TimeoutEvent
{
public:

  SendAreYouAlive(Client_Descriptor * _client_descriptor,
                  MsgId _msgid, struct timespec t)
    : TimeoutEvent(_client_descriptor, SENDAREYOUALIVE, _msgid, t)
  {

  }

  ~SendAreYouAlive()
  {

  }

  virtual void EventFct();
};

class ClientExpired : public TimeoutEvent
{
public:

  ClientExpired(Client_Descriptor * _client_descriptor,
                MsgId _msgid, struct timespec t)
    : TimeoutEvent(_client_descriptor, CLIENTEXPIRED, _msgid, t)
  {

  }

  ~ClientExpired()
  {

  }

  virtual void EventFct();
};

class ReplyExpired : public TimeoutEvent
{
public:

  ReplyExpired(Client_Descriptor * _client_descriptor,
               MsgId _msgid, struct timespec t)
    : TimeoutEvent(_client_descriptor, REPLYEXPIRED, _msgid, t)
  {

  }

  ~ReplyExpired()
  {

  }

  virtual void EventFct();
};



class Repeat_Message_Event : public TimeoutEvent
{
  unsigned int sending_time;

public:

  Repeat_Message_Event(Client_Descriptor * _client_descriptor,
                       MsgId _msgid, struct timespec t,
                       unsigned int _sending_time) :
    TimeoutEvent(_client_descriptor, REPEAT_MESSAGE, _msgid, t),
    sending_time(_sending_time)
  {

  }

  ~Repeat_Message_Event()
  {

  }

  virtual void EventFct();
};
# 59 "../../../../src/aleph/receiveThread.H" 2
# 1 "../../../../src/aleph/ipcPars.H" 1
# 60 "../../../../src/aleph/receiveThread.H" 2

class ReceiveThread
{
private:

  pthread_t threadId;
  bool isShutdown;
  int sockfd;
  struct sockaddr_in serverAddr, clientAddr;

  static int instanceCounter;

  void *receiveMessage();

  static void* receiveMessageThread(void*);

  void processRequest(MessageHeader*, size_t, unsigned int);

  void processReply(MessageHeader*, size_t, unsigned int);

  void processLongService(MessageHeader*);

  void processAreYouAlive(MessageHeader*, unsigned int);

  void processBadEpoch(MessageHeader*, unsigned int);

  void processUnknown(MessageHeader*);

  void process_async_message(MessageHeader*, size_t, unsigned int);

  void process_ack_async_message(MessageHeader*);

  void process_lost_message(MessageHeader*);

  void process_lost_request(MessageHeader*);

public:

  ReceiveThread();

  ~ReceiveThread();

  void shutdown();

  pthread_t getThreadId() const { return threadId; }
};
# 56 "../../../../src/aleph/boot.H" 2
# 1 "../../../../src/aleph/bindTable.H" 1
# 57 "../../../../src/aleph/boot.H" 2
# 1 "../../../../src/aleph/requestTable.H" 1
# 49 "../../../../src/aleph/requestTable.H"
# 1 "../../../../src/aleph/protected_lhash.H" 1
# 50 "../../../../src/aleph/requestTable.H" 2
# 1 "../../../../src/aleph/tpl_autoPtr.H" 1
# 50 "../../../../src/aleph/tpl_autoPtr.H"
# 1 "../../../../src/aleph/ahNew.H" 1
# 51 "../../../../src/aleph/tpl_autoPtr.H" 2

    template <class T>
class Auto_Ptr
{
private:

  T * ptr;
  mutable bool committed;






public:

  Auto_Ptr(




           T* p = __null
           ) :
    ptr(p), committed(false)




  {

  }

  Auto_Ptr& operator = (T * p)
  {
    if (ptr not_eq __null)
      throwException<Duplicated>("../../../../src/aleph/tpl_autoPtr.H", 86, "Duplicated") ();

    ptr = p;
                         ;

    return *this;
  }

  ~Auto_Ptr()
  {
    if (ptr == __null)
      return;

    if (not committed)
      {





        destruct(*Aleph::objectAlloc, ptr);
      }
  }

  void commit() { committed = true; }

  operator T* ()
  {
    return ptr;
  }

  Auto_Ptr<T>& operator () () { return *this; }

  T* operator -> ()
  {
    if (ptr == __null)
      throwException<NullPointer>("../../../../src/aleph/tpl_autoPtr.H", 122, "NullPointer") ();

    return ptr;
  }

  T& operator * ()
  {
    if (ptr == __null)
      throwException<NullPointer>("../../../../src/aleph/tpl_autoPtr.H", 130, "NullPointer") ();

    return *ptr;
  }
};
# 51 "../../../../src/aleph/requestTable.H" 2
# 1 "../../../../src/aleph/timeoutEvent.H" 1
# 52 "../../../../src/aleph/requestTable.H" 2
# 1 "../../../../src/aleph/messages.H" 1
# 53 "../../../../src/aleph/requestTable.H" 2
# 1 "../../../../src/aleph/bindTable.H" 1
# 54 "../../../../src/aleph/requestTable.H" 2
# 1 "../../../../src/aleph/msgId.H" 1
# 55 "../../../../src/aleph/requestTable.H" 2

class Client_Descriptor;

extern TimeoutQueue * timeoutQueuePtr;


class RequestDataEntry : public ProtectedLhashTable<MsgId>::Bucket
{
private:


  MessageHeader* request;

  Client_Descriptor * client_descriptor;



  TimeoutQueue::Event* repeat_request_event;

  TimeoutQueue::Event* send_alive_event;



  TimeoutQueue::Event* clientTimeout;


  int n_time;




  Dlink dlink;

  bool reply_received;

public:

  RequestDataEntry(RequestMsg* _request,
                   Client_Descriptor * _client_descriptor,
                   TimeoutQueue::Event * _eventid,
                   TimeoutQueue::Event * _clienttimeout,
                   int _n_time);

  ~RequestDataEntry();

  RequestMsg* getRequestMsg()
  {
    return static_cast<RequestMsg*>(request);
  }

  Client_Descriptor * get_client_data_entry()
  {
    return client_descriptor;
  }


  TimeoutQueue::Event*& get_repeat_request_event()
  {
    return repeat_request_event;
  }


  TimeoutQueue::Event*& get_client_timeout_event()
  {
    return clientTimeout;
  }

  Client_Descriptor * get_client_descriptor() { return client_descriptor; }


  int getn_time() const { return n_time; }


  void setn_time(int _n_time)
  {
                       ;
    n_time = _n_time;
  }

  TimeoutQueue::Event*& get_send_alive_event()
  {
    return send_alive_event;
  }

  bool is_reply_received() const { return reply_received; }

  void set_reply_received() { reply_received = true; }

  static RequestDataEntry * dlink_to_type(Dlink * l) { RequestDataEntry * ptr_zero = 0; size_t offset_link = reinterpret_cast<size_t>(&(ptr_zero->dlink)); char * address_type = reinterpret_cast<char*>(l) - offset_link; return reinterpret_cast<RequestDataEntry *>(address_type); };

  void insert_in_list(Dlink * list)
  {
                           ;
    list->append(&dlink);
  }

  void remove_from_list()
  {
                            ;
    dlink.del();
  }

  void reschedule_repeat_request_event(const struct timespec & current_time,
                                       int request_resend_timeout)
  {
    if (repeat_request_event == __null)
      return;

    struct timespec request_resend_time =
      timespec_plus_msec(current_time, request_resend_timeout);



    timeoutQueuePtr->insertEvent(request_resend_time, repeat_request_event);
  }
};



unsigned long hashFctRequest(const MsgId& key);




class RequestTable : public ProtectedLhashTable<MsgId>
{
public:

  RequestTable(unsigned long _len)
    : ProtectedLhashTable<MsgId>::ProtectedLhashTable(hashFctRequest, _len)
  {

  }


  ~RequestTable()
  {
    ProtectedLhashTable<MsgId>::removeAllAndDelete();
  }


  RequestDataEntry* search(const MsgId&);

  bool resend_request(const MsgId & msgid);
};
# 58 "../../../../src/aleph/boot.H" 2
# 1 "../../../../src/aleph/replyTable.H" 1
# 50 "../../../../src/aleph/replyTable.H"
# 1 "../../../../src/aleph/protected_lhash.H" 1
# 51 "../../../../src/aleph/replyTable.H" 2
# 1 "../../../../src/aleph/timeoutQueue.H" 1
# 52 "../../../../src/aleph/replyTable.H" 2
# 1 "../../../../src/aleph/messages.H" 1
# 53 "../../../../src/aleph/replyTable.H" 2
# 1 "../../../../src/aleph/msgId.H" 1
# 54 "../../../../src/aleph/replyTable.H" 2
# 1 "../../../../src/aleph/connectionTable.H" 1
# 55 "../../../../src/aleph/replyTable.H" 2


extern TimeoutQueue * timeoutQueuePtr;

class ReplyDataEntry : public ProtectedLhashTable<MsgId>::Bucket
{
private:

  Client_Descriptor * client_descriptor;

  unsigned int source_ip;


  ReplyMsg* reply;



  TimeoutQueue::Event* long_service_event;

  TimeoutQueue::Event* delete_reply_event;

  int relayTime;

  Dlink dlink;

public:

  static ReplyDataEntry * dlink_to_type(Dlink * l) { ReplyDataEntry * ptr_zero = 0; size_t offset_link = reinterpret_cast<size_t>(&(ptr_zero->dlink)); char * address_type = reinterpret_cast<char*>(l) - offset_link; return reinterpret_cast<ReplyDataEntry *>(address_type); };

  void insert_in_list(Dlink * list)
  {
                           ;
    list->append(&dlink);
  }

  void remove_from_list()
  {
                               ;
    dlink.del();
  }

  ReplyDataEntry(Client_Descriptor * _client_descriptor,
                 const MsgId& msg_id,
                 unsigned int src_ip,
                 TimeoutQueue::Event* _long_service_event,
                 int _relaytime) :
    ProtectedLhashTable<MsgId>::Bucket(msg_id),
    client_descriptor(_client_descriptor),
    source_ip(src_ip),
    reply(__null),
    long_service_event(_long_service_event),
    delete_reply_event(__null),
    relayTime(_relaytime)
  {
    insert_in_list(client_descriptor->get_reply_list());
  }

  ~ReplyDataEntry()
  {
    if (reply not_eq __null)
      (Aleph::objectAlloc->dealloc(reply));

    remove_from_list();

    timeoutQueuePtr->cancel_delete_event(long_service_event);
    timeoutQueuePtr->cancel_delete_event(delete_reply_event);
  }

  ReplyMsg* getReplyMsg()
  {
    return reply;
  }

  void setReplyMsg(ReplyMsg* _reply)
  {
    reply = _reply;
  }

  TimeoutQueue::Event*& get_long_service_event()
  {
    return long_service_event;
  }

  TimeoutQueue::Event*& get_delete_reply_event()
  {
    return delete_reply_event;
  }

  Client_Descriptor * get_client_descriptor() { return client_descriptor; }

  bool wasReplySent() const
  {
    return reply not_eq __null;
  }

  void setRelayTime(int _relay)
  {
    relayTime = _relay;
  }

  int getRelayTime() const
  {
    return relayTime;
  }

  unsigned int get_source_ip() const { return source_ip; }
};


unsigned long hashFctReply(const MsgId& key);




class ReplyTable : public ProtectedLhashTable<MsgId>
{
public:

  ReplyTable(const unsigned long _len)
    : ProtectedLhashTable<MsgId>::ProtectedLhashTable(hashFctReply, _len)
  {

  }

  ~ReplyTable()
  {
    ProtectedLhashTable<MsgId>::removeAllAndDelete();
  }

  ReplyDataEntry* search(const MsgId&);

  bool resend_reply(const MsgId & msgid);
};
# 59 "../../../../src/aleph/boot.H" 2
# 1 "../../../../src/aleph/siteTable.H" 1
# 51 "../../../../src/aleph/siteTable.H"
# 1 "../../../../src/aleph/protected_lhash.H" 1
# 52 "../../../../src/aleph/siteTable.H" 2
# 1 "../../../../src/aleph/msgSequence.H" 1
# 50 "../../../../src/aleph/msgSequence.H"
# 1 "/usr/include/pthread.h" 1 3
# 51 "../../../../src/aleph/msgSequence.H" 2
# 1 "../../../../src/aleph/useMutex.H" 1
# 52 "../../../../src/aleph/msgSequence.H" 2
# 1 "../../../../src/aleph/tpl_dlist.H" 1
# 7 "tpl_dlist.nw"
# 53 "../../../../src/aleph/msgSequence.H" 2
# 1 "../../../../src/aleph/aleph.H" 1
# 54 "../../../../src/aleph/msgSequence.H" 2





class MsgSequence
{
private:


  unsigned long long receiving_sequence_number;


  Dlist<unsigned long long> lost_sequence_number_list;

  pthread_mutex_t mutex;







  bool checkSmallerSeq(unsigned long long);






  void checkGreaterSeq(unsigned long long);

  long long search_pending_message(unsigned long long);

public:

  static const long No_Lost_Message = -1;

  MsgSequence(unsigned long long _receiving_sequence_number = 0) :
    receiving_sequence_number(_receiving_sequence_number)
  {
    init_mutex(mutex);
  }

  ~MsgSequence()
  {
    {
      UseMutex critical_section(mutex);
      lost_sequence_number_list.removeAllAndDelete();
    }
    destroy_mutex(mutex);
  }






  bool updateSequence(unsigned long long);

  bool update_sequence_and_verify_lost_message(unsigned long long, long long&);

  unsigned long long get_receiving_sequence_number() const
  {
    return receiving_sequence_number;
  }
};
# 53 "../../../../src/aleph/siteTable.H" 2


class SiteDataEntry : public ProtectedLhashTable<unsigned int>::Bucket
{
private:



  MsgSequence messages_sequencer;


  unsigned int epoch;



  unsigned long long sending_sequence_number;

public:

  SiteDataEntry(unsigned int _addr,
                        unsigned int _epoch) :
    ProtectedLhashTable<unsigned int>::Bucket(_addr),
    epoch(_epoch),
    sending_sequence_number (0)
  {

  }

  ~SiteDataEntry()
  {

  }

  MsgSequence& get_message_sequencer() { return messages_sequencer; }

  unsigned long long get_sending_sequence_number() const
  {
    return sending_sequence_number;
  }

  void increase_sending_sequence_number()
  {
    sending_sequence_number++;
  }

  unsigned int getEpoch()
  {
    return epoch;
  }
};

unsigned long hashFctSite(const unsigned int& key);



class SiteTable : public ProtectedLhashTable<unsigned int>
{
public:
# 120 "../../../../src/aleph/siteTable.H"
  SiteTable(const unsigned long _len) :
    ProtectedLhashTable<unsigned int>::ProtectedLhashTable(hashFctSite, _len)
  {

  }

  ~SiteTable()
  {
    ProtectedLhashTable<unsigned int>::removeAllAndDelete();
  }

  SiteDataEntry* search(const unsigned int&);
};
# 60 "../../../../src/aleph/boot.H" 2
# 1 "../../../../src/aleph/connectionTable.H" 1
# 61 "../../../../src/aleph/boot.H" 2
# 1 "../../../../src/aleph/singleMessageTable.H" 1
# 49 "../../../../src/aleph/singleMessageTable.H"
# 1 "../../../../src/aleph/protected_lhash.H" 1
# 50 "../../../../src/aleph/singleMessageTable.H" 2
# 1 "../../../../src/aleph/timeoutQueue.H" 1
# 51 "../../../../src/aleph/singleMessageTable.H" 2
# 1 "../../../../src/aleph/messages.H" 1
# 52 "../../../../src/aleph/singleMessageTable.H" 2
# 1 "../../../../src/aleph/connectionTable.H" 1
# 53 "../../../../src/aleph/singleMessageTable.H" 2
# 1 "../../../../src/aleph/msgId.H" 1
# 54 "../../../../src/aleph/singleMessageTable.H" 2

class Single_Message_Data_Entry : public ProtectedLhashTable<MsgId>::Bucket
{
private:


  Single_Message* single_message;

  Client_Descriptor * client_descriptor;


  unsigned int sockfd;



  TimeoutQueue::Event* repeat_message_event;


  int n_time;




  Dlink dlink;

public:

  Single_Message_Data_Entry(Single_Message* _single_message,
                            Client_Descriptor * _client_descriptor,
                            TimeoutQueue::Event* _repeat_message_event,
                            int _n_time);

  ~Single_Message_Data_Entry();

  Single_Message* get_single_message() { return single_message; }

  Client_Descriptor * get_client_descriptor()
  {
    return client_descriptor;
  }


  unsigned int getSockCoord()
  {
    return sockfd;
  }


  TimeoutQueue::Event*& get_repeat_message_event()
  {
    return repeat_message_event;
  }


  int getn_time() const
  {
    return n_time;
  }


  void setn_time(int _n_time)
  {
                       ;
    n_time = _n_time;
  }

  static Single_Message_Data_Entry * dlink_to_type(Dlink * l) { Single_Message_Data_Entry * ptr_zero = 0; size_t offset_link = reinterpret_cast<size_t>(&(ptr_zero->dlink)); char * address_type = reinterpret_cast<char*>(l) - offset_link; return reinterpret_cast<Single_Message_Data_Entry *>(address_type); };

  void insert_in_list(Dlink * list)
  {
                           ;
    list->append(&dlink);
  }

  void remove_from_list()
  {
                               ;
    dlink.del();
  }
};


unsigned long hashFct_single_message(const MsgId& key);


class Single_Message_Table : public ProtectedLhashTable<MsgId>
{
public:

  Single_Message_Table(unsigned long _len) :
    ProtectedLhashTable<MsgId>::ProtectedLhashTable(hashFct_single_message,
                                                    _len)
  {

  }

  ~Single_Message_Table()
  {
    ProtectedLhashTable<MsgId>::removeAllAndDelete();
  }

  Single_Message_Data_Entry* search(const MsgId&);

  bool resend_single_message(const MsgId &msgid);

  void process_ack_single_message(const MsgId &msgid);
};
# 62 "../../../../src/aleph/boot.H" 2
# 1 "../../../../src/aleph/downCall.H" 1
# 51 "../../../../src/aleph/downCall.H"
# 1 "/usr/include/sys/un.h" 1 3
# 52 "../../../../src/aleph/downCall.H" 2
# 1 "/usr/include/errno.h" 1 3
# 53 "../../../../src/aleph/downCall.H" 2
# 1 "/usr/include/sys/socket.h" 1 3
# 54 "../../../../src/aleph/downCall.H" 2
# 1 "/usr/include/netinet/in.h" 1 3
# 55 "../../../../src/aleph/downCall.H" 2
# 1 "/usr/include/arpa/inet.h" 1 3
# 56 "../../../../src/aleph/downCall.H" 2
# 1 "/usr/include/pthread.h" 1 3
# 57 "../../../../src/aleph/downCall.H" 2
# 1 "/usr/include/sys/types.h" 1 3
# 58 "../../../../src/aleph/downCall.H" 2
# 1 "/usr/include/sys/time.h" 1 3
# 59 "../../../../src/aleph/downCall.H" 2
# 1 "../../../../src/aleph/aleph.H" 1
# 60 "../../../../src/aleph/downCall.H" 2
# 1 "../../../../src/aleph/socket_wrappers.H" 1
# 61 "../../../../src/aleph/downCall.H" 2
# 1 "../../../../src/aleph/useMutex.H" 1
# 62 "../../../../src/aleph/downCall.H" 2
# 1 "../../../../src/aleph/ipcPars.H" 1
# 63 "../../../../src/aleph/downCall.H" 2
# 1 "../../../../src/aleph/localMessages.H" 1
# 64 "../../../../src/aleph/downCall.H" 2
# 1 "../../../../src/aleph/connectionTable.H" 1
# 65 "../../../../src/aleph/downCall.H" 2
# 1 "../../../../src/aleph/requestTable.H" 1
# 66 "../../../../src/aleph/downCall.H" 2
# 1 "../../../../src/aleph/siteTable.H" 1
# 67 "../../../../src/aleph/downCall.H" 2
# 1 "../../../../src/aleph/messages.H" 1
# 68 "../../../../src/aleph/downCall.H" 2
# 79 "../../../../src/aleph/downCall.H"
class DownCall
{
private:

  pthread_t threadId;

  bool isShutdown;

  bool reset;

  static int instanceCounter;

  static uint64_t uid_counter;


  struct sockaddr_un servaddr;


  int listenfd;


  pthread_mutex_t mutex;



  void* receive_from_process();

  int respond_to_process(int client_sockfd,
                         IpcD_Exit_Header * exit_header);

  BindDataEntry * verify_binding(Client_Descriptor*,
                                 const Port&,
                                 IpcD_Exit_Header&);

  void process_client_send_request(Client_Descriptor*, IpcD_Entry_Header*);

  void process_client_receive_reply(Client_Descriptor*, IpcD_Entry_Header*);

  void process_server_receive_request(Client_Descriptor*, IpcD_Entry_Header*);

  void process_server_send_reply(Client_Descriptor*, IpcD_Entry_Header*);

  void process_async_send(Client_Descriptor*, IpcD_Entry_Header*);

  void process_async_receive(Client_Descriptor*, IpcD_Entry_Header*);

  void processBinding(int , IpcD_Entry_Header*);

  void processUnbinding(Client_Descriptor*, IpcD_Entry_Header*);

  void processUid(int , IpcD_Entry_Header*);

  void process_unconnected_services(int sockfd);

  void process_connected_services(Client_Descriptor*);

  void close_client(Client_Descriptor*&);

  static void* downCallThread(void*);

public:

  DownCall();

  ~DownCall();







  void shutdown();

  pthread_t getThreadId() const { return threadId; }
};
# 63 "../../../../src/aleph/boot.H" 2
# 1 "../../../../src/aleph/piggyback.H" 1
# 64 "../../../../src/aleph/boot.H" 2


extern bool with_epochs;

extern Log_Manager * log_manager;

extern FILE * log_file;

extern TimeoutQueue * timeoutQueuePtr;
extern SendQueue * sendQueuePtr;
extern ReceiveThread * receivePtr;
extern DownCall * downCallPtr;
extern BindTable * bindTablePtr;
extern RequestTable * requestTablePtr;
extern ReplyTable * replyTablePtr;
extern SiteTable * siteTablePtr;
extern Single_Message_Table * single_message_table_ptr;
extern Client_Table * client_table_ptr;
extern Piggyback_Table * piggyback_table_ptr;


extern unsigned int siteEpoch;
extern int siteAddress;

extern void bootstrapIpcSystem(int, char**);

extern void waitForTerminateIpcSystem();

extern void shutdownIpcSystem();


extern void sig_null(int);
# 68 "../../../../src/aleph/ipcClient.H" 2




extern void createUid(Uid*);

class IpcClient
{
public:

  enum ProtocolType { MAYBE, IPCCALL, STREAM };

  IpcClient(const Port& _target, ProtocolType protocol = IPCCALL)
  { }

  IpcClient() { }

  virtual ~IpcClient() { }

  virtual MsgId send_request(const RawMsg& msg) = 0;

  template <class T> MsgId send_request(const TypedMsg<T>& msg) = 0;

  virtual MsgId receive_reply(RawMsg& msg) = 0;

  template <class T> MsgId receive_reply(TypedMsg<T>& msg) = 0;
};


class IpcRemoteClient : public virtual IpcClient
{
protected:

  Port local_port;
  Port remotePort;



  int downcall_sockfd;



  int upcall_listenfd;



  char * file_name;



  pthread_mutex_t mutex;


  bool send_done;

  MsgId current_msg_id;

  MsgId sendRequest(const RawMsg& _msg);

  MsgId receiveReply(RawMsg& _msg);

private:

  IpcRemoteClient(const IpcRemoteClient&);

  IpcRemoteClient& operator = (const IpcRemoteClient&);

public:

  IpcRemoteClient(const Port& );

  MsgId send_request(const RawMsg& _msg)
  {
    return sendRequest(_msg);
  }

      template <class T>
  MsgId send_request(const TypedMsg<T>& _msg)
  {
    return sendRequest(_msg);
  }

  MsgId receive_reply(RawMsg& _msg)
  {
    return receiveReply(_msg);
  }

      template <class T>
  MsgId receive_reply(TypedMsg<T>& _msg)
  {
    return receiveReply(_msg);
  }

  ~IpcRemoteClient();

  const Port& get_local_port() const { return local_port; }
};

class IpcServer
{
protected:



  int downcall_sockfd;



  int upcall_listenfd;



  char *file_name;

  Port serverPort;
  pthread_mutex_t mutex;
  bool receive_done;

  IpcServer(const IpcServer &);
  IpcServer& operator = (const IpcServer &);

public:

  IpcServer();

  const MsgId receive_request(RawMsg& _msg);

  void send_reply(const RawMsg& _msg, const MsgId& msgId);

  Port& getServerPort()
  {
    return serverPort;
  }

  ~IpcServer();
};



class Ipc_MultiClient_Server
{
private:




  friend struct Rpc_Descriptor : public Dlink
  {
    friend class Ipc_MultiClient_Server;


    MsgId msg_id;

    Rpc_Descriptor() { }

    Rpc_Descriptor(const MsgId _msg_id) :
      msg_id(_msg_id)
    {

    }
  };



  int downcall_sockfd;



  int upcall_listenfd;



  char *file_name;


  Port local_port;

  pthread_mutex_t mutex;

  Rpc_Descriptor pending_request_list;

  Rpc_Descriptor pending_reply_list;

  size_t greatest_upcall_header_size;

  size_t smallest_upcall_header_size;

  static Rpc_Descriptor* search(Rpc_Descriptor & list, const MsgId & msg_id)
  {
    Rpc_Descriptor* current = static_cast<Rpc_Descriptor*>(list.getNext());

    while (current not_eq &list)
      {
        if (current->msg_id == msg_id)
          return current;
        current = static_cast<Rpc_Descriptor*>(current->getNext());
      }

    return __null;
  }

  MsgId receive_upcall(IpcD_Exit_Header * upcall_header, RawMsg & msg);

public:

  Ipc_MultiClient_Server();

  ~Ipc_MultiClient_Server();


  const MsgId rpc_send_request(const Port& ,
                               const RawMsg& );


  void rpc_send_reply(const RawMsg&, const MsgId&);


  const MsgId send_message(const Port& ,
                           const RawMsg& );
# 295 "../../../../src/aleph/ipcClient.H"
  const MsgId receive(RawMsg& );

  const Port & get_port() { return local_port; }
};
# 9 "../../../../src/Binder/include/remote_access_point.H" 2
# 1 "../../../../src/aleph/port.H" 1
# 10 "../../../../src/Binder/include/remote_access_point.H" 2
# 1 "../../../../src/Binder/include/base_message_header.H" 1
# 11 "../../../../src/Binder/include/remote_access_point.H" 2
# 1 "../../../../src/aleph/aleph.H" 1
# 12 "../../../../src/Binder/include/remote_access_point.H" 2
# 1 "../../../../src/Binder/include/locator_exceptions.H" 1
# 13 "../../../../src/Binder/include/remote_access_point.H" 2
# 1 "/usr/include/pthread.h" 1 3
# 14 "../../../../src/Binder/include/remote_access_point.H" 2

class Remote_Locator : public Deamon_Locator
{
  IpcRemoteClient * deamon_link;
  Port remote_server_port;

public:
  Remote_Locator(const Port & _server_port) :
    remote_server_port(_server_port)
  {

  }

  void set_deamon_link(IpcRemoteClient * _deamon_link)
  {
    deamon_link = _deamon_link;
  }

  IpcRemoteClient * get_deamon_link() const
  {
    return deamon_link;
  }

  Port get_remote_server_port() const
  {
    return remote_server_port;
  }

  const char * stringficate() const
  {
    return __null;
  }
};

class Remote_Access_Point : public Access_Point
{
  IpcRemoteClient * ptr_access_point;

public:
# 61 "../../../../src/Binder/include/remote_access_point.H"
  Remote_Access_Point(Remote_Locator & _deamon_locator,
                      unsigned int _no_of_services,
                      GenAlloc & _alloc = *objectAlloc);




  void shutdown();




  ~Remote_Access_Point();
};
# 9 "../../../../src/Binder/include/local_message_header.H" 2

enum Locator_Call_Entry_Code
{

  GET_SITE_ID,
  REGISTER_CONTAINER,
  UNREGISTER_CONTAINER,
  REGISTER_OBJECT,
  UNREGISTER_OBJECT,
  TARGET_REG_MIG_OBJECT,
  SOURCE_UNREG_MIG_OBJECT,
  TARGET_REG_MIG_CONTAINER,
  SOURCE_UNREG_MIG_CONTAINER,
  STRONG_LOCATE,
  WEAK_LOCATE,
  IMPLICIT_LOCATE,
  CLIENT_INVOKE_SEND,
  LOCATOR_SUPER_RECEIVE,
  SERVER_INVOKE_REPLY,
  TEST_OBJECT_LOCATION,
  PING_N_OBJECTS,

  LOCATOR_CALL_ENTRY_CODE_LAST
};

enum Reception_Type
{
  RECTYPE_INVOCATION_REQUEST,
  RECTYPE_INVOCATION_REPLY,

  RECTYPE_TYPE_LAST
};

enum Locator_Call_Exit_Code
{
  LOCEXIT_OK,
  LOCEXIT_CONTAINER_UNKNOWN,
  LOCEXIT_CONTAINER_STILL_WORKING,
  LOCEXIT_INTENDED_DUPLICATION,
  LOCEXIT_OBJECT_UNKNOWN,
  LOCEXIT_OBJECT_DEAD,
  LOCEXIT_OBJECT_NOT_FOUND,
  LOCEXIT_OBJECT_RECENT_BINDING,
  LOCEXIT_OBJECT_BUSY,

  LOCEXIT_INVALID
};

enum Cache_Update_Policy
{
  LOCCACHE_LRU,
  LOCCACHE_MRU,
  LOCCACHE_MIDDLE,

  LOCCACHE_INVALID
};


class Param_Cnt_Msg : public Msg_Entry_Header
{
  Container_Id container_id;

public:
  Param_Cnt_Msg (Locator_Call_Entry_Code service,
                 const Container_Id & cnt_id) :
    Msg_Entry_Header(service, sizeof(*this)),
    container_id(cnt_id)
    {

    }

  const Container_Id & get_container_id() const
    {
      return container_id;
    }
};



class Param_ObjCnt_Msg : public Msg_Entry_Header
{
  Object_Id object_id;
  Container_Id container_id;

public:
  Param_ObjCnt_Msg(Locator_Call_Entry_Code service,
                   const Object_Id & obj_id,
                   const Container_Id & cnt_id) :
    Msg_Entry_Header(service, sizeof(*this)),
    object_id(obj_id),
    container_id(cnt_id)
    {

    }

  const Object_Id & get_object_id()
    {
      return object_id;
    }

  const Container_Id & get_container_id()
    {
      return container_id;
    }
};


class Param_Obj_Msg : public Msg_Entry_Header
{
  Object_Id object_id;

public:
  Param_Obj_Msg(Locator_Call_Entry_Code service,
                const Object_Id & obj_id) :
    Msg_Entry_Header(service, sizeof(*this)),
    object_id(obj_id)
    {

    }

  const Object_Id & get_object_id() const
    {
      return object_id;
    }
};


class Param_Bind_Msg : public Msg_Entry_Header
{
  Binding binding;

public:
  Param_Bind_Msg(Locator_Call_Entry_Code service,
                 Binding _binding) :
    Msg_Entry_Header(service, sizeof(*this)),
    binding(_binding)
    {

    }

  const Binding & get_binding() const
    {
      return binding;
    }
};



class Param_ObjBind_Msg : public Msg_Entry_Header
{
  Object_Id object_id;
  Binding binding;

public:
  Param_ObjBind_Msg(Locator_Call_Entry_Code service,
                    const Object_Id & obj_id,
                    const Binding & _binding) :
    Msg_Entry_Header(service, sizeof(*this)),
    object_id(obj_id),
    binding(_binding)
    {

    }

  const Object_Id & get_object_id() const
    {
      return object_id;
    }

  const Binding & get_binding() const
    {
      return binding;
    }

};



class Param_ObjSite_Msg : public Msg_Entry_Header
{
  Object_Id object_id;
  Site_Id site_id;

public:
  Param_ObjSite_Msg(Locator_Call_Entry_Code service,
                    const Object_Id & _object_id,
                    const Site_Id & _site_id) :
    Msg_Entry_Header(service, sizeof(*this)),
    object_id(_object_id),
    site_id(_site_id)
    {

    }

  const Object_Id & get_object_id() const
    {
      return object_id;
    }

  const Site_Id & get_site_id() const
    {
      return site_id;
    }
};


class Site_Id_CallMsg : public Msg_Entry_Header
{
public:
  Site_Id_CallMsg() :
    Msg_Entry_Header(GET_SITE_ID, sizeof(*this))
  {

  }
};


class Site_Id_RetMsg : public Msg_Exit_Header
{
  Site_Id site_id;

public:
  Site_Id_RetMsg(Locator_Call_Exit_Code status, Site_Id _site_id) :
    Msg_Exit_Header(status),
    site_id(_site_id)
    {

    }

  Site_Id_RetMsg() :
    Msg_Exit_Header(LOCEXIT_INVALID),
    site_id(INVALID_SITE_ID)
    {

    }

  const Site_Id & get_site_id() const
    {
      return site_id;
    }
};

class Register_Cnt_CallMsg : public Msg_Entry_Header
{
  pid_t pid;

public:
  Register_Cnt_CallMsg() :
    Msg_Entry_Header(REGISTER_CONTAINER, sizeof(*this)),
    pid(getpid())
    {

    }

  pid_t get_pid() const
  {
    return pid;
  }
};

class Register_Cnt_RetMsg : public Msg_Exit_Header
{
  Container_Id container_id;

public:
  Register_Cnt_RetMsg(Locator_Call_Exit_Code status,
                      const Container_Id & cnt_id) :
    Msg_Exit_Header(status),
    container_id(cnt_id)
    {

    }

  Register_Cnt_RetMsg() :
    Msg_Exit_Header(LOCEXIT_INVALID)
    {

    }

  const Container_Id & get_container_id() const
    {
      return container_id;
    }
};

class Unregister_Cnt_CallMsg : public Param_Cnt_Msg
{
public:
  Unregister_Cnt_CallMsg(const Container_Id & _container_id) :
    Param_Cnt_Msg(UNREGISTER_CONTAINER, _container_id)
    {

    }
};

class Unregister_Cnt_RetMsg : public Msg_Exit_Header
{
public:
  Unregister_Cnt_RetMsg(Locator_Call_Exit_Code status) :
    Msg_Exit_Header(status)
    {

    }

  Unregister_Cnt_RetMsg() :
    Msg_Exit_Header(LOCEXIT_INVALID)
    {

    }
};


class Param_Loc_Exit_Msg : public Msg_Exit_Header
{
  Locator locator;

public:

  Param_Loc_Exit_Msg(Locator_Call_Exit_Code status,
                     const Locator & _locator) :
    Msg_Exit_Header(status),
    locator(_locator)
    {

    }

  Param_Loc_Exit_Msg() :
    Msg_Exit_Header(LOCEXIT_INVALID)
    {

    }

  void set_locator(const Locator & _loc)
    {
      locator = _loc;
    }

  const Locator & get_locator() const
    {
      return locator;
    }
};

class Param_Obj_Exit_Msg : public Msg_Exit_Header
{
  Object_Id object_id;

public:

  Param_Obj_Exit_Msg(Locator_Call_Exit_Code status,
                     const Object_Id & _object_id) :
    Msg_Exit_Header(status),
    object_id(_object_id)
    {

    }

  Param_Obj_Exit_Msg() :
    Msg_Exit_Header(LOCEXIT_INVALID)
    {

    }

  void set_object_id(const Object_Id & _object_id)
    {
      object_id = _object_id;
    }

  const Object_Id & get_object_id() const
    {
      return object_id;
    }
};

class Weak_Locate_CallMsg : public Param_Obj_Msg
{
public:
  Weak_Locate_CallMsg(const Object_Id & _object_id) :
    Param_Obj_Msg(WEAK_LOCATE, _object_id)
    {

    }
};


class Weak_Locate_RetMsg : public Param_Loc_Exit_Msg
{

public:

  Weak_Locate_RetMsg(Locator_Call_Exit_Code status,
                     const Locator & _locator) :
    Param_Loc_Exit_Msg(status, _locator)
    {

    }

  Weak_Locate_RetMsg() :
    Param_Loc_Exit_Msg()
    {

    }
};


class Strong_Locate_CallMsg : public Param_Obj_Msg
{
public:
  Strong_Locate_CallMsg(const Object_Id & _object_id) :
    Param_Obj_Msg(STRONG_LOCATE, _object_id)
    {

    }
};


class Strong_Locate_RetMsg : public Param_Loc_Exit_Msg
{

public:

  Strong_Locate_RetMsg(Locator_Call_Exit_Code status,
                       const Locator & _locator) :
    Param_Loc_Exit_Msg(status, _locator)
    {

    }

  Strong_Locate_RetMsg() :
    Param_Loc_Exit_Msg()
    {

    }
};

class Implicit_Locate_CallMsg : public Param_Bind_Msg
{
public:
  Implicit_Locate_CallMsg(const Binding & _binding) :
    Param_Bind_Msg(IMPLICIT_LOCATE, _binding)
    {

    }
};

class Implicit_Locate_RetMsg : public Msg_Exit_Header
{
public:
  Implicit_Locate_RetMsg(Locator_Call_Exit_Code _status) :
    Msg_Exit_Header(_status)
    {

    }

  Implicit_Locate_RetMsg() :
    Msg_Exit_Header(LOCEXIT_INVALID)
    {

    }
};

class Register_Obj_CallMsg : public Param_Cnt_Msg
{
public:
  Register_Obj_CallMsg(const Container_Id & _container_id) :
    Param_Cnt_Msg(REGISTER_OBJECT,
                  _container_id)
  {

  }
};


class Register_Obj_RetMsg : public Param_Obj_Exit_Msg
{
public:
  Register_Obj_RetMsg(Locator_Call_Exit_Code _status,
                      const Object_Id & _object_id) :
    Param_Obj_Exit_Msg(_status, _object_id)
    {

    }

  Register_Obj_RetMsg() :
    Param_Obj_Exit_Msg()
    {

    }
};


class Unregister_Obj_CallMsg : public Param_Obj_Msg
{
public:
  Unregister_Obj_CallMsg(const Object_Id & _object_id) :
    Param_Obj_Msg(UNREGISTER_OBJECT, _object_id)
    {

    }
};

class Unregister_Obj_RetMsg : public Msg_Exit_Header
{
public:
  Unregister_Obj_RetMsg(Locator_Call_Exit_Code _status) :
    Msg_Exit_Header(_status)
    {

    }

  Unregister_Obj_RetMsg() :
    Msg_Exit_Header(LOCEXIT_INVALID)
    {

    }
};


class Clt_Invoke_Send_CallMsg : public Msg_Entry_Header
{
  Binding binding;
  size_t request_size;

public:
  char request[0];

  Clt_Invoke_Send_CallMsg(const Binding & _binding,
                          const size_t _request_size) :
    Msg_Entry_Header(CLIENT_INVOKE_SEND, sizeof(*this)),
    binding(_binding),
    request_size(_request_size)
  {
    set_invocation_size(_request_size);
  }

  size_t get_request_size() const
  {
    return request_size;
  }

  Binding & get_binding()
  {
    return binding;
  }
};

class Clt_Invoke_Send_RetMsg : public Msg_Exit_Header
{



  Message_Id message_id;

  Locator locator;

public:
  Clt_Invoke_Send_RetMsg(const Message_Id & _message_id,
                         const Locator & _locator,
                         Locator_Call_Exit_Code _status) :
    Msg_Exit_Header(_status),
    message_id(_message_id),
    locator(_locator)
  {

  }

  Clt_Invoke_Send_RetMsg() :
    Msg_Exit_Header(LOCEXIT_INVALID)
  {

  }

  const Message_Id & get_message_id() const
  {
    return message_id;
  }

  const Locator & get_locator() const
  {
    return locator;
  }
};


class Locator_Super_Receive_CallMsg : public Msg_Entry_Header
{
  size_t message_size;
  Binding binding;
  Container_Id receiving_container_id;

public:
  Locator_Super_Receive_CallMsg(const size_t & _message_size,
                                const Binding & _binding,
                                const Container_Id & _rec_cnt_id) :
    Msg_Entry_Header(LOCATOR_SUPER_RECEIVE, sizeof(*this)),
    message_size(_message_size),
    binding(_binding),
    receiving_container_id(_rec_cnt_id)
  {

  }

  size_t get_message_size() const
  {
    return message_size;
  }

  const Binding & get_binding() const
  {
    return binding;
  }

  const Container_Id & get_receiving_container_id() const
  {
    return receiving_container_id;
  }
};

class Locator_Super_Receive_RetMsg : public Msg_Exit_Header
{
  Message_Id message_id;





  Binding binding;

  size_t message_size;

  Reception_Type reception_type;

public:

  Locator_Super_Receive_RetMsg(const Message_Id & _message_id,
                               const Binding & _binding,
                               size_t _msg_size,
                               Reception_Type _reception_type,
                               Locator_Call_Exit_Code _status) :
    Msg_Exit_Header(_status),
    message_id(_message_id),
    binding(_binding),
    message_size(_msg_size),
    reception_type(_reception_type)
  {

  }

  Locator_Super_Receive_RetMsg() :
    Msg_Exit_Header(LOCEXIT_INVALID)
  {

  }

  const Message_Id & get_message_id() const
  {
    return message_id;
  }

  size_t get_message_size() const
  {
    return message_size;
  }

  const Binding & get_binding() const
  {
    return binding;
  }

  Reception_Type get_reception_type() const
  {
    return reception_type;
  }
};

class Srv_Invoke_Reply_CallMsg : public Msg_Entry_Header
{
  Message_Id message_id;
  Binding binding;
  Container_Id replying_container_id;
  size_t reply_size;

  char reply_buffer[0];

public:


  Srv_Invoke_Reply_CallMsg(const Message_Id & _message_id,
                           const Binding & _binding,
                           const Container_Id & _rep_cnt_id,
                           const size_t _reply_size) :
    Msg_Entry_Header(SERVER_INVOKE_REPLY, sizeof(*this)),
    message_id(_message_id),
    binding(_binding),
    replying_container_id(_rep_cnt_id),
    reply_size(_reply_size)
    {
      set_invocation_size(reply_size);
    }

  const Message_Id & get_message_id() const
  {
    return message_id;
  }

  const Binding & get_binding() const
    {
      return binding;
    }

  size_t get_reply_size() const
    {
      return reply_size;
    }

  const Container_Id & get_replying_container_id() const
  {
    return replying_container_id;
  }

  char * get_reply_buffer()
  {
    return &reply_buffer[0];
  }
};

class Srv_Invoke_Reply_RetMsg : public Msg_Exit_Header
{
public:
  Srv_Invoke_Reply_RetMsg(Locator_Call_Exit_Code _status) :
    Msg_Exit_Header(_status)
    {

    }

  Srv_Invoke_Reply_RetMsg() :
    Msg_Exit_Header(LOCEXIT_INVALID)
    {

    }
};


class Src_Unreg_Mig_Obj_CallMsg : public Msg_Entry_Header
{
  Object_Id object_id;
  Site_Id tgt_site_id;

public:
  Src_Unreg_Mig_Obj_CallMsg(const Object_Id & _obj_id,
                            const Site_Id & _site_id) :
    Msg_Entry_Header(SOURCE_UNREG_MIG_OBJECT, sizeof(*this)),
    object_id(_obj_id),
    tgt_site_id(_site_id)
  {

  }

  const Object_Id & get_object_id() const
  {
    return object_id;
  }

  const Site_Id & get_tgt_site_id() const
  {
    return tgt_site_id;
  }
};

class Src_Unreg_Mig_Obj_RetMsg : public Msg_Exit_Header
{
public:
  Src_Unreg_Mig_Obj_RetMsg(Locator_Call_Exit_Code _status) :
    Msg_Exit_Header(_status)
  {

  }

  Src_Unreg_Mig_Obj_RetMsg() :
    Msg_Exit_Header(LOCEXIT_INVALID)
  {

  }
};

class Tgt_Reg_Mig_Obj_CallMsg : public Msg_Entry_Header
{
  Object_Id object_id;
  Container_Id container_id;
  Logical_Timestamp logical_timestamp;

public:
  Tgt_Reg_Mig_Obj_CallMsg(const Object_Id & _obj_id,
                          const Container_Id & _cnt_id,
                          const Logical_Timestamp _timestamp) :
    Msg_Entry_Header(TARGET_REG_MIG_OBJECT, sizeof(*this)),
    object_id(_obj_id),
    container_id(_cnt_id),
    logical_timestamp(_timestamp)
  {

  }

  const Object_Id & get_object_id() const
  {
    return object_id;
  }

  const Container_Id & get_container_id() const
  {
    return container_id;
  }

  Logical_Timestamp get_logical_timestamp() const
  {
    return logical_timestamp;
  }
};

class Tgt_Reg_Mig_Obj_RetMsg : public Msg_Exit_Header
{
public:
  Tgt_Reg_Mig_Obj_RetMsg(Locator_Call_Exit_Code _status) :
    Msg_Exit_Header(_status)
  {

  }

  Tgt_Reg_Mig_Obj_RetMsg() :
    Msg_Exit_Header(LOCEXIT_INVALID)
  {

  }
};


class Test_Object_Location_CallMsg : public Msg_Entry_Header
{
  Locator locator;

public:
  Test_Object_Location_CallMsg(const Locator & _locator) :
    Msg_Entry_Header(TEST_OBJECT_LOCATION, sizeof(*this)),
    locator(_locator)
  {

  }

  Locator & get_locator()
  {
    return locator;
  }
};

class Test_Object_Location_RetMsg : public Msg_Exit_Header
{
  Locator new_locator;

public:
  Test_Object_Location_RetMsg(const Locator & _new_locator,
                              Locator_Call_Exit_Code _status) :
    Msg_Exit_Header(_status),
    new_locator(_new_locator)
  {

  }

  Test_Object_Location_RetMsg() :
    Msg_Exit_Header(LOCEXIT_INVALID)
  {

  }

  const Locator & get_new_locator() const
  {
    return new_locator;
  }
};


class Ping_N_Objects_CallMsg : public Msg_Entry_Header
{
  unsigned int number_of_objects;
  Cache_Update_Policy policy;

public:
  Ping_N_Objects_CallMsg(unsigned int _number_of_objects,
                         Cache_Update_Policy _policy) :
    Msg_Entry_Header(PING_N_OBJECTS, sizeof(*this)),
    number_of_objects(_number_of_objects),
    policy(_policy)
  {

  }

  unsigned int get_number_of_objects() const
  {
    return number_of_objects;
  }

  Cache_Update_Policy get_policy() const
  {
    return policy;
  }
};

class Ping_N_Objects_RetMsg : public Msg_Exit_Header
{
public:
  Ping_N_Objects_RetMsg(Locator_Call_Exit_Code _status) :
    Msg_Exit_Header(_status)
  {

  }

  Ping_N_Objects_RetMsg() :
    Msg_Exit_Header(LOCEXIT_INVALID)
  {

  }
};
# 10 "../../../../src/Binder/include/locator_calls.H" 2

extern Local_Access_Point * clt_services_access;

extern Local_Access_Point * srv_services_access;

extern void bootstrap_services();

extern Locator_Call_Exit_Code get_site_id(Site_Id & site_id)
throw(std::exception);


extern void register_cnt(Container_Id & cnt_id)
  throw (std::exception, Duplicated, Panic);

extern void unregister_cnt(const Container_Id & cnt_id)
  throw(std::exception, NotFound, RefusedService, Panic);

extern void register_obj(Object_Id & obj_id, const Container_Id & cnt_id)
  throw(std::exception, Duplicated, NotFound, Panic);

extern void unregister_obj(const Object_Id & obj_id)
  throw(std::exception, NotFound, RefusedService, Panic);


extern void src_unreg_mig_obj(const Object_Id & obj_id,
                              const Site_Id & tgt_site_id)
  throw(std::exception, NotFound, ObjectBusy, Panic);

extern void tgt_reg_mig_obj(const Object_Id & obj_id,
                            const Container_Id & cnt_id,
                            const Logical_Timestamp timestamp)
  throw(std::exception, NotFound, Duplicated, Panic);

extern void src_unreg_mig_cnt(const Container_Id & cnt_id,
                              const Site_Id & tgt_site_id)
  throw(std::exception, NotFound, RefusedService, Panic);

extern void tgt_reg_mig_cnt(const Container_Id & cnt_id)
  throw(std::exception, Duplicated, Panic);



extern Message_Id clt_invoke_send(Binding & binding,
                                  const void * request,
                                  size_t request_size)
  throw (std::exception, ObjectDead, Panic);

extern Message_Id multi_receive(Binding & binding,
                                const Container_Id & receiving_container_id,
                                void * data,
                                size_t & data_size,
                                Reception_Type & reception_type)
  throw (std::exception, NotFound, ObjectDead, RecentBinding, Panic);

extern void srv_invoke_reply(const Message_Id & msg_id,
                             const Binding & binding,
                             const Container_Id & replying_cnt_id,
                             const void * reply,
                             size_t reply_size)
  throw (std::exception, Panic);


extern Locator strong_locate(const Object_Id & obj_id)
  throw(std::exception, ObjectDead, Panic);

extern Locator weak_locate(const Object_Id & obj_id)
  throw(std::exception, NotFound, ObjectDead, Panic);



extern void implicit_locate(const Binding & old_binding)
  throw (std::exception, Panic);



void test_location(Locator & locator)
  throw (std::exception, NotFound, ObjectDead, Panic);

void ping(unsigned int number_of_entries, const Cache_Update_Policy policy)
  throw (std::exception, NotFound, Panic);
# 3 "client2.C" 2
# 1 "../../../../src/aleph/port.H" 1
# 4 "client2.C" 2

int get_rand(int min_number, int max_number)
{
                                        ;

  if (max_number == min_number)
    return max_number;

  max_number = max_number - min_number + 1;

  int ret_val = min_number;

  float value = static_cast<float>(max_number)*rand()/(2147483647 +1.0);

  ret_val += static_cast<int>(value);

                                                                           ;

  return ret_val;
}


int main(int argc, char ** argv)
{
  if (argc == 1)
    {
      cout << "usage: client2 <Site_Id> <Obj_Id> <#invocations> <invocation_size> <pause_time (usec)>" << endl;
      exit(0);
    }

  bootstrap_services();

  Object_Id rem_obj(argv[2]);

  int n_times = atoi(argv[3]);


  Site_Id rem_site(argv[1]), this_site(INVALID_SITE_ID);
  get_site_id(this_site);

  Locator remote_object_loc(rem_obj, rem_site);

  Container_Id this_container;

  register_cnt(this_container);

  char strtmp[Uid::stringSize];

                                                                            ;


  Binding binding(remote_object_loc, this_container, this_site);



  Message_Id msg_id;

  Reception_Type reception_type;

  size_t invocation_size = atoi(argv[4]);

  size_t reply_size;

  char * invocation = new char [invocation_size];

  char * reply = new char [invocation_size];

  fill(invocation, &invocation[invocation_size - 2], 'X');
  invocation[invocation_size - 1] = '\0';
# 82 "client2.C"
  for (int i=0; i < n_times; i++)
    {



      try
        {
          msg_id = clt_invoke_send(binding, invocation, invocation_size);
        }
      catch(NotFound)
        {
          Aleph::error("client2.C", 93, "*** ERROR: Debe buscar un nuevo binding para el objeto");
        }

      msg_id = multi_receive(binding, this_container, reply, reply_size,
                             reception_type);

                                           ;

                                                   ;

      if (argc == 6)
        usleep(atol(argv[5]));
    }

  unregister_cnt(this_container);

  delete [] invocation;

  return 0;
}

/**
 * Enhanced Seccomp MIPS64 Specific Code
 *
 * Copyright (c) 2014 Red Hat <pmoore@redhat.com>
 * Author: Paul Moore <paul@paul-moore.com>
 *
 */

/*
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of version 2.1 of the GNU Lesser General Public License as
 * published by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License
 * for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, see <http://www.gnu.org/licenses>.
 */

#include <string.h>

#include <seccomp.h>

#include "arch.h"
#include "arch-mips64.h"

/* 64 ABI */
#define __SCMP_NR_BASE	5000

/* NOTE: based on Linux 4.14 */
const struct arch_syscall_def mips64_syscall_table[] = { \
	{ "_llseek", __PNR__llseek },
	{ "_newselect", (__SCMP_NR_BASE + 22) },
	{ "_sysctl", (__SCMP_NR_BASE + 152) },
	{ "accept", (__SCMP_NR_BASE + 42) },
	{ "accept4", (__SCMP_NR_BASE + 293) },
	{ "access", (__SCMP_NR_BASE + 20) },
	{ "acct", (__SCMP_NR_BASE + 158) },
	{ "add_key", (__SCMP_NR_BASE + 239) },
	{ "adjtimex", (__SCMP_NR_BASE + 154) },
	{ "afs_syscall", (__SCMP_NR_BASE + 176) },
	{ "alarm", (__SCMP_NR_BASE + 37) },
	{ "arm_fadvise64_64", __PNR_arm_fadvise64_64 },
	{ "arm_sync_file_range", __PNR_arm_sync_file_range },
	{ "arch_prctl", __PNR_arch_prctl },
	{ "bdflush", __PNR_bdflush },
	{ "bind", (__SCMP_NR_BASE + 48) },
	{ "bpf", (__SCMP_NR_BASE + 315) },
	{ "break", __PNR_break },
	{ "breakpoint", __PNR_breakpoint },
	{ "brk", (__SCMP_NR_BASE + 12) },
	{ "cachectl", (__SCMP_NR_BASE + 198) },
	{ "cacheflush", (__SCMP_NR_BASE + 197) },
	{ "capget", (__SCMP_NR_BASE + 123) },
	{ "capset", (__SCMP_NR_BASE + 124) },
	{ "chdir", (__SCMP_NR_BASE + 78) },
	{ "chmod", (__SCMP_NR_BASE + 88) },
	{ "chown", (__SCMP_NR_BASE + 90) },
	{ "chown32", __PNR_chown32 },
	{ "chroot", (__SCMP_NR_BASE + 156) },
	{ "clock_adjtime", (__SCMP_NR_BASE + 300) },
	{ "clock_getres", (__SCMP_NR_BASE + 223) },
	{ "clock_gettime", (__SCMP_NR_BASE + 222) },
	{ "clock_nanosleep", (__SCMP_NR_BASE + 224) },
	{ "clock_settime", (__SCMP_NR_BASE + 221) },
	{ "clone", (__SCMP_NR_BASE + 55) },
	{ "close", (__SCMP_NR_BASE + 3) },
	{ "connect", (__SCMP_NR_BASE + 41) },
	{ "copy_file_range", (__SCMP_NR_BASE + 320) },
	{ "creat", (__SCMP_NR_BASE + 83) },
	{ "create_module", (__SCMP_NR_BASE + 167) },
	{ "delete_module", (__SCMP_NR_BASE + 169) },
	{ "dup", (__SCMP_NR_BASE + 31) },
	{ "dup2", (__SCMP_NR_BASE + 32) },
	{ "dup3", (__SCMP_NR_BASE + 286) },
	{ "epoll_create", (__SCMP_NR_BASE + 207) },
	{ "epoll_create1", (__SCMP_NR_BASE + 285) },
	{ "epoll_ctl", (__SCMP_NR_BASE + 208) },
	{ "epoll_ctl_old", __PNR_epoll_ctl_old },
	{ "epoll_pwait", (__SCMP_NR_BASE + 272) },
	{ "epoll_wait", (__SCMP_NR_BASE + 209) },
	{ "epoll_wait_old", __PNR_epoll_wait_old },
	{ "eventfd", (__SCMP_NR_BASE + 278) },
	{ "eventfd2", (__SCMP_NR_BASE + 284) },
	{ "execve", (__SCMP_NR_BASE + 57) },
	{ "execveat", (__SCMP_NR_BASE + 316) },
	{ "exit", (__SCMP_NR_BASE + 58) },
	{ "exit_group", (__SCMP_NR_BASE + 205) },
	{ "faccessat", (__SCMP_NR_BASE + 259) },
	{ "fadvise64", (__SCMP_NR_BASE + 215) },
	{ "fadvise64_64", __PNR_fadvise64_64 },
	{ "fallocate", (__SCMP_NR_BASE + 279) },
	{ "fanotify_init", (__SCMP_NR_BASE + 295) },
	{ "fanotify_mark", (__SCMP_NR_BASE + 296) },
	{ "fchdir", (__SCMP_NR_BASE + 79) },
	{ "fchmod", (__SCMP_NR_BASE + 89) },
	{ "fchmodat", (__SCMP_NR_BASE + 258) },
	{ "fchown", (__SCMP_NR_BASE + 91) },
	{ "fchown32", __PNR_fchown32 },
	{ "fchownat", (__SCMP_NR_BASE + 250) },
	{ "fcntl", (__SCMP_NR_BASE + 70) },
	{ "fcntl64", __PNR_fcntl64 },
	{ "fdatasync", (__SCMP_NR_BASE + 73) },
	{ "fgetxattr", (__SCMP_NR_BASE + 185) },
	{ "finit_module", (__SCMP_NR_BASE + 307) },
	{ "flistxattr", (__SCMP_NR_BASE + 188) },
	{ "flock", (__SCMP_NR_BASE + 71) },
	{ "fork", (__SCMP_NR_BASE + 56) },
	{ "fremovexattr", (__SCMP_NR_BASE + 191) },
	{ "fsetxattr", (__SCMP_NR_BASE + 182) },
	{ "fstat", (__SCMP_NR_BASE + 5) },
	{ "fstat64", __PNR_fstat64 },
	{ "fstatat64", __PNR_fstat64 },
	{ "fstatfs", (__SCMP_NR_BASE + 135) },
	{ "fstatfs64", __PNR_fstatfs64 },
	{ "fsync", (__SCMP_NR_BASE + 72) },
	{ "ftime", __PNR_ftime },
	{ "ftruncate", (__SCMP_NR_BASE + 75) },
	{ "ftruncate64", __PNR_ftruncate64 },
	{ "futex", (__SCMP_NR_BASE + 194) },
	{ "futimesat", (__SCMP_NR_BASE + 251) },
	{ "get_kernel_syms", (__SCMP_NR_BASE + 170) },
	{ "get_mempolicy", (__SCMP_NR_BASE + 228) },
	{ "get_robust_list", (__SCMP_NR_BASE + 269) },
	{ "get_thread_area", __PNR_get_thread_area },
	{ "getcpu", (__SCMP_NR_BASE + 271) },
	{ "getcwd", (__SCMP_NR_BASE + 77) },
	{ "getdents", (__SCMP_NR_BASE + 76) },
	{ "getdents64", (__SCMP_NR_BASE + 308) },
	{ "getegid", (__SCMP_NR_BASE + 106) },
	{ "getegid32", __PNR_getegid32 },
	{ "geteuid", (__SCMP_NR_BASE + 105) },
	{ "geteuid32", __PNR_geteuid32 },
	{ "getgid", (__SCMP_NR_BASE + 102) },
	{ "getgid32", __PNR_getgid32 },
	{ "getgroups", (__SCMP_NR_BASE + 113) },
	{ "getgroups32", __PNR_getgroups32 },
	{ "getitimer", (__SCMP_NR_BASE + 35) },
	{ "getpeername", (__SCMP_NR_BASE + 51) },
	{ "getpgid", (__SCMP_NR_BASE + 119) },
	{ "getpgrp", (__SCMP_NR_BASE + 109) },
	{ "getpid", (__SCMP_NR_BASE + 38) },
	{ "getpmsg", (__SCMP_NR_BASE + 174) },
	{ "getppid", (__SCMP_NR_BASE + 108) },
	{ "getpriority", (__SCMP_NR_BASE + 137) },
	{ "getrandom", (__SCMP_NR_BASE + 313) },
	{ "getresgid", (__SCMP_NR_BASE + 118) },
	{ "getresgid32", __PNR_getresgid32 },
	{ "getresuid", (__SCMP_NR_BASE + 116) },
	{ "getresuid32", __PNR_getresuid32 },
	{ "getrlimit", (__SCMP_NR_BASE + 95) },
	{ "getrusage", (__SCMP_NR_BASE + 96) },
	{ "getsid", (__SCMP_NR_BASE + 122) },
	{ "getsockname", (__SCMP_NR_BASE + 50) },
	{ "getsockopt", (__SCMP_NR_BASE + 54) },
	{ "gettid", (__SCMP_NR_BASE + 178) },
	{ "gettimeofday", (__SCMP_NR_BASE + 94) },
	{ "getuid", (__SCMP_NR_BASE + 100) },
	{ "getuid32", __PNR_getuid32 },
	{ "getxattr", (__SCMP_NR_BASE + 183) },
	{ "gtty", __PNR_gtty },
	{ "idle", __PNR_idle },
	{ "init_module", (__SCMP_NR_BASE + 168) },
	{ "inotify_add_watch", (__SCMP_NR_BASE + 244) },
	{ "inotify_init", (__SCMP_NR_BASE + 243) },
	{ "inotify_init1", (__SCMP_NR_BASE + 288) },
	{ "inotify_rm_watch", (__SCMP_NR_BASE + 245) },
	{ "io_cancel", (__SCMP_NR_BASE + 204) },
	{ "io_destroy", (__SCMP_NR_BASE + 201) },
	{ "io_getevents", (__SCMP_NR_BASE + 202) },
	{ "io_setup", (__SCMP_NR_BASE + 200) },
	{ "io_submit", (__SCMP_NR_BASE + 203) },
	{ "ioctl", (__SCMP_NR_BASE + 15) },
	{ "ioperm", __PNR_ioperm },
	{ "iopl", __PNR_iopl },
	{ "ioprio_get", (__SCMP_NR_BASE + 274) },
	{ "ioprio_set", (__SCMP_NR_BASE + 273) },
	{ "ipc", __PNR_ipc },
	{ "kcmp", (__SCMP_NR_BASE + 306) },
	{ "kexec_file_load", __PNR_kexec_file_load },
	{ "kexec_load", (__SCMP_NR_BASE + 270) },
	{ "keyctl", (__SCMP_NR_BASE + 241) },
	{ "kill", (__SCMP_NR_BASE + 60) },
	{ "lchown", (__SCMP_NR_BASE + 92) },
	{ "lchown32", __PNR_lchown32 },
	{ "lgetxattr", (__SCMP_NR_BASE + 184) },
	{ "link", (__SCMP_NR_BASE + 84) },
	{ "linkat", (__SCMP_NR_BASE + 255) },
	{ "listen", (__SCMP_NR_BASE + 49) },
	{ "listxattr", (__SCMP_NR_BASE + 186) },
	{ "llistxattr", (__SCMP_NR_BASE + 187) },
	{ "lock", __PNR_lock },
	{ "lookup_dcookie", (__SCMP_NR_BASE + 206) },
	{ "lremovexattr", (__SCMP_NR_BASE + 190) },
	{ "lseek", (__SCMP_NR_BASE + 8) },
	{ "lsetxattr", (__SCMP_NR_BASE + 181) },
	{ "lstat", (__SCMP_NR_BASE + 6) },
	{ "lstat64", __PNR_lstat64 },
	{ "madvise", (__SCMP_NR_BASE + 27) },
	{ "mbind", (__SCMP_NR_BASE + 227) },
	{ "membarrier",  (__SCMP_NR_BASE + 318) },
	{ "memfd_create", (__SCMP_NR_BASE + 314) },
	{ "migrate_pages", (__SCMP_NR_BASE + 246) },
	{ "mincore", (__SCMP_NR_BASE + 26) },
	{ "mkdir", (__SCMP_NR_BASE + 81) },
	{ "mkdirat", (__SCMP_NR_BASE + 248) },
	{ "mknod", (__SCMP_NR_BASE + 131) },
	{ "mknodat", (__SCMP_NR_BASE + 249) },
	{ "mlock", (__SCMP_NR_BASE + 146) },
	{ "mlock2", (__SCMP_NR_BASE + 319) },
	{ "mlockall", (__SCMP_NR_BASE + 148) },
	{ "mmap", (__SCMP_NR_BASE + 9) },
	{ "mmap2", __PNR_mmap2 },
	{ "modify_ldt", __PNR_modify_ldt },
	{ "mount", (__SCMP_NR_BASE + 160) },
	{ "move_pages", (__SCMP_NR_BASE + 267) },
	{ "mprotect", (__SCMP_NR_BASE + 10) },
	{ "mpx", __PNR_mpx },
	{ "mq_getsetattr", (__SCMP_NR_BASE + 235) },
	{ "mq_notify", (__SCMP_NR_BASE + 234) },
	{ "mq_open", (__SCMP_NR_BASE + 230) },
	{ "mq_timedreceive", (__SCMP_NR_BASE + 233) },
	{ "mq_timedsend", (__SCMP_NR_BASE + 232) },
	{ "mq_unlink", (__SCMP_NR_BASE + 231) },
	{ "mremap", (__SCMP_NR_BASE + 24) },
	{ "msgctl", (__SCMP_NR_BASE + 69) },
	{ "msgget", (__SCMP_NR_BASE + 66) },
	{ "msgrcv", (__SCMP_NR_BASE + 68) },
	{ "msgsnd", (__SCMP_NR_BASE + 67) },
	{ "msync", (__SCMP_NR_BASE + 25) },
	{ "multiplexer", __PNR_multiplexer },
	{ "munlock", (__SCMP_NR_BASE + 147) },
	{ "munlockall", (__SCMP_NR_BASE + 149) },
	{ "munmap", (__SCMP_NR_BASE + 11) },
	{ "name_to_handle_at", (__SCMP_NR_BASE + 298) },
	{ "nanosleep", (__SCMP_NR_BASE + 34) },
	{ "newfstatat", (__SCMP_NR_BASE + 252) },
	{ "nfsservctl", (__SCMP_NR_BASE + 173) },
	{ "nice", __PNR_nice },
	{ "oldfstat", __PNR_oldfstat },
	{ "oldlstat", __PNR_oldlstat },
	{ "oldolduname", __PNR_oldolduname },
	{ "oldstat", __PNR_oldstat },
	{ "olduname", __PNR_olduname },
	{ "oldwait4", __PNR_oldwait4 },
	{ "open", (__SCMP_NR_BASE + 2) },
	{ "open_by_handle_at", (__SCMP_NR_BASE + 299) },
	{ "openat", (__SCMP_NR_BASE + 247) },
	{ "pause", (__SCMP_NR_BASE + 33) },
	{ "pciconfig_iobase", __PNR_pciconfig_iobase },
	{ "pciconfig_read", __PNR_pciconfig_read },
	{ "pciconfig_write", __PNR_pciconfig_write },
	{ "perf_event_open", (__SCMP_NR_BASE + 292) },
	{ "personality", (__SCMP_NR_BASE + 132) },
	{ "pipe", (__SCMP_NR_BASE + 21) },
	{ "pipe2", (__SCMP_NR_BASE + 287) },
	{ "pivot_root", (__SCMP_NR_BASE + 151) },
	{ "pkey_alloc", (__SCMP_NR_BASE + 324) },
	{ "pkey_free", (__SCMP_NR_BASE + 325) },
	{ "pkey_mprotect", (__SCMP_NR_BASE + 323) },
	{ "poll", (__SCMP_NR_BASE + 7) },
	{ "ppoll", (__SCMP_NR_BASE + 261) },
	{ "prctl", (__SCMP_NR_BASE + 153) },
	{ "pread64", (__SCMP_NR_BASE + 16) },
	{ "preadv", (__SCMP_NR_BASE + 289) },
	{ "preadv2", (__SCMP_NR_BASE + 321) },
	{ "prlimit64", (__SCMP_NR_BASE + 297) },
	{ "process_vm_readv", (__SCMP_NR_BASE + 304) },
	{ "process_vm_writev", (__SCMP_NR_BASE + 305) },
	{ "prof", __PNR_prof },
	{ "profil", __PNR_profil },
	{ "pselect6", (__SCMP_NR_BASE + 260) },
	{ "ptrace", (__SCMP_NR_BASE + 99) },
	{ "putpmsg", (__SCMP_NR_BASE + 175) },
	{ "pwrite64", (__SCMP_NR_BASE + 17) },
	{ "pwritev", (__SCMP_NR_BASE + 290) },
	{ "pwritev2", (__SCMP_NR_BASE + 322) },
	{ "query_module", (__SCMP_NR_BASE + 171) },
	{ "quotactl", (__SCMP_NR_BASE + 172) },
	{ "read", (__SCMP_NR_BASE + 0) },
	{ "readahead", (__SCMP_NR_BASE + 179) },
	{ "readdir", __PNR_readdir },
	{ "readlink", (__SCMP_NR_BASE + 87) },
	{ "readlinkat", (__SCMP_NR_BASE + 257) },
	{ "readv", (__SCMP_NR_BASE + 18) },
	{ "reboot", (__SCMP_NR_BASE + 164) },
	{ "recv", __PNR_recv },
	{ "recvfrom", (__SCMP_NR_BASE + 44) },
	{ "recvmmsg", (__SCMP_NR_BASE + 294) },
	{ "recvmsg", (__SCMP_NR_BASE + 46) },
	{ "remap_file_pages", (__SCMP_NR_BASE + 210) },
	{ "removexattr", (__SCMP_NR_BASE + 189) },
	{ "rename", (__SCMP_NR_BASE + 80) },
	{ "renameat", (__SCMP_NR_BASE + 254) },
	{ "renameat2", (__SCMP_NR_BASE + 311) },
	{ "request_key", (__SCMP_NR_BASE + 240) },
	{ "restart_syscall", (__SCMP_NR_BASE + 213) },
	{ "rmdir", (__SCMP_NR_BASE + 82) },
	{ "rt_sigaction", (__SCMP_NR_BASE + 13) },
	{ "rt_sigpending", (__SCMP_NR_BASE + 125) },
	{ "rt_sigprocmask", (__SCMP_NR_BASE + 14) },
	{ "rt_sigqueueinfo", (__SCMP_NR_BASE + 127) },
	{ "rt_sigreturn", (__SCMP_NR_BASE + 211) },
	{ "rt_sigsuspend", (__SCMP_NR_BASE + 128) },
	{ "rt_sigtimedwait", (__SCMP_NR_BASE + 126) },
	{ "rt_tgsigqueueinfo", (__SCMP_NR_BASE + 291) },
	{ "rtas", __PNR_rtas },
	{ "s390_pci_mmio_read", __PNR_s390_pci_mmio_read },
	{ "s390_pci_mmio_write", __PNR_s390_pci_mmio_write },
	{ "s390_runtime_instr", __PNR_s390_runtime_instr },
	{ "sched_get_priority_max", (__SCMP_NR_BASE + 143) },
	{ "sched_get_priority_min", (__SCMP_NR_BASE + 144) },
	{ "sched_getaffinity", (__SCMP_NR_BASE + 196) },
	{ "sched_getattr", (__SCMP_NR_BASE + 310) },
	{ "sched_getparam", (__SCMP_NR_BASE + 140) },
	{ "sched_getscheduler", (__SCMP_NR_BASE + 142) },
	{ "sched_rr_get_interval", (__SCMP_NR_BASE + 145) },
	{ "sched_setaffinity", (__SCMP_NR_BASE + 195) },
	{ "sched_setattr", (__SCMP_NR_BASE + 309) },
	{ "sched_setparam", (__SCMP_NR_BASE + 139) },
	{ "sched_setscheduler", (__SCMP_NR_BASE + 141) },
	{ "sched_yield", (__SCMP_NR_BASE + 23) },
	{ "seccomp", (__SCMP_NR_BASE + 312) },
	{ "security", __PNR_security },
	{ "select", __PNR_select },
	{ "semctl", (__SCMP_NR_BASE + 64) },
	{ "semget", (__SCMP_NR_BASE + 62) },
	{ "semop", (__SCMP_NR_BASE + 63) },
	{ "semtimedop", (__SCMP_NR_BASE + 214) },
	{ "send", __PNR_send },
	{ "sendfile", (__SCMP_NR_BASE + 39) },
	{ "sendfile64", __PNR_sendfile64 },
	{ "sendmmsg", (__SCMP_NR_BASE + 302) },
	{ "sendmsg", (__SCMP_NR_BASE + 45) },
	{ "sendto", (__SCMP_NR_BASE + 43) },
	{ "set_mempolicy", (__SCMP_NR_BASE + 229) },
	{ "set_robust_list", (__SCMP_NR_BASE + 268) },
	{ "set_thread_area", (__SCMP_NR_BASE + 242) },
	{ "set_tid_address", (__SCMP_NR_BASE + 212) },
	{ "set_tls", __PNR_set_tls },
	{ "setdomainname", (__SCMP_NR_BASE + 166) },
	{ "setfsgid", (__SCMP_NR_BASE + 121) },
	{ "setfsgid32", __PNR_setfsgid32 },
	{ "setfsuid", (__SCMP_NR_BASE + 120) },
	{ "setfsuid32", __PNR_setfsuid32 },
	{ "setgid", (__SCMP_NR_BASE + 104) },
	{ "setgid32", __PNR_setgid32 },
	{ "setgroups", (__SCMP_NR_BASE + 114) },
	{ "setgroups32", __PNR_setgroups32 },
	{ "sethostname", (__SCMP_NR_BASE + 165) },
	{ "setitimer", (__SCMP_NR_BASE + 36) },
	{ "setns", (__SCMP_NR_BASE + 303) },
	{ "setpgid", (__SCMP_NR_BASE + 107) },
	{ "setpriority", (__SCMP_NR_BASE + 138) },
	{ "setregid", (__SCMP_NR_BASE + 112) },
	{ "setregid32", __PNR_setregid32 },
	{ "setresgid", (__SCMP_NR_BASE + 117) },
	{ "setresgid32", __PNR_setresgid32 },
	{ "setresuid", (__SCMP_NR_BASE + 115) },
	{ "setresuid32", __PNR_setresuid32 },
	{ "setreuid", (__SCMP_NR_BASE + 111) },
	{ "setreuid32", __PNR_setreuid32 },
	{ "setrlimit", (__SCMP_NR_BASE + 155) },
	{ "setsid", (__SCMP_NR_BASE + 110) },
	{ "setsockopt", (__SCMP_NR_BASE + 53) },
	{ "settimeofday", (__SCMP_NR_BASE + 159) },
	{ "setuid", (__SCMP_NR_BASE + 103) },
	{ "setuid32", __PNR_setuid32 },
	{ "setxattr", (__SCMP_NR_BASE + 180) },
	{ "sgetmask", __PNR_sgetmask },
	{ "shmat", (__SCMP_NR_BASE + 29) },
	{ "shmctl", (__SCMP_NR_BASE + 30) },
	{ "shmdt", (__SCMP_NR_BASE + 65) },
	{ "shmget", (__SCMP_NR_BASE + 28) },
	{ "shutdown", (__SCMP_NR_BASE + 47) },
	{ "sigaction", __PNR_sigaction },
	{ "sigaltstack", (__SCMP_NR_BASE + 129) },
	{ "signal", __PNR_signal },
	{ "signalfd", (__SCMP_NR_BASE + 276) },
	{ "signalfd4", (__SCMP_NR_BASE + 283) },
	{ "sigpending", __PNR_sigpending },
	{ "sigprocmask", __PNR_sigprocmask },
	{ "sigreturn", __PNR_sigreturn },
	{ "sigsuspend", __PNR_sigsuspend },
	{ "socket", (__SCMP_NR_BASE + 40) },
	{ "socketcall", __PNR_socketcall },
	{ "socketpair", (__SCMP_NR_BASE + 52) },
	{ "splice", (__SCMP_NR_BASE + 263) },
	{ "spu_create", __PNR_spu_create },
	{ "spu_run", __PNR_spu_run },
	{ "ssetmask", __PNR_ssetmask },
	{ "stat", (__SCMP_NR_BASE + 4) },
	{ "stat64", __PNR_stat64 },
	{ "statfs", (__SCMP_NR_BASE + 134) },
	{ "statfs64", __PNR_statfs64 },
	{ "statx", (__SCMP_NR_BASE + 326) },
	{ "stime", __PNR_stime },
	{ "stty", __PNR_stty },
	{ "subpage_prot", __PNR_subpage_prot },
	{ "swapcontext", __PNR_swapcontext },
	{ "swapoff", (__SCMP_NR_BASE + 163) },
	{ "swapon", (__SCMP_NR_BASE + 162) },
	{ "switch_endian", __PNR_switch_endian },
	{ "symlink", (__SCMP_NR_BASE + 86) },
	{ "symlinkat", (__SCMP_NR_BASE + 256) },
	{ "sync", (__SCMP_NR_BASE + 157) },
	{ "sync_file_range", (__SCMP_NR_BASE + 264) },
	{ "sync_file_range2", __PNR_sync_file_range2 },
	{ "syncfs", (__SCMP_NR_BASE + 301) },
	{ "syscall", __PNR_syscall },
	{ "sys_debug_setcontext", __PNR_sys_debug_setcontext },
	{ "sysfs", (__SCMP_NR_BASE + 136) },
	{ "sysinfo", (__SCMP_NR_BASE + 97) },
	{ "syslog", (__SCMP_NR_BASE + 101) },
	{ "sysmips", (__SCMP_NR_BASE + 199) },
	{ "tee", (__SCMP_NR_BASE + 265) },
	{ "tgkill", (__SCMP_NR_BASE + 225) },
	{ "time", __PNR_time },
	{ "timer_create", (__SCMP_NR_BASE + 216) },
	{ "timer_delete", (__SCMP_NR_BASE + 220) },
	{ "timer_getoverrun", (__SCMP_NR_BASE + 219) },
	{ "timer_gettime", (__SCMP_NR_BASE + 218) },
	{ "timer_settime", (__SCMP_NR_BASE + 217) },
	{ "timerfd", (__SCMP_NR_BASE + 277) },
	{ "timerfd_create", (__SCMP_NR_BASE + 280) },
	{ "timerfd_gettime", (__SCMP_NR_BASE + 281) },
	{ "timerfd_settime", (__SCMP_NR_BASE + 282) },
	{ "times", (__SCMP_NR_BASE + 98) },
	{ "tkill", (__SCMP_NR_BASE + 192) },
	{ "truncate", (__SCMP_NR_BASE + 74) },
	{ "truncate64", __PNR_truncate64 },
	{ "tuxcall", __PNR_tuxcall },
	{ "ugetrlimit", __PNR_ugetrlimit },
	{ "ulimit", __PNR_ulimit },
	{ "umask", (__SCMP_NR_BASE + 93) },
	{ "umount", __PNR_umount },
	{ "umount2", (__SCMP_NR_BASE + 161) },
	{ "uname", (__SCMP_NR_BASE + 61) },
	{ "unlink", (__SCMP_NR_BASE + 85) },
	{ "unlinkat", (__SCMP_NR_BASE + 253) },
	{ "unshare", (__SCMP_NR_BASE + 262) },
	{ "uselib", __PNR_uselib },
	{ "userfaultfd",  (__SCMP_NR_BASE + 317) },
	{ "usr26", __PNR_usr26 },
	{ "usr32", __PNR_usr32 },
	{ "ustat", (__SCMP_NR_BASE + 133) },
	{ "utime", (__SCMP_NR_BASE + 130) },
	{ "utimensat", (__SCMP_NR_BASE + 275) },
	{ "utimes", (__SCMP_NR_BASE + 226) },
	{ "vfork", __PNR_vfork },
	{ "vhangup", (__SCMP_NR_BASE + 150) },
	{ "vm86", __PNR_vm86 },
	{ "vm86old", __PNR_vm86old },
	{ "vmsplice", (__SCMP_NR_BASE + 266) },
	{ "vserver", (__SCMP_NR_BASE + 236) },
	{ "wait4", (__SCMP_NR_BASE + 59) },
	{ "waitid", (__SCMP_NR_BASE + 237) },
	{ "waitpid", __PNR_waitpid },
	{ "write", (__SCMP_NR_BASE + 1) },
	{ "writev", (__SCMP_NR_BASE + 19) },
	{ NULL, __NR_SCMP_ERROR },
};

/**
 * Resolve a syscall name to a number
 * @param name the syscall name
 *
 * Resolve the given syscall name to the syscall number using the syscall table.
 * Returns the syscall number on success, including negative pseudo syscall
 * numbers; returns __NR_SCMP_ERROR on failure.
 *
 */
int mips64_syscall_resolve_name(const char *name)
{
	unsigned int iter;
	const struct arch_syscall_def *table = mips64_syscall_table;

	/* XXX - plenty of room for future improvement here */
	for (iter = 0; table[iter].name != NULL; iter++) {
		if (strcmp(name, table[iter].name) == 0)
			return table[iter].num;
	}

	return __NR_SCMP_ERROR;
}

/**
 * Resolve a syscall number to a name
 * @param num the syscall number
 *
 * Resolve the given syscall number to the syscall name using the syscall table.
 * Returns a pointer to the syscall name string on success, including pseudo
 * syscall names; returns NULL on failure.
 *
 */
const char *mips64_syscall_resolve_num(int num)
{
	unsigned int iter;
	const struct arch_syscall_def *table = mips64_syscall_table;

	/* XXX - plenty of room for future improvement here */
	for (iter = 0; table[iter].num != __NR_SCMP_ERROR; iter++) {
		if (num == table[iter].num)
			return table[iter].name;
	}

	return NULL;
}

/**
 * Iterate through the syscall table and return the syscall mapping
 * @param spot the offset into the syscall table
 *
 * Return the syscall mapping at position @spot or NULL on failure.  This
 * function should only ever be used internally by libseccomp.
 *
 */
const struct arch_syscall_def *mips64_syscall_iterate(unsigned int spot)
{
	/* XXX - no safety checks here */
	return &mips64_syscall_table[spot];
}

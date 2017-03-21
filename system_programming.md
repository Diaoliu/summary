## 2. Micro-controllers

#### Transistor-Transistor Logic (TTL)

* **Diode** lets current flow only in one direction
* **Transistor** amplifies current (as Buffer) and inverts voltage (as Inverter)
* **Universal Logic Gate** NAND and NOR

#### Combinational logic

ROM, ALU, selector/multiplexer

####  Sequential logic

RAM/Register, Program Counter

#### MCU

1. ALU fetches instruction from ROM with stored address in PC
2. ALU processes data with decoded instruction
3. ALU fetches next instruction or jump to new address if jump-condition bits are set

#### Buses

* **Address Bus**
  * uses bit flags to address components
  * address decoding : low active
* **Data Bus**
* **Control Bus**
  * read / write signals

#### I/O Mapped Peripheral

* Memory-mapped I/O (MMIO)
  * ARM
  * uses the same address space to address both memory and I/O devices
  * GCC pointer
* Port-mapped I/O (PMIO)
  * i386 : 64k I/O space, 65536 ports
  * uses special class of CPU instructions
    * `	IN AL, DX` : 	Input byte from I/O port in DX into AL
  * uses a separate I/O space from main memory
  * GCC `inb(), outb()`

## 3. I/O

#### Board I/O

* **components**
  * I/O Controller
  * I/O Ports : group of pins/bits
    * status Register
    * control Register (in/out)
    * Data-in Register
    * Data-out Register
  * I/O Buses
  * Master Processer
* **Digital Sampling**
  * Meta-stability
  * Schmitt-trigger
  * Synchronizer
  * Pull Register
* **Data Communication Scheme**
  * Serial and Parallel I/O
  * Simplex, Half duplex, Full duplex
  * Asynchronous (packet) and Synchronous (stream) transfer
* Examples
  * Universal asynchronous receiver-transmitter (UART)
    * Asynchronous mode
      * Data frame : a configurable number of data bits (usually 8 bits)
      * idle period : always high voltage
      * START bit : logic low (0)
      * STOP bit : logic high (1)
    * Synchronous mode
      * NO idle period, START and STOP bit
      * but common Clock
  * Serial Peripheral Interface bus (SPI)
    ![](https://upload.wikimedia.org/wikipedia/commons/e/ed/SPI_single_slave.svg)
    * SCLK: Serial Clock (output from master).
    * MOSI: Master Output, Slave Input (output from master).
    * MISO: Master Input, Slave Output (output from slave).
    * S̅S̅: Slave Select (active low, output from master).
  * RS232
    * data circuit-terminating equipment (DCE) : Peripheral devices
    * data terminal equipment (DTE) : PC
  * IEEE 802.11
  * Ethernet
  * CANbus
  * USB
* Interfacing I/O Controller and Master CPU
  * Master CPU initialize and monitor attached I/O devices via the status and control registers on I/O Controller
  * **Port-mapped I/O** isolate I/O space
    ```c
    /* Driver maps data, status and control bits of device into isolate I/O space */
    #include <linux/ioport.h>
    /* Allocate n ports, check occupied ports with /proc/ioports */
    struct resource * request_region(unsigned long first, unsigned long n, const char * name);
    /* read from requested port */
    unsigned inb(unsigned port);
    /* write into requested port */
    void outb(unsigned char byte, unsigned port);
    ```
  * **Memory-mapped I/O** shared I/O space
    ```c
    /* request a block of memory, check occupied space with /proc/iomem */
    struct resource *request_mem_region(unsigned long start, unsigned long len, char * name);
    ```
  * Communication
    * Peripheral to PC : Interrupt Request
    * PC to Peripheral : System Call
    * Direct memory access (DMA)

#### Buses

* Categories
  * System Buses : connect CPU, main memory and I/O space
    * address bus, control bus, data bus
  * I/O Buses : raise IRQ (interrupt request) control signals
    * ISA Bus : unique IRQ number
    * PCI Bus : shared IRQ number
  * Backplane Buses : System Buses + I/O Buses
* Bus Arbitration
  * Dynamic central parallel
  * Centralized serial (daisy chain)
  * Distributed self-selection
* Communication
  * Master : only one master device is granted at a time
  * Slave : communicate over the bus at any given time
* Handshake
  * Synchronous bus timing scheme:
    * Additional clock signal
    * All components using synchronous Bus run at the same clock rate
    * Clock rate depends on bus length
    * How I/O and master processor communicate
  * Asynchronous bus timing scheme:
    * Handshake signals
    * Request/Reply commands
    * Does not depend on bus length
* I2C
  * Serial Data Line (SDL) / Serial Clock Line (SCL)
  * Multi-Master System
  * Master node: issues the clock and addresses the slaves
  * Slave node: receives clock line and address

## 4. Interrupt

#### Interrupt Handler (Interrupt Service Routine)

* Interrupt Gate Descriptor

#### Interrupt Control

* Trap types
  * Exception
  * Interrupt Request or Hardware Interrupt
  * Software Interrupt or trap or system call
* Programmable Interrupt Controller (PIC) has
  * **ISR** Interrupt Enable (In Service Register)
    * stores the IR, which is currently in processing
  * **IMR** Interrupt Mask Registers
    * each IRR has a mask bit
  * **IRR** Interrupt (Request) Registers
    * Interrupt Request Line
    * waiting queue
* CPU has Global Interrupt Enable bit
  * Interrupt Flag Register
    * on ATmega 169 Status Register : SEI/CLI
    * on X86 FLAGS register: CLI (Clear Interrupts), STI (Set Interrupts)
* Operating System
  * Interrupt Vector Table (Linux /proc/interrupts)
  * Interrupt Service Routine
* Interrupt Handling
  1. Peripheral / CPU(User) raises Interrupt signal
    * Set IRR flag in PIC
  2. PIC selects a not masked IR based on Priority and stores it in ISR
  3. PIC raises INTR line
  4. CPU
    1. Finish current instruction
    2. Read IF flag and INTR pin
    3. If flags are set
      * clear IF
      * acknowledge PIC, interrupt has been accepted
      * switch to kernel mode
      * else continue with next instruction
    4. PIC deliver INTR# via data bus
    4. Read INTR#
    5. Access Interrupt Vector Table
    6. Save current process context
    7. Run ISR
    8. Set IF and acknowledge PIC

## 5.Timer

#### Counter

* Asynchronous and Synchronous
* Implemented by
  * overflow interrupt
  * modulus mode (PWM)

#### Clock (source)

* **Jitter**: the interval of two ticks are never exact same
* **Drift**: two clock source are never equally fast
* **Stability**: clock speed may change

#### Prescaler

* A counter (Prescaler) can be used as tick-input for other counter.

#### Input Capture

* Register stores timestamp (count value) of an event

#### Output Compare / Timer (modulus mode)

* Pulse Width Modulation (PWM)
  * up counter
  * up-down counter
* Duty cycles Register (top)
  * set up timer to reset counter
* High time Register (compare)
  * set up compare time

#### Watchdog Timer

* Separated clock source
* Counting down -> zero reached -> wake the dog -> reset
* The program need to regularly reset the timer

#### Sleep Modes

* Active
* Idle
* Standby
* Power down

## 6. Operating System

#### Overview

* Tasks
  * Program controlling
  * Resource Management
  * Operating Interface
* Process Management
  * Process scheduling / Synchronization
  * memory management
  * process communication
* Operating System Structure
  * Simple structure - MSDOS
  * More complex - UNIX
  * Layered
  * Microkernel
  * Hybrid Systems

#### System Calls

* General procedure
  1. Kernel initializes system call table
    * System Call Vector `*syscalls[]`
  2. user call `write(1, buf, sz)`
  3. pass **system call number** in register `movl $SYS_write, %eax`
  4. raise Interrupt and switch into Kernel Mode `INT 64`
  5. kernel looks up syscall table using system call number `syscalls[%eax]()`
  6. Kernel invokes the corresponding function `sys_write() { do real work } `
  7. Interrupt return
* Parameter passing
  * Pass via registers (e.g., Linux)
  * Pass via user-mode stack (e.g., xv6)
  * Pass via pointer of memory block
* Types of System Calls
  * Process Control
    * `fork(), exit(), wait()`
  * File management
    * `open(), read(), write(), close()`
  * Device Management
    * `ioctl(), read(), write()`
  * Information Maintenance
    * `getpid(), aloarm(), sleep()`
  * Communication
    * `pipe(), shmget(), mmap()`

#### I/O Subsystem

* I/O Hardware
  * PC side
    * Port : 'mapped address' of device registers/RAM on I/O space or RAM space
    * Bus : daisy chain or shared direct address
    * Device Controller : contain micro-processor, micro-code, memory
  * Device side
    * Registers : Data-in/Data-out, status, control
    * RAM : for direct I/O or Memory-mapped I/O
* Direct Memory access
  * avoid programmed IO (bypass CPU)
  * need DMA Controller
* Characteristics of I/O Devices
  * Block Devices (buffered access)
  * Character Devices (unbuffered access)
  * Network Devices
* Linux I/O Model
  * blocking IO
    * busy wait, process suspended until system call returns.
  * non-blocking IO
    * system call returns immediately with size_t or an error.
  * IO multiplexing (event driven IO)
    * select/epoll(polling all file descriptors)
    * process suspended by select/epoll
    * file descriptors are set in non-blocking mode
    * when one of fd is ready to write/read, system call returns.
  * asynchronous IO
    * system sends signals to process when IO completed

## 7. IPC

#### Posix vs. System V IPC

| IPC            | System V | Posix |
| :------------- | :------------- | :------------- |
| Shared Memory  | **&lt;sys/shm.h&gt;** shmget, shmdt, shmctl | **&lt;sys/mman.h&gt;** mmap,munmap, shm_open, shm_unlink |
| Semaphores     | **&lt;sys/sem.h&gt;** semget, semop, semctl | **&lt;semaphore.h&gt;** sem_init, sem_open, sem_wait, sem_trywait, sem_timedwait, sem_unlinksem_close, |
| Message Queues | **&lt;sys/msg.h&gt;** msgget, msgctl, msgrcv, msgsnd | **&lt;mqueue.h&gt;** mq_open, mq_close, mq_send, mq_receive, mq_notify |

#### Open Group Single UNIX Specification

[Online API Reference](http://pubs.opengroup.org/onlinepubs/9699919799/nframe.html)

> click 'Headers' at the bottom left corner to view all header definitions

#### "Name" to identify communication channel

1. parent-child
2. socket : ip + port
3. file path
4. Posix IPC Namespace *always begin with '/'*

#### File API

```c
int open(const char * pathname, int oflag, mode_t mode);
int creat(const char * path, mode_t mode);
off_t lseek(int filedes, off_t offset, int whence);
ssize_t read(int filedes, void * buf, size_t nbytes);
ssize_t write(int fildes, const void * buf, size_t nbyte);
int close(int filedes);
int unlink(const char * path);
```

* All Operations are atomic
* After fork() file descriptors are also copied
* file descriptors are small integers, STDIN_FILENO(0), STDOUT_FILENO(1), STDERR_FILENO(2)

#### Pipes

```c
/* create pipe */
int pipe(int fd[2]);
/* execute daemon process to write or read */
/* tpye = "r" or "w"                       */
FILE * popen(const char * cmd, const char * type);
int pclose(FILE * p);
/* FIFO / Named Pipe                       */
int mkfifo(const char * pathname, mode_t mode);
```

* All readers close pipe
  * return EOF
* All writers close pipe
  * raise SIGPIPE

#### Message Queues

* Message queue descriptor instead of file descriptor
  * Small integer `mqd_t`
  * Different namespace

```c
#include <mqueue.h>
/* Open existed message queue */
mqd_t mq_open(const char *name, int oflag);
mqd_t mq_open(const char *name, int oflag, mode_t mode, struct mq_attr *attr);
/* Attribute of message queue */
mqd_t mq_getattr(mqd_t mqdes, struct mq_attr *attr);
mqd_t mq_setattr(mqd_t mqdes, struct mq_attr *newattr, struct mq_attr *oldattr);
struct mq_attr {
    long mq_flags; /* Flags: 0 or O_NONBLOCK */
    long mq_maxmsg; /* Max. # of messages on queue */
    long mq_msgsize; /* Max. message size (bytes) */
    long mq_curmsgs; /* # of messages currently in queue */
};
/* Send a message */
int mq_send(mqd_t mqdes, const char *msg_ptr, size_t msg_len, unsigned int msg_prio);
/* Receive a message and remove message from queue */
ssize_t mq_receive(mqd_t mqdes, char *msg_ptr, size_t msg_len, unsigned int *msg_prio);
/* Close and delete message queue */
int mq_close(mqd_t mqdes);
int mq_unlink(const char *name);
```

#### Socket

#### Posix Shared Memory

```c
/* Memory mapped file */
void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);
/* Flush to save changes on file */
int msync(void *addr, size_t len, int flags);
/* Releasing the map */
int munmap(caddr_t addr, size_t len);
/* Open and delete shared memory */
int shm_open(const char *name, int oflag, mode_t mode);
int shm_unlink(const char * name);
```

#### Posix Semaphores

```c
#include <semaphore.h>
sem_t *sem_open(const char *name, int oflag);
sem_t *sem_open(const char *name, int oflag,
               mode_t mode, unsigned int value);
int sem_wait(sem_t *sem);
int sem_trywait(sem_t *sem);
int sem_timedwait(sem_t *sem, const struct timespec *abs_timeout);
/* increments (unlocks)  the  semaphore */
int sem_post(sem_t *sem);
int sem_close(sem_t *sem);
int sem_unlink(const char *name);
```

#### Signals

* General Procedure
  1. CPU raises exception (divided by zero) or User invokes syscall (kill)
  2. Execute interrupt handler.
  3. Interrupt handler invokes process scheduler
  4. Switch to the process context, which receives the signal (now still in kernel mode)
  5. Before return from kernel mode
    * Target process examines its own signal table
    * If has one, do default action(normally abort), catch or ignore
* Generate / Catch / block signals
```c
#include <signal.h>
/* Generate a signal */
int kill(pid_t pid, int signo);
/* same as kill(getpid(), int signo);*/
int raise(int signo);
/* Catch a signal */
void handler(int signo);
void handler(int signo, siginfo_t *info, void *context);
/* Additional informations about signal */
struct siginfo {
    int si_signo; /* signal number */
    int si_errno; /* if nonzero, errno value from <errno.h> */
    int si_code; /* additional info (depends on signal) */
    pid_t si_pid; /* sending process ID */
    uid_t si_uid; /* sending process real user ID */
    void *si_addr; /* address that caused the fault */
    int si_status; /* exit value or signal number */
    long si_band; /* band number for SIGPOLL */
    /* possibly other fields also */
};
/* Modify Signal Handler */
int sigaction(int signo, const struct sigaction *act, struct sigaction *oact);
```

## 8. File

#### UNIX File

* Each file type has a **Magic Number**
* Files may exist on RAM `/proc, /dev`
* Linux File Types
  * Regular file (-rw-r--r--)
  * Directory (drw-r--r--)
  * Block devices(brw-r--r--)
  * Character devices (crw-r--r--)
  * Pipe (prw-r--r--)
  * Symbolic link (lrw-r--r--)
  * Socket (srw-r--r--)
* Linux VFS(Virtual File System)
* File Attribute
```c
struct stat {
    dev_t   st_dev; // device
    ino_t   st_ino; // inode
    mode_t  st_mode; // protection
    nlink_t st_nlink; // number of hard links
    uid_t   st_uid; // userID of owner
    gid_t   st_gid; // groupID of owner
    dev_t   st_rdev; // device type
    off_t   st_size; // total size
    blksize_t  st_blksize; // block size for file system
    blkcnt_t   st_blocks; // number of blocks allocated
    time_t     st_atime; // time of last access
    time_t     st_mtime; // time of last modification
    time_t     st_ctime; // time of last status
};
```
* File Operations
```c
#include <stdio.h>
FILE* fopen(const char* path, const char* mode);
int   fclose(FILE* fp);
size_t fread(void* ptr, size_t size, size_t nmemb, FILE* stream);
size_t fwrite(const void* ptr, size_t size, size_t nmemb, FILE* stream);
int stat(const char* path, stuct stat* buf);
int rename(const char* oldpath, const chat* newpath);
```
* File Locking
  * Advisory Lock
  ```c
  /* from sys/file.h                   */
  /* Operations for the `flock' call.  */
  #define	LOCK_SH	1	/* Shared lock.  */
  #define	LOCK_EX	2 	/* Exclusive lock.  */
  #define	LOCK_UN	8	/* Unlock.  */
  /* Can be OR'd in to one of the above.  */
  #define	LOCK_NB	4	/* Don't block when locking.  */
  /* Apply or remove an advisory lock, according to OPERATION,
    on the file FD refers to.  */
  extern int flock (int fd, int operation);
  ```
  * Mandatory Lock
  ```c
  /* F_SETLK, F_SETLKW: Sets lock in non-blocking/blocking way */
  /* F_GETLK: Checks if lock can be set as described           */
  int fcntl(int fd, int cmd, struct flock * ptr);
  /* flock defintion */
  struct flock {
      ...
      short l_type;    // Type of lock: F_RDLCK, F_WRLCK, F_UNLCK
      short l_whence;  // How to interpret l_start: SEEK_SET, SEEK_CUR, SEEK_END
      off_t l_start;   // Starting offset for lock
      off_t l_len;     // Number of bytes to lock
      pid_t l_pid;     // PID of process blocking our lock (set by F_GETLK and F_OFD_GETLK)
      ...
  };
  ```
* Memory-mapped Files

#### Directory

* hard link and soft link
* Directory Operations
```c
/* create and delete */
int mkdir(const char * pathname, mode_t mode);
int rmdir(const char * pathname);
/* open and close */
DIR * opendir(const char * name);
int closedir(DIR * dir);
/* Change current working directory */
int chdir(const char * path);
/* Get current working directory */
char * getcwd(char * buf, size_t size);
```

#### Mass-Storage Organization

* Disk Partitioning
  * Master Boot Record (MBR)
  * Partition table
  * Partition
* File Storage (How blocks grouped together)
  * Contiguous Allocation
  * Linked Allocation
  * Index Allocation (table of pointers of files blocks)
* Free Space Management
  * Bit Vector : each block has a bit flag (ext2 1 = allocated)
  * Linked list: Linked free blocks
  * Grouping : index table of free blocks
  * Counting : pointer of address and number of blocks
* Directory Management Structure
  * Entries Structure
    * linear list (i-node table)
    * hash table (calculated from filename)
  * Entry
    * complete file information
    * just filename and pointer
      * ext2 : pointer to i-node
      * NTFS : pointer to Master File Table (MFT)
* File Management Structure: **i-node**
  * ![](img/inode.png)
* NTFS
  * Master File Table : like i-node table
  * Journaling : after crash
    * Read all log entries after last checkpoint
    * Redo all committed transactions
    * Undo all unfinished transactions

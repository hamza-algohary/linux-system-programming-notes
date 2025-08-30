## Definitions

**Binary** is a compiled, executable code lying dormant on a storage medium.

**Process** is a running program. A process includes:
- Binary image, loaded into memory.
- Instance of virtualized memory.
- Kernel resources such as open files.
- Security context such as an associated user.
- One or more threads.

**Thread** is the unit of activity inside of a process. Each thread has its own virtualized
processor, which includes a stack, processor state such as registers, and an instruction
pointer. threads share the same memory address space.

## Facts

Each process on Linux is identified by an int called PID.

PID 0 represents *idle* process.

PID 1 is *init* process, whether the executable itself is called init or not.

Every process has a parent except init. Each child process inherits its parent’s user
and group

Maximum number of processes can be configured from `/proc/sys/kernel/pid_max`

PIDs of terminated processes is not recycled until kernel reaches maximum PID.

## API

- **getpid()** to get pid.
- **getppid()** to get parent's pid.

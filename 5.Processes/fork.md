## Fork
Use **fork()** to make a clone of the running process.
The new process is said to be a child of the original process.

To distinguish between child and parent, **fork()** returns 0 for the child, and PID of child for the parent and -1 on error.

Example:
```C
pid_t pid = fork();

if(pid > 0)
    printf("I am the parent\n");
else if(pid == 0)
    printf("I am the child\n");
```

Usually to create a new process you **fork()** then **exec()** another binary.

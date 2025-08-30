## Exec
exec family of functions is used to replace the current program by a new program. On success it doesn't return, but jumps to the entry point of the other program. 

The new program inherits the same PID, PPID, user/group owners. It also inherits open file descriptors, if that is not desired you should close open file descriptors. You can do that conveniently by calling fcntl().

## API
- **execl(full_path , args...)** 
- **execlp(file_name , args...)**
- **execv(full_path , args[])**
- **execvp(file__name , args[])**
- **execle(full_path , args... , envp[])**
- **execve(full_path , args[] , envp[])**

Where **l** means arguments are a list and **v** means a vector, both are NULL-terminated. First argument should be program name. 

Example for a list:

```C
execl("/usr/bin/ls" , "ls", NULL);
```

Example for a vector:

```C
char * const args[] = {
    "ls",
    "/home/hamza",
    "-l",
    NULL
};

execv("/usr/bin/ls" , args);
```

**p** is to search in PATH environment variable, for example:

```C
execlp("ls" , "ls" , "--help" , NULL);
```

**e** is to give a different list of environment variables.

envp is the array of environment variables, in the form of "KEY=VALUE".

```C
char * const env[] = {
    "HOME=/home/John",
    NULL
};
execle("/usr/bin/printenv" , "printenv" , NULL , env);
```
Programs like **sudo** should NEVER use p variants of exec to avoid a security hole called PATH injection.

On Linux, only **execve()** is a syscall, the other are wrappers. That is because variadic syscalls are hard to implement and the PATH concept only exists in user-space.
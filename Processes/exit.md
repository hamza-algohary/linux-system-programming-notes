## Exit
Call **exit(status)** to terminate the current process.

Use **EXIT_SUCCESS** & **EXIT_FAILURE** as portable ways of defining success & failure.

Steps of shuting down:
1. Call functions registered with **atexit()**.
2. Flush all open streams.
3. Remove files created with **tmpfile()**.
4. Call **_exit()** syscall.

Upon termination, process's parent recieves recieves **SIGCHLD** signal.

Use **atexit()** to register a callback on termination. Registered callbacks are called in reverse order of their registeration.

Maximum number of exit callbacks can be retreived by the following:
```C
sysconf(_SC_ATEXIT_MAX);
```

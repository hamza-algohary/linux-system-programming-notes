## Wait for a child to terminate and get more info about it
**wait( int * status )** 

Takes a pointer to status. Waits for a child to terminate and returns its PID.

Use one of the following to decode status :
- WIFEXITED() if exited normally.
- WIFSIGNALED() if terminated due to a signal.
- WIFSTOPPED() if stopped.
- WIFCONTINUED() if continued.
- WEXITSTATUS() get exit code.
- WTERMSIG() get number of signal causing termination.
- WSTOPSIG() get number of signal caused stoping.
- WCOREDUMP() if dumped core on exit. 

**waitpid (pid_t pid, int * status, int options)**

Possible values for **PID**:
- < -1 : wait for a child whose group ID is absolute pid.
- -1 : wait for any child.
- 0  : wait for any child in current Group ID.
- \> 0 : wait for child whose ID is pid.

**Options** is a binary OR of zero or any of the following:
- WNOHANG : Does not block, returns immediately if no child was terminated. 
- WUNTRACED : Returns also if child is stopped.
- WCONTINUED : Returns also if child is continued.

There are [Linux-specific options](https://linux.die.net/man/2/waitpid) as well.

## More wait() variants
**waitid (idtype, id,  * infop, options)**
- **idtype**: P_PID or P_GID or P_ALL for PID, group ID and all processes respectively.
- **id**: ID accoring to **idtype**.
- **infop**: If it's not NULL it will be filled with child's data.
- **options**: One or a combination of (WEXITED , WSTOPPED , WCONTINUED , WCONTINUED , WNOWAIT)

**wait3( * status, options, * rusage)**
**wait4(pid, * status, options, * rusage )**
- If rusage is not NULL will it be filled with resource usage data.

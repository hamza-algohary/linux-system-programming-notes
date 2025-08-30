## System
Call **system()** to invoke shell commands. 

It spawns a child process, waits for its termination, and returns exit status that can be checked using one of W*() macros.

This function uses `/bin/sh -c`.

If **sh** fails it returns 127, or -1 if **system()** fails.

Implement a system() function yourself.
Single stdio function calls are atomic, thus they are thread safe.

To make a group of IO calls as one atom, use **flockfile()** & **funlockfile()** as follows:

```C
FILE* file = open("text.txt" , "w+");

flockfile(file);

fputs("Hello", file);
fputs("I am", file);
fputs("one", file);
fputs("atomic", file);
fputs("operation\n", file);

funlockfile(file);
```

- **flockfile()** increases lock count and acquires lock if it's available.
- **funlockfile()** decreases lock count and releases lock if count reaches zero. 

Acoording to the above, these calls can be nested.

**flockfile()** blocks until it is able to acquire the lock. To check the lock without blocking use **ftrylockfile()**

If locking is done manually by the programmer then there is no need for the locking overhead of single IO calls. For this purpose use the **_unlocked versions** of IO calls, these are Linux-specific.
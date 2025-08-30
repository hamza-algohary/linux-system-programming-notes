# File Buffered I/O
## Open
- **<stdio.h>** identifies files by File Pointers (FILE*).
- **fopen()** returns a FILE*.
- **fdopen()** wraps a file descriptor with a file pointer.

Modes are **r** for read, **r+** for read & write. **w** for overwriting, **w+** for overwriting & reading. **a** for append, **a+** for append and read.

## Close
- **fclose()** closes a file.
- **fcloseall()** closes all open files including stdin, stdout & stderr.

## Read
- **fgetc()** reads a char, until it reads EOF.
- **fungetc()** pushes back a char to the input stream, it returns EOF on failure, or the specified char on success.
- **fgets()** reads until {length | \n | EOF} and puts back the delimiter to the buffer.
- **fread()** reads number of structs. Doesn't solve the problem of diffrenet alignment on different machines.

## Write
- **fputc()** puts one char. returns char on success, EOF on failure.
- **fputs()** writes a null-terminated string.
- **fwrite()** writes a number of structs to stream.

## Seek
- **fseek()** to seek relative to either beginning, current or end.
- **rewind()** to set file position to start.
- **ftell()** gets file position.

On non Unix platforms file positions might not be represented as long, but instead as f_pos_t which the following functions use.
- **fsetpos()** to seek relative beginning. It's more portable than **fseek()** for non-Unix platforms.
- **fgetpos()** gets file position.

## Flush (ensuring that user-space buffer is synchronized with kernel-space buffer)
- **fflush()** to write to kernel buffer then call **fsync()**. Call **fflush(null)** to flush all open input streams.

## Notes
- Use **ferror()** to check whether an error is set on stream.
- Use **feof()** to check whether file reached EOF.
- Use **clearerr()** to clear set error or EOF indicators on stream.    
- Use **fileno()** to get file descriptor backing a FILE*.
- You should ALWAYS fflush() before doing IO with system calls, so to not conflict user-buffer with kernel-buffer.
- You can change buffer size of a stream using **setvbuf()**.
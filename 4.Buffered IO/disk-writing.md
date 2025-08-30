**When** writing to disks, it's required to read/write block size or integer multiple of block size. 
If it's desired to write one byte and block size is 1024, then you need to read 1024 bytes, update the modified byte and then rewrite them again.
If you are going to write 4.5 blocks, then you need to write 5 blocks.
<br/><br/>
**Use** dd command to copy data from a file/device to another, and use bs option to specify single write size, where 1024 is going to be the most effecient option.
```
dd bs=1 count=2048 if=/dev/zero of=pirate
```
``/dev/zero`` is a device providing an endless stream of zeros.

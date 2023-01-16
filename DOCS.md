# Puttin the hard parts in text

So what I think is going on, is

There's the static address of pointer 1 that is found via this offset:

```c++s
ac_client.exe+18B0B8
```

Then, the value of that pointer, is the address of the entity class. When you have the entity class, you can find the health address, which is the offset of:

```c++
408
```

So here would be the full equation:
```c++
HEX x = [ ac_client.exe+18B0B8 ]
[ x + 408 ] = 69420 // or some
```
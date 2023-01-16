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

# Issues with overflow

Once I got this little memory editor up and running, I found that I could change the health to whatever I want.

Though after a bit of playtesting, I found that when setting too big of a number, I'd die instantly when I take any form of damage.

Thankfully, I quickly came to the conclusion that I was causing overflow. And after some further testing, I found out that a signed 4 byte integer was used to resemble the health.

This means the largest possible integer is around `2147483647`, if you go any higher that that it switches to a negative because of the signed int.
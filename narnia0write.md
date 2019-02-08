# Narnia0 (OverTheWire)
As soon as we change directories into /narnia, we see that we have both the source code and the executable for narnia0.

We cat narnia0.c to see the source code, and see that there is a buffer of 20 bytes, but the scanf is reading in 24 bytes. so we have 4 bytes with which to overflow.

We go ahead and run the narnia0 executable, and it's easier to see that we want to set "val" to 0xdeadbeef.

We can set this with a simple command line python script, then pipe the results to the executable:

`(python -c "print 'B'*20 + '\xef\xbe\xad\xde'"; cat -) | ./narnia0`

Let's break this line down a bit:

The `python` command means we're using a python script

`-c` means we will be specifying the script from the command line

`"print 'B'*20 + '\xef\xbe\xad\xde'"` The entire python script must be in quotes, and string literals must be in a different type of quotes. when a string is multiplied in python, it prints that string the number of times it's been multiplied by. The + concatenates the strings in the script, and the second string is 0xdeadbeef, corrected for endianness. the `\x` denotes a raw hex value to the python interpreter.

`cat -` cats the stdout, which keeps python from sending an EOF to the pipe

`| ./narnia0` pipes the entire output of both the python and cat commands to the narnia0 executable.

Running this command sets the value to 0xdeadbeef, and the program seems to hang. Looking at the source code again, we see that we have probably run /bin/bash, which means we are now in a shell.

`whoami` results in narnia1. awesome! now we cd to /etc/narnia_pass, and cat narnia1, which gives us the password: efeidiedae
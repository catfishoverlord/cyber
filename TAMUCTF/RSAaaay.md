# TAMUCTF RSAaaay
Immediate observations: 
- the name of this problem indicates that it's probably an RSA decryption
- given this info, the 2 number pair in the problem is probably the (n, e) public key pair.

We are given `n = 2531257` and `e = 43`. From that, we find the totient of n (using [this](http://www.javascripter.net/math/calculators/eulertotientfunction.htm) handy tool) to be 2525776. 

d will be the multiplicative inverse of e mod phi(n). Using [this](https://planetcalc.com/3311/) website, I found `d = 58739`. 

Since the "super secret message" is split into parts, I wrote a simple python script to give me the message:

	encrypted = [906851, 991083, 1780304, 2380434, 438490, 356019, 921472, 822283, 817856, 556932, 2102538, 2501908, 2211404, 991083, 1562919, 38268]
	decrypted = []

	n = 2531257
	d = 58739

	for value in encrypted:
		decrypted.append(pow(value, d, n))
		
	print(decrypted)

This outputs [103, 105103, 101109, 12383, 97118, 97103, 10195, 83105, 12095, 70108, 121105, 110103, 9584, 105103, 101114, 115125]. I split up the results into valid character values and throw them into [ASCIItoHex](https://www.asciitohex.com), and you get `gigem{Savage_Six_Flying_Tigers}`.
# TAMUCTF - Hello World
Upon downloading the file, I opened it in Notepad++. Immediately, I noticed there were 147 lines of whitespace characters, followed by a simple C++ "Hello World" program. I figured this was a Whitespace program hidden inside a C++ program. I found a simple [Whitespace Interpreter](https://vii5ard.github.io/whitespace/) that did the job. 

I originally tried just the leading whitespace, but that didn't output anything. I then put the entire file (including the C++ code) into the ide, and then (carefully) deleted the non-whitespace characters. 

This resulted in "Well sweet golly gee, that sure is a lot of whitespace!" Not exactly what I was looking for. 

I started clicking around the IDE and found [103, 105, 103, 101, 109, 123, 48, 104, 95, 109, 121, 95, 119, 104, 52, 116, 95, 115, 112, 52, 99, 49, 110, 103, 95, 121, 48, 117, 95, 104, 52, 118, 51, 125] on the stack. 

That looks like ASCII!

If I throw it into [ASCIItoHex](https://www.asciitohex.com), I get `gigem{0h_my_wh4t_sp4c1ng_y0u_h4v3}`

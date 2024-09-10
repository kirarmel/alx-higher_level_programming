#!/usr/bin/python3

# Use a loop to print each ASCII character from 'a' to 'z' without newline
print("".join("{:c}".format(i) for i in range(97, 123)), end="")

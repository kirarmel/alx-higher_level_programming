#!/usr/bin/python3

# Print numbers from 0 to 98 in decimal and hexadecimal
print("\n".join("{:d} = 0x{:x}".format(i, i) for i in range(99)))

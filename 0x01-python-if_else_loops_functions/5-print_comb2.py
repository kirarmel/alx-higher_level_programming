#!/usr/bin/python3

# Print numbers from 0 to 99 separated by ", "
print(", ".join("{:02d}".format(i) for i in range(100)))

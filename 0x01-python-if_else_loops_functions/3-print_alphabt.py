#!/usr/bin/python3

# Print lowercase alphabet excluding 'q' and 'e'
print("".join("{:c}".format(i) for i in range(97, 123) if i not in (101, 113)), end="")

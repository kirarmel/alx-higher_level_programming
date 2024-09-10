#!/usr/bin/python3
print("".join("{}".format(chr(c)) if c % 2 == 0 else "{}".format(chr(c).upper()) for c in range(122, 96, -1)), end="")

#!/usr/bin/python3
def uppercase(str):
    for c in str:
        # Check if the character is a lowercase letter
        if ord(c) >= 97 and ord(c) <= 122:
            c = chr(ord(c) - 32)  # Convert to uppercase
        print("{}".format(c), end="")
    print("")

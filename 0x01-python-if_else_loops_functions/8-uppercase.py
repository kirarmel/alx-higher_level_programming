#!/usr/bin/python3

def uppercase(str):
    print("".join(chr(ord(c) - 32) if ord('a') <= ord(c) <= ord('z') else c for c in str))

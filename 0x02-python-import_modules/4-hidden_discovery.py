#!/usr/bin/python3
import sys
import importlib.util

def print_module_names(filepath):
    # Load the module from the .pyc file
    spec = importlib.util.spec_from_file_location("hidden_4", filepath)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)

    # Get all names from the module and filter out those starting with '__'
    names = [name for name in dir(module) if not name.startswith("__")]
    
    # Print names in alphabetical order
    for name in sorted(names):
        print(name)

if __name__ == "__main__":
    # Ensure the file path is correct for the local .pyc file
    print_module_names("hidden_4.pyc")

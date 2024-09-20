#include <Python.h>
#include <stdio.h>

void print_python_bytes(PyObject *p) {
    if (!PyBytes_Check(p)) {
        printf("[.] bytes object info\n[ERROR] Invalid Bytes Object\n");
        return;
    }

    Py_ssize_t size = PyBytes_Size(p);
    const char *str = PyBytes_AsString(p);
    printf("[.] bytes object info\n  size: %zd\n  trying string: %s\n  first %s bytes: ", 
           size, str, (size < 10) ? (char *)str : "10");

    for (int i = 0; i < (size < 10 ? size : 10); i++) {
        printf("%02x ", (unsigned char)str[i]);
    }
    printf("\n");
}

void print_python_list(PyObject *p) {
    Py_ssize_t size, allocated, i;
    PyObject *item;

    if (!PyList_Check(p)) {
        printf("[.] list object info\n[ERROR] Invalid List Object\n");
        return;
    }

    size = PyList_Size(p);
    allocated = ((PyListObject *)p)->allocated;  // Accessing the allocated size directly
    printf("[*] Python list info\n[*] Size of the Python List = %zd\n[*] Allocated = %zd\n", size, allocated);

    for (i = 0; i < size; i++) {
        item = PyList_GetItem(p, i);  // Get item without checking bounds
        printf("Element %zd: %s\n", i, Py_TYPE(item)->tp_name);
        if (PyBytes_Check(item)) {
            print_python_bytes(item);
        }
    }
}


#include <Python.h>
#include <iostream>

int main() {
    // Initialize the Python interpreter
    Py_Initialize();

    // Import the compiled module
    PyObject* pName = PyUnicode_DecodeFSDefault("pythontest");
    PyObject* pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    if (pModule != NULL) {
        // Get the reference to the greet function
        PyObject* pFunc = PyObject_GetAttrString(pModule, "greet");

        if (pFunc && PyCallable_Check(pFunc)) {
            // Prepare the argument for the function
            PyObject* pArgs = PyTuple_Pack(1, PyUnicode_FromString("World"));

            // Call the function
            PyObject* pValue = PyObject_CallObject(pFunc, pArgs);
            Py_DECREF(pArgs);

            if (pValue != NULL) {
                // Print the result
                std::cout << PyUnicode_AsUTF8(pValue) << std::endl;
                Py_DECREF(pValue);
            } else {
                PyErr_Print();
            }
        } else {
            if (PyErr_Occurred())
                PyErr_Print();
        }

        Py_XDECREF(pFunc);
        Py_DECREF(pModule);
    } else {
        PyErr_Print();
    }

    // Finalize the Python interpreter
    Py_Finalize();
    return 0;
}